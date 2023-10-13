/**********************************************************
*  Web 		: http://www.gencmucitler.com
*  �lk		: A�ustos 2008
*  D�zenleme: May�s 2017 
*  Versiyon : 0.4
*  A��klama : Piyasada rahatl�kla bulunan HD44780 karakter lcd ekran k�t�phanesi.
*			  Lcd ye 4 bit modda eri�im sa�lan�r.
 *            XC8 i�in gerekli d�zenlemeler yap�ld�.
***********************************************************/

#include "mcc_generated_files/mcc.h"
#include "lcd4bit.h"


/*
*  Standart LCD ayak ba�lant�lar�
*  1: Gnd
*  2: Vcc
*  3: Vee : Kontras aya��. 10K pot veya 1K diren� ile �aseye ba�la.
*  4: RS
*  5: RW
*  6: E
*  7: D0 - gnd ye ba�la
*  8: D1 - gnd ye ba�la
*  9: D2 - gnd ye ba�la
* 10: D3 - gnd ye ba�la
* 11: D4 highport aktifse 4 e de�ilse 0 a ba�la.
* 12: D5 highport aktifse 5 e de�ilse 1 a ba�la.
* 13: D6 highport aktifse 6 e de�ilse 2 a ba�la.
* 14: D7 highport aktifse 7 e de�ilse 3 a ba�la.
* 15: Backlight Vcc
* 16: Backlight Gnd
*/



/***********************************************************
*  Lcd ekran� �al��t�r�r. Di�er fonksiyonlar kullan�lmadan �nce ilk olarak bu �al��t�r�lmal�d�r.
*/
void lcd_baslat(void)
{
    //lcd_tris=0x00;
#ifdef lcd_highport
    lcd_tris = 0x0F & lcd_tris; //4 bit mod
#else
    lcd_tris = 0xF0 & lcd_tris; //4 bit mod
#endif

    tris_lcd_e = 0;
    tris_lcd_rs = 0;
	
	__delay_ms(15);
	lcd_rs=0;
    
#ifdef mesgulbitioku
	lcd_rw=0;
    tris_lcd_rw=0;
#endif
    
	lcd_e=0;
	#ifdef lcd_highport
		lcd_data=0x20 | (lcd_data & 0x0f);	//4 bit mod
	#else
		lcd_data=0x02 | (lcd_data &0xf0);	//4 bit mod
	#endif
	lcd_e=1;
	__delay_us(1);
	lcd_e=0;
	__delay_us(40);
	lcd_komut(0x28);
	__delay_us(40);
    lcd_komut(0x0C);  //display on
	__delay_us(40);    
    lcd_komut(0x06);  //cursor ileri	
	__delay_ms(1);
}

/*********************************************************
* �stenilen pozisyona gider.
* �rnek lcd_git(2,5);
*/
void lcd_git(char satir, char sutun)
{
	char temp;
	switch(satir)
	{
		case 1:
			temp=sutun-1+ 0x80;
			break;
		case 2:
			temp= sutun-1+0xc0;
			break;
		case 3:
			temp= (sutun-1+0x94);
			break;
		case 4:
			temp= (sutun-1+0xd4);
			break;
	}	
	lcd_komut(temp);
	__delay_us(100);
}
	
/***********************************************************
* �stenilen posziyonda ekrana string yazar.
* �rnek : lcd_mesajyaz(1,4,"Deneme");
*/
void lcd_mesajyaz(char satir, char sutun, const char *mesaj)
{
	char temp;
	switch(satir)
	{
		case 1:
			temp=sutun-1+ 0x80;
			break;
		case 2:
			temp= sutun-1+0xc0;
			break;
		case 3:
			temp= (sutun-1+0x94);
			break;
		case 4:
			temp= (sutun-1+0xd4);
			break;
	}	
	lcd_komut(temp);
	__delay_us(100);;
	do
	{
		lcd_harfyaz(*mesaj++);
	}while(*mesaj);
}


/***********************************************************
* Lcd ekrana en son kald��� pozisyondan itibaren string yazar. 
* �rnek : lcd_mesajyaz_cp("deneme");
*/
void lcd_mesajyaz_cp(const char *mesaj)
{
	do
	{
		lcd_harfyaz(*mesaj++);
	}while(*mesaj);
}

/***********************************************************
* Lcd me�gul oldu�u s�rece bu fonksiyon i�inde bekler..
* Lcd_komut ve lcd_harfyaz fonksiyonlar� bu fonksiyonu kullan�r.
*/
#ifdef mesgulbitioku

void lcd_mesgulmu(void)
{
	char temp,temp2;
	lcd_rs=0;
	lcd_rw=1;
	#ifdef lcd_highport
		lcd_tris=0xf0 | lcd_tris;
	#else
		lcd_tris=0x0f | lcd_tris;	
	#endif
	do
	{
		__delay_us(1);		
		lcd_e=1;
		__delay_us(1);
		lcd_e=0;	//high byte oku
		#ifdef lcd_highport
			temp=lcd_read & 0x80;
		#else
			temp=lcd_read & 0x08;
		#endif
		__delay_us(1);		
		lcd_e=1;
		__delay_us(1);
		lcd_e=0;	//low byte oku, ama herhangi bir de�i�kene kaydetmeye gerek yok.
	}while(temp);
	#ifdef lcd_highport	
		lcd_tris=lcd_tris & 0x0f;	
	#else
		lcd_tris=lcd_tris & 0xf0;
	#endif
}
#else

void lcd_mesgulmu(void)
{
	__delay_us(100);
}

#endif

/***********************************************************
* Lcd ekrana tek bir harf yazar.
* �rnek : lcd_harfyaz('A');
*/
void lcd_harfyaz(char harf)
{
	lcd_mesgulmu();
	lcd_rs=1;
#ifdef mesgulbitioku
    lcd_rw = 0;
#endif
	#ifdef lcd_highport
		lcd_data = (lcd_data & 0x0f) | (harf & 0xf0);	//high verisini g�nder.
	#else
		lcd_data = (lcd_data & 0xf0) | (harf >>4);
	#endif	
	lcd_e=1;
	__delay_us(1);
	lcd_e=0;	
	__delay_us(1);
	#ifdef lcd_highport
		lcd_data = (lcd_data & 0x0f) | (harf << 4);  //low verisini g�nder.
	#else
		lcd_data = (lcd_data & 0xf0) | (harf & 0x0f);
	#endif	
	lcd_e=1;
	__delay_us(1);
	lcd_e=0;	
	__delay_us(1);
}

/***********************************************************
* Lcd komutlar�n� g�nderir.
*/	
void lcd_komut(char komut)
{
	lcd_mesgulmu();
	lcd_rs=0;
#ifdef mesgulbitioku
    lcd_rw = 0;
#endif
	#ifdef lcd_highport
		lcd_data = (lcd_data & 0x0f) | (komut & 0xf0);	//high verisini g�nder.
	#else
		lcd_data = (lcd_data & 0xf0) | (komut >>4);
	#endif	
	lcd_e=1;
	__delay_us(1);	
	lcd_e=0;	
	__delay_us(1);
	#ifdef lcd_highport
		lcd_data = (lcd_data & 0x0f) | (komut << 4);  //low verisini g�nder.
	#else
		lcd_data = (lcd_data & 0xf0) | (komut & 0x0f);
	#endif	
	lcd_e=1;
	__delay_us(1);	
	lcd_e=0;	
	__delay_us(1);
}
	
/***********************************************************
* Lcdyi siler.
* �rnek : lcd_sil();
*/
void lcd_sil(void)
{
	lcd_komut(0x01);
#ifndef mesgulbitioku
	__delay_ms(2);
#endif
}

/***********************************************************
* Kurs�r� aktif yapar
* �rnek : lcd_kursorac();
*/
void lcd_kursorac(void)
{
	lcd_komut(0x0F);
}

/***********************************************************
* K�rs�r� kapat�r.
*/
void lcd_kursorkapat(void)
{
	lcd_komut(0x0C);
}

/***********************************************************
* 1. sat�r 1. sutuna gider
*/
void lcd_satirbasi(void)
{
	lcd_komut(0x02);
}

/***********************************************************
* 1. sat�r 1. sutuna gider
*/
void lcd_satir1(void)
{
	lcd_komut(0x80);
}

/***********************************************************
* 2. sat�r 1. sutuna gider
*/
void lcd_satir2(void)
{
	lcd_komut(0xc0);
}

/***********************************************************
* 3. sat�r 1. sutuna gider 
*/
void lcd_satir3(void)
{
	lcd_komut(0x94);
}

/***********************************************************
* 4. sat�r 1. sutuna gider
*/
void lcd_satir4(void)
{
	lcd_komut(0xd4);
}

/* Printf fonksiyonu i�in.
*/
void putch(unsigned char byte)
{
	lcd_harfyaz(byte);
}


/*
v0.3 #define mesgulbitioku parametresi eklendi. Bu sayede me�gul biti okunarak m� yoksa
sabit bir s�remi beklenece�i belirleniyor. Proteusta Me�gul biti �zelli�i �al��m�yor.

v0.2 lcd_git() fonksiyonu eklendi.
*/
//lcd ayaklar�
#define lcd_data	LATD	//data hatt�
#define lcd_read   PORTD
#define lcd_tris	TRISD
//#define lcd_highport  //4,5,6,7 . ayaklar� lcdnin data hatt�na ba�l�

#define lcd_lowport	//0,1,2,3 . ayaklar� lcdnin data hatt�na ba�l�

#define lcd_e	LATD2	//kontrol pinleri
#define lcd_rs	LATD3
#define tris_lcd_e  TRISD2
#define tris_lcd_rs TRISD3

//#define mesgulbitioku	//Me�gul biti okuyarak daha h�zl� lcdye yaz� yazar.
						//Kapat�l�rsa her harf g�nderiminde 0.1 ms bekler
						//Proteus i�in kapal� olmal�, proteusta bu fonksiyon d�zg�n �al��m�yor.

#ifdef mesgulbitioku
    #define lcd_rw	LATB2
    #define tris_lcd_rw TRISB2
#endif

//fonksiyon prototipleri
void lcd_baslat(void);
void lcd_git(char satir, char sutun);
void lcd_mesajyaz(char satir, char sutun, const char *mesaj);
void lcd_mesajyaz_cp(const char *mesaj);
void lcd_mesgulmu(void);
void lcd_harfyaz(char harf);
void lcd_komut(char komut);
void lcd_sil(void);
void lcd_kursorac(void);
void lcd_kursorkapat(void);
void lcd_satirbasi(void);
void lcd_satir1(void);
void lcd_satir2(void);
void lcd_satir3(void);
void lcd_satir4(void);
void putch(unsigned char byte);

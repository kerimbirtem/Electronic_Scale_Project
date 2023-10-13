//lcd ayaklarý
#define lcd_data	LATD	//data hattý
#define lcd_read   PORTD
#define lcd_tris	TRISD
//#define lcd_highport  //4,5,6,7 . ayaklarý lcdnin data hattýna baðlý

#define lcd_lowport	//0,1,2,3 . ayaklarý lcdnin data hattýna baðlý

#define lcd_e	LATD2	//kontrol pinleri
#define lcd_rs	LATD3
#define tris_lcd_e  TRISD2
#define tris_lcd_rs TRISD3

//#define mesgulbitioku	//Meþgul biti okuyarak daha hýzlý lcdye yazý yazar.
						//Kapatýlýrsa her harf gönderiminde 0.1 ms bekler
						//Proteus için kapalý olmalý, proteusta bu fonksiyon düzgün çalýþmýyor.

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

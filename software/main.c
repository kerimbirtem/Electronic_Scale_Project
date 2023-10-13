/**
 
  Creator : Kerim Birtem 
  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K20
        Driver Version    :  2.00
*/



// CONFIG1H
#pragma config FOSC = INTIO67   // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 18        // Brown Out Reset Voltage bits (VBOR set to 1.8 V nominal)

// CONFIG2H
#pragma config WDTEN = OFF       // Watchdog Timer Enable bit (WDT is always enabled. SWDTEN bit has no effect)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config HFOFST = ON      // HFINTOSC Fast Start-up (HFINTOSC starts clocking the CPU without waiting for the oscillator to stablize.)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection Block 0 (Block 0 (000800-003FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection Block 1 (Block 1 (004000-007FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection Block 2 (Block 2 (008000-00BFFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection Block 3 (Block 3 (00C000-00FFFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection Block 0 (Block 0 (000800-003FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection Block 1 (Block 1 (004000-007FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection Block 2 (Block 2 (008000-00BFFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection Block 3 (Block 3 (00C000h-00FFFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0 (Block 0 (000800-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection Block 1 (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection Block 2 (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection Block 3 (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)




#include <xc.h>
#include <pic18f46k20.h>
#include "mcc_generated_files/mcc.h"
#include "lcd4bit.h"
#include "keypad1.h"

#define _XTAL_FREQ 1000000                                                      // Frequency is 1 MHz .
#define  Baud_rate 9600                                                         // Baud rate is 9600 



float weight=0, br_fyt= 00.00 ,top_fyt = 00.00,tare_sbt=0,memory_read_indis ;                                // 24 bit data from hx711 to kg data.
double cal_value=0.0002 ;                                                       // calibration factor ---> max kg - 0 / (24bit0b111... - 0)
bool kg_to_g=0 ;                                                                // 0 = kg , 1 = g  . Weight value showing lcd parameter.  
const char weight_units[2][3] = {"kg","gr"};                                    // lcd text . 
char weight_str[5], br_fyt_str[5], top_fyt_str[5]; 
uint16_t dutycycle=32765;                                                       // pwm %50 
int memi,memj;
   
   

// 24 bit hx711 data to kg values function .
float scale_weight(){ 
   
   float x,xf,xmxf;
   long xmx,x1;
   uint32_t dt_hx711;
   
   // if(EUSART_is_rx_ready()){
   //         
   // dt_hx711 = EUSART_Read();
   dt_hx711 = 0b00000000010111101111010111001101 ;
   x1= (long)(dt_hx711*cal_value);
  
   xmx= x1%100; //45
   xmxf = xmx;  //45.00
   xf= x1 / 100; //14
   x=xf+(xmxf/100);
           
           if(tare_button == 1 ){
              tare_sbt =x;
              __delay_ms(100);
              tare_button = 0;
           }
             
   x=x-tare_sbt;
    return x ;   
}

// Scale calibration function
void cal_scale(){
  
    double zero_weight , refe_weight;
    float refe_kg=20.00;
    char refe_kg_str[5];
    uint32_t zero_refe;
    //int enter_cal;
    
   
     
     
    lcd_sil();
    lcd_mesajyaz(2, 1, "Calibration");
    __delay_ms(2500);
    lcd_mesajyaz(2, 1, "           ");
    lcd_mesajyaz(2, 6, "Teraziyi");
    lcd_mesajyaz(3, 4, "Bosaltiniz.");
    __delay_ms(3500);
   
    lcd_sil();
    lcd_mesajyaz(2, 6, "00.00 kg");
    lcd_mesajyaz(3, 1, "Agirlik onayi icin");
    lcd_mesajyaz(4, 1, "Enter'e basiniz");
    __delay_ms(1000);
    
    
    do {
    // enter_cal= PORTB>>4 ;
    
    keypad1_read();
    lcd_mesajyaz(4, 9, "basiniz");                                              // enter tusuna basilana kadar bekletip bu s?rada basiniz yaz?s?n? blink ediyor.
    __delay_ms(500);
    lcd_mesajyaz(4, 9, "       ");
    __delay_ms(500);
    } while (!enter_button);
    
    enter_button=0;
    lcd_mesajyaz(3, 1, "                  ");
    lcd_mesajyaz(4, 1, "                  ");
    
    
    // 0 agirlik 
    zero_weight = EUSART_Read();
   
    
    lcd_mesajyaz(2, 6, "        ");
    __delay_ms(500);
    lcd_mesajyaz(2, 6, "00.00 kg");
    __delay_ms(500);
    lcd_mesajyaz(2, 6, "        ");
    __delay_ms(500);
    lcd_mesajyaz(2, 6, "00.00 kg");
   
    
    
    lcd_mesajyaz(3, 2, "Referans agirligi");
    lcd_mesajyaz(4, 6, "Giriniz.");
    
    __delay_ms(3500);
    
    lcd_mesajyaz(3, 2, "                 ");
    lcd_mesajyaz(4, 6, "        ");
    
    
    do {
    //enter_cal= PORTB>>4 ;
    
    keypad1_read();
    refe_kg = keypad1_read_br();
    
    sprintf(refe_kg_str, "%.2f", refe_kg);      
    lcd_mesajyaz(2, 6, refe_kg_str);   
    lcd_mesajyaz(3, 1, "Agirlik onayi icin");
    lcd_mesajyaz(4, 1, "Enter'e basiniz");
    
    } while (!enter_button); // while (enter_cal !=12)
  
    enter_button = 0;
    
    lcd_mesajyaz(2, 6, "        ");
    __delay_ms(500);
    lcd_mesajyaz(2, 6, refe_kg_str); 
    __delay_ms(500);
    lcd_mesajyaz(2, 6, "        ");
    __delay_ms(500);
    lcd_mesajyaz(2, 6, refe_kg_str); 
    
   lcd_sil();
   __delay_ms(1500);
   lcd_mesajyaz(3, 1, "cal...");
   
    refe_weight = EUSART_Read();
    
    
    cal_value= refe_kg / (refe_weight - zero_weight) ;
    lcd_mesajyaz(3, 1, "completed");
    __delay_ms(1500);
   
   function_button=0; 
    return;
}

// Scale LCD display contrast settings 
void lcd_cntrst_bar (){
    int j,i=7 ;
    


    
    j= (dutycycle/6553)+5;
    lcd_sil();
    
    lcd_mesajyaz(2, 5, "Parlaklik");    
    
    lcd_mesajyaz(3, 6, "|");
    lcd_mesajyaz(3, 12, "|");
    
    
        for (i=7;i<j;i++){
            lcd_git(3,i);
            lcd_komut(0xFF);
            }
    __delay_ms(2000);
    lcd_sil();
}

void lcd_cntrst_up (){
    
    dutycycle = dutycycle + 6553 ;                                              // +%10 if %70 ise = 70
            if(dutycycle>45871){
                dutycycle=45871;
            }
           lcd_cntrst_bar ();
           cntrst_up=0;
}

void lcd_cntrst_down (){
    
    dutycycle = dutycycle- 6553 ;                                               // -%10 if %30 ise = 30
            if(dutycycle<19659){
                dutycycle=19659;
            }
    lcd_cntrst_bar ();
    cntrst_down=0;
}

void keypad2_memory_write(float value ,float adr){
    int i,j;
    //adr=3.2
    i=(int)(adr*10)/10;
    j=(int)(adr*10)%10;
    
    memory[i][j]=value;
    
    memory_write=0;
}

void main(void){
    
    SYSTEM_Initialize();                                                        // eusart,pwm,timer2,pins and device configuration.
    
    
    PWM2_LoadDutyValue(dutycycle);                                              //lcd ekranin kontrast ayar?.
    
    __delay_ms(500);
    lcd_baslat();                                                               // turn on the lcd .
    lcd_kursorkapat();                                                          // turn off the cursor on lcd . 
    lcd_mesajyaz(2, 7, "Birtem");                                               // Opening Text at the start.
    lcd_mesajyaz(3, 3, "scale-project");
    __delay_ms(2500);
    lcd_sil();
    __delay_ms(200);

    while (1){
        
     kg_to_g = button_kgg;
     
     weight = scale_weight();                                                   //read weight value.
     if (kg_to_g){                                                              // select g unit or kg unit .
         weight = 1000*weight;
        }   
     
     lcd_mesajyaz(1, 1, "/---------\\" );                                        // lcd display screen frame 
     lcd_mesajyaz(4, 1, "\\---------/") ;
     lcd_mesajyaz(1, 12, "*") ;
     lcd_mesajyaz(4, 12, "*") ;
     lcd_mesajyaz(2, 1, "|") ;
     lcd_mesajyaz(3, 1, "|") ;
     lcd_mesajyaz(2, 11, "|*") ;
     lcd_mesajyaz(3, 11, "|*") ;
     
     
     lcd_mesajyaz(1, 20, "*") ;
     lcd_mesajyaz(2, 20, "*") ;
     lcd_mesajyaz(3, 20, "*") ;
     lcd_mesajyaz(4, 20, "*") ;
     
     
     
     lcd_mesajyaz(2, 18, "tl");                                                  // write the money unit on the lcd .  ///// dolar/euro/? maybe £ $
     lcd_mesajyaz(4, 18, "tl");
     lcd_mesajyaz(1, 14, "Tutar");
     lcd_mesajyaz(3, 13, "Br Fyt");
     
     
     lcd_mesajyaz(2, 9, weight_units[kg_to_g]);                                 // write "kg/gr" 2x8 cell in the lcd  
     sprintf(weight_str, "%.2f", weight);                                       // cover the float data type weight to string dara type (for write to the lcd.)
     lcd_mesajyaz(2, 3, weight_str);                                            // write "weight value" 2x2 cell in the lcd
     __delay_ms(200);
     
     
     
     
     
     keypads_read();                                                            //read keypads data.
     br_fyt=keypad1_read_br();
     
     if(bool_memory){
     memory_read_indis=keypad2_memory_read();
     memi=(int)(memory_read_indis*10)/10;
     memj=(int)(memory_read_indis*10)%10;
     
     br_fyt=memory[memi][memj];
     bool_memory=0;
     }
     
     
     if(memory_write){
         do{
         
         lcd_mesajyaz(3, 5,"***");   
         memory_read_indis=keypad2_memory_read();    
             
         }while(!bool_memory);
         
         keypad2_memory_write(br_fyt,memory_read_indis);
         
         lcd_mesajyaz(3, 5,"   "); 
         memory_write=0;
         bool_memory=0;
     }
     
     if(cntrst_up)lcd_cntrst_up ();
     if(cntrst_down)lcd_cntrst_down ();
     if(button_C){
         br_fyt=00.00;
         button_C=0;
     }
     
     sprintf(br_fyt_str, "%.2f", br_fyt);      
     lcd_mesajyaz(4, 13, br_fyt_str);
     top_fyt= br_fyt*weight;
     sprintf(top_fyt_str, "%.2f", top_fyt);      
     lcd_mesajyaz(2, 13, top_fyt_str);   
     
     
    
     // geri tusu eklenicek mesela kalibirasyondan cikmak için geri tusu fomksiyonu kullanilacak
     
     
     
     if(function_button>7){
         cal_scale();
         function_button=0;
     }
     
     
     }

}

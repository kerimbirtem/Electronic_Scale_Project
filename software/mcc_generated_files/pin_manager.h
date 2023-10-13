/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K20
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set kp1_da aliases
#define kp1_da_TRIS                 TRISAbits.TRISA0
#define kp1_da_LAT                  LATAbits.LATA0
#define kp1_da_PORT                 PORTAbits.RA0
#define kp1_da_ANS                  ANSELbits.ANS0
#define kp1_da_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define kp1_da_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define kp1_da_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define kp1_da_GetValue()           PORTAbits.RA0
#define kp1_da_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define kp1_da_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define kp1_da_SetAnalogMode()      do { ANSELbits.ANS0 = 1; } while(0)
#define kp1_da_SetDigitalMode()     do { ANSELbits.ANS0 = 0; } while(0)

// get/set kp2_da aliases
#define kp2_da_TRIS                 TRISAbits.TRISA1
#define kp2_da_LAT                  LATAbits.LATA1
#define kp2_da_PORT                 PORTAbits.RA1
#define kp2_da_ANS                  ANSELbits.ANS1
#define kp2_da_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define kp2_da_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define kp2_da_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define kp2_da_GetValue()           PORTAbits.RA1
#define kp2_da_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define kp2_da_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define kp2_da_SetAnalogMode()      do { ANSELbits.ANS1 = 1; } while(0)
#define kp2_da_SetDigitalMode()     do { ANSELbits.ANS1 = 0; } while(0)

// get/set kp1_a aliases
#define kp1_a_TRIS                 TRISBbits.TRISB0
#define kp1_a_LAT                  LATBbits.LATB0
#define kp1_a_PORT                 PORTBbits.RB0
#define kp1_a_WPU                  WPUBbits.WPUB0
#define kp1_a_ANS                  ANSELHbits.ANS12
#define kp1_a_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define kp1_a_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define kp1_a_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define kp1_a_GetValue()           PORTBbits.RB0
#define kp1_a_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define kp1_a_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define kp1_a_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define kp1_a_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define kp1_a_SetAnalogMode()      do { ANSELHbits.ANS12 = 1; } while(0)
#define kp1_a_SetDigitalMode()     do { ANSELHbits.ANS12 = 0; } while(0)

// get/set kp1_b aliases
#define kp1_b_TRIS                 TRISBbits.TRISB1
#define kp1_b_LAT                  LATBbits.LATB1
#define kp1_b_PORT                 PORTBbits.RB1
#define kp1_b_WPU                  WPUBbits.WPUB1
#define kp1_b_ANS                  ANSELHbits.ANS10
#define kp1_b_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define kp1_b_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define kp1_b_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define kp1_b_GetValue()           PORTBbits.RB1
#define kp1_b_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define kp1_b_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define kp1_b_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define kp1_b_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define kp1_b_SetAnalogMode()      do { ANSELHbits.ANS10 = 1; } while(0)
#define kp1_b_SetDigitalMode()     do { ANSELHbits.ANS10 = 0; } while(0)

// get/set kp1_c aliases
#define kp1_c_TRIS                 TRISBbits.TRISB2
#define kp1_c_LAT                  LATBbits.LATB2
#define kp1_c_PORT                 PORTBbits.RB2
#define kp1_c_WPU                  WPUBbits.WPUB2
#define kp1_c_ANS                  ANSELHbits.ANS8
#define kp1_c_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define kp1_c_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define kp1_c_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define kp1_c_GetValue()           PORTBbits.RB2
#define kp1_c_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define kp1_c_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define kp1_c_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define kp1_c_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define kp1_c_SetAnalogMode()      do { ANSELHbits.ANS8 = 1; } while(0)
#define kp1_c_SetDigitalMode()     do { ANSELHbits.ANS8 = 0; } while(0)

// get/set kp1_d aliases
#define kp1_d_TRIS                 TRISBbits.TRISB3
#define kp1_d_LAT                  LATBbits.LATB3
#define kp1_d_PORT                 PORTBbits.RB3
#define kp1_d_WPU                  WPUBbits.WPUB3
#define kp1_d_ANS                  ANSELHbits.ANS9
#define kp1_d_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define kp1_d_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define kp1_d_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define kp1_d_GetValue()           PORTBbits.RB3
#define kp1_d_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define kp1_d_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define kp1_d_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define kp1_d_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define kp1_d_SetAnalogMode()      do { ANSELHbits.ANS9 = 1; } while(0)
#define kp1_d_SetDigitalMode()     do { ANSELHbits.ANS9 = 0; } while(0)

// get/set kp2_a aliases
#define kp2_a_TRIS                 TRISBbits.TRISB4
#define kp2_a_LAT                  LATBbits.LATB4
#define kp2_a_PORT                 PORTBbits.RB4
#define kp2_a_WPU                  WPUBbits.WPUB4
#define kp2_a_ANS                  ANSELHbits.ANS11
#define kp2_a_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define kp2_a_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define kp2_a_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define kp2_a_GetValue()           PORTBbits.RB4
#define kp2_a_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define kp2_a_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define kp2_a_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define kp2_a_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define kp2_a_SetAnalogMode()      do { ANSELHbits.ANS11 = 1; } while(0)
#define kp2_a_SetDigitalMode()     do { ANSELHbits.ANS11 = 0; } while(0)

// get/set kp2_b aliases
#define kp2_b_TRIS                 TRISBbits.TRISB5
#define kp2_b_LAT                  LATBbits.LATB5
#define kp2_b_PORT                 PORTBbits.RB5
#define kp2_b_WPU                  WPUBbits.WPUB5
#define kp2_b_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define kp2_b_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define kp2_b_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define kp2_b_GetValue()           PORTBbits.RB5
#define kp2_b_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define kp2_b_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define kp2_b_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define kp2_b_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)

// get/set kp2_c aliases
#define kp2_c_TRIS                 TRISBbits.TRISB6
#define kp2_c_LAT                  LATBbits.LATB6
#define kp2_c_PORT                 PORTBbits.RB6
#define kp2_c_WPU                  WPUBbits.WPUB6
#define kp2_c_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define kp2_c_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define kp2_c_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define kp2_c_GetValue()           PORTBbits.RB6
#define kp2_c_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define kp2_c_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define kp2_c_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define kp2_c_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set kp2_d aliases
#define kp2_d_TRIS                 TRISBbits.TRISB7
#define kp2_d_LAT                  LATBbits.LATB7
#define kp2_d_PORT                 PORTBbits.RB7
#define kp2_d_WPU                  WPUBbits.WPUB7
#define kp2_d_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define kp2_d_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define kp2_d_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define kp2_d_GetValue()           PORTBbits.RB7
#define kp2_d_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define kp2_d_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define kp2_d_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define kp2_d_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set lcd_d7 aliases
#define lcd_d7_TRIS                 TRISDbits.TRISD2
#define lcd_d7_LAT                  LATDbits.LATD2
#define lcd_d7_PORT                 PORTDbits.RD2
#define lcd_d7_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define lcd_d7_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define lcd_d7_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define lcd_d7_GetValue()           PORTDbits.RD2
#define lcd_d7_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define lcd_d7_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)

// get/set lcd_d6 aliases
#define lcd_d6_TRIS                 TRISDbits.TRISD3
#define lcd_d6_LAT                  LATDbits.LATD3
#define lcd_d6_PORT                 PORTDbits.RD3
#define lcd_d6_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define lcd_d6_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define lcd_d6_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define lcd_d6_GetValue()           PORTDbits.RD3
#define lcd_d6_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define lcd_d6_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)

// get/set lcd_d5 aliases
#define lcd_d5_TRIS                 TRISDbits.TRISD4
#define lcd_d5_LAT                  LATDbits.LATD4
#define lcd_d5_PORT                 PORTDbits.RD4
#define lcd_d5_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define lcd_d5_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define lcd_d5_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define lcd_d5_GetValue()           PORTDbits.RD4
#define lcd_d5_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define lcd_d5_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set lcd_d4 aliases
#define lcd_d4_TRIS                 TRISDbits.TRISD5
#define lcd_d4_LAT                  LATDbits.LATD5
#define lcd_d4_PORT                 PORTDbits.RD5
#define lcd_d4_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define lcd_d4_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define lcd_d4_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define lcd_d4_GetValue()           PORTDbits.RD5
#define lcd_d4_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define lcd_d4_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

// get/set lcd_e aliases
#define lcd_e_TRIS                 TRISDbits.TRISD6
#define lcd_e_LAT                  LATDbits.LATD6
#define lcd_e_PORT                 PORTDbits.RD6
#define lcd_e_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define lcd_e_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define lcd_e_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define lcd_e_GetValue()           PORTDbits.RD6
#define lcd_e_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define lcd_e_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

// get/set lcd_rs aliases
#define lcd_rs_TRIS                 TRISDbits.TRISD7
#define lcd_rs_LAT                  LATDbits.LATD7
#define lcd_rs_PORT                 PORTDbits.RD7
#define lcd_rs_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define lcd_rs_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define lcd_rs_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define lcd_rs_GetValue()           PORTDbits.RD7
#define lcd_rs_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define lcd_rs_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
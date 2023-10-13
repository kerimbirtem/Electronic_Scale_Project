/* 
 * File:   keypad1.h
 * Author: kerim
 *
 * Created on December 29, 2022, 6:22 PM
 */

#ifndef KEYPAD1_H
#define	KEYPAD1_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* KEYPAD1_H */

#define KP1_DA PORTAbits.RA0 
#define KP2_DA PORTAbits.RA1


bool tare_button = 0,function_button = 0,enter_button=0,button_C=0,button_kgg=0,cntrst_up=0,cntrst_down=0,memory_write=0,bool_memory=0 ;


float memory[4][3] = {
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}
};


void keypads_read(void);
    
void keypad1_read(void);
void keypad2_read(void);    
float keypad1_read_br();
float keypad2_memory_read();

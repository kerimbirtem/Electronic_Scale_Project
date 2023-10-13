

#include "mcc_generated_files/mcc.h"
#include "keypad1.h"


/* char keypad1[16] = {'7', '8', '9', 'T',
                       '4', '5', '6', 'F',
                       '1', '2', '3', 'kg/g',
                       'C', '0', '.', 'Ent'};

*/
char const keypad1[16] = {'T','9','8','7','F','6','5','4','kgg','3','2','1','Ent','.','0','C'};
int i=0;



void keypads_read(void){
    
    if(KP1_DA==1) keypad1_read();
    if(KP2_DA==1){
        keypad2_read();
        keypad2_memory_read();
}

}


void keypad1_read(void){
   
    int data_74c922;
    
    
    data_74c922 = PORTB>>4;
    
    if(data_74c922 == 0 || data_74c922 == 4 || data_74c922 == 8 || data_74c922 == 9 || data_74c922 == 12 ){
        
          
        
            switch (data_74c922) {
                
            case 0:                                                             // tare button 
             tare_button =1;
             
             break;
             
             
            case 4:
              function_button += function_button ;                              //F button 
               __delay_ms(100);

             break;
               
            case 8:
               button_kgg = !button_kgg;
             break;
            case 9:
                button_C =1 ;
             break;
             
            case 12:
                enter_button = 1;
            break;
                default:  
              break;  
            }   
        
        
        
        
        
        
        
        
        
        
         }
     
    }






float keypad1_read_br(){
    
    
   float br_fyt_key;
   int data_74c922;
   char key_value,br_fyt_str_key[5];
    
   while(KP1_DA){
       
        data_74c922 = PORTB>>4;
        
       if(data_74c922 != 0 && data_74c922 != 4 && data_74c922 != 8 && data_74c922 != 9 && data_74c922 != 12 ){
            
            key_value =keypad1[data_74c922];
            
            
            br_fyt_str_key[i] = key_value;                                      // write the characters from keypad1 key.
            i=i++;
            if(i==5) i =0;
            
            sscanf(br_fyt_str_key, "%.2f", &br_fyt_key);
            
          __delay_ms(100);
           return br_fyt_key;
       }     
        /*if(data_74c922==9){ button_C olarak mainde yap?ld?.
            br_fyt_key = 00.00;
        }*/
       
   }   
}






void keypad2_read(void){
    
    
    
    int data_74c922;

    
    data_74c922 = PORTB & 0x0F;
    
     if(data_74c922 == 0 || data_74c922 == 4 || data_74c922 == 8 || data_74c922 == 12 ){
    
      
         switch (data_74c922) {
                
            case 0:                                                             // Fonksiyonsuz ?uanl?k
             
             
             break;
             
             
            case 4:
                cntrst_up=1;
             break;
               
            case 8:
               cntrst_down=1;
             break;
             
            case 12:
                memory_write=1;
            break;
                default:  
              break;  
            }   
         
     }
}


float keypad2_memory_read(){
    
    int data_74c922;
    int  mi,mj;
    float mij;
    data_74c922 = PORTB & 0x0F;
    
     if(data_74c922 != 0 && data_74c922 != 4 && data_74c922 != 8 && data_74c922 != 12 ){
    
         bool_memory=1;
      
         switch (data_74c922) {
                
            case 1:                                                             
                mi=0;
                mj=2;
             break;
             
            case 2:
                mi=0;
                mj=1;   
             break;
            case 3:
                mi=0;
                mj=0;
             break;
            case 5:
                mi=1;
                mj=2;
            break;
            case 6:                                                             
                mi=1;
                mj=1;
             break;
            case 7:
                mi=1;
                mj=0;
             break; 
            case 9:
                mi=2;
                mj=2;
             break;
            case 10:
                mi=2;
                mj=1;   
            break;
            case 11:                                                             
                mi=2;
                mj=0;
             break;
            case 13:
                mi=3;
                mj=2;
             break; 
            case 14:
                mi=3;
                mj=1;
             break; 
            case 15:
                mi=3;
                mj=0;
            break;
            
                default:  
              break;  
            }   
      
         mij= mi+(mj%10)/10;
         return mij;                                                                 //tuple ??
     }
    
    
}




    
   
    

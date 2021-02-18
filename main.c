/*
 * File:   main.c
 * Author: 20185074
 *
 * Created on 3 de Fevereiro de 2021, 15:04
 */

#include "config.h"
#include <xc.h>



void contatores_init( void )
{
    
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD7 = 0;
   
}

void botoes_init( void )

{  
    TRISDbits.TRISD0 = 1;
    TRISDbits.TRISD1 = 1;
}
void botao_ligar()
{  
    PORTDbits.RD1 = 1;   
}
void botao_desligar()
{  
    PORTDbits.RD0 = 0;   
}
int s1_status(void)
{  
    return(PORTDbits.RD1);  
}
int s0_status(void)
{  
    return(PORTDbits.RD0);  
}
int k1_status(void)
{  
    return(PORTDbits.RD7);  
}
void  k1 (int estado)
{  
    PORTDbits.RD7 = estado;  
}
void  k2 (int estado)
{  
    PORTDbits.RD6 = estado;  
}
void  k3 (int estado)
{  
    PORTDbits.RD5 = estado;  
}



void main(void)
{
    contatores_init();
    botoes_init();
    
    while( 1 )  
    {
        
        
        if(s1_status() == 1 && k1_status() == 0)
            
        {
            
          k1 (1);
          k2 (1);
          __delay_ms(2000);
          k2 (0);
          __delay_ms(1000);
          k3 (1);
          
        } 
        if(s0_status() == 1 && k1_status() == 1)
        {

          k1 (0);
          k2 (0);
          k3 (0);
        }
    }    
}
    



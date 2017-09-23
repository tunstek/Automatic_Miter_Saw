/* 
 * File:   main.c
 * Author: Keith
 *
 * Created on 05 July 2016, 20:28
 */



// DSPIC30F4012 Configuration Bit Settings

// 'C' source line config statements

// FOSC
#pragma config FPR = XTL                // Primary Oscillator Mode (XTL)
#pragma config FOS = LPRC               // Oscillator Source (Internal Low-Power RC)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_64          // POR Timer Value (64ms)
#pragma config BODENV = BORV20          // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_OFF          // PBOR Enable (Disabled)
#pragma config LPOL = PWMxL_ACT_HI      // Low-side PWM Output Polarity (Active High)
#pragma config HPOL = PWMxH_ACT_HI      // High-side PWM Output Polarity (Active High)
#pragma config PWMPIN = RST_IOPIN       // PWM Output Pin Reset (Control with PORT/TRIS regs)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enabled)

// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = CODE_PROT_OFF      // General Segment Code Protection (Disabled)

// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <libpic30.h>
#include <p30F4012.h>


#include <stdio.h>
#include <stdlib.h>




/*
 * 
 */


int main(void) {
    
    
    ADPCFG = 0xFFFF; //Configure all IO (B) as Digital
    
    TRISB = 0x0002; //outputs

    TRISE = 0x0001; //outputs EXCEPT RE0 (enable))
   



   //  *** RESET SAW ***
    
    //let up the saw
    LATBbits.LATB0 = 0;
    __delay32(102400); //*** DELAY FOR 0.8s @ 0.128 MIPS
            
    //  *** END RESET ***
    

    while(1) {
        

        if(PORTBbits.RB1 == 0) {
            //If enable is LOW

        	//Start the saw motor
        	//LATEbits.LATE1 = 0; 

            //Bring down the saw blade
            LATBbits.LATB0 = 1;
            __delay32(102400); //*** DELAY FOR 0.8s @ 0.128 MIPS
            //__delay32(70400); //*** DELAY FOR 0.55s @ 0.128 MIPS
        	
            
            //Bring back up the saw blade 
            LATBbits.LATB0 = 0;
            
        	//STOP the saw motor
        	//LATEbits.LATE1 = 1;

        	//Turn on solonoid
        	//LATEbits.LATE2 = 0;


        	//*** DELAY FOR 1 FULL REVOLUTION OF MOTOR
            //__delay32(12000); //*** DELAY FOR 0.106s @ 0.128 MIPS


        	

             //__delay32(64000); //*** DELAY FOR 0.5s @ 0.128 MIPS
            //__delay32(102400); //*** DELAY FOR 0.8s @ 0.128 MIPS


        	//Turn off solonoid
        	//LATEbits.LATE2 = 1;


        	//ALLOW FOR THE SPRINGS TO RESET
        	//__delay32(128000); //*** DELAY FOR 1s @ 0.128 MIPS
            
            //Combine?
            __delay32(230400); //*** DELAY FOR 1.8s @ 0.128 MIPS



        }
        else {
            
            //Turn off solonoid
        	//LATEbits.LATE2 = 1;
            //Stop the saw motor
        	//LATEbits.LATE1 = 1;
            
            //Let up the saw
        	LATBbits.LATB0 = 0;
            
        }
    
    }
    
    return (EXIT_SUCCESS);
}



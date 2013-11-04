#include <device.h>

#include "fft.h" // FFT Processing Libraries
#include "state.h"  // FFT Beat State Structs
#include "clock.h"


#define ADC_GAIN (100)
#define ADC_SCALE (256.0/4096.0)



// FFT Monitoring Values
// ----------------------------------------------------------------
uint16 adcResult = 0;

double max,zero=0;
unsigned int global_i=0;         //index
unsigned int ind;         
unsigned int endl=65535;  //uart tag


// FFT State Values
// ----------------------------------------------------------------
BeatState beat1, beat2;


void UARTPrintMod(){    //send ABSOLUTE VALUE dat
    char output[32];
    //UART_PutChar('D');
    int i;
    for(i=0;i<N_points;i++){
        // Format output as 2 number hex digits (max value 255)
        sprintf(output, " %02x", (int)(mod[i]));
        UART_PutString(output);
    }
    Crlf();
}


void UARTPrintModAvg(){    //send ABSOLUTE VALUE dat
    char output[32];  //C character output buffer
    //UART_PutChar('A');
    int i;
    for(i=0;i<N_points/N_avg/2;i++){
        // Format output as 2 number hex digits (max value 255)
        sprintf(output, " %02x", (int)(mod_avg[i]));
        UART_PutString(output);
    }
    Crlf();
}


void UARTPrintFFTBeatInfo(){
    char output[32];  //C character output buffer
    UART_PutChar('F'); // Indicates start of output
    int i;
    for(i=0;i<N_points/N_avg/2;i++){
        // Format output as 2 number hex digits (max value 255)
        sprintf(output, " %02x", (int)(mod_avg[i]));
        UART_PutString(output);
    }
    UART_PutChar(' '); 
    UART_PutChar('B');  // Indicates start of output
    // Beat1 is bit0, Beat2 is bit 1
    if(beat1.isBeat && beat2.isBeat){
        //UART_PutChar(0x03);
        UART_PutChar('3');
    }else if(beat1.isBeat && !beat2.isBeat){
        //UART_PutChar(0x01);
        UART_PutChar('1');
    }else if(!beat1.isBeat && beat2.isBeat){
        //UART_PutChar(0x02);
        UART_PutChar('2');
    }else{
        //UART_PutChar(0x00);
        UART_PutChar('0');
    }
    Crlf();
}


void UARTPrintFFTBeatInfo8051(){
    //char output[32];  //C character output buffer
    UART_PutChar(0xFF); // Indicates start of output
    int i;
    uint8 output;
    for(i=0;i<N_points/N_avg/2;i++){
        // Format output as 2 number hex digits (max value 255)
        //sprintf(output, " %02x", (int)(mod_avg[i]));
        //UART_PutString(output);
        output = (int)(mod_avg[i]);
        // We must ensure no outputs result in our indication char (FF)
        if(output == 0xFF){
            output = 0xFE;
        }
        UART_PutChar(output);
    }
    //UART_PutChar(' '); 
    //UART_PutChar('B');  // Indicates start of output
    // Beat1 is bit0, Beat2 is bit 1
    if(beat1.isBeat && beat2.isBeat){
        UART_PutChar(0x03);
        //UART_PutChar('3');
    }else if(beat1.isBeat && !beat2.isBeat){
        UART_PutChar(0x01);
        //UART_PutChar('1');
    }else if(!beat1.isBeat && beat2.isBeat){
        UART_PutChar(0x02);
        //UART_PutChar('2');
    }else{
        UART_PutChar(0x00);
        //UART_PutChar('0');
    }
    //Crlf();
}


void main(){	
    Init();                             // Initialize the PSoC

/*
    char output[32];

    while(1){// Main loop 
        if ( ADC_SAR_1_IsEndConversion(1) ){  
            //adcResult =ADC_DelSig_1_GetResult16() * ADC_SCALE;       
            adcResult =ADC_SAR_1_GetResult16() * ADC_SCALE;       
        }   
        
        // Format output as 2 number hex digits (max value 255)
        sprintf(output, "%02x ", (int)(adcResult));
        UART_PutString(output);
    }
    */

    while(1){
        // Loop endlessly
    }
}


void ProcessBeats(){
    long diff;
    
    // Process Beat 1
    diff = (getCurrentTimeMills() - beat1.lastTimeMills); 
    if(diff >BEAT_TIMEOUT_MILLS){
        if(mod_avg[beat1.frequency] > beat1.threshold){
            beat1.isBeat = true;
            beat1.lastTimeMills = getCurrentTimeMills();
        }else{
            beat1.isBeat = false;
        }
    }else{
        beat1.isBeat = false;
    }
    
    // Process Beat 2
    diff = (getCurrentTimeMills() - beat2.lastTimeMills); 
    if(diff >BEAT_TIMEOUT_MILLS){
        if(mod_avg[beat2.frequency] > beat2.threshold){
            beat2.isBeat = true;
            beat2.lastTimeMills = getCurrentTimeMills();
        }else{
            beat2.isBeat = false;
        }
    }else{
        beat2.isBeat = false;
    }
}


void ProcessFFT(){
    // Calculate Beat status
    ProcessBeats();
    // Send info over serial
    UARTPrintFFTBeatInfo8051();
    return;
}


void CalculateFFT(){
    if (ADC_SAR_1_IsEndConversion(1) ){  
        //data_re[i]=ADC_DelSig_1_GetResult16() * ADC_GAIN;  
        data_re[global_i] =ADC_SAR_1_GetResult16() * ADC_GAIN;       

        global_i++;
    } 

    if(global_i==N_points){
    	FFT(1,exponent,data_re,data_imm );    // Run FFT
        FFTAVG();   // Calculate AVGs
        
        ProcessFFT();  // Process the FFT result based on the stae

        ResetFFT();  // Reset FFT after processing 
        global_i=0;
    }// end for i==N
}


void ProcessUARTRX(uint8 input){
    switch(input){
        case 'F':
            
            break;
        case 'B':
            break;
    }
}

void InitBeatStates(){
    // Init beat1
    beat1.frequency = 0;
    beat1.threshold = 128;
    beat1.lastTimeMills = 0; // Get the current time. 
    beat1.isBeat = false;
    // Init beat2
    beat2.frequency = 4;
    beat2.threshold = 80;
    beat2.lastTimeMills = 0; // Get the current time.
    beat2.isBeat = false;
}


void Init() {
    PGA_1_Start();
    VDAC8_1_Start();
    
	LCD_Start();					    // initialize lcd
	LCD_ClearDisplay();
    
    CyGlobalIntEnable;  // Global interrupts enabled
    rx_int_Start();                     // start RX interrupt--look at this file under "Generated_Source"
                                        // for code that writes received bytes to LCD.
    
    UART_Start();                       // initialize UART
    UART_ClearRxBuffer();
    
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();

    // FFT Interrrupt enable
    FFT_ISR_Start();    
    FFT_ISR_Enable();
    
    // Clock Interrupt enable
    Clock_ISR_Start();    
    Clock_ISR_Enable();

    // Initialize the beat states
    InitBeatStates();
}


void Crlf(){   
    UART_PutChar(10);
    UART_PutChar(13);
}

/* [] END OF FILE */
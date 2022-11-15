/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/

/*==================[inclusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* Para definicines de tipos estandar */

/*==================[definiciones y macros]==================================*/
/* TODO Define system operating frequency */
/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        4000000L
#define _XTAL_FREQ      SYS_FREQ
#define FCY             SYS_FREQ/4

/* Definición de Bits de Configuración */
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
//#pragma config FOSC = INTRC_NOCLKOUT // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3/PGM pin io, low voltage programming disabled)
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// Definición de entradas y salidas
#define PIN_LED1    PORTEbits.RE2
#define TRIS_LED1   TRISEbits.TRISE2
#define PIN_LED2    PORTEbits.RE1
#define TRIS_LED2   TRISEbits.TRISE1
#define PIN_LED3    PORTEbits.RE0
#define TRIS_LED3   TRISEbits.TRISE0
#define PIN_LED4    PORTAbits.RA5
#define TRIS_LED4   TRISAbits.TRISA5

#define PIN_TEC1    PORTBbits.RB0
#define TRIS_TEC1   TRISBbits.TRISB0
#define PIN_TEC2    PORTBbits.RB1
#define TRIS_TEC2   TRISBbits.TRISB1
#define PIN_TEC3    PORTBbits.RB2
#define TRIS_TEC3   TRISBbits.TRISB2
#define PIN_TEC4    PORTBbits.RB3
#define TRIS_TEC4   TRISBbits.TRISB3

#define PIN_SEG_A   PORTDbits.RD0
#define TRIS_SEG_A  TRISDbits.TRISD0
#define PIN_SEG_B   PORTDbits.RD1
#define TRIS_SEG_B  TRISDbits.TRISD1
#define PIN_SEG_C   PORTDbits.RD2
#define TRIS_SEG_C  TRISDbits.TRISD2
#define PIN_SEG_D   PORTDbits.RD3
#define TRIS_SEG_D  TRISDbits.TRISD3
#define PIN_SEG_E   PORTDbits.RD4
#define TRIS_SEG_E  TRISDbits.TRISD4
#define PIN_SEG_F   PORTDbits.RD5
#define TRIS_SEG_F  TRISDbits.TRISD5
#define PIN_SEG_G   PORTDbits.RD6
#define TRIS_SEG_G  TRISDbits.TRISD6
#define PIN_SEG_P   PORTDbits.RD7
#define TRIS_SEG_P  TRISDbits.TRISD7

#define BUZZER      PORTCbits.RC0
#define TRIS_BUZZER TRISCbits.TRISC0

#define PIN_POTE    PORTAbits.RA0
#define TRIS_POTE   TRISAbits.TRISA0

//Pines de la UART
#define	TRIS_PICTX      TRISCbits.TRISC6
#define	PIN_PICTX       PORTCbits.RC6
#define	TRIS_PICRX      TRISCbits.TRISC7
#define	PIN_PICRX       PORTCbits.RC7
//Definición del Baudrate
#define	UART_BAUDRATE        9600




/*==================[definiciones de datos internos]=========================*/
 typedef enum{ 
    AIN0 = 0, AIN1, AIN2, AIN3, AIN4, AIN5, AIN6, AIN7, AIN8,
    AIN9, AIN10, AIN11, AIN12, AIN13, AIN_CVREF, AIN_FIXREF,
    VDD_CALC = 255        
} adcMap_t;
/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[funcion principal]======================================*/
void main(void) {
    // Configuración de IO
    ANSEL = 1;       
    ANSELH = 1;      
    TRIS_TEC1 = 1;              // Configuro la TEC1 como entrada
    TRIS_LED1 = 0;              // Configuro el LED1 como salida
    TRIS_TEC2 = 1;             
    TRIS_LED2 = 0;
    TRIS_TEC3 = 1;             
    TRIS_LED3 = 0;
    TRIS_TEC4 = 1;             
    TRIS_LED4 = 0;         
    
    TRIS_SEG_A = 0;
    TRIS_SEG_B = 0;
    TRIS_SEG_C = 0;
    TRIS_SEG_D = 0;
    TRIS_SEG_E = 0;
    TRIS_SEG_F = 0;
    TRIS_SEG_G = 0;
    TRIS_SEG_P = 0;
    PIN_SEG_A = 0;
    PIN_SEG_B = 0;
    PIN_SEG_C = 0;
    PIN_SEG_D = 0;
    PIN_SEG_E = 0;
    PIN_SEG_F = 0;
    PIN_SEG_G = 0;
    PIN_SEG_P = 0;
    TRIS_POTE = 1;    
    
    adcInit();
    uartInit();
    
    __delay_ms(100);
    
    adcRead_mV(VDD_CALC);
    uint16_t resultado;
    
    while(1) {                  // Super loop
            resultado = adcRead(AIN0);
        //    printf("%dmV",adcRead_mV(AIN0));
            uartReadByte(adcRead_mV(AIN0));
            __delay_ms(1000);
    }
}

void adcInit(void) {
    FVREN = 1;
    VCFG0 = 0;      // VDD
    VCFG1 = 0;      // VSS
    ADFM  = 1;      // Ajuste a derecha         
    ADCS0 = 1;      // clock interno
    ADCS1 = 1;
    ADON  = 1;      // enciendo conversor
}

uint16_t adcRead(adcMap_t analogInput){
    
    ADCON0bits.CHS = analogInput;
    __delay_us(50);
    GO = 1;
    while(GO==1);
    return (ADRESL + ((uint16_t) ADRESH << 8));
    
}

uint16_t adcRead_mV(adcMap_t analogInput){
    static uint16_t nAdcRef = 0;
    
    if (analogInput == VDD_CALC){
        nAdcRef = adcRead(VDD_CALC);
        return ((1023UL*600U) / nAdcRef); 
    }
    else{
        return ((600UL*adcRead(analogInput)) / nAdcRef);
    }   
}

void uartInit(void) {
#if((SYS_FREQ - UART_BAUDRATE*16L)/(UART_BAUDRATE*16L)) > 255 //Si necesita High Baud Rate
#if	(SYS_FREQ - UART_BAUDRATE*64L)/(UART_BAUDRATE*64L) > 255
#error Baud Rate demasiado Bajo
#endif
    SPBRG = (SYS_FREQ - UART_BAUDRATE * 64L) / (UART_BAUDRATE * 64L); //SPBRG para Low Baud Rate
    BRGH = 0;   //Selecciona Low Baud Rate
#else
    SPBRG = (SYS_FREQ - UART_BAUDRATE * 16L) / (UART_BAUDRATE * 16L); //SPBRG para High Baud Rate
    BRGH = 1;   //Selecciona High Baud Rate
#endif
    SYNC = 0;   //Selecciona Modo Asincronico
    SPEN = 1;   //Habilita Puerto Serie
    TRISC7 = 1;
    TRISC6 = 1;
    CREN = 1;   //Habilita Recepción continua
    TXEN = 1;   //Habilita Transmisión
}

void putch(char data) {
    while (!TXIF)   //Espera que haya espacio en la FIFO (bloquea poco tiempo)
        continue;
    TXREG = data;   //Envía el byte
}

void uartWriteByte( uint8_t value ){
    while (!TXIF)   //Espera que haya espacio en la FIFO (bloquea poco tiempo)
        continue;
    TXREG = value;  //Envía el byte
}

char getch(void) {
    while (!RCIF)   //Espera hasta que haya un byte recibido (bloqueante)
        continue;
    return RCREG;   //retorna lo recibido
}

__bit uartReadByte( uint8_t* receivedByte ){
   if ( RCIF ){     //Si hay por lo menos un byte recibido
      *receivedByte = RCREG;    //lo coloca en el lugar de destino
      return 1;     //Retorna 1 para indicar que ha recibido
   }
   return 0;        //Retorna 0 para indicar que no ha recibido
}

char getche(void) {
    char data;
    while (!RCIF)   //Espera hasta que haya un byte recibido (bloqueante)
        continue;
    data = RCREG;   //almacena lo recibido
    while (!TXIF)   //Espera que haya espacio en la FIFO (bloqueante poco tiempo)
        continue;
    TXREG = data;   //Envía el byte
    return data;    //retorna lo recibido
}
/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
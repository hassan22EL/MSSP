/*
 * File:   Serial Peripheral Interface
 * Author: Hassan Elsaied Mohammed Mohammed
 * Comments:
 * Revision history: 
 */
#ifndef _SPI_H
#define	_SPI_H

#include <xc.h> // include processor files - each processor file is guarded.

typedef enum {
    Master_OSC_Div4 = 0x20, //SSPCON=0x20
    Master_OSC_Div16 = 0x21, //SSPCON=0x21
    Master_OSC_Div64 = 0x22, //SSPCON=0x22
    Master_OSC_TRM2 = 0x23, //SSPCON=0x23
    SPI_Slave_SS_EN = 0x24, //SSPCON=0x24
    SPI_Slave_SS_DIS = 0x25F//SSPCON=0x25
} SPI_Type;

typedef enum {
    Data_Simple_Middle = 0x00, //SSPSTAT=0x00
    Data_Simple_End = 0x10 //SSPSTAT=0x10
} SPI_Data_Sample;

typedef enum {
    SPI_Clock_Idle_High = 0x08,
    SPI_Clock_Idle_Low = 0x00
} SPI_Colck_Idle;

typedef enum {
    SPI_Idle_2_Active = 0x00, //SSPSTAT=0x00
    SPI_Active_2_Idle = 0x40 //SSPSTAT=0x40
} SPI_Tranmit_Edge;
void SPI_INIT(SPI_Type, SPI_Data_Sample, SPI_Colck_Idle, SPI_Tranmit_Edge);
static void SPI_Receive_Wait();
void SPI_Write(char Data);
unsigned SPI_Data_Ready();
char SPI_Read();

#endif	/* _SPI_H */



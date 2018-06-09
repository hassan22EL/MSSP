/*
 * File:   SPI.c
 * Author: Hassan
 *
 * Created on March 4, 2018, 1:16 PM
 */


#include <xc.h>

#include "SPI.h"

void SPI_INIT(SPI_Type sType, SPI_Data_Sample sDataSample, SPI_Colck_Idle sClockIdle, SPI_Tranmit_Edge sTransmitEdge)
{
    TRISCbits.TRISC5 = 0; //open serial port out 
    if (sType & 0x04) // if Slave Mode 
    {
        SSPSTAT = sTransmitEdge;
        TRISCbits.TRISC3 = 1; //open serial port Data input 
    } else // if Master Mode
    {
        SSPSTAT = sDataSample;
        TRISCbits.TRISC3 = 0; //open serial port Data out
    }
    SSPCON = sType | sClockIdle;

}

static void SPI_Receive_Wait() {
    while (!SSPSTATbits.BF);

}

void SPI_Write(char Data) {
    SSPBUF = Data;
}

unsigned SPI_Data_Ready() {
    if (SSPSTATbits.BF)
        return 1;
    else
        return 0;
}

char SPI_Read() {
    SPI_Receive_Wait();
    return SSPBUF;

}
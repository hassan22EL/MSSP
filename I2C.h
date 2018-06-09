
/*
 * ************************************************ 
 * File:   Inter Integrated circuit protocol      *
 * Author: Hassan Elsaied Mohammed Mohammed       *
 * Comments:                                      *
 * Revision history:                              *
 * ************************************************
 */
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _I2C_H
#define	_I2C_H
#include <xc.h> // include processor files - each processor file is guarded.  
#ifndef __XC8
#warning Header file I2C.h included directly. Use #include <xc.h> instead.
#endif


void I2C_Master_INIT(const unsigned long clock);
/*
 **********************************************************************
 *        (??? ??????? ?? ????? ?? ?? ?? ???? ??? ??? ???? )          *
 * I2C_Master_wait not return values but the Recorder the sate        *
 * of the Master synch serial port  is the status Register Contains   *
 * bits Setting you this bit && 0x04 the Start bit values zero or one *
 * for example if the status register as a values 0x3F and with 0x04  *
 * the result = 0x04 the Start bit ==1 the result = 0x04 if Start bit *
 * equals zero the Status Register depended of the Start Bit such as  *
 * Start bit equal zero start bit was not detected last and Start bit *
 * equal one indicates that a Start bit has been Detected Last        *
 * this method wait a Start bit indicates that a Start bit has been   *
 *  Detected Last  the break loop when Start bit = 1                  *
 * and Register SSPCON2 Result SSPCON2 & 0x1F this bit open Start bit *
 * and Stop bit and Receiver bit on and Repeated Start Condition      *
 * Enabled bit and ACKEN Enable bit                                   *         
 * ?Wait method For the Enable Sate Start bit and Start bit and Stop  *
 * and other                                                          *
 * ********************************************************************
 */
void I2C_Master_Wait();
/*
 ********************************************************************************
 * Send Data From Micro Processor To Serial Synch PORT                          *
 * this method Dependent the SSPSR ( Synch Serial PORT Shift Register)          *
 * the Data From MP Store into SSPBUF(Synch Serial PORT Buffer Register )       *
 * the Buffer Register Store Data just Micro second the Move Data From SSPBUF   *
 * to SSPSR and SSPSR shift Data bit or bit each Clock cycle this Register Synch*
 * the SSPADD holes the Baud Rate of the Data                                   *
 * Store Data Byte From Data Bus to SSPBUF Register when interrupt              *
 * Flag is one  if interrupt Flag is zero not Transfer Byte into Register       *
 ********************************************************************************
 * */
void I2C_Master_Write(unsigned int DataByte);
/*
 ********************************************************************************
 * Read  Data From Peripheral(PH) To CPU                                        *
 * this method Dependent the SSPSR ( Synch Serial PORT Shift Register)          *
 * the Data From PH Store  Register  SSPSR bit and bit each clock cycle         *
 *  the Store into SSPSR Register exit Transfer Data From SSPSR Register        *
 * SSPBUF just one cycle   and the bit RW From Status Register Enable Write     *
 * Data From SSPBUF to Data Bus of this micro Processor                         *
 * Store Data Byte From Data Bus to SSPBUF Register when interrupt              *
 * Flag is one  if interrupt Flag is zero not Transfer Byte into Register       *
 ********************************************************************************
 * */
unsigned int I2C_Master_Read(unsigned char a);

/* 
 *******************************************
 * this method Enable Start Bit after Wait *
 * *****************************************
 */
void I2C_Master_Start();
/* 
 ***************************************************************
 * this method Enable  Repeated Start Condition Bit after Wait *
 * ************************************************************
 */
void I2C_Master_Respeated() ;
/* 
 *******************************************
 * this method Enable Stop Bit after Wait *
 * *****************************************
 */
void I2C_Master_Stop();
/*
 * *************************************************************************************************
 * EEPROM Serial PORT I2C any Device can be write into or Read From                                *
 * this Device has a code and address  can be Write into or Read From                              * 
 * have Code and address and select Read or Write operation                                        * 
 *  Assume code the serial EEPROM (I2C) is defined as  1010                                        *
 * and Read or Write bit selected by RW bit if RW=0                                                *
 * the operation Read operation or RW =1 operation Write operation                                 *
 * For Example EEPROM space 4k Words (4096 Word) the address bit = 12 bit can Access 4k Word       *
 * this Method Control Store the address and Code Device and RW into SSPBUF                        *
 * For Example this Code CCCBBBR                                                                   *
 * CCC this bits select Code and BBB this Bits select Address and R Read or Write operations       *
 * this method address three  bits and code Four bits and   and RW = one bit  the Code= 8 bit      * 
 * *************************************************************************************************      
 */
void I2C_Master_ControlByte(unsigned int adderss, unsigned int RW);
#endif	/*_I2C_H */
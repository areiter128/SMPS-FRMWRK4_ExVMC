/*LICENSE ********************************************************************
 * Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 * ***************************************************************************/
/* @@config_bits.c
 * ****************************************************************************
 * File:   config_bits.c
 * Author: M91406
 *
 * Description:
 * - 
 *  
 * History:
 * Created on July 03, 2017, 09:32 PM
 ******************************************************************************/

#include "p33SMPS_devices.h"

#if defined (_P33SMPS_TLAL_)

//------------------------------------------------------------------------------
// DSPIC33EPxxGS202 Configuration Bit Settings
//------------------------------------------------------------------------------
// FSEC
#pragma config BWRP = OFF               // Boot Segment Write-Protect bit (Boot Segment may be written)
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSEN = OFF               // Boot Segment Control bit (No Boot Segment)
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF               // Configuration Segment Write-Protect bit (Configuration Segment may be written)
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = OFF            // Alternate Interrupt Vector Table bit (Disabled AIVT)

// FBSLIM
//#pragma config BSLIM = BSLIM            // Boot Segment Flash Page Address Limit bits (Boot Segment Flash page address  limit)

// FOSCSEL
#pragma config FNOSC = FRCPLL           // Oscillator Source Selection (Fast RC Oscillator with divide-by-N with PLL module (FRCPLL) )
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled)
#pragma config OSCIOFNC = ON           // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config IOL1WAY = OFF             // Peripheral pin select configuration bit (Allow only one reconfiguration)
#pragma config FCKSM = CSECMD           // Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled)
#pragma config PLLKEN = OFF             // PLL Lock Enable Bit (Clock switch will not wait for the PLL lock signal)

// FWDT
#pragma config WDTPOST = PS1            // Watchdog Timer Postscaler bits (1:1)
#pragma config WDTPRE = PR32            // Watchdog Timer Prescaler bit (1:32)
#pragma config WDTEN = OFF              // Watchdog Timer Enable bits (WDT and SWDTEN disabled)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
#pragma config WDTWIN = WIN75           // Watchdog Timer Window Select bits (WDT Windo is 75% of WDT period)

// FICD
#pragma config ICS = PGD3               // ICD Communication Channel Select bits (Communicate on PGEC3 and PGED3)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)

// FDEVOPT
#pragma config PWMLOCK = OFF            // PWMx Lock Enable bit (PWM registers may be written without key sequence)

// FALTREG
#pragma config CTXT1 = OFF				// Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits (Not Assigned)
#pragma config CTXT2 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits (Not Assigned)


#elif defined (_P33SMPS_TLAH_)

//------------------------------------------------------------------------------
// DSPIC33EPxxGS502 Configuration Bit Settings
//------------------------------------------------------------------------------
// FSEC
#pragma config BWRP = OFF               // Boot Segment Write-Protect bit (Boot Segment may be written)
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSEN = OFF               // Boot Segment Control bit (No Boot Segment)
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF               // Configuration Segment Write-Protect bit (Configuration Segment may be written)
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = OFF            // Alternate Interrupt Vector Table bit (Disabled AIVT)

// FBSLIM
//#pragma config BSLIM = BSLIM            // Boot Segment Flash Page Address Limit bits (Boot Segment Flash page address  limit)

// FOSCSEL
#pragma config FNOSC = FRCPLL           // Oscillator Source Selection (Fast RC Oscillator with divide-by-N with PLL module (FRCPLL) )
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled)
#pragma config OSCIOFNC = ON           // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config IOL1WAY = OFF             // Peripheral pin select configuration bit (Allow only one reconfiguration)
#pragma config FCKSM = CSECMD           // Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled)
#pragma config PLLKEN = OFF             // PLL Lock Enable Bit (Clock switch will not wait for the PLL lock signal)

// FWDT
#pragma config WDTPOST = PS1            // Watchdog Timer Postscaler bits (1:1)
#pragma config WDTPRE = PR32            // Watchdog Timer Prescaler bit (1:32)
#pragma config WDTEN = OFF              // Watchdog Timer Enable bits (WDT and SWDTEN disabled)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
#pragma config WDTWIN = WIN75           // Watchdog Timer Window Select bits (WDT Windo is 75% of WDT period)

// FICD
#pragma config ICS = PGD3               // ICD Communication Channel Select bits (Communicate on PGEC3 and PGED3)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config BTSWP = OFF              // BOOTSWP Instruction Enable/Disable bit (BOOTSWP instruction is disabled)

// FDEVOPT
#pragma config PWMLOCK = OFF            // PWMx Lock Enable bit (PWM registers may be written without key sequence)
#pragma config ALTI2C1 = OFF            // Alternate I2C1 Pin bit (I2C1 mapped to SDA1/SCL1 pins)
#pragma config ALTI2C2 = OFF            // Alternate I2C2 Pin bit (I2C2 mapped to SDA2/SCL2 pins)
#pragma config DBCC = OFF               // DACx Output Cross Connection bit (No Cross Connection between DAC outputs)

// FALTREG
#pragma config CTXT1 = OFF				// Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits (Not Assigned)
#pragma config CTXT2 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits (Not Assigned)



#elif defined (_P33SMPS_TLAY_)

//------------------------------------------------------------------------------
// DSPIC33EPxxGS502 Configuration Bit Settings
//------------------------------------------------------------------------------
// FSEC
#pragma config BWRP = OFF               // Boot Segment Write-Protect bit (Boot Segment may be written)
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSEN = OFF               // Boot Segment Control bit (No Boot Segment)
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF               // Configuration Segment Write-Protect bit (Configuration Segment may be written)
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = OFF            // Alternate Interrupt Vector Table bit (Disabled AIVT)

// FBSLIM
//#pragma config BSLIM = BSLIM            // Boot Segment Flash Page Address Limit bits (Boot Segment Flash page address  limit)

// FOSCSEL
#pragma config FNOSC = FRCPLL           // Oscillator Source Selection (Fast RC Oscillator with divide-by-N with PLL module (FRCPLL) )
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config IOL1WAY = OFF            // Peripheral pin select configuration bit (Allow only one reconfiguration)
#pragma config FCKSM = CSECMD           // Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled)
//#pragma config PLLKEN = OFF           // PLL Lock Enable Bit (Clock switch will not wait for the PLL lock signal)

// FWDT
#pragma config WDTPOST = PS1            // Watchdog Timer Postscaler bits->1:1
#pragma config WDTPRE = PR128           // Watchdog Timer Prescaler bit->1:128
#pragma config WDTEN = SWDTEN           // Watchdog Timer Enable bits->WDT Enabled/Disabled (controlled using SWDTEN bit)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit->Watchdog Timer in Non-Window mode
#pragma config WDTWIN = WIN50           // Watchdog Timer Window Select bits->WDT Window is 50% of WDT period

// FICD
#pragma config ICS = PGD1               // ICD Communication Channel Select bits (Communicate on PGEC3 and PGED3)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config BTSWP = OFF              // BOOTSWP Instruction Enable/Disable bit (BOOTSWP instruction is disabled)

// FDEVOPT
#pragma config PWMLOCK = OFF            // PWMx Lock Enable bit (PWM registers may be written without key sequence)
#pragma config ALTI2C1 = OFF            // Alternate I2C1 Pin bit (I2C1 mapped to SDA1/SCL1 pins)
#pragma config ALTI2C2 = OFF            // Alternate I2C2 Pin bit (I2C2 mapped to SDA2/SCL2 pins)
#pragma config DBCC = OFF               // DACx Output Cross Connection bit (No Cross Connection between DAC outputs)

// FALTREG
#pragma config CTXT1 = OFF				// Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits (Not Assigned)
#pragma config CTXT2 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits (Not Assigned)


#elif defined (_P33SMPS_WACS_)

// FSEC
#pragma config BWRP = OFF               // Boot Segment Write-Protect bit (Boot Segment may be written)
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSEN = OFF               // Boot Segment Control bit (No Boot Segment)
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF               // Configuration Segment Write-Protect bit (Configuration Segment may be written)
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = OFF            // Alternate Interrupt Vector Table bit (Disabled AIVT)

// FBSLIM
#pragma config BSLIM = 0x1FFF           // Boot Segment Flash Page Address Limit bits (Boot Segment Flash page address  limit)

// FSIGN

// FOSCSEL
#pragma config FNOSC = FRC              // Oscillator Source Selection (Internal Fast RC (FRC))
#pragma config IESO = OFF               // Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function bit (OSC2 is general purpose digital I/O pin)
#pragma config FCKSM = CSECME           // Clock Switching Mode bits (Clock switching is enabled,  Fail-safe Clock Monitor is disabled)

// FWDT
#pragma config RCLKSEL = LPRC           // Watchdog Timer Clock Select bits (Always use LPRC)
#pragma config RWDTPS = PS1048576       // Run Mode Watchdog Timer Post Scaler select bits (1:1048576)
#pragma config SWDTPS = PS1048576       // Sleep Mode Watchdog Timer Post Scaler select bits (1:1048576)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer operates in Non-Window mode)
#pragma config WDTWIN = WIN75           // Watchdog Timer Window Select bits (WDT Window is 75% of WDT period)
#pragma config FWDTEN = ON_SW           // Watchdog Timer Enable bit (WDT controlled via SW, use WDTCON.ON bit)

// FPOR
//#pragma BORLVL = BOR200                 // Brown-Out Voltage is 2.00 V => currently not supported
#pragma config BSSO = NORMAL            // Boot Space Start Option (Normal startup operation after reset, execute instruction at 0x000000)

// FICD
#pragma config ICS = PGD2               // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
//#pragma config BTSWP = OFF              // BOOTSWP Instruction Enable/Disable bit (BOOTSWP instruction is disabled)

// FDMTIVTL
#pragma config DMTIVTL = 0xFFFF         // Lower 16 bits of 32 bit DMT window interval (0-0xFFFF) (Lower 16 bits of 32 bit DMT window interval (0-0xFFFF))

// FDMTIVTH
#pragma config DMTIVTH = 0xFFFF         // Upper 16 bits of 32 bit DMT window interval (0-0xFFFF) (Upper 16 bits of 32 bit DMT window interval (0-0xFFFF))

// FDMTCNTL
#pragma config DMTCNTL = 0xFFFF         // Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF) (Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF))

// FDMTCNTH
#pragma config DMTCNTH = 0xFFFF         // Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF) (Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF))

// FDMT
#pragma config DMTDIS = OFF             // Dead Man Timer Disable bit (Dead Man Timer is Disabled and can be enabled by software)

// FDEVOPT1
#pragma config ALTI2C1 = OFF            // Alternate I2C1 Pin bit (I2C1 mapped to SDA1/SCL1 pins)
#pragma config ALTI2C2 = OFF            // Alternate I2C2 Pin bit (I2C2 mapped to SDA2/SCL2 pins)
//#pragma config MCA = SINGLE             // Multi Cycle Access for program flash (Flash read accesses are 2 cycle to support maximum processor frequency of operation)
#pragma config MAXTEMP = t12n0          //  (20 ns flash access)
//#pragma config CFGAN14 = PIN            // Select input to ADC AN14 input channel (Device pin is input to AN14)
//#pragma config CFGAN15 = PIN            // Select input to ADC AN15 input channel (Device pin is input to AN15)

// FALTREG
#pragma config CTXT1 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits (Not Assigned)
#pragma config CTXT2 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits (Not Assigned)
#pragma config CTXT3 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits (Not Assigned)
#pragma config CTXT4 = OFF              // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits (Not Assigned)

// FMBXM
#pragma config MBXM0 = M2S              // Mailbox 0 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM1 = M2S              // Mailbox 1 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM2 = M2S              // Mailbox 2 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM3 = M2S              // Mailbox 3 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM4 = M2S              // Mailbox 4 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM5 = M2S              // Mailbox 5 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM6 = M2S              // Mailbox 6 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM7 = M2S              // Mailbox 7 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM8 = M2S              // Mailbox 8 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM9 = M2S              // Mailbox 9 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM10 = M2S             // Mailbox 10 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM11 = M2S             // Mailbox 11 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM12 = M2S             // Mailbox 12 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM13 = M2S             // Mailbox 13 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM14 = M2S             // Mailbox 14 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM15 = M2S             // Mailbox 15 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))

// FMBXHS1
#pragma config MBXHSA = MBX15           // Mailbox handshake protocol block A register assignment (MSIxMBXD15 assigned to mailbox handshake protocol block A)
#pragma config MBXHSB = MBX15           // Mailbox handshake protocol block B register assignment (MSIxMBXD15 assigned to mailbox handshake protocol block B)
#pragma config MBXHSC = MBX15           // Mailbox handshake protocol block C register assignment (MSIxMBXD15 assigned to mailbox handshake protocol block C)
#pragma config MBXHSD = MBX15           // Mailbox handshake protocol block D register assignment (MSIxMBXD15 assigned to mailbox handshake protocol block D)

// FMBXHS2
#pragma config MBXHSE = MBX15           // Mailbox handshake protocol block E register assignment (MSIxMBXD15 assigned to mailbox handshake protocol block E)
#pragma config MBXHSF = MBX15           // Mailbox handshake protocol block F register assignment (MSIxMBXD15 assigned to mailbox handshake protocol block F)
#pragma config MBXHSG = MBX15           // Mailbox handshake protocol block G register assignment (MSIxMBXD15 assigned to mailbox handshake protocol block G)
#pragma config MBXHSH = MBX15           // Mailbox handshake protocol block H register assignment (MSIxMBXD15 assigned to mailbox handshake protocol block H)

// FMBXHSEN
#pragma config HSAEN = OFF              // Mailbox A data flow control protocol block enable (Mailbox data flow control handshake protocol block disabled.)
#pragma config HSBEN = OFF              // Mailbox B data flow control protocol block enable (Mailbox data flow control handshake protocol block disabled.)
#pragma config HSCEN = OFF               // Mailbox C data flow control protocol block enable (Mailbox data flow control handshake protocol block enabled)
#pragma config HSDEN = OFF               // Mailbox D data flow control protocol block enable (Mailbox data flow control handshake protocol block enabled)
#pragma config HSEEN = OFF               // Mailbox E data flow control protocol block enable (Mailbox data flow control handshake protocol block enabled)
#pragma config HSFEN = OFF               // Mailbox F data flow control protocol block enable (Mailbox data flow control handshake protocol block enabled)
#pragma config HSGEN = OFF               // Mailbox G data flow control protocol block enable (Mailbox data flow control handshake protocol block enabled)
#pragma config HSHEN = OFF               // Mailbox H data flow control protocol block enable (Mailbox data flow control handshake protocol block enabled)

// FCFGPRA0
#pragma config CPRA0 = MSTR             // Pin RA0 Ownership Bits (Master core owns pin.)
#pragma config CPRA1 = MSTR             // Pin RA1 Ownership Bits (Master core owns pin.)
#pragma config CPRA2 = MSTR             // Pin RA2 Ownership Bits (Master core owns pin.)
#pragma config CPRA3 = MSTR             // Pin RA3 Ownership Bits (Master core owns pin.)
#pragma config CPRA4 = MSTR             // Pin RA4 Ownership Bits (Master core owns pin.)

// FCFGPRB0
#pragma config CPRB0 = MSTR             // Pin RB0 Ownership Bits (Master core owns pin.)
#pragma config CPRB1 = MSTR             // Pin RB1 Ownership Bits (Master core owns pin.)
#pragma config CPRB2 = SLV1             // Pin RB2 Ownership Bits (Slave 1 core owns pin.)  => S1_MCLR
#pragma config CPRB3 = SLV1             // Pin RB3 Ownership Bits (Slave 1 core owns pin.)  => S1_PGD2
#pragma config CPRB4 = SLV1             // Pin RB4 Ownership Bits (Slave 1 core owns pin.)  => S1_PGC2
#pragma config CPRB5 = MSTR             // Pin RB5 Ownership Bits (Master core owns pin.)
#pragma config CPRB6 = MSTR             // Pin RB6 Ownership Bits (Master core owns pin.)
#pragma config CPRB7 = MSTR             // Pin RB7 Ownership Bits (Master core owns pin.)
#pragma config CPRB8 = MSTR             // Pin RB8 Ownership Bits (Master core owns pin.)
#pragma config CPRB9 = MSTR             // Pin RB9 Ownership Bits (Master core owns pin.)
#pragma config CPRB10 = MSTR            // Pin RB10 Ownership Bits (Master core owns pin.)
#pragma config CPRB11 = MSTR            // Pin RB11 Ownership Bits (Master core owns pin.)
#pragma config CPRB12 = MSTR            // Pin RB12 Ownership Bits (Master core owns pin.)
#pragma config CPRB13 = MSTR            // Pin RB13 Ownership Bits (Master core owns pin.)
#pragma config CPRB14 = MSTR            // Pin RB14 Ownership Bits (Master core owns pin.)
#pragma config CPRB15 = MSTR            // Pin RB15 Ownership Bits (Master core owns pin.)

// FCFGPRC0
#pragma config CPRC0 = MSTR             // Pin RC0 Ownership Bits (Master core owns pin.)
#pragma config CPRC1 = MSTR             // Pin RC1 Ownership Bits (Master core owns pin.)
#pragma config CPRC2 = MSTR             // Pin RC2 Ownership Bits (Master core owns pin.)
#pragma config CPRC3 = MSTR             // Pin RC3 Ownership Bits (Master core owns pin.)
#pragma config CPRC4 = MSTR             // Pin RC4 Ownership Bits (Master core owns pin.)
#pragma config CPRC5 = MSTR             // Pin RC5 Ownership Bits (Master core owns pin.)
#pragma config CPRC6 = MSTR             // Pin RC6 Ownership Bits (Master core owns pin.)
#pragma config CPRC7 = MSTR             // Pin RC7 Ownership Bits (Master core owns pin.)
#pragma config CPRC8 = MSTR             // Pin RC8 Ownership Bits (Master core owns pin.)
#pragma config CPRC9 = MSTR             // Pin RC9 Ownership Bits (Master core owns pin.)
#pragma config CPRC10 = MSTR            // Pin RC10 Ownership Bits (Master core owns pin.)
#pragma config CPRC11 = MSTR            // Pin RC11 Ownership Bits (Master core owns pin.)
#pragma config CPRC12 = MSTR            // Pin RC12 Ownership Bits (Master core owns pin.)
#pragma config CPRC13 = MSTR            // Pin RC13 Ownership Bits (Master core owns pin.)
#pragma config CPRC14 = MSTR            // Pin RC14 Ownership Bits (Slave 1 core owns pin.)
#pragma config CPRC15 = MSTR            // Pin RC15 Ownership Bits (Slave 1 core owns pin.)

// FCFGPRD0
#pragma config CPRD0 = MSTR             // Pin RD0 Ownership Bits (Master core owns pin.)
#pragma config CPRD1 = MSTR             // Pin RD1 Ownership Bits (Master core owns pin.)
#pragma config CPRD2 = MSTR             // Pin RD2 Ownership Bits (Master core owns pin.)
#pragma config CPRD3 = MSTR             // Pin RD3 Ownership Bits (Master core owns pin.)
#pragma config CPRD4 = MSTR             // Pin RD4 Ownership Bits (Master core owns pin.)
#pragma config CPRD5 = MSTR             // Pin RD5 Ownership Bits (Slave 1 core owns pin.)
#pragma config CPRD6 = MSTR             // Pin RD6 Ownership Bits (Slave 1 core owns pin.)
#pragma config CPRD7 = MSTR             // Pin RD7 Ownership Bits (Slave 1 core owns pin.)
#pragma config CPRD8 = MSTR             // Pin RD8 Ownership Bits (Master core owns pin.)
#pragma config CPRD9 = MSTR             // Pin RD9 Ownership Bits (Slave 1 core owns pin.)
#pragma config CPRD10 = MSTR            // Pin RD10 Ownership Bits (Master core owns pin.)
#pragma config CPRD11 = MSTR            // Pin RD11 Ownership Bits (Slave 1 core owns pin.)
#pragma config CPRD12 = MSTR            // Pin RD12 Ownership Bits (Slave 1 core owns pin.)
#pragma config CPRD13 = MSTR            // Pin RD13 Ownership Bits (Master core owns pin.)
#pragma config CPRD14 = MSTR            // Pin RD14 Ownership Bits (Slave 1 core owns pin.)
#pragma config CPRD15 = MSTR            // Pin RD15 Ownership Bits (Slave 1 core owns pin.)

// FCFGPRE0
//#pragma config CPRE0 = MSTR             // Pin RE0 Ownership Bits (Master core owns pin.)
//#pragma config CPRE1 = MSTR             // Pin RE1 Ownership Bits (Master core owns pin.)
//#pragma config CPRE2 = MSTR             // Pin RE2 Ownership Bits (Master core owns pin.)
//#pragma config CPRE3 = MSTR             // Pin RE3 Ownership Bits (Master core owns pin.)
//#pragma config CPRE4 = SLV1             // Pin RE4 Ownership Bits (Slave 1 core owns pin.)
//#pragma config CPRE5 = MSTR             // Pin RE5 Ownership Bits (Master core owns pin.)
//#pragma config CPRE6 = MSTR             // Pin RE6 Ownership Bits (Master core owns pin.)
//#pragma config CPRE7 = MSTR             // Pin RE7 Ownership Bits (Master core owns pin.)
//#pragma config CPRE8 = MSTR             // Pin RE8 Ownership Bits (Master core owns pin.)
//#pragma config CPRE9 = MSTR             // Pin RE9 Ownership Bits (Master core owns pin.)
//#pragma config CPRE10 = MSTR            // Pin RE10 Ownership Bits (Master core owns pin.)
//#pragma config CPRE11 = MSTR            // Pin RE11 Ownership Bits (Master core owns pin.)
//#pragma config CPRE12 = MSTR            // Pin RE12 Ownership Bits (Master core owns pin.)
//#pragma config CPRE13 = MSTR            // Pin RE13 Ownership Bits (Master core owns pin.)
//#pragma config CPRE14 = MSTR            // Pin RE14 Ownership Bits (Master core owns pin.)
//#pragma config CPRE15 = MSTR            // Pin RE15 Ownership Bits (Master core owns pin.)

/*

// FSLV1OSCSEL
#pragma config S_FNOSC = FRCPLL          // Oscillator Source Selection (Internal Fast RC (FRC))
#pragma config S_IESO = ON               // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FSLV1OSC
#pragma config S_IOL1WAY = OFF           // Peripheral pin select configuration bit (Allow only one reconfiguration)
#pragma config S_FCKSM = CSECMD         // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)
#pragma config S_PLLKEN = LOCK          //  (Source for PLL Lock signal is lock detect)

// FSLV1WDT
#pragma config S_RWDTPS = PS1048576     // Run Mode Watchdog Timer Post Scaler select bits (1:1048576)
#pragma config S_RCLKSEL = INT          // Watchdog Timer Clock Select bits (Always use INTOSC/LPRC)
#pragma config S_WINDIS = OFF            // Watchdog Timer Window Enable bit (Watchdog Timer operates in Non-Window mode)
#pragma config S_WDTWIN = WIN25         // Watchdog Timer Window Select bits (WDT Window is 25% of WDT period)
#pragma config S_SWDTPS = PS1048576     // Sleep Mode Watchdog Timer Post Scaler select bits (1:1048576)
#pragma config S_FWDTEN = ON_SWDTEN     // Watchdog Timer Enable bit (WDT controlled via WDTCON.ON bit)

// FSLV1POR
#pragma config S_BSSO = NORMAL          // Boot Space Start Option (Normal startup operation after reset, execute instruction at 0x000000)

// FSLV1ICD
#pragma config S_ICS = PGD2             // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
#pragma config S_ISOLAT = OFF           // Isolate the Slave core subsystem from the master subsystem during Debug (The slave can operate (in debug mode) even if the SLVEN bit in the MSI is zero.)
#pragma config S_NOBTSWP = OFF          // BOOTSWP Instruction Enable/Disable bit (BOOTSWP instruction is disabled)

// FSLV1DEVOPT
#pragma config S_ALTI2C1 = OFF          // Alternate I2C1 Pin bit (I2C1 mapped to SDA1/SCL1 pins)
#pragma config S_SSRE = OFF             // Slave Slave Reset Enable (Slave generated resets will reset the Slave Enable Bit in the MSI module)
#pragma config S_MSRE = OFF             // Master Slave Reset Enable (The master software oriented RESET events (RESET Op-Code, Watchdog timeout, TRAP reset, illegalInstruction) will also cause the slave subsystem to reset.)

// FSLV1ALTREG
#pragma config S_CTXT1 = OFF            // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits (Not Assigned)
#pragma config S_CTXT2 = OFF            // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits (Not Assigned)
#pragma config S_CTXT3 = OFF            // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits (Not Assigned)
#pragma config S_CTXT4 = OFF            // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits (Not Assigned)

 */

#else

#error === selected device not supported (no configuration bits defined) ===

#endif

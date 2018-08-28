/*@@Software License Agreement
 * ************************************************************************************************
 *
 * Software License Agreement
 *
 * Copyright © 2012 Microchip Technology Inc.  All rights reserved. Microchip licenses to you the
 * right to use, modify, copy and distribute Software only when embedded on a Microchip 
 * microcontroller or digital signal controller, which is integrated into your product or third 
 * party product (pursuant to the sublicense terms in the accompanying license agreement).
 *
 * You should refer to the license agreement accompanying this Software for additional information 
 * regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR 
 * IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR 
 * OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT  
 * LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS  
 * OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY  
 * THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *
 * ***********************************************************************************************/
/*@@pps.h
 * ************************************************************************************************
 * Summary:
 * Generic Peripheral Pin Select (PPS) Driver Module (header file)
 *
 * Description:
 * This additional header file contains defines for all required bit-settings of all related registers.
 * This file is an additional header file on top of the generic device header file.
 * 
 * See Also:
 *	p33EGS_pps.c
 * ***********************************************************************************************/
// Device header file
#include <xc.h>

#ifndef _P33SMPS_PINMAP_DEF_H_
#define _P33SMPS_PINMAP_DEF_H_

#include "p33SMPS_devices.h"

// Default definitions for all de4vices

	#define PINMAP_LOCK			(0U)
	#define PINMAP_UNLOCK		(1U)

// Generic declarations for pin numbers for all devices

	#define PIN_RP0             (0U)
	#define PIN_RP1             (1U)
	#define PIN_RP2             (2U)
	#define PIN_RP3             (3U)
	#define PIN_RP4             (4U)
	#define PIN_RP5             (5U)
	#define PIN_RP6             (6U)
	#define PIN_RP7             (7U)
	#define PIN_RP8             (8U)
	#define PIN_RP9             (9U)
	#define PIN_RP10            (10U)
	#define PIN_RP11            (11U)
	#define PIN_RP12            (12U)
	#define PIN_RP13            (13U)
	#define PIN_RP14            (14U)
	#define PIN_RP15            (15U)
	#define PIN_RP16            (16U)
	#define PIN_RP17            (17U)
	#define PIN_RP18            (18U)
	#define PIN_RP19            (19U)
	#define PIN_RP20            (20U)
	#define PIN_RP21            (21U)
	#define PIN_RP22            (22U)
	#define PIN_RP23            (23U)
	#define PIN_RP24            (24U)
	#define PIN_RP25            (25U)
	#define PIN_RP26            (26U)
	#define PIN_RP27            (27U)
	#define PIN_RP28            (28U)
	#define PIN_RP29            (29U)
    #define PIN_RP30            (30U)
	#define PIN_RP31            (31U)
	#define PIN_RP32            (32U)
	#define PIN_RP33            (33U)
	#define PIN_RP34            (34U)
	#define PIN_RP35            (35U)
	#define PIN_RP36            (36U)
	#define PIN_RP37            (37U)
	#define PIN_RP38            (38U)
	#define PIN_RP39            (39U)
    #define PIN_RP40            (40U)
    #define PIN_RP41            (41U)
    #define PIN_RP42            (42U)
    #define PIN_RP43            (43U)
    #define PIN_RP44            (44U)
    #define PIN_RP45            (45U)
    #define PIN_RP46            (46U)
    #define PIN_RP47            (47U)
    #define PIN_RP48            (48U)
    #define PIN_RP49            (49U)
    #define PIN_RP50            (50U)
    #define PIN_RP51            (51U)
    #define PIN_RP52            (52U)
    #define PIN_RP53            (53U)
    #define PIN_RP54            (54U)
    #define PIN_RP55            (55U)
    #define PIN_RP56            (56U)
    #define PIN_RP57            (57U)
    #define PIN_RP58            (58U)
    #define PIN_RP59            (59U)
    #define PIN_RP60            (60U)
    #define PIN_RP61            (61U)
    #define PIN_RP62            (62U)
    #define PIN_RP63            (63U)
    #define PIN_RP64            (64U)
    #define PIN_RP65            (65U)
    #define PIN_RP66            (66U)
    #define PIN_RP67            (67U)
    #define PIN_RP68            (68U)
    #define PIN_RP69            (69U)
    #define PIN_RP70            (70U)
    #define PIN_RP71            (71U)
    #define PIN_RP72            (72U)
    #define PIN_RP73            (73U)
    #define PIN_RP74            (74U)
    #define PIN_RP75            (75U)
    #define PIN_RP76            (76U)
    #define PIN_RP77            (77U)
    #define PIN_RP78            (78U)
    #define PIN_RP79            (79U)
    #define PIN_RP80            (80U)
    #define PIN_RP81            (81U)
    #define PIN_RP82            (82U)
    #define PIN_RP83            (83U)
    #define PIN_RP84            (84U)
    #define PIN_RP85            (85U)
    #define PIN_RP86            (86U)
    #define PIN_RP87            (87U)
    #define PIN_RP88            (88U)
    #define PIN_RP89            (89U)
    #define PIN_RP90            (90U)
    #define PIN_RP91            (91U)
    #define PIN_RP92            (92U)
    #define PIN_RP93            (93U)
    #define PIN_RP94            (94U)
    #define PIN_RP95            (95U)
    #define PIN_RP96            (96U)
    #define PIN_RP97            (97U)
    #define PIN_RP98            (98U)
    #define PIN_RP99            (99U)
    #define PIN_RP100           (100U)
    #define PIN_RP101           (101U)
    #define PIN_RP102           (102U)
    #define PIN_RP103           (103U)
    #define PIN_RP104           (104U)
    #define PIN_RP105           (105U)
    #define PIN_RP106           (106U)
    #define PIN_RP107           (107U)
    #define PIN_RP108           (108U)
    #define PIN_RP109           (109U)
    #define PIN_RP110           (110U)
    #define PIN_RP111           (111U)
    #define PIN_RP112           (112U)
    #define PIN_RP113           (113U)
    #define PIN_RP114           (114U)
    #define PIN_RP115           (115U)
    #define PIN_RP116           (116U)
    #define PIN_RP117           (117U)
    #define PIN_RP118           (118U)
    #define PIN_RP119           (119U)
    #define PIN_RP120           (120U)
    #define PIN_RP121           (121U)
    #define PIN_RP122           (122U)
    #define PIN_RP123           (123U)
    #define PIN_RP124           (124U)
    #define PIN_RP125           (125U)
    #define PIN_RP126           (126U)
    #define PIN_RP127           (127U)
    #define PIN_RP128           (128U)
    #define PIN_RP129           (129U)
    #define	PIN_RP130			(130U)
    #define	PIN_RP131			(131U)
    #define	PIN_RP132			(132U)
    #define	PIN_RP133			(133U)
    #define	PIN_RP134			(134U)
    #define	PIN_RP135			(135U)
    #define	PIN_RP136			(136U)
    #define	PIN_RP137			(137U)
    #define	PIN_RP138			(138U)
    #define	PIN_RP139			(139U)
    #define	PIN_RP140			(140U)
    #define	PIN_RP141			(141U)
    #define	PIN_RP142			(142U)
    #define	PIN_RP143			(143U)
    #define	PIN_RP144			(144U)
    #define	PIN_RP145			(145U)
    #define	PIN_RP146			(146U)
    #define	PIN_RP147			(147U)
    #define	PIN_RP148			(148U)
    #define	PIN_RP149			(149U)
    #define	PIN_RP150			(150U)
    #define	PIN_RP151			(151U)
    #define	PIN_RP152			(152U)
    #define	PIN_RP153			(153U)
    #define	PIN_RP154			(154U)
    #define	PIN_RP155			(155U)
    #define	PIN_RP156			(156U)
    #define	PIN_RP157			(157U)
    #define	PIN_RP158			(158U)
    #define	PIN_RP159			(159U)
    #define	PIN_RP160			(160U)
    #define	PIN_RP161			(161U)
    #define	PIN_RP162			(162U)
    #define	PIN_RP163			(163U)
    #define	PIN_RP164			(164U)
    #define	PIN_RP165			(165U)
    #define	PIN_RP166			(166U)
    #define	PIN_RP167			(167U)
    #define	PIN_RP168			(168U)
    #define	PIN_RP169			(169U)
    #define	PIN_RP170			(170U)
    #define	PIN_RP171			(171U)
    #define	PIN_RP172			(172U)
    #define	PIN_RP173			(173U)
    #define	PIN_RP174			(174U)
    #define	PIN_RP175			(175U)
    #define	PIN_RP176			(176U)
    #define	PIN_RP177			(177U)
    #define	PIN_RP178			(178U)
    #define	PIN_RP179			(179U)
    #define	PIN_RP180			(180U)
    #define	PIN_RP181			(181U)
    #define	PIN_RP182			(182U)
    #define	PIN_RP183			(183U)
    #define	PIN_RP184			(184U)
    #define	PIN_RP185			(185U)
    #define	PIN_RP186			(186U)
    #define	PIN_RP187			(187U)
    #define	PIN_RP188			(188U)
    #define	PIN_RP189			(189U)
    #define	PIN_RP190			(190U)
    #define	PIN_RP191			(191U)
    #define	PIN_RP192			(192U)
    #define	PIN_RP193			(193U)
    #define	PIN_RP194			(194U)
    #define	PIN_RP195			(195U)
    #define	PIN_RP196			(196U)
    #define	PIN_RP197			(197U)
    #define	PIN_RP198			(198U)
    #define	PIN_RP199			(199U)
    #define	PIN_RP200			(200U)
    #define	PIN_RP201			(201U)
    #define	PIN_RP202			(202U)
    #define	PIN_RP203			(203U)
    #define	PIN_RP204			(204U)
    #define	PIN_RP205			(205U)
    #define	PIN_RP206			(206U)
    #define	PIN_RP207			(207U)
    #define	PIN_RP208			(208U)
    #define	PIN_RP209			(209U)
    #define	PIN_RP210			(210U)
    #define	PIN_RP211			(211U)
    #define	PIN_RP212			(212U)
    #define	PIN_RP213			(213U)
    #define	PIN_RP214			(214U)
    #define	PIN_RP215			(215U)
    #define	PIN_RP216			(216U)
    #define	PIN_RP217			(217U)
    #define	PIN_RP218			(218U)
    #define	PIN_RP219			(219U)
    #define	PIN_RP220			(220U)
    #define	PIN_RP221			(221U)
    #define	PIN_RP222			(222U)
    #define	PIN_RP223			(223U)
    #define	PIN_RP224			(224U)
    #define	PIN_RP225			(225U)
    #define	PIN_RP226			(226U)
    #define	PIN_RP227			(227U)
    #define	PIN_RP228			(228U)
    #define	PIN_RP229			(229U)
    #define	PIN_RP230			(230U)
    #define	PIN_RP231			(231U)
    #define	PIN_RP232			(232U)
    #define	PIN_RP233			(233U)
    #define	PIN_RP234			(234U)
    #define	PIN_RP235			(235U)
    #define	PIN_RP236			(236U)
    #define	PIN_RP237			(237U)
    #define	PIN_RP238			(238U)
    #define	PIN_RP239			(239U)
    #define	PIN_RP240			(240U)
    #define	PIN_RP241			(241U)
    #define	PIN_RP242			(242U)
    #define	PIN_RP243			(243U)
    #define	PIN_RP244			(244U)
    #define	PIN_RP245			(245U)
    #define	PIN_RP246			(246U)
    #define	PIN_RP247			(247U)
    #define	PIN_RP248			(248U)
    #define	PIN_RP249			(249U)
    #define	PIN_RP250			(250U)
    #define	PIN_RP251			(251U)
    #define	PIN_RP252			(252U)
    #define	PIN_RP253			(253U)
    #define	PIN_RP254			(254U)
    #define	PIN_RP255			(255U)


#if defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJA__) || defined (__P33SMPS_FJC__)
        
	// driver definitions for maximum pin number supported
	#define RP_PINNO_MIN		0
	#define RP_PINNO_MAX		35
	
	// defines for available output functions
	
	#define PPSOUT_NULL			(0U)
	#define PPSOUT_NONE			(63U)

	#define PPSOUT_C1OUT		(1U)
	#define PPSOUT_C2OUT		(2U)
	
	#define PPSOUT_U1TX			(3U)
	#define PPSOUT_U1RTS		(4U)
	
	#define PPSOUT_U2TX			(5U)
	#define PPSOUT_U2RTS		(6U)
	
	#define PPSOUT_SDO1			(7U)
	#define PPSOUT_SCK1			(8U)
	#define PPSOUT_SS1			(9U)
	
	#define PPSOUT_SDO2			(10U)
	#define PPSOUT_SCK2			(11U)
	#define PPSOUT_SS2			(12U)
	
	#define PPSOUT_CAN1TX		(16U)
	#define PPSOUT_CAN2TX		(17U)
	
	#define PPSOUT_OC1			(18U)
	#define PPSOUT_OC2			(19U)
	#define PPSOUT_OC3			(14U)
	#define PPSOUT_OC4			(15U)
	
	#define PPSOUT_QEIUPDN1		(26U)
	#define PPSOUT_QEIUPDN2		(27U)
	
	// Specific Defines for dsPIC33F GS Devices
	#define PPSOUT_SYNCO1		(37U)

	#define PPSOUT_REFCLKO		(38U)

	#define PPSOUT_ACMP1		(39U)
	#define PPSOUT_ACMP2		(40U)
	#define PPSOUT_ACMP3		(41U)
	#define PPSOUT_ACMP4		(42U)

	#define PPSOUT_PWM4H		(44U)
	#define PPSOUT_PWM4L		(45U)

	
	// defines for available input functions
	#define PPSIN_INT1			(unsigned char*)&RPINR0+1
	#define PPSIN_INT2			(unsigned char*)&RPINR1
	
	#define PPSIN_T2CKI			(unsigned char*)&RPINR3
	#define PPSIN_T3CKI			(unsigned char*)&RPINR3+1
	#define PPSIN_T4CKI			(unsigned char*)&RPINR4
	#define PPSIN_T5CKI			(unsigned char*)&RPINR4+1
	
	#define PPSIN_IC1			(unsigned char*)&RPINR7
	#define PPSIN_IC2			(unsigned char*)&RPINR7+1
	#define PPSIN_IC7			(unsigned char*)&RPINR10
	#define PPSIN_IC8			(unsigned char*)&RPINR10+1
	
	#define PPSIN_OCFA			(unsigned char*)&RPINR11
	
	#define PPSIN_FLTA1			(unsigned char*)&RPINR12
	#define PPSIN_FLTA2			(unsigned char*)&RPINR13
	
	#define PPSIN_QEI1A			(unsigned char*)&RPINR14
	#define PPSIN_QEI1B			(unsigned char*)&RPINR14+1
	#define PPSIN_QEI1INDX		(unsigned char*)&RPINR15
	
	#define PPSIN_QEI2A			(unsigned char*)&RPINR16
	#define PPSIN_QEI2B			(unsigned char*)&RPINR16+1
	#define PPSIN_QEI2INDX		(unsigned char*)&RPINR17
	
	#define PPSIN_U1RX			(unsigned char*)&RPINR18
	#define PPSIN_U1CTS			(unsigned char*)&RPINR18+1
	
	#define PPSIN_U2RX			(unsigned char*)&RPINR19
	#define PPSIN_U2CTS			(unsigned char*)&RPINR19+1
	
	#define PPSIN_SDI1			(unsigned char*)&RPINR20
	#define PPSIN_SCK1			(unsigned char*)&RPINR20+1
	#define PPSIN_SS1			(unsigned char*)&RPINR21
	
	#define PPSIN_SDI2			(unsigned char*)&RPINR22
	#define PPSIN_SCK2			(unsigned char*)&RPINR22+1
	#define PPSIN_SS2			(unsigned char*)&RPINR23
	
	#define PPSIN_CAN1RX		(unsigned char*)&RPINR26
	#define PPSIN_CAN2RX		(unsigned char*)&RPINR26+1
	
	#define PPSIN_FAULT1		(unsigned char*)&RPINR29+1
	#define PPSIN_FAULT2		(unsigned char*)&RPINR30
	#define PPSIN_FAULT3		(unsigned char*)&RPINR30+1
	#define PPSIN_FAULT4		(unsigned char*)&RPINR31
	#define PPSIN_FAULT5		(unsigned char*)&RPINR31+1
	#define PPSIN_FAULT6		(unsigned char*)&RPINR32
	#define PPSIN_FAULT7		(unsigned char*)&RPINR32+1
	#define PPSIN_FAULT8		(unsigned char*)&RPINR33
	
	#define PPSIN_EXT_SYNCI1	(unsigned char*)&RPINR33+1
	#define PPSIN_EXT_SYNCI2	(unsigned char*)&RPINR34

    /* Specific declarations for virtual, remappable pins */

	// Defines for Pin Numbers
	#define PIN_RP0             (0U)
	#define PIN_RP1             (1U)
	#define PIN_RP2             (2U)
	#define PIN_RP3             (3U)
	#define PIN_RP4             (4U)
	#define PIN_RP5             (5U)
	#define PIN_RP6             (6U)
	#define PIN_RP7             (7U)
	#define PIN_RP8             (8U)
	#define PIN_RP9             (9U)
	#define PIN_RP10            (10U)
	#define PIN_RP11            (11U)
	#define PIN_RP12            (12U)
	#define PIN_RP13            (13U)
	#define PIN_RP14            (14U)
	#define PIN_RP15            (15U)
	#define PIN_RP16            (16U)
	#define PIN_RP17            (17U)
	#define PIN_RP18            (18U)
	#define PIN_RP19            (19U)
	#define PIN_RP20            (20U)
	#define PIN_RP21            (21U)
	#define PIN_RP22            (22U)
	#define PIN_RP23            (23U)
	#define PIN_RP24            (24U)
	#define PIN_RP25            (25U)
	#define PIN_RP26            (26U)
	#define PIN_RP27            (27U)
	#define PIN_RP28            (28U)
	#define PIN_RP29            (29U)
	#define PIN_RP30            (30U)
	#define PIN_RP31            (31U)
	
	#define PIN_RP32            (32U)
	#define PIN_RP33            (33U)
	#define PIN_RP34            (34U)
	#define PIN_RP35            (35U)


	#define PIN_VRP1            (32U)
	#define PIN_VRP2            (33U)
	#define PIN_VRP3            (34U)
	#define PIN_VRP4            (35U)

	#define PIN_RP_TO_VSS		(63U)	// Inputs will be tied to VSS

#elif defined (__P33SMPS_EP__)

	// driver definitions for maximum pin number supported
	#define RP_PINNO_MIN		16
    #define RP_PINNO_GAP_MIN    20
    #define RP_PINNO_GAP_MAX    32
    #define PR_PINNO_GAP_OFFSET (uint16_t)(RP_PINNO_GAP_MIN - RP_PINNO_MIN + 1) // The register number gap flips the order of odd and even pin numbers
	#define RP_PINNO_MAX		181

/* ---------------------------------------------------------------------------
 * 	defines for register addresses for available output sources
 *  The pin number 0...181 will be the value written to the registers 
 *  declared here
 * ---------------------------------------------------------------------------*/

    #define PPSOUT_NULL			(0U)
	#define PPSOUT_NONE			(0U)
	
	#define PPSOUT_U1TX			(1U)
	#define PPSOUT_U1RTS		(2U)
	
	#define PPSOUT_U2TX			(3U)
	#define PPSOUT_U2RTS		(4U)
	
	#define PPSOUT_SDO1			(5U)
	#define PPSOUT_SCK1			(1U)
	#define PPSOUT_SS1			(7U)
	
	#define PPSOUT_SDO2			(8U)
	#define PPSOUT_SCK2			(9U)
	#define PPSOUT_SS2			(10U)
	
	#define PPSOUT_OC1			(16U)
	#define PPSOUT_OC2			(17U)
	#define PPSOUT_OC3			(18U)
	#define PPSOUT_OC4			(19U)
	
	#define PPSOUT_SYNCO1		(45U)
	#define PPSOUT_SYNCO2		(46U)

	#define PPSOUT_REFCLKO		(49U)

	#define PPSOUT_ACMP1		(24U)
	#define PPSOUT_ACMP2		(25U)
	#define PPSOUT_ACMP3		(26U)
	#define PPSOUT_ACMP4		(50U)

	#define PPSOUT_PWM4H		(51U)
	#define PPSOUT_PWM4L		(52U)
	#define PPSOUT_PWM5H		(53U)
	#define PPSOUT_PWM5L		(54U)

/* ---------------------------------------------------------------------------
 * 	defines for register addresses for available input sources
 *  The pin number 0...181 will be the value written to the registers 
 *  declared here
 * ---------------------------------------------------------------------------*/

    #define PPSIN_INT1			(unsigned char*)&RPINR0+1
	#define PPSIN_INT2			(unsigned char*)&RPINR1
	
	#define PPSIN_T1CKI			(unsigned char*)&RPINR2+1
	#define PPSIN_T2CKI			(unsigned char*)&RPINR3
	#define PPSIN_T3CKI			(unsigned char*)&RPINR3+1
	
	#define PPSIN_IC1			(unsigned char*)&RPINR7
	#define PPSIN_IC2			(unsigned char*)&RPINR7+1
	#define PPSIN_IC3			(unsigned char*)&RPINR8
	#define PPSIN_IC4			(unsigned char*)&RPINR8+1
	
	#define PPSIN_OCFA			(unsigned char*)&RPINR11
	
	#define PPSIN_FLTA1			(unsigned char*)&RPINR12
	#define PPSIN_FLTA2			(unsigned char*)&RPINR12+1
	#define PPSIN_FLTA3			(unsigned char*)&RPINR13
	#define PPSIN_FLTA4			(unsigned char*)&RPINR13+1
	#define PPSIN_FLTA5			(unsigned char*)&RPINR42
	#define PPSIN_FLTA6			(unsigned char*)&RPINR42+1
	#define PPSIN_FLTA7			(unsigned char*)&RPINR43
	#define PPSIN_FLTA8			(unsigned char*)&RPINR43+1
	
	#define PPSIN_U1RX			(unsigned char*)&RPINR18
	#define PPSIN_U1CTS			(unsigned char*)&RPINR18+1
	
	#define PPSIN_U2RX			(unsigned char*)&RPINR19
	#define PPSIN_U2CTS			(unsigned char*)&RPINR19+1
	
	#define PPSIN_SDI1			(unsigned char*)&RPINR20
	#define PPSIN_SCK1			(unsigned char*)&RPINR20+1
	#define PPSIN_SS1			(unsigned char*)&RPINR21
	
	#define PPSIN_SDI2			(unsigned char*)&RPINR22
	#define PPSIN_SCK2			(unsigned char*)&RPINR22+1
	#define PPSIN_SS2			(unsigned char*)&RPINR23
	
	#define PPSIN_SYNCI1		(unsigned char*)&RPINR37+1
	#define PPSIN_SYNCI2		(unsigned char*)&RPINR38

    /* Specific declarations for virtual, remappable pins */
    #if defined (__P33SMPS_EP__)
            
        #define PIN_VRP1            (176U)
        #define PIN_VRP2            (177U)
        #define PIN_VRP3            (178U)
        #define PIN_VRP4            (179U)
        #define PIN_VRP5            (180U)
        #define PIN_VRP6            (181U)

    	#define PIN_RP_TO_VSS		(63U)	// Inputs will be tied to VSS

    #endif

#else
    #error === p33SMPS_pps: selected device type not supported ===

#endif

	// PROTOTYPES FOR pps.c
	extern unsigned char pps_RemapOutput(unsigned char pinno,unsigned char peripheral);
	extern unsigned char pps_UnmapOutput(unsigned char pinno);
	extern unsigned char pps_RemapInput(unsigned char pinno,unsigned char *regptr);
	extern unsigned char pps_UnmapInput(unsigned char *regptr);
	extern void pps_LockIO(void);
	extern void pps_UnlockIO(void);

#endif
// End of File _P33SMPS_PINMAP_DEF_H_
    
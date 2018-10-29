#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-00124_R10_EP806.mk)" "nbproject/Makefile-local-00124_R10_EP806.mk"
include nbproject/Makefile-local-00124_R10_EP806.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=00124_R10_EP806
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/framework4_vmc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/framework4_vmc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/_root/config/globals.c ../src/_root/generic/fdrv_FaultHandler.c ../src/_root/generic/task_manager.c ../src/_root/generic/traps.c ../src/apl/config/tasks.c ../src/apl/tasks/task_FaultHandler.c ../src/apl/tasks/task_Idle.c ../src/apl/tasks/task_LED_Green.c ../src/apl/tasks/task_LED_Red.c ../src/apl/tasks/task_Switch.c ../src/apl/tasks/task_OnPIM_LED.c ../src/apl/tasks/task_SoftStart.c ../src/apl/tasks/task_ConverterStateControl.c ../src/apl/tasks/task_UART.c ../src/apl/apl.c ../src/hal/initialization/init_control.c ../src/hal/initialization/init_dsp.c ../src/hal/initialization/init_fosc.c ../src/hal/initialization/init_gpio.c ../src/hal/initialization/init_hsadc.c ../src/hal/initialization/init_hspwm.c ../src/hal/initialization/init_swdt.c ../src/hal/initialization/init_timer.c ../src/hal/initialization/init_irq.c ../src/hal/initialization/init_hsacmp.c ../src/hal/initialization/init_uart.c ../src/hal/hal.c ../src/mcal/config/config_bits.c ../src/mcal/generic/p33GS_hsacmp.c ../src/mcal/generic/p33GS_hsadc.c ../src/mcal/generic/p33GS_hspwm.c ../src/mcal/generic/p33SMPS_gpio.c ../src/mcal/generic/p33SMPS_oscillator.c ../src/mcal/generic/p33SMPS_pmd.c ../src/mcal/generic/p33SMPS_swdt.c ../src/mcal/generic/p33SMPS_timer.c ../src/mcal/generic/p33SMPS_dsp.c ../src/mcal/generic/p33SMPS_irq.c ../src/mcal/generic/p33SMPS_uart.c ../src/mcal/generic/p33SMPS_pps.c ../src/mcal/mcal.c ../src/sfl/asmlib/cnpnz_vmc.s ../src/sfl/isr/isr_adc.c ../src/sfl/isr/isr_adcmp.c ../src/sfl/isr/isr_adcflt.c ../src/sfl/isr/isr_gpio.c ../src/sfl/isr/isr_pwm.c ../src/sfl/isr/isr_timer.c ../src/sfl/libapi/cnpnz_vmc.c ../src/sfl/sfl.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1726478858/globals.o ${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o ${OBJECTDIR}/_ext/949971983/task_manager.o ${OBJECTDIR}/_ext/949971983/traps.o ${OBJECTDIR}/_ext/687227054/tasks.o ${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o ${OBJECTDIR}/_ext/1838571682/task_Idle.o ${OBJECTDIR}/_ext/1838571682/task_LED_Green.o ${OBJECTDIR}/_ext/1838571682/task_LED_Red.o ${OBJECTDIR}/_ext/1838571682/task_Switch.o ${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o ${OBJECTDIR}/_ext/1838571682/task_SoftStart.o ${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o ${OBJECTDIR}/_ext/1838571682/task_UART.o ${OBJECTDIR}/_ext/659850787/apl.o ${OBJECTDIR}/_ext/1752484138/init_control.o ${OBJECTDIR}/_ext/1752484138/init_dsp.o ${OBJECTDIR}/_ext/1752484138/init_fosc.o ${OBJECTDIR}/_ext/1752484138/init_gpio.o ${OBJECTDIR}/_ext/1752484138/init_hsadc.o ${OBJECTDIR}/_ext/1752484138/init_hspwm.o ${OBJECTDIR}/_ext/1752484138/init_swdt.o ${OBJECTDIR}/_ext/1752484138/init_timer.o ${OBJECTDIR}/_ext/1752484138/init_irq.o ${OBJECTDIR}/_ext/1752484138/init_hsacmp.o ${OBJECTDIR}/_ext/1752484138/init_uart.o ${OBJECTDIR}/_ext/659857049/hal.o ${OBJECTDIR}/_ext/391766742/config_bits.o ${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o ${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o ${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o ${OBJECTDIR}/_ext/1019117317/mcal.o ${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o ${OBJECTDIR}/_ext/1724212984/isr_adc.o ${OBJECTDIR}/_ext/1724212984/isr_adcmp.o ${OBJECTDIR}/_ext/1724212984/isr_adcflt.o ${OBJECTDIR}/_ext/1724212984/isr_gpio.o ${OBJECTDIR}/_ext/1724212984/isr_pwm.o ${OBJECTDIR}/_ext/1724212984/isr_timer.o ${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o ${OBJECTDIR}/_ext/659867775/sfl.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1726478858/globals.o.d ${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o.d ${OBJECTDIR}/_ext/949971983/task_manager.o.d ${OBJECTDIR}/_ext/949971983/traps.o.d ${OBJECTDIR}/_ext/687227054/tasks.o.d ${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o.d ${OBJECTDIR}/_ext/1838571682/task_Idle.o.d ${OBJECTDIR}/_ext/1838571682/task_LED_Green.o.d ${OBJECTDIR}/_ext/1838571682/task_LED_Red.o.d ${OBJECTDIR}/_ext/1838571682/task_Switch.o.d ${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o.d ${OBJECTDIR}/_ext/1838571682/task_SoftStart.o.d ${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o.d ${OBJECTDIR}/_ext/1838571682/task_UART.o.d ${OBJECTDIR}/_ext/659850787/apl.o.d ${OBJECTDIR}/_ext/1752484138/init_control.o.d ${OBJECTDIR}/_ext/1752484138/init_dsp.o.d ${OBJECTDIR}/_ext/1752484138/init_fosc.o.d ${OBJECTDIR}/_ext/1752484138/init_gpio.o.d ${OBJECTDIR}/_ext/1752484138/init_hsadc.o.d ${OBJECTDIR}/_ext/1752484138/init_hspwm.o.d ${OBJECTDIR}/_ext/1752484138/init_swdt.o.d ${OBJECTDIR}/_ext/1752484138/init_timer.o.d ${OBJECTDIR}/_ext/1752484138/init_irq.o.d ${OBJECTDIR}/_ext/1752484138/init_hsacmp.o.d ${OBJECTDIR}/_ext/1752484138/init_uart.o.d ${OBJECTDIR}/_ext/659857049/hal.o.d ${OBJECTDIR}/_ext/391766742/config_bits.o.d ${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o.d ${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o.d ${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o.d ${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o.d ${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o.d ${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o.d ${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o.d ${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o.d ${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o.d ${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o.d ${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o.d ${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o.d ${OBJECTDIR}/_ext/1019117317/mcal.o.d ${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o.d ${OBJECTDIR}/_ext/1724212984/isr_adc.o.d ${OBJECTDIR}/_ext/1724212984/isr_adcmp.o.d ${OBJECTDIR}/_ext/1724212984/isr_adcflt.o.d ${OBJECTDIR}/_ext/1724212984/isr_gpio.o.d ${OBJECTDIR}/_ext/1724212984/isr_pwm.o.d ${OBJECTDIR}/_ext/1724212984/isr_timer.o.d ${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o.d ${OBJECTDIR}/_ext/659867775/sfl.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1726478858/globals.o ${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o ${OBJECTDIR}/_ext/949971983/task_manager.o ${OBJECTDIR}/_ext/949971983/traps.o ${OBJECTDIR}/_ext/687227054/tasks.o ${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o ${OBJECTDIR}/_ext/1838571682/task_Idle.o ${OBJECTDIR}/_ext/1838571682/task_LED_Green.o ${OBJECTDIR}/_ext/1838571682/task_LED_Red.o ${OBJECTDIR}/_ext/1838571682/task_Switch.o ${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o ${OBJECTDIR}/_ext/1838571682/task_SoftStart.o ${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o ${OBJECTDIR}/_ext/1838571682/task_UART.o ${OBJECTDIR}/_ext/659850787/apl.o ${OBJECTDIR}/_ext/1752484138/init_control.o ${OBJECTDIR}/_ext/1752484138/init_dsp.o ${OBJECTDIR}/_ext/1752484138/init_fosc.o ${OBJECTDIR}/_ext/1752484138/init_gpio.o ${OBJECTDIR}/_ext/1752484138/init_hsadc.o ${OBJECTDIR}/_ext/1752484138/init_hspwm.o ${OBJECTDIR}/_ext/1752484138/init_swdt.o ${OBJECTDIR}/_ext/1752484138/init_timer.o ${OBJECTDIR}/_ext/1752484138/init_irq.o ${OBJECTDIR}/_ext/1752484138/init_hsacmp.o ${OBJECTDIR}/_ext/1752484138/init_uart.o ${OBJECTDIR}/_ext/659857049/hal.o ${OBJECTDIR}/_ext/391766742/config_bits.o ${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o ${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o ${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o ${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o ${OBJECTDIR}/_ext/1019117317/mcal.o ${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o ${OBJECTDIR}/_ext/1724212984/isr_adc.o ${OBJECTDIR}/_ext/1724212984/isr_adcmp.o ${OBJECTDIR}/_ext/1724212984/isr_adcflt.o ${OBJECTDIR}/_ext/1724212984/isr_gpio.o ${OBJECTDIR}/_ext/1724212984/isr_pwm.o ${OBJECTDIR}/_ext/1724212984/isr_timer.o ${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o ${OBJECTDIR}/_ext/659867775/sfl.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/_root/config/globals.c ../src/_root/generic/fdrv_FaultHandler.c ../src/_root/generic/task_manager.c ../src/_root/generic/traps.c ../src/apl/config/tasks.c ../src/apl/tasks/task_FaultHandler.c ../src/apl/tasks/task_Idle.c ../src/apl/tasks/task_LED_Green.c ../src/apl/tasks/task_LED_Red.c ../src/apl/tasks/task_Switch.c ../src/apl/tasks/task_OnPIM_LED.c ../src/apl/tasks/task_SoftStart.c ../src/apl/tasks/task_ConverterStateControl.c ../src/apl/tasks/task_UART.c ../src/apl/apl.c ../src/hal/initialization/init_control.c ../src/hal/initialization/init_dsp.c ../src/hal/initialization/init_fosc.c ../src/hal/initialization/init_gpio.c ../src/hal/initialization/init_hsadc.c ../src/hal/initialization/init_hspwm.c ../src/hal/initialization/init_swdt.c ../src/hal/initialization/init_timer.c ../src/hal/initialization/init_irq.c ../src/hal/initialization/init_hsacmp.c ../src/hal/initialization/init_uart.c ../src/hal/hal.c ../src/mcal/config/config_bits.c ../src/mcal/generic/p33GS_hsacmp.c ../src/mcal/generic/p33GS_hsadc.c ../src/mcal/generic/p33GS_hspwm.c ../src/mcal/generic/p33SMPS_gpio.c ../src/mcal/generic/p33SMPS_oscillator.c ../src/mcal/generic/p33SMPS_pmd.c ../src/mcal/generic/p33SMPS_swdt.c ../src/mcal/generic/p33SMPS_timer.c ../src/mcal/generic/p33SMPS_dsp.c ../src/mcal/generic/p33SMPS_irq.c ../src/mcal/generic/p33SMPS_uart.c ../src/mcal/generic/p33SMPS_pps.c ../src/mcal/mcal.c ../src/sfl/asmlib/cnpnz_vmc.s ../src/sfl/isr/isr_adc.c ../src/sfl/isr/isr_adcmp.c ../src/sfl/isr/isr_adcflt.c ../src/sfl/isr/isr_gpio.c ../src/sfl/isr/isr_pwm.c ../src/sfl/isr/isr_timer.c ../src/sfl/libapi/cnpnz_vmc.c ../src/sfl/sfl.c ../src/main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-00124_R10_EP806.mk dist/${CND_CONF}/${IMAGE_TYPE}/framework4_vmc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP128GS806
MP_LINKER_FILE_OPTION=,--script=p33EP128GS806.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1726478858/globals.o: ../src/_root/config/globals.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1726478858" 
	@${RM} ${OBJECTDIR}/_ext/1726478858/globals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1726478858/globals.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/_root/config/globals.c  -o ${OBJECTDIR}/_ext/1726478858/globals.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1726478858/globals.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1726478858/globals.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o: ../src/_root/generic/fdrv_FaultHandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/949971983" 
	@${RM} ${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o.d 
	@${RM} ${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/_root/generic/fdrv_FaultHandler.c  -o ${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/949971983/task_manager.o: ../src/_root/generic/task_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/949971983" 
	@${RM} ${OBJECTDIR}/_ext/949971983/task_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/949971983/task_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/_root/generic/task_manager.c  -o ${OBJECTDIR}/_ext/949971983/task_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/949971983/task_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/949971983/task_manager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/949971983/traps.o: ../src/_root/generic/traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/949971983" 
	@${RM} ${OBJECTDIR}/_ext/949971983/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/949971983/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/_root/generic/traps.c  -o ${OBJECTDIR}/_ext/949971983/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/949971983/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/949971983/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/687227054/tasks.o: ../src/apl/config/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/687227054" 
	@${RM} ${OBJECTDIR}/_ext/687227054/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/687227054/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/config/tasks.c  -o ${OBJECTDIR}/_ext/687227054/tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/687227054/tasks.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/687227054/tasks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o: ../src/apl/tasks/task_FaultHandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_FaultHandler.c  -o ${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_Idle.o: ../src/apl/tasks/task_Idle.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_Idle.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_Idle.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_Idle.c  -o ${OBJECTDIR}/_ext/1838571682/task_Idle.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_Idle.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_Idle.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_LED_Green.o: ../src/apl/tasks/task_LED_Green.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_LED_Green.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_LED_Green.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_LED_Green.c  -o ${OBJECTDIR}/_ext/1838571682/task_LED_Green.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_LED_Green.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_LED_Green.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_LED_Red.o: ../src/apl/tasks/task_LED_Red.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_LED_Red.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_LED_Red.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_LED_Red.c  -o ${OBJECTDIR}/_ext/1838571682/task_LED_Red.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_LED_Red.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_LED_Red.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_Switch.o: ../src/apl/tasks/task_Switch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_Switch.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_Switch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_Switch.c  -o ${OBJECTDIR}/_ext/1838571682/task_Switch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_Switch.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_Switch.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o: ../src/apl/tasks/task_OnPIM_LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_OnPIM_LED.c  -o ${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_SoftStart.o: ../src/apl/tasks/task_SoftStart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_SoftStart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_SoftStart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_SoftStart.c  -o ${OBJECTDIR}/_ext/1838571682/task_SoftStart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_SoftStart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_SoftStart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o: ../src/apl/tasks/task_ConverterStateControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_ConverterStateControl.c  -o ${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_UART.o: ../src/apl/tasks/task_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_UART.c  -o ${OBJECTDIR}/_ext/1838571682/task_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_UART.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659850787/apl.o: ../src/apl/apl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/659850787" 
	@${RM} ${OBJECTDIR}/_ext/659850787/apl.o.d 
	@${RM} ${OBJECTDIR}/_ext/659850787/apl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/apl.c  -o ${OBJECTDIR}/_ext/659850787/apl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659850787/apl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/659850787/apl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_control.o: ../src/hal/initialization/init_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_control.c  -o ${OBJECTDIR}/_ext/1752484138/init_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_dsp.o: ../src/hal/initialization/init_dsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_dsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_dsp.c  -o ${OBJECTDIR}/_ext/1752484138/init_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_dsp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_dsp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_fosc.o: ../src/hal/initialization/init_fosc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_fosc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_fosc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_fosc.c  -o ${OBJECTDIR}/_ext/1752484138/init_fosc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_fosc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_fosc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_gpio.o: ../src/hal/initialization/init_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_gpio.c  -o ${OBJECTDIR}/_ext/1752484138/init_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_gpio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_hsadc.o: ../src/hal/initialization/init_hsadc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hsadc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hsadc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_hsadc.c  -o ${OBJECTDIR}/_ext/1752484138/init_hsadc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_hsadc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_hsadc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_hspwm.o: ../src/hal/initialization/init_hspwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hspwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hspwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_hspwm.c  -o ${OBJECTDIR}/_ext/1752484138/init_hspwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_hspwm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_hspwm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_swdt.o: ../src/hal/initialization/init_swdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_swdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_swdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_swdt.c  -o ${OBJECTDIR}/_ext/1752484138/init_swdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_swdt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_swdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_timer.o: ../src/hal/initialization/init_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_timer.c  -o ${OBJECTDIR}/_ext/1752484138/init_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_irq.o: ../src/hal/initialization/init_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_irq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_irq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_irq.c  -o ${OBJECTDIR}/_ext/1752484138/init_irq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_irq.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_irq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_hsacmp.o: ../src/hal/initialization/init_hsacmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hsacmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hsacmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_hsacmp.c  -o ${OBJECTDIR}/_ext/1752484138/init_hsacmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_hsacmp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_hsacmp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_uart.o: ../src/hal/initialization/init_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_uart.c  -o ${OBJECTDIR}/_ext/1752484138/init_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659857049/hal.o: ../src/hal/hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/659857049" 
	@${RM} ${OBJECTDIR}/_ext/659857049/hal.o.d 
	@${RM} ${OBJECTDIR}/_ext/659857049/hal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/hal.c  -o ${OBJECTDIR}/_ext/659857049/hal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659857049/hal.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/659857049/hal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/391766742/config_bits.o: ../src/mcal/config/config_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/391766742" 
	@${RM} ${OBJECTDIR}/_ext/391766742/config_bits.o.d 
	@${RM} ${OBJECTDIR}/_ext/391766742/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/config/config_bits.c  -o ${OBJECTDIR}/_ext/391766742/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/391766742/config_bits.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/391766742/config_bits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o: ../src/mcal/generic/p33GS_hsacmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33GS_hsacmp.c  -o ${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o: ../src/mcal/generic/p33GS_hsadc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33GS_hsadc.c  -o ${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o: ../src/mcal/generic/p33GS_hspwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33GS_hspwm.c  -o ${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o: ../src/mcal/generic/p33SMPS_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_gpio.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o: ../src/mcal/generic/p33SMPS_oscillator.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_oscillator.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o: ../src/mcal/generic/p33SMPS_pmd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_pmd.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o: ../src/mcal/generic/p33SMPS_swdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_swdt.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o: ../src/mcal/generic/p33SMPS_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_timer.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o: ../src/mcal/generic/p33SMPS_dsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_dsp.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o: ../src/mcal/generic/p33SMPS_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_irq.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o: ../src/mcal/generic/p33SMPS_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_uart.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o: ../src/mcal/generic/p33SMPS_pps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_pps.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1019117317/mcal.o: ../src/mcal/mcal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1019117317" 
	@${RM} ${OBJECTDIR}/_ext/1019117317/mcal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019117317/mcal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/mcal.c  -o ${OBJECTDIR}/_ext/1019117317/mcal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1019117317/mcal.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019117317/mcal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_adc.o: ../src/sfl/isr/isr_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_adc.c  -o ${OBJECTDIR}/_ext/1724212984/isr_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_adcmp.o: ../src/sfl/isr/isr_adcmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adcmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adcmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_adcmp.c  -o ${OBJECTDIR}/_ext/1724212984/isr_adcmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_adcmp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_adcmp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_adcflt.o: ../src/sfl/isr/isr_adcflt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adcflt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adcflt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_adcflt.c  -o ${OBJECTDIR}/_ext/1724212984/isr_adcflt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_adcflt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_adcflt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_gpio.o: ../src/sfl/isr/isr_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_gpio.c  -o ${OBJECTDIR}/_ext/1724212984/isr_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_gpio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_pwm.o: ../src/sfl/isr/isr_pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_pwm.c  -o ${OBJECTDIR}/_ext/1724212984/isr_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_pwm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_pwm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_timer.o: ../src/sfl/isr/isr_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_timer.c  -o ${OBJECTDIR}/_ext/1724212984/isr_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o: ../src/sfl/libapi/cnpnz_vmc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1703581435" 
	@${RM} ${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/libapi/cnpnz_vmc.c  -o ${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659867775/sfl.o: ../src/sfl/sfl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/659867775" 
	@${RM} ${OBJECTDIR}/_ext/659867775/sfl.o.d 
	@${RM} ${OBJECTDIR}/_ext/659867775/sfl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/sfl.c  -o ${OBJECTDIR}/_ext/659867775/sfl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659867775/sfl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/659867775/sfl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1726478858/globals.o: ../src/_root/config/globals.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1726478858" 
	@${RM} ${OBJECTDIR}/_ext/1726478858/globals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1726478858/globals.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/_root/config/globals.c  -o ${OBJECTDIR}/_ext/1726478858/globals.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1726478858/globals.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1726478858/globals.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o: ../src/_root/generic/fdrv_FaultHandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/949971983" 
	@${RM} ${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o.d 
	@${RM} ${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/_root/generic/fdrv_FaultHandler.c  -o ${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/949971983/fdrv_FaultHandler.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/949971983/task_manager.o: ../src/_root/generic/task_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/949971983" 
	@${RM} ${OBJECTDIR}/_ext/949971983/task_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/949971983/task_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/_root/generic/task_manager.c  -o ${OBJECTDIR}/_ext/949971983/task_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/949971983/task_manager.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/949971983/task_manager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/949971983/traps.o: ../src/_root/generic/traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/949971983" 
	@${RM} ${OBJECTDIR}/_ext/949971983/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/949971983/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/_root/generic/traps.c  -o ${OBJECTDIR}/_ext/949971983/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/949971983/traps.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/949971983/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/687227054/tasks.o: ../src/apl/config/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/687227054" 
	@${RM} ${OBJECTDIR}/_ext/687227054/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/687227054/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/config/tasks.c  -o ${OBJECTDIR}/_ext/687227054/tasks.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/687227054/tasks.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/687227054/tasks.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o: ../src/apl/tasks/task_FaultHandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_FaultHandler.c  -o ${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_FaultHandler.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_Idle.o: ../src/apl/tasks/task_Idle.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_Idle.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_Idle.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_Idle.c  -o ${OBJECTDIR}/_ext/1838571682/task_Idle.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_Idle.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_Idle.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_LED_Green.o: ../src/apl/tasks/task_LED_Green.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_LED_Green.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_LED_Green.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_LED_Green.c  -o ${OBJECTDIR}/_ext/1838571682/task_LED_Green.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_LED_Green.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_LED_Green.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_LED_Red.o: ../src/apl/tasks/task_LED_Red.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_LED_Red.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_LED_Red.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_LED_Red.c  -o ${OBJECTDIR}/_ext/1838571682/task_LED_Red.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_LED_Red.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_LED_Red.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_Switch.o: ../src/apl/tasks/task_Switch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_Switch.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_Switch.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_Switch.c  -o ${OBJECTDIR}/_ext/1838571682/task_Switch.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_Switch.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_Switch.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o: ../src/apl/tasks/task_OnPIM_LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_OnPIM_LED.c  -o ${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_OnPIM_LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_SoftStart.o: ../src/apl/tasks/task_SoftStart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_SoftStart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_SoftStart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_SoftStart.c  -o ${OBJECTDIR}/_ext/1838571682/task_SoftStart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_SoftStart.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_SoftStart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o: ../src/apl/tasks/task_ConverterStateControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_ConverterStateControl.c  -o ${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_ConverterStateControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1838571682/task_UART.o: ../src/apl/tasks/task_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1838571682" 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1838571682/task_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/tasks/task_UART.c  -o ${OBJECTDIR}/_ext/1838571682/task_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1838571682/task_UART.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1838571682/task_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659850787/apl.o: ../src/apl/apl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/659850787" 
	@${RM} ${OBJECTDIR}/_ext/659850787/apl.o.d 
	@${RM} ${OBJECTDIR}/_ext/659850787/apl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/apl/apl.c  -o ${OBJECTDIR}/_ext/659850787/apl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659850787/apl.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/659850787/apl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_control.o: ../src/hal/initialization/init_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_control.c  -o ${OBJECTDIR}/_ext/1752484138/init_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_control.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_dsp.o: ../src/hal/initialization/init_dsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_dsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_dsp.c  -o ${OBJECTDIR}/_ext/1752484138/init_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_dsp.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_dsp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_fosc.o: ../src/hal/initialization/init_fosc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_fosc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_fosc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_fosc.c  -o ${OBJECTDIR}/_ext/1752484138/init_fosc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_fosc.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_fosc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_gpio.o: ../src/hal/initialization/init_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_gpio.c  -o ${OBJECTDIR}/_ext/1752484138/init_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_gpio.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_hsadc.o: ../src/hal/initialization/init_hsadc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hsadc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hsadc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_hsadc.c  -o ${OBJECTDIR}/_ext/1752484138/init_hsadc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_hsadc.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_hsadc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_hspwm.o: ../src/hal/initialization/init_hspwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hspwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hspwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_hspwm.c  -o ${OBJECTDIR}/_ext/1752484138/init_hspwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_hspwm.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_hspwm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_swdt.o: ../src/hal/initialization/init_swdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_swdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_swdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_swdt.c  -o ${OBJECTDIR}/_ext/1752484138/init_swdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_swdt.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_swdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_timer.o: ../src/hal/initialization/init_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_timer.c  -o ${OBJECTDIR}/_ext/1752484138/init_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_timer.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_irq.o: ../src/hal/initialization/init_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_irq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_irq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_irq.c  -o ${OBJECTDIR}/_ext/1752484138/init_irq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_irq.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_irq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_hsacmp.o: ../src/hal/initialization/init_hsacmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hsacmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_hsacmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_hsacmp.c  -o ${OBJECTDIR}/_ext/1752484138/init_hsacmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_hsacmp.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_hsacmp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1752484138/init_uart.o: ../src/hal/initialization/init_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1752484138" 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1752484138/init_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/initialization/init_uart.c  -o ${OBJECTDIR}/_ext/1752484138/init_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1752484138/init_uart.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1752484138/init_uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659857049/hal.o: ../src/hal/hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/659857049" 
	@${RM} ${OBJECTDIR}/_ext/659857049/hal.o.d 
	@${RM} ${OBJECTDIR}/_ext/659857049/hal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/hal/hal.c  -o ${OBJECTDIR}/_ext/659857049/hal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659857049/hal.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/659857049/hal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/391766742/config_bits.o: ../src/mcal/config/config_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/391766742" 
	@${RM} ${OBJECTDIR}/_ext/391766742/config_bits.o.d 
	@${RM} ${OBJECTDIR}/_ext/391766742/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/config/config_bits.c  -o ${OBJECTDIR}/_ext/391766742/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/391766742/config_bits.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/391766742/config_bits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o: ../src/mcal/generic/p33GS_hsacmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33GS_hsacmp.c  -o ${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33GS_hsacmp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o: ../src/mcal/generic/p33GS_hsadc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33GS_hsadc.c  -o ${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33GS_hsadc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o: ../src/mcal/generic/p33GS_hspwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33GS_hspwm.c  -o ${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33GS_hspwm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o: ../src/mcal/generic/p33SMPS_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_gpio.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o: ../src/mcal/generic/p33SMPS_oscillator.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_oscillator.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_oscillator.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o: ../src/mcal/generic/p33SMPS_pmd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_pmd.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_pmd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o: ../src/mcal/generic/p33SMPS_swdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_swdt.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_swdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o: ../src/mcal/generic/p33SMPS_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_timer.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o: ../src/mcal/generic/p33SMPS_dsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_dsp.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_dsp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o: ../src/mcal/generic/p33SMPS_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_irq.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_irq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o: ../src/mcal/generic/p33SMPS_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_uart.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o: ../src/mcal/generic/p33SMPS_pps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1771397949" 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/generic/p33SMPS_pps.c  -o ${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1771397949/p33SMPS_pps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1019117317/mcal.o: ../src/mcal/mcal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1019117317" 
	@${RM} ${OBJECTDIR}/_ext/1019117317/mcal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019117317/mcal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/mcal/mcal.c  -o ${OBJECTDIR}/_ext/1019117317/mcal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1019117317/mcal.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019117317/mcal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_adc.o: ../src/sfl/isr/isr_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_adc.c  -o ${OBJECTDIR}/_ext/1724212984/isr_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_adc.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_adcmp.o: ../src/sfl/isr/isr_adcmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adcmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adcmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_adcmp.c  -o ${OBJECTDIR}/_ext/1724212984/isr_adcmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_adcmp.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_adcmp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_adcflt.o: ../src/sfl/isr/isr_adcflt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adcflt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_adcflt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_adcflt.c  -o ${OBJECTDIR}/_ext/1724212984/isr_adcflt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_adcflt.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_adcflt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_gpio.o: ../src/sfl/isr/isr_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_gpio.c  -o ${OBJECTDIR}/_ext/1724212984/isr_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_gpio.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_pwm.o: ../src/sfl/isr/isr_pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_pwm.c  -o ${OBJECTDIR}/_ext/1724212984/isr_pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_pwm.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_pwm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1724212984/isr_timer.o: ../src/sfl/isr/isr_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1724212984" 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1724212984/isr_timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/isr/isr_timer.c  -o ${OBJECTDIR}/_ext/1724212984/isr_timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1724212984/isr_timer.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1724212984/isr_timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o: ../src/sfl/libapi/cnpnz_vmc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1703581435" 
	@${RM} ${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/libapi/cnpnz_vmc.c  -o ${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1703581435/cnpnz_vmc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659867775/sfl.o: ../src/sfl/sfl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/659867775" 
	@${RM} ${OBJECTDIR}/_ext/659867775/sfl.o.d 
	@${RM} ${OBJECTDIR}/_ext/659867775/sfl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sfl/sfl.c  -o ${OBJECTDIR}/_ext/659867775/sfl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659867775/sfl.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/659867775/sfl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -mno-eds-warn  -g -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -O3 -falign-arrays -I"../h" -I"../h/_root" -I"../h/_root/config" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../src" -msmart-io=1 -Wall -msfr-warn=off   -finline
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o: ../src/sfl/asmlib/cnpnz_vmc.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2008928838" 
	@${RM} ${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o.d 
	@${RM} ${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../src/sfl/asmlib/cnpnz_vmc.s  -o ${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -Wa,-MD,"${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o: ../src/sfl/asmlib/cnpnz_vmc.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2008928838" 
	@${RM} ${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o.d 
	@${RM} ${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../src/sfl/asmlib/cnpnz_vmc.s  -o ${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -Wa,-MD,"${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/2008928838/cnpnz_vmc.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/framework4_vmc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/framework4_vmc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src"  -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/framework4_vmc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/framework4_vmc.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -D__00124_R10_EP806__ -DXPRJ_00124_R10_EP806=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../h" -I"../h/_root" -I"../h/_root/generic" -I"../h/apl" -I"../h/apl/config" -I"../h/apl/tasks" -I"../h/hal" -I"../h/hal/config" -I"../h/hal/initialization" -I"../h/mcal" -I"../h/mcal/config" -I"../h/mcal/generic" -I"../h/sfl" -I"../h/sfl/asmlib" -I"../h/sfl/generic" -I"../h/sfl/libapi" -I"../h/sfl/isr" -I"../src" -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/framework4_vmc.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/00124_R10_EP806
	${RM} -r dist/00124_R10_EP806

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

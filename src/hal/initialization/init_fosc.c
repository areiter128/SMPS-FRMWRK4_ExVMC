

#include "init_fosc.h"

uint16_t init_oscillator(void) {
    
    volatile uint16_t fres = 0;
    OSC_CONFIG_t osc;
    
    #if defined (__P33SMPS_CH2__) || defined (__P33SMPS_CH5__)
    osc.osc_type = OSC_FRCPLL;
    osc.N1 = OSC_PLLDIV_N1_1;
    osc.M = 180;
    osc.N2 = OSC_PLLDIV_N2_4;
    osc.N3 = OSC_PLLDIV_N3_1;
    osc.VCODIV = OSC_PLL_VCODIV_1;
    osc.frc_tune = 31;
    
    #elif defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJA__) || defined (__P33SMPS_FJC__)
    osc.osc_type = OSC_FRCPLL;
    osc.N1 = OSC_PLLDIV_N1_2;
    osc.M = 50;
    osc.N2 = OSC_PLLDIV_N2_2;

    #elif defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)
    osc.osc_type = OSC_FRCPLL;
    osc.N1 = OSC_PLLDIV_N1_2;
    osc.M = 75; //180;
    osc.N2 = OSC_PLLDIV_N2_2;
    osc.frc_tune = 31;
    
    #endif
    
    fres  = init_FOSC(osc, OSC_FRCDIVN_1, osc.frc_tune);
    
    return fres;
}

uint16_t init_aux_oscillator(void) {

    volatile uint16_t fres = 0;
    AUXOSC_CONFIG_t auxosc;
    
    #if defined (__P33SMPS_CH2__) || defined (__P33SMPS_CH5__)
    auxosc.clock_source = OSC_AUX_CLOCK_FRC;
    auxosc.divider = OSC_AUX_PREDIV_1;
    auxosc.enableAUXPLL = OSC_AUXPLL_ON;
    
    #elif defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJA__) || defined (__P33SMPS_FJC__)
    auxosc.clock_source = OSC_AUX_CLOCK_FRC;
    auxosc.divider = OSC_AUX_PREDIV_1;
    auxosc.enableAUXPLL = OSC_AUXPLL_ON;

    #elif defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)

    auxosc.clock_source = OSC_AUX_CLOCK_FRC;
    auxosc.divider = OSC_AUX_PREDIV_1;
    auxosc.enableAUXPLL = OSC_AUXPLL_ON;
            
    #endif
    
    fres  = init_ACLK(auxosc);
    
    return fres;
}
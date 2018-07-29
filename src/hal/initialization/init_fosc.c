

#include "init_fosc.h"

uint16_t init_oscillator(void) {
    
    uint16_t fres=0;
    OSC_CONFIG_t osc;
    
    #if defined (_P33SMPS_WACA_) || defined (_P33SMPS_WACS_)
    osc.osc_type = OSC_FRCPLL;
    osc.N1 = OSC_PLLDIV_N1_1;
    osc.M = 180;
    osc.N2 = OSC_PLLDIV_N2_4;
    osc.N3 = OSC_PLLDIV_N3_1;
    osc.VCODIV = OSC_PLL_VCODIV_1;
    osc.frc_tune = 31;
    
    #elif defined (_P33SMPS_YGAR_) || defined (_P33SMPS_UEAG_) || defined (_P33SMPS_UEAA_)
    osc.osc_type = OSC_FRCPLL;
    osc.N1 = OSC_PLLDIV_N1_2;
    osc.M = 50;
    osc.N2 = OSC_PLLDIV_N2_2;

    #elif defined (_P33SMPS_TLAL_) || defined (_P33SMPS_TLAH_) || defined (_P33SMPS_TLAY_)
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

    uint16_t fres=0;
    AUXOSC_CONFIG_t auxosc;
    
    #if defined (_P33SMPS_WACA_) || defined (_P33SMPS_WACS_)
    auxosc.clock_source = OSC_AUX_CLOCK_FRC;
    auxosc.divider = OSC_AUX_PREDIV_1;
    auxosc.enableAUXPLL = OSC_AUXPLL_ON;
    
    #elif defined (_P33SMPS_YGAR_) || defined (_P33SMPS_UEAG_) || defined (_P33SMPS_UEAA_)
    auxosc.clock_source = OSC_AUX_CLOCK_FRC;
    auxosc.divider = OSC_AUX_PREDIV_1;
    auxosc.enableAUXPLL = OSC_AUXPLL_ON;

    #elif defined (_P33SMPS_TLAL_) || defined (_P33SMPS_TLAH_) || defined (_P33SMPS_TLAY_)

    auxosc.clock_source = OSC_AUX_CLOCK_FRC;
    auxosc.divider = OSC_AUX_PREDIV_1;
    auxosc.enableAUXPLL = OSC_AUXPLL_ON;
            
    #endif
    
    fres  = init_ACLK(auxosc);
    
    return fres;
}
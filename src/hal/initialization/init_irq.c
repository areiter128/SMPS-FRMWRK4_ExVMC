/*
 * File:   init_irq.c
 * Author: M91406
 *
 * Created on August 3, 2018, 9:50 AM
 */



#include "init_irq.h"

#include "mcal.h"
#include "devcfg_irq.h"

uint16_t init_irq(void)
{

    volatile uint16_t fres = 0;
    
    fres = gsirq_init_irq(IRQ_INTCON1_CFG, IRQ_INTCON2_CFG);
    fres &= gsirq_init_soft_traps(0, 0, 0);
    
    return(fres);
}

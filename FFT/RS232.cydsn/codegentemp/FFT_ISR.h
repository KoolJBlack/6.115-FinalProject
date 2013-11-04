/*******************************************************************************
* File Name: FFT_ISR.h
* Version 1.60
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#if !defined(__FFT_ISR_INTC_H__)
#define __FFT_ISR_INTC_H__


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void FFT_ISR_Start(void);
void FFT_ISR_StartEx(cyisraddress address);
void FFT_ISR_Stop(void) ;

CY_ISR_PROTO(FFT_ISR_Interrupt);

void FFT_ISR_SetVector(cyisraddress address) ;
cyisraddress FFT_ISR_GetVector(void) ;

void FFT_ISR_SetPriority(uint8 priority) ;
uint8 FFT_ISR_GetPriority(void) ;

void FFT_ISR_Enable(void) ;
uint8 FFT_ISR_GetState(void) ;
void FFT_ISR_Disable(void) ;

void FFT_ISR_SetPending(void) ;
void FFT_ISR_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the FFT_ISR ISR. */
#define FFT_ISR_INTC_VECTOR            ((reg32 *) FFT_ISR__INTC_VECT)

/* Address of the FFT_ISR ISR priority. */
#define FFT_ISR_INTC_PRIOR             ((reg8 *) FFT_ISR__INTC_PRIOR_REG)

/* Priority of the FFT_ISR interrupt. */
#define FFT_ISR_INTC_PRIOR_NUMBER      FFT_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable FFT_ISR interrupt. */
#define FFT_ISR_INTC_SET_EN            ((reg32 *) FFT_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the FFT_ISR interrupt. */
#define FFT_ISR_INTC_CLR_EN            ((reg32 *) FFT_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the FFT_ISR interrupt state to pending. */
#define FFT_ISR_INTC_SET_PD            ((reg32 *) FFT_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the FFT_ISR interrupt. */
#define FFT_ISR_INTC_CLR_PD            ((reg32 *) FFT_ISR__INTC_CLR_PD_REG)



/* __FFT_ISR_INTC_H__ */
#endif

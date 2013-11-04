/*******************************************************************************
* File Name: rx_int_Amulet.h
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
#if !defined(__rx_int_Amulet_INTC_H__)
#define __rx_int_Amulet_INTC_H__


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void rx_int_Amulet_Start(void);
void rx_int_Amulet_StartEx(cyisraddress address);
void rx_int_Amulet_Stop(void) ;

CY_ISR_PROTO(rx_int_Amulet_Interrupt);

void rx_int_Amulet_SetVector(cyisraddress address) ;
cyisraddress rx_int_Amulet_GetVector(void) ;

void rx_int_Amulet_SetPriority(uint8 priority) ;
uint8 rx_int_Amulet_GetPriority(void) ;

void rx_int_Amulet_Enable(void) ;
uint8 rx_int_Amulet_GetState(void) ;
void rx_int_Amulet_Disable(void) ;

void rx_int_Amulet_SetPending(void) ;
void rx_int_Amulet_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the rx_int_Amulet ISR. */
#define rx_int_Amulet_INTC_VECTOR            ((reg32 *) rx_int_Amulet__INTC_VECT)

/* Address of the rx_int_Amulet ISR priority. */
#define rx_int_Amulet_INTC_PRIOR             ((reg8 *) rx_int_Amulet__INTC_PRIOR_REG)

/* Priority of the rx_int_Amulet interrupt. */
#define rx_int_Amulet_INTC_PRIOR_NUMBER      rx_int_Amulet__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable rx_int_Amulet interrupt. */
#define rx_int_Amulet_INTC_SET_EN            ((reg32 *) rx_int_Amulet__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the rx_int_Amulet interrupt. */
#define rx_int_Amulet_INTC_CLR_EN            ((reg32 *) rx_int_Amulet__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the rx_int_Amulet interrupt state to pending. */
#define rx_int_Amulet_INTC_SET_PD            ((reg32 *) rx_int_Amulet__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the rx_int_Amulet interrupt. */
#define rx_int_Amulet_INTC_CLR_PD            ((reg32 *) rx_int_Amulet__INTC_CLR_PD_REG)



/* __rx_int_Amulet_INTC_H__ */
#endif

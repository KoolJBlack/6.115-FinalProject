/*******************************************************************************
* File Name: TX_Amulet.h  
* Version 1.70
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_TX_Amulet_H) /* Pins TX_Amulet_H */
#define CY_PINS_TX_Amulet_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TX_Amulet_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_70 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TX_Amulet__PORT == 15 && (TX_Amulet__MASK & 0xC0))

/***************************************
*        Function Prototypes             
***************************************/    

void    TX_Amulet_Write(uint8 value) ;
void    TX_Amulet_SetDriveMode(uint8 mode) ;
uint8   TX_Amulet_ReadDataReg(void) ;
uint8   TX_Amulet_Read(void) ;
uint8   TX_Amulet_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TX_Amulet_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TX_Amulet_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TX_Amulet_DM_RES_UP          PIN_DM_RES_UP
#define TX_Amulet_DM_RES_DWN         PIN_DM_RES_DWN
#define TX_Amulet_DM_OD_LO           PIN_DM_OD_LO
#define TX_Amulet_DM_OD_HI           PIN_DM_OD_HI
#define TX_Amulet_DM_STRONG          PIN_DM_STRONG
#define TX_Amulet_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TX_Amulet_MASK               TX_Amulet__MASK
#define TX_Amulet_SHIFT              TX_Amulet__SHIFT
#define TX_Amulet_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TX_Amulet_PS                     (* (reg8 *) TX_Amulet__PS)
/* Data Register */
#define TX_Amulet_DR                     (* (reg8 *) TX_Amulet__DR)
/* Port Number */
#define TX_Amulet_PRT_NUM                (* (reg8 *) TX_Amulet__PRT) 
/* Connect to Analog Globals */                                                  
#define TX_Amulet_AG                     (* (reg8 *) TX_Amulet__AG)                       
/* Analog MUX bux enable */
#define TX_Amulet_AMUX                   (* (reg8 *) TX_Amulet__AMUX) 
/* Bidirectional Enable */                                                        
#define TX_Amulet_BIE                    (* (reg8 *) TX_Amulet__BIE)
/* Bit-mask for Aliased Register Access */
#define TX_Amulet_BIT_MASK               (* (reg8 *) TX_Amulet__BIT_MASK)
/* Bypass Enable */
#define TX_Amulet_BYP                    (* (reg8 *) TX_Amulet__BYP)
/* Port wide control signals */                                                   
#define TX_Amulet_CTL                    (* (reg8 *) TX_Amulet__CTL)
/* Drive Modes */
#define TX_Amulet_DM0                    (* (reg8 *) TX_Amulet__DM0) 
#define TX_Amulet_DM1                    (* (reg8 *) TX_Amulet__DM1)
#define TX_Amulet_DM2                    (* (reg8 *) TX_Amulet__DM2) 
/* Input Buffer Disable Override */
#define TX_Amulet_INP_DIS                (* (reg8 *) TX_Amulet__INP_DIS)
/* LCD Common or Segment Drive */
#define TX_Amulet_LCD_COM_SEG            (* (reg8 *) TX_Amulet__LCD_COM_SEG)
/* Enable Segment LCD */
#define TX_Amulet_LCD_EN                 (* (reg8 *) TX_Amulet__LCD_EN)
/* Slew Rate Control */
#define TX_Amulet_SLW                    (* (reg8 *) TX_Amulet__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TX_Amulet_PRTDSI__CAPS_SEL       (* (reg8 *) TX_Amulet__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TX_Amulet_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TX_Amulet__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TX_Amulet_PRTDSI__OE_SEL0        (* (reg8 *) TX_Amulet__PRTDSI__OE_SEL0) 
#define TX_Amulet_PRTDSI__OE_SEL1        (* (reg8 *) TX_Amulet__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TX_Amulet_PRTDSI__OUT_SEL0       (* (reg8 *) TX_Amulet__PRTDSI__OUT_SEL0) 
#define TX_Amulet_PRTDSI__OUT_SEL1       (* (reg8 *) TX_Amulet__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TX_Amulet_PRTDSI__SYNC_OUT       (* (reg8 *) TX_Amulet__PRTDSI__SYNC_OUT) 


#if defined(TX_Amulet__INTSTAT)  /* Interrupt Registers */

    #define TX_Amulet_INTSTAT                (* (reg8 *) TX_Amulet__INTSTAT)
    #define TX_Amulet_SNAP                   (* (reg8 *) TX_Amulet__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins TX_Amulet_H */

#endif
/* [] END OF FILE */

/*******************************************************************************
* File Name: AudioOut.h  
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

#if !defined(CY_PINS_AudioOut_H) /* Pins AudioOut_H */
#define CY_PINS_AudioOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AudioOut_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_70 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AudioOut__PORT == 15 && (AudioOut__MASK & 0xC0))

/***************************************
*        Function Prototypes             
***************************************/    

void    AudioOut_Write(uint8 value) ;
void    AudioOut_SetDriveMode(uint8 mode) ;
uint8   AudioOut_ReadDataReg(void) ;
uint8   AudioOut_Read(void) ;
uint8   AudioOut_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define AudioOut_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define AudioOut_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define AudioOut_DM_RES_UP          PIN_DM_RES_UP
#define AudioOut_DM_RES_DWN         PIN_DM_RES_DWN
#define AudioOut_DM_OD_LO           PIN_DM_OD_LO
#define AudioOut_DM_OD_HI           PIN_DM_OD_HI
#define AudioOut_DM_STRONG          PIN_DM_STRONG
#define AudioOut_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define AudioOut_MASK               AudioOut__MASK
#define AudioOut_SHIFT              AudioOut__SHIFT
#define AudioOut_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AudioOut_PS                     (* (reg8 *) AudioOut__PS)
/* Data Register */
#define AudioOut_DR                     (* (reg8 *) AudioOut__DR)
/* Port Number */
#define AudioOut_PRT_NUM                (* (reg8 *) AudioOut__PRT) 
/* Connect to Analog Globals */                                                  
#define AudioOut_AG                     (* (reg8 *) AudioOut__AG)                       
/* Analog MUX bux enable */
#define AudioOut_AMUX                   (* (reg8 *) AudioOut__AMUX) 
/* Bidirectional Enable */                                                        
#define AudioOut_BIE                    (* (reg8 *) AudioOut__BIE)
/* Bit-mask for Aliased Register Access */
#define AudioOut_BIT_MASK               (* (reg8 *) AudioOut__BIT_MASK)
/* Bypass Enable */
#define AudioOut_BYP                    (* (reg8 *) AudioOut__BYP)
/* Port wide control signals */                                                   
#define AudioOut_CTL                    (* (reg8 *) AudioOut__CTL)
/* Drive Modes */
#define AudioOut_DM0                    (* (reg8 *) AudioOut__DM0) 
#define AudioOut_DM1                    (* (reg8 *) AudioOut__DM1)
#define AudioOut_DM2                    (* (reg8 *) AudioOut__DM2) 
/* Input Buffer Disable Override */
#define AudioOut_INP_DIS                (* (reg8 *) AudioOut__INP_DIS)
/* LCD Common or Segment Drive */
#define AudioOut_LCD_COM_SEG            (* (reg8 *) AudioOut__LCD_COM_SEG)
/* Enable Segment LCD */
#define AudioOut_LCD_EN                 (* (reg8 *) AudioOut__LCD_EN)
/* Slew Rate Control */
#define AudioOut_SLW                    (* (reg8 *) AudioOut__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AudioOut_PRTDSI__CAPS_SEL       (* (reg8 *) AudioOut__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AudioOut_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AudioOut__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AudioOut_PRTDSI__OE_SEL0        (* (reg8 *) AudioOut__PRTDSI__OE_SEL0) 
#define AudioOut_PRTDSI__OE_SEL1        (* (reg8 *) AudioOut__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AudioOut_PRTDSI__OUT_SEL0       (* (reg8 *) AudioOut__PRTDSI__OUT_SEL0) 
#define AudioOut_PRTDSI__OUT_SEL1       (* (reg8 *) AudioOut__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AudioOut_PRTDSI__SYNC_OUT       (* (reg8 *) AudioOut__PRTDSI__SYNC_OUT) 


#if defined(AudioOut__INTSTAT)  /* Interrupt Registers */

    #define AudioOut_INTSTAT                (* (reg8 *) AudioOut__INTSTAT)
    #define AudioOut_SNAP                   (* (reg8 *) AudioOut__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins AudioOut_H */

#endif
/* [] END OF FILE */

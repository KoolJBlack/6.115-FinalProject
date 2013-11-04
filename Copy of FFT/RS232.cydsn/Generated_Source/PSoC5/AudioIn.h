/*******************************************************************************
* File Name: AudioIn.h  
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

#if !defined(CY_PINS_AudioIn_H) /* Pins AudioIn_H */
#define CY_PINS_AudioIn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AudioIn_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_70 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AudioIn__PORT == 15 && (AudioIn__MASK & 0xC0))

/***************************************
*        Function Prototypes             
***************************************/    

void    AudioIn_Write(uint8 value) ;
void    AudioIn_SetDriveMode(uint8 mode) ;
uint8   AudioIn_ReadDataReg(void) ;
uint8   AudioIn_Read(void) ;
uint8   AudioIn_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define AudioIn_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define AudioIn_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define AudioIn_DM_RES_UP          PIN_DM_RES_UP
#define AudioIn_DM_RES_DWN         PIN_DM_RES_DWN
#define AudioIn_DM_OD_LO           PIN_DM_OD_LO
#define AudioIn_DM_OD_HI           PIN_DM_OD_HI
#define AudioIn_DM_STRONG          PIN_DM_STRONG
#define AudioIn_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define AudioIn_MASK               AudioIn__MASK
#define AudioIn_SHIFT              AudioIn__SHIFT
#define AudioIn_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AudioIn_PS                     (* (reg8 *) AudioIn__PS)
/* Data Register */
#define AudioIn_DR                     (* (reg8 *) AudioIn__DR)
/* Port Number */
#define AudioIn_PRT_NUM                (* (reg8 *) AudioIn__PRT) 
/* Connect to Analog Globals */                                                  
#define AudioIn_AG                     (* (reg8 *) AudioIn__AG)                       
/* Analog MUX bux enable */
#define AudioIn_AMUX                   (* (reg8 *) AudioIn__AMUX) 
/* Bidirectional Enable */                                                        
#define AudioIn_BIE                    (* (reg8 *) AudioIn__BIE)
/* Bit-mask for Aliased Register Access */
#define AudioIn_BIT_MASK               (* (reg8 *) AudioIn__BIT_MASK)
/* Bypass Enable */
#define AudioIn_BYP                    (* (reg8 *) AudioIn__BYP)
/* Port wide control signals */                                                   
#define AudioIn_CTL                    (* (reg8 *) AudioIn__CTL)
/* Drive Modes */
#define AudioIn_DM0                    (* (reg8 *) AudioIn__DM0) 
#define AudioIn_DM1                    (* (reg8 *) AudioIn__DM1)
#define AudioIn_DM2                    (* (reg8 *) AudioIn__DM2) 
/* Input Buffer Disable Override */
#define AudioIn_INP_DIS                (* (reg8 *) AudioIn__INP_DIS)
/* LCD Common or Segment Drive */
#define AudioIn_LCD_COM_SEG            (* (reg8 *) AudioIn__LCD_COM_SEG)
/* Enable Segment LCD */
#define AudioIn_LCD_EN                 (* (reg8 *) AudioIn__LCD_EN)
/* Slew Rate Control */
#define AudioIn_SLW                    (* (reg8 *) AudioIn__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AudioIn_PRTDSI__CAPS_SEL       (* (reg8 *) AudioIn__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AudioIn_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AudioIn__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AudioIn_PRTDSI__OE_SEL0        (* (reg8 *) AudioIn__PRTDSI__OE_SEL0) 
#define AudioIn_PRTDSI__OE_SEL1        (* (reg8 *) AudioIn__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AudioIn_PRTDSI__OUT_SEL0       (* (reg8 *) AudioIn__PRTDSI__OUT_SEL0) 
#define AudioIn_PRTDSI__OUT_SEL1       (* (reg8 *) AudioIn__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AudioIn_PRTDSI__SYNC_OUT       (* (reg8 *) AudioIn__PRTDSI__SYNC_OUT) 


#if defined(AudioIn__INTSTAT)  /* Interrupt Registers */

    #define AudioIn_INTSTAT                (* (reg8 *) AudioIn__INTSTAT)
    #define AudioIn_SNAP                   (* (reg8 *) AudioIn__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins AudioIn_H */

#endif
/* [] END OF FILE */

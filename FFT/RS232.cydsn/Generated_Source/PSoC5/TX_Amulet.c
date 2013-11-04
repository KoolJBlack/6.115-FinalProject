/*******************************************************************************
* File Name: TX_Amulet.c  
* Version 1.70
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "TX_Amulet.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TX_Amulet__PORT == 15 && (TX_Amulet__MASK & 0xC0))

/*******************************************************************************
* Function Name: TX_Amulet_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void TX_Amulet_Write(uint8 value) 
{
    uint8 staticBits = TX_Amulet_DR & ~TX_Amulet_MASK;
    TX_Amulet_DR = staticBits | ((value << TX_Amulet_SHIFT) & TX_Amulet_MASK);
}


/*******************************************************************************
* Function Name: TX_Amulet_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void TX_Amulet_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(TX_Amulet_0, mode);
}


/*******************************************************************************
* Function Name: TX_Amulet_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro TX_Amulet_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TX_Amulet_Read(void) 
{
    return (TX_Amulet_PS & TX_Amulet_MASK) >> TX_Amulet_SHIFT;
}


/*******************************************************************************
* Function Name: TX_Amulet_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 TX_Amulet_ReadDataReg(void) 
{
    return (TX_Amulet_DR & TX_Amulet_MASK) >> TX_Amulet_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TX_Amulet_INTSTAT) 

    /*******************************************************************************
    * Function Name: TX_Amulet_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 TX_Amulet_ClearInterrupt(void) 
    {
        return (TX_Amulet_INTSTAT & TX_Amulet_MASK) >> TX_Amulet_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif
/* [] END OF FILE */ 

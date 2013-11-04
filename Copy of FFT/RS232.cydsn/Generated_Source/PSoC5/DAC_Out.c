/*******************************************************************************
* File Name: DAC_Out.c  
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
#include "DAC_Out.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DAC_Out__PORT == 15 && (DAC_Out__MASK & 0xC0))

/*******************************************************************************
* Function Name: DAC_Out_Write
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
void DAC_Out_Write(uint8 value) 
{
    uint8 staticBits = DAC_Out_DR & ~DAC_Out_MASK;
    DAC_Out_DR = staticBits | ((value << DAC_Out_SHIFT) & DAC_Out_MASK);
}


/*******************************************************************************
* Function Name: DAC_Out_SetDriveMode
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
void DAC_Out_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DAC_Out_0, mode);
}


/*******************************************************************************
* Function Name: DAC_Out_Read
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
*  Macro DAC_Out_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DAC_Out_Read(void) 
{
    return (DAC_Out_PS & DAC_Out_MASK) >> DAC_Out_SHIFT;
}


/*******************************************************************************
* Function Name: DAC_Out_ReadDataReg
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
uint8 DAC_Out_ReadDataReg(void) 
{
    return (DAC_Out_DR & DAC_Out_MASK) >> DAC_Out_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DAC_Out_INTSTAT) 

    /*******************************************************************************
    * Function Name: DAC_Out_ClearInterrupt
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
    uint8 DAC_Out_ClearInterrupt(void) 
    {
        return (DAC_Out_INTSTAT & DAC_Out_MASK) >> DAC_Out_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif
/* [] END OF FILE */ 

/*******************************************************************************
* File Name: AudioOut.c  
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
#include "AudioOut.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AudioOut__PORT == 15 && (AudioOut__MASK & 0xC0))

/*******************************************************************************
* Function Name: AudioOut_Write
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
void AudioOut_Write(uint8 value) 
{
    uint8 staticBits = AudioOut_DR & ~AudioOut_MASK;
    AudioOut_DR = staticBits | ((value << AudioOut_SHIFT) & AudioOut_MASK);
}


/*******************************************************************************
* Function Name: AudioOut_SetDriveMode
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
void AudioOut_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(AudioOut_0, mode);
}


/*******************************************************************************
* Function Name: AudioOut_Read
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
*  Macro AudioOut_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 AudioOut_Read(void) 
{
    return (AudioOut_PS & AudioOut_MASK) >> AudioOut_SHIFT;
}


/*******************************************************************************
* Function Name: AudioOut_ReadDataReg
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
uint8 AudioOut_ReadDataReg(void) 
{
    return (AudioOut_DR & AudioOut_MASK) >> AudioOut_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(AudioOut_INTSTAT) 

    /*******************************************************************************
    * Function Name: AudioOut_ClearInterrupt
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
    uint8 AudioOut_ClearInterrupt(void) 
    {
        return (AudioOut_INTSTAT & AudioOut_MASK) >> AudioOut_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif
/* [] END OF FILE */ 

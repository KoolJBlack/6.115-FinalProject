/*******************************************************************************
* File Name: AudioIn.c  
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
#include "AudioIn.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AudioIn__PORT == 15 && (AudioIn__MASK & 0xC0))

/*******************************************************************************
* Function Name: AudioIn_Write
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
void AudioIn_Write(uint8 value) 
{
    uint8 staticBits = AudioIn_DR & ~AudioIn_MASK;
    AudioIn_DR = staticBits | ((value << AudioIn_SHIFT) & AudioIn_MASK);
}


/*******************************************************************************
* Function Name: AudioIn_SetDriveMode
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
void AudioIn_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(AudioIn_0, mode);
}


/*******************************************************************************
* Function Name: AudioIn_Read
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
*  Macro AudioIn_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 AudioIn_Read(void) 
{
    return (AudioIn_PS & AudioIn_MASK) >> AudioIn_SHIFT;
}


/*******************************************************************************
* Function Name: AudioIn_ReadDataReg
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
uint8 AudioIn_ReadDataReg(void) 
{
    return (AudioIn_DR & AudioIn_MASK) >> AudioIn_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(AudioIn_INTSTAT) 

    /*******************************************************************************
    * Function Name: AudioIn_ClearInterrupt
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
    uint8 AudioIn_ClearInterrupt(void) 
    {
        return (AudioIn_INTSTAT & AudioIn_MASK) >> AudioIn_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif
/* [] END OF FILE */ 

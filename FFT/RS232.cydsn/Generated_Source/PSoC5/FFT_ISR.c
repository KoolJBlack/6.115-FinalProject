/*******************************************************************************
* File Name: FFT_ISR.c  
* Version 1.60
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#include <CYDEVICE.H>
#include <CYDEVICE_TRM.H>
#include <CYLIB.H>
#include <FFT_ISR.H>


/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START FFT_ISR_intc` */

/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE	16
#endif
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);

/*******************************************************************************
* Function Name: FFT_ISR_Start
********************************************************************************
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   void.
*
*
* Return:
*   void.
*
*******************************************************************************/
void FFT_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    FFT_ISR_Disable();

    /* Set the ISR to point to the FFT_ISR Interrupt. */
    FFT_ISR_SetVector(FFT_ISR_Interrupt);

    /* Set the priority. */
    FFT_ISR_SetPriority(FFT_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    FFT_ISR_Enable();
}

/*******************************************************************************
* Function Name: FFT_ISR_StartEx
********************************************************************************
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
*
* Return:
*   void.
*
*******************************************************************************/
void FFT_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    FFT_ISR_Disable();

    /* Set the ISR to point to the FFT_ISR Interrupt. */
    FFT_ISR_SetVector(address);

    /* Set the priority. */
    FFT_ISR_SetPriority(FFT_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    FFT_ISR_Enable();
}

/*******************************************************************************
* Function Name: FFT_ISR_Stop
********************************************************************************
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
void FFT_ISR_Stop(void) 
{
    /* Disable this interrupt. */
    FFT_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    FFT_ISR_SetVector(IntDefaultHandler);
}

/*******************************************************************************
* Function Name: FFT_ISR_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for FFT_ISR.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
*
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
CY_ISR(FFT_ISR_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START FFT_ISR_Interrupt` */
    CalculateFFT();
    /* `#END` */
}

/*******************************************************************************
* Function Name: FFT_ISR_SetVector
********************************************************************************
* Summary:
*   Change the ISR vector for the Interrupt. Note calling FFT_ISR_Start
*   will override any effect this method would have had. To set the vector before
*   the component has been started use FFT_ISR_StartEx instead.
*
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void FFT_ISR_SetVector(cyisraddress address) 
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + FFT_ISR__INTC_NUMBER] = address;
}

/*******************************************************************************
* Function Name: FFT_ISR_GetVector
********************************************************************************
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*
*******************************************************************************/
cyisraddress FFT_ISR_GetVector(void) 
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + FFT_ISR__INTC_NUMBER];
}

/*******************************************************************************
* Function Name: FFT_ISR_SetPriority
********************************************************************************
* Summary:
*   Sets the Priority of the Interrupt. Note calling FFT_ISR_Start
*   or FFT_ISR_StartEx will override any effect this method would have had. 
*	This method should only be called after FFT_ISR_Start or 
*	FFT_ISR_StartEx has been called. To set the initial
*	priority for the component use the cydwr file in the tool.
*
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void FFT_ISR_SetPriority(uint8 priority) 
{
    *FFT_ISR_INTC_PRIOR = priority << 5;
}

/*******************************************************************************
* Function Name: FFT_ISR_GetPriority
********************************************************************************
* Summary:
*   Gets the Priority of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
*******************************************************************************/
uint8 FFT_ISR_GetPriority(void) 
{
    uint8 priority;


    priority = *FFT_ISR_INTC_PRIOR >> 5;

    return priority;
}

/*******************************************************************************
* Function Name: FFT_ISR_Enable
********************************************************************************
* Summary:
*   Enables the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void FFT_ISR_Enable(void) 
{
    /* Enable the general interrupt. */
    *FFT_ISR_INTC_SET_EN = FFT_ISR__INTC_MASK;
}

/*******************************************************************************
* Function Name: FFT_ISR_GetState
********************************************************************************
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   1 if enabled, 0 if disabled.
*
*
*******************************************************************************/
uint8 FFT_ISR_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return (*FFT_ISR_INTC_SET_EN & FFT_ISR__INTC_MASK) ? 1:0;
}

/*******************************************************************************
* Function Name: FFT_ISR_Disable
********************************************************************************
* Summary:
*   Disables the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void FFT_ISR_Disable(void) 
{
    /* Disable the general interrupt. */
    *FFT_ISR_INTC_CLR_EN = FFT_ISR__INTC_MASK;
}

/*******************************************************************************
* Function Name: FFT_ISR_SetPending
********************************************************************************
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void FFT_ISR_SetPending(void) 
{
    *FFT_ISR_INTC_SET_PD = FFT_ISR__INTC_MASK;
}

/*******************************************************************************
* Function Name: FFT_ISR_ClearPending
********************************************************************************
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void FFT_ISR_ClearPending(void) 
{
    *FFT_ISR_INTC_CLR_PD = FFT_ISR__INTC_MASK;
}

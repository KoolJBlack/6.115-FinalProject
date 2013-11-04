/*******************************************************************************
* File Name: UART_Amulet_INT.c
* Version 2.20
*
* Description:
*  This file provides all Interrupt Service functionality of the UART component
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_Amulet.h"
#include "CyLib.h"


/***************************************
* Custom Declratations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if( (UART_Amulet_RX_ENABLED || UART_Amulet_HD_ENABLED) && \
     (UART_Amulet_RXBUFFERSIZE > UART_Amulet_FIFO_LENGTH))

    extern volatile uint8 UART_Amulet_rxBuffer[];
    extern volatile uint8 UART_Amulet_rxBufferRead;
    extern volatile uint8 UART_Amulet_rxBufferWrite;
    extern volatile uint8 UART_Amulet_rxBufferLoopDetect;
    extern volatile uint8 UART_Amulet_rxBufferOverflow;
    #if (UART_Amulet_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 UART_Amulet_rxAddressMode;
        extern volatile uint8 UART_Amulet_rxAddressDetected;
    #endif /* End EnableHWAddress */    

    /*******************************************************************************
    * Function Name: UART_Amulet_RXISR
    ********************************************************************************
    *
    * Summary:
    *  Interrupt Service Routine for RX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_Amulet_rxBuffer - RAM buffer pointer for save received data.
    *  UART_Amulet_rxBufferWrite - cyclic index for write to rxBuffer, 
    *     increments after each byte saved to buffer.
    *  UART_Amulet_rxBufferRead - cyclic index for read from rxBuffer, 
    *     checked to detect overflow condition.
    *  UART_Amulet_rxBufferOverflow - software overflow flag. Set to one
    *     when UART_Amulet_rxBufferWrite index overtakes 
    *     UART_Amulet_rxBufferRead index.
    *  UART_Amulet_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when UART_Amulet_rxBufferWrite is equal to 
    *    UART_Amulet_rxBufferRead
    *  UART_Amulet_rxAddressMode - this variable contains the Address mode, 
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  UART_Amulet_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(UART_Amulet_RXISR)
    {
        uint8 readData;
        uint8 increment_pointer = 0u;

        /* User code required at start of ISR */
        /* `#START UART_Amulet_RXISR_START` */

        /* `#END` */

        readData = UART_Amulet_RXSTATUS_REG;

        if((readData & (UART_Amulet_RX_STS_BREAK | UART_Amulet_RX_STS_PAR_ERROR |
                        UART_Amulet_RX_STS_STOP_ERROR | UART_Amulet_RX_STS_OVERRUN)) != 0u)
        {
            /* ERROR handling. */
            /* `#START UART_Amulet_RXISR_ERROR` */

            /* `#END` */
        }

        while(readData & UART_Amulet_RX_STS_FIFO_NOTEMPTY)
        {
            
            #if (UART_Amulet_RXHW_ADDRESS_ENABLED)
                if(UART_Amulet_rxAddressMode == UART_Amulet__B_UART__AM_SW_DETECT_TO_BUFFER) 
                {
                    if((readData & UART_Amulet_RX_STS_MRKSPC) != 0u)
                    {  
                        if ((readData & UART_Amulet_RX_STS_ADDR_MATCH) != 0u)
                        {
                            UART_Amulet_rxAddressDetected = 1u;
                        }
                        else
                        {
                            UART_Amulet_rxAddressDetected = 0u;
                        }
                    }

                    readData = UART_Amulet_RXDATA_REG;
                    if(UART_Amulet_rxAddressDetected != 0u)
                    {   /* store only addressed data */
                        UART_Amulet_rxBuffer[UART_Amulet_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* without software addressing */
                {
                    UART_Amulet_rxBuffer[UART_Amulet_rxBufferWrite] = UART_Amulet_RXDATA_REG;
                    increment_pointer = 1u;
                }
            #else  /* without addressing */
                UART_Amulet_rxBuffer[UART_Amulet_rxBufferWrite] = UART_Amulet_RXDATA_REG;
                increment_pointer = 1u;
            #endif /* End SW_DETECT_TO_BUFFER */
            
            /* do not increment buffer pointer when skip not adderessed data */
            if( increment_pointer != 0u )
            {
                if(UART_Amulet_rxBufferLoopDetect)
                {   /* Set Software Buffer status Overflow */
                    UART_Amulet_rxBufferOverflow = 1u;
                }
                /* Set next pointer. */
                UART_Amulet_rxBufferWrite++;

                /* Check pointer for a loop condition */
                if(UART_Amulet_rxBufferWrite >= UART_Amulet_RXBUFFERSIZE)
                {
                    UART_Amulet_rxBufferWrite = 0u;
                }
                /* Detect pre-overload condition and set flag */
                if(UART_Amulet_rxBufferWrite == UART_Amulet_rxBufferRead)
                {
                    UART_Amulet_rxBufferLoopDetect = 1u;
                    /* When Hardware Flow Control selected */
                    #if(UART_Amulet_FLOW_CONTROL != 0u)
                    /* Disable RX interrupt mask, it will be enabled when user read data from the buffer using APIs */
                        UART_Amulet_RXSTATUS_MASK_REG  &= ~UART_Amulet_RX_STS_FIFO_NOTEMPTY;
                        CyIntClearPending(UART_Amulet_RX_VECT_NUM); 
                        break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                    #endif /* End UART_Amulet_FLOW_CONTROL != 0 */    
                }
            }

            /* Check again if there is data. */
            readData = UART_Amulet_RXSTATUS_REG;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START UART_Amulet_RXISR_END` */

        /* `#END` */

    }

#endif /* End UART_Amulet_RX_ENABLED && (UART_Amulet_RXBUFFERSIZE > UART_Amulet_FIFO_LENGTH) */


#if(UART_Amulet_TX_ENABLED && (UART_Amulet_TXBUFFERSIZE > UART_Amulet_FIFO_LENGTH))

    extern volatile uint8 UART_Amulet_txBuffer[];
    extern volatile uint8 UART_Amulet_txBufferRead;
    extern uint8 UART_Amulet_txBufferWrite;


    /*******************************************************************************
    * Function Name: UART_Amulet_TXISR
    ********************************************************************************
    *
    * Summary:
    * Interrupt Service Routine for the TX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_Amulet_txBuffer - RAM buffer pointer for transmit data from.
    *  UART_Amulet_txBufferRead - cyclic index for read and transmit data 
    *     from txBuffer, increments after each transmited byte.
    *  UART_Amulet_rxBufferWrite - cyclic index for write to txBuffer, 
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(UART_Amulet_TXISR)
    {

        /* User code required at start of ISR */
        /* `#START UART_Amulet_TXISR_START` */

        /* `#END` */

        while((UART_Amulet_txBufferRead != UART_Amulet_txBufferWrite) && \
             !(UART_Amulet_TXSTATUS_REG & UART_Amulet_TX_STS_FIFO_FULL))
        {
            /* Check pointer. */
            if(UART_Amulet_txBufferRead >= UART_Amulet_TXBUFFERSIZE)
            {
                UART_Amulet_txBufferRead = 0u;
            }

            UART_Amulet_TXDATA_REG = UART_Amulet_txBuffer[UART_Amulet_txBufferRead];

            /* Set next pointer. */
            UART_Amulet_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START UART_Amulet_TXISR_END` */

        /* `#END` */
        
    }

#endif /* End UART_Amulet_TX_ENABLED && (UART_Amulet_TXBUFFERSIZE > UART_Amulet_FIFO_LENGTH) */


/* [] END OF FILE */

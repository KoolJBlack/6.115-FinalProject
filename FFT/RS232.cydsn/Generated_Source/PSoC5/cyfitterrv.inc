    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; UART_Amulet_IntClock
UART_Amulet_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
UART_Amulet_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
UART_Amulet_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
UART_Amulet_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
UART_Amulet_IntClock__INDEX EQU 0x01
UART_Amulet_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
UART_Amulet_IntClock__PM_ACT_MSK EQU 0x02
UART_Amulet_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
UART_Amulet_IntClock__PM_STBY_MSK EQU 0x02

; ADC_SAR_1_ADC_SAR
ADC_SAR_1_ADC_SAR__CLK EQU CYREG_SAR1_CLK
ADC_SAR_1_ADC_SAR__CSR0 EQU CYREG_SAR1_CSR0
ADC_SAR_1_ADC_SAR__CSR1 EQU CYREG_SAR1_CSR1
ADC_SAR_1_ADC_SAR__CSR2 EQU CYREG_SAR1_CSR2
ADC_SAR_1_ADC_SAR__CSR3 EQU CYREG_SAR1_CSR3
ADC_SAR_1_ADC_SAR__CSR4 EQU CYREG_SAR1_CSR4
ADC_SAR_1_ADC_SAR__CSR5 EQU CYREG_SAR1_CSR5
ADC_SAR_1_ADC_SAR__CSR6 EQU CYREG_SAR1_CSR6
ADC_SAR_1_ADC_SAR__PM_ACT_CFG EQU CYREG_PM_ACT_CFG11
ADC_SAR_1_ADC_SAR__PM_ACT_MSK EQU 0x02
ADC_SAR_1_ADC_SAR__PM_STBY_CFG EQU CYREG_PM_STBY_CFG11
ADC_SAR_1_ADC_SAR__PM_STBY_MSK EQU 0x02
ADC_SAR_1_ADC_SAR__SW0 EQU CYREG_SAR1_SW0
ADC_SAR_1_ADC_SAR__SW2 EQU CYREG_SAR1_SW2
ADC_SAR_1_ADC_SAR__SW3 EQU CYREG_SAR1_SW3
ADC_SAR_1_ADC_SAR__SW4 EQU CYREG_SAR1_SW4
ADC_SAR_1_ADC_SAR__SW6 EQU CYREG_SAR1_SW6
ADC_SAR_1_ADC_SAR__TR0 EQU CYREG_SAR1_TR0
ADC_SAR_1_ADC_SAR__WRK0 EQU CYREG_SAR1_WRK0
ADC_SAR_1_ADC_SAR__WRK1 EQU CYREG_SAR1_WRK1

; ADC_SAR_1_theACLK
ADC_SAR_1_theACLK__CFG0 EQU CYREG_CLKDIST_ACFG0_CFG0
ADC_SAR_1_theACLK__CFG1 EQU CYREG_CLKDIST_ACFG0_CFG1
ADC_SAR_1_theACLK__CFG2 EQU CYREG_CLKDIST_ACFG0_CFG2
ADC_SAR_1_theACLK__CFG2_SRC_SEL_MASK EQU 0x07
ADC_SAR_1_theACLK__CFG3 EQU CYREG_CLKDIST_ACFG0_CFG3
ADC_SAR_1_theACLK__CFG3_PHASE_DLY_MASK EQU 0x0F
ADC_SAR_1_theACLK__INDEX EQU 0x00
ADC_SAR_1_theACLK__PM_ACT_CFG EQU CYREG_PM_ACT_CFG1
ADC_SAR_1_theACLK__PM_ACT_MSK EQU 0x01
ADC_SAR_1_theACLK__PM_STBY_CFG EQU CYREG_PM_STBY_CFG1
ADC_SAR_1_theACLK__PM_STBY_MSK EQU 0x01

; UART_Amulet_BUART
UART_Amulet_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB07_08_ACTL
UART_Amulet_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB07_08_ST
UART_Amulet_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B1_UDB07_MSK
UART_Amulet_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB07_MSK_ACTL
UART_Amulet_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB07_MSK_ACTL
UART_Amulet_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB07_ACTL
UART_Amulet_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB07_ST_CTL
UART_Amulet_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB07_ST_CTL
UART_Amulet_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B1_UDB07_ST
UART_Amulet_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB07_08_ACTL
UART_Amulet_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB07_08_CTL
UART_Amulet_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB07_08_CTL
UART_Amulet_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB07_08_CTL
UART_Amulet_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB07_08_CTL
UART_Amulet_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB07_08_MSK
UART_Amulet_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB07_08_MSK
UART_Amulet_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB07_08_MSK
UART_Amulet_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB07_08_MSK
UART_Amulet_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB07_ACTL
UART_Amulet_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B1_UDB07_CTL
UART_Amulet_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB07_ST_CTL
UART_Amulet_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B1_UDB07_CTL
UART_Amulet_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B1_UDB07_ST_CTL
UART_Amulet_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB07_MSK_ACTL
UART_Amulet_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B1_UDB07_MSK
UART_Amulet_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB07_MSK_ACTL
UART_Amulet_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB07_08_A0
UART_Amulet_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB07_08_A1
UART_Amulet_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB07_08_D0
UART_Amulet_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB07_08_D1
UART_Amulet_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB07_08_ACTL
UART_Amulet_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB07_08_F0
UART_Amulet_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB07_08_F1
UART_Amulet_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB07_A0_A1
UART_Amulet_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B0_UDB07_A0
UART_Amulet_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B0_UDB07_A1
UART_Amulet_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB07_D0_D1
UART_Amulet_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B0_UDB07_D0
UART_Amulet_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B0_UDB07_D1
UART_Amulet_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB07_ACTL
UART_Amulet_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB07_F0_F1
UART_Amulet_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B0_UDB07_F0
UART_Amulet_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B0_UDB07_F1
UART_Amulet_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB07_08_ACTL
UART_Amulet_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB07_08_ST
UART_Amulet_BUART_sRX_RxSts__3__MASK EQU 0x08
UART_Amulet_BUART_sRX_RxSts__3__POS EQU 3
UART_Amulet_BUART_sRX_RxSts__4__MASK EQU 0x10
UART_Amulet_BUART_sRX_RxSts__4__POS EQU 4
UART_Amulet_BUART_sRX_RxSts__5__MASK EQU 0x20
UART_Amulet_BUART_sRX_RxSts__5__POS EQU 5
UART_Amulet_BUART_sRX_RxSts__MASK EQU 0x38
UART_Amulet_BUART_sRX_RxSts__MASK_REG EQU CYREG_B0_UDB07_MSK
UART_Amulet_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB07_ACTL
UART_Amulet_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B0_UDB07_ST
UART_Amulet_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB01_02_A0
UART_Amulet_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB01_02_A1
UART_Amulet_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB01_02_D0
UART_Amulet_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB01_02_D1
UART_Amulet_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB01_02_ACTL
UART_Amulet_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB01_02_F0
UART_Amulet_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB01_02_F1
UART_Amulet_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB01_A0_A1
UART_Amulet_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB01_A0
UART_Amulet_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB01_A1
UART_Amulet_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB01_D0_D1
UART_Amulet_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB01_D0
UART_Amulet_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB01_D1
UART_Amulet_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB01_ACTL
UART_Amulet_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB01_F0_F1
UART_Amulet_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB01_F0
UART_Amulet_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB01_F1
UART_Amulet_BUART_sTX_TxSts__0__MASK EQU 0x01
UART_Amulet_BUART_sTX_TxSts__0__POS EQU 0
UART_Amulet_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB01_02_ACTL
UART_Amulet_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB01_02_ST
UART_Amulet_BUART_sTX_TxSts__1__MASK EQU 0x02
UART_Amulet_BUART_sTX_TxSts__1__POS EQU 1
UART_Amulet_BUART_sTX_TxSts__2__MASK EQU 0x04
UART_Amulet_BUART_sTX_TxSts__2__POS EQU 2
UART_Amulet_BUART_sTX_TxSts__3__MASK EQU 0x08
UART_Amulet_BUART_sTX_TxSts__3__POS EQU 3
UART_Amulet_BUART_sTX_TxSts__MASK EQU 0x0F
UART_Amulet_BUART_sTX_TxSts__MASK_REG EQU CYREG_B0_UDB01_MSK
UART_Amulet_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB01_ACTL
UART_Amulet_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B0_UDB01_ST
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B0_UDB06_07_A0
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B0_UDB06_07_A1
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B0_UDB06_07_D0
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B0_UDB06_07_D1
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB06_07_ACTL
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B0_UDB06_07_F0
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B0_UDB06_07_F1
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B0_UDB06_A0_A1
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B0_UDB06_A0
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B0_UDB06_A1
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B0_UDB06_D0_D1
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B0_UDB06_D0
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B0_UDB06_D1
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B0_UDB06_ACTL
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B0_UDB06_F0_F1
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B0_UDB06_F0
UART_Amulet_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B0_UDB06_F1

; ADC_SAR_1_Bypass
ADC_SAR_1_Bypass__0__MASK EQU 0x04
ADC_SAR_1_Bypass__0__PC EQU CYREG_PRT0_PC2
ADC_SAR_1_Bypass__0__PORT EQU 0
ADC_SAR_1_Bypass__0__SHIFT EQU 2
ADC_SAR_1_Bypass__AG EQU CYREG_PRT0_AG
ADC_SAR_1_Bypass__AMUX EQU CYREG_PRT0_AMUX
ADC_SAR_1_Bypass__BIE EQU CYREG_PRT0_BIE
ADC_SAR_1_Bypass__BIT_MASK EQU CYREG_PRT0_BIT_MASK
ADC_SAR_1_Bypass__BYP EQU CYREG_PRT0_BYP
ADC_SAR_1_Bypass__CTL EQU CYREG_PRT0_CTL
ADC_SAR_1_Bypass__DM0 EQU CYREG_PRT0_DM0
ADC_SAR_1_Bypass__DM1 EQU CYREG_PRT0_DM1
ADC_SAR_1_Bypass__DM2 EQU CYREG_PRT0_DM2
ADC_SAR_1_Bypass__DR EQU CYREG_PRT0_DR
ADC_SAR_1_Bypass__INP_DIS EQU CYREG_PRT0_INP_DIS
ADC_SAR_1_Bypass__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
ADC_SAR_1_Bypass__LCD_EN EQU CYREG_PRT0_LCD_EN
ADC_SAR_1_Bypass__MASK EQU 0x04
ADC_SAR_1_Bypass__PORT EQU 0
ADC_SAR_1_Bypass__PRT EQU CYREG_PRT0_PRT
ADC_SAR_1_Bypass__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
ADC_SAR_1_Bypass__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
ADC_SAR_1_Bypass__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
ADC_SAR_1_Bypass__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
ADC_SAR_1_Bypass__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
ADC_SAR_1_Bypass__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
ADC_SAR_1_Bypass__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
ADC_SAR_1_Bypass__PS EQU CYREG_PRT0_PS
ADC_SAR_1_Bypass__SHIFT EQU 2
ADC_SAR_1_Bypass__SLW EQU CYREG_PRT0_SLW

; VDAC8_1_viDAC8
VDAC8_1_viDAC8__CR0 EQU CYREG_DAC1_CR0
VDAC8_1_viDAC8__CR1 EQU CYREG_DAC1_CR1
VDAC8_1_viDAC8__D EQU CYREG_DAC1_D
VDAC8_1_viDAC8__PM_ACT_CFG EQU CYREG_PM_ACT_CFG8
VDAC8_1_viDAC8__PM_ACT_MSK EQU 0x02
VDAC8_1_viDAC8__PM_STBY_CFG EQU CYREG_PM_STBY_CFG8
VDAC8_1_viDAC8__PM_STBY_MSK EQU 0x02
VDAC8_1_viDAC8__STROBE EQU CYREG_DAC1_STROBE
VDAC8_1_viDAC8__SW0 EQU CYREG_DAC1_SW0
VDAC8_1_viDAC8__SW2 EQU CYREG_DAC1_SW2
VDAC8_1_viDAC8__SW3 EQU CYREG_DAC1_SW3
VDAC8_1_viDAC8__SW4 EQU CYREG_DAC1_SW4
VDAC8_1_viDAC8__TR EQU CYREG_DAC1_TR
VDAC8_1_viDAC8__TRIM__M1 EQU CYREG_FLSHID_CUST_TABLES_DAC1_M1
VDAC8_1_viDAC8__TRIM__M2 EQU CYREG_FLSHID_CUST_TABLES_DAC1_M2
VDAC8_1_viDAC8__TRIM__M3 EQU CYREG_FLSHID_CUST_TABLES_DAC1_M3
VDAC8_1_viDAC8__TRIM__M4 EQU CYREG_FLSHID_CUST_TABLES_DAC1_M4
VDAC8_1_viDAC8__TRIM__M5 EQU CYREG_FLSHID_CUST_TABLES_DAC1_M5
VDAC8_1_viDAC8__TRIM__M6 EQU CYREG_FLSHID_CUST_TABLES_DAC1_M6
VDAC8_1_viDAC8__TRIM__M7 EQU CYREG_FLSHID_CUST_TABLES_DAC1_M7
VDAC8_1_viDAC8__TRIM__M8 EQU CYREG_FLSHID_CUST_TABLES_DAC1_M8
VDAC8_1_viDAC8__TST EQU CYREG_DAC1_TST

; ADC_SAR_1_IRQ
ADC_SAR_1_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
ADC_SAR_1_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
ADC_SAR_1_IRQ__INTC_MASK EQU 0x04
ADC_SAR_1_IRQ__INTC_NUMBER EQU 2
ADC_SAR_1_IRQ__INTC_PRIOR_NUM EQU 7
ADC_SAR_1_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_2
ADC_SAR_1_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
ADC_SAR_1_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; rx_int_Amulet
rx_int_Amulet__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
rx_int_Amulet__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
rx_int_Amulet__INTC_MASK EQU 0x10
rx_int_Amulet__INTC_NUMBER EQU 4
rx_int_Amulet__INTC_PRIOR_NUM EQU 7
rx_int_Amulet__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_4
rx_int_Amulet__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
rx_int_Amulet__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; UART_IntClock
UART_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
UART_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
UART_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
UART_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
UART_IntClock__INDEX EQU 0x00
UART_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
UART_IntClock__PM_ACT_MSK EQU 0x01
UART_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
UART_IntClock__PM_STBY_MSK EQU 0x01

; LCD_LCDPort
LCD_LCDPort__0__MASK EQU 0x01
LCD_LCDPort__0__PC EQU CYREG_PRT2_PC0
LCD_LCDPort__0__PORT EQU 2
LCD_LCDPort__0__SHIFT EQU 0
LCD_LCDPort__1__MASK EQU 0x02
LCD_LCDPort__1__PC EQU CYREG_PRT2_PC1
LCD_LCDPort__1__PORT EQU 2
LCD_LCDPort__1__SHIFT EQU 1
LCD_LCDPort__2__MASK EQU 0x04
LCD_LCDPort__2__PC EQU CYREG_PRT2_PC2
LCD_LCDPort__2__PORT EQU 2
LCD_LCDPort__2__SHIFT EQU 2
LCD_LCDPort__3__MASK EQU 0x08
LCD_LCDPort__3__PC EQU CYREG_PRT2_PC3
LCD_LCDPort__3__PORT EQU 2
LCD_LCDPort__3__SHIFT EQU 3
LCD_LCDPort__4__MASK EQU 0x10
LCD_LCDPort__4__PC EQU CYREG_PRT2_PC4
LCD_LCDPort__4__PORT EQU 2
LCD_LCDPort__4__SHIFT EQU 4
LCD_LCDPort__5__MASK EQU 0x20
LCD_LCDPort__5__PC EQU CYREG_PRT2_PC5
LCD_LCDPort__5__PORT EQU 2
LCD_LCDPort__5__SHIFT EQU 5
LCD_LCDPort__6__MASK EQU 0x40
LCD_LCDPort__6__PC EQU CYREG_PRT2_PC6
LCD_LCDPort__6__PORT EQU 2
LCD_LCDPort__6__SHIFT EQU 6
LCD_LCDPort__AG EQU CYREG_PRT2_AG
LCD_LCDPort__AMUX EQU CYREG_PRT2_AMUX
LCD_LCDPort__BIE EQU CYREG_PRT2_BIE
LCD_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
LCD_LCDPort__BYP EQU CYREG_PRT2_BYP
LCD_LCDPort__CTL EQU CYREG_PRT2_CTL
LCD_LCDPort__DM0 EQU CYREG_PRT2_DM0
LCD_LCDPort__DM1 EQU CYREG_PRT2_DM1
LCD_LCDPort__DM2 EQU CYREG_PRT2_DM2
LCD_LCDPort__DR EQU CYREG_PRT2_DR
LCD_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
LCD_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
LCD_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
LCD_LCDPort__MASK EQU 0x7F
LCD_LCDPort__PORT EQU 2
LCD_LCDPort__PRT EQU CYREG_PRT2_PRT
LCD_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
LCD_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
LCD_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
LCD_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
LCD_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
LCD_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
LCD_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
LCD_LCDPort__PS EQU CYREG_PRT2_PS
LCD_LCDPort__SHIFT EQU 0
LCD_LCDPort__SLW EQU CYREG_PRT2_SLW

; UART_BUART
UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B0_UDB03_04_ST
UART_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B0_UDB03_MSK
UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B0_UDB03_ST_CTL
UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B0_UDB03_ST_CTL
UART_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B0_UDB03_ST
UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB03_04_CTL
UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB03_04_CTL
UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB03_04_CTL
UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB03_04_CTL
UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB03_04_MSK
UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB03_04_MSK
UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB03_04_MSK
UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB03_04_MSK
UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
UART_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B0_UDB03_CTL
UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B0_UDB03_ST_CTL
UART_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B0_UDB03_CTL
UART_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B0_UDB03_ST_CTL
UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
UART_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B0_UDB03_MSK
UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB03_04_A0
UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB03_04_A1
UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB03_04_D0
UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB03_04_D1
UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB03_04_F0
UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB03_04_F1
UART_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB03_A0_A1
UART_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B0_UDB03_A0
UART_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B0_UDB03_A1
UART_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB03_D0_D1
UART_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B0_UDB03_D0
UART_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B0_UDB03_D1
UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
UART_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB03_F0_F1
UART_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B0_UDB03_F0
UART_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B0_UDB03_F1
UART_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
UART_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB03_MSK_ACTL
UART_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB04_05_ACTL
UART_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB04_05_ST
UART_BUART_sRX_RxSts__3__MASK EQU 0x08
UART_BUART_sRX_RxSts__3__POS EQU 3
UART_BUART_sRX_RxSts__4__MASK EQU 0x10
UART_BUART_sRX_RxSts__4__POS EQU 4
UART_BUART_sRX_RxSts__5__MASK EQU 0x20
UART_BUART_sRX_RxSts__5__POS EQU 5
UART_BUART_sRX_RxSts__MASK EQU 0x38
UART_BUART_sRX_RxSts__MASK_REG EQU CYREG_B0_UDB04_MSK
UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB04_ACTL
UART_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B0_UDB04_ST
UART_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB05_06_A0
UART_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB05_06_A1
UART_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB05_06_D0
UART_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB05_06_D1
UART_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB05_06_ACTL
UART_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB05_06_F0
UART_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB05_06_F1
UART_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB05_A0_A1
UART_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB05_A0
UART_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB05_A1
UART_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB05_D0_D1
UART_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB05_D0
UART_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB05_D1
UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB05_ACTL
UART_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB05_F0_F1
UART_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB05_F0
UART_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB05_F1
UART_BUART_sTX_TxSts__0__MASK EQU 0x01
UART_BUART_sTX_TxSts__0__POS EQU 0
UART_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB05_06_ACTL
UART_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB05_06_ST
UART_BUART_sTX_TxSts__1__MASK EQU 0x02
UART_BUART_sTX_TxSts__1__POS EQU 1
UART_BUART_sTX_TxSts__2__MASK EQU 0x04
UART_BUART_sTX_TxSts__2__POS EQU 2
UART_BUART_sTX_TxSts__3__MASK EQU 0x08
UART_BUART_sTX_TxSts__3__POS EQU 3
UART_BUART_sTX_TxSts__MASK EQU 0x0F
UART_BUART_sTX_TxSts__MASK_REG EQU CYREG_B0_UDB05_MSK
UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB05_ACTL
UART_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B0_UDB05_ST
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B1_UDB06_07_A0
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B1_UDB06_07_A1
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B1_UDB06_07_D0
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B1_UDB06_07_D1
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB06_07_ACTL
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B1_UDB06_07_F0
UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B1_UDB06_07_F1
UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B1_UDB06_A0_A1
UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B1_UDB06_A0
UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B1_UDB06_A1
UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B1_UDB06_D0_D1
UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B1_UDB06_D0
UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B1_UDB06_D1
UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B1_UDB06_ACTL
UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B1_UDB06_F0_F1
UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B1_UDB06_F0
UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B1_UDB06_F1

; Clock_ISR
Clock_ISR__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
Clock_ISR__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
Clock_ISR__INTC_MASK EQU 0x01
Clock_ISR__INTC_NUMBER EQU 0
Clock_ISR__INTC_PRIOR_NUM EQU 0
Clock_ISR__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
Clock_ISR__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
Clock_ISR__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; RX_Amulet
RX_Amulet__0__MASK EQU 0x04
RX_Amulet__0__PC EQU CYREG_PRT12_PC2
RX_Amulet__0__PORT EQU 12
RX_Amulet__0__SHIFT EQU 2
RX_Amulet__AG EQU CYREG_PRT12_AG
RX_Amulet__BIE EQU CYREG_PRT12_BIE
RX_Amulet__BIT_MASK EQU CYREG_PRT12_BIT_MASK
RX_Amulet__BYP EQU CYREG_PRT12_BYP
RX_Amulet__DM0 EQU CYREG_PRT12_DM0
RX_Amulet__DM1 EQU CYREG_PRT12_DM1
RX_Amulet__DM2 EQU CYREG_PRT12_DM2
RX_Amulet__DR EQU CYREG_PRT12_DR
RX_Amulet__INP_DIS EQU CYREG_PRT12_INP_DIS
RX_Amulet__MASK EQU 0x04
RX_Amulet__PORT EQU 12
RX_Amulet__PRT EQU CYREG_PRT12_PRT
RX_Amulet__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
RX_Amulet__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
RX_Amulet__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
RX_Amulet__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
RX_Amulet__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
RX_Amulet__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
RX_Amulet__PS EQU CYREG_PRT12_PS
RX_Amulet__SHIFT EQU 2
RX_Amulet__SIO_CFG EQU CYREG_PRT12_SIO_CFG
RX_Amulet__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
RX_Amulet__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
RX_Amulet__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
RX_Amulet__SLW EQU CYREG_PRT12_SLW

; TX_Amulet
TX_Amulet__0__MASK EQU 0x08
TX_Amulet__0__PC EQU CYREG_PRT12_PC3
TX_Amulet__0__PORT EQU 12
TX_Amulet__0__SHIFT EQU 3
TX_Amulet__AG EQU CYREG_PRT12_AG
TX_Amulet__BIE EQU CYREG_PRT12_BIE
TX_Amulet__BIT_MASK EQU CYREG_PRT12_BIT_MASK
TX_Amulet__BYP EQU CYREG_PRT12_BYP
TX_Amulet__DM0 EQU CYREG_PRT12_DM0
TX_Amulet__DM1 EQU CYREG_PRT12_DM1
TX_Amulet__DM2 EQU CYREG_PRT12_DM2
TX_Amulet__DR EQU CYREG_PRT12_DR
TX_Amulet__INP_DIS EQU CYREG_PRT12_INP_DIS
TX_Amulet__MASK EQU 0x08
TX_Amulet__PORT EQU 12
TX_Amulet__PRT EQU CYREG_PRT12_PRT
TX_Amulet__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
TX_Amulet__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
TX_Amulet__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
TX_Amulet__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
TX_Amulet__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
TX_Amulet__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
TX_Amulet__PS EQU CYREG_PRT12_PS
TX_Amulet__SHIFT EQU 3
TX_Amulet__SIO_CFG EQU CYREG_PRT12_SIO_CFG
TX_Amulet__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
TX_Amulet__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
TX_Amulet__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
TX_Amulet__SLW EQU CYREG_PRT12_SLW

; PGA_1_SC
PGA_1_SC__BST EQU CYREG_SC2_BST
PGA_1_SC__CLK EQU CYREG_SC2_CLK
PGA_1_SC__CMPINV EQU CYREG_SC_CMPINV
PGA_1_SC__CPTR EQU CYREG_SC_CPTR
PGA_1_SC__CR0 EQU CYREG_SC2_CR0
PGA_1_SC__CR1 EQU CYREG_SC2_CR1
PGA_1_SC__CR2 EQU CYREG_SC2_CR2
PGA_1_SC__MSK EQU CYREG_SC_MSK
PGA_1_SC__PM_ACT_CFG EQU CYREG_PM_ACT_CFG9
PGA_1_SC__PM_ACT_MSK EQU 0x04
PGA_1_SC__PM_STBY_CFG EQU CYREG_PM_STBY_CFG9
PGA_1_SC__PM_STBY_MSK EQU 0x04
PGA_1_SC__SR EQU CYREG_SC_SR
PGA_1_SC__SW0 EQU CYREG_SC2_SW0
PGA_1_SC__SW10 EQU CYREG_SC2_SW10
PGA_1_SC__SW2 EQU CYREG_SC2_SW2
PGA_1_SC__SW3 EQU CYREG_SC2_SW3
PGA_1_SC__SW4 EQU CYREG_SC2_SW4
PGA_1_SC__SW6 EQU CYREG_SC2_SW6
PGA_1_SC__SW7 EQU CYREG_SC2_SW7
PGA_1_SC__SW8 EQU CYREG_SC2_SW8
PGA_1_SC__WRK1 EQU CYREG_SC_WRK1

; Clock_1
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG2_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG2_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG2_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x02
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x04
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x04

; Clock_2
Clock_2__CFG0 EQU CYREG_CLKDIST_DCFG3_CFG0
Clock_2__CFG1 EQU CYREG_CLKDIST_DCFG3_CFG1
Clock_2__CFG2 EQU CYREG_CLKDIST_DCFG3_CFG2
Clock_2__CFG2_SRC_SEL_MASK EQU 0x07
Clock_2__INDEX EQU 0x03
Clock_2__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_2__PM_ACT_MSK EQU 0x08
Clock_2__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_2__PM_STBY_MSK EQU 0x08

; FFT_ISR
FFT_ISR__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
FFT_ISR__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
FFT_ISR__INTC_MASK EQU 0x02
FFT_ISR__INTC_NUMBER EQU 1
FFT_ISR__INTC_PRIOR_NUM EQU 7
FFT_ISR__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
FFT_ISR__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
FFT_ISR__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; ADC_In
ADC_In__0__MASK EQU 0x02
ADC_In__0__PC EQU CYREG_PRT0_PC1
ADC_In__0__PORT EQU 0
ADC_In__0__SHIFT EQU 1
ADC_In__AG EQU CYREG_PRT0_AG
ADC_In__AMUX EQU CYREG_PRT0_AMUX
ADC_In__BIE EQU CYREG_PRT0_BIE
ADC_In__BIT_MASK EQU CYREG_PRT0_BIT_MASK
ADC_In__BYP EQU CYREG_PRT0_BYP
ADC_In__CTL EQU CYREG_PRT0_CTL
ADC_In__DM0 EQU CYREG_PRT0_DM0
ADC_In__DM1 EQU CYREG_PRT0_DM1
ADC_In__DM2 EQU CYREG_PRT0_DM2
ADC_In__DR EQU CYREG_PRT0_DR
ADC_In__INP_DIS EQU CYREG_PRT0_INP_DIS
ADC_In__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
ADC_In__LCD_EN EQU CYREG_PRT0_LCD_EN
ADC_In__MASK EQU 0x02
ADC_In__PORT EQU 0
ADC_In__PRT EQU CYREG_PRT0_PRT
ADC_In__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
ADC_In__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
ADC_In__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
ADC_In__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
ADC_In__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
ADC_In__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
ADC_In__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
ADC_In__PS EQU CYREG_PRT0_PS
ADC_In__SHIFT EQU 1
ADC_In__SLW EQU CYREG_PRT0_SLW

; rx_int
rx_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
rx_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
rx_int__INTC_MASK EQU 0x08
rx_int__INTC_NUMBER EQU 3
rx_int__INTC_PRIOR_NUM EQU 7
rx_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_3
rx_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
rx_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; tx_int
tx_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
tx_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
tx_int__INTC_MASK EQU 0x20
tx_int__INTC_NUMBER EQU 5
tx_int__INTC_PRIOR_NUM EQU 7
tx_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_5
tx_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
tx_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; RX
RX__0__MASK EQU 0x01
RX__0__PC EQU CYREG_PRT6_PC0
RX__0__PORT EQU 6
RX__0__SHIFT EQU 0
RX__AG EQU CYREG_PRT6_AG
RX__AMUX EQU CYREG_PRT6_AMUX
RX__BIE EQU CYREG_PRT6_BIE
RX__BIT_MASK EQU CYREG_PRT6_BIT_MASK
RX__BYP EQU CYREG_PRT6_BYP
RX__CTL EQU CYREG_PRT6_CTL
RX__DM0 EQU CYREG_PRT6_DM0
RX__DM1 EQU CYREG_PRT6_DM1
RX__DM2 EQU CYREG_PRT6_DM2
RX__DR EQU CYREG_PRT6_DR
RX__INP_DIS EQU CYREG_PRT6_INP_DIS
RX__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
RX__LCD_EN EQU CYREG_PRT6_LCD_EN
RX__MASK EQU 0x01
RX__PORT EQU 6
RX__PRT EQU CYREG_PRT6_PRT
RX__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
RX__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
RX__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
RX__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
RX__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
RX__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
RX__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
RX__PS EQU CYREG_PRT6_PS
RX__SHIFT EQU 0
RX__SLW EQU CYREG_PRT6_SLW

; TX
TX__0__MASK EQU 0x40
TX__0__PC EQU CYREG_PRT6_PC6
TX__0__PORT EQU 6
TX__0__SHIFT EQU 6
TX__AG EQU CYREG_PRT6_AG
TX__AMUX EQU CYREG_PRT6_AMUX
TX__BIE EQU CYREG_PRT6_BIE
TX__BIT_MASK EQU CYREG_PRT6_BIT_MASK
TX__BYP EQU CYREG_PRT6_BYP
TX__CTL EQU CYREG_PRT6_CTL
TX__DM0 EQU CYREG_PRT6_DM0
TX__DM1 EQU CYREG_PRT6_DM1
TX__DM2 EQU CYREG_PRT6_DM2
TX__DR EQU CYREG_PRT6_DR
TX__INP_DIS EQU CYREG_PRT6_INP_DIS
TX__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
TX__LCD_EN EQU CYREG_PRT6_LCD_EN
TX__MASK EQU 0x40
TX__PORT EQU 6
TX__PRT EQU CYREG_PRT6_PRT
TX__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
TX__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
TX__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
TX__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
TX__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
TX__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
TX__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
TX__PS EQU CYREG_PRT6_PS
TX__SHIFT EQU 6
TX__SLW EQU CYREG_PRT6_SLW

; Miscellaneous
; -- WARNING: define names containing LEOPARD or PANTHER are deprecated and will be removed in a future release
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_MEMBER_5B EQU 3
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_DIE_PSOC5LP EQU 3
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_DIE_PSOC5LP
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E123069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_5A EQU 2
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REV_PSOC5LP_PRODUCTION
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC5LP_ES EQU 0
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_CONFIG_FORCE_ROUTE EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_REQXRES EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x1000
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x4000
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0 EQU 5
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1 EQU 5
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2 EQU 5
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3 EQU 5
CYDEV_VIO3_MV EQU 5000
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END
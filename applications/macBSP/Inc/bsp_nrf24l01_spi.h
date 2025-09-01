/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-29     Administrator       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_BSP_NRF24L01_SPI_H_
#define APPLICATIONS_MACBSP_INC_BSP_NRF24L01_SPI_H_
#include "bsp_sys.h"

#define USE_CUSTOMER_NRF24L01 0
#if USE_CUSTOMER_NRF24L01

extern struct rt_spi_device *spi_dev_nrf24;

/* 片选引脚 -- CS */
#define     nRF24_CS_PORT     nRF24_CE_GPIO_Port
#define     nRF24_CS_PIN      nRF24_CE_Pin

#define     nRF24_CS_SET(bit) if(bit) \
                              HAL_GPIO_WritePin ( nRF24_CS_PORT, nRF24_CS_PIN , GPIO_PIN_SET )\
                              else \
                              HAL_GPIO_WritePin ( nRF24_CS_PORT, nRF24_CS_PIN , GPIO_PIN_RESET )


/* SPI引脚 -- NSS */
#define     nRF24_NSS_PORT     nRF24_CSN_GPIO_Port
#define     nRF24_NSS_PIN      nRF24_CSN_Pin

#define     nRF24_NSS_SET(bit) if(bit) \
                               HAL_GPIO_WritePin ( nRF24_NSS_PORT, nRF24_NSS_PIN , GPIO_PIN_SET )\
                               else \
                               HAL_GPIO_WritePin ( nRF24_NSS_PORT, nRF24_NSS_PIN , GPIO_PIN_RESET )



//---------spi函数声明-------------------



#endif

#endif /* APPLICATIONS_MACBSP_INC_BSP_NRF24L01_SPI_H_ */

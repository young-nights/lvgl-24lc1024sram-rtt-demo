/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-29     Administrator       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_BSP_LORA_SPI_H_
#define APPLICATIONS_MACBSP_INC_BSP_LORA_SPI_H_
#include "bsp_sys.h"



extern struct rt_spi_device *spi_dev_lora;

/* 片选引脚 -- CS */
#define     LORA_CS_PORT     LORA_CE_GPIO_Port
#define     LORA_CS_PIN      LORA_CE_Pin

#define     LORA_CS_SET(bit) if(bit) \
                            HAL_GPIO_WritePin ( LORA_CS_PORT, LORA_CS_PIN , GPIO_PIN_SET )\
                            else \
                            HAL_GPIO_WritePin ( LORA_CS_PORT, LORA_CS_PIN , GPIO_PIN_RESET )


/* SPI引脚 -- NSS */
#define     LORA_CSN_PORT     LORA_NSS_GPIO_Port
#define     LORA_CSN_PIN      LORA_NSS_Pin

#define     LORA_CSN_SET(bit) if(bit) \
                            HAL_GPIO_WritePin ( LORA_CSN_PORT, LORA_CSN_PIN , GPIO_PIN_SET )\
                            else \
                            HAL_GPIO_WritePin ( LORA_CSN_PORT, LORA_CSN_PIN , GPIO_PIN_RESET )



//---------spi函数声明-------------------



#endif /* APPLICATIONS_MACBSP_INC_BSP_LORA_SPI_H_ */

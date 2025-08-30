/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-29     Administrator       the first version
 */
#include "bsp_lora_spi.h"


#if USE_CUSTOMER_NRF24L01

//以下是SPI以及LORA引脚配置相关的函数---------------------------------------------------------------------------------------------

/* 宏定义SPI名称 */
#define     LORA_SPI_NAME    "lora_spi3"
/* 宏定义SPI总线 */
#define     LORA_SPI_BUS     "spi3"
/* 宏定义SPI句柄 */
struct rt_spi_device *spi_dev_lora;



/**
  * @brief  SPI Initialization
  * @retval void
  */
void lora_spi_init(void)
{
    /* 将SPI设备名挂载到总线 */
    rt_hw_spi_device_attach(LORA_SPI_BUS, LORA_SPI_NAME, LORA_CSN_PORT, LORA_CSN_PIN);
    /* 查找SPI设备 */
    spi_dev_lora = (struct rt_spi_device *)rt_device_find(LORA_SPI_NAME);
    if(spi_dev_lora == NULL){
        rt_kprintf("lora spi device is not created!\r\n");
    }
    else{
        rt_kprintf("lora spi device is successfully!\r\n");
    }
    /***
     *! 配置SPI结构体参数
     *! data_width: spi传输数据长度为8bits
     *! max_hz: spi的最大工作频率；
     *! mode-> RT_SPI_MASTER: 主机模式；
     *! mode-> RT_SPI_MODE_0: 工作模式0（ CPOL:0 -- 空闲状态为低电平 ， CPHA:0 -- 第一个边沿采集数据 ）
     *! mode-> RT_SPI_MSB: 通讯数据高位在前低位在后
     * */
    struct rt_spi_configuration spi3_cfg;
    spi3_cfg.data_width = 8;
    spi3_cfg.max_hz = 10*1000*1000; /* 10M,SPI max 10MHz,lora 4-wire spi */
    spi3_cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
    rt_spi_configure(spi_dev_lora, &spi3_cfg); /* 使能参数 */
}


#endif










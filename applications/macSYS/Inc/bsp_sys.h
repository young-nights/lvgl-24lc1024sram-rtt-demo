/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-05-15     teati       the first version
 */
#ifndef APPLICATIONS_MACSYS_INC_BSP_SYS_H_

#define APPLICATIONS_MACSYS_INC_BSP_SYS_H_

/* RTT实时操作系统的头文件 */
#include <rtthread.h>
#include <drv_common.h>
#include <board.h>
#include <rtdevice.h>
#include <rthw.h>
#include <drv_spi.h>
#include <rtdbg.h>
#include <ulog.h>
/* 该头文件包含了所有CubeMX自动生成的初始化引脚 */
#include "main.h"
/* macAPP 头文件 */
#include "rtt_hwtimer_state_machine.h"
#include "rtt_system_work.h"
/* macBSP 头文件 */
#include "bsp_battery.h"
#include "bsp_key.h"
#include "bsp_led.h"
#include <bsp_nrf24l01_driver.h>
#include <bsp_nrf24l01_spi.h>
#include "ft6336u_driver.h"
#include "ft6336u_iic.h"
#include "lcd_driver.h"
#include "lcd_driver.h"
#include "st7789_driver.h"
#include "st7789_spi.h"
/* macGUI 路径下头文件 */
// --lvgl_demos
#include "basic_widgets.h"
#include "lvgl_examples.h"
// --lvgl_fonts
// --lvgl_gui
#include "lvgl_events.h"
#include "lvgl_gui.h"
#include "lvgl_screen.h"
// --porting
#include "lv_port_disp.h"
#include "lv_port_indev.h"
/* macSYS 头文件 */
#include "bsp_typedef.h"
#include "internal_rtc.h"
#include "macLOG.h"
// 这个宏用于使能lv_printf.c文件中的lv_snprintf()函数
#define USE_LV_SNPRINTF     0




#endif /* APPLICATIONS_MACSYS_INC_BSP_SYS_H_ */

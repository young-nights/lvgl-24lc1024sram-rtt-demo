/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-07     18452       the first version
 */
#include "bsp_sys.h"



/**
  * @brief  This thread entry is used for touch check
  * @retval void
  */
void GUI_Thread_entry(void* parameter)
{
    lv_init();

    lv_port_disp_init();
    lv_port_indev_init();
    lv_user_gui_init();

    for(;;)
    {
        rt_thread_mdelay(10);
        lv_task_handler();
    }
}



/**
  * @brief  This is a Initialization for water level Check
  * @retval int
  */
rt_thread_t GUI_Task_Handle = RT_NULL;
int GUI_Thread_Init(void)
{
    GUI_Task_Handle = rt_thread_create("GUI_Thread_entry", GUI_Thread_entry, RT_NULL, 4096, 5, 300);
    /* 检查是否创建成功,成功就启动线程 */
    if(GUI_Task_Handle != RT_NULL)
    {
        rt_kprintf("PRINTF:%d. GUI_Thread_entry is Succeed!! \r\n",Record.kprintf_cnt++);
        rt_thread_startup(GUI_Task_Handle);
    }
    else {
        rt_kprintf("PRINTF:%d. GUI_Thread_entry is Failed \r\n",Record.kprintf_cnt++);
    }

    return RT_EOK;
}
//INIT_APP_EXPORT(GUI_Thread_Init);






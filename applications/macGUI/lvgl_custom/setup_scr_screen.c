/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-29     18452       the first version
 */
#include "bsp_sys.h"

lvgl_ui_t guider_lvgl;

void setup_src_screen(lvgl_ui_t *ui)
{
    //Write codes screen
    ui->screen_main = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_main, 240, 320);
    lv_obj_set_scrollbar_mode(ui->screen_main,LV_SCROLLBAR_MODE_OFF);



}





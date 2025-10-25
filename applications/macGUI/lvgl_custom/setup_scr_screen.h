/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-29     18452       the first version
 */
#ifndef APPLICATIONS_MACGUI_LVGL_CUSTOM_SETUP_SCR_SCREEN_H_
#define APPLICATIONS_MACGUI_CUSTOM_SETUP_SCR_SCREEN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "bsp_sys.h"


typedef struct
{

    lv_obj_t *screen_main;
    bool screen_del;
    lv_obj_t *screen_cont_1;
    lv_obj_t *screen_start_btn;
    lv_obj_t *screen_start_btn_label;
    lv_obj_t *screen_main_title_lab;
}lvgl_ui_t;
extern lvgl_ui_t guider_lvgl;


void setup_src_screen(lvgl_ui_t *ui);

#ifdef __cplusplus
}
#endif


#endif /* APPLICATIONS_MACGUI_LVGL_CUSTOM_SETUP_SCR_SCREEN_H_ */

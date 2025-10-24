/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-06-29     Administrator       the first version
 */
#ifndef APPLICATIONS_MACGUI_LVGL_GUI_LVGL_DEMOS_H_
#define APPLICATIONS_MACGUI_LVGL_GUI_LVGL_DEMOS_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "bsp_sys.h"
#include "lvgl.h"


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


void lv_user_gui_init(void);


#ifdef __cplusplus
}
#endif

#endif /* APPLICATIONS_MACGUI_LVGL_GUI_LVGL_DEMOS_H_s */

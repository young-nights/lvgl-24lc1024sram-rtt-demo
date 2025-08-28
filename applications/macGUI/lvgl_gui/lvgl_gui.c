/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-06-29     Administrator       the first version
 */
#include <macGUI/lvgl_gui/lvgl_gui.h>

lv_ui gui_guider_lvgl;

void lv_user_gui_init(void)
{

#define USE_GUI_GUIDER 0
#if USE_GUI_GUIDER
    extern void setup_ui(lv_ui *ui);
    setup_ui(&gui_guider_lvgl);
    events_init(&gui_guider_lvgl);
#endif


    draw_basic_button();
}




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






void lv_user_gui_init(void)
{

#if USE_LVGL_TEST_BUTTON
    lv_example_get_started_1();
#endif

    setup_src_screen(&guider_lvgl);


}




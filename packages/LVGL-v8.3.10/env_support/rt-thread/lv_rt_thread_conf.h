/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-15     Meco Man     The first version
 */

#ifndef LV_RT_THREAD_CONF_H
#define LV_RT_THREAD_CONF_H

#ifdef __RTTHREAD__

#define LV_RTTHREAD_INCLUDE <rtthread.h>
#include LV_RTTHREAD_INCLUDE

/* music player demo */
#include <rtconfig.h>



/*====================
   COLOR SETTINGS
 *====================*/

/*Color depth: 1 (1 byte per pixel), 8 (RGB332), 16 (RGB565), 32 (ARGB8888)*/
#define LV_COLOR_DEPTH 16

/*Swap the 2 bytes of RGB565 color. Useful if the display has an 8-bit interface (e.g. SPI)*/
#define LV_COLOR_16_SWAP 1

/*Enable features to draw on transparent background.
 *It's required if opa, and transform_* style properties are used.
 *Can be also used if the UI is above another layer, e.g. an OSD menu or video player.*/
#define LV_COLOR_SCREEN_TRANSP 0

/* Adjust color mix functions rounding. GPUs might calculate color mix (blending ) differently.
 * 0: round down, 64: round up from x.75, 128: round up from half, 192: round up from x.25, 254: round up */
#define LV_COLOR_MIX_ROUND_OFS 0

/*Images pixels with this color will not be drawn if they are chroma keyed)*/
#define LV_COLOR_CHROMA_KEY lv_color_hex(0x00ff00)         /*pure green*/


/*-------------
 * Drawing
 *-----------*/

/*Enable complex draw engine.（是否启用复杂绘制引擎）
 *Required to draw shadow, gradient, rounded corners, circles, arc, skew lines, image transformations or any masks*/
#define LV_DRAW_COMPLEX 1
#if LV_DRAW_COMPLEX != 0

    /*Allow buffering some shadow calculation.
    *LV_SHADOW_CACHE_SIZE is the max. shadow size to buffer, where shadow size is `shadow_width + radius`
    *Caching has LV_SHADOW_CACHE_SIZE^2 RAM cost*/
    // 完全关闭阴影缓存，每次实时计算，CPU 负担大但 RAM 零额外开销
    #define LV_SHADOW_CACHE_SIZE 0

    /* Set number of maximally cached circle data.
    * The circumference of 1/4 circle are saved for anti-aliasing
    * radius * 4 bytes are used per circle (the most often used radiuses are saved)
    * 0: to disable caching */
    #define LV_CIRCLE_CACHE_SIZE 4
#endif /*LV_DRAW_COMPLEX*/


/*=========================
   MEMORY SETTINGS
 *=========================*/

#ifdef RT_USING_HEAP
#  define LV_MEM_CUSTOM 1
#  define LV_MEM_CUSTOM_INCLUDE LV_RTTHREAD_INCLUDE
#  define LV_MEM_CUSTOM_ALLOC   rt_malloc
#  define LV_MEM_CUSTOM_FREE    rt_free
#  define LV_MEM_CUSTOM_REALLOC rt_realloc
#endif

/*====================
   HAL SETTINGS
 *====================*/

#define LV_TICK_CUSTOM 1
#define LV_TICK_CUSTOM_INCLUDE LV_RTTHREAD_INCLUDE
#define LV_TICK_CUSTOM_SYS_TIME_EXPR (rt_tick_get_millisecond())    /*Expression evaluating to current system time in ms*/

#ifdef PKG_LVGL_DISP_REFR_PERIOD
#define LV_DISP_DEF_REFR_PERIOD   PKG_LVGL_DISP_REFR_PERIOD
#endif

/*=======================
 * FEATURE CONFIGURATION
 *=======================*/

/*-------------
 * Asserts
 *-----------*/

#define LV_ASSERT_HANDLER_INCLUDE LV_RTTHREAD_INCLUDE
#define LV_ASSERT_HANDLER RT_ASSERT(0);

/*-------------
 * Others
 *-----------*/

#define LV_SPRINTF_CUSTOM 1
#define LV_SPRINTF_INCLUDE LV_RTTHREAD_INCLUDE
#define lv_snprintf  rt_snprintf
#define lv_vsnprintf rt_vsnprintf
#define LV_SPRINTF_USE_FLOAT 0

/*=====================
 *  COMPILER SETTINGS
 *====================*/

#ifdef ARCH_CPU_BIG_ENDIAN
#  define LV_BIG_ENDIAN_SYSTEM 1
#else
#  define LV_BIG_ENDIAN_SYSTEM 0
#endif

#ifdef rt_align /* >= RT-Thread v5.0.0 */
#  define LV_ATTRIBUTE_MEM_ALIGN rt_align(RT_ALIGN_SIZE)
#else
#  define LV_ATTRIBUTE_MEM_ALIGN ALIGN(RT_ALIGN_SIZE)
#endif

/*==================
* EXAMPLES
*==================*/

#ifdef PKG_LVGL_USING_EXAMPLES
#  define LV_BUILD_EXAMPLES 1
#endif


/*Music player demo*/
#define LV_USE_DEMO_RTT_MUSIC 0
#if LV_USE_DEMO_RTT_MUSIC
#define LV_HOR_RES_MAX              240
#define LV_VER_RES_MAX              320
#define LV_DEMO_RTT_MUSIC_AUTO_PLAY 1
#define LV_FONT_MONTSERRAT_12       1
#define LV_FONT_MONTSERRAT_16       1
#endif

/*--END OF LV_RT_THREAD_CONF_H--*/

#endif /*__RTTHREAD__*/

#endif /*LV_CONF_H*/

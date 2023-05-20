//
// Created by yaniss on 5/8/23.
//

#ifndef LV_SPECTRUM_UI_H
#define LV_SPECTRUM_UI_H

#include <lvgl/lvgl.h>

void ui_init();
void ui_draw(lv_obj_t * parent);
void ui_update_chart(float *buff, uint16_t size);
#endif //LV_SPECTRUM_UI_H

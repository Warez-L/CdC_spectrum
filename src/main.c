//
// Created by yaniss on 5/8/23.
//

#include <stdio.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#include <lv_drivers/sdl/sdl.h>

#include <lvgl/lvgl.h>

#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"

#include "../include/ui_init.h"

uint8_t run = 1;
uint8_t run2 = 1;

static lv_disp_t *disp;

void start_systick_routine(void);
static void * systick_routine(void * arg);

int main(){

    lv_init();

    ui_init();

    lv_demo_widgets();

    start_systick_routine();

    while(run) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        usleep(1 * 1000);
        lv_task_handler();
    }

    return 0;
}

void start_systick_routine(void){
    //start the thread
    SDL_CreateThread((SDL_ThreadFunction) systick_routine, NULL,  NULL);
}

static void * systick_routine(void * arg){
    while(run2) {
        usleep(5 * 1000);
        lv_tick_inc(5);
    }
}

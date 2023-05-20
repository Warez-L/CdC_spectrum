//
// Created by yaniss on 5/8/23.
//

#include <stdio.h>
#include <unistd.h>

#include <math.h>
#include <time.h>

#include "../include/main.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#include <lvgl/lvgl.h>
#include "lvgl/demos/lv_demos.h"
#include "../include/ui.h"

#include "kissfft/kiss_fftr.h"

static lv_disp_t *disp;

void start_systick_routine(void);
static void * systick_routine(void * arg);
void start_task_handler_routine(void);
static void * task_handler_routine(void * arg);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide the file path as a command line argument.\n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "rb");  // Open wave file specified in the command line argument

    if (infile == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    uint16_t BUFSIZE = 256;                  // BUFSIZE can be changed according to the frame size required (eg:512)
    uint64_t count = 0;                      // For counting number of frames in wave file.
    uint16_t buff16[256];              // short int used for 16 bit as input data format is 16 bit PCM audio
    header_p meta = (header_p)malloc(sizeof(header));   // header_p points to a header struct that contains the wave file metadata fields
    uint16_t nb;                         // variable storing number of bytes returned

    float oneFrame[256] = {0};

    kiss_fftr_cfg cfg = kiss_fftr_alloc(256, 0, NULL, NULL);

    kiss_fft_cpx cx_out[256/2+1];

    lv_init();

    ui_init();

    start_systick_routine();

    ui_draw(lv_scr_act());

    start_task_handler_routine();

    if (!infile)return 0;

    clock_t start_time = clock();

    fread(meta, 1, sizeof(header), infile);
    while ((nb = fread(buff16,1,BUFSIZE,infile))>0)
    {
        start_time = clock();
        // Reading data in chunks of BUFSIZE
        //cout << nb <<endl;
        count++;
        // Incrementing > of frame
        for (uint16_t i = 0; i < nb - 1; i += 2) // Incrementing by 2 since we are reading 16-bit samples
        {
            // Convert the 16 bit samples to double
            int16_t sample = (buff16[i] << 8) | buff16[i + 1];
            oneFrame[i / 2] = (float)sample / 32768.0f;
        }

        kiss_fftr(cfg, oneFrame, cx_out);

        ui_update_chart(cx_out, 256/2+1);

        clock_t elapsed_time = clock() - start_time;

        if (elapsed_time < CLOCKS_PER_SEC / 20) {
            usleep((CLOCKS_PER_SEC / 20) - elapsed_time); // Subtract elapsed time from desired duration
        }

    }


    kiss_fft_free(cfg);
    fclose(infile);

    return 0;
}

void start_systick_routine(void){
    //start the thread
    SDL_CreateThread((SDL_ThreadFunction) systick_routine, NULL,  NULL);
}

static void * systick_routine(void * arg){
    while(1) {
        usleep(5 * 1000);
        lv_tick_inc(5);
    }
}


void start_task_handler_routine(void){
    //start the thread
    SDL_CreateThread((SDL_ThreadFunction) task_handler_routine, NULL,  NULL);
}

static void * task_handler_routine(void * arg){
    while(1) {
        usleep(lv_task_handler());
    }
}

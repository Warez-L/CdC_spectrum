//
// Created by yaniss on 5/8/23.
//

#ifndef LV_SPECTRUM_MAIN_H
#define LV_SPECTRUM_MAIN_H

typedef struct header_file
{
    char chunk_id[4];
    int chunk_size;
    char format[4];
    char subchunk1_id[4];
    int subchunk1_size;
    short int audio_format;
    short int num_channels;
    int sample_rate;            // sample_rate denotes the sampling rate.
    int byte_rate;
    short int block_align;
    short int bits_per_sample;
    char subchunk2_id[4];
    int subchunk2_size; // subchunk2_size denotes the number of samples.
    //char data; // actual data : Added by tarmizi
} header;

typedef struct header_file* header_p;



#endif //LV_SPECTRUM_MAIN_H

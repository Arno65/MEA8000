/*

    MEA8000_Sounds.cpp

    This is a dataset of MEA8000 sounds, the ones I know.
    It's mainly a collection of data from French BASIC programs and French datasets. 
    This data was copied and OCR-ed from scanned prints from the 1980s.
    
    The code in this file is for Arduino projects. Via <avr/pgmspace.h> the data will not
    be copied to the microcontrollers RAM and is accessible from Flash memory.
    The first part of the dataset has data in hexadecimal format (base-16).
    Catalog 2 and 3 have data in decimal format (base-10).

    (I asume that if you need this data in another programming language (or environment) it will
    be easy to reformat the code.)

    Info on the Philips MEA8000 voice synthesizer chip:  
    http://c.papy.free.fr/ZX81/original/mea8000-1.pdf


    version 0.1     (2021-07-07)        First collected set - based on the sets in my previous code  
    version 1.0     (2021-07-16)        All OCR-ed docs - Some of catalog 1 and all of catalog 2 and 3.  
                                        OCR data tested with check sums and manually edited

    (cl) 2014, 2021 by Arno Jacobs
        

    Some info on the MEA8000 chip:
  
        31-30 BW1  2bit Bandwidth of 1st formant (726,309,125,50 Hz)
        29-28 BW2  2bit Bandwidth of 2nd formant (726,309,125,50 Hz)
        27-26 BW3  2bit Bandwidth of 3rd formant (726,309,125,50 Hz)
        25-24 BW4  2bit Bandwidth of 4th formant (726,309,125,50 Hz)
        N/A   FM4  0bit Resonance Frequency of 4th formant (3500 Hz) (fixed)
        23-21 FM3  3bit Resonance Frequency of 3rd formant (1179..3400 Hz)
        20-16 FM2  5bit Resonance Frequency of 2nd formant (440..3400 Hz)
        15-11 FM1  5bit Resonance Frequency of 1st formant (150..1047 Hz)
        10-7  AMPL 4bit Amplitude (volume) (0.000 .. 1.000) (nonlinear)
        6-5   FD   2bit Frame Duration (8,16,32,64 ms)
        4-0   PI   5bit Pitch Increment (signed, -15..+15 Hz per 8ms) (or -16=Noise)
        
        Val FD(ms) P(Hz) PI(Hz/8ms) Ampl. FM1(Hz) FM2(Hz) FM3(Hz) FM4(Hz) BW(Hz)
        0   8      0     0          0.000 150     440     1179    3500    726
        1   16     2     +1         0.008 162     466     1337    -       309
        2   32     4     +2         0.011 174     494     1528    -       125
        3   64     6     +3         0.016 188     523     1761    -       50
        4   -      8     +4         0.022 202     554     2047    -       -
        5   -      10    +5         0.031 217     587     2400    -       -
        6   -      12    +6         0.044 233     622     2842    -       -
        7   -      14    +7         0.062 250     659     3400    -       -
        8   -      16    +8         0.088 267     698     -       -       -
        9   -      18    +9         0.125 286     740     -       -       -
        10  -      20    +10        0.177 305     784     -       -       -
        11  -      22    +11        0.250 325     830     -       -       -
        12  -      24    +12        0.354 346     880     -       -       -
        13  -      26    +13        0.500 368     932     -       -       -
        14  -      28    +14        0.707 391     988     -       -       -
        15  -      30    +15        1.000 415     1047    -       -       -
        16  -      32    Noise      -     440     1100    -       -       -
        17  -      34    -15        -     466     1179    -       -       -
        18  -      36    -14        -     494     1254    -       -       -
        19  -      38    -13        -     523     1337    -       -       -
        20  -      40    -12        -     554     1428    -       -       -
        21  -      42    -11        -     587     1528    -       -       -
        22  -      44    -10        -     622     1639    -       -       -
        23  -      46    -9         -     659     1761    -       -       -
        24  -      48    -8         -     698     1897    -       -       -
        25  -      50    -7         -     740     2047    -       -       -
        26  -      52    -6         -     784     2214    -       -       -
        27  -      54    -5         -     830     2400    -       -       -
        28  -      56    -4         -     880     2609    -       -       -
        29  -      58    -3         -     932     2842    -       -       -
        30  -      60    -2         -     988     3105    -       -       -
        31  -      62    -1         -     1047    3400    -       -       -
        ... -      ...   -          -     -       -       -       -       -
        255 -      510   -          -     -       -       -       -       -
    
 */


// Keep ALL sound data in the program Flash memory space, do not copy all to SRAM.
//
#include <avr/pgmspace.h>


// = Most sounds based on French phonemes  =============================================================================================  

const byte NoSound [8] PROGMEM = { 0xAB, 0xB3, 0x80, 0x20, 0xAB, 0xB3, 0x80, 0x20 };

// Phonemes

const byte Sound_a  [32] PROGMEM = { 0x86, 0xB3, 0xCD, 0xA0, 0x86, 0xB3, 0xCD, 0xA0, 0x86, 0xB2, 0xD6, 0xA0, 0x86, 0xB2, 0xD6, 0xA0,
                                     0x96, 0xB2, 0xCE, 0xA0, 0x96, 0xB2, 0xCE, 0xA0, 0x97, 0xB1, 0xCD, 0xA0, 0x97, 0xB1, 0xCD, 0xA0 }; 

const byte Sound_e  [32] PROGMEM = { 0xAF, 0xB3, 0x85, 0x20, 0xAF, 0xB3, 0x85, 0x20, 0xAB, 0xB3, 0x7E, 0x20, 0xAB, 0xB3, 0x7E, 0x20,
                                     0xAB, 0xB3, 0x86, 0x20, 0xAB, 0xB3, 0x86, 0x20, 0xFF, 0xB3, 0x85, 0x20, 0xFF, 0xB3, 0x85, 0x20 };

const byte Sound_i  [32] PROGMEM = { 0xAF, 0xDA, 0x5D, 0x20, 0xAF, 0xDA, 0x5D, 0x20, 0xAF, 0xDA, 0x5E, 0x20, 0xAF, 0xDA, 0x5E, 0x20,
                                     0xAF, 0xDA, 0x66, 0x20, 0xAF, 0xDA, 0x66, 0x20, 0xAF, 0xDA, 0x65, 0x20, 0xAF, 0xDA, 0x65, 0x20 };  

const byte Sound_oo [32] PROGMEM = { 0xC7, 0xAC, 0x84, 0xA0, 0xC7, 0xAC, 0x84, 0xA0, 0xC6, 0xAB, 0x85, 0x20, 0xC6, 0xAB, 0x85, 0x20,
                                     0xC6, 0xAB, 0x85, 0x20, 0xC6, 0xAB, 0x85, 0x20, 0xD6, 0xAB, 0x84, 0xA0, 0xD6, 0xAB, 0x84, 0xA0 };

const byte Sound_u  [32] PROGMEM = { 0xB7, 0xB7, 0x5D, 0x20, 0xB7, 0xB7, 0x5D, 0x20, 0xB7, 0xB7, 0x66, 0xA0, 0xB7, 0xB7, 0x66, 0xA0,
                                     0xB7, 0xB7, 0x66, 0xA0, 0xB7, 0xB7, 0x66, 0xA0, 0xB7, 0xB7, 0x5D, 0x20, 0xB7, 0xB7, 0x5D, 0x20 };

const byte Sound_eh [32] PROGMEM = { 0xA6, 0xB6, 0xB5, 0x20, 0xA6, 0xB6, 0xB5, 0x20, 0xB6, 0xB6, 0xBF, 0x20, 0xB6, 0xB6, 0xBF, 0x20,
                                     0xB6, 0xB6, 0xB7, 0x20, 0xB6, 0xB6, 0xB7, 0x20, 0xFA, 0xB7, 0xA5, 0x20, 0xFA, 0xB7, 0xA5, 0x20 }; 

const byte Sound_ee [32] PROGMEM = { 0xBB, 0xB8, 0x85, 0xA0, 0xBB, 0xB8, 0x85, 0xA0, 0xBB, 0xB8, 0x87, 0x20, 0xBB, 0xB8, 0x87, 0x20,
                                     0xBB, 0xB8, 0x87, 0x20, 0xBB, 0xB8, 0x87, 0x20, 0xFB, 0xB8, 0x85, 0xA0, 0xFB, 0xB8, 0x85, 0xA0 };

const byte Sound_oh [32] PROGMEM = { 0x52, 0xCA, 0xBD, 0x20, 0x52, 0xCA, 0xBD, 0x20, 0x97, 0xCA, 0xBD, 0xA0, 0x97, 0xCA, 0xBD, 0xA0,
                                     0x97, 0xCA, 0xBD, 0xA0, 0x97, 0xCA, 0xBD, 0xA0, 0x83, 0xCA, 0xBD, 0x20, 0x83, 0xCA, 0xBD, 0x20 }; 

const byte Sound_w  [32] PROGMEM = { 0x66, 0xB4, 0xBD, 0xA0, 0x66, 0xB4, 0xBD, 0xA0, 0x66, 0xB5, 0xBF, 0x20, 0x66, 0xB5, 0xBF, 0x20,
                                     0x65, 0xB5, 0xC7, 0x20, 0x65, 0xB5, 0xC7, 0x20, 0x61, 0xB5, 0xD5, 0xA0, 0x61, 0xB5, 0xD5, 0xA0 };  

const byte Sound_A  [32] PROGMEM = { 0x82, 0xD1, 0xA5, 0x20, 0x82, 0xD1, 0xA5, 0xA0, 0x83, 0xCD, 0xAE, 0xA0, 0xC3, 0xCE, 0xAE, 0xA0,
                                     0xC3, 0xD1, 0x9E, 0xA0, 0xD2, 0xD3, 0x96, 0x20, 0x92, 0xD2, 0x95, 0x20, 0x92, 0xD2, 0x95, 0x20 };

const byte Sound_I  [56] PROGMEM = { 0x5A, 0x84, 0x9C, 0x20, 0x5A, 0x84, 0x9C, 0x20, 0x5A, 0x84, 0x9D, 0x20, 0x5A, 0x84, 0x9D, 0x20,
                                     0x5A, 0x8A, 0xB6, 0xA0, 0x5A, 0x8A, 0xB6, 0xA0, 0x87, 0xAD, 0xC6, 0xA0, 0x87, 0xAD, 0xC6, 0xA0,
                                     0x47, 0xB1, 0xCE, 0xA0, 0x47, 0xB1, 0xCE, 0xA0, 0x97, 0xB2, 0xC6, 0x20, 0x97, 0xB2, 0xC6, 0x20,
                                     0x9B, 0xB1, 0xC4, 0x20, 0x9B, 0xB1, 0xC4, 0x20 };

const byte Sound_O  [32] PROGMEM = { 0xD6, 0xB3, 0x6C, 0xA0, 0xD6, 0xB3, 0x6D, 0x20, 0xFA, 0xB4, 0x66, 0x20, 0xFA, 0xB4, 0x66, 0x20,
                                     0xFA, 0xB4, 0x66, 0x20, 0xFA, 0xB4, 0x66, 0x20, 0xF6, 0xB4, 0x65, 0x20, 0xEA, 0xB4, 0x64, 0xA0 };

const byte Sound_W  [32] PROGMEM = { 0x9B, 0xAD, 0x6C, 0xA0, 0x9B, 0xAD, 0x6C, 0xA0, 0xDB, 0xAE, 0x6D, 0x20, 0xDB, 0xAE, 0x6D, 0x20,
                                     0xDB, 0xAE, 0x6D, 0x20, 0xDB, 0xAE, 0x6D, 0x20, 0x9B, 0xAE, 0x6C, 0xA0, 0x9B, 0xAE, 0x6C, 0xA0 };

const byte Sound_b  [24] PROGMEM = { 0x80, 0xD6, 0x18, 0x20, 0x60, 0xD6, 0x1A, 0xA0, 0x90, 0xB2, 0x13, 0xA0, 0xA4, 0xB2, 0x13, 0xA0,
                                     0xA5, 0xB1, 0x24, 0xA0, 0xE1, 0x91, 0x76, 0x20 };

const byte Sound_d  [24] PROGMEM = { 0x80, 0xB5, 0x18, 0x20, 0x80, 0xB5, 0x1B, 0xA0, 0x10, 0xD5, 0x04, 0xA0, 0xA0, 0xD5, 0x0C, 0x20,
                                     0x40, 0xD2, 0x2C, 0xA0, 0x40, 0xD9, 0x5E, 0x20 };

const byte Sound_f  [32] PROGMEM = { 0x16, 0xB7, 0xFD, 0xB0, 0x16, 0xB7, 0xFE, 0x30, 0x16, 0xB7, 0xFE, 0xB0, 0x16, 0xB7, 0xFE, 0xB0,
                                     0x16, 0xB7, 0xFE, 0xB0, 0x16, 0xB7, 0xFE, 0xB0, 0x16, 0xBF, 0xFE, 0x30, 0x16, 0xB7, 0xFD, 0xB0 };

const byte Sound_g  [16] PROGMEM = { 0xFF, 0x97, 0x60, 0x20, 0xFF, 0x97, 0x63, 0xA0, 0xFA, 0x97, 0x66, 0xA0, 0xA6, 0x97, 0x66, 0xA0 };

const byte Sound_j  [20] PROGMEM = { 0x1E, 0xBA, 0x7C, 0x30, 0x1E, 0xBA, 0x7D, 0xA0, 0x1E, 0xBA, 0x76, 0xB0, 0x1E, 0xBA, 0x76, 0xA0,
                                     0x1E, 0xBA, 0x75, 0xB0 };

const byte Sound_k  [16] PROGMEM = { 0x09, 0x97, 0x88, 0x30, 0x0D, 0x97, 0x8F, 0xB0, 0x09, 0x97, 0x8E, 0xB0, 0x67, 0x96, 0x86, 0x20 };

const byte Sound_l  [20] PROGMEM = { 0x74, 0xB5, 0x55, 0x20, 0x74, 0xB5, 0x55, 0x20, 0x74, 0xB6, 0x2E, 0x20, 0x74, 0xB6, 0x2E, 0x20,
                                     0x28, 0xB5, 0x55, 0x20 };

const byte Sound_m  [32] PROGMEM = { 0x4C, 0xB4, 0x5C, 0xA0, 0x4C, 0xB4, 0x5C, 0xA0, 0x4C, 0xB4, 0x5D, 0x20, 0x4C, 0xB4, 0x5D, 0xA0,
                                     0x4A, 0xB4, 0xB4, 0x5E, 0x4A, 0xB4, 0x5E, 0x20, 0x4A, 0xB4, 0x5D, 0xA0, 0x4A, 0xB4, 0x5D, 0x20 };

const byte Sound_n  [16] PROGMEM = { 0x88, 0xB4, 0x55, 0x20, 0x48, 0xB4, 0x5E, 0x20, 0x4C, 0xB4, 0x5F, 0x20, 0x4A, 0xB4, 0x5E, 0x20 };

const byte Sound_p  [20] PROGMEM = { 0xC2, 0xB9, 0x38, 0x30, 0xC2, 0xB9, 0x38, 0x30, 0x11, 0xB6, 0x97, 0xB0, 0x16, 0xB3, 0x8E, 0x30,
                                     0x5B, 0xB2, 0x8D, 0xA0 };

const byte Sound_R  [16] PROGMEM = { 0x3A, 0xB3, 0x84, 0x20, 0x36, 0xB3, 0x8D, 0xA0, 0x79, 0xB2, 0x96, 0x20, 0x97, 0xB1, 0xCD, 0x20 };

const byte Sound_r  [20] PROGMEM = { 0xF5, 0xB0, 0xA4, 0xA0, 0xB5, 0x8F, 0x86, 0x20, 0xB5, 0x8F, 0x83, 0xA0, 0x54, 0xB0, 0x3C, 0xA0,
                                     0x54, 0xB0, 0x3A, 0xA0 };

const byte Sound_s  [28] PROGMEM = { 0x09, 0xF3, 0xBD, 0x30, 0x09, 0xF3, 0xBD, 0x30, 0x09, 0xF3, 0xBD, 0xB0, 0x09, 0xF3, 0x8D, 0xB0,
                                     0x09, 0xF3, 0x8D, 0xB0, 0x09, 0xF3, 0x8D, 0x30, 0x09, 0xF3, 0x8D, 0x30 };

const byte Sound_t  [16] PROGMEM = { 0xB6, 0xF6, 0x90, 0x30, 0xB6, 0xF6, 0x94, 0x30, 0xB6, 0xF6, 0x96, 0x30, 0x9B, 0xB4, 0x8D, 0x10 };

const byte Sound_v  [28] PROGMEM = { 0x6A, 0xB2, 0x84, 0xA0, 0x6A, 0xB2, 0x85, 0x20, 0x6A, 0xB2, 0x86, 0x20, 0x6A, 0xB2, 0x86, 0xA0,
                                     0x6A, 0xB2, 0x86, 0xB0, 0x6A, 0xB2, 0x86, 0xB0, 0x6A, 0xB2, 0x86, 0x30 };

const byte Sound_z  [16] PROGMEM = { 0x12, 0xF5, 0x76, 0x20, 0x12, 0xF5, 0x76, 0xA0, 0x12, 0xF5, 0x77, 0x30, 0xAA, 0xB4, 0x76, 0xA0 };

const byte Sound_ch [28] PROGMEM = { 0x29, 0xBA, 0x8E, 0x30, 0x29, 0xBA, 0x8E, 0xB0, 0x29, 0xBA, 0x8E, 0xB0, 0x29, 0xBA, 0x8E, 0xB0,
                                     0x29, 0xBA, 0x8E, 0xB0, 0x29, 0xBA, 0x8E, 0xB0, 0x29, 0xBA, 0x8E, 0x30 };

const byte Sound_N  [52] PROGMEM = { 0x98, 0xD7, 0x5D, 0xA0, 0x98, 0xD7, 0x5D, 0xA0, 0x98, 0xD7, 0x5D, 0xA0, 0x99, 0xD6, 0x55, 0x20,
                                     0x8E, 0xD6, 0x5C, 0x20, 0x8F, 0xD8, 0x5E, 0x20, 0x8F, 0xD8, 0x5E, 0x20, 0xAF, 0xD8, 0x56, 0xA0,
                                     0xAF, 0xD8, 0x56, 0xA0, 0xAF, 0xD8, 0x56, 0xA0, 0x7F, 0xD8, 0x5F, 0x20, 0x7F, 0xD8, 0x5F, 0x20,
                                     0x6B, 0xB7, 0x6F, 0xA0 };

const byte Sound_ai [60] PROGMEM = { 0x57, 0xB3, 0xDD, 0xA0, 0x46, 0xB4, 0xE7, 0xA0, 0x46, 0xB4, 0xDF, 0xA0, 0xAB, 0xB4, 0xCF, 0xA0,
                                     0xAB, 0xB4, 0xCF, 0xA0, 0xEA, 0xB5, 0xC7, 0x20, 0xEA, 0xB5, 0xC7, 0x20, 0xFA, 0xB6, 0xB6, 0xA0,
                                     0xFA, 0xB6, 0xB6, 0xA0, 0xBA, 0xB7, 0x9E, 0x20, 0xBA, 0xB7, 0x9E, 0x20, 0xBA, 0xD8, 0x7D, 0x20,
                                     0xBA, 0xD8, 0x7D, 0x20, 0xFA, 0xD8, 0x73, 0x20, 0xFA, 0xD8, 0x73, 0x20 };

const byte Sound_ej [60] PROGMEM = { 0xBB, 0xB7, 0xB6, 0x20, 0xBB, 0xB7, 0xB6, 0x20, 0xFB, 0xB7, 0xAF, 0x20, 0xFB, 0xB7, 0xAF, 0x20,
                                     0xFB, 0xB7, 0xAF, 0xA0, 0xFB, 0xB7, 0xAF, 0xA0, 0xBB, 0xB7, 0x9F, 0xA0, 0xBB, 0xB7, 0x9F, 0xA0,
                                     0xB6, 0xB8, 0x9F, 0x20, 0xBA, 0xD8, 0x8F, 0x20, 0xBA, 0xD8, 0x8F, 0x20, 0xBA, 0xD8, 0x7E, 0xA0,
                                     0xBA, 0xD8, 0x7E, 0xA0, 0xFA, 0xD8, 0x75, 0xA0, 0xFA, 0xD8, 0x75, 0xA0 };

const byte Sound_ui [60] PROGMEM = { 0xEB, 0xB3, 0xAE, 0x20, 0xEB, 0xB3, 0xAE, 0x20, 0x97, 0xB4, 0xA7, 0x20, 0x97, 0xB4, 0xA7, 0x20,
                                     0x97, 0xB4, 0xA7, 0xA0, 0x57, 0xB4, 0xA7, 0xA0, 0x67, 0xB6, 0x9F, 0x20, 0x67, 0xB6, 0x9F, 0x20,
                                     0x77, 0xB6, 0x87, 0x20, 0xBB, 0xB7, 0x7E, 0xA0, 0xEB, 0xB7, 0x7E, 0xA0, 0xAB, 0xB8, 0x7E, 0x20,
                                     0xAB, 0xD8, 0x76, 0x20, 0x6B, 0xD8, 0x76, 0x20, 0xBA, 0xB7, 0x8C, 0xA0 };

const byte Sound_ie [60] PROGMEM = { 0x7F, 0xD8, 0x6D, 0x20, 0x7F, 0xD8, 0x6E, 0xA0, 0x7F, 0xD8, 0x6E, 0xA0, 0xBF, 0xD7, 0x87, 0x20,
                                     0xFB, 0xD7, 0x8F, 0x20, 0xBB, 0xD7, 0x9F, 0xA0, 0x67, 0xD6, 0xBF, 0xA0, 0x67, 0xD6, 0xBF, 0xA0,
                                     0x67, 0xD5, 0xBF, 0x20, 0x67, 0xD5, 0xBF, 0x20, 0x61, 0xD5, 0xBE, 0x20, 0x61, 0xD5, 0xBE, 0x20,
                                     0x61, 0xD5, 0xBE, 0x20, 0x61, 0xD4, 0xC5, 0x20, 0x61, 0xD4, 0xC5, 0x20 };

const byte Sound_oi [40] PROGMEM = { 0x86, 0x94, 0xBD, 0xA0, 0x86, 0x94, 0xBE, 0xA0, 0x86, 0x96, 0xC7, 0x20, 0x42, 0xB4, 0xD7, 0xA0,
                                     0x53, 0xB5, 0xCF, 0xA0, 0x62, 0xB5, 0xC7, 0x20, 0x62, 0xB5, 0xC6, 0xA0, 0x62, 0xB5, 0xC6, 0x20,
                                     0x62, 0xB5, 0xC5, 0xA0, 0x62, 0xB5, 0xC5, 0x20 };

const byte Sound_o  [32] PROGMEM = { 0xAD, 0xAF, 0xA5, 0x20, 0xAD, 0xAF, 0xA5, 0x20, 0xAD, 0xAF, 0xA6, 0x20, 0xAD, 0xAF, 0xA6, 0x20,
                                     0xAD, 0xAD, 0x96, 0x20, 0xAD, 0xAD, 0x96, 0x20, 0xF9, 0xAD, 0x8D, 0x20, 0xF9, 0xAD, 0x8D, 0x20 };


  
// Words - NATO phonetic alphabet ---------------------------------------------------------------------------------------


const byte Sound_Alpha [140] PROGMEM = {    0x00, 0x99, 0xF8, 0x10, 0x94, 0xD1, 0xCE, 0x20, 0xA8, 0xD1, 0xCF, 0x20, 0xE9, 0xD2, 0xCF, 0xA1,
                                            0xE9, 0xD3, 0xCF, 0xA0, 0xD4, 0xD3, 0xCF, 0x20, 0xD4, 0xD3, 0xBF, 0xBF, 0xEB, 0xD4, 0x9F, 0x20,
                                            0xD4, 0xB5, 0x8F, 0x20, 0xE5, 0xB5, 0x7E, 0xA0, 0xE1, 0xB5, 0x76, 0x20, 0xE2, 0xB5, 0x65, 0xBF, 
                                            0xE5, 0x95, 0x5D, 0x3F, 0xE0, 0x95, 0x6C, 0xA0, 0x44, 0xB6, 0x54, 0x30, 0x11, 0x77, 0x54, 0xB0, 
                                            0x14, 0xD6, 0x5C, 0xB0, 0x40, 0xD9, 0x5E, 0x30, 0x00, 0xDB, 0x65, 0xB0, 0x54, 0xD7, 0x65, 0xB0, 
                                            0x00, 0xD8, 0x6D, 0x30, 0x00, 0xB8, 0x6D, 0x30, 0x00, 0xD6, 0x75, 0x30, 0x00, 0xB4, 0x73, 0xB0, 
                                            0x90, 0xD1, 0x7C, 0x30, 0xE8, 0xD1, 0x9D, 0x20, 0xF8, 0xD1, 0xAE, 0xBD, 0xE4, 0xD1, 0xBE, 0xBE, 
                                            0xA4, 0xD1, 0xBE, 0xBE, 0xA4, 0xD1, 0xC6, 0xBF, 0xA4, 0xD1, 0xBE, 0xBE, 0x91, 0xD2, 0xD5, 0x3F,
                                            0x93, 0xB2, 0xDC, 0x30, 0x42, 0x95, 0xEA, 0xB0, 0x40, 0x55, 0xF8, 0x30 };


const byte Sound_Bravo [120] PROGMEM = {    0x00, 0x99, 0xF0, 0x10, 0xF8, 0xCD, 0x94, 0x20, 0xA9, 0xCD, 0x94, 0xA0, 0xA8, 0xCE, 0xAD, 0x21, 
                                            0xB8, 0xCE, 0xBD, 0xA2, 0xB9, 0xCE, 0xBE, 0xA1, 0xA8, 0xCF, 0xC7, 0x24, 0x94, 0xCF, 0xD7, 0xA1, 
                                            0x94, 0xCF, 0xD7, 0xA2, 0x94, 0xD0, 0xCF, 0xA1, 0x94, 0xD0, 0xC7, 0x20, 0x94, 0xD0, 0xAF, 0x21, 
                                            0x94, 0xD0, 0x8E, 0x20, 0xF9, 0xD0, 0x75, 0xBE, 0xA9, 0xB0, 0x65, 0xBF, 0x66, 0xB0, 0x3C, 0xBC, 
                                            0x11, 0xB1, 0x2C, 0x3F, 0x15, 0xAF, 0x2D, 0x3E, 0x16, 0xB0, 0x3D, 0x21, 0x51, 0xB0, 0x56, 0x24, 
                                            0x95, 0xAC, 0x6D, 0x24, 0xE1, 0xAB, 0x75, 0x22, 0xD0, 0xAA, 0x7D, 0x3F, 0xD1, 0x8A, 0x7C, 0xBE, 
                                            0x80, 0xC9, 0x7C, 0xBF, 0x81, 0xC6, 0x74, 0x3E, 0x81, 0xC5, 0x6C, 0x3E, 0x90, 0xA5, 0x6B, 0xBC, 
                                            0x61, 0xA3, 0x6A, 0xA0, 0x00, 0x75, 0x68, 0x20 };
            
 
const byte Sound_Charlie [164] PROGMEM = {  0x00, 0x99, 0xF8, 0x10, 0x25, 0xBA, 0xF3, 0xB0, 0x25, 0xBA, 0xE4, 0xB0, 0x25, 0xBA, 0xD5, 0x30, 
                                            0x25, 0xBA, 0xC5, 0xB0, 0x25, 0xBA, 0xBD, 0xB0, 0x25, 0xBA, 0xAE, 0x30, 0x25, 0xBA, 0x9E, 0x30, 
                                            0x25, 0xBA, 0x8D, 0xB0, 0x25, 0xBA, 0x86, 0x30, 0x25, 0xB9, 0x86, 0x30, 0x18, 0xD6, 0x85, 0xB0, 
                                            0x94, 0xD4, 0x96, 0xA0, 0x94, 0xB2, 0xB7, 0x20, 0xA8, 0xB2, 0xBF, 0x3F, 0xE8, 0xB2, 0xC7, 0xA0, 
                                            0xE8, 0xB1, 0xC7, 0xA0, 0xA8, 0xD0, 0xC7, 0xBF, 0xA4, 0xD0, 0xC7, 0x3F, 0xB5, 0xAF, 0xB6, 0x3D, 
                                            0xB9, 0xAF, 0xA5, 0xBF, 0xA9, 0xAE, 0x9D, 0xBF, 0xAD, 0xAD, 0x94, 0x30, 0x59, 0xAD, 0x94, 0xB0, 
                                            0x4C, 0xAD, 0xA4, 0xB0, 0x5C, 0xAE, 0x9D, 0x21, 0x98, 0xB0, 0x95, 0xA0, 0x94, 0xB1, 0x85, 0x3F, 
                                            0x90, 0xB3, 0x7D, 0x3F, 0x52, 0xB4, 0x55, 0x3F, 0x92, 0xB7, 0x65, 0x20, 0xD8, 0xD9, 0x6E, 0x21, 
                                            0xD4, 0xDA, 0x66, 0x20, 0xE0, 0xDB, 0x5D, 0x3F, 0xE4, 0xDB, 0x55, 0x3F, 0xE4, 0xDB, 0x55, 0x20, 
                                            0xE4, 0xDC, 0x55, 0x3F, 0xF1, 0xBB, 0x5A, 0x3F, 0xE8, 0xBC, 0x4C, 0x3E, 0x82, 0xB8, 0x43, 0x3E, 
                                            0x44, 0xD8, 0x20, 0x30 };
        
const byte Sound_Delta [140] PROGMEM = {    0x80, 0xD7, 0x20, 0x10, 0x04, 0xB5, 0x4B, 0x80, 0x40, 0xB7, 0x7D, 0x80, 0xF8, 0xD7, 0x75, 0x80, 
                                            0xF2, 0xB7, 0x85, 0x80, 0xE8, 0xD7, 0x96, 0xA0, 0xE8, 0xD7, 0x97, 0xA0, 0xE8, 0xD7, 0x9F, 0xA0,
                                            0xD8, 0xD7, 0x9F, 0xA1, 0xE8, 0xD7, 0x9F, 0xA0, 0xD0, 0xB6, 0x8F, 0x20, 0xE4, 0xB6, 0x6E, 0x20,
                                            0xE6, 0xB5, 0x6E, 0x20, 0xE7, 0xB6, 0x65, 0xBE, 0xE1, 0xB7, 0x66, 0x20, 0xE5, 0x97, 0x4D, 0xBF,
                                            0xE1, 0xB7, 0x4D, 0x3F, 0xF1, 0xB7, 0x44, 0x20, 0xA0, 0xB7, 0x33, 0x30, 0x40, 0xB8, 0x39, 0x30,
                                            0x40, 0xB8, 0x38, 0x70, 0x40, 0xB8, 0x38, 0x70, 0x00, 0xB8, 0xE3, 0x30, 0x01, 0x98, 0xCD, 0x30, 
                                            0xA2, 0xD6, 0x96, 0x27, 0x98, 0xD5, 0xA6, 0xBA, 0x82, 0xD3, 0xBE, 0xBD, 0x93, 0xB3, 0xBE, 0xBE,
                                            0xE8, 0xD3, 0xC7, 0x3F, 0xA8, 0xD2, 0xC6, 0xBF, 0xA8, 0xD1, 0xBE, 0xBE, 0x58, 0xD0, 0xC5, 0xBE,
                                            0x22, 0x91, 0xF3, 0xB0, 0x11, 0x72, 0xFA, 0xB0, 0x10, 0xB2, 0xE0, 0x30 };


const byte Sound_Echo [100] PROGMEM = { 0x44, 0xD5, 0x88, 0x10, 0xE4, 0xDA, 0x74, 0xA0, 0xC8, 0xBA, 0x76, 0x20, 0xE4, 0xBA, 0x77, 0x20, 
                                        0xF0, 0xDA, 0x77, 0x20, 0xF4, 0xDA, 0x77, 0xA0, 0xE4, 0xDB, 0x6F, 0x20, 0xE0, 0xDB, 0x5E, 0x20, 
                                        0xE0, 0xBB, 0x45, 0xBD, 0xCC, 0xBA, 0x3B, 0xB0, 0x84, 0xB5, 0x59, 0xB0, 0x88, 0xB4, 0x60, 0x70,
                                        0x88, 0xB4, 0x60, 0x70, 0x40, 0xB9, 0xE9, 0x30, 0x90, 0xAF, 0xBD, 0x30, 0x50, 0xAC, 0x73, 0xB0,
                                        0xE5, 0xA9, 0x5C, 0x23, 0xE6, 0xA7, 0x64, 0xA0, 0xE1, 0xC7, 0x64, 0xBE, 0x91, 0xC5, 0x64, 0x20, 
                                        0x90, 0xC4, 0x64, 0x3F, 0x90, 0xC4, 0x63, 0xBF, 0x94, 0xC5, 0x5C, 0x3E, 0x95, 0xC5, 0x53, 0x3D,
                                        0x20, 0xA0, 0x00, 0x30 };
        


const byte Sound_Foxtrot [232] PROGMEM = {  0x00, 0x99, 0xF0, 0x10, 0x00, 0x97, 0xD3, 0xB0, 0x1A, 0xB7, 0xC4, 0x30, 0x16, 0xB6, 0xBC, 0x30, 
                                            0x16, 0xB6, 0xB4, 0xB0, 0x16, 0xB6, 0xAC, 0xB0, 0x16, 0xB6, 0xA4, 0xB0, 0x16, 0xB6, 0x95, 0x30, 
                                            0x16, 0xB6, 0x8D, 0x30, 0xAA, 0xAF, 0x7D, 0x20, 0xFF, 0xAF, 0x8E, 0xA0, 0xEF, 0xAF, 0x9F, 0x20, 
                                            0xEA, 0xAE, 0x9F, 0xA0, 0xFA, 0xAD, 0x8E, 0xBF, 0xB5, 0xCC, 0x65, 0x20, 0x75, 0xAD, 0x43, 0x30, 
                                            0x90, 0xAF, 0x9A, 0x30, 0x80, 0xB0, 0x91, 0xB0, 0x80, 0xB0, 0x90, 0x30, 0x10, 0xB6, 0xC4, 0xB0, 
                                            0x60, 0xB7, 0xA5, 0x30, 0x25, 0xD7, 0x6E, 0xB0, 0x15, 0xD8, 0xBE, 0x30, 0x05, 0xD7, 0xCD, 0xB0, 
                                            0x14, 0xF7, 0xC5, 0xB0, 0x14, 0xD7, 0x8D, 0xB0, 0x00, 0xD8, 0xD8, 0x30, 0x00, 0xD8, 0xD8, 0x30, 
                                            0x00, 0xD8, 0xD8, 0x30, 0x00, 0xD8, 0xD8, 0x30, 0x00, 0xD8, 0xD8, 0x30, 0x00, 0xD8, 0xD8, 0x30, 
                                            0x00, 0xD8, 0xD8, 0x30, 0x10, 0xB8, 0xAC, 0xB0, 0x00, 0xB9, 0xFE, 0x30, 0x20, 0xD1, 0x05, 0x30, 
                                            0x10, 0xD0, 0x44, 0xB0, 0x99, 0xAD, 0x9D, 0xB0, 0xE4, 0xAD, 0xA6, 0xA0, 0xA4, 0xCE, 0xB7, 0x3C, 
                                            0xA4, 0xAF, 0xB7, 0x3E, 0xE4, 0xD0, 0xAF, 0x20, 0xE8, 0xD1, 0x9F, 0x20, 0xD8, 0xD2, 0x97, 0x3E, 
                                            0xE8, 0xD3, 0x74, 0xA0, 0x50, 0xAF, 0x3A, 0x30, 0x40, 0xD2, 0xA2, 0x30, 0x90, 0xB0, 0xA0, 0x30, 
                                            0x90, 0xB0, 0xA0, 0x30, 0x90, 0xB0, 0xA0, 0x30, 0x91, 0xF0, 0xA0, 0x30, 0x91, 0xF0, 0xA0, 0x30, 
                                            0x91, 0xF0, 0xA3, 0xB0, 0x91, 0xF0, 0xA5, 0x30, 0x91, 0xF0, 0xA4, 0x30, 0x91, 0xF0, 0xA3, 0x30, 
                                            0x91, 0xF0, 0xA2, 0x30, 0x91, 0xF0, 0xA0, 0x30 };

const byte Sound_Golf [124] PROGMEM = { 0x80, 0xB6, 0x30, 0x10, 0x20, 0xB7, 0xEC, 0x20, 0x64, 0xB6, 0x75, 0x20, 0xC8, 0xD7, 0x75, 0x20, 
                                        0xD8, 0xD3, 0x7E, 0x20, 0xD8, 0xD2, 0x8E, 0xA0, 0xDD, 0xD1, 0x9F, 0xA1, 0xDD, 0xD1, 0x9F, 0xA0, 
                                        0xD9, 0xD1, 0x9F, 0x20, 0xEC, 0xB2, 0x9F, 0x20, 0xA7, 0x93, 0x8E, 0xBF, 0xA7, 0x93, 0x86, 0xA0, 
                                        0xA7, 0x94, 0x7E, 0xBE, 0x96, 0x94, 0x76, 0x3F, 0xE1, 0x74, 0x6D, 0x3E, 0x91, 0x75, 0x65, 0x3E, 
                                        0xA0, 0x76, 0x6C, 0x30, 0x16, 0xB7, 0x6B, 0xB0, 0x16, 0xB7, 0x83, 0xB0, 0x56, 0xB7, 0xFB, 0xB0, 
                                        0x16, 0xB7, 0xFC, 0x30, 0x16, 0xB7, 0xDC, 0xB0, 0x16, 0xB7, 0xFC, 0xB0, 0x16, 0xB7, 0xD5, 0x30, 
                                        0x16, 0xB7, 0xD5, 0x30, 0x16, 0xB7, 0xD4, 0xB0, 0x16, 0xB7, 0xD4, 0xB0, 0x16, 0xB7, 0xD4, 0xB0, 
                                        0x16, 0xB7, 0xD4, 0x30, 0x16, 0xB7, 0xEA, 0x30, 0x16, 0xB7, 0xC8, 0x10 };

const byte Sound_Hotel [184] PROGMEM = {    0x00, 0x99, 0xF8, 0x10, 0xF9, 0xAC, 0x95, 0x20, 0xE4, 0xAB, 0x95, 0xA0, 0xD0, 0xAC, 0x96, 0x20, 
                                            0x90, 0x8D, 0x9E, 0xA1, 0xD0, 0xAD, 0x8E, 0xA1, 0xE4, 0xAD, 0x86, 0xA0, 0xE4, 0xAE, 0x7E, 0xA0, 
                                            0xF9, 0xD1, 0x7F, 0x20, 0xC8, 0xD3, 0x76, 0x3F, 0x40, 0xD3, 0x3B, 0xB0, 0x00, 0x90, 0x03, 0x30, 
                                            0x00, 0x96, 0xF0, 0x30, 0x00, 0x96, 0xF0, 0x30, 0x00, 0x96, 0xF0, 0x30, 0x00, 0x96, 0xF0, 0x30, 
                                            0x00, 0x96, 0xF0, 0x30, 0x00, 0x96, 0xF0, 0x30, 0x00, 0x96, 0xF0, 0x30, 0x00, 0x96, 0xF0, 0x30, 
                                            0x00, 0x96, 0xF0, 0x30, 0x14, 0xD8, 0xCE, 0x30, 0xE2, 0xD7, 0x8E, 0x3F, 0xE4, 0xD7, 0x97, 0xA0, 
                                            0xE8, 0xD7, 0x9F, 0xBC, 0xE8, 0xD7, 0x9F, 0xA0, 0xF2, 0xD7, 0x9F, 0x20, 0xE2, 0xD7, 0x9F, 0xA0, 
                                            0xD4, 0xD6, 0x97, 0xBF, 0xE8, 0xD5, 0x7E, 0xBE, 0xF5, 0xB5, 0x6E, 0x20, 0xF6, 0xB5, 0x76, 0x20, 
                                            0xF2, 0xB5, 0x76, 0x20, 0xE2, 0xB5, 0x76, 0x20, 0xD2, 0xB5, 0x7E, 0x20, 0xD6, 0xB4, 0x7E, 0xA0, 
                                            0xD6, 0xB4, 0x7E, 0x3F, 0xC6, 0xB4, 0x7E, 0x20, 0xC2, 0xB3, 0x7E, 0x20, 0xC6, 0xB3, 0x76, 0x20, 
                                            0xD6, 0xB4, 0x75, 0xA0, 0x84, 0xD5, 0x7E, 0x20, 0x22, 0x96, 0x8C, 0xB0, 0x21, 0x96, 0x6B, 0xB0, 
                                            0x11, 0x76, 0x9B, 0x30, 0x00, 0xB4, 0x08, 0x30 };

const byte Sound_India [152] PROGMEM = {    0x00, 0x99, 0xF8, 0x10, 0xE2, 0xDB, 0x54, 0xA0, 0xCE, 0xBA, 0x5D, 0x20, 0xE8, 0xDB, 0x5E, 0x20, 
                                            0xE1, 0xDB, 0x55, 0xA2, 0xF0, 0xBB, 0x55, 0xA1, 0xF2, 0xDB, 0x4E, 0x20, 0xF8, 0xDB, 0x4E, 0x3F, 
                                            0xAA, 0xB8, 0x54, 0xBD, 0x88, 0xB2, 0x5C, 0xA1, 0x86, 0xAC, 0x54, 0xA0, 0x96, 0xA9, 0x4C, 0xBF, 
                                            0x86, 0xA7, 0x4C, 0x3F, 0x84, 0xC6, 0x4B, 0xBE, 0x80, 0xC5, 0x4B, 0x3E, 0x84, 0xA6, 0x4B, 0xBF, 
                                            0x84, 0xA9, 0x5A, 0xB0, 0x80, 0xAE, 0x6A, 0x30, 0x14, 0xB2, 0x52, 0x30, 0x44, 0xD7, 0x3A, 0x30, 
                                            0xB8, 0xDA, 0x43, 0xB0, 0xF8, 0xDA, 0x44, 0xA0, 0xB2, 0xDA, 0x55, 0x22, 0xF4, 0xDB, 0x5D, 0xA0, 
                                            0xF8, 0xDB, 0x5E, 0x20, 0xF8, 0xDA, 0x6E, 0xA0, 0xF8, 0xDA, 0x7F, 0xA0, 0xE4, 0xD9, 0x8F, 0xA0, 
                                            0xE8, 0xD8, 0xA7, 0x3E, 0xD4, 0xD6, 0xB7, 0x3F, 0x88, 0xD5, 0xB7, 0x3F, 0x88, 0xB3, 0xBE, 0xA0, 
                                            0x93, 0xB4, 0xCE, 0x3F, 0x64, 0xD3, 0xAD, 0x30, 0x12, 0x72, 0x8C, 0x30, 0x42, 0x74, 0x74, 0x30, 
                                            0x14, 0xB1, 0x53, 0x30, 0x00, 0xAD, 0x38, 0x30 };
        
const byte Sound_Juliet [148] PROGMEM = {   0x00, 0x99, 0xF8, 0x10, 0x1D, 0xB8, 0xFB, 0xB0, 0x48, 0xBB, 0xFC, 0x30, 0x61, 0xBB, 0xFC, 0xB0,
                                            0x88, 0xDB, 0xFC, 0xB0, 0xA4, 0xDB, 0xFD, 0x30, 0x18, 0xB8, 0xFD, 0xB0, 0x64, 0xB7, 0x5D, 0x20, 
                                            0x84, 0xB7, 0x65, 0x20, 0x84, 0xB1, 0x65, 0x21, 0x99, 0xAE, 0x5C, 0xA2, 0xA8, 0xAC, 0x5C, 0xA0, 
                                            0x48, 0xB0, 0x64, 0x3C, 0x52, 0xB0, 0x33, 0x3F, 0x9C, 0xB2, 0x3B, 0xA0, 0x06, 0x73, 0x25, 0x20, 
                                            0x94, 0xBA, 0x4E, 0x22, 0xE9, 0xBA, 0x46, 0x22, 0xF0, 0xDB, 0x46, 0x20, 0xF4, 0xDB, 0x56, 0x20, 
                                            0xE4, 0xDB, 0x66, 0xA0, 0xE4, 0xDA, 0x7F, 0x20, 0xE4, 0xD9, 0x87, 0x3F, 0xE8, 0xD8, 0x97, 0xBE,
                                            0xE8, 0xD8, 0x9F, 0xBE, 0xE8, 0xD7, 0x9F, 0x3E, 0xFC, 0xD7, 0x96, 0x3D, 0xB2, 0xD7, 0x6C, 0xBF, 
                                            0x52, 0xD8, 0x49, 0xB0, 0x90, 0xD7, 0x80, 0x70, 0x90, 0xD7, 0x80, 0x70, 0x90, 0xD7, 0x80, 0x70, 
                                            0x90, 0xD7, 0x80, 0x50, 0x01, 0xF3, 0xC0, 0x30, 0x41, 0xF7, 0x9C, 0x30, 0x61, 0xF7, 0x7A, 0xB0, 
                                            0x60, 0xD7, 0x78, 0x30 };

const byte Sound_Kilo [108] PROGMEM = { 0x00, 0x99, 0xF8, 0x10, 0x00, 0xD8, 0xE4, 0x90, 0x00, 0xD9, 0xDF, 0x10, 0x01, 0xBA, 0xF6, 0x30, 
                                        0x48, 0xFA, 0x64, 0xA0, 0xE8, 0xFB, 0x45, 0xA0, 0xF1, 0xDB, 0x46, 0xA0, 0xF5, 0xDB, 0x47, 0x20, 
                                        0xF5, 0xDB, 0x47, 0x20, 0xE9, 0xDB, 0x47, 0x3F, 0xA5, 0xDA, 0x4F, 0x3F, 0x99, 0xB7, 0x46, 0xBE,
                                        0xA9, 0xB6, 0x4E, 0xA0, 0xEC, 0xD6, 0x4F, 0x3F, 0xAC, 0xB6, 0x4F, 0x3F, 0xA8, 0xB5, 0x4E, 0xBE, 
                                        0xA8, 0xB4, 0x4E, 0x3F, 0xC6, 0xB2, 0x76, 0xA0, 0xD9, 0xAE, 0x76, 0xA0, 0x9E, 0xAC, 0x76, 0x3E, 
                                        0x9D, 0xCA, 0x76, 0x3E, 0xE8, 0xC8, 0x65, 0x3E, 0xD1, 0xC9, 0x64, 0xBF, 0xA4, 0xC7, 0x5B, 0xBE, 
                                        0xA4, 0xC7, 0x52, 0xB0, 0x21, 0xA5, 0x01, 0x30, 0x20, 0xA6, 0x00, 0x10 };

const byte Sound_Lima [124] PROGMEM = { 0x45, 0xB7, 0x58, 0x10, 0xD1, 0xB7, 0x5B, 0xA0, 0x91, 0xB8, 0x75, 0x20, 0xE1, 0xB7, 0x65, 0xA0, 
                                        0xE0, 0xB7, 0x65, 0x22, 0xD0, 0xD7, 0x55, 0xA1, 0xD4, 0xD8, 0x45, 0x21, 0xD0, 0xDA, 0x5E, 0x24, 
                                        0xD4, 0xDB, 0x56, 0xA2, 0xE4, 0xDB, 0x46, 0x21, 0xE0, 0xDB, 0x46, 0x20, 0xE4, 0xFC, 0x46, 0x20, 
                                        0xE4, 0xDB, 0x46, 0x20, 0x88, 0xB7, 0x5D, 0x20, 0x43, 0xB9, 0x65, 0x21, 0x43, 0xB9, 0x6D, 0x20, 
                                        0x8C, 0xB3, 0x55, 0xA0, 0x8C, 0xB2, 0x4D, 0xBF, 0x8C, 0xB2, 0x4D, 0xBE, 0x9C, 0xB1, 0x45, 0xA0, 
                                        0xE8, 0xB1, 0x86, 0x3F, 0xA8, 0xD2, 0xAF, 0x3E, 0xBC, 0xD2, 0xBF, 0x3F, 0xFC, 0xD2, 0xC7, 0xBE, 
                                        0xA8, 0xD2, 0xC7, 0x3E, 0xA8, 0xD2, 0xCE, 0xBF, 0xA9, 0xD1, 0xC5, 0xBD, 0xA8, 0xD1, 0xC5, 0x3E,
                                        0x52, 0xB2, 0xCC, 0xB0, 0x12, 0x90, 0xDB, 0xB0, 0x11, 0x71, 0xE8, 0x30 };
                                        

// 188 bytes for "Michael" and 112 const byte for (official) "Mike"
const byte Sound_Michael [188] PROGMEM = {  0x00, 0x99, 0xF8, 0x10, 0x00, 0x99, 0xF8, 0x30, 0x00, 0x99, 0xF8, 0x30, 0x00, 0x99, 0xF8, 0x30, 
                                            0x00, 0x99, 0xF8, 0x30, 0xF8, 0xB0, 0x4A, 0xB0, 0x6C, 0xB0, 0x4C, 0x20, 0x5C, 0xAF, 0x3D, 0x20, 
                                            0xB8, 0xAF, 0x95, 0x20, 0xB5, 0xB0, 0xB6, 0x21, 0xB4, 0xB1, 0xC6, 0xA1, 0xFD, 0xB2, 0xC7, 0x21, 
                                            0xFD, 0xB3, 0xBF, 0xA1, 0xE8, 0xB5, 0xB7, 0xA0, 0xE8, 0xB7, 0x9F, 0xA0, 0xD8, 0xD8, 0x8F, 0x21, 
                                            0xE4, 0xDA, 0x7F, 0x20, 0xF4, 0xDB, 0x6E, 0x20, 0xF4, 0xDB, 0x4D, 0xA0, 0xF0, 0xFB, 0x44, 0xBF, 
                                            0x8D, 0xB8, 0x33, 0x30, 0x84, 0xB5, 0x39, 0xB0, 0x84, 0xB4, 0x49, 0x30, 0x84, 0xB4, 0x48, 0x30,
                                            0x84, 0xB4, 0x48, 0x30, 0x84, 0xB4, 0x48, 0x30, 0x84, 0xB4, 0x48, 0x30, 0x84, 0xB4, 0x48, 0x30, 
                                            0x10, 0xDA, 0xFD, 0xB0, 0x10, 0xBA, 0xF5, 0xB0, 0xD8, 0xB9, 0x64, 0x21, 0xD8, 0xB8, 0x7D, 0x20,
                                            0xE8, 0xB7, 0x8D, 0xBC, 0xEC, 0xB6, 0x95, 0xBF, 0xC8, 0xB6, 0x9D, 0xBF, 0xD9, 0xB4, 0x95, 0x3F,
                                            0xE8, 0xD4, 0x84, 0xBF, 0xF5, 0xB5, 0x6C, 0xBF, 0xE2, 0xB5, 0x7D, 0x20, 0xE2, 0xB5, 0x7D, 0x3F, 
                                            0xA7, 0xB5, 0x7D, 0x20, 0xE2, 0xB5, 0x7C, 0x3F, 0xE2, 0x95, 0x7B, 0xBF, 0xE2, 0xB5, 0x73, 0xB0, 
                                            0x52, 0xD6, 0x42, 0xB0, 0x44, 0xD7, 0x59, 0xB0, 0x41, 0xB8, 0x90, 0x30 };

const byte Sound_November [200] PROGMEM = { 0x00, 0x99, 0xF8, 0x10, 0x41, 0xAE, 0x63, 0x30, 0x81, 0xAE, 0x63, 0xA0, 0x86, 0xAC, 0x54, 0xA0, 
                                            0x85, 0xAB, 0x55, 0x21, 0x8A, 0xAC, 0x55, 0x21, 0xD4, 0xB4, 0x76, 0x24, 0xE4, 0xD3, 0x8F, 0xA0, 
                                            0xE8, 0xD2, 0x97, 0xA1, 0xF8, 0xD1, 0x97, 0xA1, 0xE8, 0xCF, 0x97, 0x20, 0xE4, 0xCF, 0x97, 0x20, 
                                            0xE8, 0xCF, 0x8E, 0xBF, 0xE4, 0xCE, 0x7E, 0x3E, 0xA8, 0xCF, 0x6D, 0xBF, 0xA8, 0xB0, 0x6E, 0x20, 
                                            0xFC, 0xD1, 0x7E, 0xA1, 0xF8, 0xD2, 0x87, 0x21, 0xF8, 0xD2, 0x97, 0xA0, 0xF8, 0xD3, 0x97, 0xA0, 
                                            0xF8, 0xD3, 0x8F, 0xBF, 0xF8, 0xD2, 0x7E, 0x3E, 0xE8, 0xB2, 0x5D, 0xBF, 0xE8, 0xB2, 0x4D, 0x21,
                                            0xD8, 0xD2, 0x4D, 0x21, 0xD8, 0xB2, 0x4D, 0x3F, 0xD0, 0xB2, 0x4C, 0xBF, 0xD8, 0xB3, 0x4D, 0x3F,
                                            0xD8, 0xB3, 0x4D, 0x20, 0xD8, 0xB3, 0x4D, 0x20, 0xCC, 0xB3, 0x4C, 0xBF, 0xDC, 0xB3, 0x44, 0xBF, 
                                            0xDC, 0xB3, 0x44, 0x30, 0x94, 0xB4, 0x7D, 0xB0, 0xE8, 0xB4, 0x87, 0x21, 0xE8, 0xB4, 0x97, 0x20,
                                            0xE4, 0xD4, 0x9F, 0x3F, 0xE8, 0xD5, 0x9F, 0x3F, 0xF8, 0xD5, 0x9F, 0xA0, 0xF4, 0xD5, 0x9F, 0x20, 
                                            0xE8, 0xD5, 0x9F, 0x3F, 0xE8, 0xD4, 0x9F, 0x20, 0xE0, 0xD4, 0xA6, 0xA0, 0xE4, 0xD4, 0xA6, 0xA0,
                                            0xE4, 0xD3, 0xA6, 0x3F, 0x84, 0xD2, 0x8D, 0xA0, 0x5C, 0xD0, 0x8D, 0x20, 0x24, 0xD0, 0x03, 0xB0,
                                            0x15, 0xB0, 0x03, 0x30, 0x14, 0xAE, 0x00, 0x30 };

const byte Sound_Oscar [164] PROGMEM = {    0x00, 0x99, 0xF8, 0x10, 0xA4, 0xCD, 0x8C, 0xA0, 0xF9, 0xCD, 0x9E, 0x20, 0xF4, 0xCE, 0x9E, 0xA0, 
                                            0xE8, 0xD0, 0x9F, 0x20, 0xE8, 0xB1, 0x97, 0xA0, 0xE8, 0xD2, 0x8F, 0x21, 0x88, 0xD3, 0x7E, 0x3F, 
                                            0x40, 0xB5, 0x5D, 0xB0, 0x40, 0xD8, 0x95, 0x30, 0x55, 0xF7, 0xA5, 0xB0, 0x05, 0xF7, 0x86, 0x30, 
                                            0x04, 0xF8, 0x76, 0xB0, 0x24, 0xF8, 0x06, 0xB0, 0x20, 0xD8, 0x00, 0x30, 0x20, 0xD8, 0x00, 0x30, 
                                            0x20, 0xD8, 0x00, 0x30, 0x20, 0xD8, 0x00, 0x30, 0x20, 0xD8, 0x00, 0x30, 0x20, 0xD8, 0x00, 0x30,
                                            0x00, 0x92, 0xF1, 0x30, 0x10, 0xB9, 0xCF, 0x30, 0x50, 0xD8, 0x9E, 0xBF, 0xC4, 0xB7, 0x7F, 0x28,
                                            0xC4, 0xD2, 0x97, 0x3C, 0xD4, 0xB4, 0x9F, 0xBE, 0xD4, 0xB3, 0xA7, 0xA0, 0xE4, 0xB3, 0xB7, 0xBE, 
                                            0xE8, 0xB3, 0xB7, 0xBF, 0xE8, 0xB3, 0xB7, 0xBF, 0xA8, 0xD3, 0xB7, 0x20, 0xB8, 0xD3, 0xBF, 0x3F, 
                                            0xA8, 0xD3, 0xBF, 0x3F, 0xA8, 0xD3, 0xBF, 0x3F, 0xA4, 0xD2, 0xBE, 0xBF, 0xA8, 0xD2, 0xC6, 0x3F, 
                                            0xA4, 0xD1, 0xBD, 0x20, 0x58, 0xD1, 0xC4, 0xA0, 0x24, 0xD0, 0x4B, 0xA0, 0xAA, 0x92, 0x4B, 0x20,
                                            0x64, 0xB1, 0x90, 0x20 };

const byte Sound_Papa [128] PROGMEM = { 0x00, 0x99, 0xF8, 0x10, 0x90, 0x94, 0x94, 0x20, 0xA8, 0xCF, 0xB6, 0x20, 0xA4, 0xD0, 0xC7, 0x20,
                                        0xA8, 0xD0, 0xCF, 0xBF, 0xA2, 0xD0, 0xCF, 0x20, 0xA1, 0xD0, 0xC7, 0x20, 0xE4, 0xCF, 0xAF, 0x3F,
                                        0x90, 0xAE, 0x84, 0xBF, 0x10, 0xCE, 0x13, 0x30, 0x20, 0xB0, 0x72, 0x30, 0x20, 0xB0, 0x70, 0x30,
                                        0x20, 0xB0, 0x70, 0x30, 0x20, 0xB0, 0x70, 0x30, 0x20, 0xB0, 0x70, 0x30, 0x20, 0xB0, 0x70, 0x30, 
                                        0x20, 0xB0, 0x70, 0x30, 0x20, 0xB0, 0x70, 0x30, 0x41, 0xB2, 0x9D, 0xA9, 0xE8, 0xD0, 0xAF, 0x20,
                                        0xE8, 0xD0, 0xBF, 0xBA, 0xA8, 0xD0, 0xBF, 0xBE, 0xF8, 0xD0, 0xC7, 0xA0, 0xF8, 0xD0, 0xC7, 0x3F,
                                        0xA8, 0xD0, 0xC7, 0xBF, 0xE8, 0xD0, 0xC7, 0x20, 0xA8, 0xD0, 0xC6, 0xBE, 0x18, 0xCE, 0xD5, 0x30,
                                        0x82, 0x97, 0xF4, 0xB0, 0x81, 0x77, 0xF3, 0xB0, 0x41, 0x96, 0xF9, 0xB0, 0x10, 0xB1, 0xF8, 0x10 };

const byte Sound_Quebec [148] PROGMEM = {   0x00, 0x99, 0xF8, 0x10, 0x14, 0xDA, 0xDE, 0x30, 0x04, 0xB7, 0x8D, 0xB0, 0x90, 0xDB, 0x6C, 0xA0,
                                            0xE0, 0xDB, 0x66, 0x20, 0xE0, 0xDA, 0x76, 0x20, 0xE0, 0xDA, 0x7E, 0xA0, 0xD4, 0xB9, 0x7F, 0x3F, 
                                            0xE9, 0xB8, 0x77, 0x20, 0xDA, 0xB4, 0x5D, 0x3A, 0xD9, 0xB2, 0x2B, 0x3F, 0xC4, 0xB2, 0x2A, 0xB0, 
                                            0xD8, 0xB2, 0x32, 0x30, 0xD8, 0xB3, 0x32, 0x30, 0xA9, 0xB4, 0x33, 0xB0, 0xF9, 0xB6, 0x7E, 0xA5, 
                                            0xE9, 0xB6, 0x8F, 0x20, 0xE9, 0xB7, 0x97, 0xA0, 0xE9, 0xB7, 0x97, 0x3F, 0xE9, 0xB8, 0x8F, 0xBF, 
                                            0xE9, 0xB8, 0x8F, 0x3E, 0xE9, 0xB9, 0x7F, 0x3F, 0xEC, 0xB9, 0x5D, 0xBE, 0xA0, 0xBB, 0x6A, 0xB0, 
                                            0x90, 0xB8, 0x69, 0xB0, 0x90, 0xB8, 0x68, 0x30, 0x90, 0xB8, 0x68, 0x30, 0x90, 0xB8, 0x68, 0x30, 
                                            0x90, 0xB8, 0x68, 0x30, 0x90, 0xB8, 0x68, 0x30, 0x90, 0xB8, 0x68, 0x30, 0x90, 0xB8, 0x68, 0x30,
                                            0x90, 0xB8, 0x68, 0x30, 0x05, 0xBB, 0xB4, 0xB0, 0x24, 0xDB, 0xC5, 0x30, 0x00, 0xDA, 0x83, 0xB0,
                                            0x00, 0xDA, 0x80, 0x10 };

const byte Sound_Romeo [156] PROGMEM = {    0x95, 0xAE, 0x60, 0x10, 0xE4, 0xAD, 0x82, 0xA0, 0x90, 0xAB, 0x83, 0xA0, 0x52, 0xA7, 0x83, 0xA0, 
                                            0x96, 0xA9, 0x8B, 0xBF, 0x82, 0xA3, 0x93, 0x22, 0x91, 0xA7, 0x9C, 0x20, 0xD9, 0xA8, 0x9D, 0x20, 
                                            0x9A, 0xA8, 0x9D, 0xA4, 0xC9, 0xAA, 0x96, 0x22, 0xC0, 0xAD, 0x9E, 0xA4, 0x85, 0xAB, 0x96, 0xA2, 
                                            0x84, 0xAD, 0x8F, 0x21, 0xC0, 0xAF, 0x86, 0xA1, 0xD4, 0xAE, 0x7E, 0xA0, 0xDC, 0xAD, 0x76, 0x3F, 
                                            0x5C, 0xB0, 0x4E, 0x3E, 0x9C, 0xB1, 0x46, 0x21, 0x8C, 0xB2, 0x45, 0xA0, 0xDC, 0xB2, 0x45, 0xA0, 
                                            0xEC, 0xB5, 0x76, 0xA0, 0xD8, 0xB7, 0x7F, 0x3F, 0xD4, 0xB8, 0x7F, 0xA0, 0xE8, 0xD9, 0x7F, 0x20, 
                                            0xE8, 0xD9, 0x7F, 0x20, 0xD4, 0xD9, 0x7F, 0x20, 0xE4, 0xB9, 0x7F, 0xBF, 0xE8, 0xB8, 0x7F, 0x20, 
                                            0xE8, 0xB5, 0x76, 0xBF, 0xE9, 0xB0, 0x76, 0x3F, 0xE8, 0xAE, 0x76, 0x3F, 0xF4, 0xAB, 0x6D, 0x3F, 
                                            0xE9, 0xA9, 0x65, 0x3F, 0xE5, 0xA8, 0x64, 0xBF, 0x95, 0xC7, 0x64, 0xBF, 0x90, 0xA6, 0x6B, 0xBE, 
                                            0xA2, 0xA7, 0x62, 0xB0, 0x40, 0xA3, 0x91, 0x30, 0x54, 0xAD, 0x60, 0x10 };

const byte Sound_Sierra [120] PROGMEM = {   0x09, 0xF9, 0xF8, 0x10, 0x09, 0xF9, 0xBC, 0xB0, 0x59, 0xF9, 0xAC, 0xB0, 0x59, 0xFA, 0xBC, 0xB0, 
                                            0x19, 0xFA, 0x9C, 0xB0, 0x69, 0xFA, 0xAC, 0xB0, 0xD4, 0xDB, 0x5D, 0xA0, 0xD4, 0xDA, 0x6E, 0x20, 
                                            0xE8, 0xDA, 0x7E, 0xA0, 0xE8, 0xD9, 0x7F, 0x3F, 0xE8, 0xD9, 0x7F, 0xBF, 0xE9, 0xB8, 0x87, 0xBF,
                                            0xE8, 0xB7, 0x8F, 0x3F, 0xE8, 0xD6, 0x8E, 0xBF, 0x98, 0xB4, 0x8E, 0x3E, 0x68, 0xB4, 0x65, 0x30, 
                                            0xAA, 0xB2, 0x8D, 0x30, 0x65, 0xB1, 0x84, 0xB0, 0xA8, 0xB0, 0xA5, 0xB0, 0xAC, 0xB0, 0xAD, 0xBF, 
                                            0xA9, 0xB0, 0xBF, 0x20, 0xAD, 0xB0, 0xBF, 0x3F, 0xA8, 0xB0, 0xC7, 0x3F, 0xE8, 0xD0, 0xC7, 0x3F,
                                            0xE8, 0xD0, 0xC7, 0x20, 0xA4, 0xD0, 0xC6, 0xBF, 0x64, 0xD0, 0xCE, 0x3F, 0x18, 0xCD, 0xDC, 0xB0, 
                                            0x41, 0x97, 0xF3, 0x30, 0x80, 0xB8, 0xF0, 0x30 };

const byte Sound_Tango [120] PROGMEM = {    0x00, 0x99, 0xF8, 0x10, 0x00, 0xDA, 0xEF, 0xB0, 0xD4, 0xD3, 0x8E, 0xA0, 0xE4, 0xB2, 0xA7, 0xA0, 
                                            0xF5, 0xB0, 0xAF, 0x3F, 0xE1, 0xAF, 0x9E, 0xBF, 0xB5, 0xAD, 0x8E, 0x20, 0xAD, 0xAE, 0x7E, 0x20, 
                                            0x48, 0xB2, 0x8E, 0xA0, 0x48, 0xB6, 0xA6, 0xA0, 0x44, 0xB4, 0xAE, 0xA0, 0x48, 0xB0, 0xAE, 0xBF,
                                            0x49, 0xAB, 0x76, 0x20, 0x5C, 0xAB, 0x6D, 0xBF, 0x4C, 0xA9, 0x75, 0xA0, 0x1C, 0xAA, 0x65, 0x3E,
                                            0x1C, 0xAC, 0x6C, 0xBE, 0x23, 0xAD, 0x63, 0x3D, 0x20, 0xAF, 0x6D, 0xA0, 0xB9, 0xAF, 0x5C, 0xA0,
                                            0xEC, 0xAF, 0x65, 0x24, 0xF4, 0xCD, 0x6C, 0xA0, 0xE4, 0xCC, 0x6C, 0xA0, 0xF4, 0xAC, 0x6D, 0x20,
                                            0xE4, 0xAB, 0x75, 0x20, 0xF1, 0xCA, 0x6C, 0xBF, 0xE1, 0xA9, 0x6C, 0x3F, 0xF5, 0xA8, 0x5B, 0xBE,
                                            0x50, 0xC8, 0x52, 0x30, 0x00, 0xC5, 0x00, 0x10 };

const byte Sound_Uniform [204] PROGMEM = {  0x00, 0x99, 0xF8, 0x10, 0xCC, 0xB8, 0x4B, 0xA0, 0xE4, 0xDB, 0x4C, 0x20, 0xF8, 0xDB, 0x45, 0x20, 
                                            0xF4, 0xDB, 0x3D, 0x22, 0xE4, 0xDB, 0x3D, 0xA0, 0xE4, 0xDB, 0x3D, 0xA1, 0xF4, 0xDB, 0x3D, 0xA1,
                                            0xE0, 0xBA, 0x46, 0x24, 0xD9, 0xB7, 0x4F, 0x24, 0xC9, 0xB6, 0x57, 0x23, 0x89, 0xAB, 0x5F, 0x22,
                                            0x4A, 0xA4, 0x67, 0x20, 0x8A, 0xA5, 0x6F, 0x21, 0x8A, 0xAC, 0x67, 0x21, 0x8A, 0xB3, 0x67, 0xA0, 
                                            0x89, 0xB6, 0x5F, 0x3D, 0x4C, 0xB9, 0x76, 0xA0, 0x4C, 0xBA, 0x6E, 0xBF, 0x8D, 0xB4, 0x4E, 0xBE, 
                                            0xD4, 0xDA, 0x5F, 0x3E, 0xD4, 0xDA, 0x5E, 0xA0, 0xE5, 0xBA, 0x4E, 0xBE, 0xD4, 0xB9, 0x4D, 0xBF, 
                                            0x94, 0xB7, 0x3C, 0xB0, 0x10, 0xB6, 0xFC, 0xB0, 0x11, 0xB7, 0xFD, 0x30, 0x41, 0xB8, 0xFD, 0xB0, 
                                            0x45, 0xB4, 0xFD, 0xB0, 0x10, 0xD7, 0xB6, 0x30, 0x41, 0xB9, 0xFE, 0xB0, 0x00, 0xD8, 0xCC, 0xB0, 
                                            0xE4, 0xB0, 0x7D, 0x3D, 0xE9, 0xB0, 0x97, 0x3F, 0xE9, 0xB0, 0x97, 0x3F, 0xE8, 0xB0, 0xA7, 0x3F, 
                                            0xE8, 0xAF, 0xA7, 0x3F, 0xE8, 0xCF, 0xA6, 0xBF, 0xE4, 0xAF, 0xAF, 0x3F, 0xF4, 0xAE, 0xAE, 0x20, 
                                            0xA9, 0xAD, 0xA6, 0xBF, 0xA9, 0xAC, 0xAE, 0xBF, 0xFD, 0xAC, 0xA6, 0x3F, 0xA9, 0xAC, 0x9D, 0xBF, 
                                            0xED, 0xAC, 0x7D, 0x3E, 0x25, 0xAE, 0x25, 0xA2, 0x64, 0xAE, 0x44, 0xA1, 0x45, 0xAC, 0x44, 0x20, 
                                            0x84, 0xD8, 0x3B, 0x3F, 0x16, 0xB1, 0x01, 0x30, 0x01, 0xA9, 0xC0, 0x10 };

const byte Sound_Victor [160] PROGMEM = {   0x00, 0xD7, 0x00, 0x10, 0xD0, 0xB8, 0x2A, 0x30, 0x80, 0xB9, 0x1A, 0x30, 0x94, 0xB9, 0x4C, 0x20, 
                                            0xD0, 0xBA, 0x55, 0xA0, 0x90, 0xDB, 0x57, 0x20, 0x90, 0xDB, 0x4F, 0xA4, 0xC8, 0xBB, 0x47, 0x20, 
                                            0x8C, 0xBA, 0x34, 0xBE, 0x84, 0xB7, 0x2A, 0x30, 0xC4, 0xBA, 0x21, 0x30, 0x88, 0xB7, 0x50, 0xB0, 
                                            0x01, 0xB8, 0xBE, 0x30, 0x01, 0xB6, 0x34, 0x30, 0x48, 0xB6, 0x08, 0x30, 0x48, 0xB6, 0x08, 0x30, 
                                            0x48, 0xB6, 0x08, 0x30, 0x48, 0xB6, 0x08, 0x30, 0x48, 0xB6, 0x08, 0x30, 0x48, 0xB6, 0x08, 0x30, 
                                            0x05, 0xD6, 0x7A, 0x30, 0x00, 0xBA, 0xE5, 0x30, 0xE8, 0xD6, 0x7D, 0xBE, 0xD4, 0xD5, 0x8E, 0xBD, 
                                            0xD8, 0xD4, 0x96, 0xBE, 0xE8, 0xD3, 0x9E, 0xA0, 0xE8, 0xD2, 0x9E, 0xA0, 0xFC, 0xD2, 0xA6, 0xA0, 
                                            0xF8, 0xD1, 0xA6, 0xBF, 0xE8, 0xD1, 0xA6, 0xBE, 0xEC, 0xD1, 0xA6, 0x3F, 0xF8, 0xD0, 0xA5, 0xBF, 
                                            0xF8, 0xD0, 0xA5, 0xBF, 0xF8, 0xD0, 0xA5, 0xBF, 0xE4, 0xCF, 0xA5, 0xBF, 0xE4, 0xCF, 0xA5, 0x3F, 
                                            0xE4, 0xCE, 0x9C, 0xBF, 0xA4, 0xCC, 0x94, 0x3E, 0x71, 0xAC, 0x5A, 0x30, 0x20, 0xAC, 0x00, 0x10 };

const byte Sound_Whisky [128] PROGMEM = {   0x00, 0x88, 0x80, 0x10, 0x28, 0xA0, 0x7B, 0x20, 0x9C, 0xA2, 0x83, 0xA0, 0x59, 0xA5, 0x64, 0x20, 
                                            0xE9, 0xAA, 0x64, 0xA3, 0xF9, 0xAE, 0x66, 0x22, 0xEC, 0xB2, 0x66, 0xA1, 0xC8, 0xB9, 0x67, 0xA2, 
                                            0xE0, 0xDB, 0x5F, 0xA1, 0xF2, 0xDB, 0x56, 0x20, 0xE8, 0xDA, 0x4E, 0x3F, 0x09, 0xB9, 0x4D, 0xB0,
                                            0x21, 0xBA, 0x4D, 0x30, 0x64, 0xFA, 0x4E, 0x30, 0x14, 0xFA, 0x4E, 0x30, 0x24, 0xF9, 0x4E, 0x30, 
                                            0x04, 0xF4, 0x4C, 0x30, 0x04, 0xB4, 0x48, 0x30, 0x04, 0xB4, 0x48, 0x70, 0x00, 0xB5, 0x4C, 0x50, 
                                            0x04, 0xDB, 0x4F, 0xB0, 0x04, 0xDC, 0x4E, 0x30, 0xE0, 0xDC, 0x56, 0x3F, 0xE0, 0xDB, 0x5F, 0x3E,
                                            0xE4, 0xDB, 0x5F, 0xBE, 0xE4, 0xDB, 0x67, 0x3F, 0xE4, 0xDB, 0x67, 0x3F, 0xF0, 0xDC, 0x67, 0x3E,
                                            0xF4, 0xDB, 0x66, 0xBE, 0xF0, 0xDB, 0x65, 0xBE, 0xA4, 0xDB, 0x2C, 0xB0, 0x81, 0xB7, 0xD8, 0x30 };

const byte Sound_X_ray [104] PROGMEM = {    0x51, 0x99, 0x70, 0x10, 0xF4, 0xDA, 0x6D, 0xA0, 0xE9, 0xDA, 0x67, 0x20, 0xE5, 0xBA, 0x67, 0xC0,
                                            0x98, 0xBA, 0x5F, 0xBF, 0x88, 0xBA, 0x3D, 0x39, 0xF0, 0xDB, 0x32, 0xB0, 0x8C, 0xB6, 0x62, 0x30, 
                                            0x04, 0xB8, 0x64, 0xB0, 0x04, 0xB7, 0x66, 0x30, 0x14, 0xB8, 0x6D, 0x30, 0x11, 0xF8, 0x75, 0xF0, 
                                            0x11, 0xF5, 0x86, 0xF0, 0x11, 0xF5, 0x8C, 0xD0, 0x24, 0xB3, 0x8D, 0x30, 0xA4, 0xB3, 0x95, 0xA1, 
                                            0xD8, 0xB3, 0x9E, 0x20, 0xD8, 0xB4, 0xA7, 0x40, 0xE0, 0xB5, 0xA7, 0x21, 0xD0, 0xB5, 0xA7, 0x3F, 
                                            0xE4, 0xD7, 0x9F, 0x40, 0xD8, 0xD7, 0x96, 0xBF, 0x64, 0xD8, 0x64, 0xBF, 0x02, 0x98, 0xE4, 0xB0, 
                                            0x30, 0xB8, 0x99, 0xB0, 0x70, 0xD8, 0x90, 0x30 };

const byte Sound_Yankee [160] PROGMEM = {   0xC4, 0xBA, 0x68, 0x10, 0xE0, 0xBB, 0x5B, 0xA0, 0xF8, 0xDB, 0x5C, 0xA0, 0xF4, 0xDB, 0x55, 0x20, 
                                            0xF4, 0xFB, 0x55, 0xA0, 0xFC, 0xFB, 0x55, 0xA1, 0xF4, 0xFB, 0x55, 0xA1, 0xF4, 0xDB, 0x66, 0xA1, 
                                            0xE4, 0xDA, 0x7F, 0x23, 0xD8, 0xB7, 0x97, 0xA0, 0xED, 0xB4, 0x9F, 0xA0, 0xEC, 0xB1, 0x9F, 0x20, 
                                            0xEC, 0xCF, 0x96, 0x20, 0xE8, 0xAE, 0x85, 0x20, 0xE8, 0xAD, 0x74, 0xBF, 0x98, 0xAE, 0x64, 0xA0, 
                                            0x4C, 0xA7, 0x74, 0xBF, 0x4C, 0xA8, 0x7D, 0x20, 0x9C, 0xAB, 0x5C, 0xBF, 0xAC, 0xAB, 0x54, 0x3F, 
                                            0x48, 0xAA, 0x32, 0xB0, 0x08, 0xA1, 0x6A, 0x30, 0x48, 0xAE, 0x80, 0x30, 0x48, 0xAE, 0x80, 0x30, 
                                            0x48, 0xAE, 0x80, 0x30, 0x48, 0xAE, 0x80, 0x30, 0x48, 0xAE, 0x80, 0x30, 0x48, 0xAE, 0x80, 0x30, 
                                            0x00, 0xDB, 0xFC, 0xB0, 0x04, 0xDB, 0xE5, 0xB0, 0x08, 0xD5, 0xFD, 0xB0, 0xD9, 0xBB, 0x4D, 0x21, 
                                            0xE5, 0xBB, 0x56, 0x20, 0xF0, 0xDB, 0x5D, 0xBE, 0xF0, 0xDB, 0x55, 0xBF, 0xE0, 0xDB, 0x5D, 0xBF,
                                            0xE1, 0xDB, 0x55, 0xA0, 0xE4, 0xDB, 0x4C, 0xBF, 0xE1, 0xDC, 0x3B, 0x3F, 0x45, 0xB3, 0xD0, 0x30 };
        
const byte Sound_Zulu [116] PROGMEM = { 0x80, 0xD6, 0x30, 0x10, 0xD2, 0xD8, 0x4C, 0x20, 0xEC, 0xD8, 0x4C, 0xA0, 0xE4, 0xD8, 0x45, 0xBD, 
                                        0xA8, 0xD8, 0x46, 0x30, 0x01, 0xD8, 0x26, 0xB0, 0x02, 0xD8, 0x26, 0xB0, 0x9D, 0xB8, 0x57, 0x28, 
                                        0x94, 0xB7, 0x5F, 0x25, 0x94, 0xB4, 0x5F, 0x20, 0x48, 0xCE, 0x5E, 0xA1, 0x48, 0xAC, 0x5E, 0xA0, 
                                        0x48, 0xC7, 0x66, 0x20, 0x4C, 0xA5, 0x66, 0x20, 0x98, 0xA9, 0x4D, 0xA0, 0x58, 0xA9, 0x3C, 0x3E, 
                                        0x84, 0xAC, 0x3C, 0x3F, 0x58, 0xB0, 0x3D, 0x3E, 0xA8, 0xD1, 0x4D, 0xA0, 0xA8, 0xD0, 0x55, 0xBF, 
                                        0x94, 0xB0, 0x66, 0x20, 0xEB, 0xAC, 0x66, 0x20, 0xE9, 0xCB, 0x5D, 0xBF, 0xEC, 0xCA, 0x5D, 0xBF,
                                        0xE8, 0xC8, 0x54, 0xBF, 0xA4, 0xC6, 0x54, 0x3F, 0x90, 0xA6, 0x64, 0x3F, 0x14, 0xC4, 0x2B, 0x30,
                                        0x24, 0xC6, 0x00, 0x10 };

// Self designed samples
// (There was no 'h' (Hotel, Him and Her, Help) in this French data set.)

// hooo  
const byte Sound_hooo [64] PROGMEM = {  0x00, 0x99, 0xF8, 0x10, 0xF9, 0xAC, 0x95, 0x20, 0xE4, 0xAB, 0x95, 0xA0, 0xD0, 0xAC, 0x96, 0x20, 
                                        0x90, 0x8D, 0x9E, 0xA1, 0xD0, 0xAD, 0x8E, 0xA1, 0xE4, 0xAD, 0x86, 0xA0, 0xE4, 0xAE, 0x7E, 0xA0, 
                                        0xF9, 0xD1, 0x7F, 0x20, 0xC8, 0xD3, 0x76, 0x3F, 0x40, 0xD3, 0x3B, 0xB0, 0x00, 0x90, 0x03, 0x30, 
                                        0x00, 0x96, 0xF0, 0x30, 0x00, 0x96, 0xF0, 0x30, 0x00, 0x96, 0xF0, 0x30, 0x00, 0x96, 0xF0, 0x30 };

// ho  
const byte Sound_ho [32] PROGMEM = {    0x00, 0x99, 0xF8, 0x10, 0xF9, 0xAC, 0x95, 0x20, 0xE4, 0xAB, 0x95, 0xA0, 0xD0, 0xAC, 0x96, 0x20, 
                                        0x90, 0x8D, 0x9E, 0xA1, 0xD0, 0xAD, 0x8E, 0xA1, 0xE4, 0xAD, 0x86, 0xA0, 0xE4, 0xAE, 0x7E, 0xA0 };
                               
// h
const byte Sound_h  [16] PROGMEM = {    0x95, 0x96, 0x58, 0x00, 0xD9, 0x97, 0x4C, 0x5E, 0xE9, 0xB6, 0x43, 0xDA, 0xD5, 0x95, 0x44, 0x42 };

// uhu
const byte Sound_hu [24] PROGMEM = {    0x95, 0x96, 0x58, 0x20, 0xD9, 0x97, 0x4B, 0x5E, 0xE9, 0xB6, 0x43, 0xDA, 0xD5, 0x95, 0x44, 0x42,
                                        0xF5, 0x95, 0x4D, 0xC4, 0xDA, 0xB7, 0x4F, 0x20 };

// heu
const byte Sound_he [32] PROGMEM = {    0x66, 0xB5, 0x95, 0x01, 0x77, 0xB4, 0x97, 0x20, 0x77, 0xB4, 0x97, 0xC0, 0xB7, 0xB4, 0x97, 0x5F,
                                        0x77, 0xB4, 0x97, 0x40, 0xF7, 0xB5, 0x96, 0xDF, 0xB7, 0xB5, 0x8E, 0xC0, 0xF6, 0xB5, 0xBE, 0x5F };
  
// HA (base 10 data)
const byte Sound_ha [28] PROGMEM = {  0,  80,  47,  47,  84, 179, 192,   0, 149, 176, 182,  66, 102, 178, 207,  64,
                                    102, 178, 207,  95, 106, 180, 183,  95, 132, 214,  88,   8 };
    
      
// Numbers in English 
//
const byte Sound_ZerOO [56] PROGMEM = { 0x89, 0x91, 0x88, 0x00, 0x95, 0x91, 0x83, 0x20, 0xE4, 0x90, 0x95, 0xA2, 0xE4, 0x90, 0x96, 0x25, 
                                        0xF8, 0x90, 0x96, 0xC1, 0xED, 0x90, 0x97, 0x5F, 0xE8, 0x91, 0x8E, 0xFF, 0xE9, 0x90, 0x86, 0xDE, 
                                        0xDA, 0x90, 0x7D, 0x7F, 0xDE, 0x8F, 0x7D, 0x20, 0xC5, 0x8E, 0x74, 0xFE, 0xD5, 0x8D, 0x73, 0xE0, 
                                        0xD9, 0x8D, 0x7B, 0xE0, 0xD4, 0xB0, 0x70, 0x40 };
                       
const byte Sound_One [64] PROGMEM = {   0x20, 0xA0, 0x70, 0x00, 0x95, 0x85, 0x6B, 0x40, 0x9A, 0x89, 0x7D, 0x41, 0x9A, 0x8C, 0x96, 0xC2,
                                        0xA9, 0x8E, 0x9F, 0x41, 0xAA, 0x8F, 0x9F, 0x5E, 0xA8, 0x8F, 0x97, 0x3F, 0xA8, 0x8F, 0x96, 0xDE, 
                                        0x80, 0x91, 0x64, 0xDD, 0x80, 0x6C, 0x6C, 0x40, 0xC0, 0x8D, 0x6B, 0x7F, 0x80, 0x8E, 0x6A, 0xE0, 
                                        0x80, 0xB3, 0x62, 0x40, 0x95, 0xB3, 0x84, 0x20, 0xE4, 0xB3, 0x7A, 0xC0, 0x50, 0xB1, 0x91, 0xE0 };
                            
const byte Sound_Two [64] PROGMEM = {   0x11, 0xD7, 0xC7, 0x30, 0x01, 0xD8, 0x97, 0x30, 0x42, 0xB9, 0xFF, 0x50, 0x8A, 0xB7, 0xFE, 0xB0, 
                                        0x36, 0xB5, 0x25, 0xB0, 0xED, 0x94, 0x76, 0xA0, 0xEA, 0x94, 0x76, 0xDE, 0xEA, 0x94, 0x6E, 0xDE, 
                                        0xEF, 0x93, 0x66, 0x5E, 0xEA, 0x92, 0x65, 0xDE, 0xEE, 0x92, 0x6C, 0xDE, 0xD5, 0x90, 0x63, 0xC0, 
                                        0xD4, 0x8E, 0x63, 0x5E, 0xD9, 0x8E, 0x63, 0x60, 0xD5, 0x8D, 0x63, 0x40, 0xD5, 0xAE, 0x6A, 0xC0 };
                
const byte Sound_Three [72] PROGMEM = { 0x40, 0xB9, 0xF8, 0x10, 0x45, 0xB9, 0xFA, 0x50, 0x40, 0xB9, 0xFC, 0xD0,
                                        0x45, 0xB9, 0xF6, 0x50, 0x55, 0xB9, 0xC6, 0xB0, 0x56, 0xB6, 0x9E, 0x90, 0xA6, 0x93, 0x84, 0x20, 
                                        0xE4, 0x93, 0x6D, 0x3F, 0xA0, 0x93, 0x75, 0xDE, 0xA5, 0x94, 0x6E, 0xE0, 0xE5, 0xB7, 0x6F, 0x7F,
                                        0xE4, 0xB8, 0x66, 0x7E, 0xE4, 0xB9, 0x65, 0x40, 0xE4, 0xB9, 0x5C, 0x7F, 0xE4, 0xB9, 0x5C, 0x40, 
                                        0xE1, 0xD9, 0x53, 0x40, 0xE0, 0xBA, 0x62, 0xFC, 0x84, 0xB7, 0x71, 0x40 }; 
                                        
const byte Sound_Four [64] PROGMEM = {  0x10, 0xBA, 0xFC, 0x10, 0x05, 0xB5, 0xFD, 0xF0, 0x84, 0xB5, 0xFD, 0xD0, 0x85, 0xB3, 0xE5, 0x30, 
                                        0x90, 0xAB, 0x8C, 0xA0, 0x90, 0xAA, 0x8D, 0xC0, 0x90, 0xAA, 0x8D, 0xC0, 0x90, 0xA9, 0x8D, 0xFF,
                                        0xA5, 0xA9, 0x8D, 0xDE, 0xAA, 0xA9, 0x8D, 0xDF, 0xE9, 0xA9, 0x8D, 0x7F, 0xE9, 0xAA, 0x8C, 0xDF,
                                        0xF8, 0xAA, 0x84, 0x40, 0xB5, 0xAA, 0x7A, 0xC0, 0xA4, 0xAA, 0x79, 0x40, 0x54, 0xAB, 0x80, 0x41 };

const byte Sound_Five [84] PROGMEM = {  0x55, 0xB6, 0x78, 0x10, 0x09, 0xB7, 0xFD, 0x50, 0x15, 0xB4, 0xFE, 0x70, 0x45, 0xB6, 0xFE, 0x70, 
                                        0x55, 0xB5, 0xFE, 0x30, 0x99, 0xBF, 0x9E, 0xC0, 0xAE, 0x8E, 0x9F, 0x5F, 0xAD, 0xAF, 0x9F, 0x40, 
                                        0xAC, 0xB0, 0x9F, 0x7F, 0xAC, 0xB0, 0x9E, 0xDF, 0xAB, 0xB3, 0x9E, 0x7E, 0xE8, 0xB4, 0x9D, 0xDF, 
                                        0xE8, 0xB4, 0x8D, 0xC0, 0xE4, 0xB5, 0x7C, 0x7F, 0xE8, 0xB5, 0x74, 0x40, 0x69, 0xB5, 0x7B, 0xB0,
                                        0x89, 0xB5, 0x6B, 0xD0, 0xE4, 0xB2, 0x7B, 0x50, 0xE4, 0xB2, 0x7B, 0xB0, 0xD4, 0xB2, 0x7A, 0xA1, 
                                        0x91, 0xB4, 0x71, 0x40 };

const byte Sound_Six [92] PROGMEM = {   0x01, 0xDB, 0xF8, 0x10, 0x05, 0xDB, 0xFC, 0x30, 0x06, 0xDB, 0xFD, 0x50, 0x05, 0xFB, 0xFD, 0xF0,
                                        0x01, 0xFB, 0xFE, 0xF0, 0x87, 0xBB, 0xFF, 0x30, 0x4B, 0xBB, 0xFE, 0x30, 0xE8, 0xB5, 0x76, 0xA0,
                                        0xE9, 0xB5, 0x77, 0xBE, 0xF8, 0xB6, 0x77, 0xBC, 0xE5, 0xB6, 0x77, 0x3B, 0xE9, 0xB7, 0x7E, 0xBB, 
                                        0xD5, 0x98, 0x6C, 0x5E, 0xD0, 0xB7, 0x71, 0xC0, 0xC0, 0xD6, 0x68, 0x40, 0x40, 0xB4, 0x60, 0x40,
                                        0x40, 0xD6, 0x30, 0x40, 0x40, 0xB5, 0x80, 0x20, 0x26, 0xB4, 0xBE, 0x30, 0x01, 0xD7, 0xFE, 0x50,
                                        0x04, 0xFC, 0xFE, 0x50, 0x08, 0xF9, 0xFB, 0x70, 0x05, 0xFA, 0xF8, 0xD0 };
                                    
const byte Sound_Seven [108] PROGMEM = {    0x01, 0xDB, 0xF8, 0x10, 0x05, 0xDB, 0xFC, 0x30, 0x06, 0xDB, 0xFD, 0x50, 0x05, 0xFB, 0xFD, 0xF0, 
                                            0x01, 0xFB, 0xFE, 0xF0, 0x87, 0xBB, 0xFF, 0x30, 0xE8, 0xB3, 0x8F, 0xC1, 0xE8, 0xB3, 0x8F, 0x5F, 
                                            0xE8, 0xB3, 0x86, 0xBF, 0xE4, 0xB2, 0x7D, 0x3F, 0x94, 0xB5, 0x6C, 0x5E, 0xA5, 0xB5, 0x6C, 0xBE, 
                                            0xE4, 0xB1, 0x6D, 0x20, 0xE8, 0xB1, 0x7E, 0x3F, 0xE8, 0xB1, 0x86, 0x3F, 0xE8, 0xB1, 0x8D, 0xBE, 
                                            0xEC, 0xB2, 0x85, 0x5E, 0xE8, 0xB1, 0x7D, 0x3F, 0xC0, 0x8E, 0x63, 0xBF, 0xC0, 0x8E, 0x5B, 0x5F,
                                            0xC0, 0xB2, 0x5B, 0x60, 0xD6, 0xB1, 0x6C, 0x20, 0xD4, 0xB3, 0x7C, 0x40, 0xE4, 0xB3, 0x7B, 0xBD, 
                                            0x80, 0xB5, 0x61, 0x5B, 0xA9, 0xB4, 0x70, 0x3E, 0x50, 0xD8, 0x8A, 0xD0 };
                    
const byte Sound_Eight [64] PROGMEM = {     0xE8, 0xB3, 0x90, 0x00, 0xE8, 0xB4, 0x95, 0x20, 0xE8, 0xB4, 0x97, 0x5F, 0xE8, 0xB5, 0x87, 0x5F, 
                                            0xE8, 0xB7, 0x7E, 0xDF, 0xE8, 0xB8, 0x76, 0x5D, 0xE0, 0xB9, 0x5B, 0x5B, 0xE0, 0xD8, 0x6C, 0x39, 
                                            0xC0, 0xD6, 0x71, 0x5D, 0x40, 0xD6, 0x70, 0x7F, 0x15, 0xB6, 0xC0, 0x70, 0x56, 0xD7, 0xDF, 0xB0,
                                            0x12, 0xDA, 0xFE, 0xD0, 0x7B, 0xB5, 0xB4, 0xF0, 0x40, 0xB4, 0x9A, 0x70, 0x40, 0xB4, 0x98, 0x50 };
                                                
const byte Sound_Nine [68] PROGMEM = {  0x40, 0xB5, 0x78, 0x00, 0xD0, 0xAA, 0x5B, 0xC0, 0xC0, 0xAC, 0x5C, 0xC1, 0xC0, 0xD0, 0x65, 0xC0,
                                        0xE9, 0xB2, 0x7E, 0xA1, 0xE8, 0xB2, 0x86, 0xA1, 0xF8, 0xB2, 0x96, 0xC0, 0xE8, 0xB3, 0x97, 0x5E,
                                        0xF9, 0xB3, 0x96, 0xDF, 0xF9, 0xB4, 0x96, 0xDF, 0xE8, 0xB5, 0x8E, 0x5E, 0xE8, 0xB6, 0x7D, 0xDF,
                                        0xD4, 0xB7, 0x7C, 0xDF, 0x84, 0xAB, 0x73, 0x21, 0x80, 0xAC, 0x62, 0xE0, 0xC5, 0xAE, 0x62, 0xE0,
                                        0x00, 0x00, 0x00, 0x3B  };
                                     
const byte Sound_Ten [76] PROGMEM = {   0x00, 0xB6, 0x90, 0x10, 0x11, 0xD7, 0xD6, 0xB0, 0x45, 0xD7, 0xF7, 0xB0, 0x0A, 0xB7,
                                        0xFF, 0x50, 0x2A, 0xB5, 0xC6, 0x30, 0xA9, 0xB5, 0x8D, 0xA0, 0xE8, 0xB5, 0x87, 0x40, 0xF8, 0xB5, 
                                        0x97, 0x5E, 0xF8, 0xB5, 0x97, 0x5E, 0xE8, 0xB5, 0x96, 0xDE, 0xE8, 0xB5, 0x96, 0x3E, 0xE8, 0xB4, 
                                        0x7D, 0x3D, 0x90, 0xAC, 0x63, 0xBF, 0x80, 0x8D, 0x5C, 0x5F, 0xC0, 0xAD, 0x64, 0x40, 0xC0, 0xAD, 
                                        0x6B, 0xA0, 0xC0, 0xAD, 0x6A, 0xA0, 0xC4, 0xAD, 0x69, 0xA0, 0xC0, 0x96, 0x70, 0x59 };

const byte Sound_Eleven [120] PROGMEM = {   0x10, 0xD8, 0x58, 0x00, 0xE2, 0xB8, 0x65, 0x40, 0xE8, 0xB8, 0x6E, 0xC0, 0xE8, 0xB6,
                                            0x6F, 0xC0, 0xE8, 0xB6, 0x6F, 0x20, 0xE1, 0xD4, 0x5D, 0xC0, 0xE0, 0xD4, 0x65, 0xC0, 0xE4, 0xD3, 
                                            0x5D, 0xC0, 0xE8, 0xB3, 0x76, 0xA1, 0xE8, 0xB3, 0x87, 0xA4, 0xE8, 0xB3, 0x8F, 0xC1, 0xE8, 0xB3,
                                            0x8F, 0x5F, 0xE8, 0xB3, 0x86, 0xBF, 0xE4, 0xB2, 0x7D, 0x3F, 0x94, 0xB5, 0x6C, 0x5E, 0xA5, 0xB5,
                                            0x6C, 0xBE, 0xE4, 0xB1, 0x6D, 0x20, 0xE8, 0xB1, 0x7E, 0x3F, 0xE8, 0xB1, 0x86, 0x3F, 0xE8, 0xB1,
                                            0x8D, 0xBE, 0xEC, 0xB2, 0x85, 0x5E, 0xE8, 0xB1, 0x7D, 0x3F, 0xC0, 0x8E, 0x63, 0xBF, 0xC0, 0x8E,
                                            0x5B, 0x5F, 0xC0, 0xB2, 0x5B, 0x60, 0xD6, 0xB1, 0x6C, 0x20, 0xD4, 0xB3, 0x7C, 0x40, 0xE4, 0xB3,
                                            0x7B, 0xBD, 0x80, 0xB5, 0x61, 0x5B, 0xA9, 0xB4, 0x70, 0x3E };
        
const byte Sound_Twelve [88] PROGMEM = {    0x00, 0xF9, 0xF8, 0x10, 0x01, 0x99, 0xFF, 0x30, 0x86, 0x98, 0xFE, 0xB0, 0x81, 0xB7, 0xFE, 0x30, 
                                            0x55, 0xB2, 0xB4, 0xD0, 0x50, 0xB1, 0x8B, 0xB0, 0xE0, 0xBB, 0x73, 0xA0, 0xEA, 0x8D, 0x7E, 0x40,
                                            0xE8, 0x91, 0x97, 0x40, 0xE9, 0xB2, 0x9F, 0xFE, 0xE8, 0xAF, 0x8E, 0xFE, 0xE8, 0xAC, 0x85, 0x7F,
                                            0xE4, 0xAB, 0x7B, 0xFF, 0xE8, 0xAB, 0x72, 0xC0, 0xE5, 0xAC, 0x6A, 0xDD, 0xE5, 0xAC, 0x6A, 0xDD,
                                            0x40, 0xB6, 0x75, 0x20, 0x04, 0xB3, 0xC5, 0x50, 0x24, 0xB1, 0xB5, 0x50, 0x26, 0xB1, 0x93, 0xB0, 
                                            0xA4, 0xB2, 0x7B, 0x5F, 0x60, 0xB3, 0x81, 0xC0 };

const byte Sound_Thir_ [68] PROGMEM = {     0x05, 0xB9, 0xE8, 0x10, 0x04, 0xB7, 0xFC, 0xB0, 0x04, 0xB9, 0x8D, 0x30, 0x05, 0xB8, 0xA5, 0xB0,
                                            0x05, 0xB8, 0xAE, 0x30, 0x05, 0xB8, 0xAE, 0x30, 0x09, 0xB7, 0xA5, 0xB0, 0x5A, 0xB7, 0x85, 0x30,
                                            0xE9, 0xB3, 0x77, 0x40, 0xFD, 0xB3, 0x87, 0x5F, 0xE9, 0xB3, 0x8F, 0x7F, 0xF9, 0xB3, 0x87, 0x3F, 
                                            0xE9, 0xB3, 0x86, 0xDE, 0xE5, 0xB3, 0x7E, 0x20, 0x80, 0xB3, 0x7A, 0x5E, 0xD1, 0xB5, 0x79, 0xA1, 
                                            0x15, 0xB7, 0xBD, 0xB0 };

const byte Sound_Four_  [52] PROGMEM = {    0x10, 0xBA, 0xF8, 0x10, 0x05, 0xB5, 0xFE, 0x70, 0x84, 0xB5, 0xFD, 0xD0, 0x85, 0xB3,
                                            0xE5, 0x30, 0x90, 0xAB, 0x8C, 0xA0, 0x90, 0xAA, 0x8D, 0xC0, 0x90, 0xAA, 0x8D, 0xC0, 0x90, 0xA9,
                                            0x8D, 0xFF, 0xAA, 0xA9, 0x8D, 0xDD, 0xE9, 0xA9, 0x8D, 0x7F, 0xE9, 0xAA, 0x8C, 0xDF, 0xF8, 0xAA,
                                            0x84, 0x40, 0xB5, 0xAA, 0x7A, 0xC0 };

const byte Sound_Fif_ [64] PROGMEM = {      0x25, 0xB3, 0xF8, 0x10, 0x12, 0xB4, 0xFB, 0x50, 0x16, 0xB3, 0xFB, 0xD0, 0x05, 0xB4, 0xFC, 0x50, 
                                            0x05, 0xB5, 0xFC, 0xD0, 0x1A, 0xB5, 0xFE, 0x50, 0x1A, 0xB5, 0xFE, 0x30, 0x1E, 0xB5, 0xCC, 0xB0,
                                            0xE9, 0x94, 0x76, 0x20, 0xE9, 0x94, 0x76, 0x20, 0xE9, 0x94, 0x76, 0xC0, 0xE1, 0xB6, 0x6D, 0xA0,
                                            0x16, 0xB6, 0xFE, 0xD0, 0x06, 0xB9, 0xFE, 0x50, 0x05, 0xB5, 0xFD, 0xF0, 0x05, 0xB8, 0xFD, 0xF0 };
                          
const byte Sound__teen [96] PROGMEM = {     0x01, 0xD8, 0xF8, 0x10, 0x01, 0xD8, 0xFE, 0x10, 0x11, 0xD9, 0xFE, 0xB0, 
                                            0x46, 0xD9, 0xFF, 0x30, 0x45, 0xD8, 0xFF, 0x30, 0x2A, 0xB7, 0xF7, 0x30, 0xAE, 0xB7, 0x7D, 0xB0, 
                                            0xE8, 0xB8, 0x65, 0xC0, 0xE4, 0xB9, 0x64, 0xE0, 0xE4, 0xB9, 0x64, 0xA0, 0xE1, 0xBA, 0x74, 0xBF, 
                                            0xE0, 0xBA, 0x74, 0xDF, 0xE4, 0xBA, 0x6C, 0xA0, 0xE0, 0xDA, 0x6C, 0xC0, 0x80, 0xB9, 0x5A, 0xDE, 
                                            0xC0, 0x98, 0x62, 0xDF, 0x80, 0x76, 0x62, 0xC0, 0x80, 0x95, 0x62, 0xC0, 0x80, 0xD5, 0x63, 0x21, 
                                            0xEA, 0xB4, 0x75, 0x20, 0xD4, 0xB4, 0x7B, 0xA0, 0xA0, 0xD4, 0x7A, 0xC0, 0xA4, 0xB4, 0x91, 0x43, 
                                            0x60, 0xB4, 0x90, 0x25 };

const byte Sound_Twen_ [64] PROGMEM = {     0x50, 0xB6, 0xA0, 0x10, 0x05, 0xB6, 0xBE, 0x90, 0x01, 0xB5, 0xD7, 0xB0, 0x29, 0xB4, 0xC6, 0xB0,
                                            0x80, 0x96, 0xB5, 0xD0, 0x24, 0x8F, 0xBC, 0xB0, 0xA4, 0x8F, 0x83, 0xA0, 0xF9, 0x8F, 0x7E, 0x20,
                                            0xE9, 0x91, 0x87, 0x3F, 0xE8, 0x93, 0x8F, 0x3E, 0xE8, 0x94, 0x8F, 0x3E, 0xE8, 0xB5, 0x87, 0x3E,
                                            0xD8, 0xB5, 0x6E, 0xBE, 0xD0, 0xAF, 0x54, 0x5E, 0xC0, 0xB1, 0x53, 0xFF, 0x50, 0xD7, 0x68, 0xE0 };
            
const byte Sound__ty [60] PROGMEM = {   0x50, 0xD7, 0x68, 0x00, 0x16, 0xDB, 0xED, 0xD0, 0x8A, 0xB7, 0xFE, 0x50, 0x06, 0xB6, 0xB6, 0x30,
                                        0x9E, 0xB6, 0x9C, 0xB0, 0xC4, 0xB5, 0x6B, 0xBE, 0xE8, 0xB7, 0x6D, 0xDE, 0xE8, 0xB8, 0x6D, 0xDE, 
                                        0xD4, 0xB9, 0x6B, 0xDF, 0xC4, 0x99, 0x6B, 0xC0, 0xD9, 0xB8, 0x62, 0xC0, 0x94, 0xB8, 0x7B, 0x50,
                                        0x84, 0xB6, 0x92, 0x50, 0x55, 0xB6, 0x80, 0xD0, 0x55, 0xB6, 0x80, 0x30 };
                                    
const byte Sound_Hundred [92] PROGMEM = {   0x14, 0xB3, 0x60, 0x00, 0x64, 0xB2, 0x9D, 0xB0, 0x64, 0xB2, 0xAD, 0xB0, 0x64, 0xB2, 0x95, 0xD0, 
                                            0x91, 0xD0, 0x85, 0x42, 0xA4, 0xCF, 0x9E, 0xA2, 0xA4, 0xD0, 0x9F, 0x3F, 0x81, 0x91, 0x75, 0xDE, 
                                            0x80, 0xB1, 0x5D, 0x5F, 0xC0, 0xB0, 0x5D, 0x5F, 0xC0, 0xAD, 0x5B, 0x5F, 0xD0, 0xB5, 0x52, 0xA0,
                                            0x14, 0xB6, 0x87, 0x30, 0x14, 0xB7, 0x6F, 0x30, 0xE5, 0x92, 0x76, 0x41, 0xE5, 0x93, 0x7E, 0xE0,
                                            0xE5, 0x93, 0x76, 0x22, 0xE8, 0xB4, 0x5E, 0x20, 0xC0, 0xB5, 0x6A, 0x5E, 0x05, 0xB7, 0x9D, 0xB0,
                                            0x14, 0xDB, 0xE6, 0x30, 0x66, 0xB4, 0x7C, 0x50, 0xB1, 0xB4, 0x62, 0x57 };

const byte Sound_Telephone [124] PROGMEM = {    0x01, 0xB7, 0xE0, 0x10, 0x01, 0xB7, 0xDE, 0x30, 0x42, 0xB7, 0xA6, 0xB0, 0x16, 0xB6, 0x7E, 0xB0,
                                                0x65, 0xB5, 0x96, 0x30, 0xA0, 0xB4, 0x8D, 0xA0, 0xE0, 0xB4, 0x8F, 0x3F, 0xE1, 0xB3, 0x8F, 0xC0,
                                                0xE2, 0x92, 0x5D, 0x40, 0xE2, 0xD3, 0x55, 0x21, 0xE5, 0xB4, 0x7F, 0x40, 0xE4, 0xB4, 0x76, 0xA1, 
                                                0xD0, 0xB3, 0x64, 0xDE, 0x94, 0xB5, 0x6C, 0xBF, 0x15, 0xB5, 0x6D, 0xB0, 0x2A, 0xB4, 0x8C, 0xF0, 
                                                0xEA, 0xB2, 0x8E, 0xDE, 0xF8, 0xB1, 0x96, 0xC0, 0xE8, 0xB1, 0x96, 0xC0, 0xE8, 0xB1, 0x8E, 0x7F,
                                                0xE4, 0xB2, 0x7E, 0x7F, 0xC4, 0xB0, 0x5C, 0xC0, 0xC4, 0xB0, 0x5C, 0x40, 0xC0, 0xAE, 0x5B, 0xC0,
                                                0xD0, 0xAC, 0x5A, 0xA1, 0x80, 0xD1, 0x64, 0xA1, 0xD0, 0xD3, 0x7C, 0x22, 0xC0, 0xB0, 0x73, 0x22,
                                                0x80, 0xAF, 0x72, 0xA1, 0xB6, 0xB3, 0x71, 0xA0, 0x17, 0xB4, 0x60, 0x60 };

const byte Sound_Number [96] PROGMEM = {    0x17, 0xB4, 0x60, 0x60, 0x40, 0x8D, 0x7A, 0x21, 0xD0, 0x8B, 0x53, 0x20, 0xC4, 0xAF, 0x5B, 0xC0, 
                                            0xE9, 0xB2, 0x8E, 0xC0, 0xE5, 0xB1, 0x96, 0xC0, 0xE6, 0xAF, 0x8E, 0x41, 0x91, 0x8E, 0x5D, 0x40,
                                            0xD5, 0x8F, 0x54, 0xE0, 0xC0, 0x91, 0x5C, 0xA0, 0xD0, 0x8F, 0x53, 0xDF, 0xC0, 0x8E, 0x53, 0x21,
                                            0xC0, 0xAE, 0x52, 0xA1, 0xA4, 0xB1, 0x7E, 0x21, 0xE5, 0xB0, 0x8E, 0xA1, 0xE5, 0xB1, 0x95, 0xFF,
                                            0xE5, 0xB1, 0x95, 0xA2, 0xE5, 0xB1, 0x8C, 0xC0, 0xE5, 0xB0, 0x8C, 0x20, 0xD0, 0xB0, 0x83, 0xA1,
                                            0x94, 0xB2, 0x73, 0x3F, 0x95, 0xB2, 0x8A, 0x5E, 0x95, 0xB2, 0x89, 0x40, 0x95, 0xB2, 0x88, 0x40 }; 

const byte Sound_Code [76] PROGMEM = {  0x10, 0x97, 0xD0, 0x10, 0x38, 0x97, 0xAF, 0x30, 0x75, 0xB7, 0xE6, 0xD0, 0x26, 0xB6, 0xFE, 0x30, 
                                        0x66, 0xB3, 0x85, 0x20, 0xE6, 0x92, 0x8E, 0xA9, 0xE5, 0x92, 0x96, 0xC0, 0xFE, 0x92, 0x7E, 0x7F,
                                        0xFA, 0x92, 0x6E, 0x60, 0xEA, 0x92, 0x66, 0x60, 0xEE, 0x93, 0x65, 0xE0, 0xD0, 0xB3, 0x62, 0x5D,
                                        0x11, 0xB6, 0xCE, 0xB0, 0x15, 0xD6, 0xD7, 0x90, 0x06, 0xB4, 0xE6, 0x30, 0xBA, 0xB4, 0x5C, 0xB0,
                                        0xE4, 0xB4, 0x5B, 0x5D, 0x00, 0xB4, 0x59, 0x60, 0x00, 0x00, 0x00, 0x70 };

const byte Sound_And [60] PROGMEM = {   0x00, 0xB7, 0x60, 0x00, 0x90, 0xB2, 0xA3, 0x40, 0xA8, 0xB3, 0xA6, 0x40, 0xE8, 0xB3, 0xA6, 0xFF, 
                                        0xA8, 0xB3, 0x9E, 0x5F, 0xEC, 0xB2, 0x96, 0x40, 0x81, 0xB1, 0x64, 0xC0, 0x94, 0xAD, 0x5C, 0x41,
                                        0xD4, 0xAC, 0x54, 0x40, 0xC0, 0xB0, 0x4B, 0xDF, 0x85, 0xD8, 0x54, 0x20, 0x45, 0xBA, 0x9E, 0x30,
                                        0x46, 0xDA, 0x76, 0xB0, 0xED, 0xB2, 0x64, 0xD8, 0x40, 0xD7, 0x61, 0xDD };

// From catalog 2
// Formatted (C-code) from the OCR-ed data files
// (Here the values are in base-10)

const byte Sound_C2_A [48] PROGMEM = {
       0,  48,  47,  47,   0, 153, 248,   0, 153, 177, 204, 143, 234, 176, 197, 160,
     246, 177, 198,  64, 186, 177, 198, 160, 186, 177, 206, 223, 186, 177, 206,  63,
     186, 177, 197, 160, 184, 145, 189,  32, 164, 145, 180,  32, 173, 145, 168,  23 };

const byte Sound_C2_ACCOLADE [184] PROGMEM = {
       0, 184,  47,  47,   0, 117, 248,   0,   0, 117, 250, 144, 184, 180, 173,   6,
     185, 180, 174,   7, 233, 148, 174,  32, 185, 149, 158,  62, 121, 118, 126,  61,
     160, 151, 124, 160, 132, 119, 147,  32, 144, 150, 130,  32,  80, 148, 136,  80,
      96, 181, 235, 159,  16, 116, 221,  16,  32, 177, 109,  48, 218, 144, 108,  40,
     174, 144, 117,  62, 234, 144, 125, 159, 234, 146, 125, 191, 169, 146, 126,  27,
     169, 148, 118,  32, 100, 181,  93, 160, 188, 180,  93, 192, 108, 181, 110,   3,
     184, 181, 142, 128, 248, 181, 151,   0, 185, 180, 175,  64, 185, 180, 175,  64,
     189, 181, 159,  64, 184, 181, 142, 188, 184, 181, 126,   0, 184, 181, 109, 128,
     136, 181, 104,  32,  64, 151, 128,  64,  64, 181,  66, 128,   5, 181,  35, 128,
     190, 181, 100,  64, 250, 180, 115, 160, 237, 180, 115,   0, 237, 179, 131,  64,
     228, 179, 122, 223, 216, 179, 122,  29, 216, 179, 113, 159, 217, 179, 113,   1,
     213, 178, 112, 159, 144, 178, 112,   7 };

const byte Sound_C2_AIMER [76] PROGMEM = {
       0,  76,  47,  47,   0, 153, 248,   0, 182, 184, 101,  60, 245, 184,  94,  32,
     246, 184, 102,  65, 245, 184, 110, 192, 170, 182,  86,  64, 132, 183,  52, 223,
     136, 183,  52, 192, 137, 183,  53,  63, 137, 183,  53,  64, 102, 184,  95,  34,
     118, 184, 103,  63, 186, 184, 119,  63, 249, 185, 102, 192, 229, 185,  93, 192,
     245, 185,  93, 193, 229, 185,  84,  34, 229, 185,  88,   2 };

const byte Sound_C2_ALLER [76] PROGMEM = {
       0,  76,  47,  47,  41, 181, 216,   0, 105, 181, 197, 155, 248, 181, 182, 160,
     184, 182, 166, 192, 185, 182, 151,  64, 188, 182, 111,  64, 188, 183, 102, 160,
     188, 183,  94,  63, 189, 183,  94,  63, 186, 182,  85, 191, 122, 183,  78,  33,
     185, 184, 102, 192, 185, 185,  94, 223, 245, 185,  86,  32, 228, 185,  84, 191,
     229, 185,  76,  62, 229, 185,  91, 133, 212, 185,  72,  14 };

const byte Sound_C2_ALORS [92] PROGMEM = {
       0,  92,  44,  47,  40, 181, 216,   0, 252, 181, 182,  32, 212, 181, 182,  32,
     232, 181, 175,  32, 248, 182, 159,  64, 249, 182, 143,  33, 184, 182, 119,  63,
     188, 181, 110, 160, 172, 181, 102, 160, 250, 181, 127,  64, 170, 180, 143,  95,
     170, 179, 143,  95, 170, 178, 134, 192, 170, 177, 134,  63, 238, 176, 133, 223,
     154, 176, 133,  95, 170, 176, 124, 192,  90, 176, 132,  63, 123, 175, 124,  32,
     110, 174, 100,  80,  38, 173,  76,  80,  34, 174,  72,  15 };

const byte Sound_C2_AMI [56] PROGMEM = {
       0,  56,  47,  47,  84, 180, 168,   0, 169, 180, 175,   2, 184, 180, 175,  32,
     165, 181, 167,  64, 169, 182, 143,  64,  85, 149, 102,  63, 132, 150,  69, 160,
     160, 216,  69, 224, 133, 151,  52, 189, 201, 215,  52, 224, 196, 246,  60, 224,
      64, 216,  52,  95,  69, 217,  24,  10 };

const byte Sound_C2_ANIMAL [108] PROGMEM = {
       0, 108,  47,  47,  20, 182, 128,   0, 164, 182, 165, 130, 216, 181, 159,  64,
     168, 182, 134, 161, 108, 183, 101, 160, 163, 183,  76, 193, 162, 184,  69,  32,
     136, 215,  78,  32, 136, 214,  78, 160, 137, 215,  87,  64, 134, 184,  78, 190,
     133, 181,  69, 160, 133, 181,  69, 223, 132, 180,  61, 223, 169, 181, 159,  94,
     105, 180, 159,  95, 121, 180, 151,  64, 169, 181, 174, 223, 169, 181, 134,  64,
     252, 181, 117, 192, 237, 181, 109, 192, 237, 181, 109, 192, 108, 181, 101,  64,
     172, 181, 101,  64, 169, 181, 116, 163, 109, 181, 152,  14 };

const byte Sound_C2_ANIMAUX [100] PROGMEM = {
       0, 100,  47,  47, 101, 180,  80,   0, 164, 181, 165,  17, 248, 181, 175,   0,
     252, 181, 174,   0, 228, 182, 158, 166, 216, 182, 151,  35, 232, 182, 135,  33,
     216, 183, 127,  33, 108, 183,  78,  32, 172, 183,  69, 162, 145, 151,  68, 192,
     136, 212,  69,  64, 133, 215,  78, 192, 136, 183,  69, 222, 132, 184,  69, 223,
     136, 181,  53,  95,  73, 179,  52, 223, 142, 174,  92, 186, 142, 172, 108, 192,
     142, 170, 108, 192, 141, 169, 100,  64,  46, 165,   3, 223,  46, 165,   0,  13,
      46, 165,   0,  12 };

const byte Sound_C2_ANNEE [80] PROGMEM = {
       0,  80,  47,  47, 164, 181, 184,   0, 164, 181, 187, 157, 228, 182, 189, 128,
     224, 182, 175,  32, 152, 183, 167,  64, 152, 183, 126, 192, 136, 183, 101, 160,
     140, 178,  60, 161, 140, 179,  61,  32, 140, 182,  61,  63, 140, 179,  61,  63,
     140, 178,  52, 191, 204, 183,  52, 160, 232, 184,  94,  95, 212, 185,  85, 223,
     153, 185,  77, 222, 169, 185,  76,  32, 234, 185,  75, 137, 165, 185,  56,  14 };

const byte Sound_C2_ANNIVERSAIRE [140] PROGMEM = {
       0, 140,  47,  47,   0, 153, 248,   0, 164, 182, 173, 192, 164, 182, 142,  64,
     152, 183, 117, 161, 140, 182,  68,  66, 136, 183,  68, 192, 136, 217,  78,  32,
     229, 217,  78,  64, 182, 184,  85, 222, 169, 182, 101,  64, 250, 183, 118, 162,
     250, 183, 127,  32, 185, 183, 135,  32, 185, 182, 135,  32, 165, 182, 125, 191,
     101, 182, 133, 144,  36, 181, 134,  48,  64, 187, 134,  80,  17, 182, 133, 176,
      17, 215, 125,  48,   5, 182, 125,  80,   5, 184, 117,  80,  86, 215, 118,  80,
     230, 182, 110,  23, 248, 181, 126,  32, 232, 181, 126,  60, 233, 182, 134,  63,
     185, 183, 126,  96, 230, 182, 117, 189, 186, 183, 101, 224, 117, 183, 116, 192,
     181, 183, 115,  64, 170, 183, 112,   7, 170, 183, 112,  14 };

const byte Sound_C2_ANTI [100] PROGMEM = {
       0, 100,  47,  47,   0, 153, 248,   0,  21, 175, 187,  15,  85, 176, 189, 128,
      86, 175, 182,   0,  86, 174, 183,  32,  86, 174, 191,  33,  82, 174, 191,  32,
      86, 173, 175,  32,  84, 173, 167,  64,  68, 173, 158, 158,  65, 145, 150,  32,
       8, 179, 125, 191,  72, 178, 101,  31, 152, 178,  92, 158, 152, 178,  76,  29,
     152, 178,  75, 128, 128, 214,  96, 112,   8, 215,   5, 208, 221, 216,  62,  48,
     229, 216,  61, 165, 240, 216,  61,  94, 228, 216,  60, 158, 152, 185,  60, 224,
      89, 184,  16,  25 };

const byte Sound_C2_APPRENDRE [116] PROGMEM = {
       0, 116,  47,  47, 185, 180, 200,   0, 152, 180, 188, 156, 165, 179, 182, 194,
     169, 179, 158,  34,  64, 147, 140,  63, 132, 178, 144,  80, 133, 186, 232, 112,
     137, 174, 229, 176,  25, 170,   5,  61,  22, 171, 181, 160,  26, 171, 190,  33,
      69, 175, 198, 192,  70, 175, 198, 223,  26, 169, 198,  95,  27, 169, 197, 223,
      26, 170, 181, 192,  26, 173, 157, 223,  94, 175, 141, 191,  31, 176, 117,  60,
      17, 178,  80, 112, 110, 177, 125, 165,  25, 174,   5,  63,  42, 176,   4, 188,
      42, 176, 157,  64, 106, 176, 148,  63,  42, 175,   3,  32,  26, 175,  66, 140,
      27, 176,  16,  14 };

const byte Sound_C2_APPUI [104] PROGMEM = {
       0, 104,  48,  47, 133, 182, 112,   0,  68, 178, 198,   5, 106, 181, 143,  64,
     185, 181, 143,  32, 149, 180, 126, 160, 153, 180,  94,  63, 132, 179,  67, 160,
     128, 214, 120,  80, 128, 214, 120, 112,   1, 183,   4, 144,  22, 183,   7, 176,
      21, 183,   6,  16,   5, 151, 166,  16,  37, 182, 238,  48,  36, 182,   5,  16,
     181, 183,  45,  34, 209, 151,  44, 192, 166, 150,  45,  32, 234, 151,  37, 160,
     230, 217,  46,  96, 225, 217,  46,  65, 228, 217,  45, 162, 229, 217,  45,  64,
     217, 185,  37, 161,  89, 218,   0,  17 };

const byte Sound_C2_APRES [68] PROGMEM = {
       0,  68,  47,  47, 249, 179, 184,   0, 148, 179, 190,  31, 164, 179, 182, 224,
     164, 179, 174,  64, 164, 178, 150,  64, 164, 178, 123, 161,  18, 210, 136, 112,
      22, 180, 183,  80, 165, 182,  86,  64, 165, 182, 117, 160, 185, 182, 110,  32,
     186, 183, 102, 223, 186, 183, 102, 192, 186, 183, 102,  95, 186, 183, 101, 191,
     186, 183,  96,   9 };

const byte Sound_C2_ARRET [76] PROGMEM = {
       0,  76,  46,  47,   0, 181, 208,   0, 100, 178, 189, 191, 170, 179, 190, 160,
      21, 179, 190, 193,  85, 179, 199,  64, 105, 178, 191,  62,  85, 178, 182, 160,
     106, 178, 157, 191,  36, 177, 254,  48,  37, 178,  46,  48,  21, 179, 253, 208,
      21, 180, 126,  80, 105, 181, 125,  36, 149, 183, 134,  94, 246, 183, 125, 223,
     246, 183, 117, 192, 181, 184, 100,  94, 181, 184,  80,  15 };

const byte Sound_C2_ASSEZ [88] PROGMEM = {
       0,  88,  47,  47,   0, 180, 208,   0, 248, 181, 165, 185, 216, 181, 159,  64,
     180, 181, 126, 193, 244, 182, 126,  64, 101, 183, 134,  64,  33, 215, 174, 208,
      38, 183, 182, 208,  38, 215, 214,  80,  38, 183, 230, 208,  23, 183, 150,  80,
     187, 182,  86,  48, 244, 182,  85, 190, 249, 183,  85, 192, 224, 184,  85, 192,
     229, 184,  85, 192, 213, 185,  85, 160, 213, 185,  85, 162, 212, 184,  85,  33,
     201, 184,  68, 161, 196, 184,  64,   6 };

const byte Sound_C2_ASSIETTE [144] PROGMEM = {
       0, 144,  47,  47,  20, 182, 216,   0, 168, 181, 182,   3, 228, 181, 174, 160,
     168, 181, 175,  32, 184, 181, 158, 161, 168, 181, 142,  32, 153, 183, 125, 191,
       4, 183,  94,  48,   1, 215, 133, 208,   5, 184, 125,  80,  21, 216, 117,  80,
       9, 218, 110,  80,   8, 219, 102,  80,  88, 217,  69,  32, 246, 184,  86,  62,
     245, 184, 110, 190, 185, 183, 143,  94, 233, 183, 126, 190, 185, 183, 118,  63,
     225, 183,  84,  32, 192, 182, 112,  48, 192, 182, 112,  80, 192, 182, 112, 112,
      16, 215, 184, 112,  21, 214, 219, 144, 102, 215, 236,  16,  22, 182, 204,  16,
     102, 181, 115, 159, 214, 180, 114, 159, 214, 180, 113, 192, 106, 180, 113, 190,
      85, 180,  81,  63,  89, 179, 145,  63,  89, 179, 121,  15,  37, 180,  96,  14 };

const byte Sound_C2_ASTERISQUE [168] PROGMEM = {
       0, 168,  47,  47,   4, 180, 224,   0,   4, 180, 228,  11, 168, 180, 190, 128,
     168, 180, 183,  64, 168, 180, 167,  32,  99, 180, 141, 191,  88, 181, 101,  62,
       4, 182,   5,  48,  84, 183, 189, 208,   4, 151, 253,  80,   4, 151, 252, 144,
       4, 151, 248,  48,   4, 151, 248, 112,   0, 183, 245, 144,   4, 183, 198,  16,
      88, 183, 110, 144, 168, 183,  94,  14, 248, 184,  94, 191, 232, 184,  94, 189,
     228, 184,  94, 191, 233, 184, 103,  62, 232, 184, 110, 191, 152, 183, 110,  62,
     153, 182, 101, 187, 166, 184,  96,  80, 150, 183, 100, 138, 149, 184,  93, 130,
     152, 184,  86,   0, 148, 185,  85, 159, 224, 217,  69,  95, 228, 217,  60, 223,
      20, 182, 244, 240, 137, 152, 252, 208, 137, 152, 248, 112,  17, 153, 252, 144,
      16, 185, 253, 144,  20, 185, 190,  16, 169, 183,  93,  16, 200, 150, 107, 189,
     216, 150, 114, 160, 216, 150, 112,  14 };

const byte Sound_C2_AU [40] PROGMEM = {
       0,  40,  47,  47,   0, 151, 216,   0, 254, 169, 108, 188, 202, 168, 109,  65,
     135, 167, 117,  64, 218, 169, 101,  64, 217, 167,  92, 223, 130, 169, 100,  62,
     150, 168,  91, 191, 129, 167,  88,  14 };

const byte Sound_C2_AUSSI [76] PROGMEM = {
       0,  76,  47,  47,  20, 167, 104,   0,  89, 171, 100,   2, 153, 171, 101,  32,
     141, 171, 109, 160,  90, 175, 101, 193, 165, 179,  93, 192, 149, 182, 101,  32,
       1, 184,  69,  16, 103, 216, 118,  80, 102, 216, 109, 208,  98, 215, 126,  48,
      27, 183,  94, 112,  11, 216,  78, 112, 174, 216,  77, 188, 238, 216,  53,  63,
     250, 216,  53,  96, 233, 217,  52, 223, 234, 217,  48,   8 };

const byte Sound_C2_AVANT [84] PROGMEM = {
       0,  84,  47,  47, 117, 179, 160,   0, 164, 179, 167,  60, 184, 180, 183,  64,
     164, 178, 159,  64, 169, 178, 151,  33, 181, 178, 134,  32, 170, 177, 117, 191,
     190, 177, 125, 190, 149, 178,  92, 189, 105, 177,  76, 160,  41, 177,  68, 191,
      25, 176,   5,  65, 252, 174, 117, 193, 186, 173, 134,  64,  90, 171, 142,  64,
      74, 168, 141, 192,  70, 171, 142,  66,  73, 171, 149, 161,   5, 166, 132,  63,
      68, 173, 120,   4 };

const byte Sound_C2_AVOIR [96] PROGMEM = {
       0,  96,  47,  47,  41, 180, 232,   0, 120, 179, 182,  11, 164, 180, 191,  32,
     170, 180, 142, 192, 154, 178, 125, 221, 150, 178, 108,  62,  65, 181, 116,  60,
       1, 183,   5, 208,  69, 179, 109, 195,  90, 172, 109, 192,  22, 169, 118, 192,
      43, 171, 119,  63, 111, 175, 151,  64, 190, 176, 166, 192, 187, 177, 166, 223,
     174, 177, 158,  95, 105, 177, 158,  64,  58, 177, 142,  64, 122, 177, 125, 192,
      38, 176, 180, 240, 129, 178, 252,  80,  54, 177, 211, 176,  34, 176,   0,  11 };

const byte Sound_C2_B [80] PROGMEM = {
       0,  80,  47,  47, 209, 180,   0,   0, 197, 180,  11, 135, 212, 180,   4,  61,
     213, 180,   4, 159, 213, 180,   4, 128, 192, 181,   2,  13, 198, 180,  20, 131,
     198, 184,  78, 128, 217, 183,  95,  32, 216, 184,  87,  61, 233, 184,  78, 224,
     228, 185,  78, 192, 232, 185,  78, 158, 229, 185,  69,  31, 217, 185,  76, 159,
     212, 186,  59, 128, 216, 185,  67,   4, 224, 185,  50, 128, 200, 185,  32,  22 };

const byte Sound_C2_BARRE [92] PROGMEM = {
       0,  92,  47,  47, 149, 179,   0,   0, 149, 178,  11, 152, 152, 178,  69,   2,
     168, 178, 134,   1, 184, 179, 158, 130, 189, 179, 190, 224, 189, 178, 198, 224,
     125, 178, 198, 160, 168, 178, 198,  95, 188, 177, 181, 192, 184, 177, 173,  63,
     188, 177, 164, 191, 168, 177, 147, 144, 168, 175, 131, 208, 184, 176, 131,  48,
     101, 176,  99,  48, 121, 177, 131,  48, 121, 177, 115,  48,  32, 210,   3,  48,
      52, 177, 179,  48,  32, 177,  98, 176,  32, 177,  96,  11 };

const byte Sound_C2_BAS [48] PROGMEM = {
       0,  48,  47,  47, 169, 177,  56,   0,   0, 152,  84, 157,   0, 152, 102,   6,
      68, 151, 159,  29, 173, 178, 135,  63, 173, 178, 166, 192, 109, 178, 182, 255,
     172, 178, 181, 160,  72, 176, 196,  32,  92, 176, 170, 156,  92, 177, 128,  14 };

const byte Sound_C2_BIEN [60] PROGMEM = {
       0,  60,  47,  47, 129, 148,  16,   0,  32, 182,   4,  22,  54, 216,   6,  33,
     185, 217,  53, 192, 185, 217,  61, 192, 169, 216,  94, 193, 169, 183, 119,  64,
     109, 182, 151,  64, 121, 181, 150, 191, 116, 181, 150,  32,  84, 181, 125, 191,
     112, 180,  93,  63,  85, 179,  59, 160,  37, 179,  96,  10 };

const byte Sound_C2_BLOCAGE [152] PROGMEM = {
       0, 152,  47,  47, 148, 181,  16,   0,  20, 180,  12, 135,  96, 149,  86,   0,
      96, 149,  85, 128,  96, 148,  85,   0, 180, 116,  85,  32, 164, 115,  84, 160,
     181, 146, 117, 160, 189, 175, 126,  64, 253, 174, 125, 158, 173, 173, 117, 191,
     190, 172, 108, 158, 106, 172, 100,   0, 109, 139,  96,  16, 208, 174, 112,  80,
     192, 180, 112, 112,   1, 153, 252, 144,   4, 184, 238, 144,   4, 186, 214,  16,
     228, 184,  92, 169, 228, 183, 126,  32, 244, 182, 143,  62, 248, 181, 159, 223,
     185, 181, 167, 192, 189, 180, 151, 224, 125, 180, 151,  63, 125, 180, 127,  64,
      30, 182, 118,  31,  30, 183, 117, 160,  30, 183, 117, 192,  30, 183, 117, 176,
      30, 183, 117,  16,  30, 183, 116, 144, 237, 180,  92,  80, 173, 178,  91, 189,
     109, 178,  91,  63, 109, 178,  88,   0 };

const byte Sound_C2_BOIRE [88] PROGMEM = {
       0,  88,  44,  47,   0, 113, 248,   0,  69, 172, 115,  59, 149, 170, 107, 160,
      41, 170, 109,  32, 106, 170, 125, 160,  89, 172, 142,  33,  89, 173, 158, 160,
      41, 175, 175,  32, 105, 177, 183,  64, 174, 178, 183,  95, 173, 178, 191,  64,
     168, 178, 182,  62, 105, 177, 181, 223, 109, 176, 189,  64, 109, 176, 148, 160,
      38, 208, 220,  32,  34, 176, 203, 160,  34, 176, 251, 160, 194, 181, 251,  64,
     194, 181, 250, 160,  39, 176, 232,  15 };

const byte Sound_C2_BON [32] PROGMEM = {
       0,  32,  46,  47, 128, 181,  16,   0,   0, 178,   6,  18,   0, 116, 126,  34,
      73, 170, 132, 191,  73, 164, 132, 224,  69, 163, 132, 224, 133, 162, 128,  11 };

const byte Sound_C2_BONJOUR [104] PROGMEM = {
       0, 104,  46,  47, 128, 181,  16,   0,   0, 178,   6, 146,   0, 116, 126, 162,
      73, 170, 133,  63,  73, 164, 133,  95,  69, 163, 133,  96,  84, 182, 101, 130,
      20, 182,  78,  32,   0, 184,  54, 160,   4, 184,   6, 208,  32, 218,   6, 208,
       4, 184, 254, 208,   4, 182, 254, 130,  69, 182,  78,  34,  73, 171, 110,  96,
     154, 170,  92, 192, 154, 168,  84, 127, 141, 167,  92,  64, 133, 165, 124, 224,
      19, 203, 164, 208,  35, 173, 148, 208,  66, 178, 220, 208,  82, 206, 196, 176,
      66, 176, 236,  48,  35, 174, 208,  15 };

const byte Sound_C2_BONNE [88] PROGMEM = {
       0,  88,  47,  47, 213, 177,  24,   0,  16, 178,  76,   4,  97, 178, 126,   0,
     154, 177, 126, 128, 234, 177, 143,  64, 250, 177, 151,  32, 185, 178, 151,  64,
     169, 178, 151,  62, 168, 179, 142, 223, 132, 175,  93, 220, 136, 177,  85,  32,
     128, 184,  93,  64, 132, 186,  52, 192, 196, 183,  44, 192, 132, 183,  44, 192,
     132, 183,  53,  32,  84, 181,  85,  33, 136, 148,  93,  63,  72, 179,  85,  33,
      20, 181,   0,   7,  24, 181,   0,  11 };

const byte Sound_C2_BRAVO [100] PROGMEM = {
       0, 100,  47,  47,  37, 170,   0,   0,  37, 173, 116,   1,  37, 175, 189,  32,
      21, 174, 205, 128,  21, 176, 141,  32, 101, 176, 149, 175, 104, 176, 166, 166,
     104, 177, 183,  66, 148, 177, 174, 162, 157, 175, 150,  32, 169, 176, 101,  63,
      89, 175, 100, 156,  68, 175,  92,  55,   4, 175,  68,  31,  16, 172,  28,  64,
      20, 173,  92, 160, 251, 171, 109,  64, 254, 171, 109,  62, 254, 170, 100, 222,
     250, 169,  92,  61, 189, 168,  91, 223, 169, 166,  91,  95, 137, 165,  98, 188,
     153, 164,  88,   4 };

const byte Sound_C2_C_EST [48] PROGMEM = {
       0,  48,  47,  47,  20, 183,  80,   0,  21, 215,  84,  48,  21, 183,  85,  48,
       5, 184,  85,  48,  26, 183,  85, 176, 248, 183, 102,  66, 249, 184, 119,  64,
     249, 184, 103,  95, 249, 184,  86,  61, 224, 184,  83, 191, 197, 215,  96,   4 };

const byte Sound_C2_C_ETAIT [96] PROGMEM = {
       0,  96,  47,  47,   1, 182, 224,   0,   1, 182, 228, 144,  17, 184, 253, 208,
      23, 182, 214,  48, 189, 182, 102,  39, 185, 183, 110, 186, 185, 184, 102, 127,
     229, 184,  93, 189, 246, 184,  93,  63, 225, 184,  84,  63, 225, 185,  83, 160,
       0, 153, 248,  80,  20, 180, 236,  16,  69, 183, 254, 144,   1, 182, 190,   7,
     229, 214, 109, 128, 244, 182, 117, 128, 228, 182, 133, 224, 228, 182, 133, 192,
     248, 183, 125, 224, 248, 183, 117, 160, 228, 183,  84, 160, 228, 183,  96,   9 };

const byte Sound_C2_C [56] PROGMEM = {
       0,  56,  47,  47,   1, 182, 224,   0,   1, 182, 229, 144,  17, 184, 254, 208,
      23, 182, 215,  48, 189, 182, 103,  39, 185, 183, 111, 186, 185, 184, 103, 127,
     229, 184,  94, 223, 246, 184,  94,  62, 225, 184,  85,  63, 225, 185,  84, 192,
     212, 184,  83, 163, 213, 184,  72,  10 };

const byte Sound_C2_CALCUL [136] PROGMEM = {
       0, 136,  47,  47,   4, 183, 224,   0,   4, 183, 220, 143, 224, 183, 101, 160,
     176, 183, 127,  32, 164, 182, 151, 190, 185, 182, 143, 192, 248, 182, 135,  29,
     253, 182, 110, 160, 166, 183,  94,  64, 150, 183,  77,  63, 145, 182,  75, 160,
     208, 182,  64,  16, 133, 151,  88,  48, 128, 216,  80, 112,  24, 184, 222, 176,
      12, 185, 213, 176,  25, 185,  61, 144, 168, 185,  61,  34, 250, 151,  68, 193,
     251, 151,  69,  63, 250, 151,  69, 224, 234, 151,  77, 194, 230, 151,  85, 164,
     229, 150,  85,  32, 229, 150,  76, 129, 161, 150,  68,   2, 181, 150,  60,  64,
     245, 150,  76, 160, 248, 182,  76, 223, 248, 181,  76, 158, 250, 181,  76, 192,
     229, 181,  72,  22, 229, 181,  72,  17 };

const byte Sound_C2_CE [60] PROGMEM = {
       0,  60,  47,  47,  21, 215, 248,   0,  21, 214, 252, 176,   5, 214, 253,  80,
       1, 215, 253, 208,   1, 220, 254,  48,   4, 216, 254, 112,  89, 180, 102,  63,
      90, 180, 102,  32, 106, 180, 110,  64, 239, 181, 110,  95, 187, 180, 101, 190,
     230, 181,  92, 160, 211, 181, 100,  33, 133, 182,  96,   8 };

const byte Sound_C2_CECI [80] PROGMEM = {
       0,  80,  47,  47,  25, 183, 160,   0,   7, 183, 253,  48,   5, 183, 253, 240,
      81, 183, 254, 112,  74, 183, 254, 208, 186, 180, 102, 191, 254, 180, 103,  64,
     255, 181, 102, 191,  95, 182,  78,  32,  17, 187,  71,  48,  18, 216,  71,  80,
       5, 215,  70, 176,  21, 216,  62, 112,  10, 219,  54, 112, 157, 216,  61, 223,
     212, 217,  69, 225, 192, 217,  60, 160, 200, 217,  51, 161, 196, 219,  40,  30 };

const byte Sound_C2_CHIFFRE [176] PROGMEM = {
       0, 176,  47,  47,  19, 218,   0,   0,  19, 186, 253,  16,  10, 186, 253, 144,
      19, 186, 253, 176,  17, 217, 254,  48,  17, 218,   6,  48,  21, 218, 174,  48,
      21, 218, 206, 176,  36, 251, 238, 176,  37, 219, 246, 176,  20, 250, 254, 144,
      33, 219, 254, 208,  10, 184, 254, 208, 234, 215,  86, 167, 245, 215,  78, 160,
     246, 215,  70, 160, 230, 215,  62, 160, 226, 215,  62, 162, 242, 216,  62,   2,
     245, 184,  70,  65,  89, 184,  62,  80,  21, 184,  14,  48,  17, 183,   6,  80,
      22, 183, 166,  48,  17, 182,   6,  48,  17, 181, 198,  48,  68, 181, 254,  48,
      17, 183,  94,  48,  65, 152, 182,  48,   0, 149, 238,  48, 130, 146, 198,  48,
      81, 174, 150,  16,  37, 174, 181, 176,  34, 174, 133, 144, 119, 176, 101, 157,
     171, 176, 117, 190, 171, 176, 133, 160, 170, 177, 149, 192, 170, 177, 157,  32,
     101, 177, 148, 191, 165, 177, 124,  59,  64, 177, 123, 155,  84, 177, 112,   0 };

const byte Sound_C2_CHOISI [84] PROGMEM = {
       0,  84,  47,  47,  17, 186, 248,   0,  20, 218, 254,  48,  69, 218, 254, 112,
      64, 215, 253, 208, 145, 182, 236,  80,  69, 140, 100,  37, 101, 141, 101, 160,
     169, 144, 126, 160, 185, 180, 143,  64, 184, 181, 119,  95, 244, 213,  93,  95,
     149, 214, 108,  80,  82, 215, 101,  80,  87, 215, 109, 208, 158, 216,  69, 208,
     213, 217,  60, 220, 229, 216,  68,  96, 249, 216,  68, 127, 249, 216,  68,   8,
     249, 216,  64,  14 };

const byte Sound_C2_CHOIX [76] PROGMEM = {
       0,  76,  47,  47,  16, 184, 192,   0,  19, 216, 238,  48,  19, 217, 254, 208,
      83, 184, 254, 240,  67, 183, 254,  48, 131, 215, 253,  48, 135, 140, 216,  48,
      89, 136, 124,  36,  86, 139, 117, 223,  86, 139, 134,  63, 106, 141, 150,  32,
      22, 174, 158,  32, 170, 175, 158,  64, 170, 175, 158,  62, 184, 175, 141,   0,
     116, 174, 124, 160, 101, 174,  98,  63,  98, 175, 112,   4 };

const byte Sound_C2_CLASSE [84] PROGMEM = {
       0,  84,  47,  47,   5, 153, 216,   0,  17, 185, 190,  48,  81, 214,  93,   0,
     166, 182, 101,  32, 249, 182, 118,  32, 249, 182, 135,  32, 164, 181, 183, 192,
     144, 180, 183,  95,  72, 179, 150,  95, 169, 180, 125,  61,   0, 186, 253,  80,
      17, 183, 253, 112,  64, 186, 253, 112,  16, 181, 165, 112,  84, 181, 109,  48,
     229, 179, 116,  32, 228, 179, 123, 192,  64, 178, 123, 192,  16, 178,   2,  32,
      81, 178,  64,  14 };

const byte Sound_C2_CLAVIER [100] PROGMEM = {
       0, 100,  47,  47,   5, 153, 216,   0,  17, 185, 190,  48,  81, 214,  93,   0,
     166, 182, 101,  32, 249, 182, 118,  32, 249, 182, 135,  32, 245, 182, 143, 191,
     185, 183, 135, 192, 181, 183, 127,  60, 169, 150, 101, 191, 149, 151, 100, 144,
     145, 184, 117,  48, 149, 185,  93,  80, 169, 217,  61, 208, 230, 216,  53,  48,
     233, 216,  59, 223, 228, 216,  68,  33, 249, 216,  68, 161, 234, 184,  85,  64,
     245, 184,  93, 161, 249, 184,  94,  32, 249, 184, 102,  64, 244, 184,  93, 161,
     240, 185,  88,   8 };

const byte Sound_C2_CLEF [48] PROGMEM = {
       0,  48,  47,  47,   4, 182,   0,   0,   8, 181,   5, 144, 196, 215,  69, 173,
     225, 182,  69, 160, 178, 214,  62,  32, 233, 184, 102, 255, 228, 185, 102, 255,
     212, 185,  94,  61, 216, 185,  85, 159, 200, 185,  68, 128, 196, 185,  56,  29 };

const byte Sound_C2_COMBIEN [112] PROGMEM = {
       0, 112,  47,  47, 130, 178, 216,   0, 194, 174, 228, 130,  35, 173, 221,   0,
      69, 149, 158,  32, 137, 176, 134, 160, 133, 177, 150, 223, 132, 179, 135,  64,
      72, 182, 102, 190, 137, 182,  62,  64,  73, 148,  53, 191, 129, 152,  61,  63,
     196, 152,  52,  63, 165, 152,  44,  62,  37, 152,  46,   1,  20, 184,  54, 134,
     185, 184,  61, 129, 250, 184,  61, 160, 250, 216,  61,  64, 233, 215,  77, 190,
     233, 183,  94,  32, 233, 182, 127,  64, 165, 181, 126, 192, 169, 180, 126,  64,
     149, 179, 126,  64, 101, 178, 142, 192, 105, 177, 109, 191,  85, 177,  80,  14 };

const byte Sound_C2_COMME [116] PROGMEM = {
       0, 116,  47,  47,  97,  81, 224,   0, 209, 180, 248,  15,  81, 176, 252,  39,
      86, 145, 132, 160,  70, 141, 109, 160, 101, 142, 101, 192, 102, 175, 174,  63,
      91, 176, 182,  94,  90, 176, 173, 191,  90, 175,  68, 188,  73, 180,  77,  33,
      89, 176,  69,  94,  74, 178,  53,  64,  90, 178,  44, 223, 138, 179,  36,  62,
     154, 177,  35, 191, 223, 177,  27,  32, 238, 177,  42, 160, 202, 179,  43,  64,
     218, 178,  59,  64, 169, 177, 124, 160, 185, 177, 132, 189, 181, 177, 125,  32,
     190, 177, 140, 192, 100, 177, 156,  64,  80, 208, 187, 160, 130, 148, 250, 160,
     130, 148, 248,  13 };

const byte Sound_C2_COMMERCIAL [108] PROGMEM = {
       0, 108,  47,  47,   0, 153, 248,   0,  16, 179, 171,  16,  80, 145, 221, 176,
     149, 144, 116,  38, 238, 142, 117, 192, 172, 142,  92,  57, 156, 143,  51, 162,
     137, 143,  68,  33, 148, 145,  60,  65, 232, 150, 143,  64, 165, 182, 143,  94,
     101, 181, 150,  57,  20, 180, 142,  80,  85, 183, 125, 208,  16, 181, 117,  80,
      14, 215,  93, 240,   4, 218,  86, 208, 240, 182, 110,  67, 218, 147, 158, 192,
     234, 179, 166, 192, 244, 180, 150,  64, 237, 180,  92, 223, 237, 179,  83, 192,
     237, 179,  91,  64, 237, 179, 146,  95, 237, 179, 144,  10 };

const byte Sound_C2_COMPRENDRE [128] PROGMEM = {
       0, 128,  47,  47,  64, 204, 224,   0, 129, 207, 214,  48,  80, 206, 165, 144,
      81, 174, 157,   7,  70, 174, 134, 160, 133, 179, 142, 160, 137, 172, 150, 192,
      72, 169, 166, 192,  72, 173, 118, 160,   0, 173, 110,  63, 133, 186, 232,  96,
     137, 174, 231, 208,  25, 170,   6, 223,  22, 171, 182,  32,  26, 171, 190, 160,
      69, 175, 199,  64,  70, 175, 199,  64,  26, 169, 198, 192,  27, 169, 198,  64,
      26, 170, 182,  95,  26, 173, 158,  64,  94, 175, 142,  62,  31, 176, 117,  32,
      17, 178,  80, 112, 110, 177, 125, 162,  25, 174,  69,  32,  42, 176,  84, 189,
      42, 176, 156, 192, 106, 176, 148,  63,  42, 175,  91,  32,  42, 175,  88,  11 };

const byte Sound_C2_COMPTER [84] PROGMEM = {
       0,  84,  47,  47,  64, 204, 224,   0, 129, 207, 214,  48,  80, 206, 165, 144,
      81, 174, 157,   7,  70, 174, 134, 160, 133, 179, 142, 160, 137, 172, 150, 192,
      72, 169, 166, 192,  72, 173, 118, 160,   0, 173, 110,  63, 129, 148, 128, 112,
     129, 185, 120, 112,  16, 215, 207,  48, 169, 183, 158, 176, 249, 183,  94, 188,
     250, 183, 103, 223, 246, 184,  95,  94, 233, 184,  86,  96, 226, 185,  69,  32,
     226, 185,  72,  15 };

const byte Sound_C2_CONNAITRE [112] PROGMEM = {
       0, 112,  47,  47, 128, 180, 248,   0,   0, 146, 202, 144,  85, 182, 245, 144,
     150, 147, 142, 192, 155, 179, 142, 192,  85, 179, 126, 189, 153, 180,  69,  32,
     136, 180,  68, 191, 152, 181,  69,  32, 153, 181,  77,  64, 168, 182, 126, 191,
     184, 182, 126, 191, 164, 183, 142, 224, 245, 183, 126, 193, 228, 183, 117, 162,
     212, 183,  83, 161, 212, 247, 112, 112, 128, 185, 112, 112,   0, 119, 253,  16,
      64, 181, 254,  16,  32, 181, 182,  16,  17, 148, 254,  16,  33, 180,   5,  16,
      33, 180,   4,   0, 192, 150, 252, 159, 192, 185, 252, 160, 128, 185, 248,   3 };

const byte Sound_C2_COPIE [96] PROGMEM = {
       0,  96,  47,  47, 128, 178, 248,   0,  33, 145, 222,  15,  16,  50, 254, 135,
      32, 177, 190, 128, 161, 177, 109, 160, 170, 143, 118,  32, 174, 142, 134,  95,
     191, 141, 134,  63, 190, 141, 126,  32, 174, 141, 117,  27, 196, 175,  96,  80,
     192, 217, 120, 112,  20, 181, 141,  16,  41, 182,   7,  48,  29, 151,   6,   6,
     153, 184,  70, 128, 245, 215,  62, 254, 244, 215,  62,  62, 244, 216,  53, 190,
     224, 247,  53,  63, 216, 215,  52, 190, 212, 216,  44,  64, 212, 216,  40,  13 };

const byte Sound_C2_CORRESPONDANTE [180] PROGMEM = {
       0, 180,  47,  47,  32, 211, 224,   0,  32, 211, 230,  16,  49, 211, 214,  48,
      97, 177, 117, 162,  86, 144, 126,  32,  26, 142, 134,  62,  21, 171, 126,  62,
      37, 139, 133, 160,  21, 143, 158,  64, 169, 148, 150,  64, 164, 182, 141, 160,
     148, 182, 125, 188,  69, 183, 141, 144,   6, 183, 158,  48,  20, 215, 134,  80,
       4, 216, 149, 208, 144, 216, 120,  48, 101, 171, 128, 100,  17, 169, 149,  51,
      33, 169, 109, 158,  16, 169,  77, 224, 132, 182,  92, 191, 132, 182,  77,  63,
     132, 181,  76, 191, 137, 176,  76,  63,  65, 213,  77,  32,  90, 176, 125, 161,
      85, 175, 157, 192,  21, 173, 157, 192,  37, 170, 117, 192,  37, 171,  93, 193,
      38, 171,  93, 162,  25, 171, 117,  35,  85, 172, 133, 163,  25, 170,  76, 162,
       1, 171,  91, 192,  69, 177, 216,  48,  64, 165, 128, 112,  64, 165, 128, 112,
      16, 216, 254,  48,   1, 214, 237,  48,  21, 181, 252, 176,  17, 149, 252,  48,
      17, 149, 248,  22 };

const byte Sound_C2_COTEE [76] PROGMEM = {
       0,  76,  47,  47, 128, 180, 248,   0,   0, 146, 203, 144,  85, 182, 246, 144,
     150, 147, 103,  95, 155, 179, 102, 224,  85, 179, 102, 191, 133, 177, 112,  48,
     192, 186, 104, 112,  70, 183, 160, 112, 237, 183,  95,  36, 250, 184, 103,  94,
     234, 184,  95,  95, 234, 184,  87,  64, 234, 184,  94, 193, 246, 185,  85,  35,
     229, 185,  68, 160, 212, 185,  76,  32, 197, 185,  56,   0 };

const byte Sound_C2_COULEUR [112] PROGMEM = {
       0, 112,  47,  47,  33, 140,   0,   0,  21, 139,  61,  48,  22, 169,   5,  37,
       6, 134,   5,  32,   1, 139,   5,  32,  21, 176,   5,  61,  33,  84,   5,  60,
     100, 150,  77,  63, 100, 150,  85,  32, 148, 182, 109, 161, 229, 181, 125, 191,
     170, 180, 134,  63, 170, 180, 142,  63, 238, 180, 142, 192, 234, 180, 142, 192,
     254, 180, 142, 192, 238, 180, 142, 192, 170, 179, 142, 224, 170, 179, 150, 193,
     235, 179, 142, 193, 230, 178, 133, 163, 234, 178, 125,  35, 229, 178, 116, 162,
     166, 177,  92,  32, 101, 177,  59, 160,  50, 177,  35,  80,  49, 208,   0,  18 };

const byte Sound_C2_CRAYON [88] PROGMEM = {
       0,  88,  47,  47,  36, 182, 192,   0,  32, 182, 255,  48, 128, 186, 254, 176,
     164, 182,  93, 160, 168, 183, 119,  32, 184, 184, 119,  96, 185, 184,  95,  95,
     245, 216,  86,  62, 245, 216,  77, 160, 228, 217,  69,  63, 209, 216,  77,  32,
     229, 184,  85, 160, 149, 184, 110,  33,  85, 151, 126,  32,  69, 176, 142,  64,
      20, 168, 134,  96,  36, 168, 125, 160,  20, 165, 125,  33,  40, 165, 116,  34,
      36, 164, 115, 162, 100, 164, 112,  30 };

const byte Sound_C2_CROCHET [116] PROGMEM = {
       0, 116,  47,  47,   2, 173, 192,   0,   6, 137, 198,  16,   7, 145, 198, 144,
       2, 174, 198,  15,   6, 175, 197, 158,   7, 165, 109,  30, 139, 170, 140, 158,
      91, 169, 125,  32, 171, 170, 125, 160, 170, 170, 126,   1, 169, 142, 126, 192,
     101, 144, 119,  61,  81, 179, 110,  32,  16, 184,  86, 176,  16, 184,   7,  16,
       4, 185, 255,  80, 100, 218, 255, 112,  29, 181, 215,  48,  26, 182,   6, 136,
     107, 181,  94, 128, 189, 182, 110, 190, 189, 182, 119,  95, 249, 183, 111,  96,
     249, 184, 110, 160, 249, 184,  94,  64, 233, 184,  93, 159, 249, 184,  92, 188,
     244, 184,  88,   5 };

const byte Sound_C2_CURSEUR [108] PROGMEM = {
       0, 108,  47,  47,  13, 150, 208,   0,  16, 152, 253, 176,  48, 183,  69,   4,
     170, 150,  86,  32, 171, 150, 102, 160,  90, 180, 118, 160, 170, 178, 118,  62,
       5, 178,  69,  32,  17, 178, 253, 176,  66, 183, 254, 208,  17, 182,   6, 112,
      90, 180, 126, 112, 229, 179, 118, 191, 170, 179, 127,  62, 238, 180, 135,  95,
     238, 180, 143,  64, 170, 179, 143,  96, 170, 179, 151,  65, 235, 179, 143,  65,
     230, 178, 134,  35, 234, 178, 125, 163, 229, 178, 117,  34, 166, 177,  92, 160,
     101, 177,  60,  32,  50, 177,  35, 208,  49, 208,   0,  18 };

const byte Sound_C2_D_ [20] PROGMEM = {
       0,  20,  47,  47, 144, 176,  40,   0,   0, 179,  67,  15, 169, 181, 117, 160,
     253, 180, 136,  17 };

const byte Sound_C2_D [64] PROGMEM = {
       0,  64,  47,  47, 212, 182,  24,   0, 208, 214,  26, 165, 196, 182,  27,  32,
     212, 182,  27, 160, 105, 183,  77,  32, 185, 184,  86, 160, 184, 184,  95,  32,
     181, 184, 103, 160, 245, 184, 103, 160, 245, 184,  95,  32, 229, 184,  94, 160,
     229, 185,  94,  32, 245, 185,  93,  32, 209, 185,  83, 160, 209, 185,  56,  22 };

const byte Sound_C2_DANS [56] PROGMEM = {
       0,  56,  47,  47, 217, 180,  24,   0,  17, 215,   4,  19,   0, 247, 149, 130,
      16, 215, 142,   4, 106, 180, 126, 163,  46, 178, 134, 160,  25, 176, 159,  96,
      25, 204, 183,  95,  37, 203, 158, 223,  20, 169, 173, 160,  20, 199, 181,  62,
      73, 201, 124,  32,  20, 167,   0,  13 };

const byte Sound_C2_DE [52] PROGMEM = {
       0,  52,  47,  47,   1,  31,   0,   0,   1,  31,   3,  16,   1, 122, 108, 144,
       1, 150, 125, 145,  29, 181,  94,  37, 153, 181, 102,  32, 229, 181, 110,  32,
     229, 180, 110,  64, 233, 180, 109, 190, 253, 180, 101, 192, 253, 180, 101, 160,
     136, 176,  56,   9 };

const byte Sound_C2_DEBUT [76] PROGMEM = {
       0,  76,  47,  47,  96, 215,  88,   0, 249, 184,  94, 167, 249, 184, 102, 192,
     233, 184,  94, 192, 249, 184,  86, 191, 153, 149,  78,  49, 208, 184,  67, 186,
     208, 185,  72,  80,   5, 147, 224, 112,  49, 183,   5, 172,  97, 183,  29, 163,
     101, 151,  45, 192, 101, 151,  54,  66, 101, 151,  61, 193, 177, 151,  61,  38,
     214, 151,  60, 162, 245, 150,  59, 186, 245, 150,  48,  17 };

const byte Sound_C2_DEJA [92] PROGMEM = {
       0,  92,  47,  47,   0, 186, 248,   0,  37, 184,  29, 129, 169, 184,  94,  32,
     186, 184, 102, 192, 186, 184, 102, 223, 102, 184,  94, 223,  18, 216,  22, 160,
      17, 215,   7,  48,   2, 182,   7,  80,   9, 214,   7,  80,   5, 217,   6, 208,
       2, 181,   6,  64, 102, 181, 126,  32, 105, 180, 134, 191, 165, 180, 142, 160,
     186, 179, 158, 191, 185, 179, 166,  32, 166, 179, 174, 192, 102, 178, 174, 161,
     102, 178, 182, 194, 102, 177, 157, 160, 102, 177, 136,   1 };

const byte Sound_C2_DELETE [124] PROGMEM = {
       0, 124,  44,  47,  20, 215,   0,   0,  20, 214,  60, 143,  25, 215,  62,   4,
     186, 216,  69, 160, 181, 216,  70,  32, 169, 184,  62,  33, 245, 184,  62,  64,
     245, 184,  70,  63, 145, 182,  77, 223, 248, 182, 110,  62, 248, 182, 118, 159,
     248, 182, 119,  30, 248, 182, 127,  30, 248, 182, 135,  63, 248, 182, 135,  95,
     232, 182, 134, 157, 232, 183, 126,  30, 228, 182, 117, 189, 212, 183, 125,  29,
     228, 183, 101,  62, 244, 182,  84, 191, 128, 215, 112,  16, 192, 216, 120,  48,
     128, 214,  96,  80,   0, 152, 251,  16,   0, 183, 244,  16,   0, 188, 252, 144,
       0, 183, 245,  16,  20, 214, 204, 144,  21, 181, 168,  15 };

const byte Sound_C2_DEMANDER [116] PROGMEM = {
       0, 116,  47,  47, 129, 152, 248,   0, 230, 180, 110,  65, 170, 180, 110, 160,
     154, 180, 110,  95,  69, 181,  69,  61,  80, 186,  60, 191,  72, 181,  60, 192,
      80, 187,  69,  32,   9, 172, 110, 160,  10, 170, 198, 192,  26, 170, 158,  63,
      74, 173, 166,  64,  25, 174, 126,  64,  28, 176, 101, 160,  73, 178,  60, 190,
      76, 179,  68,  32, 136, 178,  72,  16,  20, 216, 136, 112,  42, 182,   5, 135,
     106, 183,  94,   1, 122, 183, 103,  31, 122, 183, 111,  61, 246, 184, 102,  64,
     228, 184,  85,  64, 228, 184,  93,  96, 230, 185,  84,  33, 230, 185,  59,  33,
     217, 184,  64,   9 };

const byte Sound_C2_DEMI [80] PROGMEM = {
       0,  80,  47,  47, 128, 215,  24, 128,   6, 181, 252, 144,  18, 186, 254, 144,
      18, 181, 254,  15,  33, 214,  54, 133,  38, 181,  71,   0, 107, 181, 103,  32,
     127, 148, 119,  95, 107, 149, 103,  95, 107, 149,  79,  29,  26, 148,  70, 157,
      90, 148,  78,  30,  72, 148,  53,  33, 137, 116,  61,  64, 137, 114,  60, 161,
      69, 245,  69, 224, 145, 215,  77, 189,  96, 215,  77,  31, 145, 152,  72,  31 };

const byte Sound_C2_DES [52] PROGMEM = {
       0,  52,  47,  47,  16, 184, 248,   0,  16, 184, 252, 159, 244, 183,  85, 160,
     248, 183, 102, 160, 245, 184, 111,  64, 249, 184, 103,  95, 233, 184, 102, 191,
     228, 185,  93, 160, 224, 185,  93,  32, 212, 185,  92,  32, 196, 184,  91,  32,
     200, 184,  88,   7 };

const byte Sound_C2_DESIRER [116] PROGMEM = {
       0, 116,  47,  47,  98, 215, 168,   0, 229, 184,  86,  63, 228, 184, 103,  64,
     232, 184,  95,  32, 232, 184,  95,  63, 172, 183,  78,  62, 233, 184,  69, 160,
     149, 184,  69,  48, 174, 184,  62,  80,  94, 185,  70, 176, 110, 217,  63,  48,
     106, 217,  70,  31, 174, 217,  70, 160, 244, 217,  78, 160, 232, 185,  86, 160,
     229, 184,  94, 192, 213, 182,  94,  60,  81, 183,  86,  60,  33, 181,   6,  48,
     101, 181, 102, 176, 169, 181, 109, 165, 233, 182, 126, 160, 232, 183, 126, 192,
     228, 183, 118, 160, 232, 184, 102,  64, 216, 185,  93,  63, 248, 185,  92, 161,
     217, 184,  72,  15 };

const byte Sound_C2_DIEZE [120] PROGMEM = {
       0, 120,  47,  47, 170, 216,  32,   0, 245, 217,  52, 192, 230, 216,  61,  34,
     245, 216,  77, 131, 229, 184, 102,  32, 229, 183, 110, 129, 233, 183, 126, 160,
     249, 183, 143,  95, 249, 183, 143,  64, 249, 182, 143,  95, 233, 182, 135,  95,
     169, 183, 134, 159, 185, 183, 126, 191, 189, 182, 118, 223, 125, 182, 110,  64,
     189, 182, 109, 191, 188, 182,  93,  31, 188, 182,  84, 128, 185, 182,  84,  32,
     185, 181,  67, 160, 188, 181,  59,   0, 185, 181,  75,  32, 101, 181,  67,  64,
     122, 180,  83,  64, 105, 179,  83,  64, 106, 179,  90, 128, 101, 179,  90,   0,
     101, 179,  89, 128, 164, 179,  88,  14 };

const byte Sound_C2_DIFFICILE [124] PROGMEM = {
       0, 124,  47,  47,   8, 215,   0,   0,  77, 218,  61,   5, 174, 217,  61, 145,
     217, 217,  62,  34, 216, 218,  54,  34, 216, 217,  62,  64,  21, 217,   7,  48,
      20, 218,   6, 208,  20, 183,   6,  80,   9, 218,   6, 208, 229, 217,  62,  32,
     244, 217,  62,  64, 221, 217,  62,  59,   9, 217,   6,   0,  72, 212,   7, 208,
       4, 215,   6,  80,   9, 183,   6, 240,  25, 217,   7, 112, 104, 217,  70,  13,
     233, 217,  54,  94, 229, 216,  53, 255,  72, 216,  53, 192, 244, 215,  69,  95,
     244, 214,  69,  95, 245, 214,  76, 222, 232, 181,  92, 192, 180, 181, 131, 192,
     104, 180, 160,   1, 184, 179, 152,  15, 104, 179, 184,  15 };

const byte Sound_C2_DIRE [64] PROGMEM = {
       0,  64,  47,  47, 200, 216,  24,   0,  16, 215,   4, 146,  24, 214,   5, 128,
     157, 218,  46,  65, 233, 218,  54, 193, 169, 218,  54, 192, 233, 218,  54, 224,
     229, 186,  70,  96, 101, 180, 117, 224,  41, 178, 109,  60,  21, 179,  69,  16,
       0, 211,   4, 208,  25, 177, 148,  80,  57, 177, 124,  80,  57, 208, 184,  14 };

const byte Sound_C2_DIRIGE [120] PROGMEM = {
       0, 120,  47,  47,   0, 184, 104,   0, 254, 217,  61, 188, 185, 217,  70,  34,
     245, 217,  70, 162, 249, 185,  78, 192, 185, 184,  94, 223, 121, 183,  86, 191,
      37, 215,   6,  36,  33, 183,   7,  80,  36, 216,   6, 187, 249, 184,  95,  34,
     185, 185, 103,  32, 185, 185,  95,  63, 250, 185,  87,  32, 186, 185,  87,  32,
     185, 185,  78, 160, 245, 185,  70,  65, 249, 184,  78,  65, 186, 184,  78,  33,
     114, 216,  70,  32,  17, 216,  22,  32,   5, 184,  22, 176,  16, 217,  22, 208,
       6, 182,  22, 208,  68, 185,  68,  36, 144, 180,  75, 161, 128, 185,  58, 160,
     132, 181,   9, 160, 144, 180,   0,  18 };

const byte Sound_C2_DO [48] PROGMEM = {
       0,  48,  47,  47,  65, 182, 120,   0,  86, 180,  71,  36, 234, 178,  94, 161,
     182, 173,  86,  96, 166, 172,  94,  96, 166, 172,  93, 159,  82, 163,  53,  32,
     130, 198, 108, 158, 210, 201,  75, 128, 234, 168,  74, 159, 170, 168,  72,  26 };

const byte Sound_C2_DOLLARD [128] PROGMEM = {
       0, 128,  47,  47, 100, 181,  64,   0, 100, 181,  69,   9, 154, 180, 101, 160,
     234, 174, 109, 192, 254, 173, 117,  31, 253, 174, 117,  64, 253, 174, 117, 130,
     249, 144, 117, 191, 228, 146, 117, 157, 160, 147, 101, 191, 104, 180, 101, 192,
     172, 180, 102,  63, 184, 180, 126, 157, 248, 180, 151,  32, 248, 180, 175,  32,
     249, 179, 183,  64, 173, 179, 183,  95, 189, 178, 183,  64, 124, 178, 191,  32,
     125, 178, 190, 160, 125, 178, 190, 191, 125, 177, 190, 160, 184, 177, 190, 192,
     188, 177, 181, 159, 180, 177, 173,  32, 168, 176, 172, 160, 184, 176, 172, 192,
     124, 176, 139, 192, 104, 176, 138, 223, 100, 176, 138,  64, 104, 176, 128,  13 };

const byte Sound_C2_DONC [80] PROGMEM = {
       0,  80,  47,  47,  38, 183,   0,   0,  17, 183,   7, 176, 134, 179, 109, 160,
      65, 208, 125, 191,  85, 169, 141, 192, 136, 166, 157, 223, 138, 212, 141, 224,
     137, 177, 141,  64, 141, 168, 133,  65, 136, 177, 116, 194,  80, 218,  76,  65,
      64, 217,  80,  48, 128, 185, 104, 112,  68, 185, 254,  16,   8, 185, 254,  48,
      73, 185, 253, 176, 133, 216, 253,  48,  54, 184, 132, 176,  54, 183,   0,  22 };

const byte Sound_C2_DONNE [92] PROGMEM = {
       0,  92,  47,  47,  38, 183,   0,   0,  17, 183,   5,  48, 134, 179, 110,  32,
     169, 177, 142,  32, 169, 177, 142,  32, 169, 177, 150,  64, 169, 177, 150,  64,
     173, 179, 142,  64, 169, 179, 118,  61, 173, 179, 102,  62, 220, 179,  45, 191,
     140, 177,  60,  32, 200, 181,  44, 223, 136, 182,  36, 255,  25, 180,  52, 160,
     164, 179, 108, 160, 165, 179, 132, 192, 169, 179, 124, 138, 153, 178, 124, 142,
     105, 179, 116,  32,  85, 180,  84,  64,  21, 179,  64,   0 };

const byte Sound_C2_DROITE [96] PROGMEM = {
       0,  96,  41,  47,   5, 181, 248,   0,   2, 147, 254,  48,   2, 169,   4,  60,
      37, 170,   3,  32, 129, 177, 187, 176, 199, 170, 179, 208, 214, 166, 123,   0,
     138, 166, 132,  32, 155, 167, 124, 160, 138, 167, 133,  32, 133, 139, 150,  34,
     132, 173, 174, 160, 132, 143, 182, 158, 188, 175, 198, 192, 184, 176, 190,   1,
     184, 176, 189, 160, 152, 179, 181,  62,  64, 173, 168,  80,  64, 173, 168, 112,
       4, 183, 237,  48, 109, 181, 140,  48, 232, 181,  99, 191, 232, 179, 123, 192 };

const byte Sound_C2_DU [44] PROGMEM = {
       0,  44,  47,  47, 212, 183,  32,   0,  65, 153,   4,  18,  82, 216, 173, 129,
     101, 184,   6,  33, 164, 216,  46,  33, 182, 184,  38, 193, 166, 184,  38, 192,
     231, 184,  54, 192, 246, 183,  54, 223, 117, 183,   0,   9 };

const byte Sound_C2_E [44] PROGMEM = {
       0,  44,  47,  47,  65, 182,  88,   0,  85, 179, 101,  38, 233, 179,  94, 255,
     169, 179, 102, 191, 169, 179, 102, 190, 229, 179,  93, 161, 208, 180,  92,  32,
     192, 179,  99,  33, 192, 180,  98, 191, 192, 179,  96,   0 };

const byte Sound_C2_ECOUTE [108] PROGMEM = {
       0, 108,  47,  47,  41, 185,  16,   0, 164, 185, 102, 140, 185, 185,  95, 192,
     233, 185,  87,  62, 217, 186,  77,  63, 196, 184,  88, 112, 128, 153, 232, 112,
     192, 144, 237,  16,  16, 141,   3,   3,  70, 172,  85,  32,   6, 172,  86,  61,
       2, 173,  70,  62,  81, 209,  86, 191,  81, 211,  86, 191, 154, 182,  85, 189,
     137, 181,  51,  61, 128, 214,  64, 112,   0, 150, 248,  96,  80, 216, 224,  97,
       5, 218, 252,  16,  65, 185, 252, 176,   1, 215, 197, 176,  18, 182, 157, 208,
      82, 182, 157,  48, 163, 181, 148,  16, 146, 181, 144,   9 };

const byte Sound_C2_ECOUTEUR [120] PROGMEM = {
       0, 120,  46,  47,   0, 150, 232,   0, 144, 184, 117, 135, 224, 185, 103,  64,
     216, 185,  86, 192, 212, 185,  83, 160, 196, 184,  88,  32, 208, 153,  88,  80,
      17, 174,   0, 112,  64, 147, 237,  16,  22, 145,  61,  37,  97, 177,  77, 187,
     149, 211,  69,  62, 132, 181,  59,  58, 132, 212,  72,  48, 128, 181,  72, 112,
     100, 215, 184, 112,  21, 214, 173, 143, 213, 213, 101, 145, 229, 180, 126, 192,
     229, 180, 134, 192, 217, 178, 133, 191, 214, 179, 125, 192, 234, 180, 117, 192,
     218, 180, 125, 192, 202, 179, 133,  64, 238, 180, 125,  95, 238, 180, 124, 222,
     153, 179, 112,   7, 141, 177, 112,  15 };

const byte Sound_C2_ECRAN [96] PROGMEM = {
       0,  96,  47,  47, 165, 183,  88,   0, 233, 183, 110,   2, 232, 184, 119,  32,
     229, 185, 103,  64, 165, 185,  94, 160, 217, 185,  85,  63,  32, 214, 248, 112,
      38, 178, 224, 112,  37, 176, 245, 144,  53, 176, 198,  16,  37, 176,   6,  48,
      42, 175,  36, 154,  22, 173, 125,  32, 105, 173, 149, 160,  42, 172, 150,  32,
      42, 170, 126, 192,  42, 170, 126,  63,  38, 169, 126,  65,  41, 169, 133,  33,
      42, 168, 108, 162,  25, 165,  84,  34,  25, 163,  59, 164,  78, 168,  48,  18 };

const byte Sound_C2_ECRIS [84] PROGMEM = {
       0,  84,  47,  47,  64, 148, 240,   0, 144, 218,  92, 131, 208, 185,  85, 128,
     224, 217,  93, 160, 224, 217,  94,  33, 244, 217,  86, 192, 224, 218,  69, 190,
     196, 217,  76, 160,  96, 185,  40, 112, 101, 185, 117, 144,  97, 184, 206, 176,
      98, 183, 190,  80,  81, 215,   5, 176, 213, 185,  53,  38, 202, 152,  61,  64,
     225, 186,  53,  63, 209, 217,  45,  64, 209, 217,  44, 192, 196, 217,  43, 160,
     212, 217,  24,  21 };

const byte Sound_C2_EFFACE [100] PROGMEM = {
       0, 100,  47,  47,  16, 184, 104,   0, 228, 184, 100, 162, 250, 184, 102,  32,
     117, 184,  95,  64, 117, 184, 110, 189, 116, 184,  93,  63,  37, 183,   6, 176,
      17, 183, 254, 112,  64, 152, 254, 112, 101, 179, 157, 175, 166, 179, 158, 145,
     106, 180, 175,  92, 102, 180, 182, 222,  86, 180, 174,  62, 165, 180, 165, 157,
     101, 181, 149,  63, 102, 181, 141,  47,  85, 181, 133, 144,  17, 217, 181, 208,
       0, 216, 196, 208,  16, 215, 252, 208, 137, 181, 116,  80, 105, 180, 147, 208,
      89, 179, 128,  24 };

const byte Sound_C2_EGAL [136] PROGMEM = {
       0, 136,  47,  47,   4, 184,   0,   0, 244, 185, 101,  43, 224, 185,  93,  64,
     204, 185,  85, 192, 200, 185,  77,  27, 176, 186,  68,  59, 224, 186,  50, 136,
     224, 186,  40,  16, 140, 182,  40,  48,  12, 183,   0,  80,  88, 185,  77,  30,
     217, 185,  93, 128, 233, 184, 110, 129, 153, 183, 134, 160, 184, 182, 166, 191,
     184, 181, 182, 191, 188, 180, 190, 223, 184, 180, 190, 192, 188, 180, 182, 222,
     184, 180, 182, 189, 184, 181, 166, 160, 188, 181, 142, 191, 185, 181, 142,  32,
     184, 181, 125, 192, 184, 181, 117,  32, 248, 181, 108,  32, 252, 181, 108,  63,
     188, 181,  92,  64, 252, 181,  83, 160, 252, 181,  83,  31, 248, 181,  74, 160,
     252, 180,  82, 192, 236, 180,  96,  13 };

const byte Sound_C2_ELLE [56] PROGMEM = {
       0,  56,  47,  47, 184, 183, 144,   0, 248, 183, 150,  95, 244, 183, 134, 192,
     184, 215, 143,  64, 185, 183, 135,  95, 249, 183, 102,  64, 252, 183, 101, 223,
     252, 182, 101, 223, 252, 182, 100, 223, 253, 182,  99, 192, 248, 181,  91,  64,
     188, 181,  99,   6, 173, 181, 104,  14 };

const byte Sound_C2_EN [32] PROGMEM = {
       0,  32,  47,  47,   0, 153, 248,   0,  68, 203, 189,  19, 170, 204, 142, 192,
      85, 204, 150, 193, 101, 203, 142, 192,  40, 202, 126, 224,  84, 169, 120,   9 };

const byte Sound_C2_ENCORE [108] PROGMEM = {
       0, 108,  47,  47,  42, 175,  32,   0,  42, 170, 124, 189,  42, 170, 126, 160,
      42, 170, 126,  63,  38, 169, 126,  65,  41, 169, 133,  33,  42, 168, 108, 160,
      25, 165,  84,  32,  25, 163,  59, 161,  45, 170,  40,  48,  16, 145, 232, 112,
      17, 177, 213, 176,  37, 178,  45,  37,   1, 142, 142,  32,   5, 170, 158, 191,
      21, 173, 158, 190,  22, 173, 174,  63, 105, 173, 166, 127, 105, 173, 158,  63,
      41, 173, 126,  62, 188, 173, 125, 192, 121, 173, 117, 192, 121, 173, 101,  80,
      42, 172,   4, 208, 194, 179, 236,  80, 199, 178, 232,  12 };

const byte Sound_C2_ENFANT [88] PROGMEM = {
       0,  88,  47,  47,  64, 153, 224,   0, 133, 207, 155, 142, 133, 205, 166,   4,
     102, 202, 150,  32, 194, 202, 182,  64, 198, 201, 174,  64, 102, 200, 126,  32,
     202, 202, 142,  95, 132, 168, 101,  57,  37, 183,   6, 176,  17, 183, 254, 112,
      64, 152, 254, 112,  46, 171, 150,  35,  38, 171, 158,  94,  38, 202, 102,  64,
      39, 202,   6,  95,  39, 169,  77, 191,  99, 170, 116, 160,  22, 167,   4,  64,
      22, 168,   3, 190,  21, 168,   0,  12 };

const byte Sound_C2_ENTER [144] PROGMEM = {
       0, 144,  44,  47, 164, 182, 168,   0, 248, 182, 174,  15, 180, 182, 158,  36,
     164, 182, 158, 160, 180, 182, 159,  32, 184, 182, 159, 223, 188, 182, 151,  27,
     188, 182, 142, 128, 108, 182, 126,  29,  72, 182,  85, 161, 152, 180,  85,  32,
     152, 180,  84, 158, 148, 179,  76,  64,  65, 179,  68,  61,  66, 180,  67,   0,
      68, 180, 128,  48, 128, 214,  96, 112,   0, 149, 251,  16,  16, 213, 245, 176,
      21, 214, 197,  16,  25, 182,  13,  16, 221, 180, 100,  36, 233, 179, 125,  58,
     249, 179, 133,  62, 169, 179, 141,  95, 236, 147, 133,  63, 232, 147, 132, 128,
     232, 147, 132,  32, 173, 146, 140, 157, 237, 146, 141,  63, 253, 146, 132,   0,
     212, 145, 123, 191, 217, 145, 107,  95, 137, 114, 122, 192,  88, 114,  88,  15 };

const byte Sound_C2_ESCAPE [136] PROGMEM = {
       0, 136,  47,  47,  16, 183, 152,   0, 100, 183, 150,  15, 232, 182, 142,  33,
     244, 182, 126,  64, 248, 182, 125, 129, 172, 181, 101,  28, 252, 181, 100, 128,
      16, 185, 181,  48,  16, 214,   5, 176,  20, 183,   5, 240,  80, 183, 245,  48,
      16, 181, 248,  48,   0, 184,   0, 112,   8, 186, 246, 144,   8, 185, 247, 144,
       8, 184, 206, 144, 228, 184,  93, 167, 232, 184, 110, 189, 244, 184, 127,  58,
     248, 183, 143,  61, 248, 183, 143,  95, 248, 183, 135,  63, 248, 183, 134, 159,
     232, 183, 134,   0, 216, 183, 133, 159, 232, 184, 125,  32, 232, 184, 125, 159,
     228, 183, 126,  30, 228, 184, 125, 159, 245, 184,  92, 223, 245, 184,  84,  63,
     217, 151,  67,  64, 217, 150,  72,  14 };

const byte Sound_C2_ESPACE [152] PROGMEM = {
       0, 152,  43,  47,  16, 183,  88,   0, 168, 182, 134,  15, 228, 182, 134,  32,
     244, 183, 126, 160, 248, 182, 127,  33, 248, 182, 127,  63, 248, 182, 127, 158,
     184, 182, 127,  26, 184, 182, 118,   0, 152, 182, 109,   0,  85, 183, 134,  80,
      16, 186, 254, 112,   0, 185, 253, 176,  21, 182, 141, 208,  84, 180, 152, 112,
     168, 178, 149, 143, 248, 177, 150,   0, 248, 178, 175,  54, 248, 178, 175, 159,
     185, 178, 183, 190, 184, 179, 183, 223, 184, 179, 183,  32, 168, 179, 182, 158,
     168, 179, 174, 191, 168, 179, 174,   0, 168, 180, 165, 157, 100, 179, 157,  30,
     152, 178, 132, 176,  20, 182, 117,  80,   4, 182, 189, 112,  20, 181, 172, 240,
      89, 181, 124,  48, 232, 179, 115,   0, 232, 178, 115,  63, 228, 179, 122, 160,
      80, 146, 114,  95,  80, 147,  56,  15 };

const byte Sound_C2_ESSAY [72] PROGMEM = {
       0,  72,  47,  47, 169, 184,  93, 128, 250, 184, 102, 165, 249, 184,  94,  64,
     169, 184,  77,  32,  89, 184,  60, 176, 101, 216, 117,  48,  16, 216,  92, 176,
       1, 153, 254,  80,   1, 153, 254,  80,  21, 215, 206, 208, 101, 215,  94,  39,
     253, 182, 127,  64, 122, 183, 119, 127, 182, 216,  94, 224, 181, 216,  86, 127,
     230, 182,  77,  64,   1, 178, 152,  24 };

const byte Sound_C2_EST [28] PROGMEM = {
       0,  28,  47,  47,  20, 181, 104,   0, 233, 183, 134, 161, 233, 183, 134,  96,
     233, 183, 134,  64, 228, 182, 126,  64, 228, 183, 104,  30 };

const byte Sound_C2_EST_CE [52] PROGMEM = {
       0,  52,  47,  47,  20, 181, 104,   0, 233, 183, 134, 161, 233, 183, 134,  96,
     233, 183, 134,  64, 228, 182, 126,  64, 228, 183, 109, 191,  68, 184, 109, 160,
      89, 182, 142, 112,  20, 215, 126,  80,   0, 186, 109, 240,   0, 186, 109,  80,
      16, 180, 104,   0 };

const byte Sound_C2_ET [36] PROGMEM = {
       0,  36,  47,  47,   0, 153, 248,   0, 148, 184,  91,  12, 248, 185,  93, 192,
     229, 185,  94,  64, 229, 185,  94, 192, 228, 185,  94, 223, 164, 185,  94,  60,
     180, 153,  96,   0 };

const byte Sound_C2_ETRE [88] PROGMEM = {
       0,  88,  47,  47,   0, 153, 248,   0,  84, 182, 171, 135, 253, 182, 158,  32,
     233, 182, 150, 160, 250, 182, 151,  65, 168, 183, 135,  64, 244, 183, 118,  33,
     232, 183, 117, 191, 233, 183,  92, 190, 161, 215, 100,  63, 192, 215, 104, 112,
     128, 153, 112, 112,   1, 185, 251, 176,   4, 183, 253, 176,  23, 181, 253, 176,
     128, 186, 253,  80, 129, 150, 253,  80,  37, 177, 244, 208,  25, 175,   4, 208,
      85, 177, 148,  48,  25, 176,  96,  27 };

const byte Sound_C2_EU [36] PROGMEM = {
       0,  36,  47,  47,   0, 208,   0,   0, 254, 180, 100, 187, 209, 180,  93, 223,
     217, 180,  86,  33, 209, 213,  94,  64, 197, 181,  85, 192, 190, 180,  85, 192,
     190, 180,  80,  12 };

const byte Sound_C2_EXACTE [172] PROGMEM = {
       0, 172,  47,  47,   0, 153, 248,   0, 180, 183, 158,  39, 184, 183, 150, 134,
     168, 184, 127,  66, 232, 185, 126, 162, 152, 184, 101,  32, 164, 184,  96,  16,
     176, 153, 120,  48, 160, 217,  64,  80,  16, 118,  84,  48,  20, 150,  50, 144,
      85, 184,  44, 191,  20, 183,   5,  29,   5, 184,   5,  94,  21, 183,   5, 144,
       4, 182,   5, 208,  24, 181,  37,  61, 105, 181, 110, 164, 105, 181, 127,   2,
     169, 181, 159, 192, 169, 181, 175,  22, 165, 148, 175,  61, 180, 149, 166, 188,
     185, 149, 149, 190, 188, 149, 132, 128, 168, 149, 155, 144, 160, 149, 154,  16,
     160, 181, 144,  16, 128, 215, 120, 112, 132, 183, 146,  16,   4, 183, 229,  16,
       8, 151, 245, 144,  32, 153, 252, 144,   0, 184, 250,  16,   0, 184, 248,  16,
       0, 184, 248,  48,   0, 184, 248,  80,   0, 183, 211, 144,  85, 215, 221,  48,
      85, 182, 189,  80,  90, 181, 172,  48,  90, 181, 168,   5 };

const byte Sound_C2_EXCLAMATION [160] PROGMEM = {
       0, 160,  47,  47,  20, 181, 104,   0, 233, 183, 134, 161, 233, 183, 134,  96,
     233, 183, 134,  32, 180, 151, 118,  32,  20, 150,  61, 240,  16, 150,  61, 240,
      16, 150,  61, 144,  24, 149, 150, 176,   4, 150,   5, 176,  20, 182, 109,  16,
     164, 181,  93,  35, 233, 180,  93, 160, 248, 181, 126, 191, 248, 181, 151,  63,
     185, 180, 159,  95, 185, 148, 142, 128,  72, 147,  85,  33,  72, 146,  85,  64,
     152, 147, 142,  32, 168, 180, 150, 191, 168, 180, 150, 192, 108, 181, 142,  32,
      85, 183, 124, 240,   5, 177, 196, 240,   9, 182, 253,  48,   9, 184, 253,  80,
       9, 217,   5, 176,  25, 186,  77, 176,   8, 184,  29, 176, 153, 183,  77, 144,
     246, 150,  84, 191, 245, 117,  92,  32,  84, 143,  92, 192,  84, 142, 100,  29,
      68, 169, 107, 160, 128, 148, 131,  32, 128, 182, 130, 128, 129, 150, 128,   5 };

const byte Sound_C2_EXEMPLE [144] PROGMEM = {
       0, 144,  47,  47, 148, 184, 186, 128, 232, 184, 149,  47, 245, 184, 142, 192,
     181, 185, 110, 193, 217, 185,  84,  32, 212, 185,  74,  63, 200, 152,  73, 190,
      84, 149,  80,  64, 254, 151,  83, 187, 185, 182,  84, 223, 106, 182,  76, 190,
     106, 181,  60,  60,  85, 181,  27, 223, 170, 179,  92,  65, 106, 178, 125, 193,
      41, 178, 150,  63,  37, 174, 174,  95,  53, 204,  45,  95,  37, 169, 189,  95,
     133, 173, 196, 192,  37, 168, 164, 191,  36, 168,  51, 191,  21, 167,  67,  32,
      73, 162, 122, 191,   0, 175, 136,  80,   0, 175, 136, 112,  16, 149,  48, 112,
      20, 182,  13, 144,  40, 181, 101,  48, 108, 181, 100, 161, 109, 180, 108, 192,
     185, 179, 147, 160, 169, 179, 138, 160,  89, 177, 130,  63,  94, 177, 120,  14 };

const byte Sound_C2_EXERCICE [136] PROGMEM = {
       0, 136,  47,  47,   0, 153, 248,   0, 228, 185, 111,  64, 216, 185,  85, 222,
     208, 186,  51, 160,  96, 151,  76, 192, 180, 183,  61,  32, 165, 184,  69, 192,
     217, 184,  86,  35, 164, 183, 103,  65, 228, 183, 119, 192, 228, 183, 119, 160,
     180, 183, 127,  95, 169, 181, 102,  32,  32, 181,   7,  48,  64, 186, 254, 240,
      38, 215, 182, 112, 223, 217,  78, 240, 222, 217,  69, 146, 212, 216,  61,  64,
     228, 217,  60, 223, 233, 185,  60, 222, 105, 185,  69, 144,  30, 184,  94,  48,
      21, 216, 102, 112,  21, 215, 102, 112,  30, 215, 110, 112,  37, 181, 101, 176,
     165, 181, 109,  13, 233, 180, 108, 161, 217, 181, 116, 145, 216, 181, 124,  32,
     148, 180,  75, 142,  80, 212,  88,  14 };

const byte Sound_C2_F [52] PROGMEM = {
       0,  52,  47,  47,  20, 183, 160,   0, 168, 183, 149, 133, 245, 183, 150,  32,
     249, 183, 142,  64, 233, 183, 142, 223, 165, 183, 135,  95, 189, 150, 118,  61,
     104, 149, 133,  29,  16, 183, 149, 240,  64, 182, 157, 112,   1, 182, 164, 240,
      17, 184, 152,  12 };

const byte Sound_C2_FACILE [120] PROGMEM = {
       0, 120,  47,  47,  37, 183,   0,   0,  17, 183, 253, 112,  64, 152, 254, 112,
      22, 182, 254,  16,  22, 182, 222,  48,  22, 182, 157, 142, 170, 180, 142,  32,
     187, 181, 158, 160, 185, 181, 150, 223, 181, 181, 134,  63, 105, 183, 141, 208,
     149, 215, 149,  48, 149, 215, 140, 176, 165, 216, 124,  80,  85, 216, 132, 208,
      90, 184, 148, 208,  14, 218, 124, 208, 174, 216,  77,  48, 234, 216,  60, 223,
     230, 217,  60, 223, 239, 216,  60, 192, 234, 215,  60, 194, 241, 182,  68, 193,
     181, 213,  68, 193, 101, 182,  76, 161, 101, 181,  84,  65, 101, 181,  84,  32,
     101, 181,  84,  60, 101, 181,  80,  18 };

const byte Sound_C2_FAIRE [104] PROGMEM = {
       0, 104,  46,  47,  37, 183,   0,   0,  17, 183, 253, 112,  64, 152, 254, 112,
      22, 182, 254,  16,  22, 182, 222,  48, 168, 181, 134, 192, 253, 182, 143,  96,
     249, 182, 126, 223, 248, 183, 126, 127, 248, 183, 126,  64, 249, 183, 118,  94,
     233, 183, 117,  60, 249, 183, 117,  95, 185, 183, 117,  64, 121, 183, 117,  66,
     169, 182, 117,  66, 249, 182, 117,  16, 102, 181,  85,  48,  64, 152, 133,  16,
     128, 186, 125,  48,  32, 179, 125,  48, 160, 179, 125,  80,  33, 180, 124, 176,
      21, 179, 124, 208,  21, 178, 120,  15 };

const byte Sound_C2_FAIS [48] PROGMEM = {
       0,  48,  47,  47,  37, 183,   0,   0,  17, 183, 253, 112,  64, 152, 254, 112,
      22, 182, 254,  16,  22, 182, 222,  48, 168, 181, 134, 192, 253, 182, 143,  96,
     249, 182, 134, 223, 248, 183, 134, 127, 248, 183, 134,  64, 249, 183, 112,  12 };

const byte Sound_C2_FEMME [108] PROGMEM = {
       0, 108,  47,  47,  37, 215, 248,   0,  16, 215, 254,  16,  16, 215, 254,  48,
      17, 216, 254, 208,  17, 216, 254, 208,  17, 214, 238, 208, 149, 179, 134,  61,
     234, 178, 150, 160, 170, 179, 175,  95, 170, 179, 183,  95, 106, 179, 175,  64,
      86, 178, 167,  64,  86, 178, 150, 160,  70, 179, 126,  32, 133, 182,  85,   1,
     137, 182,  69,  33, 133, 184,  69, 192, 138, 184,  61, 192, 153, 184,  70,  65,
     154, 184,  70,  65,  72, 181,  69, 192,   8, 179,  86,   3, 103, 177, 126,  32,
      86, 180, 125, 160,  90, 181,  92, 192,  86, 181,  80,   0 };

const byte Sound_C2_FLECHE [116] PROGMEM = {
       0, 116,  47,  47, 116, 184,  88,  32,  37, 183,   5,  48,  17, 183, 254, 112,
      64, 152, 254,  80,   0, 183,   5, 164, 152, 182, 101,  32, 104, 181, 101, 129,
      44, 181,  94, 161, 105, 182, 135, 160, 165, 182, 143, 192, 165, 183, 135,  95,
     185, 183, 118, 222, 249, 182, 109, 187, 165, 183, 117,  32,  17, 185,  77, 128,
      10, 185, 255,  16,  10, 185, 255,  48,  21, 217, 255,  80,  25, 218, 175,  80,
      21, 217, 254, 208,  69, 219, 254, 144,  68, 220, 254,  48,   8, 220, 253, 208,
      28, 218, 253,  80,   8, 217, 252, 176,   8, 218, 252,  48,   1, 153,  67, 176,
       0, 184,  80,  11 };

const byte Sound_C2_FOIS [72] PROGMEM = {
       0,  72,  47,  47,  65, 153, 248,   0,  16, 184, 246,  48,  16, 217, 198, 176,
      69, 183, 246, 208,   4, 146, 222, 208,  65, 148, 205, 176, 133, 135, 132, 160,
      70, 166, 125,  64, 134, 170, 125, 191,  74, 169, 150,  32, 198, 174, 150, 191,
     158, 176, 166, 192, 138, 177, 159,  64, 154, 177, 166, 192, 150, 176, 166,  33,
      86, 176,  93,  32,  38, 176,  64,   2 };

const byte Sound_C2_FONCTION [124] PROGMEM = {
       0, 124,  47,  47,  16, 181, 248,   0,  17, 182, 245, 144,  80, 182, 246,  48,
      17, 180, 254,  80,  85, 182, 238, 176,  85, 181, 238,  80,  69, 182, 229, 176,
     146, 170, 133,  34, 132, 172, 174,  32, 136, 171, 174,  64,  72, 178, 141, 191,
      72, 179, 100, 191, 129, 212,  68, 192,  69, 174, 107, 188,  17, 175, 118,  48,
      17, 183, 119,  48,  21, 217, 119,  48,  17, 218, 119,  48,  34, 186, 118, 208,
      33, 219, 118, 208,   9, 185, 119,  80,  21, 185, 118, 208, 149, 183,  94,   1,
      85, 147, 126,  64,  68, 141, 149, 192,  69, 175, 157,  32,  69, 170, 148,  33,
       8, 178, 140,  33,  65, 185, 115, 160,  68, 180, 104,   3 };

const byte Sound_C2_FRANC [88] PROGMEM = {
       0,  88,  47,  47,  17, 182, 232,   0,  17, 214, 230,  16,  65, 185, 255,  80,
      82, 182, 222,  80,  65, 178, 220, 176, 130, 172, 220, 176,  18, 173, 212, 176,
      67, 182, 245,  48,   1, 249, 245,  48,  70, 186, 205, 176,  70, 172, 150, 189,
     150, 172, 143,  64,  86, 204, 151,  95,  22, 199, 174, 192,  66, 200, 166, 192,
      69, 168, 175,  65, 106, 200, 109, 163,  69, 164, 116,  34,   5, 163,  99, 165,
      68, 187,  51,  64,  64, 186,  80,  18 };

const byte Sound_C2_G [60] PROGMEM = {
       0,  60,  47,  47, 165, 183,  72,   0,  21, 183,  20, 190,   1, 185,   5,  32,
       1, 185, 254, 208,   5, 184, 254, 208,   4, 183, 255,  80,  40, 183,  63,  33,
     117, 184, 103,  64, 117, 184, 103,  32, 117, 184, 102, 224, 245, 185, 101,  64,
     233, 185, 100, 155, 165, 184,  84,   1, 164, 185,  80,   6 };

const byte Sound_C2_GAUCHE [88] PROGMEM = {
       0,  88,  47,  47,  54, 171,   0,   0,  55, 171,   5, 134,  50, 171,   4, 128,
      68, 116, 149,   0, 169, 140, 110,  32, 165, 171, 110, 160, 169, 171, 109, 160,
     169, 171, 109, 192, 173, 170, 109, 192, 174, 170, 109, 223,  32, 178,   5,  48,
     132, 184, 254, 176, 132, 185, 254, 176, 129, 185, 254, 208, 133, 218, 254, 240,
      64, 216, 254, 112,  33, 181, 214,  16, 160, 179, 116, 191, 208, 179, 116,  32,
     228, 179, 124,  32, 164, 179, 120,   0 };

const byte Sound_C2_GRAND [68] PROGMEM = {
       0,  68,  47,  47,  41, 160,   0,   0,  68, 152, 252, 185,  41, 180,   5, 176,
      90, 180,  70,  34, 153, 181, 109, 162,  21, 180,  94,  29,  38, 177,  70,  63,
      70, 178, 126,  32,  94, 176, 142,  64, 110, 174, 158, 193, 174, 174, 166, 192,
     171, 172, 158,  64, 154, 171, 141, 192,  26, 170, 149, 191,  20, 165, 116,  64,
      69, 167, 120,   9 };

const byte Sound_C2_GUILLEMET [120] PROGMEM = {
       0, 120,  47,  47,   1, 214,   0,   0,  85, 212,  44,   6, 242, 217,  53,  64,
     244, 249,  45,  96, 248, 249,  44, 160, 242, 249,  44,  30, 179, 217,  60,  63,
     216, 249,  52,  64, 225, 217,  44, 160, 233, 185,  53, 163, 250, 184,  54,   0,
     169, 150,  78,  63, 152, 149,  77, 154, 136, 148,  76, 128, 136, 148,  76, 192,
     200, 150,  76, 192, 136, 148,  84, 192, 169, 181,  94,  32, 185, 182, 118, 191,
     169, 182, 127,   0, 169, 182, 135,  32, 105, 182, 143,  64, 185, 183, 135,  32,
     232, 182, 117, 160, 201, 181,  93,  31, 217, 183, 101,  32, 216, 183, 100, 160,
     213, 183,  84,  32, 137, 151,  96,   3 };

const byte Sound_C2_H [68] PROGMEM = {
       0,  68,  47,  47, 166, 178, 208,   0, 250, 178, 206,   7, 233, 179, 198,  64,
     183, 179, 199,  95, 103, 179, 191,  62, 107, 180, 191,  32, 106, 180, 182, 191,
      41, 180, 174,   0, 107, 180, 133,  16,  10, 181,   6,  48,   0, 185, 254, 176,
       0, 185, 254, 208,   0, 186, 246,  48,   0, 186, 254,  48,   0, 187, 254, 112,
       0, 186, 248,   3 };

const byte Sound_C2_HA_NOM [80] PROGMEM = {
       0,  80,  47,  47,  84, 179, 192,   0, 149, 176, 182,  66, 102, 178, 207,  64,
     102, 178, 207,  95, 106, 180, 183,  95, 106, 180, 134, 191,  90, 180,  45, 191,
     158, 180,  44, 193, 222, 180,  60, 193, 153, 179,  61,  36, 162, 211, 117, 162,
     166, 173, 125, 193, 132, 174, 141, 194, 133, 178, 125, 192, 197, 180, 117, 221,
     197, 179, 124, 220, 133, 179, 108,  61, 128, 213,  91,  63, 132, 214,  88,   8 };

const byte Sound_C2_I [32] PROGMEM = {
       0,  32,  47,  47, 248, 249,  48,   0, 248, 249,  46, 196, 248, 249,  38, 160,
     248, 249,  38, 192, 248, 249,  38, 223, 248, 249,  38, 222, 248, 249,  32,  28 };

const byte Sound_C2_IL [60] PROGMEM = {
       0,  60,  47,  47,   0, 183,   0,   0, 209, 186,  70, 192, 225, 216,  54, 192,
     228, 217,  62, 192, 246, 217,  62, 192, 104, 217,  54, 222, 226, 183,  78, 192,
     226, 182,  78,  64, 230, 182,  78,  64, 234, 181,  78,  95, 237, 181, 118, 223,
     189, 180, 126, 222, 106, 180, 142, 138, 173, 180, 136,  14 };

const byte Sound_C2_INEXACTE [172] PROGMEM = {
       0, 172,  47,  47, 212, 216,  80,   0, 212, 216,  85,  14, 213, 216,  94,  39,
     218, 184,  94, 160, 153, 181,  85, 160, 152, 181,  85, 192, 232, 183, 110, 161,
     232, 183, 127,  32, 233, 183, 135, 192, 229, 184, 127,   1, 212, 185, 118, 160,
      96, 186, 109,  32,  68, 185,  82, 160, 132, 151,  80,  80,  84, 150,  84,  33,
      89, 183,  76, 222, 149, 182,  84,  30,  21, 182,  68,  95,  21, 182,  68, 159,
     105, 181,  93, 162, 169, 181, 110, 162, 185, 181, 135,  32, 165, 181, 143, 157,
     101, 181, 175, 224, 102, 181, 175,  27, 165, 181, 167,  32, 165, 149, 142,  32,
     168, 149, 133, 160, 164, 149, 108, 160, 160, 149, 121,  48, 160, 182, 144,  80,
      64, 215, 112, 112,  64, 215, 112, 112,   0, 183, 112,  16,  20, 213, 112,  80,
     232, 180, 117,  34, 237, 180, 134,  95, 168, 180, 133, 223, 164, 179, 141,  62,
     169, 179, 132, 190, 148, 178, 115,  62, 132, 177, 112,  30 };

const byte Sound_C2_INFERIEUR [192] PROGMEM = {
       0, 192,  47,  47, 100, 180, 192,   0, 100, 180, 194, 143, 164, 180, 188,   1,
     164, 180, 173, 128, 165, 180, 174,   0, 165, 180, 174, 128, 100, 180, 182, 192,
     168, 180, 174, 160, 104, 180, 166, 191, 168, 180, 166,  30, 100, 179, 149, 155,
       4, 180, 204, 176,   5, 181, 197,  48,   5, 183, 197,  80,  21, 182, 109,  48,
       8, 182,  13, 176,  41, 183,  54,  48, 233, 183,  93,  41, 249, 183, 101, 189,
     249, 183, 102,  29, 249, 183, 118,  63, 189, 182, 118,  95, 117, 181, 149, 187,
      53, 182,  85, 176,  85, 184,  69, 208, 133, 184,  84, 134, 148, 216,  84,  32,
     149, 183,  67, 128, 165, 215,  64,  96, 229, 215,  68, 131, 229, 215,  77,   0,
     250, 183,  93, 128, 250, 182, 102,   0, 250, 182, 126,  32, 185, 181, 134,  63,
     253, 180, 142,  96, 253, 180, 142,  96, 252, 180, 141, 191, 232, 179, 141,  32,
      37, 177, 205, 208,  53, 176, 205,  16,  53, 177, 172, 176,  37, 177, 156,  30,
      37, 177, 115, 128,  25, 177,  83,   0,  24, 177,  66,   0,  44, 177,  56,  29 };

const byte Sound_C2_INTERROGATION [156] PROGMEM = {
       0, 156,  47,  47, 173, 180, 160,   0, 173, 180, 166, 143, 169, 180, 175,  64,
     168, 180, 159,  32,  88, 180, 150, 189,  92, 176,  84,  60, 128, 179, 128, 112,
       4, 183, 156,  16,   8, 182, 189,  16,  25, 182, 181, 144, 221, 182,  92,  47,
     233, 183,  93,  60, 233, 183, 101, 188, 253, 148, 117, 223, 102, 173, 123, 222,
      86, 170, 112,  80,  86, 169, 115,   7, 170, 170, 124,  32, 170, 170, 124, 161,
     167, 139, 100, 223, 183, 142,  74, 191,  80, 151,  56,  80, 230, 151, 101,  32,
     233, 151, 117, 160, 249, 150, 142, 160, 248, 181, 133, 224,  10, 247, 128,  48,
      11, 247, 130, 144,  10, 247, 132, 208,  10, 247, 132, 240, 154, 183, 100,  64,
     154, 183, 100,  32, 214, 145, 107, 192,  72, 137, 139, 192, 132, 168, 123,  32,
      68, 168, 123,  64, 148, 168, 114, 160, 129, 151, 136,  26 };

const byte Sound_C2_J [40] PROGMEM = {
       0,  40,  47,  47,  30, 186, 120,   0,  30, 186, 125,  32,  30, 186, 117, 160,
      30, 186, 118,  16,  30, 186, 110,  48,  26, 186,  94,  32, 246, 217,  45, 224,
     246, 217,  45, 224, 246, 217,  40,   0 };

const byte Sound_C2_JAMAIS [88] PROGMEM = {
       0,  88,  47,  47,  30, 186, 120,   0,  30, 186, 124,  18,  30, 186, 125,  32,
      30, 186, 117, 160,  30, 186, 118,  80, 160, 213, 118,  66, 160, 180, 142,  64,
     144, 180, 141, 190, 148, 180, 141, 191, 148, 179, 117, 190, 132, 146,  67, 191,
     200, 146,  67, 192, 136, 146,  59,  33, 200, 148,  67, 192, 212, 182, 101,  32,
     233, 183, 109, 160, 228, 184, 101,  96, 209, 185,  93,  64, 208, 185,  84, 162,
     233, 184,  68,  33, 214, 152,  56,  10 };

const byte Sound_C2_JE [72] PROGMEM = {
       0,  72,  48,  47,  16, 218,   0,   0,  17, 187,   6,  48,   9, 182, 254,  48,
      33, 219,  86, 176, 116, 218, 110, 176,   9, 183, 254,  25,  73, 181, 102, 192,
      84, 180, 102, 192, 154, 180, 110, 193, 154, 180, 102,  35, 234, 179, 101,  35,
     234, 179,  92, 162, 231, 180,  92, 161, 129, 180,  83, 160, 129, 180,  59,  34,
     132, 213,  50,  63, 132, 212,  56,  17 };

const byte Sound_C2_JOUR [84] PROGMEM = {
       0,  84,  44,  47,  84, 181,  88,   0,  84, 182, 101, 146,  20, 182,  78,  32,
       0, 184,  54, 160,   4, 184,   6, 208,  32, 218,   6, 208,   4, 184, 254, 208,
       4, 182, 254, 130,  69, 182,  78,  34,  73, 171, 110,  96,  25, 160, 125, 192,
     154, 170,  92, 192, 154, 168,  84, 127, 133, 165, 124, 223,  19, 203, 164, 208,
      35, 173, 149,  80,  66, 178, 221,  80,  82, 206, 196, 176,  66, 176, 236,  48,
      35, 174, 208,  15 };

const byte Sound_C2_JOYSTICK [136] PROGMEM = {
       0, 136,  47,  47, 216, 181,  32,   0,  17, 216,  53, 144,   2, 217,  79,  48,
      17, 218,  71,  48,  86, 182, 111,  34, 169, 148, 127,  32, 166, 146, 143,  63,
     174, 146, 151,  96, 170, 148, 135,  64, 249, 183, 110, 192, 235, 183,  93, 222,
      17, 217, 110,  48,  85, 216, 109, 176, 149, 216, 116, 176, 145, 215, 116,  48,
     144, 216, 112,  80,  80, 215, 192, 112,   6, 216, 165,  16, 174, 216,  84,  48,
     249, 184,  86,  36, 245, 184,  86,  64, 229, 185,  77, 160, 229, 185,  77,  32,
     213, 185,  60,  32, 224, 217,  67,  63, 152, 184,  75,  32, 192, 214,  64, 112,
     192, 214,  64, 112,  20, 185, 229,  16,  88, 185, 166,  48,  21, 184,  85,  80,
      37, 184, 108, 176,  37, 184, 104,   0 };

const byte Sound_C2_JUSTE [112] PROGMEM = {
       0, 112,  47,  47,  16, 118,   0,   0,   4, 117,   4,  16,  17, 181,   5, 144,
      17, 182,   6, 144,  16, 216,   7,  48,  17, 185,   7,  80,  17, 182,   7,  37,
      32, 181,   7,  34, 102, 150,  71,  67, 107, 150,  71,  65, 170, 150,  70, 160,
     170, 182,  70, 160, 148, 215,  69, 160,  88, 215,  45, 176,   5, 181,   6,  80,
       0, 187,   5, 240,   0, 184,   5,  48,  17, 213,   4, 144,  17, 213,   0, 127,
      17, 213,   0,  96,  16, 180,  10, 144,   0, 215,  85, 176, 244, 179, 125,  95,
     210, 178, 125,  63, 153, 179, 125,  32, 165, 179,  84,  61, 165, 179,  80,  22 };

const byte Sound_C2_K [24] PROGMEM = {
       0,  24,  47,  47, 165, 151, 112,   0, 169, 150, 151,  36, 171, 178, 199,  96,
     190, 178, 199,  95, 190, 178, 192,  28 };

const byte Sound_C2_L_ [32] PROGMEM = {
       0,  32,  45,  47, 252, 182,  96,   0, 164, 182, 108,  19, 248, 182,  92, 160,
     232, 182,  93,  32, 248, 182,  93, 193, 248, 214,  94,  33, 245, 214,  86,  65 };

const byte Sound_C2_L_ECRAN [124] PROGMEM = {
       0, 124,  47,  47, 252, 182,  96,   0, 164, 182, 108,  19, 248, 182,  92, 160,
     232, 182,  93,  32, 248, 182,  93, 193, 248, 214,  94,  33, 245, 214,  86,  65,
     165, 214,  78, 161, 233, 183, 111,  33, 232, 184, 119,  32, 229, 185, 103,  64,
     165, 185,  94, 160, 217, 185,  85,  63,  32, 214, 248, 112,  38, 178, 224, 112,
      37, 176, 245, 144,  53, 176, 198,  16,  37, 176,   6,  48,  42, 175,  36, 155,
      22, 173, 125,  32, 105, 173, 149, 160,  42, 172, 150,  32,  42, 170, 126, 192,
      42, 170, 126,  63,  38, 169, 126,  65,  41, 169, 133,  33,  42, 168, 108, 162,
      25, 165,  84,  34,  25, 163,  59, 164,  78, 168,  48,  18 };

const byte Sound_C2_L [60] PROGMEM = {
       0,  60,  47,  47,   0, 153, 248,   0,  84, 183, 163, 134, 168, 183, 157,  64,
     228, 183, 159,  32, 249, 183, 143,  64, 182, 183, 158, 161, 186, 183, 142, 190,
     120, 183, 126, 192, 120, 182, 126, 224, 124, 182, 118,  95, 108, 182, 100, 192,
      60, 181,  92,  63, 124, 181, 122, 191, 189, 181, 144,   4 };

const byte Sound_C2_LA_BAS [84] PROGMEM = {
       0,  84,  47,  47, 248, 181,  96,   0, 248, 181, 100,  18, 248, 181,  84, 128,
     253, 181,  85,  33, 237, 181,  93, 161, 249, 181, 110, 193, 248, 181, 151,  33,
     249, 181, 159,  64, 170, 180, 135,  95, 166, 179, 118,  60, 128, 177,  96,  80,
      17, 181,   0, 112, 150, 179, 134,  40, 170, 178, 151,  61, 233, 179, 167,  95,
     185, 178, 183,  96, 170, 177, 175,  64, 165, 177, 166, 193,  88, 177, 149,  33,
     148, 176, 144,   4 };

const byte Sound_C2_LA [52] PROGMEM = {
       0,  52,  47,  47, 244, 214, 104,   0, 241, 214, 109,  33, 245, 214, 109, 160,
     245, 214, 110,  64, 233, 180, 109, 192, 233, 180, 118,   1, 168, 180, 142, 128,
     249, 180, 158, 128, 250, 180, 174, 159, 250, 178, 182, 224, 169, 177, 182, 192,
      90, 173, 120,  30 };

const byte Sound_C2_LE [52] PROGMEM = {
       0,  52,  47,  47,  84, 182,  32,   0, 249, 149,  85,  58, 153, 150,  77,  32,
     233, 149,  69, 161, 233, 149,  69,  64, 214, 150,  61, 162, 250, 149,  61, 161,
      88, 151,  62, 160, 234, 181,  94, 160, 254, 180, 102, 192, 254, 180, 102,  32,
     233, 180,  96,   4 };

const byte Sound_C2_LES [64] PROGMEM = {
       0,  64,  47,  47, 248, 182,  88,   0, 248, 182,  85,  57, 232, 182,  84, 191,
     248, 182,  85,  32, 240, 182,  85,  65, 244, 214,  86,  34, 228, 214,  86,  65,
     252, 184, 111,  33, 212, 185, 103,  96, 228, 185, 102,  61, 228, 185, 101, 191,
     232, 185,  85,  62, 228, 185,  92,  34, 228, 185,  99, 161, 228, 185,  88,   8 };

const byte Sound_C2_LEUR [96] PROGMEM = {
       0,  96,  47,  47,  21, 181,  88,   0, 106, 181, 117,  18, 229, 181, 117,  59,
     246, 181, 101, 160, 213, 182, 102,  35, 181, 182,  86,  33, 184, 182,  86, 193,
     184, 181,  78,  32, 184, 181,  70,  64, 172, 213, 103,  34, 252, 181, 127,  32,
     252, 180, 135,  64, 233, 180, 143,  64, 249, 180, 135,  96, 253, 180, 135,  64,
     249, 180, 126, 192, 249, 179, 127,  33, 244, 180, 126, 161, 248, 180, 126,  33,
     232, 179, 125, 161, 233, 180, 100, 160, 236, 180, 107, 160, 152, 179,  88,   0 };

const byte Sound_C2_LIVRE [108] PROGMEM = {
       0, 108,  40,  47,  72, 215, 120,   0, 152, 183,  92, 128, 248, 215,  77,  62,
     200, 215,  61,  33, 180, 215,  70,  34, 116, 215,  86, 160,  96, 215,  70, 193,
      98, 186,  54, 192, 101, 185,  54, 224, 109, 151,  70, 223, 110, 150,  78,  24,
     110, 149,  86,  63, 106, 147,  77, 190, 105, 176,  69,  63,  25, 175,  53, 160,
       9, 175,  53, 160,   4, 174,  77, 160,   4, 172, 101, 160, 104, 173, 109,  32,
     122, 173, 101,   0, 185, 175, 117,  64, 169, 176, 125,   0, 168, 175, 125,  32,
     189, 176, 125,  64, 100, 176, 133,   0,  88, 175, 116, 160 };

const byte Sound_C2_M [72] PROGMEM = {
       0,  72,  47,  47,   0, 153, 248,   0, 100, 183, 164,  14, 244, 183, 134,  37,
     180, 183, 126,  32, 164, 183, 142, 160, 185, 183, 143,  64, 117, 183, 143,  33,
     105, 182, 126, 222, 140, 182,  61,  34, 156, 183,  52, 192, 136, 183,  44, 255,
     141, 182,  36, 255,  78, 179,  12, 254, 106, 177,  93,  64, 105, 178, 157,  64,
     120, 178, 148, 223, 120, 178, 144,  14 };

const byte Sound_C2_MA [64] PROGMEM = {
       0,  64,  47,  47,  68, 182,  64, 128, 136, 184,  66, 186, 132, 183,  59,  32,
     136, 183,  60,  32, 136, 183,  60,  34, 136, 183,  60, 160, 136, 182,  68, 161,
     166, 177, 134,  33, 166, 178, 158, 160, 165, 179, 175,  64, 169, 179, 183, 160,
     165, 178, 183, 192, 149, 178, 182, 192,  98, 146, 157,  63, 100, 178, 152,   6 };

const byte Sound_C2_MADAME [128] PROGMEM = {
       0, 128,  47,  47, 153, 180,  72,   0, 157, 179,  58,   7, 156, 184,  75,  32,
     205, 183,  59, 183,  93, 179,  60, 193,  37, 178,  54, 160, 106, 180, 167,  33,
     185, 181, 167,  64, 184, 182, 142, 160, 184, 182, 118,  32,  64, 219, 248, 112,
     245, 182, 117, 163, 185, 182, 142, 188, 185, 181, 150, 190, 168, 181, 166, 160,
     169, 181, 174, 191, 106, 180, 183,  64, 170, 179, 166, 192, 105, 179, 141, 160,
     153, 179,  84, 160, 153, 181,  68,  65, 153, 183,  76, 161, 137, 182,  69,  64,
     153, 182,  69,  65, 148, 181,  76, 161, 136, 180,  76,  65,  90, 179, 132, 194,
      85, 181, 124, 193,  89, 180,  99, 160,  21, 179,   3,  32,  20, 181,   0,  17 };

const byte Sound_C2_MAINTENANT [128] PROGMEM = {
       0, 128,  47,  47, 196, 181,  64,   0, 197, 183,  59,  59, 196, 183,  59,  35,
     197, 183,  60, 163, 197, 183,  60, 161, 197, 151,  60, 192, 197, 182,  69,  32,
     132, 181, 102,  33, 228, 181, 166, 224, 208, 180, 142,  65, 212, 179, 117,  60,
     129, 179, 124,  32, 208, 213, 104,  48, 196, 213, 112,  80,  86, 184, 168, 112,
      86, 182, 198,  48,  87, 182,  54,  48, 203, 182,  93, 160, 197, 175,  75, 190,
     213, 177,  67,  63, 201, 178,  67,  64, 206, 179,  59, 158, 201, 182,  59, 160,
     216, 178, 109,  64, 132, 176, 132, 192, 150, 173, 132, 192, 217, 172, 132, 160,
     134, 169, 140, 161,  82, 172, 140, 192, 101, 170, 140, 192,  37, 170, 136,   4 };

const byte Sound_C2_MAIS [60] PROGMEM = {
       0,  60,  47,  47, 220, 180,  48,   0, 220, 179,  50, 185, 204, 181,  50, 192,
     204, 180,  43,  65, 200, 178,  43, 162, 200, 181,  52,  64, 189, 183, 110,  62,
     184, 184, 118, 162, 185, 184, 127,  32, 172, 184, 118, 192, 148, 185, 109, 192,
     236, 185, 101,  94, 220, 185, 108,  32, 216, 185, 120,  14 };

const byte Sound_C2_MAISON [104] PROGMEM = {
       0, 104,  47,  47,   0, 153, 248,   0,   4, 181,  66, 185,  68, 184,  84, 192,
      68, 183,  61,  64,  69, 150,  61,  65,  69, 149,  45, 162, 102, 183, 103,  32,
     118, 184, 103,  33, 182, 184, 103,  64, 249, 184,  94, 161, 186, 183,  94,  64,
     186, 183,  77, 190, 187, 183,  85,  63, 166, 215,  84, 222, 119, 214,  60, 160,
      39, 182,   4, 191,   3, 181,   5, 192,  86, 212, 109, 163,  85, 179, 125, 161,
      68, 174, 125, 192, 133, 171, 133,  64, 136, 208, 125,  96, 132, 209, 116,  34,
     128, 184, 114, 161, 132, 216, 112,   4 };

const byte Sound_C2_MAJUSCULE [148] PROGMEM = {
       0, 148,  47,  47, 204, 179,  56,   0, 200, 178,  58, 139, 204, 151,  50, 160,
     216, 145,  59,  34, 148, 179, 108, 128, 168, 181, 150,  64, 168, 181, 150, 128,
     185, 181, 126, 192, 120, 181, 118,  23,  36, 182,  86,  62,  21, 182,  30, 112,
     181, 150,  76, 164, 168, 182,  76, 223, 188, 182,  68,  61,  85, 188,  44, 144,
       4, 187,  68, 176,  38, 182, 252, 240,   1, 185, 253,  80,  32, 152, 252, 144,
      32, 184, 230, 144,  33, 152, 174,  16,   5, 149,   5,  16,  33, 152,  37,  16,
     165, 184,  60,   4, 217, 120,  59, 160, 233, 151,  68,  30, 169, 151,  68, 190,
     169, 151,  85,  95, 249, 150,  76,  95, 229, 150,  75, 157, 224, 214,  67, 160,
     181, 150,  51, 192, 237, 182,  59, 192, 252, 181,  67, 192, 190, 180,  67,  96,
     172, 180,  88,  13 };

const byte Sound_C2_MANETTE [100] PROGMEM = {
       0, 100,  59,  47, 200, 181,  32,   0, 132, 182,  59, 146, 196, 183,  59, 193,
     132, 180,  60, 160, 153, 179, 142, 162, 164, 181, 167,  64, 168, 182, 151,  64,
     152, 181, 126, 160, 136, 181,  77, 160, 136, 181,  69,  32, 136, 180,  60, 160,
     132, 183,  69, 161, 168, 183, 118, 160, 164, 183, 135,  32, 164, 183, 143,  64,
     164, 183, 143,  65, 164, 183, 127,  34, 228, 183, 117, 162, 209, 185, 124,  32,
     192, 214,  64, 112,  33, 182, 208, 112, 102, 182, 190,  48,  43, 181, 166,  16,
     246, 180, 107,  68 };

const byte Sound_C2_MATIN [92] PROGMEM = {
       0,  92,  47,  47, 205, 179,  40,   0, 136, 181,  51, 190, 140, 181,  45,  64,
     136, 181,  54,  65,  73, 183,  70, 192,  73, 181,  70, 192, 105, 179, 111,  35,
     184, 181, 175,  64, 168, 182, 167,  64, 152, 181, 101, 192, 212, 181, 136,  48,
     129, 152, 144, 112,  86, 181, 120, 112, 169, 180, 118, 129, 168, 180, 150,  95,
     169, 180, 158, 222, 101, 180, 158, 192, 165, 179, 158, 192, 100, 179, 150, 193,
     180, 178, 108,  66,  64, 141,  82, 164,   0, 173,  16,  17 };

const byte Sound_C2_ME [56] PROGMEM = {
       0,  56,  47,  47, 200, 182,  44,  59, 137, 182,  52, 160,  69, 183,  45,  32,
     137, 182,  45,  32,  72, 183,  45, 192,   0, 180,  46,  34,  38, 178,  62, 160,
      26, 180,  78, 160,  90, 180, 110, 192, 171, 179, 110,  62, 169, 179, 109,  32,
     175, 179,  75, 190, 106, 180,  80,  14 };

const byte Sound_C2_MERCI [76] PROGMEM = {
       0,  76,  47,  47, 132, 186,  72,   0, 148, 185,  75,  17, 208, 185,  51, 191,
     165, 183,  85,  66, 164, 151, 126,  64, 228, 151, 126, 192, 169, 150, 118,  63,
      32, 181, 246, 189,  68, 186, 254, 208,  64, 217, 254, 208,  80, 220, 101, 208,
      16, 214, 101, 208,  26, 216, 101, 208, 245, 217,  69, 171, 249, 217,  70, 192,
     229, 217,  69, 194, 209, 217,  43, 161, 209, 217,  40,  17 };

const byte Sound_C2_MES [64] PROGMEM = {
       0,  64,  47,  47, 136, 181,  48,   0, 204, 179,  43, 222, 152, 181,  52, 192,
     156, 180,  52, 192,  72, 181,  45,  64, 169, 182, 110, 161, 173, 184, 127,  64,
     233, 185, 119,  64, 232, 185, 118, 160, 232, 185, 110, 192, 164, 185, 102,  33,
     132, 186, 101,  33, 216, 186,  83, 161, 132, 187,  59,  37, 132, 186,  56,  22 };

const byte Sound_C2_MESDAMES [148] PROGMEM = {
       0, 148,  47,  47, 200, 179,  32,   0, 204, 180,  33, 158, 204, 184,  35, 161,
     204, 184,  35, 193, 204, 183,  35, 194, 201, 183,  44,  66, 137, 182,  45,  38,
     185, 184, 102, 160, 169, 185,  94, 193, 168, 217, 111,  64, 185, 185,  77, 188,
     212, 184,  66, 160, 212, 184,  72,  16,  64, 182,   0, 112,  88, 182,  84,  17,
     253, 183, 118,  62, 233, 182, 142, 189, 249, 181, 166, 190, 185, 180, 182, 191,
     254, 179, 182,  63, 190, 179, 198,  64, 189, 179, 181, 223, 105, 178, 149, 191,
     110, 178,  68, 190, 157, 179,  44,  32, 157, 179,  28,  64, 158, 179,  43, 160,
     217, 178,  34, 192, 222, 180,  35,  64, 223, 180,  59,  64, 158, 180,  51, 192,
     166, 177,  67,  64, 189, 177, 115, 160, 185, 178, 147, 160, 185, 178, 147, 160,
     189, 178, 144,  15 };

const byte Sound_C2_MESSIEURS [112] PROGMEM = {
       0, 112,  47,  47, 200, 184,  56,   0, 204, 183,  43,  20, 204, 183,  43,   0,
     204, 184,  35, 195, 204, 183,  36,  65, 204, 184,  45,  35, 204, 183,  53,  66,
     148, 184,  70, 161, 185, 184,  95, 192, 248, 185,  95,  34, 232, 184,  78,  63,
     185, 184,  69,  64, 175, 184,  69,  16, 167, 216,  76, 208,  91, 215,  69, 112,
      79, 217,  61, 240, 107, 184,  61, 240, 245, 183,  77, 221, 230, 152,  78,  95,
     213, 151,  86,  95, 209, 151,  86,  95, 145, 182,  94,  32, 166, 181,  94,  64,
      86, 181,  85, 192, 214, 181,  84, 160, 213, 181,  83, 130, 192, 151,  80,   0 };

const byte Sound_C2_MET [60] PROGMEM = {
       0,  60,  47,  47, 132, 152,  56,   0, 132, 151,  61,  61, 144, 184,  61,  32,
     144, 153,  69,  63,  80, 183,  69, 161, 165, 182, 119,   0, 181, 182, 127,  32,
     185, 183, 127,  32, 185, 183, 127,  64, 169, 183, 127,  65, 148, 184, 110,  65,
     212, 184,  93,  33, 132, 153,  68,  36, 132, 183,  56,  20 };

const byte Sound_C2_METTRE [108] PROGMEM = {
       0, 108,  47,  47, 200, 181,  48,   0, 140, 182,  66, 148, 204, 181,  59, 160,
     204, 182,  60, 192, 148, 181,  77,  66, 169, 182, 134, 160, 185, 183, 151, 192,
     184, 183, 143,  33, 232, 183, 134, 192, 248, 184, 118,  61, 228, 183, 108, 191,
      20, 215, 224,  80,  21, 215,  72, 112,  64, 181,  96, 112,  16, 183, 116,  16,
      20, 216, 238,  16,  21, 215, 230, 144,  21, 215, 158,  16,   2, 181, 254,  80,
      33, 178, 253, 208, 106, 178, 125,  94,  90, 177, 132, 223,   5, 175, 123, 192,
     106, 177,  98, 223,  37, 177,   0,  12, 101, 177, 144,  14 };

const byte Sound_C2_MI [48] PROGMEM = {
       0,  48,  47,  47,  80, 217,  56,   0, 137, 146,  58,  31, 201, 139,  42, 160,
     202, 150,  43, 192, 201, 151,  45,  64, 142, 148,  53,  65, 136, 214,  70,  64,
     136, 248,  70,  96, 130, 217,  77, 192, 212, 245,  59,  95, 128, 247,  56,   1 };

const byte Sound_C2_MIDI [64] PROGMEM = {
       0,  64,  47,  47, 137, 148,  64,   0, 137, 148,  70,  65, 137, 148,  69, 160,
     146, 183,  79,  32, 133, 215,  79,  64, 197, 216,  70, 191, 192, 217,  61,  62,
     144, 185,  75, 160, 128, 184,  48,  80, 222, 216,  24, 112, 237, 217,  44, 176,
     250, 217,  36, 187, 245, 217,  36, 192, 233, 217,  44, 224, 217, 217,  32,  12 };

const byte Sound_C2_MIEN [68] PROGMEM = {
       0,  68,  47,  47, 144, 152,  40,   0, 160, 184,  44, 223,  84, 215,  53, 160,
     164, 215,  69, 193, 164, 215,  78,  32, 164, 214,  86,  65, 164, 214,  94, 161,
     169, 215, 103,  32, 185, 182, 135,  64, 169, 181, 159,  95, 100, 180, 167,  95,
     100, 180, 166, 191,  84, 180, 174,  62,  84, 213, 141,  62,   4, 176, 100,  63,
      68, 178, 128,  14 };

const byte Sound_C2_MIEUX [68] PROGMEM = {
       0,  68,  45,  47,   0, 153, 248,   0, 144, 212,  67,  24, 128, 181,  60,   0,
     144, 217,  44,  32, 144, 216,  44, 160, 137, 150,  52, 192, 129, 151,  53, 161,
     144, 186,  62,  32, 128, 185,  62,  64, 148, 185,  70,  64, 148, 185,  78, 191,
     169, 183,  95,  32, 104, 182, 103,  64, 169, 180, 119,  64, 105, 179, 111,  96,
     105, 180, 104,   4 };

const byte Sound_C2_MOI [68] PROGMEM = {
       0,  68,  47,  47, 200, 180,  24,   0, 200, 183,  27,  17, 196, 184,  19, 162,
     132, 216,  29,  64, 136, 216,  29,  65, 200, 216,  45, 194, 196, 217, 102,  64,
     196, 220, 118, 193, 193, 187, 142, 193, 196, 214, 166, 160,  84, 209, 150, 191,
      85, 175, 174, 191, 106, 173, 190, 223, 169, 174, 198, 222, 169, 175, 198,  60,
     169, 175, 184,  15 };

const byte Sound_C2_MOINS [84] PROGMEM = {
       0,  84,  47,  47, 204, 180,  32,   0, 201, 183,  43,  62, 201, 184,  27, 160,
     132, 183,  36,  34, 136, 217,  36,  32, 136, 215,  37,  64, 200, 215,  45, 193,
     136, 215,  54,  35, 200, 215, 102,  33, 197, 215, 118, 193, 196, 210, 150, 193,
     132, 204, 167,  64, 101, 174, 167,  64, 106, 177, 183,  95, 105, 178, 198, 222,
     105, 179, 198, 191, 105, 179, 198, 223, 101, 179, 190,  62, 101, 179, 157,  61,
     165, 179, 144,   8 };

const byte Sound_C2_MON [84] PROGMEM = {
       0,  84,  47,  47, 204, 177,  48,   0, 200, 181,  59, 160, 204, 181,  43, 160,
     200, 178,  36,  32, 201, 182,  44, 160, 201, 183,  45, 160, 201, 183,  37, 161,
     201, 184,  37, 192, 201, 183,  46,  65, 202, 183,  54,  64, 201, 183, 102,  32,
      70, 173, 142,  34, 130, 177, 158,  64, 133, 178, 158,  64, 133, 174, 150,  28,
     133, 174, 150,  64, 133, 174, 150,  95, 128, 184, 141,  63, 133, 196, 124,  62,
     133, 196, 120,   4 };

const byte Sound_C2_MONSIEUR [96] PROGMEM = {
       0,  96,  47,  47,  64, 182,  56,   0, 144, 185,  83, 145, 196, 184,  44, 189,
     208, 185,  52, 162,  84, 181,  94, 193,  84, 181, 103,  64, 144, 213, 102, 161,
     144, 213,  86,  64, 118, 216, 134, 144,  57, 184, 126, 208,  22, 183, 150, 208,
      14, 185, 254, 240,   8, 184, 255,  80, 245, 183,  77, 192, 230, 152,  78,  64,
     213, 151,  86,  95, 209, 151,  86,  64, 145, 182,  94, 161, 166, 181,  94,  64,
      86, 181,  85, 193, 214, 181,  84, 160, 213, 181,  83, 128, 192, 151,  80,   9 };

const byte Sound_C2_MOYEN [80] PROGMEM = {
       0,  80,  47,  47, 196, 175,  48,   0, 136, 181,  51, 186, 137, 211,  44,  65,
     137, 213,  61, 193, 136, 165, 149, 192, 106, 174, 134, 192, 166, 180, 143,  64,
     165, 184, 119,  64, 233, 216,  86,  95, 233, 216,  61,  94, 234, 216,  68, 192,
     249, 184,  94,  65, 245, 183, 118, 192,  85, 180, 142, 192, 106, 179, 159,  64,
     169, 177, 142,  64,  98, 146, 141, 195, 170, 178,  84, 193,  89, 177,  88,  28 };

const byte Sound_C2_MOT [48] PROGMEM = {
       0,  48,  47,  47,  84, 251,  48,   0, 132, 185,  59, 186, 140, 183,  52,  65,
     141, 181,  52, 192, 141, 182,  61,  64, 137, 182,  61,  65, 158, 170, 117,  63,
     158, 168, 117,  64, 173, 168, 101,  95, 234, 167, 100,  32, 169, 167,  80,  10 };

const byte Sound_C2_N [88] PROGMEM = {
       0,  88,  47,  47, 128, 150, 248,   0, 244, 183, 173,  15, 248, 183, 157, 164,
     229, 183, 157, 192, 244, 183, 158,  63, 249, 183, 158, 192, 250, 183, 158, 223,
     234, 183, 150, 191, 155, 183,  77,  95, 207, 182,  68, 191, 207, 183,  60, 223,
     143, 183,  44, 191, 143, 182,  12, 223, 143, 182,  44, 224,  79, 182,   4, 223,
     207, 181,  59,  94, 140, 181,  58, 192,  70, 181,  76, 191, 170, 180, 140, 192,
     185, 179, 123, 192, 181, 179, 120,  15 };

const byte Sound_C2_NE [68] PROGMEM = {
       0,  68,  47,  47, 136, 182,  40,   0, 141, 182,  50, 192, 142, 182,  35, 192,
     141, 182,  36, 192, 141, 182,  45,  66, 142, 182,  45, 192, 142, 182,  53,  65,
     137, 183,  53,  65,  74, 182,  46,  35,  22, 181,  62, 160,  21, 180,  71,  32,
      41, 180,  86, 224,  89, 180, 118,  61, 165, 179, 100, 189, 137, 179,  99, 190,
     153, 179,  80,  26 };

const byte Sound_C2_NOMBRE [120] PROGMEM = {
       0, 120,  49,  47, 213, 179,  48,   0, 212, 180,  43,   1, 216, 179,  43, 160,
     216, 180,  44,   0, 232, 180,  44, 128, 237, 180,  45,  65, 222, 179,  45, 224,
     158, 180,  46,   9,  90, 180,  62,   1, 102, 179, 110,   1, 105, 177, 142,  32,
     134, 172, 158,  64, 133, 174, 158,  64, 133, 174, 142,  65, 132, 175, 134,   2,
     133, 179, 126,  34, 133, 180, 110,  33,  73, 178,  93, 162,  72, 179,  85,  34,
      76, 175,  84, 190, 140, 176,  51,  63,  64, 181,  96,  93, 149, 170,  99, 128,
      85, 174, 100,  64, 170, 174, 108,  95, 163, 174, 116,  62, 169, 176, 124,  64,
     153, 175, 116,  62, 148, 177, 100,  63 };

const byte Sound_C2_NOM [60] PROGMEM = {
       0,  60,  47,  47,  84, 251,  48,   0,  80, 187,  51, 148, 132, 185,  59, 128,
     140, 183,  52,  65, 141, 181,  52, 192, 141, 182,  61,  64, 137, 182,  61,  65,
      21, 179, 110, 160,  21, 174, 150, 192,  73, 175, 166,  64,  68, 209, 157, 191,
     129, 150, 156, 190,  20, 194,   2, 191,  69, 194, 128,  12 };

const byte Sound_C2_NOS [72] PROGMEM = {
       0,  72,  47,  47, 213, 179,  48,   0, 212, 180,  43,   1, 216, 179,  43, 160,
     216, 180,  44,   0, 232, 180,  44, 128, 237, 180,  45,  65, 222, 179,  45, 224,
     158, 180,  46,   9,  90, 180,  62,   1, 102, 179, 110,   1, 105, 177, 142,  32,
     129, 176, 126, 221,  74, 169, 126, 223, 154, 168, 118,  62, 173, 168, 101,  61,
     234, 167, 100,  32, 169, 167,  80,  10 };

const byte Sound_C2_NOTE [96] PROGMEM = {
       0,  96,  47,  47, 141, 180,  48,   0, 141, 181,  61,  33, 141, 182,  61, 161,
     141, 181,  61, 193, 157, 180,  61, 160, 108, 213,  87,  33, 168, 180, 143, 160,
     168, 179, 151, 160, 105, 178, 151,  63, 104, 178, 151,  64, 169, 179, 134, 190,
     169, 180, 125,  32, 192, 178, 120, 112, 128, 217, 120, 112,   0, 214, 192, 112,
       0, 215, 173, 176,  37, 213,   6,  80, 149, 182, 101, 176, 233, 181,  92,  57,
     184, 180,  84,  95,  89, 179,  83, 192,  89, 178,  26, 160,  24, 177,   0,  14 };

const byte Sound_C2_NOTRE [100] PROGMEM = {
       0, 100,  47,  47, 204, 180,  48,   0, 204, 180,  44,  20, 201, 182,  44, 161,
     202, 181,  45,  64, 137, 179,  37,  64, 137, 182,  54,  34, 105, 179, 118, 160,
     102, 178, 126, 191,  37, 176, 134, 192,  37, 176, 142, 192, 122, 177, 142, 163,
     186, 177, 126,  32, 245, 210, 101,  32, 130, 209, 112, 112,   2, 216, 176, 112,
      82, 185, 254,  16,  17, 185, 254, 176,  18, 178, 197, 208, 130, 151, 253, 208,
      38, 209, 237,  80, 123, 177,  84,  48, 186, 177,  84,  40, 186, 177,  83, 160,
     186, 177,  80,  18 };

const byte Sound_C2_NOUS [56] PROGMEM = {
       0,  56,  47,  47, 136, 182,  80,   0, 196, 185,  60, 185, 206, 184,  45, 163,
     205, 179,  53,  64, 205, 182,  45, 162, 206, 179,  45, 192,  69, 180,  87,  64,
     137, 181,  95,  65, 205, 180,  94, 192, 141, 174,  93, 223, 141, 172,  76, 189,
     141, 173,  51, 191, 137, 177,  72,  12 };

const byte Sound_C2_NUMERO [112] PROGMEM = {
       0, 112,  47,  47, 192, 184,  40,   0, 144, 215,  44,  64, 148, 215,  45,  33,
     233, 215,  45, 193, 153, 215,  46,  34, 149, 184,  62, 162, 165, 184,  62, 193,
     229, 152,  61, 161, 149, 149,  61,  32, 137, 146,  52,  63, 132, 150,  52, 191,
     132, 149,  52, 223, 149, 182,  86,  32, 181, 183, 111,  62, 181, 183, 119, 191,
     185, 184, 119, 224, 169, 183, 127,  61, 105, 181, 118,  63,  37, 178,  54,  48,
      37, 175, 165, 208,  17, 171, 220, 176, 146, 168, 108,  61, 234, 168,  99, 160,
     150, 168, 107, 192, 214, 168,  99,  64, 214, 166,  90, 160, 214, 165,  96,   8 };

const byte Sound_C2_O [36] PROGMEM = {
       0,  36,  47,  47,   0, 153, 248,   0,  64, 174, 132,  15, 217, 168, 117,  32,
     169, 167, 109,  32, 153, 198, 109,  96, 237, 166, 100,  59, 217, 165,  99, 159,
     148, 165,  88,  28 };

const byte Sound_C2_ON [32] PROGMEM = {
       0,  32,  47,  47,   0, 153, 248,   0,  89, 200, 158, 160, 133, 169, 150, 224,
     136, 208, 126, 224, 196, 211, 117,  60, 129, 185, 116,  32, 128, 177, 128,   8 };

const byte Sound_C2_OPTIQUE [112] PROGMEM = {
       0, 112,  45,  47,  90, 177, 152,   0, 234, 176, 142, 160, 251, 177, 143,  32,
     251, 177, 143,  64, 251, 176, 127,  63, 186, 176, 118,  32, 149, 174,  88,  48,
     129, 182, 112, 112,   5, 182, 190, 176,   1, 182, 254, 176,  80, 218, 248, 112,
       4, 182, 213,  16,  21, 216, 190,  48, 234, 216,  61,  63, 250, 217,  70, 190,
     249, 217,  71,  32, 186, 217,  63,  96, 182, 217,  54, 191, 230, 218,  45,  60,
      64, 216,  40,  80,  64, 216,  40,  96,   4, 182, 253,  16,   4, 186, 255, 176,
       4, 186,  46,  16,  20, 186,   5,  48, 117, 184, 124, 176, 117, 184, 120,  15 };

const byte Sound_C2_OR [68] PROGMEM = {
       0,  68,  50,  47, 185, 175, 120,   0, 169, 175, 133, 222, 169, 174, 134,  96,
     253, 174, 142,  64, 185, 174, 142, 195, 185, 174, 141, 163, 182, 174, 125,  33,
     255, 173, 116, 162, 249, 173, 116,  32, 186, 174, 100,  65, 186, 174, 100,   2,
     106, 173,  60,  32,  38, 175,  61,  48,  22, 176,  69,  80,  38, 175,  68, 208,
      39, 176,  64,  17 };

const byte Sound_C2_OU [28] PROGMEM = {
       0,  28,  47,  49,  21, 179,   0,   0,  70, 168,  94,  96,  70, 168,  94,  96,
      67, 200,  93,  93, 130, 213,  84, 223, 146, 182,  80,  12 };

const byte Sound_C2_OUI [64] PROGMEM = {
       0,  64,  47,  47, 152, 164,  80,   0, 157, 164,  74,  18, 132, 166,  74,  65,
     128, 177,  75,  34,  80, 172,  83, 161, 165, 173,  76,  34, 170, 175,  68, 161,
     166, 181,  69, 161,  91, 184,  63,  32, 123, 185,  63,  63, 187, 217,  62, 191,
     250, 217,  70,  62, 245, 217,  53, 190, 153, 218,  52,  95, 136, 218,  64,  12 };

const byte Sound_C2_P [52] PROGMEM = {
       0,  52,  47,  47,  69, 151, 248,   0, 166, 150,  93,  39, 170, 150, 110, 129,
     186, 183, 119,  32, 169, 183, 119, 189, 249, 184, 119, 191, 181, 184, 111, 223,
     245, 184, 111,  64, 249, 184, 102, 191, 245, 184,  93, 160, 225, 184,  84,  32,
     233, 184,  80,  31 };

const byte Sound_C2_PARENTHESE [172] PROGMEM = {
       0, 172,  45,  47,  20, 180, 192,   0, 169, 175, 157, 166,  88, 175, 174, 129,
     188, 176, 182, 160, 188, 177, 183,  95, 124, 176, 183,  63, 121, 176, 174,  61,
      41, 175, 189, 189, 101, 142, 165,  48,  40, 140, 165,  48,  37, 171, 149,   7,
      88, 170, 165,  32,  89, 170, 157,  32, 149, 170, 149,  32, 134, 169, 149,  64,
     134, 170, 149,  34, 106, 173, 125,  64,  90, 173, 109,  27,  88, 173, 108,  28,
     128, 151, 144, 112, 168, 180, 112,  96, 188, 180, 117, 143, 252, 180, 134,   3,
     252, 181, 134, 128, 188, 181, 143,   0, 189, 181, 151, 159, 189, 181, 151, 160,
     125, 181, 151, 191, 121, 182, 143, 192, 121, 182, 135, 192, 185, 182, 135,  32,
     189, 182, 127,  64, 188, 182, 118, 191, 124, 181, 102,  63, 124, 181,  85, 157,
     124, 181,  93,   0, 188, 181, 109,  62, 185, 180, 101, 112, 181, 180, 100, 191,
     249, 179, 115, 160, 249, 179, 123, 160, 233, 179, 123,  63 };

const byte Sound_C2_PARFAIT [116] PROGMEM = {
       0, 116,  47,  47,   0, 153, 248,   0,   0, 152, 122, 143,  89, 176, 174, 160,
     188, 177, 183,  64, 184, 177, 166,  32, 105, 177, 141, 160,  38, 177, 165, 176,
      33, 176, 181, 176, 101, 176, 181, 144,  22, 175, 189, 176,  85, 180, 189,  48,
      85, 180, 213,  16,  84, 182, 229,  80,  20, 179, 213,  48,   4, 180, 197,  80,
      21, 181, 213, 176,   5, 182, 213, 144,  25, 181, 181, 176,  21, 181, 165, 176,
      26, 181, 125, 176, 165, 179, 109,  63, 168, 180, 142, 160, 184, 182, 150, 221,
     184, 183, 134,  57, 212, 183, 124,  32, 212, 184, 115, 160, 228, 184, 107,  32,
     164, 184,  96,  13 };

const byte Sound_C2_PARLER [88] PROGMEM = {
       0,  88,  49,  47,  16, 213,   0,   0,   1, 214, 253, 144, 169, 178, 142,  33,
     154, 178, 158, 160, 154, 179, 175,  95, 170, 178, 182, 192,  86, 177, 174,  32,
      86, 175, 150,  60,  22, 177,   6,  48,  22, 178, 118,  48,  88, 179, 126,  48,
      88, 178, 117,  37, 168, 180,  93,  65, 169, 181,  77,  65, 104, 214,  69, 163,
     248, 183, 102,  34, 232, 184,  94,  65, 233, 184,  93, 191, 233, 184,  93, 192,
     214, 150,  92,  32, 208, 184,  88,  17 };

const byte Sound_C2_PASSER [68] PROGMEM = {
       0,  68,  45,  47, 150, 149, 128,   0, 217, 179, 150,   6, 232, 180, 150, 223,
     232, 181, 133, 223, 216, 181, 141,  62, 154, 183, 142,  48, 148, 216, 157, 208,
     185, 215, 157, 208, 123, 215, 157,  80,  27, 184, 157, 208,  63, 183, 149,  80,
     254, 183,  92, 223, 248, 183,  93,  95, 248, 184,  84, 223, 248, 184,  92, 192,
     249, 184,  88,  15 };

const byte Sound_C2_PENSER [96] PROGMEM = {
       0,  96,  47,  47,   5, 149, 200,   0,  22, 179, 174,   5,  85, 173, 150,  32,
      21, 168, 166, 192,  69, 173, 174, 192,  68, 174, 166, 223,  89, 175, 142, 191,
      65, 178, 117, 191,  86, 215, 125, 161,  16, 247, 125, 208,  20, 215, 109, 240,
      22, 214, 101, 240, 249, 182, 101,  32, 245, 182, 102,  63, 245, 183, 102, 190,
     182, 184, 102, 192, 246, 184,  94, 192, 246, 184,  94,  32, 242, 184,  93, 161,
     230, 184,  92, 161, 233, 184,  83, 160, 210, 184,  83,  33, 209, 184,  80,   1 };

const byte Sound_C2_PETIT [80] PROGMEM = {
       0,  80,  47,  47,   0, 150, 248,   0, 102, 183, 230, 144,  22, 182, 239, 144,
      43, 180,   6, 144, 107, 180, 110,  63, 111, 180, 111,  32, 171, 180, 103,  64,
     186, 182, 102, 223, 187, 182,  93,  62, 153, 181,  80,  80,   0, 249, 176, 112,
      13, 216, 221, 176,  26, 217, 126,  48,  31, 217,  85, 176, 238, 217,  61,  37,
     250, 217,  61,  93, 250, 217,  52, 192, 229, 217,  35, 192, 245, 217,  56,  12 };

const byte Sound_C2_PEUT_ETRE [104] PROGMEM = {
       0, 104,  47,  47,   2, 147,  80,   0,   2, 179,   5, 158, 150, 181, 110,  64,
     149, 182,  86,  64, 196, 183,  96,  96,  37, 215, 200, 112, 249, 182, 118,  80,
     249, 182, 126, 189, 186, 183, 134, 223, 182, 183, 135,  64, 186, 183, 126, 160,
     246, 183, 126,  34, 245, 183, 109,  33, 208, 184,  92, 163, 182, 183, 100,  32,
     209, 216, 120,  80, 192, 183,  96, 112,  82, 185, 253, 144,  17, 185, 253, 176,
      18, 178, 196, 208,  38, 209, 236,  80, 123, 177,  83,  48, 186, 177,  82, 165,
     186, 177,  82,  32, 186, 177,  80,  22 };

const byte Sound_C2_PLUS [80] PROGMEM = {
       0,  80,  45,  47,   5, 178, 176,   0,   5, 178, 182,  16,  17, 179,   5,  14,
     100, 148,  85, 128,  97, 116,  78, 160, 116, 117,  62, 192, 117, 117,  53, 190,
     104, 149,  79,  34, 186, 149,  87,  32, 187, 150,  79,  64,  37, 151,   6, 255,
      21, 151,   6, 150, 100, 183,  70,  32,  82, 218,  78,  48,  10, 181,   6,  80,
      10, 181,   5, 176,   2, 183,   5, 208,   2, 186, 205,  48,   2, 182, 165,  48 };

const byte Sound_C2_POIGNEE [108] PROGMEM = {
       0, 108,  47,  47,   5, 183,   0,   0,   4, 183, 221, 176,   0, 185, 252,  16,
       0, 152, 252,  48,  64, 150, 115,  15,  22, 165,   4,  41,  23, 167,  29,  32,
      91, 174, 134,  32,  26, 176, 142,  32,  26, 179, 158, 160, 101, 183, 150, 192,
     105, 183, 126,  63, 152, 182,  77, 160, 148, 182,  60, 190,  80, 184,  60, 223,
     136, 150,  60,  94,  96, 185,  68,  61, 164, 249,  60, 190, 152, 249,  69,  95,
     152, 217,  77,  95, 105, 217,  94,  95, 105, 217, 110,  63, 185, 185, 117, 160,
     245, 184, 101,  95, 229, 184,  92,  64, 185, 185,  72,  13 };

const byte Sound_C2_POINT [72] PROGMEM = {
       0,  72,  47,  47,   0, 152, 224,   0,  65, 110, 246, 176,  80, 174, 230,  16,
       1, 109, 229,  63,  64, 173, 108, 160,  64, 172, 125, 159, 132, 172, 125, 160,
      68, 171, 166,  64,  20, 168, 158, 191,  85, 175, 174, 192, 100, 144, 174, 160,
     117, 177, 182, 160, 166, 177, 182, 160, 101, 178, 174, 194, 102, 178, 158,  34,
      85, 177, 132,  32,  85, 177, 128,  25 };

const byte Sound_C2_POSITIONNE [188] PROGMEM = {
       0, 188,  47,  47,  81, 184, 248,   0,  65, 152, 253,   1, 186, 175, 118,  32,
     171, 177, 111,  32, 169, 148, 103,  64, 166, 182,  94, 191, 234, 182,  86,  32,
      21, 245, 116,   1,  21, 245, 116, 128,  21, 245, 116, 128,  21, 245, 117,   0,
      21, 245, 117, 128,  21, 245, 117, 128,  21, 245, 118,   0,  21, 245, 118,   0,
     234, 182,  86,  32, 235, 183,  85, 191, 174, 183,  77, 223, 166, 184,  78,  32,
     173, 184,  70,  64, 110, 185,  53, 192, 154, 183, 142,  48, 148, 216, 157, 208,
     185, 215, 157, 208, 123, 215, 157,  80,  27, 184, 157, 208,  63, 183, 149,  80,
     249, 183,  94, 160, 181, 183, 103,  32, 165, 182, 119,  63, 214, 181, 127,  63,
     154, 148, 135,  63, 169, 179, 143,  64, 166, 180, 135,  64,  89, 180, 127,  33,
      73, 180,  70,  32, 136, 180,  69, 161, 152, 179,  69,  66, 152, 179,  69,  66,
     136, 180,  69,  64, 136, 179,  76, 160, 132, 182,  92, 161,  72, 181, 108, 160,
     148, 179,  68, 192, 148, 181,  28,  33, 149, 180,   8,  20 };

const byte Sound_C2_POUR [60] PROGMEM = {
       0,  60,  46,  47, 192, 182,  64,   0,   1, 183, 253,  16,   1, 179, 254, 144,
      37, 146, 253, 208, 154, 170,  92, 222, 154, 168,  84, 127, 141, 167,  92,  64,
     133, 165, 124, 224,  19, 203, 164, 208,  35, 173, 148, 208,  66, 178, 220, 208,
      82, 206, 196, 176,  66, 176, 236,  48,  35, 174, 208,  15 };

const byte Sound_C2_POUR_CENT [112] PROGMEM = {
       0, 112,  47,  47,   4, 180, 160,   0,  25, 132, 117,  39, 155, 168, 117, 192,
      91, 167, 125, 159,  27, 166, 117, 189,  22, 163, 116, 160,  38, 165, 116,  29,
      38, 167,   4,  48,  70, 169, 147, 176,  33, 173, 188, 176,   2, 175, 189, 176,
      86, 178, 206,  16,  18, 180, 230,  48,  17, 181, 222,  80,  20, 181, 173, 192,
      89, 178, 133, 143, 170, 175, 126,  61, 106, 174, 150,  59,  43, 205, 150,  32,
      38, 203, 158,  63,  37, 203, 158,  95,  33, 202, 158,  32,  17, 202, 158,  63,
      16, 169, 173, 160,  16, 170, 157,  30,  17, 169,  12, 160,  17, 169,   8,   7 };

const byte Sound_C2_PREMIER [104] PROGMEM = {
       0, 104,  47,  47,  34, 170,   0,   0,  39, 170, 132, 144, 134, 174, 196, 176,
     130, 174, 227, 176,  38, 171,   3,  14,  23, 172, 118,  32,  39, 173,  70,  32,
     171, 180, 102,  32, 171, 180, 102,  64,  73, 148,  69, 160, 136, 150,  69,  64,
     137, 150,  61,  32, 136, 151,  60, 192,  82, 152,  45,  32, 104, 248,  53, 192,
     165, 248,  62,  64, 169, 216,  94, 191, 122, 216, 102, 160, 122, 184, 119,  63,
     117, 184, 118, 192, 165, 184, 110,  62, 245, 184, 109, 191, 229, 184, 100, 160,
     224, 184,  83, 192, 208, 217,  80,  28 };

const byte Sound_C2_PRENDRE [92] PROGMEM = {
       0,  92,  47,  47, 133, 186, 232,   0, 137, 174, 229, 176,  25, 170,   5,  32,
      22, 171, 182,  32,  26, 171, 190, 161,  69, 175, 199,  64,  70, 175, 199,  95,
      26, 169, 198, 223,  27, 169, 198,  95,  26, 170, 182,  64,  26, 173, 158,  95,
      94, 175, 142,  63,  31, 176, 117,  32,  17, 178,  80, 112, 110, 177, 125, 160,
      25, 174,   5,  32,  42, 176,   4, 160,  42, 176, 157,  64, 106, 176, 148,  33,
      42, 175,   3,  32,  26, 175,  66, 128,  27, 176,  16,  14 };

const byte Sound_C2_PRENOM [100] PROGMEM = {
       0, 100,  47,  47,  17, 178, 248,   0,  66, 183, 229,  16, 133, 185, 253, 176,
     129, 184, 254,  48,  22, 180,  46, 176, 149, 181, 109, 166, 170, 182, 119,  32,
     170, 183, 127,  64, 105, 183, 119,  60, 106, 182, 102, 190,  90, 181,  69, 223,
      74, 182,  69, 191,  74, 182,  69, 192,  25, 177, 118,  95,  40, 174,  77,  28,
      40, 174,  77,   0,  40, 174,  77,   0,  40, 174,  77,   0,  40, 174,  77,   0,
      25, 170,   4, 160,  29, 167,   4,  32,  40, 165,   3, 160,  40, 163,   3,  32,
      28, 160,   0,  14 };

const byte Sound_C2_PROBLEME [152] PROGMEM = {
       0, 152,  48,  47, 134, 171, 176,   0,  91, 137, 116,  39,  27, 165, 149,  40,
      27, 169, 149, 162,  91, 167, 150,   0, 154, 170, 125, 160, 154, 170, 125, 192,
     170, 170, 117,  28, 169, 171,  83, 184, 169, 171,  80,  95, 152, 144,  92, 158,
     152, 147, 101,   8, 165, 179, 110,  63, 108, 180, 102, 190, 172, 180,  94,  31,
     172, 180,  94,  32, 172, 180, 118, 160, 185, 181, 142, 128, 233, 181, 150, 160,
     233, 182, 150, 192, 229, 182, 150, 192, 169, 182, 142, 192, 169, 182, 142, 131,
     169, 150, 134, 129, 169, 149, 126, 128, 169, 148, 109, 128, 200, 149,  60, 161,
     200, 150,  52,  33, 200, 149,  60,  64, 136, 181,  68,  32, 136, 180,  68,  64,
     136, 179,  60,  33, 136, 178,  68,  32, 152, 178,  76,  33, 152, 177,  75, 160,
     165, 177, 131,  95, 165, 176, 128,  17 };

const byte Sound_C2_PUIS [64] PROGMEM = {
       0,  64,  47,  47, 145, 217, 248,   0, 209, 218, 254,  16, 144, 185, 254, 144,
     128, 152, 253, 152,  32, 151, 190,   0,  38, 151,   6, 192,  38, 150,   6, 161,
      22, 150,   7,  33,  50, 184,   7, 192, 118, 217,  31, 160, 118, 217,  63,  32,
     182, 217,  54, 191, 181, 217,  46,  63, 109, 217,  29,  62, 110, 217,  24,  12 };

const byte Sound_C2_PUISSANCE [128] PROGMEM = {
       0, 128,  40,  47,  37, 181,   0,   0,  37, 182, 198,  16,  52, 182,   6,  48,
     235, 151,  54,  70, 235, 184,  54, 160, 230, 216,  54, 192, 157, 217,  62, 222,
       9, 183,   7,  80,   4, 181, 214, 176,  21, 183, 214, 208,  21, 182, 222,  80,
      40, 182, 246, 176,   8, 181, 222,  80, 169, 180, 118,  35,  90, 178, 150, 189,
      22, 174, 174, 221, 102, 173, 166, 160,  22, 172, 174, 223,  38, 172, 166, 191,
      37, 171, 174, 192,  22, 170, 174,  95,  22, 170, 173, 157,  21, 172, 149, 192,
     165, 173, 124, 223, 144, 140,  99,  64,   4, 180,   5,  16,   8, 178,   5, 112,
       8, 178,   5, 112,  29, 179,   4, 208,  12, 176,   3, 208,  24, 179,   2, 176 };

const byte Sound_C2_Q [52] PROGMEM = {
       0,  52,  47,  47,  64, 151, 212, 128,   4, 152, 174, 165,  48, 185,  94,  32,
      33, 184,  54,  32, 182, 152,  62, 160, 166, 152,  63,  32, 114, 151,  47,  95,
     162, 152,  70, 192, 235, 151,  70,  63, 206, 150,  60,  32, 202, 120,  51,  63,
     225, 152,  56,  30 };

const byte Sound_C2_QU_ [24] PROGMEM = {
       0,  24,  47,  47,  21, 185, 168,   0,  90, 185, 125, 129, 233, 185, 102,   0,
     244, 184, 118, 160, 244, 184, 112,  31 };

const byte Sound_C2_QU_EST_CE [68] PROGMEM = {
       0,  68,  47,  47,  21, 185, 168,   0,  90, 185, 125,   1, 233, 185, 101, 128,
     244, 184, 119,  32, 248, 183, 127, 160, 244, 183, 127,  62, 244, 183, 135,  32,
     244, 183, 126, 160, 244, 183, 117, 160, 236, 183,  93,  32,  91, 184, 125, 208,
      86, 184, 125, 208,  86, 184, 133, 208,  22, 183,   5, 176, 144, 186, 253,  80,
      20, 182,   0,   3 };

const byte Sound_C2_QUAND [60] PROGMEM = {
       0,  60,  47,  47,   0, 153, 248,   0,  32, 181, 253, 144,  32, 117, 199, 144,
      33, 150, 134, 144, 113, 180, 125, 190,  70, 147, 142, 160,  70, 144, 166, 160,
       5, 172, 182, 160,  21, 170, 198, 223,  68, 171, 198, 191,   0, 169, 182,  62,
     128, 171, 188, 160,  36, 167, 163, 160,  65, 152, 168,  14 };

const byte Sound_C2_QUE [56] PROGMEM = {
       0,  56,  47,  47,   0, 153, 248,   0,  32, 181, 253, 144,  32, 117, 199, 144,
      33, 150, 134, 144, 113, 180, 125, 190, 233, 150, 101, 191, 234, 149, 101, 190,
     213, 149, 109, 223, 233, 149, 100, 160, 200, 150,  92,  64, 205, 149,  91, 160,
     149, 149,  81, 160, 169, 149,  96,  14 };

const byte Sound_C2_QUEL [60] PROGMEM = {
       0,  60,  47,  47, 133, 153, 248,   0,  21, 184, 253,  16,  22, 184, 135, 176,
     234, 216,  85,   2, 181, 184, 103,   0, 246, 183, 127,  64, 178, 183, 143,  32,
     246, 183, 143,  64, 182, 183, 127,  63, 101, 183, 102, 160, 181, 215,  94,  64,
     165, 215,  85, 160, 150, 184,  85,  64,  66, 184,  96,   0 };

const byte Sound_C2_QUELQUE [92] PROGMEM = {
       0,  92,  47,  47, 133, 153, 248,   0,  21, 184, 253,  16,  22, 184, 135, 176,
     234, 216,  85,   2, 181, 184, 103,   0, 246, 183, 127,  64, 178, 183, 143,  32,
     246, 183, 143,  64, 182, 183, 127,  63, 181, 215,  94,  64, 165, 215,  85, 192,
     150, 184,  85,  64,  34, 214,  48,  80, 209, 215,  96, 112,   1, 150,   4, 144,
      33, 152, 255,  48,  34, 183,   6,  16, 181, 183,  93,  31, 166, 182, 109,  32,
     166, 182, 109,  64, 166, 182, 107, 192, 146, 182, 112,   1 };

const byte Sound_C2_QUESTION [96] PROGMEM = {
       0,  96,  47,  47, 228, 184,  88,   0, 229, 184, 102,  38, 250, 183, 119, 160,
     249, 182, 127, 192, 196, 182, 109, 192, 132, 183, 100, 186, 148, 182, 124, 208,
      64, 216, 140, 240,  65, 184, 131, 176,   0, 218, 248,  16,   0, 218, 248,  80,
       0, 218, 252,  16,  25, 218,   5, 208,  72, 218,  45,  48, 234, 183,  68, 166,
     230, 151,  93, 160, 154, 148, 118,  63,  74, 170, 166,  96, 132, 168, 149, 224,
       5, 165, 116,  64,   9, 160,  99, 191,   4, 160,  99,  31,   0, 182, 112,  25 };

const byte Sound_C2_QUI [56] PROGMEM = {
       0,  56,  47,  47,   0, 153, 248,   0,   8, 216, 246,  16,   4, 216, 223,  48,
      16, 254, 254,  48,   8, 217, 174,  48,  89, 217,  61, 134, 164, 217,  62,  32,
     229, 217,  62, 223, 229, 217,  62,  63, 245, 217,  61, 190, 225, 217,  53, 223,
      72, 213,  60, 192,  29, 211,   0,   8 };

const byte Sound_C2_QU_IL [88] PROGMEM = {
       0,  88,  47,  47,   0, 153, 248,   0,   8, 216, 246,  16,   4, 216, 223,  48,
      16, 254, 254,  48,   8, 217, 174,  48,  89, 217,  61, 134, 164, 217,  62,  32,
     229, 217,  62, 223, 225, 216,  54, 192, 228, 217,  62, 192, 246, 217,  62, 223,
     104, 217,  54, 223, 226, 183,  78, 192, 226, 182,  78,  95, 230, 182,  78,  64,
     234, 181,  78,  95, 237, 181,  77, 191, 238, 181,  85, 192, 237, 181, 117,  64,
     237, 181, 120,   5, 172, 181, 112,  11 };

const byte Sound_C2_QUOI [52] PROGMEM = {
       0,  52,  47,  47, 134, 176, 200,   0, 129, 150, 222,  48,  85, 172, 117,  32,
     150, 171, 109, 160, 222, 139, 117, 160, 221, 173, 134, 191, 154, 175, 159,  64,
     237, 176, 151,  64, 229, 177, 142, 163, 139, 172, 150,  32,  91, 177, 117, 162,
      91, 177,  88,  24 };

const byte Sound_C2_R [72] PROGMEM = {
       0,  72,  47,  47,   0, 153, 248,   0,  84, 183, 171,   2, 232, 183, 157, 160,
     228, 183, 148, 128, 212, 183, 141,  32, 233, 183, 141, 160, 233, 184, 134,  63,
     233, 183, 142, 160, 249, 183, 143,  31, 169, 183, 143,  32, 174, 183, 135,  64,
     109, 182, 134, 161,  89, 182, 134,  33, 189, 180, 133, 160, 172, 180, 124, 188,
     120, 180, 124,   0, 121, 179, 120,   5 };

const byte Sound_C2_RE [64] PROGMEM = {
       0,  64,  47,  47, 113, 179, 104,   0, 113, 179, 108, 133, 102, 180, 109,   0,
     170, 180, 118,   2, 174, 181, 118, 131, 174, 181, 127,   1, 234, 182, 127,  32,
     234, 183, 119,  95, 250, 183, 102, 224, 250, 183, 102, 192, 249, 183,  93, 189,
     224, 152,  92,  32, 201, 148,  99,  32, 200, 181,  98, 160, 192, 186, 104,  31 };

const byte Sound_C2_RECOMMENCE [152] PROGMEM = {
       0, 152,  46,  47,  86, 174,  96,   0,   6, 174,  51, 129,   6, 174,   5,  16,
     129, 180, 237,  80,  33, 174,   5, 176,  17, 206, 101,  34, 107, 176, 118, 163,
      86, 179, 119, 193, 170, 179, 102, 160, 117, 146,  68, 160, 129, 179, 104,  48,
     129, 181, 104,  80, 129, 175, 245,  48,  38, 176, 133,  40, 166, 143, 118,  32,
      90, 173, 127,  94,   9, 172,   6, 189, 136, 180,  38,  63, 137, 182,  62,  64,
      22, 170,   7,  62,  38, 204, 143, 191,  22, 204, 175, 192,  34, 204, 167,  62,
      34, 203, 142, 192,  34, 203, 126,  62,  89, 172, 117,  64,  42, 173,   5,  94,
      22, 173,   4, 191,   0, 215, 133,  80,   0, 213, 157,  80,  21, 181,   5,  80,
       9, 181, 237,  80,   9, 180, 165,  80, 250, 177, 116, 192, 166, 178, 100,  64,
       2, 175,  35, 192,  22, 177,  24,  36 };

const byte Sound_C2_REGARDE [112] PROGMEM = {
       0, 112,  47,  47,   6, 168, 160,   0,  22, 173, 148,  28,  38, 173, 133,  32,
     101, 176, 134, 163, 106, 178, 134, 161, 106, 178, 134, 192,  90, 148, 110, 162,
      43, 150,  38, 191, 133, 150,  60, 191, 142, 147,  51, 160,  21, 182,   0,  80,
      21, 182,   5, 158, 186, 184,  94, 160, 169, 184, 119, 191, 165, 183, 143, 160,
     170, 181, 151,  63, 174, 180, 151,  96, 169, 178, 150,  62, 253, 176, 134,  64,
     174, 175, 117, 192, 130, 211, 104,  48, 130, 211, 104,  80, 166, 211, 101,  48,
     169, 180, 108, 144, 106, 180, 116, 192, 105, 181, 100,  94,  25, 180,  24,  14 };

const byte Sound_C2_REPONSE [164] PROGMEM = {
       0, 164,  47,  47, 105, 180, 104,   0,  89, 180, 118,  48, 169, 180, 117, 142,
     169, 181, 126,   0, 170, 181, 126, 128, 169, 182, 135,  31, 168, 183, 127, 160,
     232, 183, 127,   0, 249, 184, 119,  32, 169, 151, 111,  32, 169, 151, 102,  31,
     153, 149,  92, 128, 144, 184,  72,  16, 208, 184, 120,  80,   0, 119, 112, 112,
       0, 146, 132,   9, 105, 172, 124, 159, 174, 171, 133,  63, 158, 169, 149,  30,
      42, 166, 149, 158, 133, 172, 141, 161, 132, 173, 133, 224, 132, 173, 133, 225,
     132, 173, 141, 128, 132, 173, 141, 160, 132, 173, 141, 128, 132, 173, 125, 160,
     132, 173, 125,  32, 136, 173, 124, 128, 152, 172,  99, 160,  68, 178,  51, 192,
       0, 184,  80,  58,  16, 214,  93,  16,  16, 247, 125,  48,  16, 247, 125,  48,
      16, 247, 133,  48,   0, 247, 132, 144,  16, 247, 156,  48,   4, 246, 155, 176,
       4, 245, 152,  20 };

const byte Sound_C2_RESULTAT [128] PROGMEM = {
       0, 128,  47,  47,   4, 178, 146, 128, 148, 148, 148, 148, 165, 180, 141,  32,
     149, 180, 141, 160, 145, 180, 134,  32, 101, 180, 133, 192, 101, 149, 134, 195,
     165, 149, 135,  35, 164, 181, 135,  36, 165, 182, 127,  34, 184, 182, 118, 160,
     185, 182,  85, 191, 154, 183,  85, 190, 166, 183,  93, 176,  71, 216, 125, 208,
      22, 184,  46, 208, 101, 182,  78, 189,  36, 182,  22,  95, 113, 213,  29, 223,
     101, 214,  53, 222, 161, 182,  64,  80,   4, 216, 200, 112, 101, 214, 150, 176,
     164, 181, 118,  39, 249, 180, 151,  95, 164, 178, 175,  96, 164, 177, 166, 161,
     164, 176, 149, 163,  85, 176, 125,  35, 105, 176,  76, 160, 105, 176,  64,  18 };

const byte Sound_C2_RIEN [72] PROGMEM = {
       0,  72,  47,  47,  33, 180, 224,   0,  38, 181, 254, 176,  53, 181, 222,  48,
     228, 184,  94,  64, 212, 185,  86,  32, 229, 185,  70,  94,  80, 184,  70,  31,
     144, 217,  78,  32, 213, 217,  86,  33, 233, 184, 102,  32, 169, 184, 118, 160,
     121, 183, 142, 192, 169, 181, 150, 192, 168, 181, 158,  61, 100, 180, 133,  32,
      84, 180, 124,  32,  17, 180,  80,  13 };

const byte Sound_C2_S [72] PROGMEM = {
       0,  72,  47,  47, 104, 183, 144,   0, 232, 183, 150, 133, 232, 183, 142,  32,
     228, 183, 142, 192, 248, 183, 143,  63, 249, 183, 143,  63, 184, 183, 143,  63,
     249, 183, 135,  64,  88, 184, 127,  32,  88, 184, 118,   0, 170, 183, 117,  48,
      82, 183, 142, 176,   0, 184, 150,  48, 161, 215, 125, 208, 165, 215, 133,  48,
      18, 215, 148, 208,  17, 183, 144,   1 };

const byte Sound_C2_SA [60] PROGMEM = {
       0,  60,  46,  47,   0, 153, 128,   0,  21, 215, 124, 176,   0, 217, 125,  80,
      20, 214, 125,  80,   5, 184, 125, 208,  22, 183, 126,  80,  22, 183, 126,   0,
     228, 179, 158, 192, 168, 179, 166, 223, 168, 178, 174, 192, 168, 178, 174, 223,
      88, 177, 173, 189, 104, 178, 101,  63, 100, 177, 120,  15 };

const byte Sound_C2_SANS [76] PROGMEM = {
       0,  76,  47,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
       8, 179, 103,  34,  20, 174, 199,  64,  85, 174, 174, 190, 101, 173, 166,  63,
      86, 170, 182,  64,  70, 169, 190,  95,  69, 169, 173,  62,  64, 170, 164,  63,
      64, 139, 147, 159,  80, 167, 130, 128,  84, 166, 112,  13 };

const byte Sound_C2_SAVOIR [128] PROGMEM = {
       0, 128,  47,  47,  64, 153, 248,   0,  72, 185, 252,  48,  64, 185, 252, 240,
      36, 215, 165,  80,  21, 184, 197, 208,  69, 183, 148, 128, 152, 181, 142, 160,
     172, 181, 158, 160, 153, 180, 150, 192, 173, 178, 134,  62,  65, 150, 133,  94,
       4, 141, 108, 192,  22, 137, 100, 162,  74, 168, 125,  64,  26, 169,  85, 161,
      26, 170, 134, 191,  90, 176, 150, 223, 159, 177, 166, 192, 174, 178, 174, 223,
      94, 178, 174, 192, 158, 178, 174,  95, 190, 177, 174,  32, 110, 177, 181, 224,
     109, 177, 173, 144, 190, 177, 165, 176,  89, 178, 133, 208,  37, 177, 156, 208,
      33, 184, 180, 208,  32, 177, 164, 208,  33, 177, 160,   6,  32, 177, 160,  14 };

const byte Sound_C2_SCORE [120] PROGMEM = {
       0, 120,  47,  47,  53, 181,   0,   0,  22, 182,   4, 176,  43, 182, 117,  48,
       6, 214, 253, 208,  64, 187, 253, 208,  80, 185, 251, 176,  16, 212, 248,  80,
      17, 116, 253,  48,   0, 151, 253, 176,  53, 182, 198, 176,  52, 181, 159,  48,
      48, 181,   5, 136,  85, 146, 126, 160,  86, 177, 134, 160,  85, 175, 150, 192,
     154, 177, 158, 224, 174, 176, 150, 224, 110, 175, 142, 161, 233, 175, 141, 161,
     230, 175, 125,  34, 249, 207, 124, 162, 237, 207, 124, 192, 238, 208, 100,  64,
      38, 208,  68,  80,  38, 208, 101,  48,  22, 174, 188, 208,   6, 177,   4, 208,
      22, 175,   0,  25,  22, 173,   0,  19 };

const byte Sound_C2_SE [52] PROGMEM = {
       0,  52,  47,  47,   5, 214, 248,   0,   1, 215, 253, 208,   1, 220, 254,  48,
       4, 216, 254, 112,  89, 180, 102,  63,  90, 180, 102,  32, 106, 180, 110,  64,
     239, 181, 110,  95, 187, 180, 101, 190, 230, 181,  92, 160, 211, 181, 100,  33,
     133, 182,  96,   8 };

const byte Sound_C2_SELECTIONNEE [148] PROGMEM = {
       0, 148,  47,  47,  20, 183, 224,   0,   4, 183, 117,  80,  21, 184, 117, 176,
      37, 183, 118,  48, 165, 183, 102,  32, 180, 183, 110,  32, 180, 182,  94,  63,
     152, 214,  77, 191, 216, 182, 109, 192, 228, 183, 127,  32, 181, 183, 127,  32,
     181, 152, 102, 160, 237, 152,  84,  32, 136, 152,  80,  16, 196, 152, 112,  48,
      16, 119, 109,  16,  96, 215, 109, 176,  68, 184, 102,  80,   8, 184,  94,  80,
       5, 187,  94, 208,  15, 183,  86, 208,  79, 183,  86,   8, 250, 149, 103,  94,
     149, 181, 102, 222, 152, 179,  61,  32, 152, 180,  69,  32, 136, 180,  69,  32,
     137, 180,  61,  32, 137, 180,  61,  32, 233, 182, 126, 192, 233, 183, 127,  64,
     170, 183, 127,  65, 186, 183, 110, 162, 229, 183, 101, 161, 213, 151,  84, 160,
     196, 183,  64,   2 };

const byte Sound_C2_SES [68] PROGMEM = {
       0,  68,  47,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
     244, 182, 102,  94, 246, 183, 118,  95, 249, 183, 110,  64, 245, 183, 110,  64,
     229, 184,  94,  64, 229, 184,  93, 193, 229, 184,  92, 161, 241, 184,  83, 161,
     226, 153,  64,   4 };

const byte Sound_C2_SI [48] PROGMEM = {
       0,  48,  47,  47,  38, 215,  56,   0,   7, 216,  54, 240,  95, 217,  46, 240,
     239, 216,  70, 155, 182, 217,  62, 192, 250, 217,  54, 160, 246, 217,  54, 192,
     245, 217,  54, 188, 233, 217,  61, 223, 105, 216,  37, 164,  89, 216,  56,   9 };

const byte Sound_C2_SI_NOTE_ [76] PROGMEM = {
       0,  76,  47,  47,  64, 184,  40,   0,  21, 182, 230,  48,   9, 183, 246,  48,
       5, 183, 254,  80,  10, 184, 246,  48,  78, 185, 230,  16,  14, 184, 166,   5,
     173, 215,  62,  32, 250, 216,  46,  96, 250, 216,  46,  96, 250, 216,  46,  32,
     250, 216,  46,  32, 250, 216,  45, 160, 250, 216,  45,  32, 250, 216,  44, 128,
     250, 216,  44,   0, 246, 216,  43, 128, 249, 216,  40,  27 };

const byte Sound_C2_SIEN [72] PROGMEM = {
       0,  72,  47,  47,  22, 249, 240,   0,  18, 248, 252, 176,  21, 247, 254,  48,
      17, 248, 255,  16,   5, 248, 255,  48,   5, 247, 255,  80,  32, 251, 254, 208,
     164, 215,  69, 192, 160, 215,  78,  32, 169, 215, 102, 192, 185, 182, 134, 223,
     168, 181, 158, 192, 100, 180, 166, 223,  84, 180, 174,  95,  84, 213, 141,  32,
       4, 176, 100,  63,  68, 178, 128,  14 };

const byte Sound_C2_SIMPLE [128] PROGMEM = {
       0, 128,  47,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
     168, 179, 141, 175, 168, 179, 183, 163, 169, 211, 191, 191, 165, 179, 199, 222,
     166, 179, 207,  94, 165, 179, 182, 221, 165, 179, 174,  61, 101, 178, 157, 189,
     100, 178, 117,  63, 105, 178, 101,  62, 173, 178,  67,  63, 200, 147,  48,  16,
      65, 178,  56, 112,  20, 181,   0, 112,  20, 181,  76,  16,  85, 149,  93,  48,
     228, 181,  91,  33, 152, 182,  92,  63,  92, 182,  85,  32,  88, 180, 125, 160,
     105, 179, 133,  64, 105, 179, 123,  32,  21, 178, 123,  32,  21, 178, 128,  14 };

const byte Sound_C2_SLASH [116] PROGMEM = {
       0, 116,  47,  47,   0, 153, 248,   0,  95, 183, 213,  48,  95, 183, 214,  48,
      95, 183, 215, 112,  88, 183, 214, 144,   4, 184,  78,  16, 228, 213,  76, 194,
     232, 180,  92, 224, 232, 181, 134,  31, 228, 181, 166, 160, 228, 181, 175,  30,
     164, 180, 199,  96, 116, 180, 198, 154, 164, 180, 206, 191, 168, 180, 206,  62,
     100, 180, 197, 159,  80, 180, 173, 191, 100, 180, 172, 191,  84, 179, 144,  80,
      25, 179, 133,  16,  10, 180, 174,  16,  73, 182, 254,  80,  69, 185, 254,  80,
       4, 217, 254,  80, 133, 186, 253, 144,  72, 218, 253,  48,   4, 218, 252, 144,
       4, 219, 248,  12 };

const byte Sound_C2_SOIR [112] PROGMEM = {
       0, 112,  47,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
     149, 174, 100, 188, 130, 169, 108,  32, 214, 170,  99, 192, 214, 172, 125,  32,
     150, 174, 133, 160, 150, 175, 150, 160, 150, 176, 166, 160, 166, 177, 174, 192,
     102, 177, 182, 192,  86, 177, 182, 192, 166, 177, 182, 192, 102, 177, 174, 192,
     166, 176, 158,  65, 154, 176, 149, 160, 102, 177, 125,  33, 107, 177, 109,  33,
      39, 177,  61,  33,  38, 176,   5,  80,  64, 210, 253, 112,  64, 213, 248,  30 };

const byte Sound_C2_SOL [116] PROGMEM = {
       0, 116,  47,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
      69, 213, 109, 142, 166, 179, 117, 128, 234, 179, 126,   0, 171, 178, 134, 128,
     171, 178, 150, 160, 171, 176, 158, 192, 171, 177, 158, 160, 175, 177, 150, 191,
     175, 177, 142, 192, 154, 179, 134, 192, 153, 179, 126,  31, 169, 179, 118,  64,
     168, 179, 109, 160, 168, 180, 109,  31, 236, 179, 101,  32, 236, 179, 100, 160,
     236, 179,  92,   0, 232, 179,  91, 128, 200, 178,  91,  32, 220, 180,  82, 160,
     220, 180,  80,  22 };

const byte Sound_C2_SOLUTION [128] PROGMEM = {
       0, 128,  47,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
      86, 178, 119,  68, 105, 147, 111,  64,  89, 148, 103,  64, 245, 148,  61, 161,
     149, 149,  61,  32, 164, 182,  70,  32, 210, 152,  70, 192, 213, 183,  70,  64,
     153, 183,  69, 222,  18, 216, 253, 176,  21, 215, 254,  48,  17, 216, 255,  16,
       5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208, 171, 150, 101, 192,
     170, 150, 109, 160,  90, 178, 125, 192,   5, 170, 141, 192, 132, 168, 141,  64,
      64, 162, 149,  64, 128, 129, 132, 190,  32, 161, 124,  32,  32, 161, 120,  26 };

const byte Sound_C2_SON [68] PROGMEM = {
       0,  68,  47,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
      70, 173, 150,  95,  69, 177, 158,  95, 129, 179, 150,  64, 133, 177, 150,  64,
     133, 179, 142,  64, 196, 180, 134,  64, 133, 171, 124, 160, 129, 172, 107,  32,
      21, 160,   0,   8 };

const byte Sound_C2_SUITE [104] PROGMEM = {
       0, 104,  47,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
     181, 183,  62,  64, 245, 151,  62,  32, 250, 151,  62, 160, 186, 184,  71,  32,
     247, 184,  63,  32, 250, 217,  71,  64, 250, 217,  70,  32, 226, 217,  68,  62,
     209, 215,  67, 162, 192, 215,  64,  80, 192, 214,  64, 112,  33, 182, 208, 112,
     102, 182, 191, 176,  43, 181, 167, 144, 246, 180, 108, 195, 154, 179, 116, 192,
     154, 178,  92, 130, 138, 177,  88,  18 };

const byte Sound_C2_SUPERIEUR [176] PROGMEM = {
       0, 176,  47,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
     101, 183,  45, 167, 181, 183,  69,  64, 185, 150,  68, 192, 185, 117,  59,  61,
      20, 182,  96,  80, 170, 150, 108,  38, 250, 150, 117,  27, 249, 182, 126,  61,
     185, 182, 134, 190, 185, 181, 142, 192, 185, 181, 142, 224, 106, 181, 142,  32,
      53, 182,  85, 176,  85, 184,  69, 208, 133, 184,  84, 129, 148, 216,  84,  32,
     149, 183,  67, 128, 165, 215,  64,  64, 229, 215,  68, 131, 229, 215,  77,   0,
     250, 183,  93, 128, 250, 182, 102,   0, 250, 182, 126,  32, 185, 181, 134,  63,
     253, 180, 142,  96, 253, 180, 142,  96, 252, 180, 141, 191, 232, 179, 141,  32,
      37, 177, 205, 208,  53, 176, 205,  16,  53, 177, 172, 176,  37, 177, 156,  30,
      37, 177, 115, 128,  25, 177,  83,   0,  24, 177,  66,   0,  44, 177,  56,  29 };

const byte Sound_C2_SUR [64] PROGMEM = {
       0,  64,  46,  47,  22, 217, 240,   0,  18, 216, 252, 176,  21, 215, 254,  48,
      17, 216, 255,  16,   5, 216, 255,  48,   5, 215, 255,  80,  32, 219, 254, 208,
     240, 216,  77, 221, 234, 150,  77, 224,  89, 179,  93, 224, 100, 210, 101,  62,
      50, 175, 245,  48,  70, 176, 237,  48, 134, 184, 252, 176, 134, 184, 248,  15 };

const byte Sound_C2_T [56] PROGMEM = {
       0,  56,  47,  47,   0, 153, 248,   0,  84, 215, 229, 176,  38, 183, 142,  47,
     170, 183,  94, 166, 185, 183, 103,  32, 185, 183, 111,  62, 186, 184, 111,  61,
     186, 184, 103,  94, 186, 184,  94, 223, 250, 184,  94,  63, 245, 184,  84, 160,
     233, 184,  83,  62, 232, 184,  80,  18 };

const byte Sound_C2_TA [40] PROGMEM = {
       0,  40,  47,  47,  16, 186, 248,   0, 233, 181, 126,  33, 233, 180, 143, 160,
     250, 179, 159, 223, 170, 178, 167,  64, 185, 178, 174, 190,  97, 177, 166,  63,
      82, 176, 165, 191, 102, 177, 152,  10 };

const byte Sound_C2_TE [40] PROGMEM = {
       0,  40,  47,  47,  17, 184, 208, 128,  82, 214, 159,  48,  17, 214, 158, 144,
     129, 215, 102,  61, 158, 180,  94, 224, 234, 180,  94, 224, 213, 180,  93,  32,
     213, 181,  84,  32, 133, 181,  80,   6 };

const byte Sound_C2_TEMPS [56] PROGMEM = {
       0,  56,  47,  47,  16, 184, 240,   0,  16, 184, 246, 144,  85, 179, 150, 176,
     170, 176, 126, 191, 170, 175, 142, 160, 164, 175, 158, 189,  85, 174, 158, 191,
      85, 172, 166, 192,  85, 170, 158,  64,  85, 170, 157,  94,  85, 170, 156,  95,
      85, 170, 152,  10,  69, 167, 152,  12 };

const byte Sound_C2_TES [68] PROGMEM = {
       0,  68,  47,  47,   0, 153, 248,   0,   0, 183,   5, 144,   5, 183, 159, 176,
     149, 183, 143,  16, 196, 181,  78,  67, 212, 184,  86, 160, 213, 183,  86, 153,
     229, 183,  94, 156, 213, 184,  94, 160, 212, 184,  94, 158, 212, 184,  94, 160,
     213, 184,  94, 192, 209, 184,  94, 192, 225, 184,  86,  31, 224, 185,  69, 128,
     224, 217,  56,   2 };

const byte Sound_C2_TIEN [44] PROGMEM = {
       0,  44,  47,  47,   9, 217, 232,   0,  10, 218,   5, 176,  89, 217,  45, 176,
      93, 216,  61,   0, 153, 217,  77,  32, 170, 183, 111,  64, 150, 180, 151,  96,
      85, 179, 150, 192, 149, 178, 150,  64, 154, 179, 136,   0 };

const byte Sound_C2_TIRET [120] PROGMEM = {
       0, 120,  47,  47,   0, 213, 200,   0,   4, 213, 205,  16,   8, 209, 141,  16,
       8, 214, 181,  16,  10, 214,   5,  16, 153, 216,  61,  39, 245, 216,  61,  64,
     229, 216,  61,  64, 181, 184,  69, 159, 170, 184,  85, 160, 170, 184,  94,   0,
     170, 184,  94, 128, 110, 183, 111,  32,  46, 182, 118, 189,  36, 181, 110,  61,
      37, 181,  86,  16, 101, 181, 118,  48, 105, 180, 126,  48, 121, 180, 125,   0,
     121, 181, 133, 132, 189, 181, 142,  33, 189, 181, 142, 128, 185, 181, 158, 192,
     104, 182, 142, 223, 185, 183, 125, 160, 184, 183, 125,  31, 164, 182, 124, 160,
     244, 151, 116,  30, 164, 183,  96,   0 };

const byte Sound_C2_TOI [68] PROGMEM = {
       0,  68,  47,  47,   4, 180, 248,   0,   4, 183, 238, 144,  21, 179, 135, 144,
      66, 151, 255,  16, 128, 152, 254,  48, 101, 143, 109,  59, 251, 171,  91, 192,
     231, 171, 100,  32, 171, 172, 109,  32, 175, 173, 125, 160, 175, 174, 134,  63,
      90, 175, 150, 160, 174, 176, 158, 224, 169, 176, 166,  32, 169, 175, 149,  32,
      89, 175, 104,  12 };

const byte Sound_C2_TON [56] PROGMEM = {
       0,  56,  47,  47,   5, 215, 248,   0,   1, 215, 247,  48,   1, 181, 222,   7,
     151, 176, 109,  32, 170, 176, 126,  32,  89, 173, 142,  62,  73, 171, 158,  95,
     132, 173, 142,  62, 132, 179, 134,  64, 200, 179, 125,  95, 136, 178, 116, 223,
     137, 168, 107, 160, 136, 176, 112,  13 };

const byte Sound_C2_TOUJOURS [120] PROGMEM = {
       0, 120,  47,  47,   0, 153, 248,   0,   0, 184, 253, 144,  69, 183, 255, 176,
     130, 217, 255,  16,  16, 179,   5, 163,  85, 176,  93, 160,   9, 172,  53, 160,
      73, 175,  85, 191,  72, 181,  93, 192,  25, 147,  77, 189,  30, 218, 125,  57,
      30, 218, 125, 128,  30, 218, 125, 160,  30, 218, 117, 160,  30, 218, 118,  80,
      30, 218, 117, 132, 136, 147, 101, 160, 132, 146, 101, 160, 149, 174,  93,  64,
     217, 172,  84,  64, 197, 170,  92,  64, 134, 168,  92,  64,  70, 168, 100, 192,
     138, 170, 108, 192, 154, 171, 100,  32, 134, 174,  83, 160,  81, 175,  99,  32,
       0, 151, 249, 160,  16, 238,   0,  12 };

const byte Sound_C2_TOUT [36] PROGMEM = {
       0,  36,  47,  47,  40, 216, 208,   0,  24, 216, 207, 144,  64, 185, 255, 144,
      21, 179,   6,  34,  70, 168,  93,  96,  67, 200,  92,  93, 130, 213,  83, 223,
     146, 182,  80,  12 };

const byte Sound_C2_TRES [56] PROGMEM = {
       0,  56,  47,  47,  36, 181, 248,   0,  36, 181, 253,  16,  53, 181, 237, 208,
      37, 180, 213,  80,  37, 181, 181, 144, 164, 181, 126,  32, 184, 182, 135,  32,
     253, 182, 135, 192, 228, 183, 135,  64, 186, 183, 119,  64, 169, 182, 110,   0,
     148, 149, 100,   0,  64, 150,  56,   0 };

const byte Sound_C2_TROUVER [92] PROGMEM = {
       0,  92,  47,  47,   5, 149, 248,   0,   5, 149, 252,  16,   4, 185, 239, 176,
       1, 175,  77, 176,  69, 182, 205,  48, 215, 182, 181,  80, 139, 182, 188, 208,
      22, 161, 124, 191, 137, 172, 109, 192,  68, 174, 117, 223,  68, 182, 117, 222,
      73, 147,  85,  64, 234, 149, 101, 193, 232, 183, 101, 192, 237, 183,  93, 192,
     228, 184,  93, 192, 228, 184,  77,  32, 249, 184,  68, 161, 212, 185,  76,  63,
     196, 184,  75,  32, 224, 184,  66, 191, 196, 183,  72,  12 };

const byte Sound_C2_TU [44] PROGMEM = {
       0,  44,  47,  47,  85, 184, 240,   0,  20, 216, 254,  16,  34, 216, 174, 176,
      22, 184,   6,  63, 113, 184,  62, 160, 118, 183,  70, 160, 118, 184,  62, 223,
     182, 184,  62,  63, 182, 184,  61, 190, 179, 184,  64,  12 };

const byte Sound_C2_T_UN [68] PROGMEM = {
       0,  68,  47,  47, 208, 183,  96,   0,   0, 182, 166,  16,  20, 182, 206, 176,
     101, 181, 175,  16, 105, 180, 142,  15, 185, 179, 142, 156, 170, 179, 142, 156,
     186, 179, 150, 156, 169, 179, 158, 160,  86, 179, 166, 223,  86, 179, 182, 192,
     102, 177, 174, 190,  86, 177, 166, 160,  81, 177, 158, 161, 145, 177, 158, 128,
     146, 175, 144,   3 };

const byte Sound_C2_T_UNE [88] PROGMEM = {
       0,  88,  47,  47,   1, 181, 248,   0,   0, 185, 254, 144,  36, 250, 230, 144,
      36, 218, 223,  16,  17, 218, 255,  16,  80, 185,  62,  37, 166, 151,  70, 192,
     102, 151,  71,  62,  98, 151,  55, 128, 101, 151,  39, 160, 100, 183,  79, 160,
      84, 183,  87,   0,  72, 183,  70, 128, 152, 179,  62,  33, 216, 181,  53,  32,
     152, 179,  60, 192, 220, 175,  60, 192, 220, 176,  60,  64, 132, 177,  68,  32,
     213, 178, 100,  63, 234, 179, 123, 189 };

const byte Sound_C2_U [48] PROGMEM = {
       0,  48,  47,  47, 209, 184,  64,   0, 225, 152,  70,  37,  97, 152,  71,  63,
      97, 152,  55,  63,  96, 152,  71,  96,  96, 152,  62, 160, 165, 151,  70,  62,
     165, 151,  77, 160, 161, 185,  68, 191, 225, 184,  59, 128, 208, 151,  56,   0 };

const byte Sound_C2_UN [64] PROGMEM = {
       0,  64,  47,  47, 208, 179, 224,   0, 208, 179, 227,   8, 149, 177, 181, 160,
     150, 177, 166, 160, 166, 177, 167,  32, 183, 177, 167, 191, 183, 177, 167, 224,
     183, 177, 167,  61, 182, 177, 167,  95, 181, 177, 158, 191, 116, 177, 125,  62,
     100, 177, 100,  62, 100, 177,  83,  48,  84, 177,  74, 144,  84, 177,  72,  14 };

const byte Sound_C2_UNE [84] PROGMEM = {
       0,  84,  47,  47,  80, 185,  56,   0, 166, 151,  70, 194, 102, 151,  70, 191,
      98, 151,  54, 128, 101, 151,  38, 160, 100, 183,  78, 160,  84, 183,  86, 128,
      72, 183,  70, 128, 216, 181,  53,  33, 152, 179,  60, 192, 220, 176,  60,  64,
     132, 177,  68,  32, 213, 178, 100,  63, 234, 179, 123, 189, 235, 179, 123, 128,
     171, 179, 131,   0, 235, 179, 130, 128, 170, 179, 138,   0, 251, 180, 137,   0,
     247, 179, 128,   0 };

const byte Sound_C2_V [84] PROGMEM = {
       0,  84,  47,  47,  21, 180,  64,   0, 105, 147,  82, 151, 170, 147,  82, 160,
     101, 179,  83,  32,  21, 179,   4,  32,   4, 181, 157,  48,  20, 183,   5, 176,
      20, 180, 174,  80,  21, 180,   5, 165,  37, 182,   6, 164, 106, 182, 119,  36,
     186, 182, 127, 161, 185, 183, 127, 192, 185, 183, 119, 190, 170, 184, 111,  63,
     185, 184, 111,  95, 185, 184,  94, 191, 248, 184,  93,  62, 233, 184,  75, 191,
     233, 184,  72,  31 };

const byte Sound_C2_VALIDATION [128] PROGMEM = {
       0, 128,  47,  47,   0, 179, 168,   0,  41, 180, 118, 194, 105, 180, 143,  63,
      90, 181, 127,  95, 169, 183, 110, 192, 105, 183,  86,  32, 105, 216,  77, 190,
     105, 216,  77, 194, 186, 216,  70,  32, 187, 217,  78,  96,  21, 214, 112,  94,
     254, 183, 102,  34, 169, 182, 119,  63, 169, 182, 119,  64, 125, 182, 134, 191,
     125, 182, 134, 192, 165, 182, 125, 191, 165, 182, 125, 192,   5, 183, 253, 144,
      50, 220, 254,  80,  10, 185, 254, 208,  72, 185, 253, 208,  97, 183, 181,  13,
     165, 150, 109,  35, 128, 148, 116, 186,  72, 176, 116, 223,  72, 176, 132,  64,
     136, 173, 115, 192,  72, 171,  90,  33, 140, 171,  65, 160, 136, 173,  56,  31 };

const byte Sound_C2_VENIR [84] PROGMEM = {
       0,  84,  47,  47,  84, 182,  96,   0, 152, 181,  93,  28, 153, 180, 102,  33,
     173, 180, 111,  32, 253, 182,  94, 224, 220, 181,  69, 160, 232, 183,  77, 192,
     212, 183,  69, 192, 217, 216,  70,  64, 201, 216,  78,  64, 216, 216,  70,  95,
     212, 216,  70,  95, 213, 217,  69, 192, 196, 217,  69,  95, 212, 217,  68, 223,
     212, 217,  68, 192, 148, 217,  77,  95, 228, 185,  76, 223, 228, 185,  72,  12,
     208, 186,  80,  14 };

const byte Sound_C2_VENT [68] PROGMEM = {
       0,  68,  47,  47,  90, 180,  64,   0,  89, 180,  93, 154,  85, 180, 102,  32,
      26, 177, 110,  61,   6, 178, 118,  32,  78, 179, 142,  33,  94, 176, 142,  33,
      94, 174, 166, 192, 175, 174, 166, 192, 170, 173, 158, 191, 170, 172, 158,  32,
     150, 172, 157, 160,  90, 170, 173, 192, 102, 170, 125,  33,  84, 169, 107, 160,
      68, 165, 120,   8 };

const byte Sound_C2_VIRGULE [128] PROGMEM = {
       0, 128,  47,  47, 148, 181,  96,   0,  85, 181,  66, 133,  85, 183, 108, 160,
      25, 182,  46,  32, 212, 216,  62,  65, 228, 184,  86, 193, 248, 182, 126, 192,
     117, 180, 110,  93,  33, 213,  77, 192,  32, 182, 141,  30, 144, 182,  82,  32,
     132, 146,  40,  96, 129, 184,  51,   0,  96, 152,  36,   0, 160, 184,  52, 160,
     233, 152,  52,  32, 166, 152,  60, 128, 170, 151,  61,  32, 166, 151,  69, 160,
     166, 151,  77, 223, 165, 151,  76, 191, 233, 150,  68,  32, 213, 150,  76,  64,
     228, 150,  67,  60, 160, 150,  50, 191, 165, 150,  68, 162, 233, 150,  68,   1,
     233, 150,  68,  32, 236, 182,  60,  96, 105, 181, 107, 224, 184, 180, 120,  12 };

const byte Sound_C2_VOICI [92] PROGMEM = {
       0,  92,  47,  47,  81, 183,  96,   0,  16, 213, 100,  34,  65, 183, 116, 160,
      22, 172, 117,  33,  27, 170, 117, 161,  22, 173, 118,  32, 153, 169,  92, 165,
     170, 172, 125, 194, 238, 176, 158, 192, 238, 179, 150, 192, 152, 181, 110,  64,
      85, 215, 149, 112,  17, 216, 173, 112,   6, 184, 181, 208,  26, 216, 198,  48,
      26, 216,   6, 176, 106, 216,  62,  61, 186, 216,  62,  64, 186, 216,  70,  64,
     182, 216,  53, 192, 182, 216,  53, 223, 101, 215,  48,  17 };

const byte Sound_C2_VOILA [72] PROGMEM = {
       0,  72,  47,  47,  81, 183,  96,   0,  16, 213, 100,  34,  65, 183, 116, 160,
      22, 172, 117,  33,  27, 170, 117, 161,  22, 173, 118,  32, 153, 169,  92, 165,
     170, 172, 125, 194, 238, 176, 158, 192, 238, 179, 150, 192, 152, 181, 110,  64,
     237, 181,  94,  64, 233, 181, 143,  64, 238, 180, 159,  95, 234, 177, 166,  96,
     162, 175, 157, 222, 162, 175, 152,  18 };

const byte Sound_C2_VOIR [120] PROGMEM = {
       0, 120,  47,  47,  73, 177,  96,   0, 154, 176,  92,  54,  90, 177, 100, 160,
       1, 174,   4, 160,   0, 151, 204, 160,   5, 152, 220, 161,  80, 215, 117, 164,
     128, 215, 109, 160, 129, 144, 117, 160, 151, 171, 117, 192,  66, 171, 158, 161,
      86, 174, 159,  64, 169, 177, 167,  64, 184, 177, 175,  64, 164, 177, 175,  64,
     168, 177, 174, 189, 169, 177, 174, 191,  88, 178, 174,  63, 168, 178, 174,  62,
     100, 178, 165, 160,  41, 177, 133, 160,  40, 177, 149, 160,  41, 177, 149, 160,
      40, 177, 133, 160,  89, 178, 149,  80,  36, 177, 140, 208,  32, 208, 140, 240,
      32, 208, 136,   8,  32, 208, 136,  14 };

const byte Sound_C2_VOS [52] PROGMEM = {
       0,  52,  47,  47,   5, 177,  48,   0,  16, 178,  52, 185,   0, 179,  60, 193,
      64, 215,  85, 194,  64, 152, 118,  34, 137, 171, 134, 162, 129, 176, 127,  65,
      74, 169, 127,  64, 154, 168, 118,  62, 173, 168, 101,  61, 234, 167, 100,  32,
     169, 167,  80,   0 };

const byte Sound_C2_VOTRE [108] PROGMEM = {
       0, 108,  47,  47,  21, 177,   0,   0,   0, 180,  29,  18,  64, 181, 125, 161,
     170, 176, 126, 162, 175, 175, 143,  32, 106, 175, 143,  32, 154, 175, 143,  32,
     174, 175, 143,  32, 154, 176, 135,  32, 166, 176, 135,  33, 169, 178, 127,  32,
     250, 178, 109, 162, 196, 173, 112, 112,  81, 216, 120, 112,  64, 249, 254, 144,
      17, 147, 255,  48,  64, 184, 254, 176,  65, 148, 253, 176, 128, 152, 253, 176,
      21, 178,  61,  48,  17, 177, 205,  48,  21, 176,  76, 176, 213, 178,  92,  37,
     197, 179,  83, 160, 197, 179,  91, 160, 234, 179,  56,  24 };

const byte Sound_C2_VOUS [44] PROGMEM = {
       0,  44,  47,  47,  82, 180,  64,   0,  87, 178,  68, 152, 164, 178,  69,  32,
      68, 179,  77, 192,  80, 214,  54, 223,  89, 174,  87,  65, 129, 174, 103,  65,
      69, 166, 110, 192,  21, 161, 110, 192,  69, 167,  96,   4 };

const byte Sound_C2_VRAIMENT [108] PROGMEM = {
       0, 108,  47,  47,  80, 178,  72,   0,  84, 178,  93,  18,  81, 178, 125,  34,
      85, 176, 125,  32, 170, 176, 124, 191, 150, 178, 116, 189,  81, 178, 108, 160,
     229, 180, 116, 194, 233, 149, 133, 164, 185, 149, 142, 160, 184, 182, 143,  64,
     180, 182, 142, 191, 101, 149, 126, 160,  68, 150,  69,  63,  68, 151,  69,  64,
      68, 182,  77,  64,   0, 176, 134, 160,  21, 173, 159,  96,   5, 172, 174, 192,
      72, 168, 190,  64,  68, 166, 173,  35,  93, 169, 116,  35,  20, 167, 107, 160,
      64, 165,  51,  63,  68, 171,  18, 191, 132, 174,  40,  30 };

const byte Sound_C2_W [148] PROGMEM = {
       0, 148,  47,  47,  33, 217, 200,   0,  17, 182,   6, 139,  86, 181,  70, 128,
       1, 177,  78, 160,  21, 166,  46,  32,  21, 166,  45, 192,  21, 166,  45,   0,
      21, 166,  44, 190,  69, 170,  76, 160,  65, 175,  60,  62, 132, 175,  35,  27,
     132, 164,  32,  16, 128, 149,  40,  48,  20, 146,   0,  80,  20, 147,   4,   6,
      24, 115,  29,  32, 182, 117,  61, 192, 117, 117,  54,  29, 100, 149,  70, 130,
     169, 180, 111,  96, 174, 179, 102,  60, 165, 179,  85,  62,  85, 179,  80,   0,
     128, 181,  80,  94,  89, 182,  56,  97, 184, 182,  93, 162, 245, 182, 102, 161,
     249, 183, 103,  64, 249, 183, 102, 158, 249, 184, 102, 160, 248, 184, 102, 192,
     249, 184,  94, 160, 228, 184,  93, 129, 225, 153,  92, 161, 200, 153,  67, 161,
     200, 152,  72,   0 };

const byte Sound_C2_X [84] PROGMEM = {
       0,  84,  47,  47,  81, 186,  80,   0, 161, 217,  69, 140, 248, 217,  70, 160,
     248, 217,  62, 192, 184, 217,  63,  94, 180, 250,  62,  62,  64, 153,  32,  16,
      64, 149, 248,  80,  17, 184, 246, 112,  16, 215, 253, 176,  16, 216, 253, 176,
      64, 217, 253, 208,  16, 214, 253,  48,  17, 215, 253,  80,  22, 214, 229,  48,
     170, 181, 100,  34, 169, 180, 100,  32, 166, 180,  99,  32, 122, 180,  88, 160,
      98, 180, 104,  28 };

const byte Sound_C2_Y [132] PROGMEM = {
       0, 132,  47,  47,   0, 153, 248,   0, 164, 249,  75, 135, 248, 249,  61,  36,
     248, 217,  53,  64, 244, 217,  53,  95, 244, 218,  52, 188, 244, 250,  44,  30,
     136, 148,  40,  48, 141, 146,  24,  80,   5, 184,   5,  16,   0, 183,   6, 144,
       5, 150,   6,  16,   5, 153,  37, 144, 153, 183, 101, 192,  29, 181, 102,  93,
      40, 180,  93, 160, 153, 180, 117,  36, 152, 181, 134,   2,  89, 181, 143,   1,
     236, 181, 159,  95, 232, 182, 158, 190, 225, 183, 134, 192, 216, 184, 102,  64,
     216, 185, 101, 131, 144, 216, 112, 112,   4, 185, 252, 144,   4, 184, 254,  16,
      24, 184, 197, 208,  41, 185, 165,  16,  36, 184, 156, 176,  85, 184, 148,  48,
      85, 184, 144,   5 };

const byte Sound_C2_Z [96] PROGMEM = {
       0,  96,  47,  47,  46, 181,  48,   0, 126, 181, 101,  33, 126, 181, 109, 163,
     190, 181, 126,  32, 190, 181, 126, 160, 190, 181, 143,   0, 190, 182, 151, 156,
     254, 182, 151,  62, 126, 183, 151, 192, 190, 183, 127,  94, 254, 183, 126, 157,
     238, 183, 109, 157, 190, 183, 100, 128, 254, 183,  92,  20,  64, 215,  16, 112,
       0, 183,  10, 144,  84, 182, 187, 144,  96, 182, 164,  16, 237, 181, 123,  32,
     253, 181, 139, 192, 185, 180, 138, 161, 248, 180, 129, 165, 148, 178, 136,  14 };

const byte Sound_C2_ZERO_NR [80] PROGMEM = {
       0,  80,  47,  47, 149, 181,  32,   0, 121, 181,  12,  61,  22, 181,   4, 192,
      41, 181,   5,  33, 106, 181,  86,  37, 191, 181,  94, 164, 186, 183, 103, 192,
     186, 151, 111, 192, 171, 150, 119,  63,  91, 146, 118, 186,  90, 144, 125, 176,
      34, 139, 132, 176,  69, 135, 140,  48,  73, 165, 125, 127, 137, 164, 116, 191,
     105, 167, 108,  63, 104, 175, 107, 191, 168, 181, 115,  33, 136, 179,  88,  12 };

const byte Sound_C2_UN_NR [56] PROGMEM = {
       0,  56,  47,  47, 208, 179, 224,   0, 208, 179, 227,   8, 149, 177, 181, 160,
     150, 177, 166, 160, 166, 177, 167,  32, 183, 177, 167, 191, 183, 177, 167, 224,
     181, 177, 158, 186, 116, 177, 125,  62, 100, 177, 100,  62, 100, 177,  83,  48,
      84, 177,  74, 144,  84, 177,  72,  14 };

const byte Sound_C2_DEUX_NR [64] PROGMEM = {
       0,  64,  47,  47,   1,  31,   0,   0,   1,  31,   3,  16,   1, 122, 108, 144,
       1, 150, 125, 145,  29, 181,  95,  42, 153, 181, 103,  32, 229, 181, 111,  64,
     229, 180, 111,  64, 233, 180, 109, 191, 254, 180, 101,  61, 237, 180,  92,  60,
     213, 180,  99,  60, 192, 180, 106, 160, 192, 180, 106,   5, 192, 180, 104,  14 };

const byte Sound_C2_TROIS_NR [72] PROGMEM = {
       0,  72,  47,  47, 192, 180, 104,   0,   4, 185, 252,   0,  69, 184, 255,  48,
      38, 173, 198,  48, 130, 178, 181, 176, 135, 174, 173,  48,  39, 166, 117,  48,
      38, 160,   3, 176, 154, 162, 124,  32, 154, 163, 141,  64, 106, 165, 149, 160,
     173, 170, 150,  64, 169, 172, 166, 223, 185, 172, 174, 191, 109, 172, 174,  63,
     109, 172, 173, 154, 109, 172, 168,  14 };

const byte Sound_C2_QUATRE_NR [80] PROGMEM = {
       0,  80,  47,  47,  16, 217, 248,   0,  16, 217, 254, 144, 136, 184,  94,  47,
     245, 183, 126,  57, 229, 149, 151,  56, 233, 147, 183,  95, 184, 147, 183,  64,
     168, 179, 167,  64, 168, 180, 157, 191, 128, 215, 144,  80,  17, 150, 155,  48,
      20, 180, 165, 176,  17, 178, 205, 176,  97, 180, 221, 176, 117, 178, 181, 176,
     121, 177, 141,  48, 121, 177, 108, 176,  41, 177,  83, 144,  41, 177,  80,   6 };

const byte Sound_C2_CINQ_NR [84] PROGMEM = {
       0,  84,  47,  47,   0, 247,  48,   0,  16, 247,  92, 176,  20, 247, 173,  48,
       4, 245, 189, 208,  85, 177, 134, 163, 168, 178, 143,  32, 164, 178, 167, 192,
      84, 179, 167, 255,  84, 180, 166, 223,  64, 148, 100, 223, 148, 150, 100,  63,
     132, 150,  91, 191,  80, 184,  91,  32,  69, 182,  56,  80,   4, 182, 252, 176,
       8, 185, 206,  48,   9, 186, 197, 208,   8, 184,   4, 176,  29, 183,  67, 144,
      29, 183,  64,  14 };

const byte Sound_C2_CIN_CENT_NR [64] PROGMEM = {
       0,  64,  47,  47,   0, 247,  48,   0,  16, 247,  92, 176,  20, 247, 173,  48,
       4, 245, 189, 208,  85, 177, 134,  35, 168, 178, 142, 160, 164, 178, 167,  64,
      84, 179, 167,  94,  84, 180, 166, 190, 100, 180, 141,  61,  64, 148, 100, 160,
     148, 150, 100,  32, 132, 150,  91, 191,  80, 184,  91,  32,  69, 182,  56,  14 };

const byte Sound_C2_SIX_NR [76] PROGMEM = {
       0,  76,  47,  47,   5, 216, 128,   0,   5, 216, 132, 144,   5, 215,  85, 176,
      10, 215,  70,  48,  10, 215,  70, 176,  10, 215,  70, 176, 174, 216,  62, 176,
     168, 217,  62, 208, 120, 217,  46, 194, 120, 217,  46, 224, 120, 217,  46, 224,
       2, 183, 110,  80,   2, 215, 109, 208,   2, 215, 109, 208,   6, 215, 109, 208,
       6, 214, 109,  48,   6, 214, 108,  16,   6, 214, 104,  24 };

const byte Sound_C2_SI_CENT_NR [52] PROGMEM = {
       0,  52,  47,  47,   5, 216, 128,   0,   5, 216, 132, 144,   5, 215,  85, 176,
      10, 215,  70,  48,  10, 215,  70, 176,  10, 215,  70, 176, 174, 216,  62, 176,
     168, 217,  62, 208, 120, 217,  46,  66, 120, 217,  45, 192, 120, 217,  45, 224,
       6, 182,   0,  24 };

const byte Sound_C2_SEPT_NR [100] PROGMEM = {
       0, 100,  47,  47,  16, 214, 184,   0,  16, 214, 188,  16,  16, 217, 244, 176,
       0, 216, 253,  48,   0, 215, 253, 176,  16, 215, 254,  48,  16, 214, 238,  80,
      88, 182, 158, 176, 168, 181, 118, 163, 184, 181, 143,  32, 180, 182, 143, 255,
     248, 183, 135,  62, 248, 183, 118,  63, 228, 183, 116,  48, 228, 183, 130, 176,
     192, 183, 128, 112, 192, 183, 131,  48,   1, 182, 253, 176,  65, 182, 254, 176,
      21, 181, 238,  48,  85, 181, 221, 176,  85, 181, 212, 176,  85, 181, 179, 144,
      85, 181, 176,   8 };

const byte Sound_C2_HUIT_NR [92] PROGMEM = {
       0,  92,  47,  47,  85, 150,  80,   0,  85, 150,  83,  24, 229, 148,  44, 192,
     149, 148,  45,  65, 238, 151,  46,  67, 229, 185,  46, 160, 240, 249,  46, 223,
     240, 249,  46,  63, 212, 217,  53,  32, 144, 217,  52,  48, 128, 185,  51,  48,
     129, 183,  40,  80, 129, 183,  40, 112,  16, 182, 110,  48,  16, 182, 126, 176,
      16, 182, 150, 176,  86, 181, 198,  80,  85, 181, 174,  48, 153, 181, 142,  48,
     218, 181, 133,  48, 218, 181, 124,  16, 218, 181, 120,  30 };

const byte Sound_C2_HUI_CENT_NR [52] PROGMEM = {
       0,  52,  47,  47,  85, 150,  80,   0,  85, 150,  83,  24, 229, 148,  44, 192,
     149, 148,  45,  65, 238, 151,  46,  67, 229, 185,  46, 160, 240, 249,  46, 223,
     240, 249,  46,  63, 212, 217,  53,  32, 144, 217,  52,  48, 128, 185,  51,  48,
     129, 183,  40,  30 };

const byte Sound_C2_NEUF_NR [80] PROGMEM = {
       0,  80,  47,  47,   0, 177,   0,   0, 132, 181,  35,  61, 218, 179,  35, 192,
     214, 180,  36, 193, 222, 180,  45,  64, 154, 181,  54,  34, 185, 181, 119,  32,
     186, 180, 159, 191, 189, 180, 151, 223, 189, 180, 135, 190, 189, 180, 134, 190,
     189, 180, 134,  32,  84, 183, 157, 208,  85, 185, 165,  48,  85, 187, 172, 208,
      85, 155, 196, 208,  81, 155, 236, 208,  81, 155, 251, 144,  81, 155, 248,  12 };

const byte Sound_C2_DIX_NR [68] PROGMEM = {
       0,  68,  47,  47, 161, 255,   8,   0,  65, 216,  30,  59, 129, 214,  46, 160,
     153, 216,  46, 163, 246, 217,  46, 194, 244, 217,  46, 192, 170, 217,  46, 223,
      20, 248,  46, 176,   4, 248,  46, 208,   0, 247,  38, 112,   0, 247,  37, 208,
       0, 247,  29,  48,   0, 247,  28, 176,   0, 246,  28,  48,   0, 246,  27, 144,
       0, 246,  24,   0 };

const byte Sound_C2_DI_MILLE_NR [36] PROGMEM = {
       0,  36,  47,  47, 161, 255,   8,   0,  65, 216,  30,  59, 129, 214,  46, 160,
     153, 216,  46, 163, 246, 217,  46, 194, 244, 217,  46, 192, 170, 217,  46, 223,
      37, 248,  48,   0 };

// The ugly and NOT '11' one from the catalog
const byte Sound_C2_ONZE_NR_ugly [72] PROGMEM = {
       0,  72,  47,  47, 193, 183, 168,   0, 194, 217, 166, 175, 198, 216, 167,  34,
     198, 214, 159,  64, 198, 216, 159,  64, 198, 215, 135,  95, 198, 215, 134, 189,
     198, 216, 142, 255, 197, 216, 150, 126, 197, 185, 142,  64, 132, 186, 158,  95,
      85, 245, 117,  95,  85, 245, 116, 192, 173, 180, 108,  64, 157, 178,  91, 190,
     157, 178,  91, 160, 157, 178,  88,  12 };

// A beter '11' by myself...
const byte Sound_C2_ONZE_NR [72] PROGMEM = {
       0,  32,  47,  47,   0, 153, 248,   0,  89, 200, 158, 160, 133, 169, 150, 224,
     136, 208, 126, 224, 196, 211, 117,  60, 129, 185, 116,  32, 128, 177, 128,   8,
     101, 170,  85, 224, 102, 169,  93, 221, 196, 176, 133, 187,  85, 245, 117,  96,  
      84, 245, 116, 191,  84, 245, 116, 192, 173, 180, 108,  64, 157, 178,  91, 191, 
     157, 178,  91, 191, 157, 178,  88,  13 };


const byte Sound_C2_DOUZE_NR [68] PROGMEM = {
       0,  68,  47,  47, 132, 181, 176,   0,   1, 182, 126, 132,   1, 182,  95,   3,
      21, 179,  71,  36, 101, 174,  70, 192, 101, 170,  78,  64, 101, 170,  85, 224,
     102, 169,  93, 221, 196, 176, 133, 187,  85, 245, 117,  96,  84, 245, 116, 191,
      84, 245, 116, 192, 173, 180, 108,  64, 157, 178,  91, 191, 157, 178,  91, 191,
     157, 178,  88,  13 };

const byte Sound_C2_TREIZE_NR [104] PROGMEM = {
       0, 104,  47,  47,  37, 180, 248,   0,  57, 180, 164, 144,  41, 180, 228, 144,
      41, 179, 156, 144,  42, 180,  36, 144,  41, 180, 124, 144, 121, 180, 132, 176,
     108, 180, 140, 165, 109, 180, 149, 160, 125, 180, 166, 161, 189, 181, 175,  63,
     120, 181, 175,  95, 184, 182, 175,  62, 120, 182, 167,  64, 109, 182, 159,  95,
     125, 183, 151,  64, 173, 183, 134,  62, 189, 182, 125, 191, 174, 182, 117,  63,
     173, 182, 108, 223, 185, 181, 108,  64, 105, 213,  75, 192,  89, 213,  75,  32,
      22, 212,  58, 192,  21, 213,  64,  14 };

const byte Sound_C2_QUATORZE_NR [120] PROGMEM = {
       0, 120,  47,  47,  17, 187, 224,   0, 216, 184,  94,  43, 228, 183, 127,  32,
     164, 182, 143, 189, 169, 181, 151,  63, 168, 181, 125, 189, 224, 181, 120,  48,
     192, 215, 128, 112,   0, 215, 149,  48,   4, 181, 181, 176, 149, 179, 124, 164,
     165, 146, 133,  59, 185, 177, 150,  62, 173, 175, 150, 192, 173, 174, 150,  95,
     189, 173, 150,  64, 189, 173, 149, 223, 189, 173, 141, 223, 125, 173, 141,  30,
     109, 172, 141,  64, 109, 172, 124, 191, 188, 172, 132,  32, 188, 172, 123, 160,
     109, 172, 115,  32,  30, 171, 107,  64,  28, 238, 115,  64,  76, 207, 114, 192,
      27, 208, 106, 192,  27, 208, 104,  14 };

const byte Sound_C2_QUINZE_NR [80] PROGMEM = {
       0,  80,  47,  47, 168, 216,  88,   0, 168, 216,  93, 141, 229, 183, 118, 162,
     233, 182, 143, 160, 168, 181, 175, 192, 100, 181, 175, 223, 100, 181, 183, 223,
     100, 181, 175,  95, 101, 180, 175,  95, 100, 180, 166, 222,  80, 180, 158,  95,
      80, 179, 157, 160, 100, 179, 141,  63,  80, 179, 124, 160,  80, 178, 116,  63,
      88, 178,  91, 192,  86, 213,  67,  64,  75, 213,  19,  64,  22, 212,   0,  15 };

const byte Sound_C2_SEIZE_NR [116] PROGMEM = {
       0, 116,  47,  47,  15, 218, 112,   0,  15, 218, 115, 176,  15, 218, 116, 176,
      15, 218, 117,  48,  15, 218, 117,  16,   9, 216, 117, 176,   9, 214, 101, 176,
     153, 181, 110,  48, 248, 181, 126,  38, 224, 181, 142, 191, 248, 181, 151,  63,
     248, 181, 151, 158, 248, 182, 151, 191, 248, 182, 143, 223, 185, 182, 143, 192,
     169, 183, 143, 190, 185, 183, 127,  95, 249, 183, 126, 190, 233, 183, 118, 160,
     253, 183, 109, 160, 232, 182, 101,  32, 233, 181,  92, 160, 173, 181,  76,  64,
      84, 219,  84,  31,  84, 219,  83, 192,  85, 181, 107,  64, 144, 179, 123,  64,
     144, 178, 120,  13 };

const byte Sound_C2_DIX_SEPT_NR [120] PROGMEM = {
       0, 120,  47,  47,   0, 182,   0,   0,   0, 181,   3, 130,   4, 214,   4, 128,
     137, 214,  37,   0, 132, 216,  36, 128, 212, 216,  36,   3, 229, 217,  35, 130,
     230, 217,  36,   1, 228, 249,  45,  64, 228, 249,  38,   2, 153, 217,  46,  95,
      16, 217,  40,  48,  16, 184,  64,  80,  16, 184,  69, 208,  17, 183,  85, 208,
      85, 183,  94,  80, 174, 181, 102,  35, 252, 181, 119,  32, 253, 181, 143,  93,
     169, 182, 135,  64, 190, 182, 127,  60, 253, 183, 109, 191, 208, 215, 112,  80,
     208, 215, 112, 112,  20, 214, 189, 176,  16, 214, 190,  48, 144, 214, 189,  48,
     144, 214, 188,  32, 148, 214, 192,  10 };

const byte Sound_C2_DIX_HUIT [136] PROGMEM = {
       0, 136,  47,  47, 132, 216,  16,   0,   0, 180,   6,   7,  25, 213,  15,  32,
      72, 215,  30,   0, 148, 216,  47,  33, 245, 217,  47,  65, 245, 217,  47,  95,
     233, 185,  47,  64, 105, 184,  46, 222, 121, 183,  46,  63, 105, 183,  21,  48,
      21, 183,   4, 176,  21, 184,   4, 208,   5, 185,   5, 176,   2, 217,   6, 176,
      90, 185,  14, 188, 101, 184,  39,  65, 169, 152,  55,  65, 234, 184,  55,  64,
     234, 184,  55,  95, 250, 216,  54, 223, 237, 216,  45,  63, 212, 216,  43,  32,
     212, 216,  58, 191, 192, 215,  66,  80, 128, 215,  72, 112,  20, 176, 212,  16,
       5, 177, 230, 144,   1, 179,  71,  16,   1, 147, 238, 144,   0, 179, 229, 176,
       0, 179, 228, 176,  21, 182, 112,  13 };

const byte Sound_C2_DIX_HUI_MILLE_NR [104] PROGMEM = {
       0, 104,  47,  47, 132, 216,  16,   0,   0, 180,   6,   7,  25, 213,  15,  32,
      72, 215,  30,   0, 148, 216,  47,  33, 245, 217,  47,  65, 245, 217,  47,  95,
     233, 185,  47,  64, 105, 184,  46, 222, 121, 183,  46,  63, 105, 183,  21,  48,
      21, 183,   4, 176,  21, 184,   4, 208,   5, 185,   5, 176,   2, 217,   6, 176,
      90, 185,  14, 188, 101, 184,  39,  65, 169, 152,  55,  65, 234, 184,  55,  64,
     234, 184,  55,  95, 250, 216,  54, 223, 237, 216,  45,  63, 212, 216,  43,  32,
     212, 216,  58, 191, 192, 215,  64,  13 };

const byte Sound_C2_DIX_NEUF_NR [136] PROGMEM = {
       0, 136,  47,  47,   1, 213,   0,   0,  21, 213, 165,  10,  21, 213, 174,   0,
      89, 215,  54, 128, 153, 216,  45, 128, 213, 217,  45,  32, 226, 217,  45, 160,
     226, 217,  46,  64, 229, 217,  46,  64, 160, 185,  69, 189,   0, 188, 172, 176,
       0, 188, 244, 176,   0, 188, 252, 208,   4, 156, 220, 176,  64, 183,  60, 162,
     148, 180,  60, 160, 212, 176,  60, 191, 216, 178,  61,  95, 221, 178,  61, 160,
     234, 181, 102, 160, 237, 181, 135, 223, 186, 180, 143,  95, 185, 180, 143,  95,
     185, 180, 134,  63, 181, 179, 125,  63, 165, 181, 124,  48, 134, 183, 117,  48,
       4, 181, 149, 240,   4, 181, 149,  48,   4, 181, 148, 176,   4, 181, 148,  48,
       4, 181, 147,  16,   4, 181, 144,  14 };

const byte Sound_C2_VINGT_NR [92] PROGMEM = {
       0,  92,  47,  47, 153, 179,  16,   0, 153, 180,  19,  58, 153, 180,  19, 160,
       4, 180,   4,  64,   5, 180,   5, 192,  24, 180,  46, 163, 169, 180, 143, 163,
     185, 180, 167, 192, 100, 180, 175,  64,  96, 180, 167,  63, 100, 180, 142, 192,
     100, 180, 134, 191, 104, 180, 126, 192, 104, 180, 118,  62,  72, 180,  84, 160,
     152, 178,  67, 191, 129, 152, 120,  80,   0, 185, 252, 144,  16, 183, 254, 144,
      16, 183, 231,  16,   0, 179,   6, 144,  21, 179, 152,  10 };

const byte Sound_C2_VIN_MILLE_NR [72] PROGMEM = {
       0,  72,  47,  47, 153, 179,  16,   0, 153, 180,  19,  58, 153, 180,  19, 160,
       4, 180,   4,  64,   5, 180,   5, 192,  24, 180,  46, 163, 169, 180, 143, 163,
     185, 180, 167, 192, 100, 180, 175,  64,  96, 180, 167,  63, 100, 180, 142, 192,
     100, 180, 134, 191, 104, 180, 126, 192, 104, 180, 118,  62,  72, 180,  84, 160,
     152, 178,  67, 191, 144, 178,  64,  10 };

const byte Sound_C2_TRENTE_NR [128] PROGMEM = {
       0, 128,  46,  47,   0, 153, 248,   0,  21, 216, 237, 144,  16, 216, 239,  16,
      64, 154, 255, 144,  17, 147, 175,  16,  17, 113, 238, 144,  54, 179, 158,  16,
      17, 177, 206,  48, 193, 180, 253, 176, 129, 177, 253,  48,  33, 173,   4, 143,
      85, 174, 133,   2, 106, 173, 142, 160, 102, 173, 159,  63,  81, 173, 191,  63,
      65, 172, 207,  32,  81, 173, 174, 191,  97, 204, 166, 191, 162, 204, 158,  63,
     166, 172, 149, 190, 167, 171, 149,  63,  20, 169, 140,  60,  89, 171, 123, 189,
      68, 170,  99,  62, 128, 184, 136,  80, 129, 152, 120,  80,   0, 185, 252,  16,
      16, 183, 254,  16,  16, 183, 230, 144,   0, 179,   6,  16,  21, 179, 152,  15 };

const byte Sound_C2_QUARANTE_NR [112] PROGMEM = {
       0, 112,  47,  47, 148, 184, 152,   0, 216, 183, 123,  15, 164, 182, 133,  10,
     164, 182, 158, 128, 170, 148, 182, 188, 121, 178, 199,  95, 121, 178, 199,   0,
     109, 178, 190, 191, 104, 147, 190,  63,   5, 174, 216,  48,  41, 174, 156, 176,
      41, 173,   4, 144, 112, 173, 148, 208, 105, 173, 158,  60, 101, 172, 166, 191,
     101, 172, 174, 160,  37, 170, 174, 192,  25, 170, 174, 190,  25, 169, 158,  32,
      20, 168, 101,  63,   4, 148, 208,  80,   4, 148, 208, 112,  20, 181, 180, 144,
     100, 181, 181, 144, 105, 181, 157,  16, 168, 179, 124,  30,  21, 179, 152,   9 };

const byte Sound_C2_CINQUANTE_NR [132] PROGMEM = {
       0, 132,  47,  47,   0, 153, 248,   0,  68, 185, 252, 176,  16, 181, 253,  48,
       0, 215, 253,  48,  64, 182, 253,  48,  16, 216, 253, 176,   0, 182, 253, 176,
       4, 177,   5, 143,  88, 178, 158, 160,  84, 180, 199,  64,  84, 181, 191,  64,
     105, 182, 167, 223,  88, 151, 117,  60,  68, 151, 124,  31,   0, 139, 120,  16,
      96, 179, 144,  80, 148, 147, 132, 135, 173, 144, 158, 189, 186, 175, 158, 191,
     105, 174, 174, 223,  25, 172, 182, 192,  25, 172, 166,  61, 101, 173, 141,  31,
     178, 173, 132, 190, 180, 172, 123, 192, 120, 174,  66, 192,   4, 180, 184,  80,
       4, 180, 184, 112,   4, 180, 165,  16,   4, 182, 197, 144,  69, 181, 133,  16,
      20, 179,   0,  14 };

const byte Sound_C2_SOIXANTE_NR [164] PROGMEM = {
       0, 164,  47,  47,   0, 153, 248,   0,   1, 153, 253,  48,   1, 218, 253,  80,
      66, 152, 253, 176,   2, 181, 253, 208,   3, 185, 254,  48,  16, 146, 254,  80,
       5, 137,   4, 167,  70, 136, 123,  32,  86, 138, 100,  32, 234, 141, 125, 162,
     185, 142, 142, 160, 185, 144, 167,  32, 168, 179, 159,  95,  85, 180, 174, 208,
       0, 185, 222, 176,  84, 215, 174, 208,  20, 183, 174, 176,   1, 182, 198, 176,
       0, 218, 254, 176,  20, 182, 254, 208,  85, 182, 254, 176,  81, 179, 142, 160,
     104, 176, 158, 190, 105, 175, 166, 188,  89, 174, 182, 223,  21, 171, 174,  95,
      22, 171, 157, 190,  38, 171, 133, 192,  21, 171, 149,  62, 100, 171, 132, 160,
     104, 171, 108,  31, 120, 171,  91, 160,   4, 178,   0,  80,   4, 178,   0, 112,
       4, 178,   4,  16,  64, 181, 253, 144,  85, 182, 149, 144,  85, 181, 125,  16,
      21, 179, 152,  15 };

const byte Sound_C2_QUATRE_VINGT_NR [140] PROGMEM = {
       0, 140,  47,  47,  24, 185, 112,   0, 185, 184, 117, 143, 181, 183, 134, 135,
     165, 182, 167,  32, 170, 180, 175,  95, 185, 180, 175,  64, 184, 181, 157,  62,
     184, 181, 147, 159, 145, 182, 152,  48,  17, 181, 173,  16,  37, 180, 255,  48,
      37, 180, 231,  48,  36, 179, 238, 176,  39, 178, 246,  64, 119, 176,  88,  32,
     174, 176, 116, 132, 220, 176, 125, 191, 173, 176, 126,  63, 173, 177, 126, 191,
     173, 177, 118,  62, 174, 177, 117, 222, 105, 178,  93,  61,  24, 178, 109,  62,
      73, 176, 112, 112, 217, 144, 122, 134, 104, 176, 149, 160, 121, 178, 158, 192,
     120, 177, 150,  32,  85, 175, 126,  64, 100, 176, 117, 160,  88, 175, 125,  64,
      68, 177, 156, 159,  84, 177, 116,  32,   4, 175,  32,   6 };

const byte Sound_C2_CENT_NR [76] PROGMEM = {
       0,  76,  47,  47,   0, 215, 248,   0,  16, 182, 251,  16,   1, 181, 251, 144,
      69, 182, 253,  80,  64, 185, 253, 176,  64, 184, 254,  48,  17, 181, 255,  48,
       8, 179, 103,  34,  20, 174, 199,  64,  85, 174, 174, 190, 101, 173, 166,  63,
      86, 170, 182,  64,  70, 169, 190,  95,  69, 169, 173,  62,  64, 170, 164,  63,
      64, 139, 147, 159,  80, 167, 130, 128,  84, 166, 112,  13 };

const byte Sound_C2_MILLE_NR [84] PROGMEM = {
       0,  84,  47,  47,   4, 183, 248,   0,  68, 182,  99,  31,  72, 148,  84, 128,
     136, 149,  69,  64, 140, 152,  69, 192, 145, 184,  70, 163, 153, 216,  79,  64,
     212, 217,  79,  64, 213, 216,  79,  95, 245, 217,  78, 223, 178, 215,  62,  64,
     191, 182,  78,  95, 186, 181,  85, 192, 122, 181,  69,  62, 127, 181,  84, 160,
     110, 181, 100,  32, 190, 181, 147, 191, 254, 180, 155,  32, 106, 180, 154, 159,
     174, 180, 152,  14 };

const byte Sound_C2_MILLION_NR [84] PROGMEM = {
       0,  84,  47,  47, 200, 176,  32,   0, 200, 151,  35,   0, 200, 152,  35,  32,
     140, 150,  43, 193, 140, 149,  44,  64, 162, 186,  69, 224, 149, 184,  70,  94,
     165, 185,  62,  32, 182, 185,  53, 224, 166, 185,  86, 162, 172, 150, 134, 192,
     111, 177, 166, 223,  68, 174, 190,  64, 132, 178, 165, 160, 129, 186, 157, 192,
     128, 186, 141,  30, 128, 177, 124, 160, 132, 174, 124,   1, 132, 173, 115,   0,
     128, 168,  96,   5 };

const byte Sound_C2_ET_UN_NR [72] PROGMEM = {
       0,  72,  47,  47,  21, 179, 152,   0, 181, 185,  92, 165, 181, 185,  85, 192,
     185, 185,  94, 190, 181, 185, 103,  32, 168, 184, 151,  64, 104, 181, 159,  95,
     121, 180, 183,  95, 121, 179, 191,  95, 121, 179, 174,  29,  96, 178, 173,  95,
     164, 177, 156,  63,  84, 177, 131, 191,  88, 176, 123,  32,   8, 173, 122, 160,
     104, 177,  74,  33,  20, 177,  40,  15 };

const byte Sound_C2_ET_NR [32] PROGMEM = {
       0,  32,  47,  47,  21, 179, 152,   0, 181, 185,  92, 165, 181, 185,  85, 192,
     181, 185,  86, 191, 181, 185,  86, 224, 181, 185,  86, 158, 181, 185,  96,  26 };


// From catalog 3
// Formatted (C-code) from the OCR-ed data files
// (Here the values are in base-10)

const byte Sound_C3_ADDITIONNE [176] PROGMEM = {
       0, 176,  47,  47, 193, 118, 248,   0, 233, 180, 182, 171, 230, 180, 183,  32,
     234, 181, 175,  66, 189, 182, 127,  65, 216, 182,  68,  63, 144, 181,  91,  63,
     132, 179,  82, 160, 192, 216,  67,  32, 148, 215,  75, 190, 249, 216,  60, 160,
     250, 217,  61,  33, 250, 216,  61,  64, 233, 217,  52,  32, 153, 217,  43, 144,
      69, 216,  44, 208,  73, 217, 204, 240,  69, 217, 253,  48,  78, 217, 213, 176,
      89, 217, 238,  48,  89, 217,   6,  80, 153, 185,  37,  53,  37, 184,   6, 160,
     105, 181, 135,  94,  45, 178, 158, 223, 109, 177, 158,  63, 173, 176, 149, 160,
      25, 177, 149, 223, 106, 180, 133, 192,  89, 180, 101,  62, 158, 179,  60,  32,
     222, 178,  59,  33, 222, 179,  67, 160, 206, 180,  68,  32, 206, 180,  60,  64,
     222, 180,  59, 160, 206, 179,  59,  64, 154, 180, 116, 161, 170, 180, 140, 160,
     170, 180, 148, 160, 182, 179, 116, 192, 170, 179,  75, 191,  73, 177,   0,  14 };

const byte Sound_C3_AFFICHE [104] PROGMEM = {
       0, 104,  47,  47,   0, 153, 248,   0, 169, 179, 182,  43, 186, 180, 183,  64,
     190, 180, 167, 193, 125, 181, 150, 162, 101, 182,  60, 187,  20, 182,   4, 144,
      37, 183, 165, 240,  25, 184,   5, 240,  26, 184,   5,  48, 183, 216,  61,  94,
     182, 216,  53,  93, 102, 216,  45, 223, 118, 184,  45,  30, 102, 184,  36, 191,
      17, 184,   4, 191,   9, 183, 253, 176,  84, 251, 254, 208,  21, 218, 254, 240,
      22, 218, 254, 112,   2, 182, 253, 240, 181, 180, 124,  32, 217, 180, 123,  63,
     152, 180, 130,  32, 152, 180, 128,  12 };

const byte Sound_C3_AJOUTE [128] PROGMEM = {
       0, 128,  47,  47,  20, 181,  80,   0, 101, 181, 156, 148, 229, 180, 174,  32,
     134, 179, 158, 160, 230, 181, 167,  32, 185, 181, 143,  64, 104, 181, 119,  64,
       0, 181,   7,  63,   4, 184,   6, 192,   4, 184,   7,  80,   0, 180, 246,  35,
      68, 181, 101, 162,  68, 174,  93, 192,  72, 171,  93,  64,  88, 172,  69,  65,
       8, 173,  37, 162, 140, 178,  76, 190, 136, 179,  66, 161, 192, 214,  80, 112,
     128, 182,  80, 112,   0, 153, 251, 144,   1, 183, 237, 176,  20, 182, 213,  48,
       9, 181, 164, 176, 138, 180, 100,   5, 196, 174, 116,  64, 192, 212, 107, 160,
     212, 179,  91, 192, 134, 177,  83,  64, 216, 179,  75,  63, 197, 177,  80,  27 };

const byte Sound_C3_ALPHABET [128] PROGMEM = {
       0, 128,  47,  47,   0, 178,   0,   0, 165, 180, 190, 170, 173, 180, 183,  64,
     189, 181, 175, 164, 104, 181, 151, 162, 104, 181, 126, 162, 104, 181, 118,  32,
     104, 181, 101, 191, 168, 181,  93,  63,  73, 185,  37,  62,   5, 181, 190, 176,
      21, 181,   6,  80,   0, 181, 253, 208,   1, 183, 245,  80,  26, 180, 206,  80,
     173, 179, 150, 163, 191, 180, 167, 221, 111, 180, 159,  95, 111, 179, 133, 184,
     153, 178,  80,  32, 132, 177,  80, 112,  70, 182,  77,  48, 153, 183,  85,  30,
     170, 182, 118,  61, 170, 183, 126, 190, 186, 184, 119,  64, 255, 184, 117, 192,
     250, 184, 109,  62, 229, 184, 100, 160, 246, 184,  92,  32, 246, 184,  88,  14 };

const byte Sound_C3_ANALYSE [148] PROGMEM = {
       0, 148,  47,  47,   0, 176,   0,   0, 149, 179, 196, 143, 165, 179, 190,  35,
     166, 180, 190, 160, 118, 181, 183,  66, 121, 181, 159,  36, 100, 182, 142, 160,
      88, 181,  69, 163,  88, 181,  69, 160,  72, 182,  77, 192, 104, 182, 118, 189,
     121, 182, 151,  63, 105, 182, 167,  94, 121, 183, 159,  95, 104, 183, 134, 160,
     106, 183, 110,  63, 118, 183,  70,  62, 114, 215,  37,  61, 102, 216,  60, 189,
     121, 216,  53,  32, 181, 217,  61,  32, 181, 217,  60, 222, 181, 217,  68, 224,
     181, 217,  60,  60, 249, 217,  60,  95, 229, 217,  60,  63, 232, 217,  52,  32,
     214, 185,  60,  32, 170, 184,  61,  64, 170, 184,  68, 192, 170, 184,  68,  64,
     253, 180, 115,  35, 229, 179, 130,  63, 153, 179,  98,  32, 149, 177,  89, 160,
     153, 179, 104,  13 };

const byte Sound_C3_ATTENTION [128] PROGMEM = {
       0, 128,  47,  47,   0, 151, 248,   0, 152, 179, 191,  66, 164, 181, 167, 192,
     164, 181, 143,  33, 164, 180, 100, 186, 148, 180, 136,  48,  81, 214, 152,  80,
      64, 251, 237, 176,  70, 181, 156, 176,  86, 175, 142, 163,  22, 172, 143,  32,
      22, 171, 150, 192,  86, 171, 142,  32, 101, 172, 117,  63,  85, 172,  84, 188,
       4, 183, 213,  36,   1, 213, 126,  16,   1, 215,   6,  80,  20, 251, 214, 112,
       5, 185, 254, 208,  36, 219, 230,  48,   9, 181, 253, 176, 149, 183,  93,   1,
      84, 149, 110, 188,  20, 144, 126,  95,  20, 171, 126,  64,  20, 169, 126,  33,
      25, 169, 141, 193,  72, 163, 132,  66,  72, 164,  99,  33,  24, 161,   0,  25 };

const byte Sound_C3_BEBE [104] PROGMEM = {
       0, 104,  47,  47, 217, 145,  24,   0,  17, 181,   4, 135,  81, 182, 102, 128,
     210, 183, 102,   0, 233, 183, 110, 160, 249, 183, 111,  32, 250, 184, 111, 160,
     185, 184, 103, 192, 185, 183, 103,  32,  89, 150,  93, 189, 132, 150,  67, 160,
     144, 185,  48,  48, 150, 149,  48,  80, 154, 151,  85,  32, 234, 183,  93, 160,
     250, 183, 102, 160, 249, 184, 111,  32, 249, 184, 103,  64, 249, 184,  94, 195,
     212, 184,  93, 160, 196, 183,  93,  32, 202, 151,  84, 160, 201, 151,  51,  32,
     200, 149,  58, 160, 137, 143,  56,  19 };

const byte Sound_C3_BONHOMME [96] PROGMEM = {
       0,  96,  47,  47, 132, 145,  40,   0, 145, 182,  52,  22,  86, 175, 109, 165,
     170, 177, 118, 193, 171, 180, 102, 192,  89, 180,  78,  61, 137, 179,  61,  64,
      68, 181,  70,  64, 169, 180, 126, 223, 105, 179, 150, 192, 105, 178, 150, 223,
     105, 177, 126,  95,  89, 177, 101, 191, 133, 179,  52,  33, 200, 178,  51, 160,
     196, 181,  51, 192, 200, 181,  44,  32, 132, 182,  44,  64, 132, 182,  44,  64,
     132, 180,  44,  64,  68, 178,  76, 144,  37, 178,  52, 208,  37, 178,  56,  14 };

const byte Sound_C3_CORRECTION [140] PROGMEM = {
       0, 140,  47,  47,   0, 153, 248,   0, 134, 178, 252,  16,  33, 178, 132, 176,
      70, 147, 132, 143,  27, 142, 134,  42,  22, 171, 134, 223,  39, 171, 133,  61,
      42, 173, 132,  63, 103, 175, 140,  33, 106, 178, 149, 162, 110, 180, 158, 161,
     110, 181, 143,  63, 106, 183, 135,  63,  41, 183, 103,  16, 106, 152,  77, 176,
      16, 182, 128, 112,   4, 117, 189,  16,  36, 215,  85,  48,  20, 215, 252, 176,
      21, 216, 212, 208,  22, 216,   4, 208,  26, 216, 252, 208,  19, 218,   4, 240,
     101, 186,  44, 146, 106, 184,  52, 186, 101, 151,  69,  63,  17, 151,  37,  63,
       5, 146, 100, 188,   8, 169, 132, 223,  72, 168, 148,  64,  72, 176, 123, 160,
      96, 187,  99,  32,  68, 176,  74,  32,  68, 186,  96,  15 };

const byte Sound_C3_COUSIN [100] PROGMEM = {
       0, 100,  47,  47,   0, 119, 216,   0, 129, 118, 196, 144, 130, 145, 189, 144,
     128, 216, 220, 144, 192, 181, 221, 176,  16, 139,   4, 163,   5, 139,   4, 163,
      23, 172,   5, 192,  42, 145,  54,  64,  81, 214,  69, 222,   6, 181,  53,  59,
      22, 245, 117,  64,  89, 179,  93, 192, 168, 179, 126,  65, 168, 179, 143,  33,
     165, 179, 151,  63,  86, 179, 167,  64,  86, 146, 167,  95, 166, 146, 158, 192,
     165, 145, 141, 163, 165, 144, 124, 162, 165, 177, 100,  33, 133, 144,  74, 160,
      86, 144,  56,  26 };

const byte Sound_C3_DIMINUE [124] PROGMEM = {
       0, 124,  47,  47, 196, 216,  25,   0, 209, 183,  34, 138, 153, 215,  53, 176,
     250, 216,  61, 169, 250, 217,  63,  35, 250, 217,  71,  68, 230, 185,  79,  64,
     200, 183,  78, 160, 201, 183,  70, 255, 209, 186,  79,  60, 202, 217,  71,  62,
     222, 217,  71,  63, 222, 217,  63,  95, 208, 185,  62,  32, 224, 185,  61, 191,
     200, 152,  61, 160, 200, 153,  53, 223, 224, 185,  53, 187, 224, 216,  53, 222,
     224, 216,  53,  61, 212, 184,  53,  64, 164, 217,  62,  63, 176, 184,  54,  63,
     160, 184,  62,  32, 160, 184,  62,  64, 165, 152,  62,  63, 161, 152,  61, 160,
     161, 184,  69, 192, 225, 152,  60,  63, 241, 152,  48,  14 };

const byte Sound_C3_ENFANT [96] PROGMEM = {
       0,  96,  47,  47, 196, 185,  72,   0,  16, 137, 205,  35, 167, 171, 141,  32,
     166, 171, 149, 161,  68, 173, 166, 192,  89, 171, 150,  33,  73, 170, 141, 160,
       9, 165, 149,  63,   2, 180,  93,  62,   0, 184, 246, 176,  80, 215, 254, 240,
       4, 181, 254, 240,   0, 185, 253, 176,  64, 179, 125,   5, 101, 173, 141,  63,
      17, 141, 182, 189,  22, 173, 190, 223,  89, 171, 174, 224,  85, 171, 149, 164,
      85, 170, 124,  32,  20, 160, 107, 161,  73, 166,  99,  33,   8, 162,  88,  23 };

const byte Sound_C3_EVITE [124] PROGMEM = {
       0, 124,  47,  47,   0, 153, 248,   0, 144, 216, 123,  31, 228, 185, 102,  32,
     244, 217,  93,   0, 244, 217, 101,  32, 228, 185, 102, 161, 249, 185,  95,  32,
     186, 184,  87, 192, 170, 184,  78,  32, 234, 150,  77,  62, 237, 150,  76,  32,
     213, 150,  67, 191,  85, 151,  68, 161, 170, 184,  69, 162, 250, 217,  78, 163,
     245, 217,  70, 193, 244, 217,  70,  34, 228, 217,  61,  34, 244, 217,  60, 162,
     224, 217,  51,  32, 129, 182,  72, 112,   0, 182, 160, 112,   0, 215, 214,  48,
      85, 181, 173,  48, 169, 182, 141,  80, 149, 180,  92,  31, 132, 179,  67,  60,
     148, 179,  50, 160, 136, 176,  34, 160, 137, 178,  24,  18 };

const byte Sound_C3_FAMILLE [124] PROGMEM = {
       0, 124,  47,  47,  77, 150, 176,   0,  13, 179, 253,  48,  77, 185, 253,  80,
      13, 181, 229, 112,  29, 181, 213, 176,  86, 180, 156,   6, 230, 147, 125,  35,
     234, 180, 151,  64, 165, 180, 159,  30, 165, 148, 142, 191, 164, 147, 101,  63,
     136, 146,  76, 160, 153, 146,  60,  32, 137, 148,  69,  64, 133, 185,  86,  63,
     133, 215,  86, 190, 134, 215,  86,  63, 130, 216,  78,  64, 146, 216,  78,  64,
     130, 215,  78,  64, 130, 216,  69, 191, 194, 216,  69, 192, 130, 214,  69,  64,
     193, 215,  68, 160, 194, 217,  67, 161, 198, 215,  68,  32, 229, 216,  84,  66,
     229, 184,  75, 161, 168, 183,  43,  33, 213, 183,  56,  22 };

const byte Sound_C3_FREINE [88] PROGMEM = {
       0,  88,  47,  47,   5, 183, 128,   0,  17, 214, 220, 240,  85, 177, 228, 240,
     101, 180, 133, 240, 165, 180, 149,  32, 230, 181, 167, 192, 250, 181, 159,  64,
     233, 183, 143,  64, 233, 183, 142, 191, 164, 183, 134,  63, 168, 183, 126,  32,
     168, 182, 101,  63, 136, 181,  76, 160, 136, 180,  68,  33, 136, 179,  68,  64,
     136, 180,  68,  97, 136, 180,  68,  64, 152, 179,  92, 193, 148, 178, 116, 192,
     148, 179,  92,  33, 148, 180,  72,  22 };

const byte Sound_C3_LENTEMENT [116] PROGMEM = {
       0, 116,  47,  47, 108, 181,  88,   0,  92, 181,  91,  60, 156, 180,  92, 160,
     173, 179,  93, 160,  92, 179, 118,  34,  88, 177, 151,  35, 155, 176, 159,  34,
      91, 173, 158, 161, 107, 173, 134,  33, 165, 172, 125,  33, 170, 172, 100,  32,
     132, 173, 104, 112, 145, 216, 115, 144,   2, 215, 196, 176,   1, 213,   5,  48,
       2, 180, 101, 208, 102, 178, 100,  48, 169, 177, 100,  17, 137, 178,  60, 223,
     138, 177,  68,  95, 201, 173,  59,  61, 197, 183,  59, 160,   5, 173,  84, 160,
      22, 171, 124, 223,  22, 168,   3, 223,  41, 168,   3, 192,  30, 168,   2, 165,
      46, 167,   0,  15 };

const byte Sound_C3_LIGNE [136] PROGMEM = {
       0, 136,  47,  47, 116, 183, 112,   0, 184, 183, 101,  61, 184, 215,  93,  32,
     248, 215,  84, 161, 232, 215,  76,  33, 168, 216,  77,  33, 188, 215,  78,  32,
     185, 184,  78,  33, 118, 183,  45, 161, 163, 215,  61,  33, 181, 217,  70,  37,
     182, 217,  62, 193, 182, 218,  62, 160, 182, 218,  62,  64, 146, 218,  62,  64,
     145, 218,  62,  94, 145, 186,  54,  62, 136, 183,  45,  94, 137, 152,  45,  95,
     137, 153,  44, 189, 140, 151,  52,  63, 141, 152,  52, 223, 204, 151,  44, 192,
     200, 151,  44,  63, 204, 152,  44,  32, 212, 217,  52, 160, 200, 216,  52, 192,
     196, 216,  61,  32, 132, 216,  69,  32, 149, 184,  92, 192, 169, 184, 108,  33,
     169, 183, 123, 161, 169, 183, 120,  14 };

const byte Sound_C3_LIT [56] PROGMEM = {
       0,  56,  47,  47,  84, 182,  96,   0, 226, 182, 107,  58, 233, 183,  92,  33,
     104, 183,  93,  33, 184, 215,  94,  35, 124, 215,  86, 193, 125, 183,  78, 194,
     119, 183,  46, 192,  38, 215,   6, 162, 182, 217,  71,  66, 179, 217,  63,  96,
     183, 217,  54, 187, 183, 217,  48,  20 };

const byte Sound_C3_MAMAN [92] PROGMEM = {
       0,  92,  47,  47, 136, 184,  40,   0, 200, 182,  42,  30, 201, 180,  42, 160,
     201, 182,  35,  32, 141, 184,  36, 160, 142, 182,  36, 162, 142, 182,  61,  66,
     142, 180,  53, 161,  90, 178,  45, 164, 106, 178, 175,  32, 170, 179, 199, 192,
     106, 178, 191, 192,  26, 177,  94, 190,  74, 181,  54,  32,  10, 177,   6,  95,
      10, 179,   5, 189,  10, 179,   5, 223,  26, 170, 182,  62,  37, 201, 142, 127,
      37, 200,  77,  95,  54, 200,   4, 160,  36, 199,   0,  14 };

const byte Sound_C3_MERE [120] PROGMEM = {
       0, 120,  47,  47, 136, 184,  40,   0, 200, 182,  42,  30, 201, 180,  42, 160,
     203, 182,  35,  32, 141, 184,  34, 160, 142, 182,  36, 162, 142, 182,  61,  66,
     142, 180,  53, 161,  90, 178,  45, 164, 110, 180, 134,  34, 190, 180, 151,   1,
     190, 180, 151,  32, 190, 181, 167,  64, 189, 182, 159,  95, 189, 182, 159,  94,
     189, 182, 150, 189, 121, 182, 159,  95, 125, 183, 150, 222, 253, 183, 142,  95,
     185, 183, 142,  64, 185, 183, 134,  64, 170, 183, 133, 192, 169, 182, 125,  64,
     174, 179, 133,  80,  36, 178,   3, 176,  33, 178, 196, 208,  38, 178, 156,  80,
      38, 177, 124,  80,  42, 177, 104,   9 };

const byte Sound_C3_MULTIPILIE [176] PROGMEM = {
       0, 176,  47,  47, 202, 147,  40,   0, 207, 145,  42, 160, 206, 149,  35,  32,
     206, 151,  36, 161, 202, 152,  45,  67, 202, 151,  61, 195,  81, 151,  71,  40,
      21, 151,  63, 162, 101, 183,  87, 162,  97, 183,  79,  33,  90, 181,  78, 162,
     102, 180,  70,  33, 101, 181,  61, 190,  85, 181,  37,  63,  21, 148,   0,  48,
     129, 180,  64,  80, 133, 180,  88, 112,   4, 180, 252, 144,   9, 215, 156, 176,
      93, 216,  68,  48, 250, 216,  69, 185, 182, 216,  63,  60, 182, 217,  62, 190,
     102, 184,  54, 191, 146, 152,  51, 190, 144, 153,  72, 112,   5, 181,   0, 112,
      80, 183,  85, 176, 165, 150,  76, 155, 105, 182,  86,  61, 106, 182,  86, 190,
     114, 214,  62,  62, 118, 214,  37,  63, 105, 184,  78,  32, 181, 216,  86,  32,
     181, 216,  77, 191, 245, 216,  69,  32, 245, 216,  61,  64, 245, 216,  60, 190,
     229, 217,  43, 223, 213, 216,  43,  63, 193, 216,  50, 160, 133, 213,  49, 141 };

const byte Sound_C3_OBSTACLE [128] PROGMEM = {
       0, 128,  47,  47, 152, 182,  80,   0, 253, 179, 132, 191, 233, 179, 133, 160,
     233, 179, 134, 192, 254, 178, 117,  60, 217, 177, 128,  48, 197, 180, 120,  80,
      81, 185, 125,  16,   4, 217, 126,  48,  69, 216, 149, 176,  17, 216, 141,  48,
      84, 215, 140, 176,   0, 182, 176, 112,  68, 181, 205,  16, 164, 180, 125,  41,
     232, 180, 150, 220, 232, 180, 166, 223, 228, 180, 167,  65, 184, 181, 159,  65,
     184, 149, 142, 163, 233, 149, 125, 161, 144, 214, 128, 112, 144, 183, 112, 112,
      32, 216, 190, 176,  37, 216,  93, 176,  33, 183,   5,  48, 148, 182,  91, 194,
     144, 213,  91, 161, 128, 182,  67,  32,  22, 148,   2, 160,  17, 179,   0,  18 };

const byte Sound_C3_ONCLE [104] PROGMEM = {
       0, 104,  47,  47,  66, 177,  96,   0, 133, 176, 125, 191, 197, 176, 118,  96,
     137, 176, 110,  64,  73, 176, 110,  65, 141, 176, 101, 160, 140, 177,  84, 160,
     153, 173,  67,  63, 133, 167,  96,  48, 129, 152, 136,  80,  25, 146,  96, 112,
      17, 150, 246, 144,  48, 247, 190, 176,  49, 215,  94,  48,   1, 185, 254, 176,
     213, 182,  92, 166, 217, 180,  92, 191, 216, 179, 100,  63, 212, 146,  99, 160,
     148, 178,  99, 192, 149, 178, 108,  32, 153, 178,  75, 161,  85, 178,  59, 160,
      20, 177,  19, 191,  90, 178,   8,  24 };

const byte Sound_C3_ORTHOGRAPHE [204] PROGMEM = {
       0, 204,  47,  47,   0, 153, 248,   0,  85, 174, 180, 172,  82, 174, 166,  64,
      21, 174, 174, 162, 123, 205, 142, 161,  21, 172,  36, 191,  69, 173, 156, 144,
      65, 177, 164, 176,  17, 180, 197,  80,   1, 180,   5,  48,  64, 185, 136,  16,
     128, 179, 128,  48,  69, 216,  96,  80,   5, 217, 205, 144,  18, 212,   6,  48,
      22, 180,   5,   7,  23, 177, 111,  64,  27, 175,  86, 190,  43, 174,  70,  60,
      39, 172,   5,  56, 106, 173,  50, 191, 137, 135,  72,  48, 129,  84, 248,  80,
      37, 176,   4, 158,  69, 145, 245,  63,   6, 174,   6,  16,  22, 177,  77, 176,
      86, 177, 124,  31,  38, 175,   5,  63,  22, 174, 165, 191, 106, 175, 182,  32,
      90, 175, 198, 189, 169, 176, 190,  64, 185, 176, 182,  64, 189, 177, 174,  64,
     121, 176, 157, 161, 105, 176, 133,  63, 104, 177,  99, 190,  20, 178,  88,  16,
       0, 183, 253,  16,  21, 213, 157, 208,   4, 182, 253, 240,   5, 180, 253, 112,
       5, 180, 116, 208,  69, 179, 104,  16, 149, 176, 112,  48,  89, 177, 147,   1,
      89, 177, 139,  32, 102, 178, 114, 160, 102, 178, 112,  13 };

const byte Sound_C3_PAPA [84] PROGMEM = {
       0,  84,  47,  47,   0, 153, 248,   0,   8, 180, 173, 176,  25, 179,   5, 143,
     222, 178, 166, 168, 175, 178, 175, 160, 174, 178, 183, 223, 174, 178, 166,  62,
     173, 177, 140, 160, 221, 177, 152,  80, 132, 175, 152, 112, 132, 175, 152, 112,
      21, 183, 204, 144,   0, 180, 133, 176, 174, 177, 174, 220, 186, 177, 190, 222,
     190, 177, 190, 222, 190, 177, 190,  62, 121, 177, 189, 191, 233, 176, 180,  32,
     253, 176, 168,  15 };

const byte Sound_C3_PARENT [120] PROGMEM = {
       0, 120,  47,  47,  16, 212,   0,   0,   0, 180, 253, 144,   0, 182, 199,  16,
     146, 178, 141, 163, 165, 176, 158,  33, 153, 177, 183,  63, 169, 177, 191,  95,
     168, 177, 183,  95, 168, 176, 182, 191, 184, 176, 173, 160,  35, 176, 189,  16,
      35, 176, 189,   4,  19, 208, 141,  16,   2, 178,  93,   0,   6, 177, 125,  16,
      35, 176, 189,  16,  35, 176, 189,   0,  19, 208, 141,  16,   2, 178,  93,   0,
       6, 177, 125,  16, 105, 172, 132,  24, 100, 172, 140, 160, 101, 172, 165,  64,
     101, 172, 173, 161,  37, 171, 165,  64,  38, 170, 124, 193,  26, 167,  84,  33,
      26, 169,   3, 161,  42, 169,   0,  30 };

const byte Sound_C3_PERE [96] PROGMEM = {
       0,  96,  47,  47,   0, 153, 248,   0,  20, 180, 140, 144,  25, 181, 173, 176,
     110, 180, 134,  44, 190, 180, 151,   1, 190, 180, 151,  32, 190, 181, 167,  64,
     189, 182, 159,  95, 189, 182, 159,  94, 189, 182, 150, 189, 121, 182, 159,  95,
     125, 183, 150, 222, 253, 183, 142,  95, 185, 183, 142,  64, 185, 183, 134,  64,
     170, 183, 133, 192, 169, 182, 125,  64, 174, 179, 133,  80,  36, 178,   3, 176,
      33, 178, 196, 208,  38, 178, 156,  80,  38, 177, 124,  80,  42, 177, 104,   9 };

const byte Sound_C3_PLACE [144] PROGMEM = {
       0, 144,  47,  47,   0, 153, 248,   0,   0, 148, 253, 144,   1, 181, 253, 144,
      16, 180, 140, 143,  21, 149,   5, 164,  32, 181,   6, 160,  40, 181,   7,  64,
      44, 181,  55,  34,  45, 181,  79,  64, 189, 181, 151, 160, 186, 181, 183, 160,
     170, 180, 183, 192, 174, 180, 191,  62, 169, 180, 182, 222, 104, 180, 182,  61,
     168, 181, 165,  63,  37, 248,  53,  48,  25, 248,  45, 176,  25, 248,  45, 176,
       1, 248,  45, 208,   1, 247,  37,  80,   1, 247,  37,  80,  37, 248,  53,  48,
       1, 248,  45, 208,   1, 247,  37,  80,   1, 247,  36, 208, 186, 179, 115, 152,
     254, 179, 123, 191, 225, 179, 131, 192, 229, 178, 131,  95, 106, 178,  99,  62,
      89, 177, 106, 160,  85, 178, 106,  63,  85, 178,  81, 191,  89, 178,  96,  15 };

const byte Sound_C3_RECOMMENCE [172] PROGMEM = {
       0, 172,  47,  47,  35, 176, 184,   0,  35, 176, 189,  16,  35, 176, 189,   0,
      19, 208, 141,  16,   2, 178,  93,   0,   6, 177, 125,  16,  22, 171, 148, 131,
      38, 171,   5,  35,  22, 170,   6,  41,  26, 175, 134, 196,  26, 178, 126, 161,
     107, 178, 110, 160,  86, 146, 100, 177, 154, 178,  80,  48, 128, 179,  96, 112,
      33, 144, 132, 144,  17, 176, 198,  48,  33, 144, 181,   9,  86, 143, 109, 170,
      26, 171, 102, 222,  29, 170,   6,  60, 137, 180,  61, 191, 138, 182,  61, 223,
     138, 182,  53, 222,   6, 167, 142,  61,  22, 201, 182, 223,  38, 203, 126,  94,
      22, 201, 165, 223,  38, 170, 149,  64,  43, 169, 140, 223, 106, 172, 116, 223,
       1, 248,  45, 208,   1, 247,  37,  80,   1, 247,  36, 208,   1, 247,  37, 112,
       1, 247,  36, 208, 249, 178, 124,   4, 234, 178, 132,  32, 150, 177, 131, 192,
     166, 177, 107, 191,  89, 175,  91,  32,  89, 176, 104,   0 };

const byte Sound_C3_RECULE [132] PROGMEM = {
       0, 132,  47,  47,   0, 153, 248,   0, 165, 176, 124,  48, 224, 207, 124, 221,
     249, 174, 107, 160,  69, 204, 124, 160,  90, 173, 108,  64, 161, 173, 124, 167,
     165, 174, 126,  34, 106, 177, 127,  65, 169, 178, 118, 161, 166, 178, 101,  32,
      81, 177, 128,  80,  97, 214, 120, 112,  34, 182, 254,  48,  49, 183, 141,  48,
      48, 215,   5, 176, 177, 183,  76, 147, 233, 150,  68, 191, 213, 150,  77,  62,
     165, 151,  77, 223, 213, 151,  77, 223, 229, 150,  85,  64, 160, 184,  86,  65,
      96, 184,  77, 160,  41, 183,  54,  65, 122, 182,  78, 163, 190, 182,  85, 194,
     233, 181,  76, 161, 144, 148,  91, 193,  85, 145,  66, 192,  85, 147,  42,  33,
      85, 147,   8,  17 };

const byte Sound_C3_SOEUR [96] PROGMEM = {
       0,  96,  47,  47,  14, 218, 248,   0,  78, 218, 253, 112,  14, 214, 237, 112,
      30, 214, 149, 208, 165, 180, 125,  12, 170, 180, 135,  58, 250, 179, 135,  63,
     250, 179, 142, 191, 247, 179, 150, 192, 234, 179, 150, 192, 234, 179, 143,  64,
     250, 180, 134, 193, 249, 180, 134,  34, 252, 180, 141, 192, 232, 179, 141,  32,
      37, 177, 205, 208,  53, 176, 205,  16,  53, 177, 172, 176,  37, 177, 156,  31,
      37, 177, 115, 128,  25, 177,  83,   0,  24, 177,  66,   0,  44, 177,  56,  29 };

const byte Sound_C3_SOUSTRAIT [112] PROGMEM = {
       0, 112,  47,  47,  86, 213, 144,   0,   2, 215, 134, 144,   2, 215, 134, 176,
       2, 215, 134, 240,  70, 171, 117, 136,  70, 171, 117, 224,   2, 215, 134, 208,
       2, 215, 134, 240,  81, 180, 248,  48,  81, 180, 248,  80,  80, 179, 136, 112,
     128, 187, 254,  48, 100, 211, 102,  48,  80, 179, 133, 176,  85, 179, 229, 176,
     118, 180, 229, 176, 166, 181,  93, 176, 233, 180, 117,  32, 234, 181, 142, 160,
     190, 181, 143, 191, 170, 182, 143, 223, 106, 183, 119,  64, 250, 183, 118, 190,
     250, 183, 110,  32, 166, 184, 109,  63, 229, 184,  99, 160, 165, 151,  72,   4 };

const byte Sound_C3_SYNTHESE [156] PROGMEM = {
       0, 156,  47,  47,  68, 217, 248,   0,  68, 218, 252,  16, 132, 218, 252, 208,
      68, 216, 252, 176, 132, 218, 253,  48, 168, 178, 141, 175, 168, 179, 167,  38,
     168, 179, 175,  32, 168, 180, 183,  32, 164, 180, 191,  32, 152, 180, 166, 192,
     152, 180, 150,  32, 152, 178,  68, 185, 128, 178,  80,  48, 192, 213, 152,  80,
     192, 213, 152, 112,  65, 148,   3, 144, 153, 214, 180, 176, 212, 182, 115, 159,
     249, 181, 134,  63, 249, 181, 150, 188, 233, 182, 158, 222, 254, 182, 150, 192,
     249, 182, 150, 223, 254, 182, 142,  95, 254, 182, 134,  64, 254, 182, 133, 160,
     191, 182, 109, 192, 170, 184,  61,  93, 170, 184,  68, 192, 170, 184,  68,  64,
     222, 180,  91,  33, 254, 180,  99,  32, 253, 180, 115,  63, 229, 179, 130,  63,
     153, 179,  98,  32, 149, 177,  89, 160, 153, 179, 104,  13 };

const byte Sound_C3_TANTE [92] PROGMEM = {
       0,  92,  47,  47,  35, 208, 168,   0,   4, 177, 212, 144,   0, 216, 238, 176,
      85, 180, 133, 176, 149, 178,  92,   6,  98, 174, 141,  95, 102, 174, 166,  62,
      18, 173, 183,  63,  34, 172, 167,  63,  34, 171, 166, 192,  34, 171, 134,  63,
      18, 170, 134,  65,  22, 173, 150,  65,  22, 172, 133,  34,  70, 174, 100,  32,
     130, 178,  83,  62,  65, 172, 104,  80,   0, 149, 248, 112,   0, 186, 253,  16,
       5, 180, 149,  80, 132, 178,  42, 160, 153, 179,   8,   0 };

const byte Sound_C3_AUTO [84] PROGMEM = {
       0,  84,  47,  47,   0, 142, 216,   0,  90, 170, 125,  36, 170, 171, 109, 160,
     186, 173, 118,  32, 186, 176, 102,  64, 149, 179,  93, 191, 128, 177,  88, 112,
     128, 179,  96, 112,  21, 184, 214,  16,  84, 215, 215, 176,   1, 215, 182,   0,
     153, 177, 110, 191, 154, 176, 110, 190, 171, 173, 110, 192, 102, 172, 110, 190,
     106, 170, 110,  64, 219, 170, 109,  33, 146, 169,  92,  34, 194, 163,  91, 161,
      70, 177,  88,  28 };

const byte Sound_C3_AUTOBUS [148] PROGMEM = {
       0, 148,  47,  47,  69, 168, 192,   0, 134, 170, 125,  27, 145, 172, 117, 160,
     153, 173, 110,  32,  86, 146, 102, 192, 128, 183,  83, 186, 212, 176,  96,  48,
     193, 179,  96,  80,   5, 183, 230,  48,  72, 215, 175,  48, 144, 212, 101, 175,
     165, 143, 101, 187, 233, 142, 101, 222, 160, 141, 100, 190, 144, 172,  51,  60,
     132, 172,  48,  48,  32, 128,   0,  80, 132, 132,  58,  16,  81, 181,  59, 152,
      16, 182,  29,  35,  69, 151,  70,  35, 160, 183,  78, 192, 144, 151,  77, 161,
     218, 150,  69,  32, 160, 151,  70,  65,  96, 183,  63,  66, 100, 151,  71,  34,
     164, 183,  70, 162, 164, 183,  70,  32,  93, 185,  53, 190,  30, 215,   6, 176,
      74, 214, 254, 240,  30, 215,   6, 112,  26, 214, 173, 240,  94, 213, 213, 112,
      94, 213, 208,  27 };

const byte Sound_C3_AVION [96] PROGMEM = {
       0,  96,  47,  47,   0, 181, 248,   0, 100, 181, 189,  22, 232, 180, 173, 160,
     132, 181, 157,  32, 184, 181, 142,  32, 164, 181, 126,  64, 153, 148, 109,  62,
     133, 144,  83,  62, 133, 181,  67,  64, 138, 184,  77,  33, 213, 184,  77,  65,
     214, 184,  77,  63, 229, 216,  77, 191, 233, 183,  77, 192, 181, 183,  94,  33,
     101, 150, 118,  33,  85, 148, 126,  33,  24, 168, 141,  64,  24, 163, 141,  64,
     136, 165, 124,  35,  24, 160,  91,  33,  24, 160,   2, 162,  40, 160,   0,  30 };

const byte Sound_C3_BAS [56] PROGMEM = {
       0,  56,  47,  47, 213, 176,  16,   0,  84, 179,   4,   1, 100, 179,  21, 155,
     169, 180, 134,  28, 234, 176, 149, 129, 170, 177, 166, 190, 250, 177, 175,  32,
     169, 177, 174, 192, 186, 177, 175,  64, 165, 176, 182,  32, 160, 176, 173,  32,
      88, 174, 148, 161, 101, 174, 112,   9 };

const byte Sound_C3_BATEAU [80] PROGMEM = {
       0,  80,  47,  47, 213, 176,  16,   0,  84, 179,   4,   1, 100, 179,  21, 155,
     169, 180, 134,  28, 233, 180, 150, 161, 184, 181, 151,  64, 180, 182, 142, 160,
     150, 213, 109, 160, 224, 181, 120,  80, 161, 182, 136, 112,  69, 216, 131, 144,
      86, 182, 214,  48,  81, 213, 101, 187, 154, 175, 101, 194, 169, 173, 101, 160,
     169, 172, 101,  32, 154, 170,  92, 192, 230, 169,  82, 161, 150, 168,  72,   6 };

const byte Sound_C3_CAMPINGCAR [184] PROGMEM = {
       0, 184,  47,  47, 144, 182,  88,   0,  32, 183, 215,  48,  16, 214, 213, 144,
     145, 180, 126,  47, 106, 175, 126,  36,  89, 171, 142,  64,  89, 170, 125, 161,
      72, 170, 117, 160, 156, 175,  68, 190, 136, 172,  67, 191, 136, 174,  58, 183,
      68, 160,  56,  16, 192, 149,  96,  80,  21, 182,  94, 176,  37, 183,   5,  17,
     217, 184,  69, 162, 129, 216,  69, 192, 137, 150,  61, 160, 132, 185,  60, 191,
     136, 184,  61,  32, 132, 185,  60, 192, 136, 153,  61,  63, 136, 153,  52, 160,
     136, 149,  59, 191, 144, 185,  56,  48, 128, 181,  64, 112,   1, 184, 252,  16,
       4, 216, 190, 176, 196, 216,  93,  63, 228, 184, 118,  32, 228, 183, 142, 191,
     164, 181, 142, 223, 160, 180, 158, 192, 164, 180, 158, 223, 164, 179, 157, 223,
     184, 178, 157, 192, 232, 178, 157, 190, 164, 177, 165,  32, 144, 210, 164, 191,
     132, 178, 155, 176, 148, 177, 147, 176,  84, 177, 155, 176,  84, 176, 139, 208,
     104, 177, 128,  11, 104, 177, 128,  12 };

const byte Sound_C3_CAR [84] PROGMEM = {
       0,  84,  47,  47, 128, 181,  64,   0,   1, 184, 252,  16,   4, 216, 190, 176,
     196, 216,  93,  47, 228, 184, 118,  63, 228, 183, 142, 190, 164, 181, 174, 223,
     160, 180, 190, 221, 164, 180, 190, 222, 164, 179, 189, 222, 184, 178, 189, 220,
     232, 178, 189, 160, 164, 177, 181,  32, 144, 210, 180, 160, 132, 178, 171, 176,
     148, 177, 163, 176,  84, 177, 155, 176,  84, 176, 139, 208, 104, 177, 128,  12,
     104, 177, 128,  12 };

const byte Sound_C3_CARRE [108] PROGMEM = {
       0, 108,  47,  47,   0, 153, 248,   0,   4, 182,   3,  16,  20, 215, 230,  16,
      72, 216, 190, 144, 164, 215, 109, 164, 160, 182, 142, 160, 229, 149, 167,  63,
     165, 180, 183,  64, 165, 148, 183,  64, 164, 147, 174,  32, 168, 147, 165, 191,
      89, 179, 149,  63,  37, 179, 173, 208,  22, 178, 173,  48,  49, 211, 141,  80,
     101, 180,  92,  48, 165, 181, 108,  31, 212, 182, 116, 191, 228, 183, 117, 192,
     249, 183, 118,  63, 185, 184, 110,  32, 249, 184, 101, 160, 228, 152, 100, 161,
     225, 152,  75, 193, 213, 152,  51,  65, 197, 152,  72,  25 };

const byte Sound_C3_CENTIME [136] PROGMEM = {
       0, 136,  47,  47, 130, 216, 136,   0,   6, 214, 197,  16,   6, 216, 253,  80,
      22, 213, 197,  80,  70, 218, 252, 176, 144, 176, 117, 175, 161, 173, 134,  64,
     145, 172, 126,  95, 161, 173, 117, 190, 145, 171,  83, 186, 145, 171, 112,  48,
     128, 178, 112, 112,  73, 218, 120, 112,  30, 218, 125, 176,   8, 218,  37, 176,
     200, 217,  52, 182, 208, 249,  52, 164, 224, 249,  44, 191, 248, 249,  36, 189,
     240, 152,  51, 191, 200, 144,  51, 192, 204, 145,  51,  95, 140, 149,  60, 192,
     140, 180,  60, 190, 140, 147,  59, 191, 220, 177,  51, 192, 249, 178,  67, 160,
     168, 179,  91, 192, 164, 179,  91, 191,  96, 210,  90, 192,  80, 178,  90,  63,
       0, 175, 104,  12,   0, 175, 104,  14 };

const byte Sound_C3_CERCLE [96] PROGMEM = {
       0,  96,  47,  47, 161, 216,  64,   0,  14, 220, 252,  80,  30, 214,   4, 208,
     168, 182, 125, 165, 248, 182, 134, 189, 213, 183, 142, 192, 229, 183, 143,  64,
     228, 183, 142,  32, 209, 151, 133, 161, 228, 183, 116, 160, 166, 182,  92, 144,
      33, 181, 133,  80,  17, 148,   5,  80, 177, 182, 128, 112, 177, 182, 128, 112,
      16, 214, 252,  16,  48, 214, 189, 176,  98, 215,  45,  80, 196, 182,  85,  65,
     208, 180,  92, 161,  69, 182,  76, 193,  87, 148,  27, 192,  86, 179,   0,  17 };

const byte Sound_C3_ELECTRICITE [168] PROGMEM = {
       0, 168,  47,  47,  32, 184,  80,   0, 164, 184, 110, 156, 245, 184, 110, 161,
     245, 184, 111,  32, 245, 183, 111,  32, 234, 183, 103,  64, 250, 183, 111, 161,
     230, 184, 103,  64, 231, 185,  94,  62, 206, 153,  91, 160, 209, 216,  99, 161,
     224, 184,  82, 160, 180, 183,  99,  32, 240, 183, 101,  16,  16, 215,  47,  48,
      21, 215, 117, 176,  16, 184, 101,  48,  17, 184,   5, 176,  16, 217,   5, 208,
     230, 185,  77,  34, 234, 184,  76, 220, 102, 184,  69, 144,  26, 185,  69,  80,
      22, 216, 125,  80,  30, 217, 205, 176,  74, 217,  78,  48, 253, 217,  69,  38,
     226, 217,  60, 223, 144, 216,  51, 188, 128, 183,  64,  48,   0, 184, 248, 112,
      85, 215, 181, 176,   5, 216, 189,  48, 234, 184,  93, 169, 250, 183, 102, 189,
     249, 184, 103,  95, 250, 184, 103,  64, 249, 184,  94, 161, 213, 152,  93,  34,
     202, 184,  84, 160, 202, 183,  72,   0 };

const byte Sound_C3_FENETRE [112] PROGMEM = {
       0, 112,  47,  47,  35, 180,   0,   0,  37, 180, 253, 208,  42, 181, 254,  80,
      41, 181, 182,  80,  86, 180, 125, 208, 214, 179, 109,  10, 234, 179, 118,  61,
     153, 181, 127,  95,  89, 181,  94,  60, 140, 177,  68, 161, 137, 176,  69,  32,
     132, 183,  69,  64, 169, 182, 135,  64, 165, 182, 143, 223, 186, 182, 143, 192,
     170, 182, 135, 162, 245, 183, 127,  34, 213, 182, 101, 162, 181, 183, 100, 191,
     208, 183, 112,  80,  80, 215, 112, 112,  16, 216, 158,  48,   2, 182, 205, 208,
      33, 179, 221, 176,  17, 178, 205,  80, 128, 211, 251, 160,  17, 211, 208,   0 };

const byte Sound_C3_FRANC [84] PROGMEM = {
       0,  84,  47,  47,  64, 215, 112,   0,  21, 181,   5,  48,  21, 182,  77, 112,
      21, 182, 181, 176,  69, 180, 237, 208,  85, 179, 221, 176,   5, 176, 173,  48,
      69, 174, 205,  48, 197, 177, 237,  80, 133, 182, 229,  48,   6, 169, 147, 170,
      86, 173, 140, 160,  86, 172, 149, 160, 147, 171, 157, 192,  83, 170, 165, 222,
      82, 170, 165, 221,  22, 167, 140, 189,  85, 168, 131, 188, 162, 169, 114,  32,
      16, 165, 128,  14 };

const byte Sound_C3_GARE [112] PROGMEM = {
       0, 112,  47,  47, 132, 182,  56,   0,  36, 183,   5,  16, 229, 185,  85,  37,
     229, 184, 118, 160, 229, 183, 143, 160, 244, 182, 159, 161, 184, 181, 167, 161,
     164, 180, 175,  32, 165, 180, 183, 191, 165, 180, 175,  32, 180, 179, 174, 222,
     169, 179, 174, 221, 164, 178, 174,  95, 168, 178, 174,  95, 169, 178, 174,  95,
     169, 177, 157, 192, 169, 177, 149,  32, 168, 177, 124, 160, 168, 176,  83,  32,
     104, 209,  83,  32, 121, 177,  91,  32,  49, 177,   4,  16,  36, 209, 212,  80,
     121, 177,  76,  80, 169, 176,  99, 176,  96, 175,  58, 176,  36, 176,   0,  42 };

const byte Sound_C3_HAUT [44] PROGMEM = {
       0,  44,  47,  47, 106, 169, 120,   0, 106, 169, 125,  27, 170, 169, 125,  63,
     235, 169, 116, 160, 175, 168, 108, 192, 175, 168, 116, 192, 239, 168, 108, 193,
     187, 167,  83, 163, 239, 166,  90, 164, 134, 164,  96,  21 };

const byte Sound_C3_HELICOPTERE [180] PROGMEM = {
       0, 180,  47,  47, 229, 215,  56,   0, 228, 216,  92, 137, 228, 216, 109, 162,
     228, 217, 102, 162, 228, 217, 103,  34, 248, 217,  95,  32, 225, 216,  53, 191,
     212, 216,  45,  32, 209, 216,  68,  33, 192, 249,  76, 160, 232, 217,  77, 163,
     241, 217,  61, 161, 241, 217,  60,  32, 145, 217,  80, 112,  48, 181, 230, 176,
      48, 213, 173, 159, 225, 180, 101, 160, 213, 179, 118, 187, 234, 176, 118,  59,
     145, 144,  67, 181, 196, 178,  96, 112,  85, 182, 116, 144,  17, 186,  45, 176,
     145, 217,  99, 144, 192, 182, 112,  16,  81, 185, 248, 112,  16, 183, 254,  16,
      84, 214, 117, 176, 252, 182, 118, 165, 253, 182, 134, 187, 244, 182, 134,  63,
     185, 182, 134, 192, 249, 182, 142,  95, 212, 182, 125,  62, 212, 182, 133,  63,
     228, 183, 132, 192, 212, 183, 132, 192, 229, 183, 124, 192, 229, 183, 116, 192,
     229, 182, 100,  63, 165, 181, 108,  32, 169, 180, 115, 160,  82, 179, 115, 160,
      18, 179,  40,  46 };

const byte Sound_C3_HEURE [100] PROGMEM = {
       0, 100,  47,  47,  64, 132, 152,   0, 149, 179, 139,   4, 233, 179, 149, 160,
     234, 179, 150,  34, 230, 179, 150, 160, 250, 179, 150, 224, 233, 179, 142, 192,
     233, 179, 142,  61, 229, 180, 134,  64, 169, 180, 134,  93, 229, 180, 133,  62,
     149, 180, 117,  64, 217, 147, 116,  64, 214, 147, 115, 191, 154, 179, 116,  32,
      49, 176, 180, 144,  48, 177, 171, 157,  53, 177, 180, 144,  33, 177, 171, 128,
      49, 177, 172, 144,  85, 177,  91,  32, 149, 175, 114, 160, 144, 175, 114,  34,
     101, 177,  64,  15 };

const byte Sound_C3_KILO [88] PROGMEM = {
       0,  88,  47,  47, 128, 181,  64,   0,   1, 184, 252,   0,   4, 216, 189,   0,
       4, 216, 189,  16, 137, 217,  44, 143, 193, 217,  61,  70, 208, 216,  61,  94,
     209, 215,  60, 188, 166, 214,  45,  62, 101, 184,  54,  60, 166, 183,  54,  62,
     166, 182,  54,  62, 149, 182,  86,  63, 145, 179, 101, 223, 149, 176, 109,  62,
      65, 174, 108, 191, 128, 170, 108,  62, 213, 170,  91, 160, 213, 170,  83, 160,
     149, 168,  74,  32, 214, 168,  80,  13 };

const byte Sound_C3_L_ [36] PROGMEM = {
       0,  36,  47,  47, 208, 151,  64,   0, 208, 151,  66,   1, 200, 115,  58, 160,
     241, 150,  60,  32, 245, 150,  60, 161, 162, 149,  61,  32,  98, 181,  61,  36,
      86, 179,  88,  21 };

const byte Sound_C3_LA [44] PROGMEM = {
       0,  44,  47,  47, 216, 215,  88,   0, 236, 214,  91,  92, 236, 214,  83, 161,
     236, 182,  68, 161, 252, 182,  76,  33, 164, 182, 109, 160, 184, 181, 166,  64,
     249, 180, 150,  64, 168, 179, 100, 161,  76, 178,  64,   8 };

const byte Sound_C3_LE [48] PROGMEM = {
       0,  48,  47,  47, 160, 182,  80,   0, 244, 181,  83,  59, 224, 182,  67, 160,
     164, 182,  60, 191, 180, 182,  60, 160, 164, 182,  85, 163, 168, 181, 102,  32,
     234, 181, 102,  32, 165, 181,  93, 191, 232, 180,  52,  63, 200, 180,  40,  10 };

const byte Sound_C3_LES [64] PROGMEM = {
       0,  64,  47,  47,   0, 153, 248,   0, 248, 215,  99, 160, 228, 215,  91, 160,
     226, 183,  75, 160, 225, 183,  76, 160, 241, 183,  69,  32, 241, 183,  69,  64,
     249, 183,  94,  34, 229, 184, 110, 160, 246, 184, 102, 192, 245, 184,  94, 160,
     248, 184,  86,  95, 232, 184,  69,  60, 233, 184,  76, 191, 230, 184,  64,  10 };

const byte Sound_C3_LUMIERE [120] PROGMEM = {
       0, 120,  47,  47,  84, 150,  56,   0, 169, 150,  76, 183, 233, 150,  67, 160,
     253, 150,  68,  32, 185, 150,  60, 162, 170, 150,  44, 193, 100, 151,  53, 161,
      97, 184,  54,  34, 165, 184,  70,  65, 149, 151,  70,  32, 136, 148,  61,  96,
     136, 148,  61,  63, 148, 248,  70,  95, 212, 216,  86, 192, 169, 183, 127,  96,
     166, 182, 135,  96, 154, 182, 135,  96, 170, 183, 127,  64, 165, 151, 118,  65,
     151, 151, 109, 161, 232, 151, 100, 162, 169, 150,  76,  35, 138, 150,  83, 162,
     150, 149,  76, 144,  18, 180,   4, 208,  34, 179,   4, 208,  17, 179, 244, 176,
      49, 178,   3, 208,  49, 178,   0,  18 };

const byte Sound_C3_METRE [116] PROGMEM = {
       0, 116,  47,  47, 233, 180,  56,   0, 236, 180,  34, 146, 216, 180,  42, 162,
     221, 180,  43, 162, 140, 181,  60, 162, 140, 181,  60, 163, 169, 180,  61,  34,
     229, 181, 151,  39, 244, 182, 151, 163, 180, 182, 151, 161, 160, 183, 143,  63,
     224, 183, 134, 189, 164, 183, 133, 188, 168, 184, 109,  60, 212, 184, 107, 191,
     145, 183, 120,  80,  16, 215, 168, 112,  33, 180, 168, 112,  96, 244, 204, 208,
      36, 179, 180,  48, 145, 177, 116,  80,  68, 177, 131, 185, 144, 207, 131, 222,
      89, 175, 115, 189,  64, 170, 123,  32,  85, 174,  82, 191,  81, 176,  90,  32,
      17, 177,   0,  45 };

const byte Sound_C3_METRO [96] PROGMEM = {
       0,  96,  47,  47, 170, 180,  80,   0, 232, 180,  52,  21, 136, 183,  44,  66,
     136, 150,  52, 194, 234, 183, 110, 167, 229, 184, 118, 161, 228, 184, 102, 161,
     248, 184,  85, 160, 128, 184,  83, 160, 208, 153, 104, 112,  81, 216, 125, 144,
      65, 180, 254,  48,  17, 146, 245,  48,  33, 208, 132,  48,  18, 170,  96,  80,
      22, 170,  75, 177,  18, 169,   4, 160, 214, 169, 108,  33, 213, 168,  92,  64,
     213, 168,  99, 190, 213, 167,  91,  62, 149, 167,  66,  32, 145, 199,  64,  13 };

const byte Sound_C3_MINUTE [132] PROGMEM = {
       0, 132,  47,  47, 132, 145,  16,   0, 132, 113,  18,  22, 136, 112,  34, 161,
     192, 143,  11,  35, 200, 146,  20,  32, 204, 146,  20, 194, 205, 146,  29,  35,
     200, 148,  29, 163, 208, 218,  45, 162, 129, 218,  45, 193, 129, 186,  45,  32,
     201, 144,  36, 161, 200, 145,  28, 223, 201, 146,  29,  92, 132, 215,  29, 189,
     244, 217,  46,  94, 224, 217,  45, 189, 225, 184,  37,  63, 208, 184,  36,  62,
     192, 216,  48, 112,  64, 180,  24, 112,  20, 183, 120, 112,   0, 215, 117, 176,
       6, 182,   6,  48, 154, 181,  92, 136, 233, 180, 108, 190, 228, 179, 116,  63,
     212, 179, 123,  95,  84, 180,  91,  62, 148, 179,  66, 191,  81, 179,  56,  13,
      81, 179,  56,  13 };

const byte Sound_C3_MUR [104] PROGMEM = {
       0, 104,  49,  47,  68, 181,  48,   0, 132, 181,  58, 148, 132, 154,  43,  32,
     144, 185,  52, 160, 144, 217,  52, 193,  80, 217,  53,  64,  80, 217,  61, 161,
      84, 183,  78,  32, 100, 183,  86, 224, 144, 184,  86, 224, 149, 183,  86,  64,
     213, 182,  85, 192, 212, 183,  84, 193, 197, 183,  84,  33, 229, 182,  75, 161,
     233, 181,  66, 160, 228, 181,  82, 169, 161, 181,  60,  16,  32, 180,   4,  48,
     192, 148, 252,  48,  18, 179, 252, 208,  66, 183, 252, 208,  50, 209, 252, 208,
     128, 186, 252,  80, 128, 183, 248,  17 };

const byte Sound_C3_PIECE [96] PROGMEM = {
       0,  96,  47,  47,   0, 153, 248,   0,  68, 186, 255,  48,   8, 184,   6, 176,
       5, 217,   6,  16, 154, 216,  77,  31, 229, 216,  69,  64, 228, 184,  93, 160,
     228, 183, 102, 160, 228, 183, 119,  62, 249, 182, 135,  64, 250, 182, 135,  64,
     249, 182, 127,  34, 229, 182, 126, 161, 229, 182, 118,  32, 229, 182, 100, 161,
     218, 214, 116,  16,  22, 215,  93, 112,  26, 215,  84, 176,  26, 215,  60, 112,
      27, 215,  36, 112,  22, 213,  28,  48,  14, 214,   4, 112,  10, 213,   0,  29 };

const byte Sound_C3_PLANCHER [104] PROGMEM = {
       0, 104,  47,  47,  37, 178, 136,   0,  81, 184, 254,  48,   5, 115, 212, 143,
     148, 117, 100, 186,  84, 148, 101, 191,  88, 148, 109, 190,  84, 178, 125, 161,
      22, 174, 158, 192,  21, 170, 134,  95,  36, 170, 125, 160,  36, 171,  92, 160,
       4, 171, 131, 160,   4, 182, 254,  48,   1, 188, 254,  48,   5, 219, 254, 112,
      24, 219, 254,  80, 135, 186, 253, 176, 181, 182, 109,  38, 233, 183, 109, 221,
     233, 184, 101, 223, 229, 184, 101,  32, 233, 184,  84, 160, 201, 153,  75,  33,
     213, 184,  66, 160, 213, 184,   0,   7 };

const byte Sound_C3_PORTE [100] PROGMEM = {
       0, 100,  47,  47,   0, 153, 248,   0,  82, 182, 166, 176, 107, 173, 124, 190,
     169, 173, 133, 160, 186, 174, 141, 191, 174, 174, 150,  63, 105, 174, 150,  64,
     185, 174, 141,  33, 189, 174, 123, 160, 186, 174, 100,  16,  86, 206, 132,  48,
      21, 206, 165,  48,  86, 207, 157,  48,  66, 207, 172, 176,   2, 209, 196, 208,
       5, 179, 189,  48,  16, 213, 156, 176,  16, 214,  80, 112,  16, 214,  80, 112,
      65, 216, 205,  48,  66, 216, 165,  48,  18, 181, 180, 176,  19, 180, 132,  48,
      35, 180,   0,   6 };

const byte Sound_C3_RECTANGLE [156] PROGMEM = {
       0, 156,  47,  47,  68, 214,  56,   0, 105, 179, 100, 208, 169, 179, 116,  80,
     165, 179, 116, 129, 148, 180, 124, 165, 164, 180, 141, 162, 180, 149, 150, 161,
     164, 149, 142,  32, 228, 151, 117, 160, 164, 183, 108, 185, 213, 183, 120, 112,
       4, 151, 158,  48,  33, 215, 116, 176,  33, 215, 112, 112,   1, 183, 156, 144,
       5, 182, 197,  48, 133, 180, 140, 129, 165, 178, 142,  33,  89, 177, 166, 189,
      22, 175, 174, 190,  33, 172, 174, 192,  37, 171, 158, 192,  25, 171, 142,  64,
       4, 170, 149, 161,  73, 178, 101,  33, 137, 180,  84, 160, 136, 146,  75, 192,
     132, 147,  75, 159, 132, 147,  72,  32, 129, 150,  76,  16, 162, 181,  84,  35,
     165, 150,  84,  32, 165, 180,  92,  64, 225, 180,  91, 161, 212, 180,  91,  32,
     168, 180,  99,  64,  85, 180,  50,  64,  85, 180,  32,  25 };

const byte Sound_C3_TABLE [92] PROGMEM = {
       0,  92,  47,  47,   4, 170,  48,   0,  16, 184, 246, 176,  64, 217, 221, 151,
     212, 181, 134,  34, 244, 180, 159,  35, 245, 180, 175,  64, 165, 180, 183,  63,
     160, 179, 182, 192, 165, 179, 191,  64, 170, 179, 175,  95, 171, 178, 158, 191,
     170, 177, 124, 189, 149, 176,  82, 160,  64, 116, 160, 112,  21, 147, 245,  48,
     164, 149,  91, 162, 168, 181, 100,  65, 168, 180, 115, 192, 168, 180, 131, 161,
      84, 179, 123,  32,  84, 178,  98, 160, 165, 179,  64,   3 };

const byte Sound_C3_TAXI [104] PROGMEM = {
       0, 104,  47,  47,   0, 179, 208,   0,  16, 215, 206,  48, 224, 182, 117, 161,
     228, 182, 150, 160, 229, 150, 151,  62, 185, 150, 135,  63, 229, 150, 133,  61,
      96, 182, 148, 176, 164, 182, 136,  16, 208, 213, 128,  80,  80, 148, 156,  16,
      33, 182, 149,  48,  37, 183, 117,  80,  36, 215, 148, 208,  37, 184, 156, 208,
      26, 184, 205,  80,  25, 184,   5, 208, 233, 185,  69,  38, 249, 217,  62,  64,
     234, 217,  62,  64, 228, 217,  69,  33, 212, 250,  60,  32,  65, 181,  35, 160,
     132, 182,  43,  32, 201, 209,  32,  28 };

const byte Sound_C3_TELEPHONE [140] PROGMEM = {
       0, 140,  47,  47,   0, 148, 248,   0,  16, 215, 238,  16,  16, 215, 158, 176,
     229, 183, 101, 193, 245, 183, 110, 160, 229, 183, 111,  63, 250, 183, 103,  62,
     187, 183, 102, 190, 155, 183,  94,  63, 234, 184, 102, 161, 249, 183, 103,  64,
     249, 183, 102, 160, 234, 150,  93,  63, 105, 182,  85,  16,  21, 182,   6, 176,
      21, 183,  55,  80,  32, 182,   6,  80,  21, 180, 254,  80,  33, 147, 229, 208,
     217, 177, 125,  37, 250, 177, 134,  61, 234, 177, 134, 190, 174, 177, 134, 191,
     170, 177, 142, 192, 171, 179, 143,  64, 106, 179, 126, 161,  73, 180,  77, 160,
     156, 179,  69,  34, 136, 179,  77,  65, 136, 179,  68, 161, 136, 178,  60,  65,
     200, 186,  59, 161, 132, 181,  34, 162, 132, 183,  48,  20 };

const byte Sound_C3_TELEVISION [136] PROGMEM = {
       0, 136,  47,  47,  64, 153, 248,   0,  81, 184, 205,  16, 144, 183, 205, 176,
     249, 183, 101, 175, 250, 183, 119,  39, 170, 184, 119, 192, 186, 215, 103,  62,
     166, 215,  53,  32, 182, 215,  60, 162, 165, 215,  53,  32, 186, 184,  94, 223,
     186, 216,  78, 223, 167, 184,  61, 188, 215, 151,  60,  32, 155, 151,  27, 188,
     102, 184,   4, 160, 247, 216,  53, 160, 251, 216,  53, 192, 251, 216,  45, 192,
     251, 216,  53,  95, 186, 216,  52, 222, 191, 183,  44, 159,  94, 184,  20, 160,
      22, 245, 116,  56,  22, 245, 116, 193,  21, 183,   5,  32, 109, 214,  85, 160,
      21, 183,   5,  64,  97, 150,  85, 192,  41, 168,   4, 224,  41, 162,   3,  64,
     136, 179,  82, 224,  69, 174,  72,   5 };

const byte Sound_C3_TONNE [112] PROGMEM = {
       0, 112,  47,  47,   2, 185, 240,   0,  85, 215, 165, 176, 228, 179, 117,  47,
     229, 177, 134,  63, 234, 177, 142, 191, 170, 176, 151,  62, 170, 176, 159,  95,
     186, 177, 159,  95, 166, 177, 158, 188, 166, 179, 142,  61, 166, 179, 117, 189,
     234, 179, 100, 187, 140, 178,  68,  32, 140, 178,  60,  64, 204, 177,  59, 190,
     140, 179,  59, 192, 140, 183,  67, 192, 204, 179,  60,  64, 204, 179,  59, 160,
     204, 181,  59, 192, 216, 180,  83, 161, 213, 180, 123, 160, 233, 179, 123, 191,
     165, 179, 131,  95, 164, 178, 115,  63, 144, 178, 123,  32, 144, 179, 120,  45 };

const byte Sound_C3_TRAIN [68] PROGMEM = {
       0,  68,  47,  47,   0, 153, 248,   0,   0, 216, 221,  16,   0, 217, 254, 176,
      37, 181, 206,  80,  22, 178,   5,  48,  26, 180, 102,  48,  84, 177, 133,  61,
      85, 178, 158,  32, 102, 178, 182,  64, 145, 178, 182,  95,  85, 178, 173, 161,
      64, 145, 165, 162,  80, 145, 124, 161,  84, 178,  75, 164,  21, 177,   3,  32,
      21, 177,   0,  26 };

const byte Sound_C3_TRIANGLE [140] PROGMEM = {
       0, 140,  47,  47,  85, 183,  56,   0,  17, 118, 253,  48,  98, 213, 214,  48,
      34, 183,  21, 208, 209, 184,  77,  40, 224, 217,  77, 192, 212, 217,  69, 191,
     164, 217,  69,  62, 132, 217,  77,  95, 196, 216,  85,  33, 233, 184, 102, 160,
     165, 183, 127,  63, 101, 181, 151,  63,  85, 178, 158, 191,  22, 173, 182, 223,
      86, 173, 190, 192,  42, 172, 174,  64, 106, 172, 157, 160,  41, 172, 133, 161,
       8, 171, 125, 160, 136, 179,  92, 160, 136, 179,  84,  64, 136, 148,  75, 191,
     200, 146,  66,  32,  73, 145,  64,  48, 129, 150,  76,  16, 162, 181,  84,  35,
     165, 150,  84, 160, 165, 180,  92,  65, 225, 180,  91, 160, 212, 180,  91,  32,
     168, 180,  99,  64,  85, 180,  50,  64,  85, 180,  32,  24 };

const byte Sound_C3_UN [56] PROGMEM = {
       0,  56,  47,  47,   0, 116, 248,   0,  80, 146, 172, 153, 161, 178, 157, 160,
     160, 178, 157, 162,  64, 146, 125,  32,  97, 179, 150, 160, 113, 179, 158, 191,
      97, 179, 142, 192, 117, 180, 126,  61, 169, 180,  76, 191, 204, 178,  51,  33,
     196, 177,  50, 161, 132, 177,  40,   9 };

const byte Sound_C3_UNE [56] PROGMEM = {
       0,  56,  47,  48, 148, 183,  64,  16, 229, 183,  76,   0, 229, 183,  77,  32,
     229, 183,  77, 160, 228, 183,  86,  64, 229, 184,  78,  64, 228, 184,  77, 191,
     140, 182,  52, 223, 204, 184,  52,  64, 153, 180,  60,  95, 204, 178,  51,  63,
     136, 175,  34,  32, 213, 175,  24,  10 };

const byte Sound_C3_UNE_ [48] PROGMEM = {
       0,  48,  47,  47,   0, 153, 248,   0, 245, 151,  60, 191, 229, 151,  60, 160,
     225, 153,  69,  64, 225, 184,  69, 160, 196, 217,  44, 191, 145, 152,  35,  32,
     161, 183,  43, 192, 168, 215,  44,  33, 216, 182,  53,  36, 164, 182,  72,  26 };

const byte Sound_C3_VETEMENT [124] PROGMEM = {
       0, 124,  47,  47,  85, 178,  56,   0, 233, 178,  59,  32, 173, 178,  59,  32,
     168, 178,  74, 160, 168, 178,  58, 160, 105, 179,  51, 192,  85, 181, 117,  36,
     249, 180, 126,  37, 233, 181, 134, 161, 232, 182, 134, 192, 168, 182, 134, 160,
     180, 215, 116, 160, 224, 214, 112,  80, 144, 215, 120, 112,   0, 216, 245, 176,
      21, 215, 190, 176,   6, 181, 190,  48,   5, 178,   5, 144, 133, 177,  59, 191,
     212, 174,  59,  95, 196, 178,  59, 223, 196, 178,  59, 160,  70, 176, 101, 160,
     169, 173, 124, 189,  74, 172, 149,  32,  25, 170, 117, 192,  41, 170, 125,  64,
      41, 169,  92,  32,  90, 170,  58, 161,  26, 169,  32,  26 };

const byte Sound_C3_VOITURE [144] PROGMEM = {
       0, 144,  47,  47,  64, 180, 120,   0,  68, 213,  75,  17, 128, 213,  83,  32,
     128, 180,  67,  33,  80, 185, 107, 164, 128, 173, 108,  38, 149, 173, 109,  36,
     233, 178, 134, 193, 229, 181, 127,  33, 240, 182, 109, 160, 224, 246, 115, 190,
     224, 150, 106,  33, 208, 149, 104,  16,  70, 215, 136, 112, 164, 251, 141,  48,
      32, 186,   5, 208, 164, 184,  60, 184, 161, 184,  61, 223, 176, 184,  61,  32,
     176, 184,  69,  64, 176, 184,  61,  95, 161, 152,  69,  64, 161, 184,  69, 223,
     241, 184,  77,  95, 225, 183,  77,  64, 241, 183,  84,  32, 225, 151,  84, 190,
     209, 150,  91, 190, 148, 148,  67, 163,  85, 146,  91, 160, 165, 177,  91,  32,
     102, 176,  91,  64, 102, 176,  75,  32, 102, 176,  75,   0,  18, 176,   0,  15 };

const byte Sound_C3_ANE [100] PROGMEM = {
       0, 100,  40,  47, 160, 181, 176,   0, 160, 180, 188,  41, 164, 180, 189, 160,
     164, 180, 190, 160, 164, 180, 191,  32, 164, 180, 191,  64, 100, 212, 183,  93,
      96, 180, 174, 221,  96, 212, 174,  60, 100, 212, 157, 190, 180, 180, 149, 191,
     164, 181, 124, 190, 152, 181,  67, 160, 140, 183,  51, 160, 140, 184,  51, 192,
     140, 183,  52,  64, 140, 183,  51, 192, 140, 185,  51, 192, 140, 185,  51, 128,
     140, 185,  51,  32, 169, 180,  66, 160, 165, 180,  82,  32, 100, 180,  89, 192,
     100, 180,  88,  11 };

const byte Sound_C3_BANQUE [104] PROGMEM = {
       0, 104,  47,  47, 196, 179,  16,   0, 132, 182,  67,  16, 132, 176, 116, 167,
     174, 175, 142, 161,  84, 175, 167,  33,  69, 173, 183,  65,  18, 138, 158, 192,
      83, 138, 142,  32, 102, 171, 149, 189,  85, 170, 157, 221,  85, 171, 149, 222,
      86, 171, 149,  62,  21, 170, 125,  95, 117, 171, 108, 190,  84, 174,  99, 192,
     152, 175,  99,  61, 132, 178,  80,  48,  64, 182,  72,  80,   4, 183,   0, 112,
       4, 184, 150, 176, 200, 185,  84,  32, 228, 181, 131, 160, 148, 179, 123,  46,
      80, 147, 122, 163, 164, 178, 104,  20 };

const byte Sound_C3_BOITE_DE_NUIT [148] PROGMEM = {
       0, 148,  47,  47, 128, 216,   0,   0, 192, 184,  10, 144,   0, 180,   4, 144,
       0, 180,  69,  15, 169, 171,  93,  35, 238, 172, 110,  36, 249, 175, 126, 163,
     233, 178, 143,  64, 164, 180, 134, 165, 132, 213, 110,  34, 129, 175, 124, 185,
      16, 161,  80,  80,   0, 215, 189,  16, 101, 213, 118,  48, 128, 151,  88,  80,
     129, 182,  32, 112,  85, 213,  69,  49, 170, 182,  86, 169, 250, 181, 103,  32,
     250, 182,  95,  95, 250, 182,  94, 190, 196, 181,  69, 191, 136, 181,  61,  63,
     152, 215,  53, 223, 152, 216,  61,  60, 224, 217,  61, 223, 217, 151,  70,  94,
     218, 150,  69, 191, 221, 150,  61,  32, 213, 152,  61,  64, 229, 216,  61, 192,
     212, 216,  61,  62, 209, 185,  68,  64, 210, 217,  59, 223, 134, 153,  72,   8,
     134, 153,  72,  15 };

const byte Sound_C3_BOUCHE [92] PROGMEM = {
       0,  92,  47,  47,  64, 117,  72,   0,  64, 182,  58,  21,  64, 183,  58,  48,
       1, 181,  28, 171,   1, 171,  85,  33,  69, 170,  93, 162,  65, 134, 117, 192,
      66, 138,  85, 127,  65, 147,  76, 222,  17, 144,   5,  62,  69, 184, 254, 208,
      69, 185, 254, 112, 101, 185, 254, 112,  69, 185, 253, 208,  37, 184, 205, 144,
     208, 179, 116,  92, 144, 180, 139, 223,  85, 178, 139, 192,  81, 177, 123,  62,
      85, 178, 114, 191,  85, 179, 128,  14,   1, 178,  88,  15 };

const byte Sound_C3_BRAS [80] PROGMEM = {
       0,  80,  47,  47,  65, 179,  88,   0,  85, 173, 108,  27, 156, 173, 140, 189,
      86, 175, 140,  58,  17, 176, 100,  32,  37, 177, 109,  16,  37, 177, 108, 128,
      53, 176, 117,  16,  36, 176,  92, 128, 101, 177, 116,  41, 165, 175, 140, 164,
     180, 176, 157, 163, 184, 176, 166, 160, 168, 176, 182, 222, 180, 175, 182, 191,
     164, 175, 182,  61, 100, 206, 173, 191, 100, 207, 131, 189,  36, 205,  32,  15 };

const byte Sound_C3_BUREAU_DE_POSTE [180] PROGMEM = {
       0, 180,  47,  47, 128, 215,  24,   0, 148, 180,  42, 144, 101, 183,  70,  43,
     102, 151,  62, 163, 186, 150,  87,  66, 155, 178, 103,  64, 170, 174, 102,  63,
     150, 172, 100, 187, 150, 171, 116,  35, 155, 172, 100, 163, 155, 172, 118,  35,
     171, 176, 111,  64, 171, 179, 103, 189, 153, 178,  61,  49, 214, 178,  51, 177,
     197, 212,  52,  43, 149, 181,  69,  34, 234, 180,  94, 163, 234, 179,  93,  32,
     166, 178,  72,  16, 197, 178,  48,  48, 193, 179,  96,  80, 149, 213,  72, 112,
      68, 180,  68,  48, 148, 175, 108,  31, 249, 175, 134,  57, 253, 176, 142,  94,
     253, 177, 134,  95, 249, 177, 133,  61, 208, 178, 115, 160,  84, 215, 133, 208,
      84, 214, 140, 240,  64, 215, 140,  48,  64, 215, 136, 112,  64, 215, 136, 112,
       0, 215, 189,  16, 101, 213, 118,  48, 250, 180, 107, 136, 217, 178, 123, 160,
     212, 179, 132,  63, 152, 179, 107, 223,  68, 177,  91,  32, 148, 179,  90, 139,
      81, 147,  88,  12 };

const byte Sound_C3_CANARD [108] PROGMEM = {
       0, 108,  47,  47, 192, 213,  80,   0,  20, 185,   4,  16, 104, 185, 150, 176,
     212, 217, 100, 143, 228, 184, 117, 166, 224, 183, 143,  62, 228, 182, 151, 160,
     180, 182, 143,  32, 168, 182, 126, 160, 168, 182,  85,  62,  72, 183,  68, 223,
     136, 180,  60,  92, 228, 181, 125, 188, 164, 181, 141, 188, 164, 180, 174,  32,
     165, 180, 190, 192, 229, 179, 198,  64, 164, 179, 190,  64, 164, 178, 182,  95,
     164, 178, 173,  95, 168, 178, 164, 223,  68, 175, 147,  32,  24, 177,  99, 160,
      84, 175,  98, 191, 121, 177,  90, 168,  37, 177,   0,  15 };

const byte Sound_C3_CENTRE_COMMERCIAL [244] PROGMEM = {
       0, 244,  47,  47,  70, 178,  56,   0,  74, 215, 125,  48,  74, 214, 133, 208,
      26, 212,   5, 240,  26, 214, 230,  80,   4, 215, 101, 143, 160, 177, 134, 172,
     165, 176, 143,  62,  81, 175, 151, 191,  82, 173, 151,  32, 166, 172, 142, 160,
      97, 172, 126, 192, 165, 173, 118,  62, 148, 174, 101, 191, 148, 204,  67, 177,
     132, 203, 112,  80, 149, 214, 109, 144,   1, 213, 142,  48,  22, 206, 118,  48,
     150, 209, 116,  48, 138, 177, 109,  33, 154, 177, 101, 190, 218, 176,  84,  58,
     128, 181,  88, 112,  32, 175, 230,  48,  32, 112, 229, 174, 230, 144, 118,  47,
     235, 144, 127,  67, 221, 177,  77, 192, 221, 145,  69,  61, 218, 145,  77, 160,
     180, 183, 119,  94, 180, 183, 134, 187, 224, 181, 102,  60, 100, 181,  85, 179,
      20, 179,   5, 188, 105, 180, 126,  16,  64, 185, 254,  80,   5, 214,  13, 208,
      37, 215, 109,  80,   5, 183,   5, 208,  25, 218, 118,  80, 217, 216,  77,  38,
     245, 215,  94,  63, 245, 183, 111,  63, 244, 182, 135, 191, 168, 181, 159,  61,
     228, 179, 174, 223, 233, 179, 175,  63, 168, 180, 158, 192, 232, 180, 133, 223,
     232, 180, 125,  32, 252, 180, 125, 191, 252, 180, 117,  64, 252, 180, 108, 223,
     248, 180, 108,  64, 232, 180, 123, 161, 216, 179, 154, 192, 148, 179, 153, 140,
     104, 179, 152,  15 };

const byte Sound_C3_CHAT [68] PROGMEM = {
       0,  68,  47,  47,   4, 150,   0,   0,  69, 183, 255,  48,   5, 184, 255,  80,
      21, 185, 254, 240,  21, 187, 254, 240,  69, 184, 254,  48, 137, 181, 109, 143,
     145, 179, 126,  38, 229, 179, 142, 190, 229, 178, 159,  62, 170, 177, 175, 189,
     234, 177, 175, 190, 169, 176, 175,  61, 160, 176, 174,  61,  80, 175, 156, 160,
      84, 173, 152,   3 };

const byte Sound_C3_CHEVAL [132] PROGMEM = {
       0, 132,  47,  47,   4, 182,  48,   0,  17, 217,   6, 112,  65, 218, 253, 176,
      21, 218,   5, 240,   5, 185, 173, 145,  84, 212, 110,  47,  86, 179, 118, 193,
      91, 179, 101, 191,  87, 146,  76, 188, 151, 178,  92,  61, 166, 178,  83, 190,
      21, 179,  85, 161, 165, 179, 142,  32, 185, 179, 158, 190, 185, 179, 167,  62,
     185, 179, 183,  63, 185, 179, 183,  95, 185, 179, 182, 191, 249, 180, 174,  64,
     169, 180, 166,  95, 189, 180, 133, 192, 253, 180, 125,  64, 189, 180, 117,  64,
     237, 180, 100, 223, 248, 180,  92,  32, 252, 180,  91, 160, 185, 180,  91, 192,
      84, 178,  91,  61, 105, 179,  90, 161,  89, 179,  82,  32, 100, 180,  90,  14,
      36, 180,  72,  13 };

const byte Sound_C3_CHEVEUX [112] PROGMEM = {
       0, 112,  47,  47,  22, 216,   0,   0,   6, 215, 255,  16,  22, 216,   6, 176,
     134, 218, 255,  80,  70, 218, 254, 176,  70, 219, 254, 240,   6, 219, 254,  48,
      20, 217,  29, 145, 149, 181, 102, 175, 166, 179, 102, 193, 102, 179, 102,  63,
     170, 178,  93,  62, 234, 178,  76,  62, 164, 178,  67,  32, 193, 178,  66,  32,
     197, 180,  82, 160,  84, 182,  60,  32,  85, 180,  84, 184, 169, 179,  93, 160,
     185, 179, 101, 190, 233, 179, 109, 190, 249, 179, 109,  63, 228, 178,  99, 191,
     196, 178,  99,  63, 228, 179,  83,  64, 229, 178,  90, 167, 229, 178,  88,   7 };

const byte Sound_C3_CHIEN [76] PROGMEM = {
       0,  76,  47,  47,  20, 217,  32,   0,  21, 218,  78, 176,   9, 185, 254, 208,
      73, 185, 254, 240,  25, 216, 254, 112,   4, 217, 253,  80,  73, 215,  84,  15,
     197, 181,  93, 167, 210, 183,  94, 189, 214, 183, 118, 188, 149, 182, 126, 223,
     145, 180, 150, 222, 145, 179, 133, 190, 144, 178, 117,  62,  65, 170, 116,  60,
     144, 178,  83, 160,  80, 178,  67,  32,  80, 178,   8,  13 };

const byte Sound_C3_DENTISTE [144] PROGMEM = {
       0, 144,  47,  47, 132, 177,  40,   0, 132, 217,  51, 149,  80, 212,  92, 176,
     234, 177, 126, 175, 166, 175, 142, 161, 146, 174, 159,  32, 146, 173, 142, 162,
     162, 204, 134,  64, 162, 173, 117,  33, 160, 205,  92, 160, 145, 171, 114, 185,
     209, 202, 120,  16, 128, 215, 120, 112,   8, 214, 189,  48,  72, 217, 141,  48,
     153, 217,  69, 208, 212, 217,  69, 148, 244, 216,  62,  64, 244, 216,  61, 189,
     245, 217,  53, 192, 245, 217,  53,  33, 228, 184,  52, 160, 221, 184,  43, 161,
     149, 183,  67,  64,  94, 215,  69,  80,  14, 217, 253,  80,  94, 215,  12, 208,
      84, 215,   8,  80,  84, 215,   8, 112,   0, 214, 140, 144,   8, 183, 148, 176,
      85, 213,  60, 176, 197, 177,  91,  41, 217, 179,  67,  63, 133, 179,  40,  17 };

const byte Sound_C3_DOIGT [76] PROGMEM = {
       0,  76,  47,  47,  68, 215,  56,   0,   4, 215, 212, 145,  37, 214,  61,  63,
      80, 214,  68, 143, 149, 175,  84, 162, 149, 172,  92, 193, 153, 170, 100, 193,
     217, 172, 117, 160, 149, 173, 134, 160, 148, 176, 159,  63, 168, 175, 159,  62,
     168, 175, 166, 189, 184, 175, 166,  61, 184, 175, 157,  32, 164, 175, 124,  57,
      80, 175, 131,  63, 160, 175, 122, 139, 144, 206, 128,  13 };

const byte Sound_C3_GRENOUILLE [132] PROGMEM = {
       0, 132,  47,  47, 148, 145,  64,   0,   5,  79,   4,  56,  33, 178,  76,  48,
      81, 179, 108,   9,   2, 143,   4, 189,   2, 170, 132, 161, 103, 171, 108, 164,
       7, 167, 141,  39, 214, 175, 126,  40, 165, 178, 118, 193, 149, 180,  95,  62,
     136, 180,  61, 191, 140, 179,  53,  94, 153, 179,  86,  95, 136, 177,  93,  94,
     136, 171, 109,  95, 141, 170,  92, 223,  69, 175,  84, 222, 133, 152,  77,  63,
     161, 184,  69,  63, 230, 216,  61,  95, 217, 216,  36,  63, 212, 216,  43, 192,
     213, 216,  43, 192, 164, 216,  68,  64, 144, 216,  92, 192,  85, 181,  68,  61,
     152, 179,  83, 161,  68, 178,  67,  32,  80, 179,  66, 160,  80, 178,  65, 140,
      64, 178,  40,  13 };

const byte Sound_C3_HOPITAL [160] PROGMEM = {
       0, 160,  46,  47, 150, 180,  80,   0, 214, 178, 101,  47, 214, 177, 102,  42,
     214, 177, 102, 160, 214, 177, 103,  32, 218, 175, 102, 162, 170, 174,  85, 160,
     209, 174,  59, 189, 230, 173,  56,  16, 196, 175,  72, 112,   4, 180, 238, 176,
      25, 184,   6,   7, 233, 216,  53, 190, 246, 216,  53, 189, 229, 216,  53,  61,
     213, 215,  43, 177, 193, 184,  40,  16, 193, 182,  48,  80, 128, 247,  48, 112,
       0, 182,  76,  16,  85, 183, 181, 176,  84, 182, 124, 143, 228, 181, 109, 184,
     228, 181, 134, 187, 233, 181, 150, 188, 169, 180, 167,  32, 233, 180, 167,  61,
     245, 180, 166,  64, 165, 180, 166, 192, 165, 180, 150,  64, 168, 180, 125,  63,
     224, 180, 116, 160, 232, 180,  92, 192, 232, 180,  84,  64, 232, 180,  84, 192,
     233, 180,  92,  63, 169, 180, 115, 191, 160, 180, 114, 163, 160, 180, 112,  15 };

const byte Sound_C3_JAMBE [116] PROGMEM = {
       0, 116,  47,  47,  84, 213, 112,   0, 133, 216, 115, 186,  85, 218, 109,  32,
      84, 218,  94, 144,  20, 218,   5, 132,  20, 218,  54, 144,  89, 218,  86, 134,
      64, 219, 119,  37,  80, 179, 135,  34,  84, 178, 143,  32,  96, 176, 151,  32,
     102, 173, 151,  64, 102, 172, 143,  32,  86, 171, 142, 223,  85, 170, 150, 222,
      89, 170, 141, 222,  85, 169, 133, 222,  84, 169, 124,  95,   4, 166, 124,  32,
      72, 176,  44,  95,  92, 175,  43, 160, 172, 175,  40,  16, 212, 177,  24, 112,
      64, 181,  77,  48, 148, 177,  84,  16, 244, 177, 107, 160, 232, 177, 114,  37,
     164, 178, 104,  14 };

const byte Sound_C3_MAIN [68] PROGMEM = {
       0,  68,  47,  47, 156, 179,  48,   0, 220, 179,  50, 152, 204, 180,  52,  33,
      92, 180,  45,  32, 156, 179,  53,  33, 156, 179,  61, 161, 169, 177, 110,  37,
     182, 178, 159,  33, 181, 179, 167, 160, 181, 179, 167,  64,  96, 178, 159,  63,
      96, 178, 166, 189, 100, 178, 149, 190,  80, 210, 140, 188, 128,  84, 115,  62,
      80, 177, 112,  14 };

const byte Sound_C3_MEDECIN [112] PROGMEM = {
       0, 112,  47,  47,  69, 180,  72,   0, 137, 149,  59, 222, 137, 148,  52, 193,
     136, 147,  53,  35, 230, 183, 102, 165, 230, 183, 119,  33, 230, 183, 103,  32,
     235, 183,  86, 160, 150, 182,  68, 185, 192, 183,  51, 165,  85, 215, 112, 112,
      87, 214, 116, 208,   3, 213,  12, 208,  23, 215, 149,  80, 155, 181, 149, 176,
       7, 178, 181, 208,  69, 180,  84,  28, 148, 178, 109, 191, 149, 178, 126,  95,
     146, 178, 142,  95, 146, 178, 142,  64, 146, 178, 142,  64, 146, 178, 141, 160,
     129,  80, 108,  32, 129, 110, 107, 191, 130, 143,  83,  32, 130, 143,  80,   6 };

const byte Sound_C3_NEZ [68] PROGMEM = {
       0,  68,  47,  47, 156, 181,  32,   0, 140, 181,  44, 189, 220, 181,  37, 161,
     140, 181,  46,  33, 140, 182,  46,  65, 140, 182,  54,  34, 140, 183,  46, 162,
     233, 183, 103,  32, 233, 184, 103,  33, 233, 184, 103,  64, 229, 184, 111,  61,
     229, 184, 102, 189, 208, 185,  86, 189, 224, 185, 101,  61, 160, 218,  76, 191,
      72, 183,  32,  14 };

const byte Sound_C3_OPTICIEN [164] PROGMEM = {
       0, 164,  47,  47, 229, 181, 120,   0, 229, 180, 133, 143, 245, 179, 142, 164,
     245, 179, 143,  32, 245, 179, 143, 160, 250, 177, 127,  32, 168, 177,  77,  60,
     208, 178, 123, 163, 209, 177, 120,  16, 213, 176,  96,  48, 192, 182, 120,  80,
       0, 185, 150,  16,  17, 185,  71,  48,  65, 216, 133, 144, 192, 184, 128,  48,
     128, 214, 120,  80,   4, 215, 190,  48,  10, 215,   5,  48, 154, 216,  53,  28,
     233, 216,  61, 167, 233, 217,  53, 192, 200, 217,  53,  60, 141, 185,  44, 177,
     139, 215,  69,  48,  27, 215,  93,  80,  11, 216,   5,  48,  11, 213,   5,  80,
      27, 215,   5, 208,  91, 217,  70, 112, 213, 217,  61,   4, 196, 219,  60, 160,
     192, 186,  77,  32, 192, 218,  94,  63, 192, 185, 118,  62, 144, 183, 118,  61,
      85, 181, 142,  64,  80, 179, 133,  63,  80, 146,  92, 160,  85, 177,  84, 162,
      85, 178,  88,  13 };

const byte Sound_C3_OREILLE [164] PROGMEM = {
       0, 164,  47,  47, 230, 179, 112,   0, 229, 178, 123,  15, 234, 177, 124,  35,
     234, 177, 125,  32, 234, 177, 126,  32, 234, 177, 126, 160, 145, 175, 134, 192,
     229, 173, 117, 160, 229, 173, 116, 189, 150, 174, 116,  32,  85, 176, 124, 176,
       5, 208, 101,  48,   5, 178,  45,  32, 164, 179, 117,  62, 149, 180, 142, 190,
     229, 180, 159,  61, 233, 181, 159, 222, 185, 182, 151,  95, 185, 182, 135,  95,
     181, 182, 134, 157, 244, 183, 125, 191, 240, 183, 117, 160, 228, 183, 109,  32,
     240, 183,  92, 160, 224, 215,  84, 160, 244, 216,  68,  63, 228, 216,  59, 191,
     229, 215,  59,  95, 249, 215,  51, 192, 233, 216,  68,  64, 245, 183, 101,  65,
     233, 182, 125,  62, 164, 182, 124, 160,  81, 181, 116,  62, 148, 180, 147, 161,
     164, 180, 114, 160,  85, 179,  90,  32,  84, 179,  57, 160,  81, 178,  96,  15,
      80, 179,  72,  15 };

const byte Sound_C3_PAPETERIE [148] PROGMEM = {
       0, 148,  47,  47, 192, 181,  72,   0, 225, 214, 116,  16, 192, 148, 125,  47,
     212, 179, 150,  41, 212, 179, 150, 192, 212, 180, 142,  32, 192, 173, 131, 191,
     192, 147, 146, 161, 192, 180, 136,  16, 128, 212, 120,  48, 132, 183, 120,  80,
     228, 181, 109,   4, 248, 182, 126, 190, 185, 183, 127, 187, 249, 183, 127, 188,
     248, 183, 102, 191, 232, 183,  93,  61, 192, 183,  75, 177, 224, 183, 104,  48,
      16, 215, 136, 112,  17, 214, 125, 144,  33, 212, 125, 208, 224, 180, 238,  80,
      32, 213, 141, 176,  33, 213, 125,  48,  97, 214,  76, 176, 182, 182,  84,   4,
     230, 183,  84,  32, 233, 184,  93, 160, 185, 184,  78,  61, 249, 216,  77, 190,
     233, 216,  68, 160, 229, 216,  51, 192, 229, 216,  51,  32, 200, 217,  66, 192,
     200, 217,  56,  14 };

const byte Sound_C3_PHARMACIE [152] PROGMEM = {
       0, 152,  47,  47,  69, 181,  64,   0,   5, 182,   4,  16,  21, 181,   4,  48,
       5, 181,   5,  80,  85, 184,  69,  80,   5, 183, 237,  80,  85, 182, 157, 176,
     144, 145, 125,  47, 217, 177, 150,  34, 153, 177, 167,  63, 169, 177, 175,  62,
     164, 176, 158, 190,  22, 174, 101, 176,  81, 207,  85,  37,   2, 166,  68,  32,
     136, 169,  60,  63, 216, 174,  52,  35, 216, 176,  53,  62, 152, 177,  54,  60,
     169, 177,  54,  62, 161, 180, 151,  60, 168, 181, 151,  64, 164, 181, 134,  62,
     148, 182,  93,  62, 137, 214, 109,  16,  89, 215,  93, 112,  89, 216,  77, 112,
      73, 216,  69, 112, 220, 216,  52,  28, 216, 216,  45,  60, 228, 216,  45, 189,
     244, 249,  45,  64, 248, 249,  44, 191, 242, 217,  36,  32, 216, 249,  27, 193,
     194, 218,  43, 194, 130, 186,  40,   2 };

const byte Sound_C3_PIED [64] PROGMEM = {
       0,  64,  47,  47, 129, 181,  88,   0,  36, 182,  36,  16,  72, 183, 254,  48,
       9, 216, 254,  48,   8, 216, 173,  48, 196, 217,  60,  41, 228, 216,  69, 191,
     245, 216,  78, 191, 229, 216,  86, 190, 229, 184, 102, 222, 229, 184,  94,  63,
     229, 184,  85, 191, 201, 153,  84,  59, 228, 217,  74, 191, 208, 217,  80,  14 };

const byte Sound_C3_POULE [96] PROGMEM = {
       0,  96,  42,  47,  64, 217, 112,   0,   0, 216, 125,  48,   0, 214, 252,  48,
      64, 181, 108,  47, 135, 168, 100, 192, 151, 168,  92, 192, 151, 137,  84, 223,
      75, 136, 101,  61, 155, 143,  85,  92, 229, 116,  77,  94, 164, 182,  85, 221,
     228, 181,  92,  95, 248, 181,  83, 223, 216, 181,  83, 192, 197, 181, 108, 191,
     170, 179, 124, 192,  89, 179, 116, 191,  36, 179,  28,  63, 116, 178,  91, 161,
     169, 178,  82,  62, 132, 178,  57,  36,  69, 179,  17,  32,  85, 179,   0,  15 };

const byte Sound_C3_SALON_DE_COIFFURE [204] PROGMEM = {
       0, 204,  37,  47,  74, 211, 112,   0,  26, 214, 125, 208,  90, 215, 117,  48,
      26, 215, 141, 112,  90, 214, 117, 176, 164, 213, 101,  15, 164, 181, 134, 168,
     228, 181, 135,  64, 164, 181, 118, 191, 168, 181,  85, 162, 164, 179,  93, 194,
     149, 174, 118,  65, 137, 169, 126,  65, 134, 173, 126,  64, 134, 175, 118, 160,
     157, 175,  69,  57, 157, 174,  51, 185,  84, 213,  68, 189, 154, 180, 102,  32,
     234, 179, 110, 189, 231, 177, 101,  63, 129, 147,  88,  80, 132, 175, 136, 112,
       0, 174,   4,  48, 170, 174, 126,  43, 233, 144, 142, 190, 170, 146, 143,  61,
     228, 147, 142, 189, 132, 147, 117,  32, 152, 182, 133, 176, 154, 183, 142, 176,
      37, 182, 142, 240,  41, 182, 142,  80,  37, 183,  77, 176,  52, 183,  53,  48,
     181, 183,  60,  17, 241, 183,  60,  61, 224, 184,  68,  94, 224, 247,  59, 223,
     240, 183,  68,  96, 225, 151,  76,  95, 197, 119,  91, 160, 196, 149,  99, 160,
     237, 178, 123, 223, 169, 177, 107,  32, 117, 176, 107, 189,  85, 177, 108, 144,
      21, 175,   4, 208,  21, 174,   4,  48,  21, 174,   0,  15 };

const byte Sound_C3_STATION_SERVICE [216] PROGMEM = {
       0, 216,  47,  47,  64, 216, 104,   0,  74, 216, 109, 176,  74, 216, 109, 176,
      64, 186, 253, 128,  16, 182,  61, 128, 232, 181, 126, 175, 232, 181, 143, 192,
     232, 181, 134, 160, 212, 181, 117, 191, 148, 182,  85,  63, 196, 214, 124,  64,
     197, 214, 133,  16, 133, 217, 141, 176,  10, 218, 109, 176,  90, 218, 150, 176,
       5, 185,   6, 176, 149, 183,  93, 131, 150, 150, 110, 172,  85, 175, 110, 220,
      69, 173, 126,  62, 165, 173, 101,  62, 225, 172,  92,  63,  65, 180,  52, 188,
       2, 212,   4, 144,   4, 215, 101, 208,   1, 183,  53, 112,  29, 182,   5, 176,
     109, 182,  84, 141, 248, 182, 102,  63, 245, 182, 119,  60, 249, 182, 127,  94,
     181, 182, 118, 190, 161, 181, 101,  62, 161, 181, 124,  32, 145, 179, 100, 193,
     153, 179, 109, 190, 149, 147, 100,  61, 197, 145,  83,  60, 144, 152,  75,  62,
     208, 216,  67, 160, 224, 216,  60,  63, 192, 215,  59, 223, 208, 248,  51, 191,
     217, 216,  59, 223, 214, 184,  51, 223,  74, 217,  92, 208,  10, 214,  76,  48,
      26, 215,   4, 112,  26, 214, 124,  80,  26, 213,   4, 240, 138, 214, 108,  48,
     148, 180,  98,  13, 105, 180,  48,  15 };

const byte Sound_C3_TABAC [76] PROGMEM = {
       0,  76,  47,  47,  64, 183, 104,   0,  20, 215, 206,  48, 232, 182, 134, 175,
     248, 181, 159, 161, 228, 180, 175, 223, 233, 179, 159,  62, 164, 177, 117,  49,
      81, 148, 139, 175,  64, 116, 120, 112, 248, 177, 133,  49, 253, 178, 166, 189,
     249, 178, 174,  63, 232, 177, 174,  63, 164, 177, 181, 192, 148, 176, 172, 188,
     144, 207, 163, 160, 180, 208, 155, 137, 184, 176, 136,  15 };

const byte Sound_C3_TETE [92] PROGMEM = {
       0,  92,  47,  47, 128, 214,  96,   0,  20, 215, 214,  48, 228, 182, 109, 175,
     244, 182, 119,  37, 248, 182, 135, 189, 245, 182, 127, 188, 249, 182, 119, 189,
     244, 183, 119,  62, 232, 183,  94,  62, 228, 183,  93,  62, 212, 183, 104,  48,
     208, 215,  96,  80, 128, 215,  96, 112, 128, 215,  88, 112,  21, 183, 190,  48,
     153, 182, 149, 176, 153, 181,  92,  16, 213, 180,  75, 144, 208, 180,  83, 184,
     192, 145,  91,  63, 208, 180, 107, 190, 229, 179,  80,  14 };

const byte Sound_C3_VACHE [68] PROGMEM = {
       0,  68,  47,  47,   0, 213, 248,   0,  85, 180,  84,  14, 169, 179, 158,  33,
     233, 179, 167,  33, 233, 179, 183,  64, 169, 180, 175,  95, 185, 180, 166, 188,
     164, 180, 141, 190, 169, 180, 124, 189, 116, 219, 157, 176,  20, 218, 181, 208,
      20, 218, 253, 240,  68, 218, 253,  48,  37, 186, 253, 112,  21, 186, 252, 176,
       5, 177, 152,   4 };

const byte Sound_C3_VITRINE [140] PROGMEM = {
       0, 140,  47,  47, 148, 215,  24,   0, 148, 183,  36,  15, 165, 184,  69,  35,
     234, 185,  62,  36, 233, 217,  62,  39, 228, 249,  61,  34, 196, 218,  59, 185,
     145, 217,  48,  16, 192, 216,  64,  48,  20, 183,   0, 112,  37, 214, 158, 176,
      16, 182, 238, 176,  32, 214, 191,  48,  33, 215, 118,  80, 212, 184,  85, 182,
     233, 185,  95,  61, 229, 217,  95,  94, 245, 217,  86, 190, 229, 217,  78, 189,
     245, 217,  70,  63, 224, 249,  77,  32, 196, 182,  68, 160, 200, 175,  59, 223,
     204, 180,  59, 223, 136, 180,  67,  32, 200, 175,  59,  64, 200, 175,  59,  64,
     232, 181,  76,  32, 169, 181, 116,  64, 165, 180, 123, 189, 165, 179, 123,  32,
     145, 147,  98,  64, 166, 179,  97, 140,  97, 178,  64,  15 };

const byte Sound_C3_ARMOIRE [140] PROGMEM = {
       0, 140,  46,  47, 180, 181, 168,   0, 165, 180, 172, 167, 165, 180, 174,  32,
     165, 180, 175,   0, 170, 179, 191,  33, 169, 178, 166, 163,  80, 178, 149, 163,
     101, 176, 109,  63,  42, 177,  68, 190,  18, 176,  48,  80,  98, 175,  67,   8,
     134, 167,  98, 191, 129, 184,  58,  32, 200, 175,  50, 223, 136, 178,  43,  59,
     136, 182,  52,  62,  72, 184,  52,  63, 130, 186, 124, 190, 136, 179, 132, 160,
     150, 171, 140, 223, 181, 174, 157, 223, 184, 175, 173, 192, 184, 176, 174,  95,
     185, 176, 181, 192, 184, 176, 173,  64, 168, 176, 165,  95, 168, 176, 156, 223,
     232, 176, 148,  64, 244, 175, 131,  32, 232, 175, 124,  48, 149, 174, 100,  48,
     117, 175,  92,  48,  41, 176,   4,  16,  33, 177,   0,  15 };

const byte Sound_C3_BAIGNOIRE [144] PROGMEM = {
       0, 144,  47,  47,  64, 182,  56,   0,  97, 182,  92, 143, 241, 182, 110, 162,
     232, 184, 103,  65, 228, 217,  94, 162, 248, 217,  77, 191, 164, 217,  68,  34,
     205, 145,  60,  64, 200, 146,  60,  95, 210, 217,  61,  63, 129, 186,  77, 189,
     213, 182,  85, 189, 153, 179, 101, 189, 137, 176, 117, 189, 137, 172, 133,  95,
      86, 173, 158,  95, 169, 176, 166,  64, 186, 177, 182, 223, 169, 177, 182,  96,
     250, 178, 190,  94, 250, 177, 181, 160, 186, 177, 173,  32, 100, 177, 156, 192,
     100, 176, 132,  32, 185, 176, 131, 192, 121, 176,  91,  32,  37, 176,  59,  32,
      57, 176,   3,  59,  49, 176,   3, 144,  37, 176,   3, 176,  41, 176,   3, 176,
     105, 176,  99,  68,  84, 175,  91,  95,  84, 177,  58, 193,  32, 177,   0,  15 };

const byte Sound_C3_BALAIS [84] PROGMEM = {
       0,  84,  47,  47, 144, 150,  40,   0, 148, 180,  91, 145, 249, 180, 142, 175,
     228, 181, 167,  65, 228, 182, 150, 193, 228, 214, 134,  33, 232, 214, 117,  63,
     236, 214,  92, 190, 248, 183,  84, 221, 164, 183,  85,  94, 233, 183, 102,  61,
     233, 184, 118,  62, 233, 184, 117, 157, 229, 184, 109, 191, 245, 185, 101,  95,
     229, 185, 100, 158, 224, 185,  91, 160, 208, 185,  83,  65, 208, 217,  82,  34,
     228, 217,  88,  14 };

const byte Sound_C3_BIBERON [108] PROGMEM = {
       0, 108,  47,  47,  64, 116,  32,   0,  21, 180,   4, 144,   4, 149,   5,  15,
     165, 185,  62,  34, 245, 217,  54,  65, 242, 185,  61, 193, 133, 146,  51, 191,
     133, 142,  50, 191, 208, 185,  32,  48, 192, 181,  24,  80,   0, 117, 213,  55,
      85, 176, 117,  32, 185, 173, 125,  62, 165, 171, 125,  64, 177, 202, 115, 187,
      22, 167, 131,  60,  87, 168, 123,  63, 170, 167, 123,  64, 153, 168, 140,  34,
     142, 166, 156, 160, 137, 165, 148, 223, 136, 167, 139, 192, 132, 169, 123, 223,
     132, 170, 123, 192, 132, 171, 114, 164, 129, 140, 112,  15 };

const byte Sound_C3_BOUCHON [68] PROGMEM = {
       0,  68,   0,  47, 129, 215,  50, 186, 129, 145, 108,  34, 130, 173, 100, 192,
     130, 142,  92,  64,  66, 146,  75, 190, 192, 180, 252, 176, 132, 184, 254,  80,
      96, 186, 254, 112,  16, 217, 254, 112, 144, 176, 116, 221,  90, 170, 140,  95,
      74, 167, 140,  62,  25, 163,  92,  32,  72, 167,  99, 160,  44, 160,   3,  32,
      40, 160,  72,   6 };

const byte Sound_C3_BOUTEILLE [124] PROGMEM = {
       0, 124,  46,  47,  64, 182,  56,   0, 241, 182, 109,  40,   1, 177,   4, 183,
      65, 172, 100, 169,  69, 171,  84, 195, 132, 175,  68, 193,  68, 172,  52,  60,
     196, 171,  66, 177, 225, 218,  72,  48,   0, 184, 248, 112,  84, 215, 173, 176,
     234, 182, 118,  45, 249, 182, 134, 190, 248, 182, 143,  93, 248, 182, 150, 187,
     249, 182, 151,  95, 232, 183, 142, 223, 232, 183, 134,  95, 249, 184, 125, 192,
     244, 216, 101,  64, 244, 216,  68, 192, 232, 217,  68,  62, 227, 185,  67,  32,
     232, 249,  59, 223, 228, 216,  51,  64, 228, 216,  51, 161, 228, 183,  75, 192,
     212, 181,  83,  64, 153, 180,  90, 164, 168, 180,  80,  15 };

const byte Sound_C3_CARAFE [132] PROGMEM = {
       0, 132,  47,  47, 129, 151,  88,   0,  16, 186, 198,  48,  64, 186, 157,  15,
     224, 184, 118,  45, 228, 183, 151,  61, 160, 181, 183,  94, 144, 179, 174, 190,
      64, 174, 181, 191,  84, 177, 133,  63,  68, 179, 125,  16, 148, 179, 131, 176,
      84, 177, 107,  48,  80, 177, 115, 176,  84, 177, 140, 145, 169, 176, 174,  63,
     185, 176, 190, 221, 184, 176, 198,  62, 169, 177, 190,  95, 184, 177, 173, 191,
     164, 177, 164, 191, 168, 176, 123, 189,  88, 176, 123,  32,   4, 215, 163,  16,
      84, 214, 164, 176,   5, 211, 244, 240,   0, 184, 237, 112,   0, 214, 252, 208,
     153, 179,  99,  48, 152, 178,  90, 133, 212, 174, 122,  64,  84, 177,  89, 194,
     101, 177,  72,  15 };

const byte Sound_C3_CASSEROLE [112] PROGMEM = {
       0, 112,  47,  47,   0, 182,  88,   0,   4, 185, 254,  48, 228, 184, 109,  47,
     232, 183, 135,  36, 232, 182, 151,  30, 244, 181, 159,  63, 160, 181, 150, 189,
     148, 182, 124, 191, 148, 213, 141,  80,   0, 247, 141, 112,  37, 177, 140, 240,
     150, 173, 108, 112, 170, 173, 140, 177, 170, 172, 149,  94, 250, 173, 149,  64,
     254, 174, 149,  95, 254, 177, 141,  95, 249, 179, 133,  95, 184, 180, 117,  63,
     168, 180, 109,  32, 252, 180,  92,  63, 252, 180,  91,  32, 236, 180,  91,  64,
     236, 179,  91,  64, 236, 179,  90, 160, 236, 179,  89, 167, 236, 179, 104,  14 };

const byte Sound_C3_CHAISE [116] PROGMEM = {
       0, 116,  47,  47, 176, 182, 128,   0, 106, 182, 101, 144,   4, 217,   6, 112,
       2, 218, 253, 208, 138, 182, 253, 240, 228, 181, 117, 173, 244, 182, 134, 191,
     249, 182, 142, 191, 249, 183, 143,  96, 181, 183, 135,  59, 245, 183, 142, 190,
     249, 183, 134, 222, 250, 183, 126, 222, 250, 183, 118,  62, 245, 183, 109, 191,
     245, 183, 101,  32, 244, 182, 100, 191, 244, 182, 100,  63, 245, 182,  83, 191,
     224, 181,  99,  63, 234, 182,  67,  64, 150, 182,  82, 192, 170, 182,  58,  64,
     154, 181,  66, 192, 224, 180,  90, 192, 209,  84, 122, 192, 145, 179, 114, 194,
     144, 179, 120,  14 };

const byte Sound_C3_CHAMBRE [104] PROGMEM = {
       0, 104,  35,  47,  90, 215, 136,   0,  90, 218, 158, 144,  10, 214, 255,  48,
      26, 218, 199,  80,  26, 219, 190, 176,  26, 219, 254, 208, 106, 219, 254, 208,
     160, 176, 133, 199, 162, 174, 142,  95,  97, 170, 150, 127,  97, 170, 150,  93,
      81, 169, 125,  94,  33, 168,  77,  95,  21, 165, 173,  94,  68, 166, 100,  93,
     140, 177,  35,  65, 131, 153,  58, 160,   0, 147,   0,  80, 102, 176, 104, 112,
     102, 175, 116, 176,  22, 174, 107, 176, 104, 174, 148, 208, 169, 174, 140,   2,
     165, 174, 115, 191,  33, 142,  19,  32 };

const byte Sound_C3_CLEF [76] PROGMEM = {
       0,  76,  47,  47,   4, 116, 200,   0,  68, 183, 254,  16,   4, 215, 207,  48,
      17, 217, 125, 176,  85, 216,  45,  15, 216, 248,  84, 165, 224, 215,  93,  32,
     240, 246,  85,  63, 245, 182,  77,  64, 244, 183, 102, 162, 228, 183, 111,  32,
     245, 184, 103,  95, 229, 184, 102, 222, 229, 185,  94,  61, 224, 185,  93,  60,
     200, 149,  99, 190, 224, 186,  90, 189, 224, 185,  80,   9 };

const byte Sound_C3_COMPTEUR [128] PROGMEM = {
       0, 128,  47,  47, 128, 212,  88,   0,  81, 176, 198,  48, 148, 139, 116, 202,
      73, 169, 141, 160, 136, 169, 141, 162, 130, 140, 133, 161, 132, 173, 125,  63,
     133, 170, 117,  62, 149, 169, 116,  62, 128, 173,  91, 189,  68, 174, 120,  16,
     128, 145,  96,  48, 128, 152, 112,  80,  16, 196, 152, 112,  16, 181, 198,  16,
      21, 214, 150,  48, 169, 180, 117, 183, 249, 180, 126,  59, 249, 180, 142,  93,
     249, 179, 150,  32, 229, 179, 142,  95, 249, 179, 142,  95, 250, 180, 141, 192,
     233, 180, 141,  64, 232, 180, 133,  95, 232, 180, 124,  95, 168, 180,  99, 160,
     149, 179,  83,  32, 152, 146, 115,  64, 185, 177, 130, 141,  32, 178, 136,  13 };

const byte Sound_C3_CUISINE [116] PROGMEM = {
       0, 116,  47,  47, 148, 182, 104,   0,  32, 185, 254, 176,  32, 184, 125, 176,
      48, 183,   6,  48, 180, 182,  53, 163, 245, 151,  53, 191, 218, 152,  62,  32,
     234, 152,  54, 161, 246, 185,  55,  32, 246, 217,  55,  33, 229, 217,  63,  34,
     228, 217,  62, 161, 228, 184,  53, 192, 228, 184,  61, 192, 213, 216,  69, 223,
     192, 249,  69, 192, 216, 216,  61, 223, 216, 216,  62,  95, 245, 217,  70, 222,
     241, 217,  62,  95, 212, 249,  70, 192, 192, 184,  62,  95, 132, 119,  68, 192,
     162, 151,  61,  64, 172, 182,  60, 223, 216, 181,  68,  32, 228, 182,  90, 164,
     228, 182,  88,  10 };

const byte Sound_C3_CUISINIERE [148] PROGMEM = {
       0, 148,  47,  47, 128, 184, 104,   0,  68, 150, 253, 144,  32, 185, 117,  48,
      32, 216, 220, 176, 128, 183, 253,  48,  48, 182,   5,  47, 254, 151,  61,  68,
     230, 152,  61, 161, 233, 184,  69, 160, 237, 216,  61, 191, 201, 183,  60,  93,
     220, 184,  67, 188, 204, 185,  52,  64, 136, 215,  52,  32, 213, 216,  69, 192,
     197, 216,  70,  32, 192, 249,  70,  63, 197, 149,  53,  61, 141, 146,  52, 190,
     205, 146,  52,  94, 137, 143,  52,  62, 161, 249,  69,  62, 132, 250,  77, 222,
     216, 217,  85, 190, 228, 184, 102,  64, 169, 184, 135,  64, 185, 183, 142, 223,
     169, 183, 142, 192, 169, 183, 134, 192, 249, 183, 126,  64, 249, 183, 125, 191,
     212, 151, 116, 192, 213, 150, 116, 192, 217, 150, 123, 160, 217, 181, 122, 164,
     233, 148, 112,  12 };

const byte Sound_C3_ECLAIRAGE [188] PROGMEM = {
       0, 188,  47,  47, 245, 183,  80,   0, 232, 183,  98,  46, 232, 183, 100,  32,
     232, 216, 110, 161, 228, 185, 110, 193, 200, 154, 101, 190, 200, 184,  67, 191,
     224, 186,  80,  16, 133, 184, 104, 112,   8, 182,   6,  16,  80, 217, 133, 176,
     152, 217,  92, 131, 152, 216,  68, 134, 224, 183,  85,  32, 245, 214,  86,  93,
     166, 183,  94, 191, 229, 184, 119,  64, 212, 184, 110,  32, 208, 152, 117,  62,
     192, 151, 124, 191, 100, 181, 125,  64,  36, 180, 117, 144, 105, 180, 125, 176,
      25, 179, 101,  48,  89, 179, 117,  48, 165, 176, 149,  55, 169, 177, 174,  62,
     184, 177, 182,  62, 249, 177, 182,  95, 244, 177, 182,  64, 181, 177, 165, 191,
     249, 177, 173, 223, 249, 178, 141,  64, 233, 179, 132, 192, 233, 179, 116,  64,
     144, 182, 116,  64,  97, 186, 100,  62,  88, 217,  84,  32,   4, 217,   4, 144,
      20, 218,   4, 208,  16, 186,   4,  48,  68, 181, 107,  32, 128, 218, 114,  32,
     196, 182, 113, 160, 136, 180, 105, 194, 136, 180, 104,  15 };

const byte Sound_C3_EPONGE [128] PROGMEM = {
       0, 128,  47,  47, 228, 216, 104,   0, 232, 184, 124, 171, 232, 184, 125, 160,
     232, 184, 127,  32, 228, 184, 119,  66, 228, 183, 102, 162, 144, 183,  92,  63,
     144, 184, 114, 162, 208, 184, 104,  48, 133, 178, 104, 112,   0, 180, 148, 176,
      68, 176, 108, 146, 232, 173, 116,  63, 153, 173, 133, 188, 137, 171, 158,  61,
     132, 175, 142,  94, 132, 217, 141,  95, 194, 185, 125,  95, 130, 185, 116, 223,
     136, 185, 117,  95, 130, 186, 124, 192,  72, 184, 124,  62,  72, 182, 123, 191,
      72, 178, 115,  64,  26, 186, 123, 193,  26, 186, 115, 162,  30, 186, 115, 144,
      30, 186, 115, 176, 237, 178,  91, 176, 109, 178,  90,  40, 109, 178,  88,   0 };

const byte Sound_C3_EVIER [116] PROGMEM = {
       0, 116,  47,  47, 228, 184,  96,   0, 228, 184, 107,  38, 228, 184, 108, 160,
     228, 184, 110,   1, 228, 216, 110, 163, 240, 217,  95,  66, 228, 217,  86, 162,
     228, 217,  78,  33, 224, 185,  69,  62, 228, 184,  60,  61, 224, 216,  67,  32,
     148, 216,  50, 220,  85, 183,  67, 187, 149, 185,  60,  36, 153, 217,  52, 189,
     213, 217,  44,  62, 192, 217,  35, 189, 248, 248,  52,  95, 228, 216,  68, 192,
     244, 216,  85, 191, 244, 216,  93, 160, 244, 184, 101, 191, 228, 184, 101,  63,
     208, 218,  92,  64, 208, 217,  91, 160, 228, 217,  83,  64, 240, 217,  66, 137,
     240, 185,  64,  12 };

const byte Sound_C3_FAUTEUIL [148] PROGMEM = {
       0, 148,  47,  47,  85, 148,  88,   0,  21, 149,   4, 144,  21, 150, 125, 208,
      21, 150, 125, 176,  21, 150, 125, 240, 128, 150, 124,  47, 224, 173, 116,  41,
     209, 175, 116, 192, 209, 175, 116, 191, 193, 147,  92,  32, 197, 179,  75,  61,
     192, 170,  80,  48, 192, 181, 112, 112, 134, 216, 125,  16,  85, 215, 149,  48,
      85, 182,  92, 147, 234, 181, 110,  59, 233, 180, 126, 191, 165, 180, 134, 188,
     229, 180, 134, 222, 169, 180, 126,  62, 234, 180, 142, 223, 169, 181, 118, 223,
     249, 183, 102,  64, 229, 183,  93, 191, 229, 215,  85, 160, 233, 215,  69,  63,
     233, 216,  68, 223, 249, 216,  68,  32, 233, 215,  68,  64, 233, 215,  68, 192,
     249, 215,  84, 192, 185, 183, 100, 160, 185, 182, 100,  32, 169, 181,  91, 164,
      80, 182,  56,  13 };

const byte Sound_C3_GARAGE [148] PROGMEM = {
       0, 148,  47,  47, 128, 149,  64,   0,   8, 183,   5,  32, 216, 185,  93, 143,
     228, 184, 111,  35, 164, 182, 167, 192, 164, 149, 175, 160, 144, 149, 182, 161,
      88, 179, 150,  34, 153, 146, 126,  63,  85, 180, 101,  32,  84, 179, 116, 160,
      20, 179, 108, 160,  20, 178,   4, 128,  37, 179,   4,  32,  89, 177, 124, 160,
     100, 178, 157, 181, 169, 177, 174, 160, 185, 177, 175,  61, 164, 177, 190, 223,
     185, 178, 182, 223, 184, 178, 174,  62, 169, 178, 174,  64, 169, 179, 157, 223,
     169, 179, 149,  63, 232, 179, 140, 160, 144, 180, 124,  64,  84, 181, 108, 191,
      80, 217, 108, 190,  81, 217,  68, 160, 100, 218,  44,  32,  84, 218,  11, 161,
      68, 181, 107, 161, 128, 218, 115,  32, 196, 182, 114,  32, 200, 180, 105, 194,
     136, 180, 104,  15 };

const byte Sound_C3_INTERRUPTEUR [192] PROGMEM = {
       0, 192,  47,  47, 168, 213, 112,   0, 168, 213, 131,  43, 168, 213, 132, 160,
     168, 213, 134,   1, 164, 213, 150, 160,  84, 181, 142, 162, 164, 181, 134, 162,
     162, 181, 133,  32, 128, 214,  91, 188,  81, 149, 106, 160, 144, 214, 120, 112,
      20, 215, 181,  16, 120, 215, 141, 176, 216, 215,  84,  15, 212, 183, 101, 162,
     233, 182, 110, 222, 232, 181, 110,  58, 228, 179,  92,  59, 209, 178,  75, 190,
     196, 181,  91, 193, 233, 180,  85,  65, 217, 180,  76,  61, 192, 146,  66,  62,
     192, 185,  80, 112,  20, 182, 132, 144,  53, 182,  14,  80,  36, 215,  77,  16,
     165, 182,  80,  48, 129, 215,  80, 112,  20, 216, 172,  16,  85, 215, 173,  48,
      85, 214, 100,  16, 229, 181, 100, 152, 169, 180, 118,  32, 169, 180, 126, 189,
     233, 180, 134,  62, 228, 179, 124, 190, 244, 179, 132,  63, 244, 179, 132,  64,
     228, 179, 116,  32, 168, 180, 116,  33, 169, 180, 116,  64, 168, 180, 115, 223,
     152, 179, 107, 223, 148, 179,  83,  32, 117, 177,  58, 165,  48, 177,  88,  14 };

const byte Sound_C3_LAMPE [108] PROGMEM = {
       0, 108,  47,  47, 248, 181, 112,   0, 252, 181, 114, 187, 252, 182, 109, 193,
     252, 181, 102,  34, 252, 180, 110,  66, 168, 180, 150, 164, 181, 178, 167,  33,
     166, 177, 183,  33,  84, 176, 183,  33,  85, 173, 199,  63,  81, 139, 174,  63,
      85, 168, 173, 221,  85, 168, 149,  62,  36, 166, 132, 188,  41, 166, 124,  63,
      20, 163, 139,  62,  36, 165,  82, 160,  92, 165,  66,  32,  65, 119, 152,  80,
      64, 185, 136, 112,   1, 179, 224, 112,  21, 146, 181,  48,  20, 181, 180, 144,
     168, 177, 116,  16, 168, 177, 130, 144, 188, 177, 136,  14 };

const byte Sound_C3_LAVABO [124] PROGMEM = {
       0, 124,  45,  47,  36, 182,  40,   0, 184, 182,  59, 189, 253, 181,  69,  65,
     250, 181,  69,  65, 248, 181, 126, 169, 248, 181, 159, 162, 244, 181, 167, 161,
     228, 181, 159,  35, 228, 180, 150, 161, 228, 180, 125, 191, 148, 178, 100,  62,
      64, 214, 124,  32,  68, 180, 108, 160, 228, 179, 125, 162, 228, 179, 150, 160,
     249, 179, 151,  63, 233, 179, 159, 191, 169, 179, 151, 190, 186, 178, 126, 160,
     229, 178, 100, 160, 128, 175, 115, 183,  64, 172,  90, 162,  84, 211,  96, 112,
      85, 176, 100, 176, 104, 171,  83, 182, 168, 170,  91, 160, 237, 169,  99, 223,
     217, 168,  91,  32, 216, 167,  90, 223, 232, 167,  88,  15 };

const byte Sound_C3_LAVE_VAISSEILE [188] PROGMEM = {
       0, 188,  47,  47, 100, 182,  80,   0, 180, 182,  69,  59, 188, 182,  77, 193,
     252, 181,  85, 162, 237, 181,  93, 163, 232, 181, 151,  37, 228, 181, 167,  34,
     228, 181, 167,  67, 164, 181, 150, 165, 132, 181, 150,  35, 132, 183, 125,  32,
     128, 212,  92,  59, 152, 178,  75, 160, 132, 178,  72,  16,   0, 152, 136,  48,
      69, 180,  43,  95,  84, 179,  51, 223, 102, 179,  44,  94,  90, 180,  84, 160,
     170, 180,  85,  33, 250, 182, 102, 192, 232, 183,  94,  64, 232, 183,  85,  62,
     216, 183,  76, 190, 202, 184,  84, 176, 244, 215, 100, 208,  33, 214, 108, 240,
      41, 182, 109, 112, 233, 182,  92,  25, 244, 181, 117, 188, 248, 181, 126, 188,
     245, 182, 142,  62, 244, 182, 134,  94, 244, 182, 133, 192, 244, 183, 125, 192,
     244, 183, 117,  63, 228, 182, 100, 160, 232, 182, 100,  32, 252, 182,  91, 160,
     232, 181,  83, 224, 236, 181,  91, 192, 172, 181, 100, 192, 169, 180, 116,  63,
     164, 180, 107, 160, 148, 180,  99,  11, 148, 179, 104,  14 };

const byte Sound_C3_LINGE [88] PROGMEM = {
       0,  88,  47,  47, 164, 181,  72,   0, 232, 181,  59,  33, 236, 181,  77,  64,
     232, 181, 134,  32, 248, 181, 142, 191, 181, 180, 159,  95, 180, 180, 158,  95,
     160, 179, 133, 223, 160, 147, 125,  32,  80, 180, 124, 192, 164, 179, 108,  95,
     164, 179, 107, 223, 153, 178,  83,  95, 144, 179,  83,  96,  80, 216,  83, 192,
      89, 217,  84, 176, 105, 217,  60, 208, 152, 217, 100,  33, 128, 181, 107,  32,
      80, 180,  58, 164,  84, 180,  16,  14 };

const byte Sound_C3_MACHINE_A_LAVER_LE_LINGE_A [256] PROGMEM = {
       1,  12,  47,  47, 185, 180, 144,   0, 140, 181,  53,  64, 140, 180,  53,  66,
     165, 180, 127,  38, 165, 181, 159, 193, 168, 181, 143,  33, 228, 181, 126,  32,
      65, 217,  94,  63,  84, 251, 126, 176,   2, 185, 254, 240,  10, 186, 254,  80,
       9, 183, 253, 208,  73, 186,  44, 208, 208, 217,  68, 200, 134, 184,  75, 164,
     133, 180,  83, 193, 129, 119,  83,  65, 129, 181,  75, 125, 192, 214, 101,  61,
     228, 182, 134, 180, 180, 181, 151,  61, 181, 181, 159,  60, 168, 181, 151,  63,
     168, 181, 135,  62, 253, 181,  93, 192, 249, 181, 110,  36, 252, 181, 143,  34,
     248, 181, 143,  66, 248, 181, 135,  33, 248, 181, 126,  63, 164, 181, 116,  32,
     144, 214,  99, 160, 144, 215,  99,  69, 229, 182,  92, 164, 212, 182,  93, 164,
     212, 184,  93, 192, 212, 184,  85, 189, 209, 183,  68, 190, 225, 181,  67, 223,
     212, 182,  76,  32, 233, 180, 109,  60, 234, 148, 110,  62, 164, 181, 102,  94,
     164, 181,  85, 188, 164, 181,  77,  60, 232, 181,  60, 160, 236, 181,  77,  64,
     232, 181, 134,  63, 248, 181, 142, 191, 181, 180, 159,  95, 180, 180, 158,  95,
     160, 179, 133, 223, 160, 147, 125,  32,  80, 180, 124, 192, 164, 179, 108,  95,
     164, 179, 107, 223, 153, 178,  83,  95, 144, 179,  83,  96,  80, 216,  83, 192,
      89, 217,  84, 176, 105, 217,  60, 208, 152, 217, 100,  33, 128, 181, 107,  32 };

const byte Sound_C3_MACHINE_A_LAVER_LE_LINGE_B [12] PROGMEM = {
      64, 180, 107,  64,  80, 180,  58, 164,  84, 180,  16,  14 };

const byte Sound_C3_MAISON [92] PROGMEM = {
       0,  92,  47,  47, 169, 180,  88,   0, 136, 181,  60, 160, 204, 181,  60, 161,
     204, 148,  52, 194, 133, 150,  69, 166, 228, 184,  95,  65, 228, 184,  86, 160,
     228, 183,  86, 192, 229, 183,  86,  63, 248, 183,  77, 190, 230, 182,  77,  94,
     230, 181,  68, 189, 134, 181,  76,  95, 166, 179,  76,  64, 214, 178, 101,  32,
     149, 177, 109, 160, 149, 174, 125, 223, 137, 172, 125,  62, 136, 163, 124, 222,
      72, 166, 108,  62, 131, 151, 122, 162,  66, 150, 104,  14 };

const byte Sound_C3_NAPPE [100] PROGMEM = {
       0, 100,  47,  45, 140, 183,  56,   1, 140, 183,  59,  33, 140, 183,  59, 163,
     140, 183,  60, 193, 140, 183,  61,  66, 140, 184,  69,  65, 152, 213,  86,  34,
     164, 214, 151,  32, 160, 213, 175,  62, 160, 181, 191,  63,  97, 180, 190, 191,
      97, 180, 190, 223,  96, 179, 174,  95,  96, 177, 125,  59,  64, 182, 128, 112,
      64, 182, 128, 112,  84, 179,  72, 112, 168, 178, 109, 176, 185, 178, 124, 128,
     185, 178, 149, 188, 169, 179, 149,  62, 168, 179, 149,  63,  88, 177, 124,  33,
     148, 177, 128,  13 };

const byte Sound_C3_OUVRE_BOITE [164] PROGMEM = {
       0, 164,  47,  47, 157, 176,  80,   0, 157, 175,  84,  47, 157, 175,  85,  37,
     157, 174,  86,  64, 158, 173,  85, 162, 154, 172,  77,  63,  64, 171,  84,  32,
     128, 211,  67, 189, 148, 214,  52,  53,   0, 182,   5,  37,  64, 180,  68, 190,
     129, 174,  83, 160, 130, 205,  99, 223, 215, 173, 117,  33, 235, 174, 126, 161,
     250, 177, 127,  94, 234, 176, 102,  61, 161, 176,  52,  61, 149, 174,  56,  16,
     144, 173,  48,  48,  36, 160,   0,  80,  64, 180,  84,  57, 128, 174, 100,  35,
     218, 171, 125, 223, 153, 173, 142, 191, 125, 175, 150, 188, 249, 176, 166,  32,
     249, 179, 174,  64, 248, 180, 165, 189, 248, 180, 157,  63, 233, 180, 128,  16,
     128, 181, 128,  80,  64, 185, 152, 112,  64, 185, 152, 112,  20, 217, 244, 176,
      21, 214, 180,  48, 200, 176, 123,  65, 192, 179, 130, 161,  68, 177, 106, 165,
     148, 178,  96,  14 };

const byte Sound_C3_PELLE [100] PROGMEM = {
       0, 100,  47,  47,  64, 183,  96,   0,  21, 183, 164, 144,  85, 182, 132, 143,
     232, 181, 151,  42, 245, 182, 151,  32, 245, 182, 151, 190, 245, 183, 143, 222,
     245, 183, 135,  94, 180, 183, 126, 189, 184, 183, 118,  93, 252, 182, 101, 190,
     252, 182, 109,  94, 252, 182, 108, 191, 248, 182, 108,  32, 248, 181,  99, 192,
     252, 181,  99, 223, 248, 181,  99,  64, 232, 180, 115, 223, 169, 179, 115,  32,
      96, 211, 107,  63,  80, 178,  82, 192, 100, 178,  73, 192,  80, 211,  49,  15,
      80, 179,  48,  12 };

const byte Sound_C3_PLACARD [128] PROGMEM = {
       0, 128,  47,  47, 192, 181,  80,   0,   0, 151, 253,  48,  96, 150,  85,  46,
     184, 182,  93,  63, 172, 181, 102,  32, 232, 181, 151,  32, 224, 181, 166, 191,
     128, 150, 149, 160,  81, 151,  85,  32,  64, 152, 128,  16, 128, 183, 160,  80,
     129, 215, 136, 112,   8, 185, 182,  48, 196, 217,  84,  49, 224, 184, 126, 190,
     229, 183, 151,  35, 249, 182, 166, 189, 233, 180, 182, 190, 169, 180, 190, 223,
     248, 179, 190,  95, 232, 179, 189,  32, 168, 179, 188, 160, 148, 178, 189,  64,
     148, 178, 188, 190, 164, 177, 179, 160,  84, 176, 147,  32, 161, 176, 147,  64,
      85, 175, 114, 160,  84, 175, 122,  32,  84, 175, 121, 166,  84, 175, 120,  14 };

const byte Sound_C3_PLAFOND [100] PROGMEM = {
       0, 100,  47,  47,  80, 182, 112,   0,  32, 182,   4,  15, 100, 150,  84, 134,
     184, 182,  93, 161, 172, 181, 110,  33, 232, 181, 151,  63, 245, 181, 167,  63,
     228, 181, 166, 160, 144, 149, 141,  33, 149, 180,  92, 160, 149, 213, 124, 176,
      21, 214, 173, 112,   5, 214, 213, 176,  21, 182, 189, 176,   5, 182, 221,  80,
      85, 180, 101,  80,  64, 177, 115,  17, 238, 170, 123, 219,  93, 166, 139, 191,
      72, 163, 147,  63,  40, 162, 131,  32,  40, 162, 130, 190, 130, 150, 130,  35,
     130, 119, 128,  14 };

const byte Sound_C3_PLAT [60] PROGMEM = {
       0,  60,  47,  47, 128, 214, 104,   0,   0, 119, 252,  48,  85, 150,  92, 143,
     101, 181,  93, 164, 172, 181,  86,  64, 172, 180,  93, 192, 232, 180, 134,  63,
     232, 180, 167,  61, 233, 179, 183,  61, 233, 178, 191,  93, 169, 177, 190, 190,
     169, 177, 190,  61, 180, 177, 181, 160,  96, 176, 152,  13 };

const byte Sound_C3_POELE [112] PROGMEM = {
       0, 112,  47,  47,   0, 178,   0,   0,  65, 152, 253, 176,   0, 183, 132,  16,
      64, 176, 132,  47, 150, 170, 108, 160, 154, 171, 109,  32, 170, 172, 125, 191,
     234, 175, 142, 160, 234, 176, 150, 190, 234, 179, 167,  95, 170, 179, 175,  62,
     165, 180, 175,  94, 169, 180, 182, 189, 186, 180, 174, 222, 249, 180, 166,  60,
     164, 180, 149,  63, 164, 180, 116, 191, 168, 181, 123, 191, 152, 180,  99,  32,
     232, 181,  99,  63, 232, 181,  91,  64, 236, 181,  83,  64, 220, 180,  82,  64,
     133, 180, 115, 160, 152, 179, 139, 192, 164, 178, 122, 194, 164, 178, 112,  14 };

const byte Sound_C3_POUBELLE [120] PROGMEM = {
       0, 120,  47,  47, 128, 185, 144,   0,   0, 179, 157, 176,  16, 182, 180, 144,
     128, 139,  91,  47, 129, 167,  74, 195,  32,  96,   2, 223, 128, 133,  72,  48,
      69, 171,  32,  80, 128, 181,  50,  17,  85, 179,  93,  60, 170, 180, 118, 191,
     169, 181, 135,  58, 181, 182, 135,  94, 249, 182, 143,  95, 249, 182, 142, 223,
     185, 182, 126, 192, 185, 182, 118,  63, 245, 182, 109,  32, 253, 181, 109, 192,
     249, 181, 101,  64, 250, 181, 100, 191, 254, 181, 100, 192, 250, 180, 100,  64,
     249, 180, 108, 191, 228, 181, 116,  32, 169, 180, 123, 160, 169, 180, 123,  62,
     185, 179, 114,  37, 250, 179, 112,  15 };

const byte Sound_C3_RADIATEUR [160] PROGMEM = {
       0, 160,  40,  47,  37, 177, 128,   0,  37, 177, 125, 176, 100, 178, 124, 139,
     165, 178, 158,  33, 169, 178, 174, 163, 234, 179, 175,  33, 248, 181, 158, 160,
     164, 182, 126,  63,  64, 182, 123, 160,  65, 181, 123,  33,  80, 118, 130, 160,
      65, 185, 112,  48,  66, 219,  67, 191, 236, 217,  77,  33, 233, 216,  94, 162,
     245, 183, 119,  63, 245, 182, 135,  94, 245, 182, 126, 191, 224, 182,  91, 187,
     209, 150, 112,  48, 208, 214, 104,  80, 134, 180, 112, 112,   5, 180, 117, 144,
      10, 183,  85, 176, 234, 181, 101, 160, 250, 180, 126, 189, 169, 180, 134,  94,
     254, 179, 142,  64, 186, 179, 134,  94, 249, 179, 133, 160, 246, 179, 133,  32,
     234, 179, 140, 192, 233, 180, 132, 192, 233, 148, 124, 192, 148, 180, 116,  64,
     224, 146,  99,  62, 224, 146,  98, 160, 168, 177,  82, 192, 121, 177,  88,   9 };

const byte Sound_C3_REFRIGERATEUR [184] PROGMEM = {
       0, 184,  47,  47, 182, 178,  96,   0, 165, 180, 108,  63, 229, 181, 117,  39,
     216, 181, 125, 167, 228, 182, 134, 165, 228, 183, 126, 165, 229, 183, 118, 161,
     224, 184, 101, 191, 228, 183,  84, 189, 165, 215,  92, 164,  32, 214,   6,  80,
     114, 213, 125, 176,  32, 215, 165, 208, 149, 216,  93,  48, 224, 186,  76,  34,
     197, 185,  68,  94, 209, 186,  68, 190, 208, 217,  76, 221, 100, 218,  44, 190,
      84, 218,  12, 160, 213, 182,  93,  65, 225, 183, 101, 192, 208, 183, 101,  62,
     181, 182,  93,  58, 102, 181, 100,  48, 150, 181,  84,  37, 149, 179, 133, 191,
     169, 179, 166, 189, 170, 179, 167,  62, 165, 180, 142, 190, 232, 180, 125, 160,
     144, 179,  99,  51, 128, 177, 144,  80, 128, 215, 120, 112,  20, 183, 165, 176,
      21, 214, 164, 176, 169, 180, 117, 195, 249, 180, 125,  94, 249, 180, 124, 192,
     253, 180, 124, 224, 232, 180, 123, 255, 168, 148, 116,  64, 216, 146, 107,  64,
     133, 178, 107,  67,  69, 177,  96,  12 };

const byte Sound_C3_RIDEAU [104] PROGMEM = {
       0, 104,  47,  47,  37, 177,  56,   0,  38, 178,  93, 156,  33, 178,   5, 160,
      33, 181,  62, 176,  18, 182,   5, 128, 228, 217,  86, 200, 228, 217,  71,  33,
     245, 217,  63,  64, 229, 216,  54,  32, 208, 185,  52, 191, 133, 153,  52,  60,
     145, 152,  43, 185, 192, 215,  40,  80,   2, 214,  21,  16,  21, 214,  94,   7,
     165, 181,  93, 189, 213, 177, 109, 222, 153, 174, 101,  62, 201, 173, 124, 190,
      69, 170, 116, 191, 154, 170, 100,  32, 137, 168,  99, 191, 213, 168,  91, 160,
     197, 162,  99,  64, 132, 168,  80,  13 };

const byte Sound_C3_ROBINET [128] PROGMEM = {
       0, 128,  45,  47,  22, 204,  88,   0,  21, 162,   3, 186, 150, 170, 115, 174,
     217, 171, 124, 167, 170, 171, 125, 165, 190, 172, 126,  34, 254, 173, 109, 160,
     165, 173,  67, 185, 224, 172,  66, 140, 208, 174,  64,  48, 128, 170,  56,  80,
      16, 192,   3, 145, 153, 183,  77,  37, 229, 184,  61, 160, 228, 217,  61,  32,
     228, 249,  60, 160, 228, 249,  52,  62, 200, 145,  51, 222, 197, 146,  60,  63,
     152, 215,  60, 220, 140, 182,  60, 221, 136, 183,  69,  32, 228, 183,  93, 190,
     233, 183, 110,  63, 168, 184, 110, 223, 232, 184, 126,  95, 228, 184, 117,  32,
     144, 217,  99, 160, 208, 185,  75, 192,  68, 153,  42, 160,  68, 151,  24,  15 };

const byte Sound_C3_SALADIER [136] PROGMEM = {
       0, 136,  47,  47,  26, 213,  56,   0,   9, 213,   4,  48,   9, 216, 132, 112,
      10, 214, 140, 240, 169, 213, 100,  15, 232, 181, 134,  46, 248, 181, 159,  63,
     248, 182, 159, 223, 248, 182, 151,  32, 232, 181, 118,  32, 248, 182, 126, 191,
     248, 182, 151,  63, 248, 182, 151,  62, 248, 182, 151, 189, 248, 183, 127,  95,
     168, 215, 109, 191, 164, 215,  88,  16, 146, 183, 120,  65, 145, 151, 133,  16,
     145, 215, 123, 177, 132, 220,  92, 192, 212, 217,  45,  95, 228, 249,  53,  61,
     212, 249,  68, 192, 232, 217,  68, 160, 245, 217,  76, 160, 245, 216,  93,  63,
     229, 184,  92, 192, 212, 185,  92,  95, 224, 216,  83, 160, 224, 217,  83,  32,
     224, 217,  74, 168, 208, 185,  80,   9 };

const byte Sound_C3_SALLE_A_MANGER [128] PROGMEM = {
       0, 128,  47,  47, 106, 214,  88,   0,  90, 215, 124,  16,  90, 215, 172, 208,
      26, 215, 140, 240, 148, 214, 100, 143, 168, 181, 134, 169, 248, 181, 159,  32,
     232, 181, 159, 223, 232, 180, 126, 160, 168, 181, 126,  33, 168, 181, 143,  33,
     164, 181, 159,  64, 169, 178, 142, 160, 152, 176,  69,  95, 136, 177,  68, 192,
      86, 170, 125, 160,  69, 168, 141,  63,  17, 165, 141,  64,  16, 196, 149, 161,
       8, 202, 149, 192,  72, 176, 133,  62, 148, 179, 117,  94, 100, 218,  45, 164,
      84, 218,  13,  32, 148, 182, 101, 221, 228, 182, 101, 221, 229, 183, 100, 192,
     225, 183, 100,  95, 224, 152,  91, 191, 225, 184,  75,  34, 201, 153,  80,   1 };

const byte Sound_C3_SALLE_DE_BAIN [148] PROGMEM = {
       0, 148,  47,  47, 106, 214,  88,   0,  10, 215, 125,  80,  10, 216, 180, 240,
      26, 215, 173, 112,  84, 182, 117,  15, 168, 181, 135,  42, 228, 181, 151, 223,
     232, 181, 135,  63, 248, 181, 109, 194, 232, 181,  93,  32, 168, 181,  84, 190,
     152, 181,  76,  63, 213, 214,  76,  32, 128, 183,  88,  48, 128, 151,  48,  80,
      85, 214,  36, 185, 150, 181,  93, 164, 234, 180, 102, 192, 234, 179, 102, 190,
     170, 179,  94,  61, 170, 178,  60, 189, 198, 145,  72,  56, 192, 180,  48, 112,
     209, 181,  68, 128, 105, 179, 117,  32, 169, 179, 133, 129, 105, 179, 150, 160,
     105, 179, 159,  63, 121, 179, 166, 223, 121, 179, 157, 190, 101, 178, 132, 160,
      80, 177, 107, 160,  80, 177,  98, 190,  96, 177, 106, 160,  80, 177, 114,   6,
      84, 178,  96,  14 };

const byte Sound_C3_SALON [104] PROGMEM = {
       0, 104,  47,  47,  85, 214,  48,   0,  74, 216,  85, 144, 106, 214, 101, 176,
     154, 215, 101, 176,  74, 214, 101, 208,  26, 213, 133, 240,  84, 182,  92,  21,
     232, 181, 135,  47, 232, 181, 151, 165, 228, 181, 167, 191, 228, 181, 167, 192,
     228, 181, 159,  62, 177, 182, 149, 160, 212, 213, 101,  63, 196, 213,  93,  32,
     228, 181,  76, 221, 165, 149,  60, 190, 148, 180, 101, 191, 234, 178, 118,  61,
     255, 176, 125, 190,  73, 172, 133, 192, 131, 185, 132, 223, 130, 118, 116,  63,
      66, 172,  91, 191, 130, 151,  96,  15 };

const byte Sound_C3_SERPILLIERE [164] PROGMEM = {
       0, 164,  46,  47, 171, 214, 136,   0,  91, 214, 180, 144,  11, 214, 252, 208,
      11, 214, 132, 176,  91, 215, 156,  80,  27, 216, 252,  80,  27, 215, 164, 208,
     228, 183, 101,  47, 232, 183, 110, 170, 148, 183, 126,  94, 161, 181, 109,  59,
     149, 181, 108,  34, 149, 180, 112,  16, 128, 216,  88,  80, 192, 153, 120, 112,
      16, 181, 253,  16,  24, 184,   5, 176, 217, 217,  60,  63, 228, 249,  52, 221,
     228, 249,  52,  61, 226, 217,  59, 189, 196, 250,  51,  32, 196, 216,  43,  95,
     244, 217,  60, 189, 244, 216,  85, 191, 248, 216, 102, 190, 248, 183, 126, 189,
     244, 183, 133, 223, 228, 182, 142,  64, 245, 182, 142,  64, 245, 183, 141,  64,
     229, 183, 125,  64, 229, 183, 117,  95, 229, 183, 117,  64, 233, 183, 124, 192,
     169, 181, 116, 192, 148, 179, 107, 160, 148, 179,  83,  32, 101, 178,  66, 162,
      25, 178,   0,  15 };

const byte Sound_C3_SERVIETTE [140] PROGMEM = {
       0, 140,  47,  47,  78, 214, 144,   0,  78, 214, 149,  80,  14, 216, 164, 240,
      14, 216, 109, 112, 233, 184,  76,  15, 228, 184, 102,  44, 228, 184, 118, 221,
     228, 182, 109,  60,  65, 181,  92,  62,  16, 179, 124,  61, 161, 180, 115, 189,
      80, 214,  67, 170, 144, 184,  67, 160, 193, 183,  67, 220, 209, 185,  60,  65,
     233, 217,  35, 223, 212, 217,  51,  62, 249, 217,  68, 160, 248, 217,  77, 160,
     249, 184, 109, 223, 224, 184, 108,  61, 208, 184, 107, 223, 224, 184,  91,  63,
     225, 184,  66, 160, 193, 183,  96,  16, 128, 187,  96,  80, 192, 184, 104, 112,
       0, 183, 240,  96,   0, 217, 220, 160,  81, 183, 147,  32, 234, 182,  99, 159,
     217, 180, 115,  95,  68, 178, 106,  35, 132, 176, 104,  12 };

const byte Sound_C3_SOL [84] PROGMEM = {
       0,  84,  47,  47, 228, 213,  96,   0, 153, 214, 100, 240,  21, 214,   4, 240,
      26, 212,   4, 240, 153, 212, 100,  15, 248, 179, 118, 172, 245, 177, 142, 223,
     164, 177, 151,  62, 164, 176, 151,  94, 233, 179, 134, 219, 152, 180, 118, 222,
     232, 180, 126,  62, 168, 180, 109, 223, 169, 180, 109,  95, 169, 180, 100, 192,
     168, 180, 108, 160, 105, 180, 116, 191, 106, 180, 107, 160,  17, 146,  58, 163,
      81, 178,  88,  13 };

const byte Sound_C3_TAPIS [96] PROGMEM = {
       0,  96,  47,  47,  64, 183,  88,   0,  32, 214, 205,  48, 160, 182, 124, 143,
     248, 182, 134, 169, 248, 182, 151,  62, 228, 181, 159,  62, 224, 181, 142,  32,
     164, 181, 116,  59, 224, 214, 138, 160, 224, 214, 136,  16, 144, 151, 160,  48,
     129, 183, 120,  80, 128, 214,  88, 112,  21, 182, 116, 144,  36, 184,   6,  48,
      41, 185,   5,  29, 233, 217,  60, 189, 249, 217,  52, 222, 248, 217,  43, 186,
     228, 249,  43,  32, 213, 216,  34, 222, 152, 249,  26,  37, 133, 217,  32,  12 };

const byte Sound_C3_TIRE_BOUCHON [116] PROGMEM = {
       0, 116,  47,  47,   4, 216,  88,   0,   4, 214, 181, 176, 216, 216,  68, 175,
     229, 216,  77, 174, 230, 184,  94, 161, 234, 183, 111,  62, 230, 182, 118, 188,
     165, 178,  93, 187,  80, 175, 108, 189, 129, 171,  99, 191, 128, 132,  64,  16,
      32, 128,   0, 112, 129, 215,  50, 186, 129, 145, 108,  34, 130, 173, 100, 192,
     130, 142,  92,  64,  66, 146,  75, 190, 192, 180, 252, 176, 132, 184, 254,  80,
      96, 186, 254, 112,  16, 217, 254, 112, 144, 176, 116, 221,  90, 170, 140,  94,
      74, 167, 139, 190,  25, 163,  91, 160,  72, 167,  99,  32,  44, 160,   2, 160,
      40, 160,  72,   6 };

const byte Sound_C3_TOILETTE [132] PROGMEM = {
       0, 132,  41,  47,  64, 216,  72,   0,  21, 216,  84, 144,  21, 214, 142,  48,
      17, 117, 253, 144,  82, 181,  76, 143, 145, 144,  84,  36, 146, 173,  92, 160,
     150, 173, 101, 162, 170, 174, 126, 161, 185, 177, 143,  32, 166, 180, 143, 160,
     165, 181, 135,  63, 232, 181, 118,  60, 248, 182, 109, 222, 248, 182, 127,  61,
     248, 182, 143,  32, 184, 182, 143,  91, 185, 182, 142, 190, 249, 183, 125, 192,
     208, 215, 112, 112, 192, 217, 120, 112, 192, 217, 120, 112,   0, 216, 188, 144,
       0, 184, 252, 176,   1, 213, 141,  48, 149, 180, 107,  38, 169, 180, 124,  32,
     169, 179, 140,  62, 232, 179, 140,  58, 224, 179, 139, 190, 133, 179, 106, 160,
      81, 181,  88,  15 };

const byte Sound_C3_TOIT [76] PROGMEM = {
       0,  76,  47,  47,  64, 216,  72,   0,  21, 216,  84, 144,  21, 214, 142,  48,
      17, 117, 253, 144,  82, 181,  76, 143, 145, 144,  84,  36, 145, 171,  83,  62,
     150, 169,  92,  32, 134, 165, 117,  33,  86, 169, 125, 160, 214, 173, 142,  32,
      85, 175, 174,  95, 105, 174, 173, 186, 164, 174, 165,  62, 113, 174, 149,  62,
      97, 174, 123, 190, 163, 174, 114, 189, 162, 174, 120,  13 };

const byte Sound_C3_VAISSELLE [120] PROGMEM = {
       0, 120,  47,  47,  76, 178,  64,   0, 106, 180,  98, 145, 148, 180,  91,  60,
     128, 181,  83, 165, 149, 183,  76,  39, 170, 183, 102, 168, 249, 184,  95,  66,
     232, 184,  94,  32, 233, 183,  77,  32, 217, 216,  84, 191, 148, 215,  84,  32,
     164, 215, 100,  65,  16, 184, 125,  80,  81, 215, 125, 112, 217, 182,  84,  32,
     249, 181, 118,  32, 249, 182, 134, 182, 245, 182, 142, 189, 181, 182, 134, 222,
     245, 183, 134,  95, 185, 182, 118,  95, 254, 182,  93, 223, 250, 182, 101, 192,
     250, 181, 101, 192, 249, 181, 100, 160, 249, 181,  92,  32, 250, 181,  91, 192,
     251, 181,  90, 162, 235, 181,  88,  15 };

const byte Sound_C3_VOLET [88] PROGMEM = {
       0,  88,  47,  47, 212, 179,  80,   0, 144, 182,  74, 187, 148, 182,  75,  32,
      64, 180,  83, 173,  80, 175, 108, 165, 233, 173, 109, 164, 234, 173, 118,  35,
     234, 175, 118, 161, 170, 178, 119,  64, 169, 148, 110, 188, 164, 181,  94, 189,
     188, 181,  78,  91, 186, 181,  61, 191, 249, 182, 102,  32, 249, 182, 126, 189,
     249, 183, 127,  62, 233, 183, 126, 222, 169, 183, 110, 223, 245, 183, 117, 160,
     228, 184, 116, 161, 224, 184, 104,  14 };

const byte Sound_C3_AVEC [104] PROGMEM = {
       0, 104,  47,  47,  20, 179, 184,   0, 148, 180, 181,  12, 165, 179, 182, 160,
     168, 179, 183,  34, 168, 180, 159,  64, 169, 180, 142,  32, 168, 179, 117,  61,
     212, 179, 108,  32,  85, 182,  68, 186,  85, 182,  92,  63, 153, 180,  84,  63,
     101, 181, 100, 191, 185, 181, 125, 160, 249, 181, 134,  32, 249, 182, 134,  94,
     181, 183, 126,  95, 229, 183, 125, 191, 229, 184, 101,  35, 160, 152,  83, 168,
     208, 183,  96,  80, 209, 215, 112, 112,   0, 182,   0, 112,   4, 186, 205, 176,
       8, 185, 252,  80,   8, 183, 248,   0 };

const byte Sound_C3_CEINTURE [168] PROGMEM = {
       0, 168,  47,  47, 168, 181, 104,   0, 155, 215, 164, 208,  27, 214, 148, 112,
     212, 179, 100,  15, 228, 179, 133, 174, 228, 180, 142, 191, 229, 180, 143,  32,
     228, 180, 143,  63, 208, 180, 134,  63, 208, 181, 117,  62, 192, 180,  83,  56,
     144, 212,  72,  80,   1, 218,  56, 112,  33, 187, 148, 176,  17, 184, 229,  80,
     162, 184,  68, 189, 161, 183,  69, 188, 113, 183,  61, 160, 113, 183,  77, 192,
     177, 183,  78,  95, 177, 183,  77, 190, 113, 183,  77, 224, 241, 183,  85,  95,
     225, 151,  84, 191, 229, 150,  84, 192,  85, 148,  76,  63,  85, 179, 100, 190,
      97, 177, 108,  62, 161, 209,  91,  63,  97, 209,  88,  16,  96, 210,  88,  48,
      33, 210,  11,  64,  69, 175, 147,  64, 153, 175, 107, 167, 101, 176, 140, 188,
     165, 176, 123, 191, 165, 175, 115,  32, 153, 175,  82, 191,  89, 176,  42, 191,
      21, 176,   2,  37,  21, 177,   0,  13 };

const byte Sound_C3_CHAPEAU [92] PROGMEM = {
       0,  92,  47,  47,   0, 185,   0,   0,   5, 184, 254, 208,   5, 187, 255, 112,
      74, 186, 254, 208, 218, 181, 118,  47, 229, 180, 151,  66, 160, 179, 158, 191,
     213, 145, 141, 191, 128, 142, 124,  63, 128, 180, 144,  48, 128, 184, 128, 112,
     128, 181, 104, 112,   1, 151, 253,  48,   0, 117, 243, 176,  69, 171, 100,  49,
     222, 169, 108,  59, 174, 168,  83, 223, 237, 166,  91,  62, 222, 167,  99,  95,
     217, 165,  98,  63, 153, 166,  98,  36, 148, 168,  72,  14 };

const byte Sound_C3_CHAUSSETTE [116] PROGMEM = {
       0, 116,  47,  47,   5, 183, 112,   0,  17, 219, 126, 144,  21, 219, 150, 176,
       5, 187, 254, 208,  24, 218, 254, 240, 132, 186, 101, 175, 229, 176, 101,  37,
     230, 176, 109,  95, 214, 176, 100, 188, 229, 214, 109, 240,  25, 182,  69, 240,
     228, 181, 126, 186, 245, 181, 143, 182, 245, 182, 143,  63, 240, 182, 142, 191,
     245, 182, 126, 222, 245, 182, 110,  61, 208, 216, 120, 112, 192, 182, 128, 112,
      85, 181, 112, 112,  21, 182, 165,  48,  16, 214, 165,  48, 212, 179, 116,  36,
     213, 178, 108,  62, 128, 214, 123, 190, 132, 178, 107, 191, 144, 179, 114, 165,
     164, 179,  96,  14 };

const byte Sound_C3_CHAUSSURE [128] PROGMEM = {
       0, 128,  47,  47,  66, 182, 112,   0,  17, 216, 118,  16,  85, 217, 167,  48,
      33, 186, 254, 240, 149, 178, 102,  47, 134, 177,  94, 196, 214, 176,  85,  60,
     197, 210,  84, 177,  73, 214,  77,  63,   8, 213,   6,  16,  88, 214,  70,  48,
      41, 215,  37, 240, 104, 215,  69, 240, 164, 183,  69,   5, 180, 183,  69, 191,
     165, 151,  70,  62, 177, 183,  70,  95, 161, 151,  69, 222, 113, 183,  70,  62,
     177, 183,  77, 192, 241, 151,  69,  62, 177, 183,  77, 160, 177, 183,  78,  64,
     241, 151,  77,  62, 225, 151,  84, 160, 213, 150,  92,  63, 196, 149, 100,  32,
     132, 176,  99, 192, 101, 176,  91, 190,  86, 176,  99, 165,  37, 174,  96,  15 };

const byte Sound_C3_CHEMISE [124] PROGMEM = {
       0, 124,  47,  47,  22, 182, 112,   0, 116, 218, 166, 176,  20, 217, 150,  80,
       5, 187, 254, 112,  65, 183, 252, 143, 212, 181, 100, 173, 230, 148, 109, 190,
     214, 148, 109, 191, 133, 115,  92, 191, 192, 114,  75, 160, 201, 112,  67,  64,
     200, 146,  59, 221, 133, 152,  61, 188, 132, 213,  69, 190, 132, 246,  77, 222,
     132, 247,  69,  94, 132, 214,  77,  94, 137, 211,  68, 192, 132, 183,  68,  62,
     208, 185,  68,  64, 154, 183,  43, 160,  69, 185,  35, 160,  85, 182,  51, 160,
     213, 181,  75, 160, 229, 180,  91, 161, 233, 180, 115, 190, 164, 180, 115, 191,
      80, 212,  75,  62,  97, 179,  42, 166,  80, 178,   8,  15 };

const byte Sound_C3_CHEMISE_DE_NUIT [164] PROGMEM = {
       0, 164,  47,  47,  22, 182, 112,   0, 116, 218, 166, 176,  20, 217, 150,  80,
       5, 187, 254, 112,  65, 183, 252, 143, 212, 181, 100, 173, 230, 148, 109, 190,
     214, 148, 109, 191, 133, 115,  92, 191, 201, 112,  67,  64, 200, 146,  59, 221,
     133, 152,  61, 188, 132, 213,  69, 191, 132, 247,  69,  64, 132, 214,  77,  95,
     137, 211,  68, 223, 208, 185,  67, 223, 213, 183,  67,  64, 107, 181,  48,  33,
     107, 181,  53,  36, 171, 181,  86, 163, 235, 181,  95,  64, 234, 181,  94, 160,
     230, 181,  86,  61, 212, 180,  56,   0, 212, 180,  56,   0, 212, 180,  59,  32,
     216, 179,  52,  63, 216, 182,  60, 222, 148, 214,  52, 192, 152, 182,  60,  63,
     196, 177,  60,  32, 144, 216,  60, 189, 176, 152,  69,  95, 177, 151,  68, 223,
     240, 184,  59, 223, 212, 216,  59, 160, 217, 216,  51, 192, 217, 216,  67, 164,
     217, 216,  56,  13 };

const byte Sound_C3_CUBE [88] PROGMEM = {
       0,  88,  47,  47,  84, 183,  96,   0,  32, 183, 157, 176,  32, 248, 173,  16,
      32, 153, 196, 176, 178, 184,  52, 175, 231, 152,  61,  37, 247, 151,  61,  64,
     246, 151,  53,  91, 162, 151,  61,  60, 225, 183,  60, 188, 144, 119,  32, 112,
     132, 179,  24, 112, 149, 179,  66, 178, 245, 179, 116,  37, 169, 178, 125,  32,
     238, 179, 134,  63, 254, 178, 141, 190, 249, 179, 141,  63, 165, 178, 107, 160,
     165, 177,  75,   9, 169, 177,  64,  13 };

const byte Sound_C3_CUILLERE [112] PROGMEM = {
       0, 112,  47,  47,  68, 182, 120,   0,   8, 182,   6, 176,   4, 151, 133,  16,
      32, 184,   4, 176, 100, 183,   4, 175, 234, 152,  60, 196, 224, 216,  60, 223,
     225, 249,  60,  92, 232, 248,  52, 221, 228, 217,  61,  61, 245, 217,  70,  32,
     244, 216,  94, 190, 249, 184, 118, 188, 229, 183, 126, 160, 229, 183, 142, 222,
     245, 183, 142, 192, 249, 183, 134, 190, 249, 183, 142, 223, 249, 183, 134,  63,
     248, 183, 141, 160, 249, 183, 133, 192, 229, 183, 133, 223, 229, 183, 133,  64,
     229, 151, 124, 191, 232, 151, 124,  64, 197, 150, 123, 168, 213, 150, 120,  12 };

const byte Sound_C3_CUILLERE_A_DESSERT [204] PROGMEM = {
       0, 204,  47,  47,  64, 183, 104,   0,   4, 185, 254, 176,  16, 218, 172, 176,
      32, 186, 252, 176, 181, 184,  60, 175, 246, 184,  60, 164, 247, 184,  61,  61,
     235, 216,  61,  32, 234, 216,  53,  32, 245, 216,  53,  95, 229, 216,  61,  33,
     229, 216,  70,  33, 229, 184, 102, 160, 233, 184, 111,  64, 233, 183, 127,  95,
     233, 182, 118,  61, 165, 180, 125,  48, 148, 180, 125,  61, 169, 179, 150,  33,
     169, 178, 166, 191, 153, 178, 166, 192, 169, 180, 158, 223, 232, 180, 134,  62,
     144, 180, 100, 189, 148, 179,  84,  63, 144, 214,  67,  63, 144, 214,  64,  64,
     233, 183,  93, 166, 233, 183, 102,  63, 233, 184, 102,  95, 229, 184,  93, 191,
     237, 184,  85,  62, 169, 184,  68,  32, 119, 215,  93,  48,  22, 215,  76, 240,
      21, 182,   4, 240, 218, 181,  92,  13, 253, 181, 117, 184, 228, 181, 125,  61,
     229, 181, 142,  62, 245, 182, 142,  95, 228, 182, 141,  63, 228, 182, 132, 191,
     192, 183, 132,  62, 208, 182, 139, 192, 228, 183, 132,  64, 229, 183, 123, 223,
     232, 183, 114, 160, 224, 183, 113, 169, 224, 183, 104,  13 };

const byte Sound_C3_CUILLERE_A_SOUPE [168] PROGMEM = {
       0, 168,  47,  47,  64, 183, 104,   0,   4, 185, 254, 176,  16, 218, 172, 176,
      32, 186, 252, 176, 181, 184,  60, 175, 246, 184,  60, 164, 247, 184,  61,  61,
     235, 216,  61,  32, 234, 216,  53,  32, 245, 216,  53,  95, 229, 216,  61,  33,
     229, 216,  70,  33, 229, 184, 102, 160, 233, 184, 111,  64, 233, 183, 127,  95,
     233, 182, 118,  61, 165, 180, 125,  48, 148, 180, 125,  61, 169, 179, 150, 161,
     169, 178, 166, 191, 169, 178, 167,  62, 164, 180, 142, 223, 164, 180, 116, 191,
     150, 181, 125,  48,  22, 215, 117, 112,  20, 215, 132, 240,  64, 185, 252,  48,
     129, 183,  75,  60, 193, 169,  74, 221, 149, 167,  58,  94, 129, 168,  57, 191,
     208, 180,  72, 112, 192, 182,  72, 112, 192, 182,  72, 112,  84, 178, 117,  48,
     185, 177, 107,  31, 232, 176, 123,  32, 165, 177, 139, 223, 217, 177, 147,  32,
     164, 177, 130, 168, 100, 177, 136,  13 };

const byte Sound_C3_DERRIERE [140] PROGMEM = {
       0, 140,  47,  47, 128, 119,  32,   0,   0, 182,   5,  48,  86, 181,  85, 171,
     248, 183, 118, 160, 248, 183, 127,  32, 249, 183, 135,  63, 224, 183, 126, 160,
     224, 183, 126,  32, 208, 183, 125, 160, 230, 181, 101,  93, 170, 214, 100, 193,
     229, 215,  92, 190, 196, 185,  92, 160, 129, 187,  91, 186, 210, 186,  90, 191,
     130, 186,  80,  48, 245, 217,  60,  60, 244, 217,  77,  33, 245, 216,  94,  32,
     245, 183, 118, 190, 245, 183, 135,  37, 245, 182, 150, 222, 245, 182, 142,  95,
     245, 183, 142,  95, 229, 183, 134,  63, 228, 183, 133, 160, 212, 183, 125,  63,
     196, 151, 124, 160, 200, 152, 116,  32, 208, 151, 116,  64, 165, 181, 108,  64,
     149, 180, 107, 191, 165, 179, 107, 141, 165, 179, 104,  15 };

const byte Sound_C3_DEVANT [108] PROGMEM = {
       0, 108,  47,  47, 128, 119,  32,   0,   0, 182,   5,  16,  86, 181,  85, 171,
     166, 180, 102, 162, 214, 180, 110, 162, 170, 179, 102, 192, 234, 179, 102,  32,
     250, 179,  93, 190, 170, 178,  85,  61, 170, 178,  92, 187, 230, 178,  92,  61,
     213, 178,  98, 160, 128, 181,  50, 160, 148, 182,  74, 160, 148, 214,  83, 160,
      69, 178,  75, 160,  89, 175, 116, 186, 169, 174, 125,  32, 100, 173, 141,  95,
     102, 204, 141,  95,  98, 172, 140, 190,  98, 172, 148,  32, 102, 171, 131, 191,
     103, 171,  99,  62,  86, 168,  74,  38,  85, 168,  64,  14 };

const byte Sound_C3_DISTANCE [152] PROGMEM = {
       0, 152,  40,  47, 128, 119,  32,   0,   0, 182,   5,  16,  86, 181,  85, 171,
     200, 216,  60, 153, 216, 217,  52, 165, 216, 217,  52, 167, 196, 217,  60, 163,
     208, 220,  60, 190, 132, 187,  44, 177, 153, 184,  68, 177,  86, 247,  68, 208,
      86, 247,  76, 240,  80, 215,  72,  16,  80, 215,  72,  80,  81, 182, 149,  48,
     144, 213, 100, 145, 213, 179, 125, 175, 149, 178, 134,  38,  85, 208, 142,  62,
     164, 206, 133, 222,  96, 206, 133,  62,  97, 173, 117,  63,  97, 172, 133,  95,
      97, 173, 132, 190,  97, 173, 124, 192,  84, 175, 116, 223,  96, 175, 107, 190,
       5, 246, 124, 208,  85, 247, 140, 208,  21, 247, 116, 240,  21, 245,   4, 208,
     153, 211,  92, 208, 196, 177, 115, 164, 192, 213, 123, 191, 128, 210, 115, 192,
     101, 179,  26, 188,   0, 179,  80,  15 };

const byte Sound_C3_GANT [60] PROGMEM = {
       0,  60,  47,  47, 145, 184,  40,   0,   8, 116, 253,  56,  32, 151,  93,  31,
     160, 182,  93,  15,  81, 182, 118,  14, 154, 148, 135,  34,  90, 177, 159,  33,
     154, 176, 159,  32, 166, 174, 158,  95, 102, 172, 150,  94, 102, 171, 141, 221,
      37, 171, 124, 189, 117, 171, 115,  32, 100, 170, 120,  12 };

const byte Sound_C3_GILET [108] PROGMEM = {
       0, 108,  47,  47,  16, 216,   0,   0,  16, 216,   2, 143,  20, 217,   4,   9,
       1, 217,   4, 160,  17, 250,   4, 129, 153, 218,  69,  61, 209, 216,  53,  68,
     212, 216,  52, 163, 192, 218,  60,  32, 128, 214,  60,  94, 196, 214,  60, 189,
     216, 215,  52,  60, 224, 214,  61,  61, 245, 214,  61,  93, 229, 182,  85, 190,
     249, 182, 102, 188, 249, 182, 102, 160, 249, 183, 126, 191, 249, 183, 126, 191,
     245, 183, 126,  63, 245, 183, 117, 160, 229, 183, 109, 160, 208, 183, 100, 160,
     208, 184, 100,  63, 208, 184, 108,  35, 212, 184,  80,  13 };

const byte Sound_C3_GRANDEUR [132] PROGMEM = {
       0, 132,  47,  47,  32, 114,  72,   0,  32, 177,   4, 176, 165, 175, 108, 187,
     106, 174, 100, 161, 146, 172, 124,  66, 105, 172, 140, 164, 106, 171, 141, 164,
     106, 171, 133, 163, 170, 170, 133, 196, 181, 171, 133,  37, 178, 172, 125,  35,
     245, 173, 125,  63, 229, 174, 117,  63, 236, 174,  75, 184, 212, 173,  66, 189,
      65, 178,  40,  80,   0, 214, 118,  48, 233, 180, 109, 188, 249, 180, 126, 182,
     169, 179, 134, 222, 250, 179, 142, 223, 233, 179, 134, 223, 249, 179, 142,  96,
     248, 179, 141, 188, 248, 179, 133, 160, 248, 179, 133,  32, 232, 179, 123, 191,
     212, 180, 123,  32, 181, 179,  67,  32, 165, 179,  83,  64,  85, 178,  99,  38,
     150, 178,  80,  14 };

const byte Sound_C3_HAUTEUR [128] PROGMEM = {
       0, 128,  47,  47, 248, 175, 128,   0, 169, 174, 133, 155, 238, 173, 126,  33,
     217, 172, 126,  68, 154, 172, 126,  36, 153, 173, 119,  32, 250, 173, 110,  32,
     230, 175, 100, 160, 145, 178,  76, 161, 192, 172, 112, 112,   1, 183, 168, 112,
       1, 182,   6,  16,   1, 215, 150,  48,  85, 183, 101,  17, 233, 180, 126, 164,
     233, 180, 142, 220, 229, 179, 150, 222, 185, 179, 142, 223, 233, 179, 142,  63,
     229, 179, 141, 191, 153, 179, 133, 223, 228, 179, 133,  63, 224, 179, 124, 190,
     224, 179, 124,  32, 197, 179, 132,  64, 212, 178, 115, 223, 229, 147,  99, 192,
     169, 147, 107, 160, 164, 179, 115, 160, 152, 179,  99,  40,  84, 178,  88,  14 };

const byte Sound_C3_IMPERMEABLE [192] PROGMEM = {
       0, 192,  43,  57, 169, 181, 128,   1, 180, 181, 151,   3, 165, 181, 159,  35,
     164, 181, 167,  67, 164, 180, 150, 163, 148, 147, 117,  58,  81, 181, 131,  63,
     128, 181, 120, 112, 101, 181, 132, 176, 213, 180,  92,  15, 229, 181, 126,  33,
     245, 181, 134, 188, 232, 180, 134,  61, 212, 179, 141,  61, 154, 178, 100, 187,
     150, 177, 100,  34,  70, 138, 116,  35, 148, 171,  75,  63, 216, 174,  67,  32,
     216, 177,  60,  95, 165, 181, 110,  59, 165, 183, 126, 188, 233, 184, 126, 187,
     229, 184, 118,  95, 245, 184, 118,  94, 181, 183, 134, 160, 165, 182, 159,  63,
     169, 181, 174, 160, 233, 180, 175,  63, 250, 179, 182, 192, 186, 179, 174, 192,
     249, 178, 165, 192, 250, 178, 157, 223, 250, 177, 124, 160, 169, 178,  80,  16,
     144, 176,  40,  48,  84, 181,  64, 112, 100, 181, 100, 163, 168, 181, 101, 160,
     252, 180, 100, 191, 236, 181, 100, 160, 253, 180, 101,  64, 253, 180, 133, 160,
     190, 179, 141,  32, 185, 179, 132, 160, 168, 179,  99, 190, 185, 179,  88,  15 };

const byte Sound_C3_JUPE [80] PROGMEM = {
       0,  80,  47,  47, 144, 216,  72,   0, 144, 216,  77,  67, 212, 182,  77, 165,
     241, 182,  69, 196, 242, 182,  70,  32, 162, 150,  62,  92, 225, 150,  52, 182,
     197, 118,  59,  32, 208, 214,  64, 112, 129, 181,  48, 112,  16, 181,  64, 112,
     185, 114,  91, 160, 212, 113, 107, 191, 197, 114, 116,  63, 149, 114, 116, 223,
     148, 114, 108,  63,  21, 115,  17, 162, 101, 114,  99,  32, 100, 114,  64,   4 };

const byte Sound_C3_LARGEUR [148] PROGMEM = {
       0, 148,  47,  47, 248, 181, 136,   0, 248, 181, 108, 186, 253, 181, 117, 193,
     232, 181, 150, 166, 244, 180, 183,  34, 169, 178, 183,  66, 148, 178, 166,  35,
      85, 176, 109,  32,  80, 176, 100, 161, 101, 178,  76,  32, 101, 176,  51, 160,
      85, 176,  43, 160, 150, 177,  59, 192, 150, 177,  68,  63, 132, 180,  84, 189,
      16, 216,   4, 136,  20, 217,   4, 128,   1, 217,   4, 160,  17, 186,   4, 129,
       5, 180, 109, 217,   4, 211, 109, 192, 153, 178, 125, 223, 233, 179, 142,  94,
     233, 179, 141, 223, 232, 179, 141, 191, 228, 179, 124, 192, 228, 179, 124,  64,
     244, 179, 116,  95, 224, 179, 123, 160, 228, 180, 124,  32, 228, 179, 131, 160,
     233, 179, 115, 192, 153, 178,  91, 156, 136, 177, 123,  63, 136, 177, 122, 168,
     216, 177, 120,  15 };

const byte Sound_C3_LOIN_DE [132] PROGMEM = {
       0, 132,  47,  47, 164, 181,  80,   0, 244, 181,  75,  59, 245, 149,  67, 160,
     245, 149,  68, 163, 246, 117,  68, 194, 186,  84,  60, 164, 246,  83,  68, 163,
     169, 177, 101, 163, 214, 172,  93,  64, 138, 168, 109,  32,  41, 160,  93, 161,
      73, 164, 142,  34,  90, 167, 134,  33, 170, 173, 134, 160, 166, 176, 151,  32,
     166, 178, 159, 192, 165, 179, 159,  64, 161, 180, 151,  63, 160, 181, 134, 160,
     148, 181, 109, 189, 140, 179,  68,  63,  67, 181,  83, 185, 129, 213,  72, 112,
      65, 215, 101, 176, 149, 181,  93,  61, 233, 180, 102,  62, 165, 180, 110,  60,
     165, 180, 101, 222, 169, 180, 109, 223, 165, 180, 101,  62, 196, 178,  91,  38,
     196, 178,  96,  14 };

const byte Sound_C3_LONGUEUR [132] PROGMEM = {
       0, 132,  47,  47, 253, 181,  80,   0, 249, 180,  77,  24, 165, 180,  85,  37,
     165, 178, 126,  36, 250, 175, 125, 161, 154, 173, 126,  34,  73, 169, 134,  35,
     137, 170, 142,  33, 136, 163, 133, 161, 136, 168, 101,  64, 140, 171,  84, 160,
     140, 174,  68,  62, 136, 174,  51, 190, 132, 174,  58, 190,  20, 182,  40,  80,
     161, 152,  85,  58, 230, 184,  94,  32, 229, 183, 110, 160, 229, 182, 126, 188,
     249, 180, 134, 255, 169, 180, 142, 224, 233, 180, 142,  94, 233, 180, 133, 192,
     244, 180, 133,  32, 228, 180, 132, 160, 169, 180, 125,  32, 165, 180, 125,  64,
     149, 179,  91, 160, 144, 212,  99,  63,  64, 178, 106, 160, 168, 177, 106, 165,
      36, 178,  88,  14 };

const byte Sound_C3_MANTEAU [104] PROGMEM = {
       0, 104,  47,  46, 149, 180,  96,   1,  85, 179,  82, 190, 141, 179,  60, 161,
     152, 177,  60, 192, 136, 180,  69,  35,  85, 174, 117, 165, 150, 172, 126,  33,
      83, 171, 142,  35, 131, 170, 150,  66,  67, 169, 141, 162, 198, 172, 133, 162,
     145, 173, 125,  32, 128, 170, 115, 186, 129, 146, 120, 112, 148, 183, 128, 112,
      20, 182, 238,  48,   0, 217,  37, 176,  69, 171, 100,  53, 222, 169, 108,  59,
     174, 168,  83, 223, 237, 166,  91,  62, 222, 167,  99,  95, 217, 165,  98,  63,
     153, 166,  98,  35, 148, 168,  72,  15 };

const byte Sound_C3_PAIRE_DE_LUNETTE [204] PROGMEM = {
       0, 204,  47,  47, 144, 213, 120,   0, 165, 181,  84,  15, 249, 182, 102,  46,
     245, 182, 110, 189, 244, 183, 118, 192, 228, 183, 118,  32, 228, 182, 117, 162,
     208, 181, 100, 160, 144, 179,  92,  62, 146, 176, 107, 160, 230, 176,  99, 160,
     129, 210,  75, 221, 133, 211,  59,  57, 193, 175,  40,  48,  85, 213,  52,  60,
     170, 181,  85, 160, 250, 180, 101, 160, 233, 180, 102,  62, 165, 181,  94,  95,
     116, 150,  36, 190, 181, 150,  60, 161, 181, 150,  68, 189, 180, 150,  60,  38,
     182, 150,  69,  68, 181, 151,  61,  66, 224, 183,  51,  38, 200, 180,  67,  65,
     216, 179,  59,  92, 212, 181,  60, 189, 249, 182, 118, 188, 229, 182, 134, 188,
     249, 182, 134, 190, 249, 182, 134, 223, 249, 182, 126,  62, 245, 183, 109, 190,
     245, 183, 100, 189, 166, 182,  96,  48, 192, 184,  88, 112, 128, 152, 120, 112,
       0, 182, 248, 112,  21, 182, 204, 176,   1, 182,  93,  48, 233, 180, 117,  44,
     233, 180, 125, 189, 165, 180, 134,  61, 233, 180, 141, 223, 101, 179, 125, 190,
      85, 179, 132, 190,  85, 177,  67,  35, 149, 177,  96,  15 };

const byte Sound_C3_PANTALON [132] PROGMEM = {
       0, 132,  47,  47,  16, 212, 144,   0,  16, 179, 156,  16, 101, 173, 141,  15,
     170, 171, 149, 174, 170, 171, 150,  33, 166, 171, 141, 162, 165, 172, 133,  36,
     225, 174, 125,  64, 133, 174, 116, 187, 129, 174, 115, 186, 149, 169,  96,  48,
     192, 217, 128,  80,  84, 214, 125,  16,  20, 214, 117,  16, 232, 180, 126,  35,
     249, 180, 151,  62, 229, 180, 167,  92, 249, 181, 151,  95, 168, 181, 110, 189,
     252, 181, 102,  32, 253, 181,  93, 188, 185, 180,  93,  62, 233, 180,  84, 189,
     164, 179, 109,  62, 170, 177, 117,  62, 174, 176, 116, 190, 173, 174, 115, 190,
     137, 171, 123, 192,  68, 170, 115, 191, 132, 174, 115, 160, 136, 173, 106, 166,
     136, 173,  96,  13 };

const byte Sound_C3_PARAPLUIE [136] PROGMEM = {
       0, 136,  47,  47, 144, 213, 120,   0, 165, 181,  84,  15, 249, 182, 101,  14,
     233, 178, 166,  35, 229, 178, 191,  65, 169, 178, 183,  33, 100, 178, 174,  32,
     168, 176, 149,  61,  90, 177, 124, 191,  73, 178, 140, 160,  85, 178, 132, 159,
      69, 177, 116, 160, 148, 175, 149,  34, 164, 176, 157, 190, 168, 177, 142,  94,
     148, 177, 101,  58, 132, 174, 128,  80, 128, 184, 144, 112,  26, 179,   5,  48,
      21, 181,  28, 176, 100, 180,  75, 186, 148, 117,  67, 223, 101, 116,  51, 221,
     144, 183,  76, 161, 161, 183,  77,  32, 176, 184,  69,  64, 229, 216,  69,  64,
     245, 216,  68, 190, 228, 216,  68,  32, 212, 216,  59,  32, 232, 216,  42, 160,
     212, 216,  34,  34,  68, 215,  32,  14 };

const byte Sound_C3_PIJAMA [108] PROGMEM = {
       0, 108,  47,  47, 144, 182,  96,   0,  25, 183,   6, 176, 153, 217,  61, 175,
     233, 217,  61,  71, 233, 185,  61,  93,  82, 217,  70,  62,  80, 217,  45, 188,
      16, 216,   5, 150,  20, 217,   6, 144,   1, 217,   7,  48, 244, 181, 118, 192,
     229, 181, 135,  62, 165, 180, 159, 222, 165, 179, 151,  61,  88, 146,  77, 190,
     152, 177,  69,  32, 136, 178,  68, 191, 220, 176,  59, 190, 216, 177,  51,  62,
     216, 176,  59,  95, 168, 178, 133,  62, 100, 178, 149, 191, 168, 177, 174,  64,
     185, 177, 173, 192, 164, 176, 157,  34,  96, 176, 120,  14 };

const byte Sound_C3_POIDS [76] PROGMEM = {
       0,  76,  47,  47,  84, 182, 112,   0,   0, 181, 149,  48,   0, 151, 251, 144,
      64, 148, 116,  40,  22, 163, 124, 160,  70, 163, 133,  33, 134, 167, 133,  33,
     199, 169, 125, 160, 151, 171, 133, 191, 150, 173, 142, 160, 102, 174, 159,  62,
     106, 175, 167,  62, 105, 175, 175,  95, 185, 175, 166,  61,  96, 175, 157, 188,
     160, 143, 157,  63,  96, 175, 123,  63,  96, 175, 120,  12 };

const byte Sound_C3_PRES_DE [100] PROGMEM = {
       0, 100,  47,  47, 192, 181,  96,   0,  16, 181, 166,  48,   0, 118, 252, 144,
      33, 176, 221, 176,  53, 177, 181, 176, 149, 180, 108, 170, 233, 180, 125, 160,
     234, 181, 134, 161, 233, 182, 135,  64, 249, 182, 127,  95, 249, 182, 127,  62,
     253, 182, 102,  61, 232, 181,  84,  32, 224, 183, 104,  48,  86, 215, 112, 112,
     134, 184,  92,  48, 149, 182,  85,  56, 169, 180, 101, 190, 229, 180, 109, 223,
     229, 179, 100, 190, 233, 179,  99, 191, 229, 179,  91,  63, 196, 181,  90, 165,
     192, 181,  80,  14 };

const byte Sound_C3_PROFONDEUR [188] PROGMEM = {
       0, 188,  47,  47,  84, 181, 136,   0,  17, 176,   4, 176, 129, 180, 164,  58,
     133, 175, 196,  64, 134, 176, 188,  32, 150, 169, 115, 175, 228, 168, 124, 175,
     229, 167, 116, 195, 148, 170, 116,  61,  68, 213, 124, 183,   0, 213, 149, 176,
      20, 214, 173, 208,  84, 180, 141, 240, 148, 167, 107,  36, 169, 167, 115, 190,
     153, 166, 124, 189, 149, 166, 132, 190,  84, 168, 132, 190, 153, 171, 125,  62,
     170, 174, 125, 190, 219, 176, 109, 186, 157, 174,  67,  62, 132, 173,  66, 187,
      65, 160,  96,  48, 161, 215,  85,  16,  82, 181,  69,  42, 169, 180, 109, 191,
     170, 179, 101, 185, 169, 179, 126, 190, 233, 179, 142, 191, 254, 179, 142, 222,
     250, 179, 150,  63, 249, 179, 150,  32, 249, 179, 141, 191, 232, 179, 133, 160,
     233, 179, 133, 192, 232, 179, 133,  64, 248, 179, 132, 191, 248, 179, 132, 192,
     232, 178, 132,  63, 200, 173, 139,  32, 169, 177,  91,  32, 169, 176, 115,  32,
      54, 176,  59,  32,  33, 176,   3,  38,  33, 176, 136,  14 };

const byte Sound_C3_PULLOVER [140] PROGMEM = {
       0, 140,  47,  47,  88, 182,  88,   0, 133, 151, 253, 176, 133, 151, 253, 144,
      21, 151,   5, 143, 165, 150,  77, 143, 235, 117,  85, 175, 166, 150,  86,  45,
     185, 150,  69,  58, 169, 149,  85, 189, 165, 181, 102, 160, 102, 179, 119, 188,
     235, 177, 119,  91, 175, 177, 118, 186, 251, 176, 110,  60, 170, 176, 101, 188,
     149, 177,  84,  62,  64, 182,  68,  94, 165, 179, 108, 160, 153, 179, 109, 161,
     233, 180, 134, 160, 169, 181, 142, 221, 250, 181, 151,  95, 250, 181, 142, 160,
     229, 181, 142,  63, 233, 181, 125, 192, 245, 182, 133,  64, 213, 183, 125,  95,
     212, 182, 116, 192, 216, 182, 100,  63, 232, 150,  92,  62, 176, 183, 107, 160,
     149, 150, 115, 192,  85, 150, 115,  38, 101, 181, 112,  14 };

const byte Sound_C3_ROBE_DE_CHAMBRE [204] PROGMEM = {
       0, 204,  42,  47,  18, 170,  40,   0,  64, 171, 122, 146, 165, 172, 115,  47,
     165, 172, 124, 163, 170, 172, 133,  36, 187, 173, 142,  66, 175, 173, 125, 163,
     255, 173, 108,  32, 166, 172,  74, 191, 150, 171,  90,  62, 150, 173,  72,  62,
     140, 177,  64, 112, 149, 182,  51,  51, 107, 180,  35, 164, 171, 180,  77,  38,
     239, 180,  94,  32, 235, 180, 110,  95, 229, 179, 100, 188, 193, 180,  92,  63,
     145, 187,  84, 190,   5, 183, 253, 176,  20, 218, 101, 208,  20, 218,  61,  80,
       0, 219,   5, 208,  36, 218, 253,  80,   8, 148, 243, 176, 128, 180, 107, 159,
     150, 177, 124, 188, 102, 175, 124, 189, 166, 173, 124,  62, 102, 172, 107, 191,
      86, 170, 124, 223, 103, 170, 132,  64, 162, 170, 123,  63, 209, 169, 122, 159,
     167, 169, 106, 160, 167, 168, 114, 191, 155, 168, 114,  32, 102, 169,  90, 160,
      85, 167, 106, 192,  89, 167, 106, 164,   0, 147,   0,  80, 102, 176, 104, 112,
     102, 175, 115,  58,  22, 174, 107, 160, 104, 174, 148, 208, 169, 174, 139, 130,
     165, 174, 115,  63,  97, 142,  18, 160,  97, 142,  16,  15 };

const byte Sound_C3_SHORT [104] PROGMEM = {
       0, 104,  47,  47,  84, 182,  88,   0,  32, 217,   6,  80,  32, 217,   6,  80,
      64, 186, 254,  80,   5, 185, 254, 112, 148, 179, 108, 172, 230, 146, 125, 190,
     166, 145, 142,  63, 170, 175, 158,  94, 170, 174, 158,  93, 185, 174, 148, 188,
     170, 174, 124,  32, 118, 173, 124,  48,  86, 175, 140,  80,  37, 174,   5, 176,
      53, 174,   5, 176,  26, 175, 174,  48,  86, 211, 157,  48,  17, 179,   0,  48,
      81, 213,  96,  80,  81, 213,  96, 112,  81, 213,  96, 112,  21, 214,   5, 176,
      21, 180, 253, 176,  21, 180, 248,  10 };

const byte Sound_C3_SOUS_VETEMENT [152] PROGMEM = {
       0, 152,  47,  47, 198, 184,  80,   0,  91, 215, 100, 112,  11, 214,   4, 240,
      27, 213,   4, 240, 146, 181,  75, 143, 151, 177,  84, 175, 215, 175,  84,  39,
     251, 172,  75, 223, 167, 173,  75,  61, 213, 142,  66,  59, 145, 174,  57, 184,
     149, 180, 100,  38, 233, 180, 125, 160, 233, 181, 134, 160, 229, 182, 142, 190,
     244, 182, 126,  62, 228, 182, 116, 189, 148, 182,  88,  17, 208, 183, 128,  80,
     148, 215, 136, 112,  85, 215, 156, 144,   5, 215, 125,  48,   4, 217, 125,  48,
      69, 180,  48,  48, 128, 171,  58, 167, 136, 179,  59, 188, 140, 177,  59, 220,
     220, 176,  51,  62, 216, 174,  58, 191, 164, 174,  99,  61, 164, 174, 115, 160,
     181, 173, 132,  64, 181, 173, 131, 190, 165, 172, 123,  32, 101, 171, 115,  64,
     166, 170,  98,  36, 151, 170, 104,  12 };

const byte Sound_C3_SURFACE [116] PROGMEM = {
       0, 116,  43,  47, 168, 181, 136,   0,  26, 214,  69, 176,  10, 215, 165, 112,
      26, 218,   5, 112, 215, 150,  77,  71, 218, 146,  92, 190, 213, 176,  83, 191,
      66, 208,  75,  48,  64, 181, 243,  48,  64, 214, 131, 176,  27, 180, 221, 176,
      11, 181, 213, 208,  27, 181,   5, 240,  27, 181, 101, 176, 169, 177, 133, 162,
     233, 177, 150, 177, 249, 178, 166, 188, 248, 178, 174,  94, 184, 179, 166,  32,
     168, 179, 157, 190, 168, 180, 140, 190, 168, 181, 124,  35, 164, 181, 123, 144,
      88, 214, 148, 176,  26, 214, 148, 240,  26, 214, 148, 240,  26, 214,  92, 240,
     149, 211,  88, 192 };

const byte Sound_C3_TABLIER [124] PROGMEM = {
       0, 124,  47,  47,   0, 214,  88,   0,   0, 215, 197, 144,  80, 214, 125,  15,
     248, 182, 134,  47, 168, 181, 151,  65, 164, 181, 142, 191, 212, 146, 117,  57,
      64, 150,  99,  61, 144, 150, 120,  32,  64, 182,  72,  80, 144, 150,  84, 191,
     249, 150,  77, 160, 181, 183,  61, 160, 242, 183,  53, 191, 246, 215,  45,  62,
     228, 216,  61, 160, 244, 217,  53, 189, 232, 249,  53,  95, 228, 249,  44, 188,
     232, 249,  52,  62, 216, 249,  35, 222, 216, 249,  43, 223, 212, 217,  43, 190,
     228, 217,  60,  64, 230, 216,  68,  63, 225, 184,  76, 192, 208, 185,  76,  95,
     208, 216,  76,  63, 209, 186,  67,  39, 225, 185,  72,  13 };

const byte Sound_C3_VERRE [104] PROGMEM = {
       0, 104,  47,  47,  73, 181,  24,   0,  69, 182,  51,  63,  65, 183,  59,  34,
      90, 180,  76,  38, 165, 179, 117,  40, 233, 180, 142, 163, 233, 180, 151,  32,
     249, 181, 159, 160, 248, 182, 151, 192, 248, 182, 151,  62, 244, 182, 143,  61,
     248, 182, 143,  93, 249, 183, 134, 221, 233, 183, 134,  61, 233, 183, 134,  62,
     233, 183, 133, 190, 233, 183, 125,  63, 233, 183, 117,  64, 233, 183, 108, 191,
     232, 182,  99, 160, 232, 182, 107, 191, 213, 181, 115,  32, 165, 180, 107,  32,
      97, 211, 106, 162,  97, 179,  88,  14 };

const byte Sound_C3_VESTE [92] PROGMEM = {
       0,  92,  47,  47,  81, 215,  64,   0,  21, 182,  28,   4,  85, 180, 101,  36,
     249, 181, 134, 162, 249, 182, 143, 194, 248, 183, 127,  64, 232, 183, 118,  60,
     228, 183, 117,  62, 229, 183, 101,  59, 102, 215,  69, 144,  70, 214, 109, 240,
       6, 214, 101, 240,  64, 214,  96, 112,  64, 214,  96, 112,   0, 215, 156, 176,
     145, 181, 107, 144, 210, 180,  91,  17, 212, 179, 107,  59, 208, 179, 123,  63,
     132, 176, 114, 191, 136, 166, 114, 141, 129, 178, 112,  14 };

const byte Sound_C3_VOLUME [140] PROGMEM = {
       0, 140,  47,  47,  68, 183,  16,   0,   1, 150, 251, 183,  21, 181,   4,  47,
      81, 174,  68, 162, 166, 174, 109, 166, 230, 175, 110,  35, 230, 177, 110, 161,
     148, 180, 119,  32, 160, 148, 102, 189, 160, 149,  78,  63, 180, 150,  61, 188,
     181, 150,  69,  61, 165, 183,  61, 189, 229, 183,  70,  32, 229, 184,  62,  63,
     224, 216,  53, 191, 224, 217,  61, 191, 240, 184,  61,  94, 160, 183,  53,  63,
     200, 152,  51,  62, 200, 149,  51, 192, 204, 149,  44,  63, 204, 180,  52,  63,
     156, 180,  52,  64, 204, 179,  43, 160, 157, 178,  52, 192,  89, 178,  69,  62,
     181, 178,  85,  32, 181, 178,  84, 160,  84, 178,  67, 190,  97, 179,  43, 160,
      97, 179,  75,  35,  81, 179,  74, 162,  81, 178,  72,  14 };

const byte Sound_C3_ABRICOT [116] PROGMEM = {
       0, 116,  47,  47, 164, 181, 152,   0, 164, 181, 165, 172, 164, 181, 166, 160,
     164, 181, 167,  32, 164, 180, 151,  35, 165, 177, 125, 191, 136, 180,  76,  63,
     128, 176,  91,  64, 166, 175,  75, 223, 165, 211,  76,  94, 145, 214,  84, 162,
     213, 185,  77,  66, 208, 217,  60, 191, 145, 218,  42, 189, 192, 182,  72, 112,
      64, 152, 248, 112,  96, 176, 252, 176,  32, 174, 180,  48, 144, 152, 250, 144,
      64, 179,  91,  23, 129, 174, 100,  61, 133, 171, 124,  95, 137, 171, 116,  63,
     197, 171, 116,  62, 193, 170,  99, 160, 197, 169, 107, 190, 213, 169,  99,  63,
     225, 169,  88,  13 };

const byte Sound_C3_AUTOROUTE [152] PROGMEM = {
       0, 152,  47,  47,  84, 179, 112,   0, 235, 176, 116, 175, 171, 175, 118,  37,
     171, 175, 118,  65, 230, 176, 117, 161, 134, 211,  76, 192, 196, 207,  90,  32,
     193, 175,  96,  48, 197, 216, 104,  80,  21, 181,   6, 176, 229, 175, 109,  64,
     170, 173, 117, 220,  70, 169, 125, 223,  70, 167, 125,  62,  35, 162, 100, 189,
      71, 161, 131, 185, 130, 196, 106, 190, 131, 200,  90, 160, 131, 148, 130,  32,
     131, 169,  98, 187, 129, 148,  99,  64,  64, 203,  92,  64,  64, 209,  75, 223,
     132, 180,  75,  60, 148, 180,  50,  32, 144, 213,  80,  80, 144, 213,  80, 112,
       0, 180, 120, 112,   0, 215, 237,  48,  17, 214, 156, 176,  86, 180,  84, 176,
     217, 179,  98, 134, 197, 174, 122, 192, 149, 178, 114, 221, 149, 178,  98,  38,
      89, 178,  89, 164,  85, 179,  48,  10 };

const byte Sound_C3_BANANE [136] PROGMEM = {
       0, 136,  47,  47, 128, 179,  24,   0, 212, 179, 117,  19, 232, 179, 142,  15,
     249, 180, 167, 169, 232, 181, 167,  67, 178, 182, 158, 163, 176, 150, 141,  32,
     162, 149,  99, 160,  67, 116,  83, 161, 136, 179,  59, 219, 164, 182, 118,  58,
     164, 214, 150, 187, 164, 181, 159,  63, 164, 181, 175,  63, 181, 180, 183,  95,
     101, 181, 158, 192, 164, 181, 150, 190, 180, 181, 134,  32, 228, 181, 125, 191,
     168, 181,  84,  63, 140, 180,  59, 160, 140, 179,  59, 160, 204, 179,  51, 192,
     140, 181,  59, 192, 136, 181,  68,  64, 168, 180,  92,  32, 186, 180, 132,  64,
     181, 180, 131, 191, 181, 180, 131,  62,  97, 148,  98, 160,  85, 146, 106, 160,
      85, 146,  82, 140,  17, 177,   0,  12 };

const byte Sound_C3_BEEFSTEAK [112] PROGMEM = {
       0, 112,  47,  47, 192, 145,  48,   0, 196, 146,  49, 129, 166, 183,  77, 175,
     250, 215,  70,  40, 246, 216,  77, 169, 213, 216,  76, 163, 213, 184,  52,  32,
     169, 183,  68,  16,  37, 183,  69,  48,  17, 185,  85,  80, 193, 183,  80,  48,
      84, 214,  88, 112,  37, 182, 156, 176, 150, 182, 131, 144, 233, 182, 116,  17,
     254, 181, 126,  49, 250, 182, 142,  87, 245, 182, 141, 160, 229, 183, 117,  64,
     229, 152, 100, 190, 205, 152, 107,  32, 208, 152, 104, 112,   1, 185, 248, 112,
       8, 217, 196, 176,   8, 220, 115,  48,   5, 217,   2,  32,   5, 185,   0,  14 };

const byte Sound_C3_BIERE [92] PROGMEM = {
       0,  92,  47,  47,  64, 152,  64,   0,  65, 134,  60, 144,  85, 216,  62,  48,
     217, 217,  54,   0, 245, 216,  53, 162, 227, 216,  61, 164, 228, 216,  77, 164,
     244, 216, 118, 193, 244, 183, 142, 223, 244, 183, 150, 221, 248, 183, 134, 254,
     244, 183, 133,  61, 245, 183, 117,  95, 224, 184, 100, 192, 233, 151, 108,  95,
     217, 151,  91, 191, 128, 150,  99,  32, 165, 180,  83,  64, 165, 180,  83,  32,
     165, 180,  83,  96, 106, 177,  56,  10, 106, 177,  56,  14 };

const byte Sound_C3_BLANC [68] PROGMEM = {
       0,  68,  47,  47, 197, 149,  24,   0, 169, 148,  86,  34, 168, 181,  94, 189,
     172, 180,  86,  32, 168, 180,  94,  64, 228, 178, 142, 161, 166, 176, 159,  32,
     162, 173, 158, 192, 130, 172, 158,  66,  18, 167, 174,  35,  82, 169, 141,  36,
      82, 169, 124,  32, 165, 200,  99, 161,  16, 164,  98, 160,  64, 197, 106,  23,
      16, 192,   0,  17 };

const byte Sound_C3_BLEU [60] PROGMEM = {
       0,  60,  47,  47, 192, 182,  24,   0,  20, 149,  29, 164, 100, 180,  86, 160,
      20, 181,   6, 160, 100, 181,  62, 160, 100, 181,  62,  32, 100, 181,  30,  63,
     168, 180,  94, 161, 165, 179, 111,  64, 166, 179, 102, 193, 214, 179, 102,  67,
     229, 178, 108, 166, 213, 177,  67, 181, 130, 145,  64,  18 };

const byte Sound_C3_BOEUF [80] PROGMEM = {
       0,  80,  47,  47, 208, 178,  16,   0,  81, 182,  19, 144,  81, 181, 101, 139,
     234, 179, 134, 168, 234, 178, 143,  34, 229, 179, 151, 161, 228, 179, 151,  64,
     230, 147, 134, 221, 213, 178, 134,  58, 214, 146, 125,  63, 150, 181, 132, 208,
      85, 182, 149, 176, 150, 183, 142,  48, 234, 183, 149, 176,  85, 183, 133, 176,
     101, 183, 125,  80,  86, 182, 116, 176,  16, 182,  60, 208,  16, 182,  56,  25 };

const byte Sound_C3_CAFE [84] PROGMEM = {
       0,  84,  47,  47, 192, 215,  80, 128,   4, 182, 199,  48,   8, 183, 141, 143,
     224, 184, 110,  43, 229, 183, 135,  32, 229, 182, 143,  95, 213, 149, 117, 190,
     149, 181,  85,  63, 234, 182, 133, 208, 106, 182, 157, 112,  90, 183, 108, 240,
     209, 182, 100,  17, 229, 182, 109, 187, 228, 182, 109,  60, 229, 183, 109,  63,
     229, 184, 101, 223, 228, 184,  92, 191, 224, 185,  90, 160, 240, 185,  82, 160,
     224, 185,  80,  14 };

const byte Sound_C3_CAMPAGNE [124] PROGMEM = {
       0, 124,  47,  47, 144, 215, 136,   0,  64, 117, 252, 144,  33, 179, 190,  48,
      90, 174, 150,  73,  91, 169, 165, 193,  90, 166, 140, 193,  89, 166,  84,  62,
      72, 173,  74, 177,  84, 173,  90,  49,  81, 186, 128, 112,   1, 153, 100, 144,
      89, 177, 149, 171, 170, 178, 175,  61, 252, 179, 190, 223, 186, 180, 183,  94,
     185, 181, 174,  95, 185, 182, 141, 191, 184, 182, 108, 190, 152, 181,  67, 160,
     104, 182,  75,  63, 114, 183,  74, 160, 132, 116,  50,  64, 136, 118,  58, 192,
     128, 218,  75, 224, 132, 185, 100,  64, 169, 182, 100,  64,  80, 182,  99, 191,
      64, 152, 115,  32,  68, 151, 106,  15,   5, 180,  72,  15 };

const byte Sound_C3_CHOCOLAT [100] PROGMEM = {
       0, 100,  47,  47,  21, 185, 248,   0,  17, 186, 253, 176,  26, 186, 253, 176,
      17, 219, 253, 208,  17, 219, 253, 240,  16, 219, 253, 176, 170, 144, 117, 204,
     231, 141,  92, 190, 146, 141,  66, 191, 213, 141,  80,  48,  65, 173, 112,  80,
      65, 143, 181,  48,  16, 141,   4,  48, 150, 142, 100, 131, 215, 142, 117, 160,
     235, 144, 118, 189, 100, 148, 119,  92, 100, 149,  78,  60, 239, 180,  94,  94,
     238, 180, 118, 188, 248, 180, 142, 186, 228, 180, 158,  32, 233, 178, 173, 224,
     170, 178, 168,  13 };

const byte Sound_C3_CITRON [96] PROGMEM = {
       0,  96,  47,  47, 166, 215,  88,   0, 149, 215,  94, 144, 133, 216, 102,  48,
      13, 184, 134, 240,  29, 217, 127,  48, 237, 216,  71,  47, 245, 216,  71,  70,
     228, 216,  62,  60, 192, 216,  60,  49, 192, 216,  56,  16,  17, 216, 104, 112,
      20, 216, 191,  16,  18, 181, 255, 176,  16, 210,   6, 176,  18, 207,   5,  48,
      65, 181, 189,  80, 134, 177, 124,  48,  42, 162, 133,  59, 137, 162, 149, 222,
     134, 169, 135, 224, 136, 173, 125,  59, 136, 170, 115, 191,  65, 183, 136,  14 };

const byte Sound_C3_CLEMENTINE [148] PROGMEM = {
       0, 148,  47,  47,  64, 182, 120,   0,  20, 183, 222, 176,  16, 218, 119,  48,
     164, 215,  86,  43, 228, 183,  78, 161, 229, 183,  78, 195, 228, 184, 119, 195,
     212, 182, 118, 162, 152, 178,  77,  34, 152, 176,  85,  65, 132, 176, 117, 190,
     161, 173, 134,  95, 145, 173, 125, 192, 152, 174, 101, 221, 137, 173,  76,  54,
     132, 175,  67,  61,  69, 172,  64,  16,  64, 181, 104, 112,   4, 214, 173, 176,
      13, 217,  77, 208, 201, 215,  61,  37, 248, 216,  61, 218, 244, 248,  53,  61,
     228, 216,  44, 189, 212, 218,  68, 160, 196, 217,  59, 160, 161, 151,  68,  62,
     168, 183,  76, 223, 168, 182,  68,  64, 220, 181,  60, 223, 204, 178,  68,  64,
     249, 181, 124,  64, 181, 180, 131, 192, 164, 179, 115,  37,  84, 179, 115,  32,
      20, 178, 112,  14 };

const byte Sound_C3_CORNICHON [120] PROGMEM = {
       0, 120,  47,  47,  16, 217, 248,   0,  16, 217, 254, 144, 136, 184, 134, 144,
     136, 184,  86, 144, 136, 184,  94,  16, 150, 177, 126, 175, 150, 174, 151,  70,
     134, 173, 150, 191,  83, 171, 141, 190, 162, 171, 116, 161, 149, 174, 125,  65,
     136, 175,  92,  64, 213, 208,  76, 255, 213, 207,  76,  63, 128, 216,  76, 222,
      89, 184,  53, 189,   1, 184,   6, 144,  18, 185, 255,  48,  70, 185, 255,  80,
      20, 217, 254, 240,  49, 185, 253, 208,   1, 149,   5,  17, 149, 145, 125, 222,
      69, 169, 149,  93,  37, 165,   4, 222,  20, 164, 107, 160,  32, 160,   2, 191,
     129, 183, 138,  32,  65, 183, 120,  15 };

const byte Sound_C3_ESCARGOT [128] PROGMEM = {
       0, 128,  47,  47, 148, 182,  80,   0, 144, 215, 127, 201, 228, 183, 127,  38,
     232, 215, 118,  34, 165, 215,  93, 185, 213, 183,  85,  59, 244, 215, 125, 176,
      33, 214,  93, 208,  16, 214, 109, 176, 192, 184, 120,  80,  24, 151, 167, 176,
     196, 183, 101, 175, 208, 182, 135,  33, 161, 148, 159, 219, 144, 146, 150, 190,
     149, 143, 150,  63, 145, 142, 133, 191,  82, 173, 117,  62, 166, 176,  92, 190,
      98, 177,  76, 191,  87, 177,  76,  16,  17,  80,   4,  48, 128, 211,  56, 112,
      32, 207, 124, 178,  65, 174,  76,  32, 133, 171, 101,  64, 149, 170,  92,  61,
      69, 168, 124, 191, 129, 167, 100, 192, 225, 200,  90, 160, 209, 166,  80,  14 };

const byte Sound_C3_FLEUVE [104] PROGMEM = {
       0, 104,  47,  47,  16, 182,   0,   0,  21, 181,   5,  48,   2, 118, 253, 112,
      16, 182,   5, 240,  96, 150,  84, 143, 100, 180,  85,  37, 168, 180,  77, 160,
     104, 180, 110, 160, 234, 180, 143, 192, 186, 180, 151, 221, 254, 180, 143,  93,
     169, 180, 134, 222, 173, 180, 125, 222, 169, 179, 100, 192, 233, 179, 100,  62,
     168, 179,  83,  64, 133, 181,  66, 223,  69, 181,  50, 224,  85, 180,  83,  64,
      89, 178, 107, 160, 105, 178, 131, 160, 154, 178, 123, 192, 105, 178, 107,  95,
     125, 178,  98, 140, 101, 179, 104,  15 };

const byte Sound_C3_FRAISE [100] PROGMEM = {
       0, 100,  47,  47, 165, 180, 144,   0, 154, 181, 140,  16,  74, 183, 173,  48,
      10, 181, 197,  80,  26, 178, 221, 112,  42, 179, 124, 240, 168, 180, 124, 143,
     233, 181, 134,  37, 169, 181, 151,  32, 180, 182, 159,  64, 248, 182, 159,  94,
     244, 183, 151,  94, 248, 183, 134, 222, 248, 183, 126,  94, 249, 183, 118,  95,
     248, 182, 109,  95, 232, 182, 100,  95, 229, 182,  58, 223, 129, 182,  90, 192,
     149, 182,  66, 224, 165, 179, 114, 192, 128, 180,  58,  33,  80, 147,  48,  15,
      80, 147,  48,   6 };

const byte Sound_C3_FROMAGE [132] PROGMEM = {
       0, 132,  47,  47, 218, 181,  96,   0, 154, 181, 100,  16,  26, 181, 100,  48,
      26, 178, 108, 240,  42, 166, 116, 240, 210, 202, 123,  47, 199, 171, 124, 162,
     163, 171, 126,  66, 170, 172, 117, 160, 153, 175,  93, 191, 152, 175,  69,  32,
     157, 178,  61,  92, 169, 176,  86,  32, 102, 177, 167, 186, 165, 177, 167,  61,
     165, 178, 175,  94, 165, 178, 183,  95, 168, 179, 174, 223, 169, 179, 158,  95,
     165, 179, 125, 192, 165, 179, 125, 223,  84, 180, 125, 208,  69, 181, 117,  62,
      73, 185,  29, 176,  85, 185,  85, 208, 100, 217,  93, 160,  68, 180, 117,  33,
      84, 180, 133,  64,  84, 179, 132, 190,  84, 179,   2, 164,  80, 179,   8,  15,
      80, 179,   8,   1 };

const byte Sound_C3_GATEAU [80] PROGMEM = {
       0,  80,  47,  47, 144, 184,  64,   0, 136, 182,  59, 144,   8, 183,   4, 143,
     229, 185, 102,  38, 229, 184, 127,  35, 241, 183, 151, 161, 244, 182, 151,  34,
     224, 182, 142,  33, 208, 183,  92,  32, 144, 184, 128, 112, 217, 214, 136, 112,
      25, 215, 157,  16,  20, 214,  69,  48, 145, 213,  92, 145, 129, 178, 109, 217,
     209, 173,  99, 188, 149, 170,  91,  63, 133, 168,  90, 191, 213, 168,  80,  14 };

const byte Sound_C3_HUITRE [100] PROGMEM = {
       0, 100,  47,  47, 145, 218,  64,   0, 224, 216,  66, 173, 230, 151,  67, 163,
     230, 151,  69,  32, 230, 151,  69, 163, 197, 215,  78,  32, 197, 215,  78,  64,
     192, 218,  69, 219, 209, 216,  69,  61, 192, 216,  80, 112, 128, 179,  72, 112,
      32, 182, 253, 176,  33, 182,   6,  48,  64, 184, 253, 208,  33, 180, 165,  80,
     144, 179, 116, 184,  85, 178, 140,  61,  85, 177, 148,  61, 106, 177, 148,  95,
     165, 177, 131, 190,  97, 177, 123,  32, 101, 177,  74,  36,  84, 176, 104,   7,
      84, 176, 104,   9 };

const byte Sound_C3_JAMBON [104] PROGMEM = {
       0, 104,  47,  47,  84, 180,  96,   0,  84, 180,  97,  18,  84, 181,  91,  32,
      97, 185,  92, 160, 100, 217,  85, 160, 101, 217,  78,  16, 101, 217,  94,  80,
       4, 151, 174, 175,  80, 175, 142, 195,  64, 169, 166,  67, 129, 180, 149, 196,
     196, 203, 125, 223, 136, 174,  93,  62, 216, 176,  60,  59, 200, 173,  59,  59,
     204, 173,  50, 188, 153, 171,  32,  16, 148, 168,  48,  48,  81, 213,  77,  52,
     170, 171, 108, 165, 158, 170, 141, 223, 137, 168, 149, 222, 132, 199, 132, 223,
     132, 202, 115,  62, 130, 149, 128,  14 };

const byte Sound_C3_LAIT [64] PROGMEM = {
       0,  64,  47,  47, 116, 182,  64,   0, 180, 150,  60, 185, 180, 182,  61,  32,
     252, 182,  69,  65, 253, 182,  69, 193, 254, 182,  70,  65, 255, 182,  77, 163,
     182, 182,  69, 161, 249, 183, 119,  37, 249, 183, 127, 192, 245, 184, 119, 223,
     245, 184, 119,  60, 245, 184, 102, 188, 228, 152,  92,  63, 224, 184,  88,   6 };

const byte Sound_C3_MARRON [100] PROGMEM = {
       0, 100,  47,  47, 200, 173,  40,   0, 140, 180,  43, 191, 140, 178,  44, 193,
     220, 177,  45, 194, 166, 176, 150,  36, 165, 177, 190,  32, 164, 177, 190, 160,
      84, 177, 190, 129,  80, 177, 182,  33,   0, 177, 205, 160,  96, 176, 125, 191,
      85, 174, 101,  63,  21, 172,   4, 160,  22, 172,   3, 222,   5, 167,   3,  95,
     150, 169, 114, 190, 158, 168, 131, 190, 137, 168, 141,  95, 137, 166, 148, 160,
     132, 167, 125,  64, 132, 198, 124, 193, 129, 165, 116,  34, 130, 165, 107,  32,
     129, 133, 112,  31 };

const byte Sound_C3_MER [76] PROGMEM = {
       0,  76,  47,  47, 122, 180, 104,   0, 156, 182,  52, 192, 156, 182,  61,  66,
     170, 181,  69, 166, 166, 181, 134, 129, 181, 182, 159,  33, 180, 182, 159, 161,
     184, 183, 159, 192, 184, 183, 151,  94, 185, 183, 143,  92, 185, 183, 142, 187,
     185, 183, 134,  95, 186, 183, 134,  95, 186, 183, 133,  95, 164, 183, 108,  64,
     152, 183,  99, 160, 149, 183,  99,  35, 213, 183,  96,  15 };

const byte Sound_C3_MONTAGNE [144] PROGMEM = {
       0, 144,  47,  47, 105, 178,  64,   0,  88, 178,  60,  29,  28, 177,   5,  33,
      72, 179,  52, 161,   8, 178,   5,  36, 137, 174, 133,  35, 133, 172, 141, 162,
     134, 173, 149,  68, 138, 173, 124, 162,  73, 170, 116,  32,  69, 181,  76,  63,
      36, 161,   0,  48,  20, 215,   0, 112,  85, 215, 165, 176, 148, 181, 108,  17,
     169, 180, 150,  32, 185, 180, 175,  54, 186, 180, 183,  61, 106, 180, 191,  32,
     121, 181, 174, 223, 112, 181, 141, 191, 164, 182, 125,  62, 229, 182, 108, 190,
     148, 181,  67, 161, 212, 182,  59, 160, 160, 215,  68,  63, 160, 119,  59, 192,
     136, 116,  58, 192, 146, 216,  58, 192, 129, 215,  67,  63, 129, 218,  83, 160,
     185, 182,  59, 224, 145, 181,  91,  32,  89, 180, 106,  35, 101, 180,  56,  14 };

const byte Sound_C3_MOULE [96] PROGMEM = {
       0,  96,  47,  47,  88, 179,  32,   0,  72, 179,  41, 153, 136, 180,  58, 161,
     136, 180,  43, 163, 136, 180,  44,  36, 136, 181,  45,  35, 136, 180,  53,  39,
     136, 178,  77, 161, 136, 171, 109, 161,  72, 168, 125, 193, 136, 139,  93, 255,
      73, 138, 102,  58,  85, 145,  54,  92, 164, 149,  77, 222, 232, 181,  85, 223,
     252, 181,  94,  95, 189, 180, 101, 192, 253, 180, 133, 192, 250, 180, 141,  62,
     250, 180, 148, 192, 249, 179, 140,  32, 228, 178, 138, 163, 228, 178, 136,  95 };

const byte Sound_C3_MOUTARDE [128] PROGMEM = {
       0, 128,  47,  47, 105, 178, 112,   0, 140, 183,  52, 192, 140, 181,  53,  69,
     130, 153, 109,  39, 136, 177,  93, 163, 142, 176,  77,  34, 198, 177,  68,  32,
     132, 211,  59, 191, 193, 183,  64,  48, 192, 213,  72, 112,  20, 215, 222,  48,
     165, 181, 117, 186, 229, 180, 158, 220, 165, 179, 182, 221, 165, 178, 182, 255,
     165, 178, 174, 223, 165, 177, 166,  62, 166, 176, 149,  33,  98, 175, 124,  48,
      22, 173,  51, 144,  37, 174,   5, 176,  17, 175,   4, 176, 128, 179, 108,  32,
     144, 178,  75, 187, 128, 179,  40,  80,  81, 182,  59, 163, 152, 180,  99, 161,
     144, 180, 123, 192,  20, 178,  43,  64, 165, 180,  34, 160,  97, 180,   0,  14 };

const byte Sound_C3_MOUTON [92] PROGMEM = {
       0,  92,  47,  47, 153, 178,  48,   0, 216, 177,  43,  62, 216, 178,  35, 160,
     136, 180,  44, 162, 200, 178,  52, 198, 130, 185,  85,  37,  77, 172,  85,  67,
     138, 140,  76,  33, 193, 178,  67, 190, 196, 179,  58, 191, 196, 179,  72, 112,
     128, 213,  64, 112,   5, 180, 252, 144,   1, 214, 190, 176, 150, 178, 118,  54,
     134, 173, 134,  93, 150, 169, 141, 188, 136, 166, 141,  62, 132, 160, 124,  95,
      16, 160,  35,  63, 129, 183,  74, 191,  36, 160,   0,  10 };

const byte Sound_C3_NOIR [100] PROGMEM = {
       0, 100,  49,  47, 140, 180,  32,   0, 200, 182,  35,  63, 220, 180,  44, 160,
     156, 180,  45,  32, 140, 180,  53,  97, 168, 177, 101, 193, 136, 171, 117, 192,
     136, 164, 141, 192, 153, 172, 141, 223, 166, 173, 142,  63, 166, 175, 158, 191,
     166, 176, 167,  63, 182, 176, 183,  96, 101, 176, 174, 223, 101, 176, 174, 192,
     101, 176, 166, 194, 101, 175, 158,  38, 180, 176, 141, 165, 160, 176, 116, 160,
     160, 175,  99, 160, 160, 176,  83,  32,  85, 175,  26, 192,  80, 176,  42,  59,
      97, 176,  58,  93 };

const byte Sound_C3_OEUF [60] PROGMEM = {
       0,  60,  47,  47, 169, 181,  72,   0, 230, 181, 124, 170, 230, 181, 141, 161,
     166, 180, 142, 160, 166, 180, 143,  32, 166, 180, 143,  96, 230, 180, 135,  60,
     230, 180, 118, 188, 209, 180, 109,  58, 154, 181, 109,  48,  86, 182, 142, 112,
      90, 184, 166, 112,  26, 182, 157, 208,  21, 180, 120,   6 };

const byte Sound_C3_OLIVE [112] PROGMEM = {
       0, 112,  47,  47, 149, 173, 112,   0, 149, 175, 115, 143, 149, 175, 124, 139,
     153, 176, 117, 131, 170, 176, 117, 131, 170, 177, 118,  36, 149, 147, 110, 162,
     160, 150,  79,  32, 245, 182,  70,  95, 249, 183,  62,  91, 245, 216,  54, 190,
     244, 216,  54, 223, 244, 217,  46, 223, 248, 217,  46,  61, 244, 217,  53, 191,
     244, 216,  53, 223, 224, 183,  60, 222, 213, 151,  60,  62, 150, 150,  36,  32,
     213, 149,  40,  48,  69, 179,  32, 112,  85, 179, 101,  64, 169, 179, 124, 158,
     232, 179, 140, 192, 149, 178, 132,  62,  85, 177,  83, 194,  84, 178,  72,  14 };

const byte Sound_C3_ORANGE [140] PROGMEM = {
       0, 140,  47,  47, 229, 181, 112,   0, 213, 178, 123,  41, 229, 176, 125,  34,
     229, 176, 126,  64, 234, 173, 134,  65, 166, 172, 133, 160, 234, 171, 132, 190,
     166, 172, 107, 186, 145, 203,  99,  32,  81, 204,  99,  16,  69, 174,  67, 176,
     150, 172, 116,  62, 166, 173, 124, 160, 102, 173, 149,  32, 162, 173, 157,  64,
     163, 172, 149,  64,  87, 172, 157,  95, 150, 172, 149,  95,  86, 169, 157,  61,
      25, 166, 164, 223,  72, 165, 164, 192,  72, 170, 148, 223,  68, 177, 140, 192,
      81, 147, 132,  63,  16, 180, 116,  64,  16, 218, 100,  32, 164, 217, 100,  64,
      69, 217,  92,  64,  68, 218, 100,  32,  85, 179, 124,  64,  84, 178, 123, 192,
      84, 178, 122, 128,  68, 178, 114,   7,  68, 178, 112,  11 };

const byte Sound_C3_PAIN [48] PROGMEM = {
       0,  48,  47,  47, 192, 153,  80,   0,  81, 151, 158,  48, 170, 177, 134,  47,
     238, 177, 151,  33, 165, 178, 167, 192, 165, 178, 159, 222, 145, 178, 159,  92,
     160, 178, 150,  60,  80, 178, 100, 188, 145, 145,  75, 189,  80, 145,  80,  14 };

const byte Sound_C3_PAMPLEMOUSSE [136] PROGMEM = {
       0, 136,  47,  47, 192, 215,  96,   0, 148, 214, 133, 176,  64, 178, 156, 143,
     170, 172, 133, 175, 227, 172, 141, 194, 165, 169, 133,  64, 137, 170, 124, 160,
      68, 170,  74, 180, 192, 217, 128,  80,   0, 179,   5, 176,   1, 150, 156, 144,
      17, 149, 115, 144, 144, 117,  75, 139, 217, 115,  75, 160, 213, 148, 101,  32,
     238, 147, 110,  94, 170, 146, 101, 188,  89, 145,  69,  62, 136, 179,  60, 222,
     136, 181,  52, 223, 140, 166, 108, 222,  76, 163, 108, 223,  70, 144,  76, 222,
     129, 180,  68,  95,   4, 215,  52, 160,   4, 215,   5, 176,  17, 215,   5, 208,
      20, 215,   5, 112,  20, 215,   5, 112, 137, 180,  99,  31, 212, 179, 106,  32,
     208, 178, 113,  11, 209, 178, 112,   6 };

const byte Sound_C3_PATE [88] PROGMEM = {
       0,  88,  47,  47, 196, 216,  88,   0,  17, 182, 108, 144,  17, 182, 117,  15,
     212, 177, 157, 167, 213, 177, 174,  32, 213, 178, 182, 160, 213, 179, 183,  32,
     165, 179, 191,  93, 165, 179, 182, 221, 160, 180, 141,  93, 128, 150, 152, 112,
      64, 184, 144, 112,   0, 215,   8, 112, 100, 214, 172, 144,  21, 215,  44,  48,
     145, 181,  99, 176, 229, 179, 107, 189, 225, 179, 131, 192, 225, 179, 131,  63,
     165, 179,  90,  64, 133, 179,  96,  15 };

const byte Sound_C3_PECHE [76] PROGMEM = {
       0,  76,  47,  47,  65, 181,  80,   0,  86, 182,  99,  15, 233, 181, 134,  37,
     249, 182, 143,  95, 244, 183, 135,  94, 232, 183, 126, 190, 244, 183, 126,  62,
     224, 151, 125,  60, 160, 182, 100, 190,  85, 217,  94,  80,  37, 218,  94, 112,
      21, 217,  93, 176,  21, 217,  93, 208,  21, 217,  93, 240, 133, 217, 100,  48,
     169, 179, 115,  34,  85, 179, 130, 222,  85, 179, 128,  11 };

const byte Sound_C3_PLAGE [120] PROGMEM = {
       0, 120,  47,  47,  68, 179,  80,   0,   0, 181,  17, 144,   5, 151,   4, 176,
      89, 151,  68,  15, 172, 181,  93,  36, 172, 180, 102,  65, 169, 180, 143,  34,
     169, 180, 167, 160, 169, 180, 183, 223, 169, 180, 183,  61, 169, 179, 191,  94,
     169, 179, 191,  94, 105, 180, 183,  62, 106, 179, 174, 190, 106, 179, 166,  63,
     168, 179, 157, 223, 121, 180, 141,  95, 165, 180, 125,  63, 213, 148, 116,  32,
     208, 180, 107, 160, 149, 181,  99, 191, 144, 214, 100,  63,  26, 186, 124,  15,
      26, 186, 116,  65,  30, 186, 116,  80, 237, 178,  91, 176, 173, 178,  91,  32,
     109, 178,  90, 160, 109, 178,  88,   0 };

const byte Sound_C3_POIRE [104] PROGMEM = {
       0, 104,  47,  47, 128, 212, 128,   0,  68, 213, 149, 176,  64, 181, 124,  15,
      68, 135, 115, 165,  90, 167, 116, 161, 138, 169, 125,  32, 219, 173, 142, 192,
     174, 176, 167,  64, 186, 177, 175,  94, 165, 177, 183,  94, 164, 177, 182, 221,
     164, 177, 174,  95, 164, 177, 173, 223, 164, 177, 165, 223, 170, 177, 165,  95,
     166, 177, 157,  63, 169, 177, 140, 160, 100, 176, 123, 160,  17, 177, 235,  65,
      33, 176, 251, 192, 106, 177,  99,  32, 153, 143, 114, 190, 149, 174, 122,  65,
     168, 176,  89, 160,  20, 177,  56,  15 };

const byte Sound_C3_POMME [92] PROGMEM = {
       0,  92,  47,  47,  81, 214, 128,   0,  17, 181, 141,  16, 149, 178, 124, 143,
     238, 175, 133, 166, 230, 175, 142, 160, 214, 176, 142, 192, 234, 175, 134,  32,
     230, 175, 133, 222, 169, 176, 117,  59,  88, 175,  84, 190, 136, 179,  68, 191,
     136, 180,  60,  58, 136, 180,  68,  95,  76, 179,  52,  32, 156, 178,  59, 192,
     156, 178,  51, 224, 169, 177, 108, 160, 165, 179, 157,  64, 165, 178, 156, 191,
     149, 179, 155, 160,  80, 178,  90, 160,  80, 178, 120,  15 };

const byte Sound_C3_PORC [100] PROGMEM = {
       0, 100,  47,  47,  80, 213,  72,   0,   9, 115, 253,  16,   5, 108, 117,  15,
     251, 175, 125, 173, 239, 174, 142,  32, 235, 175, 150,  63, 234, 175, 150, 223,
     250, 174, 150,  93, 251, 175, 150,  92, 251, 175, 149, 221, 250, 175, 149,  95,
     250, 174, 140, 222, 255, 174, 140, 160, 233, 171, 131, 190, 232, 171, 131,  63,
     160, 172, 115,  32, 149, 171,  99,  32, 130, 172, 115,  64,  18, 174,   3, 160,
      18, 173,   3,   9,  34, 173,   4, 176,  34, 174,   4,  48,  38, 175,  36,  80,
      38, 175,  32,  14 };

const byte Sound_C3_POULET [76] PROGMEM = {
       0,  76,  47,  47, 192, 215,  80,   0,  68, 181, 190,  48,   0, 151, 221,  48,
      16, 181,  60, 176, 128, 117, 100, 175, 133, 140,  76,  39, 234, 142,  76, 160,
     166, 144,  69,  32, 162, 118,  60, 160, 225, 150,  69,  32, 229, 182,  77, 218,
     181, 182,  94, 188, 245, 182, 118, 187, 245, 182, 127,  60, 245, 183, 135,  94,
     245, 183, 126, 223, 245, 183, 126,   9, 229, 183, 104,   9 };

const byte Sound_C3_PRUNE [96] PROGMEM = {
       0,  96,  47,  47,   0, 148, 136,   0,  69, 146, 140,  16,  85, 146, 156, 144,
      25, 174,  68,  37,  82, 206,  75, 161, 134, 177,  91, 160,  86, 178, 101,  37,
     150, 179, 102,  35, 170, 149,  94, 192, 234, 149,  86,  63, 165, 150,  94,  94,
     145, 183,  93, 188, 144, 184,  85,  62, 132, 185,  68, 187, 136, 182,  59, 190,
     152, 183,  59, 190, 156, 182,  67, 224, 156, 182,  67, 223, 140, 179,  67, 223,
     153, 181,  83,  32, 229, 181, 131,  64, 229, 180, 136,  12, 229, 180, 136,   8 };

const byte Sound_C3_RAISIN [108] PROGMEM = {
       0, 108,  47,  47, 165, 175, 120,   0,  18, 175,  83, 178,  34, 206,  84,  31,
      34, 176,  92,  32,  33, 210,   4, 176, 166, 180, 108,  15, 184, 181, 117, 173,
     248, 182, 126, 162, 228, 183, 118, 193, 248, 183,  94,  34, 248, 182,  85, 160,
     248, 182,  76, 188, 161, 182,  76,  61, 225, 182,  75, 160, 225, 182,  75,  64,
     169, 180,  76,  94, 229, 180, 101,  33, 233, 180, 125, 160, 228, 180, 142,  63,
     164, 180, 150,  95, 161, 179, 157, 221, 145, 178, 132, 191, 144, 179, 123, 190,
     144, 178,  75,  32, 144, 178,  80,   8, 144, 178,  80,  12 };

const byte Sound_C3_RIVIERE [116] PROGMEM = {
       0, 116,  47,  47,  53, 179, 120,   0,  33, 212,  60, 185,  32, 247, 141, 192,
     212, 218,  76, 202, 228, 218,  77, 162, 229, 217,  61,  64, 208, 184,  51, 223,
     153, 216,  52,  93, 237, 216,  52, 221, 250, 216,  69, 223, 185, 216,  94, 161,
     249, 183, 111,  63, 186, 183, 135, 191, 186, 183, 143,  63, 250, 182, 151,  62,
     185, 182, 143,  95, 186, 183, 134, 223, 181, 183, 134,  64, 228, 183, 116, 223,
     218, 149, 108,  64, 232, 148, 115, 223, 209, 179, 106, 192,  21, 178, 124,  48,
      32, 178, 132,  80,  33, 177, 139,  63,   1, 177, 130, 192, 106, 178,  90,  13,
      90, 178,  80,  15 };

const byte Sound_C3_RIZ [52] PROGMEM = {
       0,  52,  47,  47, 146, 180, 104,   0,  82, 180, 117, 144,  97, 181, 109, 152,
      97, 181, 109, 160, 229, 183,  86,  70, 228, 184,  86, 195, 228, 217,  79,  65,
     244, 217,  62, 193, 244, 217,  53, 192, 241, 217,  44, 220, 134, 152,  67, 188,
     134, 152,  72,  20 };

const byte Sound_C3_ROSEE [104] PROGMEM = {
       0, 104,  47,  47, 149, 171, 120,   0, 165, 171, 122, 155, 218, 171, 132,  32,
     166, 170, 115, 160, 166, 169, 123, 223,  66, 170, 131, 192, 130, 165, 116,  67,
     162, 167, 100,  35, 230, 168, 108, 163, 134, 139, 133,  36, 171, 171, 125,  64,
     235, 175, 109,  64, 230, 176,  92, 190, 229, 177,  76, 188, 201, 211,  84, 223,
     128, 183,  93, 176, 213, 182,  85,  23, 213, 214,  93,  62, 225, 213,  77,  64,
     229, 181,  94,  63, 240, 182, 102,  95, 208, 216, 101, 189, 224, 216,  93,  60,
     160, 185,  60, 196, 224, 185,  80,  10 };

const byte Sound_C3_ROUTE [108] PROGMEM = {
       0, 108,  47,  47,  35, 176, 186,   0,  19, 208, 139, 161,  19, 208, 140, 166,
       6, 177, 125,  35, 129, 171, 106, 131, 130, 160, 115,  39,  66, 165,  99, 163,
      66, 196, 108,  32,  66, 166, 124, 160,  66, 168, 149,  62,  71, 174, 101,  62,
     162, 176,  85,  58, 153, 211,  60,  62, 128, 213,  88,  80, 128, 181,  80, 112,
       1, 182,   0, 112,   1, 215, 253,  16,  17, 214, 206,  48,  65, 184,  92, 208,
     194, 149, 107,  51, 149, 179, 123, 221,  97, 179, 123,  95,  89, 178, 114, 191,
      69, 179,  97, 160,  69, 181, 105, 138,  85, 179,  48,  15 };

const byte Sound_C3_SAUCE [72] PROGMEM = {
       0,  72,  47,  47, 180, 183, 128,   0, 110, 214, 166,  80,  30, 215, 141, 176,
      30, 214, 157, 240,  30, 214,  94,  48,  14, 213,   6,  80, 133, 213, 100, 143,
     229, 175, 109,  68, 226, 174, 100, 161, 225, 174,  92,  32, 193, 173,  91, 189,
     133, 178,  83, 184,  90, 214,  62,  48, 138, 215, 102, 112, 197, 216, 102,  80,
     213, 215,  93,  48, 193, 216,  88,  21 };

const byte Sound_C3_SUCRE [100] PROGMEM = {
       0, 100,  47,  47,  90, 216,  88,   0,  10, 217,  62, 176,  26, 216,   6, 208,
      10, 215,   6, 112, 165, 183,  69, 143, 161, 183,  69, 192,  97, 150,  61, 220,
     146, 150,  61,  63, 225, 182,  60,  61, 208, 183,  64,  80, 128, 215,  96, 112,
      20, 149,   4, 144,  20, 150, 126,  48,  96, 182, 141, 168,  37, 180,  62, 176,
      32, 211, 150, 208, 101, 178, 126,  48, 149, 177, 115,  92, 148, 176, 114, 190,
     101, 176,  66, 192,  20, 176,   3,  62,  32, 176,   2,  32,  16, 142,   1,  34,
      16, 174,   0,  13 };

const byte Sound_C3_THE [52] PROGMEM = {
       0,  52,  47,  47,   0, 182, 248,   0,  84, 215, 213, 144, 102, 182, 173, 176,
     229, 182,  86,  47, 250, 182, 103,  38, 250, 183, 111,  95, 249, 183, 103,  94,
     229, 184,  94,  60, 208, 184,  85,  59, 208, 185,  84,  57, 196, 153,  99,  62,
     196, 151,  96,   6 };

const byte Sound_C3_TOMATE [116] PROGMEM = {
       0, 116,  47,  47, 145, 216,  88,   0,  18, 215, 124, 176, 214, 180, 108, 143,
     219, 179, 126, 174, 231, 177, 118, 188, 167, 176, 126,  61, 234, 175, 125,  60,
     152, 177,  60,  62, 156, 177,  52,  64, 157, 177,  52, 221, 165, 177, 125, 189,
     101, 179, 158,  32, 165, 179, 174,  64, 185, 180, 157,  95, 165, 180, 132, 191,
     144, 181, 123, 191, 213, 180, 122,  34, 144, 212,  96,  48, 128, 180, 128,  80,
     128, 180, 128, 112,   0, 150,   0, 112,  16, 182, 172, 144,  16, 181,   4,  48,
     225, 179, 107,  62, 213, 178, 122, 190, 214, 178, 122, 192,  85, 178,  81, 160,
      80, 179,  80,  13 };

const byte Sound_C3_VEAU [56] PROGMEM = {
       0,  56,  47,  47, 101, 178,  40,   0,  21, 177,   3, 219,  20, 181,   3,  32,
      85, 215,  27, 160,   1, 183,   4,  32,   0, 180,   4,  64,  20, 173,  68,  45,
     149, 173, 100, 165, 233, 170, 101,  66, 149, 168, 109,  95,  69, 165, 116, 220,
     149, 166,  99,  62, 213, 166,  88,   0 };

const byte Sound_C3_VERT [92] PROGMEM = {
       0,  92,  47,  47, 196, 178,  64,   0, 144, 182,  75, 187,  80, 181,  43, 190,
      85, 180,  35, 160,  85, 181,  35, 192,  85, 180,  12, 160, 105, 179,  37,  65,
     101, 180, 110,  39, 185, 180, 126, 163, 184, 180, 135,  33, 248, 181, 151,  95,
     248, 182, 143,  96, 244, 183, 143,  96, 248, 183, 126, 195, 244, 183, 126,  36,
     224, 183, 101,  35, 224, 215, 116,  33, 228, 181,  75, 192, 164, 180, 115, 217,
      37, 179, 132, 240,  36, 178, 124, 176,  36, 178, 120,  24 };

const byte Sound_C3_VILLAGE [116] PROGMEM = {
       0, 116,  46,  47, 165, 182,  72,   0, 161, 183,  75, 148, 229, 184,  76,  35,
     217, 216,  69,  70, 229, 216,  60, 198,  68, 248,  77, 223, 225, 182,  93, 222,
     250, 182, 127,  61, 186, 182, 159, 186, 185, 181, 175, 188, 185, 180, 175,  61,
     185, 180, 185,  95, 184, 180, 182, 223, 184, 180, 174,  95, 105, 180, 164, 223,
     185, 180, 158,  64, 189, 179, 141,  64, 165, 180, 132, 192, 101, 180, 125,  64,
     169, 179, 124, 192, 133, 179,  99, 192,  69, 186,  85,  62,  33, 218,  62,  80,
      84, 218,  77, 208,  84, 218, 123, 192, 137, 179, 123,  32, 137, 178, 122, 163,
     168, 178, 112,  15 };

const byte Sound_C3_VILLE [112] PROGMEM = {
       0, 112,  47,  47, 164, 182,  88,   0,  86, 183,  67, 183,  85, 215, 108,  32,
      16, 186,  45,  32,   5, 185,   5,  32, 233, 216,  69,  74, 249, 216,  61,  69,
     249, 217,  61,  64, 249, 217,  53,  92, 249, 216,  52, 184, 213, 216,  44,  59,
     229, 215,  69,  94, 182, 183,  77, 189, 250, 182,  77,  63, 241, 182,  76,  32,
     225, 214,  75, 192, 230, 182,  67,  62, 230, 181,  67, 160, 250, 181,  84,  64,
     250, 180,  92,  32, 189, 180, 117,  32, 185, 180, 133,  63, 184, 180, 124, 191,
     164, 179, 116,  32,  85, 179,  99, 160, 105, 179,  91, 137, 101, 179,  96,  15 };

const byte Sound_C3_VINAIGRE [116] PROGMEM = {
       0, 116,  47,  47,  36, 214,   0,   0, 165, 183,  75,  15, 238, 216,  60,  36,
     229, 217,  53,  37, 192, 218,  69,  35, 192, 179,  68, 163, 210, 150,  76,  64,
     220, 180,  68, 221, 229, 183,  94, 189, 229, 183, 127,  61, 229, 182, 143, 220,
     181, 182, 143, 222, 245, 183, 143,  96, 249, 183, 134, 190, 245, 184, 110, 223,
     229, 184, 101, 189, 229, 185,  93,  63, 140, 152,  83, 190, 200, 150,  74, 192,
     192, 183,  90, 160, 165, 181,  75,  33, 165, 179, 100,  65,  85, 178, 124, 192,
     184, 177, 140, 224,  80, 175, 107, 192,  64, 173, 122, 161,  36, 176,   2,  32,
      16, 144, 184,  15 };

const byte Sound_C3_VIOLET [100] PROGMEM = {
       0, 100,  47,  47, 197, 149,  32,   0, 144, 183,  25, 128, 145, 152,  34,  32,
     149, 183,  27,  33,  89, 183,  52, 161, 167, 183,  61,  33, 170, 215,  61, 163,
     237, 183,  69,  66, 229, 149, 101, 198, 233, 147, 110,  32, 250, 144, 126,  93,
     234, 145, 126,  62, 234, 179, 126, 188, 169, 148, 110,  59, 165, 181,  94,  32,
     233, 181,  93, 221, 248, 182, 102,  63, 244, 182, 126, 223, 244, 183, 134, 223,
     245, 183, 118, 192, 224, 183, 125, 194, 224, 183, 101,  33, 208, 185,  91, 161,
     144, 218,  80,   0 };

const byte Sound_C3_VIRAGE [108] PROGMEM = {
       0, 108,  47,  47, 144, 182,  48,   0, 145, 183,  51,  17, 149, 184,  76, 166,
     170, 216,  69, 195, 245, 216,  69, 196, 245, 216,  78,  34, 233, 184, 102, 192,
     169, 182, 118,  60, 149, 181, 109,  54, 101, 179, 166,  64, 105, 177, 174, 161,
     106, 176, 183,  62, 168, 178, 190, 255, 168, 178, 182,  95, 185, 178, 182, 223,
     190, 179, 165, 192, 185, 179, 141,  95, 169, 179, 124, 192, 133, 179,  99, 192,
      69, 186,  85,  63,  33, 218,  62,  80,  84, 218,  77, 208,  84, 218, 123, 192,
     137, 179, 123,  32, 137, 178, 122, 164, 168, 178, 112,  15 };

const byte Sound_C3_YAOURT [112] PROGMEM = {
       0, 112,  47,  47, 216, 248,  48,   0, 249, 248,  44,  32, 228, 216,  69,  39,
     228, 216,  94, 165, 228, 183, 127,  34, 224, 182, 143,  64, 224, 148, 142,  66,
     224, 174, 116, 222, 232, 169,  91, 221, 153, 167,  91, 219, 149, 166,  99,  95,
     137, 167,  90,  95, 148, 165,  81, 191, 145, 166,  90,  64,  65, 203, 114, 160,
      66, 174, 154, 192,  18, 175, 123, 160,  34, 176,   4,  32,  16, 212,  48, 112,
      16, 212,  48, 112,   0, 215, 237,  48,  17, 214, 156, 176,  86, 180,  84, 176,
     217, 179,  98, 156, 200, 177, 106, 161, 197, 174, 121, 162, 197, 178, 128,  12 };

const byte Sound_C3_ADDITION [124] PROGMEM = {
       0, 124,  47,  47,   0, 153, 248,   0,  84, 181, 171, 143, 169, 180, 166,  36,
     248, 181, 166, 160, 188, 182, 151,  66, 120, 182, 135,  34, 104, 182,  85, 160,
     148, 182,  59,  32, 152, 182,  64,   1, 148, 215,  56,  80, 165, 215,  60, 144,
     182, 216,  61, 176, 186, 216,  52, 148, 247, 216,  53,  33, 230, 216,  61, 192,
     166, 216,  53, 161, 186, 216,  53,  63,   9, 186,   5, 208,   9, 217, 165, 112,
      14, 216, 197, 208,  10, 218, 238,  80,   9, 218, 230, 208,  25, 218,   6,  80,
      16, 151, 118,  91,  21, 175,  45, 223,  25, 166,  45,  94,  25, 165,  44, 223,
      69, 171, 180,  64,  69, 168, 155,  95, 132, 169, 112,  14 };

const byte Sound_C3_ALPHABETIQUE [184] PROGMEM = {
       0, 184,  47,  47,   0, 153, 248,   0, 169, 179, 190,  45, 185, 180, 183,  64,
     189, 181, 151,  66, 122, 181, 118, 193, 105, 181, 101, 189,   4, 183,   5, 190,
       4, 184,   5, 144,  21, 182, 214,  80,  16, 214, 213, 176,   5, 182, 254,  80,
      25, 182,  77, 176, 168, 180, 142, 169, 190, 180, 159,  60, 190, 181, 151, 222,
     126, 181, 126, 190, 170, 180,  99, 183, 169, 180,  91,  16, 169, 180,  67,  14,
      89, 181,  84,  32, 170, 183, 110, 160, 185, 184,  94, 223, 185, 216,  86,  62,
     122, 216,  69,  53, 148, 183,  72,  48, 212, 183,  96,  80,   9, 212, 168, 112,
      25, 216, 164,  48,  25, 217, 172, 144, 158, 217,  68, 176, 239, 217,  60,   4,
     185, 216,  60, 160, 185, 216,  61,  95, 185, 217,  60, 191, 181, 217,  68,  63,
     245, 217,  42, 191, 224, 217,  32,  48, 128, 216,  40, 112, 128, 216,  40, 112,
      21, 186, 229,  16,   4, 186, 205, 176, 153, 217,  93,  48, 249, 150, 116,  64,
     213, 181, 131, 192, 169, 181, 120,  14 };

const byte Sound_C3_ALPHANUMERIQUE [208] PROGMEM = {
       0, 208,  47,  47,  21, 179,   0,   0, 166, 179, 190,  37, 171, 180, 183,  66,
     170, 180, 167,  66, 105, 181, 151,  34, 105, 181, 143,  65, 105, 181, 126, 160,
     105, 181,  94,  64, 169, 181,  85,  61,  80, 185,  60, 188,  21, 180,   5, 176,
      85, 182, 198,  48,   6, 182, 222, 208,   5, 182, 230,  80,   0, 180, 253, 208,
       4, 180, 229,  80, 169, 178, 141, 170, 174, 180, 175,  95, 170, 180, 183,  63,
     105, 182, 159,  64, 104, 182, 126, 190, 152, 181,  69, 160, 152, 214,  69, 160,
     152, 215,  61,  64, 132, 216,  70,  64,  81, 185,  70, 190,  98, 184,  62,  95,
     137, 150,  61,  96, 170, 151,  94,  61, 166, 183, 110, 160, 170, 184, 118, 223,
     102, 184, 110, 223,  41, 183, 102,  62,  41, 182,  45, 144,  33, 214, 117, 208,
     169, 184,  93, 240, 181, 185,  84, 145, 181, 217,  68,  62, 240, 217,  59,  63,
     229, 217,  50, 223, 193, 216,  48,  48, 128, 183,  48,  80, 128, 183,  48, 112,
      65, 181, 248, 112,   4, 217, 253,  16,  10, 217,   5, 176, 237, 184,  84, 176,
     169, 183, 108, 138, 170, 181, 132,  94, 137, 181, 139, 194, 153, 181, 128,  11 };

const byte Sound_C3_AOUT [72] PROGMEM = {
       0,  72,  47,  47, 128, 185, 112,   0, 128, 162,  89, 143,  37, 160,  92,  39,
      85, 168,  84, 161,  84, 170,  93,  95,  81, 171,  85, 190,  81, 141,  70,  93,
      64, 178,  61, 189, 144, 212,  68,  59, 128, 212,  72,  16, 193, 178,  80, 112,
     128, 215,  88, 112, 132, 182,  56, 112,   5, 214, 174,  80,  64, 219, 253, 176,
      21, 214,   5, 208,  21, 214,   0,   5 };

const byte Sound_C3_APPREND [100] PROGMEM = {
       0, 100,  47,  47,   0, 153, 248,   0, 149, 179, 197,  15, 246, 178, 199,  40,
     182, 178, 191, 160, 174, 177, 183, 192, 107, 177, 158,  34, 212, 176, 168,  80,
      65, 182, 176, 112,   0, 182, 254,  48,  18, 145, 212, 176, 197, 175, 228, 208,
      33, 203,   4, 176,  38, 172, 125,  48,  38, 171, 140,  48,  43, 170, 165,  49,
      43, 170, 173, 188,  54, 202, 198,  94,  39, 202, 206,  95,  38, 202, 181, 223,
     107, 202, 148,  62,  69, 169, 155, 192,  69, 166, 155,   0,  69, 163, 131,  11,
       5, 200,  64,  12 };

const byte Sound_C3_AUGMENTE [152] PROGMEM = {
       0, 152,  47,  47,   0, 153, 248,   0,  90, 172, 158,  46,  74, 172, 159,  32,
      22, 169, 167, 161,  42, 171, 119,  33,   6, 170,  79,  63,  39, 170,  61,  32,
     134, 170,  67,  32,  85, 171,  32,  80,  33, 177,   5,  16,  54, 178, 213,  48,
      86, 180,  93,  30,  86, 147, 102, 192, 141, 180,  53, 221,  77, 179,  46,  94,
      74, 183,  38, 222,  22, 169, 183,  95,  38, 172, 191,  95,  39, 203, 191,  95,
      38, 201, 182, 192,  37, 168, 174,  64,  41, 170, 157, 223,  25, 174, 158,  95,
     153, 178, 133,  62,  66, 178, 112,  48,  20, 174,  24, 112,  20, 174,  24, 112,
       1, 183, 253,  16,  17, 215, 214,  48,  69, 182, 117, 176, 150, 180, 100, 140,
     238, 179, 124, 160, 154, 179, 132, 192, 155, 178, 124, 192,  90, 179,  51,  63,
     105, 178,  75,  32,  21, 178,   0,  14 };

const byte Sound_C3_AVRIL [124] PROGMEM = {
       0, 124,  34,  47,  85, 179, 168,   0, 166, 179, 189, 163, 166, 179, 190,  36,
     169, 179, 190, 160, 170, 179, 166, 194, 170, 178, 150,  32, 170, 177, 108, 191,
      84, 178, 108,  62,  64, 213,  84,  93,   0, 182, 124,  95,  85, 208,  83, 190,
     153, 181, 104,  80, 153, 182, 116, 128, 169, 183, 126,  32, 169, 183, 126, 190,
     181, 184, 102, 223, 181, 184,  94,  62, 181, 216,  93, 191, 182, 216,  85,  62,
     245, 216,  76, 191, 245, 216,  76,  32, 245, 215,  68,  63, 177, 215,  68,  32,
     101, 182,  93,  64, 182, 182,  92, 160, 254, 181,  84,  32, 233, 181,  83, 160,
     170, 181,  91, 160, 173, 181, 123, 192, 174, 180, 155,  64 };

const byte Sound_C3_CASSETTE [120] PROGMEM = {
       0, 120,  46,  47,  26, 183, 128,   0,  73, 183, 157, 176, 153, 184, 124,  15,
     169, 183, 135,  40, 185, 182, 159, 191, 185, 182, 143,  62, 168, 182, 117,  63,
      20, 216, 132, 208,  17, 215, 252, 240,  24, 216, 212, 240, 149, 214, 108, 176,
     105, 182, 125, 145, 125, 182, 142, 187, 185, 182, 142,  57, 249, 182, 141, 191,
     232, 183, 124, 160, 229, 183, 116,  62, 217, 183,  99, 191, 128, 182,  80,  48,
     144, 183, 104,  80, 144, 183, 104, 112,   0, 184, 248, 112,   0, 218, 238,  16,
      89, 180, 133, 208, 221, 179, 107,  38, 221, 180, 123,  94, 153, 180, 115,  60,
     165, 179,  90, 166, 145, 179,  64,  15 };

const byte Sound_C3_COULEUR [100] PROGMEM = {
       0, 100,  47,  47, 128, 180, 192,   0,   0, 146, 202, 144,  85, 182, 245, 144,
       6, 133,  76, 175,  27, 137,  77,  37,  23, 139,  78,  32,  21, 113,  78, 220,
      36, 150,  78,  93,  36, 181,  78, 160, 105, 181, 135,  61, 173, 181, 151,  62,
     185, 180, 158, 223, 189, 179, 166,  96, 189, 179, 158, 127, 110, 179, 158,  64,
     174, 148, 141,  64,  90, 148, 141, 160,  94, 148, 133,  63,  54, 177, 149,  48,
      39, 178, 236, 208,  33, 177, 244,  80, 201, 181, 252, 176,  37, 178,   3, 176,
      37, 178,   0,  12 };

const byte Sound_C3_DECEMBRE [132] PROGMEM = {
       0, 132,  47,  47, 192, 215,  16,   0,  21, 215,   5, 144, 249, 183,  93, 170,
     249, 184, 102, 161, 233, 184, 111, 160, 168, 184, 103, 160, 232, 184,  94, 160,
     216, 184,  77, 191, 169, 216, 101,  64, 233, 215, 102,  48,   5, 215, 125, 240,
      24, 214, 117, 240,  88, 214, 125, 129, 164, 178, 158, 188, 105, 176, 175,  51,
     102, 206, 166,  62,  98, 171, 156, 192,  18, 169, 173,  95,  34, 168, 164,  62,
      34, 169, 107, 160,  98, 168, 115,  32,  36, 163,  51,  64,  76, 170,  59,  64,
      67, 187,  66, 191,   4, 183,  88, 112,  85, 183, 150,  48,  18, 171,   4, 176,
      38, 174,   4, 208, 154, 174, 122,  33,  36, 174,  98,  65, 129, 148, 248,  11,
     129, 148, 248,  10 };

const byte Sound_C3_DEPLACE [116] PROGMEM = {
       0, 116,  47,  47,   4, 183, 224,   0,   4, 216,   5, 143, 186, 184,  71,  47,
     169, 184,  95, 160, 169, 184,  87,  32, 170, 184,  70, 191, 154, 181,  51, 190,
     229, 184,  40,  48,  16, 183,  48, 112,   5, 147, 230,  48, 105, 150,  69,  38,
      40, 182,  14, 186, 125, 181,  79,  59, 121, 181, 119,  63, 186, 181, 143,  95,
     184, 182, 134, 191, 181, 182,  93,  32, 100, 182,  61,  16,  97, 216, 132, 240,
      22, 216, 148, 240, 154, 183,  68, 240, 233, 183,  68,  61, 185, 184,  77,  94,
     245, 184,  68,  94, 229, 184,  67,  61, 213, 185,  58, 191, 249, 185,  50,  32,
     248, 185,  40,   9 };

const byte Sound_C3_DISQUETTE [136] PROGMEM = {
       0, 136,  47,  47, 213, 215,  40,   0, 149, 216,  36, 144,  89, 216,  21, 144,
     101, 248,  13, 176, 149, 218,  14,  68,  73, 186,   5, 192,  73, 184,   5,  16,
      68, 184, 237, 176,  84, 183, 237, 112, 196, 153, 237,  80, 196, 153, 232,  16,
      64, 185, 144, 112,  85, 186, 230, 144, 133, 218,  54, 176, 246, 184,  86, 162,
     165, 183, 119,  94, 229, 183, 110, 223, 250, 183,  77, 222, 233, 182,  56,  16,
     228, 182,  64,  16, 192, 182,  80, 112, 208, 215, 112, 112,   0, 215, 248, 112,
      20, 182, 204, 144,  85, 182, 213, 176,  37, 181,  77,  48, 169, 179, 108,  30,
      89, 180, 117,  32, 169, 179, 132, 192,  89, 178,  83,  95,  89, 178,  50, 155,
      25, 177,  42, 136,   5, 179,  96,   3 };

const byte Sound_C3_DIVISION [116] PROGMEM = {
       0, 116,  47,  47,   0, 214,   0,   0, 154, 216,  52, 176, 254, 216,  51, 143,
     186, 216,  61,  37, 186, 216,  62,  35, 250, 217,  62, 193, 185, 217,  70,  34,
     122, 216,  61, 160,  98, 152,  20, 189,  97, 152,  28, 222, 103, 184,  53,  32,
     182, 216,  61, 160, 250, 216,  62,  64, 190, 216,  62,  64, 187, 216,  69, 190,
     190, 216,  69,  63, 110, 184,  20, 222, 126, 183,  36,  28,  94, 184,  20, 160,
      22, 245, 116,  59,  22, 245, 116, 160,  22, 245, 116, 160,  21, 183,   5,  32,
      97, 150,  85, 192,  41, 168,   4, 224,  41, 162,   3,  95, 136, 179,  82, 224,
      69, 174,  72,   7 };

const byte Sound_C3_EXPLICATION [176] PROGMEM = {
       0, 176,  47,  47,   0, 153, 248,   0, 169, 183, 150,  45, 234, 183, 134, 160,
     102, 184, 119,  65, 118, 184, 102, 190, 217, 152, 100, 160, 213, 183,  96,  16,
     164, 183, 116,  16,  16, 148,   4, 208,  21, 216, 124, 208,  17, 216,   5,  80,
      22, 182,   4, 176,   1, 184, 120,  48,  69, 150, 248, 112,  21, 183,   5, 208,
     118, 216,  62,  32, 123, 216,  62, 191, 187, 217,  61, 190,  20, 185,  24, 112,
      24, 184, 206,  16, 170, 185,  86,  48, 122, 184,  94, 141, 186, 182, 143,  92,
     103, 181, 143,  95, 106, 182, 126, 191, 165, 182, 120,  48,  69, 183, 133,  16,
     150, 216, 140, 176,   1, 217, 140, 240,  30, 216, 253, 112,  85, 185,  61, 112,
     161, 185,  76,  17, 101, 151,  92, 189,   8, 146,  92, 223,   8, 175, 148,  62,
      24, 170, 147, 160,  20, 166,   3,  32,  36, 164,   3,  32,  36, 164,   2,  63,
      36, 196,   1, 191, 132, 174, 138,  63,  68, 205, 121, 169,  68, 176, 128,   6 };

const byte Sound_C3_FEVRIER [140] PROGMEM = {
       0, 140,  47,  47, 128, 186,  88,   0, 137, 182, 251, 144,  17, 182, 132, 176,
      17, 181, 253,  48,   0, 184, 245,  80,  17, 182,  77, 112,  21, 181,   5, 208,
     233, 182, 109,  47, 249, 182, 118, 160, 186, 183, 119, 190, 186, 183, 111, 223,
     122, 183,  95,  62,  90, 150,  94,  60,  90, 149,  92, 185,  65, 181,  84,  63,
      20, 180,  93,  32,  85, 179, 108, 161,  33, 211, 116, 189, 101, 179, 125, 144,
      34, 180, 182,  48, 102, 181,  93, 176, 165, 183,  84, 137, 233, 185,  93, 223,
     181, 217,  77, 222, 245, 217,  69,  64, 245, 216,  76, 191, 245, 216,  85, 191,
     224, 184,  93, 224, 213, 184,  93, 192, 229, 184,  85,  32, 181, 184,  85,  63,
     245, 216,  84, 160, 229, 184,  56,  10, 229, 184,  56,   9 };

const byte Sound_C3_FICHE [112] PROGMEM = {
       0, 112,  47,  47,   5, 183, 208,   0,   5, 183, 214,  16,  22, 182, 222, 176,
      69, 182, 255,  48,   9, 184,   7,  80, 122, 216,  71,  37, 246, 216,  62,  32,
     230, 216,  62,  32, 230, 216,  54,  61, 245, 216,  54,  62, 229, 217,  53, 190,
     230, 217,  53, 191,  21, 185,   6,  32,  17, 186,   6,  16,   2, 217, 255,  80,
     101, 218, 255, 112,  24, 218, 255, 112,  41, 218, 254, 208, 101, 218, 254,  48,
      33, 218, 109, 176,  73, 181, 124, 158, 165, 180, 124,  32, 213, 180, 131, 191,
     233, 179, 139, 160,  68, 179, 139,  63,  64, 177, 131,  64,   0, 177,  96,  12 };

const byte Sound_C3_INDEX [128] PROGMEM = {
       0, 128,  47,  47,  64, 153, 232,   0, 148, 213, 158,  43, 229, 180, 158, 192,
     230, 212, 159,  66, 168, 213, 127,  96, 153, 181,  86,  32, 200, 180,  53,  63,
     216, 180,  44,  61, 200, 180,  58, 189, 200, 180,  40,  64, 132, 184,  42, 130,
     172, 182,  84, 160, 249, 182, 118,  89, 249, 184, 126, 224,  32, 181, 248,  16,
      32, 181, 248,  48,  32, 181, 248,  80,  32, 181, 254,  48,  32, 181, 252, 144,
      51, 215, 171, 176,  51, 215, 171, 176,  51, 215, 172,  16,  51, 215, 172, 144,
      51, 215, 172, 176,  50, 215, 180, 176,  26, 215, 204,  48,  26, 215, 204,  48,
      26, 215, 220,  16, 253, 178,  91, 176, 253, 178,  91, 176, 253, 178,  88,  10 };

const byte Sound_C3_JANVIER [128] PROGMEM = {
       0, 128,  47,  47, 149, 180,  88,   0, 149, 181,  82, 150,  88, 213,  83, 160,
     164, 218,  84, 160,   5, 216,  93, 163,  89, 218,  86, 160,   4, 216, 126,  41,
       5, 144, 110, 163,  21, 172, 134, 193,  21, 167, 182,  64,  69, 170, 165, 161,
     132, 168, 157, 161, 132, 167, 149,  32,  72, 167, 133,  32,  73, 172,  92, 223,
       0, 173, 115, 184,  64, 216,  83,  48,  84, 214,  99, 176,  98, 216,  68, 176,
      89, 184,  60, 187, 218, 216,  59, 190, 233, 216,  51, 221, 248, 216,  59, 192,
     249, 216,  68, 160, 185, 216,  77, 160, 117, 216,  86,  32, 185, 216,  93, 223,
     245, 216,  85,  64, 228, 184,  67, 161, 245, 184,  75,  35, 149, 184,  48,  14 };

const byte Sound_C3_JUILLET [100] PROGMEM = {
       0, 100,  47,  47,  21, 186, 120,   0,  21, 186, 124,   0,  21, 186, 125,  32,
      25, 186, 117, 160,  30, 186, 118,  80,  30, 186, 118,   0,  16, 216,   6,  36,
      32, 182,  30,  66,  85, 150,  61, 193, 182, 184,  62, 192, 249, 217,  62,  64,
     249, 249,  61, 222, 185, 249,  45,  93, 229, 249,  44, 189, 253, 217,  45, 192,
     249, 217,  78,  32, 185, 184, 103,  95, 185, 183, 119,  94, 185, 183, 118, 160,
     185, 183, 110,  63, 185, 183, 101, 161, 229, 183,  93,  34, 212, 183,  76,  32,
     212, 184,  88,  14 };

const byte Sound_C3_JUIN [76] PROGMEM = {
       0,  76,  47,  47,  89, 182, 104,   0, 168, 181, 106, 145, 169, 181,  91, 191,
      85, 182,  84, 162,   5, 183,  61,  32,  20, 215,  29, 192,   4, 151,  70,  38,
      32, 183,  70,  34, 112, 214,  69, 194,  96, 182,  85, 193,  85, 149, 126,  64,
      85, 180, 150, 223,  85, 180, 158, 223,  81, 180, 174, 223,  21, 179, 174, 221,
      17, 179, 173, 190,  81, 179, 148,  32,  84, 179,  96,  13 };

const byte Sound_C3_LECTEUR [108] PROGMEM = {
       0, 108,  48,  47, 249, 181,  96,   0, 188, 181,  69,  67, 173, 181,  62,  67,
     189, 182,  94, 169, 185, 183, 119,  64, 246, 184, 111,  33, 246, 184,  94,  62,
     225, 183, 112, 112,  89, 185, 238,  48,  96, 219, 165,  48, 145, 186, 124,  48,
     149, 184, 112,  48,  69, 218, 232, 112,  68, 249, 156, 144,  64, 182, 237,  48,
      85, 181,   5, 176, 169, 181,  93, 131, 234, 180, 109, 160, 238, 180, 109, 192,
     234, 180, 109, 192, 238, 180, 109, 193, 239, 179, 109,  95, 155, 177, 108, 187,
      86, 176,  84, 176,  82, 208,  88,  17,  65, 215,  16,  17 };

const byte Sound_C3_MAGNETOPHONE [188] PROGMEM = {
       0, 188,  47,  47, 136, 182,  48,   0, 136, 184,  41, 130, 200, 184,  34,  32,
     200, 183,  35,  65, 138, 182,  53,  66,  90, 179,  53, 162, 106, 181, 159,  36,
     123, 181, 159, 162, 168, 183, 143,  65, 152, 182,  69,  36, 104, 184,  85,  34,
     161, 153,  77,  32, 207, 150,  77,  64, 162, 185,  77,  62, 145, 217,  77, 160,
     150, 217,  86,  63, 186, 217, 110, 223, 124, 216,  94,  62, 188, 216,  76, 153,
     249, 216,  56,   0, 232, 216,  80,  48, 209, 184,  88,  80,   6, 215, 205, 176,
      38, 181,   5, 176, 170, 178, 108, 161,  94, 175, 125, 221,  27, 173, 117,  63,
     158, 174, 115, 191,  91, 206, 124, 240, 219, 207, 132, 240, 153, 175, 123, 149,
     185, 175, 148, 192, 185, 176, 149,  62, 190, 177, 149,  64, 233, 179, 116,  95,
     150, 180, 107, 190, 206, 176,  50, 191, 207, 178,  50, 192, 203, 182,  51,  65,
     207, 184,  51,  64, 207, 181,  50, 160, 203, 182,  51,  64, 170, 181,  84,  32,
      86, 181, 100,  64,  21, 179, 115, 223,  73, 179,  88,  14 };

const byte Sound_C3_MAI [76] PROGMEM = {
       0,  76,  47,  47, 136, 149,  48,   0, 140, 180,  66, 188, 206, 179,  58, 160,
     200, 181,  50, 160, 141, 182,  60, 162, 141, 182,  61,  33, 141, 182,  69,  65,
     141, 149,  61, 194,  69, 181,  62,  37, 166, 182, 134, 160, 185, 182, 142, 160,
     169, 183, 142, 192, 169, 184, 134, 223, 169, 184, 134,  59, 169, 184, 125, 187,
     164, 184, 117,  60, 164, 184, 124,  32, 228, 184, 120,  12 };

const byte Sound_C3_MARS [112] PROGMEM = {
       0, 112,  47,  47,  72, 181,  72,   0, 200, 181,  58, 188, 140, 181,  51, 192,
      76, 179,  29,  35,  12, 179,   5, 161,  28, 177,   6,  65, 106, 178, 167, 163,
     102, 179, 191, 192, 101, 178, 199,  96, 102, 178, 191,  93, 102, 177, 182, 222,
      38, 177, 166,  61,  38, 177, 141,  62,  38, 176,  67, 208, 128, 185, 253,  80,
      41, 178, 221,  80,   4, 181, 253, 208,  68, 219, 252, 208,  64, 186, 252,  80,
      37, 216,  52,  80,  25, 216,  44,  80,   1, 216,  44,  80,   1, 215,  35, 208,
     253, 178,  91,  48, 253, 178,  91,  48, 253, 178,  88,   9, 253, 178,  88,  11 };

const byte Sound_C3_MOIS [60] PROGMEM = {
       0,  60,  47,  47, 217, 176,  40,   0,  76, 181,  52,  57,  76, 184,  36, 161,
      76, 184,  45,  37, 130, 187, 133,  65, 200, 187, 149, 162, 136, 175, 165, 193,
     137, 170, 174,  32,  86, 173, 166, 223, 106, 175, 182, 222, 122, 175, 190, 189,
     164, 175, 181, 192, 100, 174, 123, 160, 101, 175,  88,   8 };

const byte Sound_C3_MONITEUR [128] PROGMEM = {
       0, 128,  41,  47, 201, 182,  32,   0, 200, 182,  44, 194, 200, 184,  53,  66,
     201, 184,  53, 195,  22, 174,  95,  36,  22, 175,  95,  34,  23, 179,  95, 194,
     151, 181,  87,  33, 153, 182,  78,  34, 217, 213,  77, 160, 148, 216,  77, 192,
     209, 216,  86,  63, 218, 216,  78, 221, 214, 216,  70,  63, 229, 216,  53,  60,
     196, 216,  64, 112,  65, 215,   0, 112,  66, 185, 238,  48,  73, 184, 198,  48,
      89, 181,  69,  19, 234, 180, 126,  63, 235, 180, 134, 188, 170, 179, 142, 190,
     170, 179, 150, 224, 174, 179, 142,  94, 234, 179, 125,  64, 154, 180, 125,  64,
     233, 179, 116, 192, 170, 180, 108,  95, 154, 180,  91, 192, 150, 178,  91, 191 };

const byte Sound_C3_MONOCHROME [176] PROGMEM = {
       0, 176,  47,  47, 202, 180,  40,   0, 200, 183,  42,   5, 200, 179,  34, 192,
     197, 182,  36,  33, 138, 182,  53,  67,  25, 169,  62,  36,  42, 169,  70, 161,
      38, 171,   7,  35,  22, 175,   7,  66,   6, 177,   6, 161,  72, 181,  69, 192,
      73, 181,  69,  32,  22, 179,  54, 189,  21, 177,   6, 190,  21, 172,   6, 222,
      41, 171,   6,  63,  46, 171,   5,  63,  69, 171,  96, 112, 192, 152, 216, 112,
      66, 173, 220, 176,  18, 171,  93,  48, 134, 186, 204, 160,  38, 166,   4, 144,
      43, 168, 125,  48,  91, 168, 139, 145,  42, 166, 125,  92,  26, 167, 133,  64,
      25, 166, 133, 192,  29, 166, 141,  32,  77, 170, 124,  32, 137, 169, 107, 192,
      72, 169,  99,  32,  72, 184,  52,  63,  72, 183,  44, 160, 141, 182,  44, 192,
     157, 177,  43, 192, 218, 177,  51, 192, 158, 177,  43, 192, 122, 176, 100,  63,
     105, 176, 124, 160,  26, 176,   4, 160, 106, 177, 132, 192,  42, 177, 112,  12 };

const byte Sound_C3_MULTIPLICATION [184] PROGMEM = {
       0, 184,  47,  47, 224, 249,  24,   0, 202, 148,  26, 164, 197, 151,  28,  32,
     209, 152,  28, 161, 197, 152,  36, 195, 208, 152,  45, 164, 145, 151,  54, 162,
     101, 183,  14, 193, 241, 151,  53,  66, 176, 183,  35, 160,  85, 214,   0,  80,
      65, 182,   0, 112,  89, 215, 188, 176, 158, 216,  36, 176, 235, 216,  44,  26,
     251, 216,  45,  32, 247, 184,  53, 191, 151, 151,  53,  58, 209, 184,  40, 112,
      69, 181,   5,  48,  88, 215,   5,  80, 186, 216,  53, 162, 249, 216,  46,  63,
     246, 216,  45, 190, 242, 217,  44, 189, 133, 183,   8,  48, 209, 184,  40,  80,
      72, 182,   4, 144,  68, 178, 102,  48, 246, 184,  78, 166, 230, 183, 111,  59,
     186, 182, 111,  94, 170, 182, 110, 191, 186, 182, 110,  32, 153, 216, 124, 240,
      73, 215, 236, 240,  89, 218, 237, 112, 169, 216,  45,  80,  73, 147, 101,  90,
     136, 175, 115, 223, 153, 169, 106, 192, 104, 166,  98, 192, 132, 187,  98, 223,
     200, 185,  66,  36, 129, 184, 144,  14 };

const byte Sound_C3_NOVEMBRE [152] PROGMEM = {
       0, 152,  47,  47,  68, 180,  64,   0, 140, 182,  58,  61, 204, 180,  42, 161,
     140, 182,  44, 161, 140, 182,  53,  34, 140, 182,  53, 163, 140, 181,  53, 193,
     140, 181,  61, 194,  86, 179,  87,  35, 169, 175, 118, 192, 169, 174, 126,  95,
     173, 173, 117, 189,  84, 173, 100, 189,   0, 178, 116,  62,  64, 215, 120,  80,
       0, 216, 109,  80,   0, 172, 100,  59, 185, 172, 133,  64, 102, 172, 149, 222,
     165, 171, 132,  95, 166, 170, 115,  95,  20, 166, 139, 192,  80, 167,  99,  64,
      88, 166,  74, 190,  25, 162,  50, 160,  67, 186,  58, 165, 140, 168,  56,  48,
     128, 211,  32,  80,  70, 211, 141, 176,  18, 192,   3,  48,  22, 170,   3, 176,
      17, 173,   5,  80,  38, 206,  83, 176, 107, 174, 106, 128, 157, 174, 122, 160,
     105, 174, 114,  64, 105, 174, 112,  14 };

const byte Sound_C3_NUMERIQUE [132] PROGMEM = {
       0, 132,  47,  47,   0,   0,   0,   0, 152, 215,  58, 175, 152, 215,  60,  32,
     152, 215,  61,  32, 132, 216,  69, 160, 132, 216,  69, 192,  81, 185,  70,  62,
      98, 184,  61, 223, 137, 150,  61,  96, 170, 151,  94,  61, 166, 183, 110, 160,
     170, 184, 118, 223, 102, 184, 110, 223,  41, 183, 102,  62,  41, 182,  45, 144,
      33, 214, 117, 208, 169, 184,  93, 240, 181, 185,  84, 145, 181, 217,  68,  62,
     240, 217,  59,  63, 229, 217,  50, 223, 192, 216,  80, 112, 192, 216,  80, 112,
     192, 216,  80, 112,   9, 183, 220, 176,  89, 217,  84,  48, 233, 184,  82, 156,
     229, 184, 107, 160, 229, 181, 139,  64, 229, 180, 139,   2, 213, 180, 138, 137,
     213, 180, 136,  14 };

const byte Sound_C3_OCTOBRE [136] PROGMEM = {
       0, 136,  47,  47,   0, 152, 176,   0,  85, 175, 147, 140, 235, 176, 158, 161,
     166, 174, 134,  65,  98, 174, 124, 160,  96, 178, 120, 112,  33, 179, 237, 176,
      32, 213, 182,  48,   1, 182, 158, 176,  70, 215, 100, 176,  82, 213,  96,  80,
      82, 213,  96, 112,   1, 216, 214, 176, 213, 181, 117, 183, 165, 179, 135,  34,
     105, 177, 159,  94,  89, 175, 167,  94,  89, 175, 158, 191, 170, 175, 141, 191,
     169, 174, 116,  32, 229, 173, 108,  32, 232, 172,  99,  32, 165, 173, 104,  16,
     128, 179, 112, 112,   1, 180, 149,  48, 102, 203, 100,  48,  18, 171,   3, 208,
      37, 173,   4, 176,  22, 175, 237, 176, 102, 173,  84,  80,  81, 173, 130, 192,
      88, 174, 114,  33,  92, 174,  80,  14 };

const byte Sound_C3_REGARDE [144] PROGMEM = {
       0, 144,  47,  47,  41, 173,  64,   0,  22, 205, 116, 176,  34, 172, 196, 208,
      22, 171,  84, 208,  22, 173, 125, 174,  26, 174, 126, 166,  90, 176, 135,  34,
     107, 180, 111,  64,  27, 150,   6, 184, 139, 151,  60, 187, 137, 149,  67,  63,
     134, 148,  48,  80,  25, 184,  78,  48, 182, 184,  94,  62, 166, 184, 135,  62,
     106, 183, 159,  62, 175, 181, 175,  62, 191, 180, 183,  32, 170, 179, 191,  95,
     186, 179, 198, 160, 170, 178, 198,  63, 186, 177, 198,  64, 105, 176, 190,  64,
     109, 175, 173, 191, 110, 175, 165,  32, 170, 174, 164, 160, 104, 174, 156, 192,
     190, 176, 156, 192, 174, 177, 140,  63,  64, 183,  64, 112,  42, 180,  60, 176,
     170, 181, 132,  48, 238, 180, 140,  28, 252, 180, 139, 192,  90, 180, 144,  14 };

const byte Sound_C3_REGLE [116] PROGMEM = {
       0, 116,  47,  47,  37, 178, 104,   0,  41, 177,  27, 150,  37, 178,  69,  16,
      25, 178, 166,  80,  41, 178, 166,  40, 174, 180, 174, 197, 191, 180, 167,  33,
     186, 182, 159,  64, 185, 183, 151,  95, 185, 183, 142, 221, 122, 184, 126, 222,
     122, 184, 118,  62, 185, 185, 101, 191, 181, 153,  84, 160, 160, 185,  56,  80,
      80, 185,  80, 112,   4, 119, 253, 176, 177, 185,  75, 176, 176, 216,  83, 159,
     161, 184,  92,  32, 253, 181,  99, 190, 253, 181,  99,  63, 173, 181,  99, 192,
     110, 180, 100,  63, 169, 181, 140, 191, 253, 180, 156,  32, 170, 180, 155,  63,
     154, 180, 160,  15 };

const byte Sound_C3_RETENUE [128] PROGMEM = {
       0, 128,  47,  47,  18, 165,   0,   0,  38, 171,   2, 150,  34, 170,   4,  16,
      34, 170,   4,  13,  22, 168,   5,  16,  22, 170,   5,  40,  22, 172,   6,  42,
      26, 175, 118, 165,  26, 180, 111,  64,  25, 181,  78,  32, 153, 179,  96,  48,
     154, 214, 120, 112,  26, 214, 141,  16,   1, 214, 109,  48,  22, 181,  45,  30,
     166, 180, 101, 160, 106, 181, 110, 187,  90, 182,  88, 223,  88, 183,  78,  62,
     157, 181,  61,  64, 233, 182,  61,  61, 148, 182,  52, 221, 148, 182,  44,  94,
      80, 184,  52, 160, 160, 184,  69,  95, 177, 183,  69,  95, 161, 151,  68, 189,
     177, 151,  60,  64, 176, 183,  59, 190, 177, 151,  51,  32, 113, 183,  48,  15 };

const byte Sound_C3_RETIENT [120] PROGMEM = {
       0, 120,  47,  47,  40, 173,   0,   0, 107, 173, 122, 150, 106, 173, 124,  32,
      41, 172, 132, 160,  22, 168, 108,  66,  38, 169,   4, 166,  38, 170,   5, 166,
      42, 172,   6,  41,  26, 175, 151,  36,  90, 180, 127,  65,  90, 181, 102, 160,
     202, 178, 112,  48, 217, 178, 120, 112,  86, 217, 132, 208,  10, 216, 109,  48,
       9, 218,   5, 240, 102, 216,  61,  49, 118, 216,  86,  55, 101, 216, 103,  31,
     102, 184, 127,  63, 105, 183, 151,  61,  42, 181, 167,  94,  89, 180, 183,  32,
     106, 179, 183,  95,  42, 179, 182, 191, 107, 179, 182,  63, 101, 178, 140,  64,
      85, 178, 107,  35,  16, 211,  56,  15 };

const byte Sound_C3_SEMAINE [112] PROGMEM = {
       0, 112,  47,  47, 155, 213,  88,   0,  75, 215,  45,  16,  75, 215, 116, 176,
      27, 213,   5, 112,  11, 212, 173, 112, 217, 179, 101,  47, 229, 180, 109, 168,
     229, 180, 110,  62, 230, 179, 101, 188, 216, 145,  68,  61, 201, 147,  52, 253,
      89, 180,  77,  60, 101, 181, 142,  60, 185, 182, 150,  62, 185, 182, 150,  64,
     249, 182, 141, 223, 228, 183, 133,  32, 170, 183, 125,  64, 251, 182, 109,  95,
     206, 180,  51, 160, 206, 177,  51,  32, 205, 178,  59,  96, 205, 178,  59,  96,
     148, 181,  99,  63, 170, 180, 122, 194, 101, 180, 122,  35, 101, 180, 120,  12 };

const byte Sound_C3_SEPTEMBRE [168] PROGMEM = {
       0, 168,  47,  47,  24, 182, 248,   0,   4, 181, 237,  48,  16, 215, 237, 176,
       1, 214, 237, 208,  20, 214, 214,  80,  21, 214, 174, 112, 244, 182, 118,  43,
     181, 182, 135,  64,  96, 148, 108, 187, 212, 181, 131,  32, 208, 182, 128,  16,
     209, 214, 128,  80,  85, 215, 117,  48,  21, 215,   5, 176, 192, 215, 120,  48,
     132, 215, 112, 112,  10, 184, 252, 144,  85, 182, 125, 176, 166, 180, 134, 190,
     150, 178, 151,  61,  85, 175, 166, 188, 102, 173, 166,  63,  38, 172, 157, 190,
     103, 172, 140, 190,  85, 171, 124,  32,  82, 169, 131, 191,  82, 169, 123,  32,
     150, 169, 147, 191,  25, 164, 155, 192,  24, 162,  99,  32,  76, 169,  58, 190,
     140, 174,  32,  48,  24, 160,   0,  80,  23, 170,  88, 112,  27, 171,   5,  16,
      35, 174, 125, 176, 154, 174, 131, 176, 158, 174, 138, 161,  85, 175,  90, 160,
     106, 177, 121, 165,  90, 176,  96,  12 };

const byte Sound_C3_SON [68] PROGMEM = {
       0,  68,  47,  47,  22, 215, 232,   0,   5, 215, 253, 208,  18, 217, 254, 112,
       6, 214, 254, 112,   2, 214, 254, 176,  70, 218, 254, 208,  38, 172,   6,  72,
      21, 172,   6,  94, 133, 178, 142,  61, 133, 213, 134,  94, 134, 213, 125, 190,
     133, 213, 125,  61, 132, 212, 116, 188, 132, 211, 108,  61, 132, 209,  99, 160,
      68, 173,  80,  14 };

const byte Sound_C3_SUIS [68] PROGMEM = {
       0,  68,  47,  47,  40, 245,  24,   0,  29, 246,   3, 176,  10, 245,   4, 176,
       0, 248, 253, 112,   1, 251, 253, 240,  17, 252, 254, 240,  21, 247, 254,  48,
      21, 183,   6,  15,  34, 152,   6,  68,  34, 184,   6, 127, 118, 184,  54,  60,
     181, 217,  61, 223, 245, 217,  61,  59, 229, 217,  52,  61, 225, 217,  51, 191,
     240, 217,  40,   7 };

const byte Sound_C3_TRAVAIL [152] PROGMEM = {
       0, 152,  47,  47,  65, 183, 232,   0,  98, 179,  93,  48,  96, 180, 172, 176,
     101, 179, 204, 176, 117, 178,   4, 176,  85, 177, 140, 143, 170, 176, 166,  41,
     170, 176, 199,  64, 170, 177, 183,  64, 175, 177, 150,  60, 174, 178, 124, 187,
     174, 177, 124, 144, 173, 177, 108, 176, 105, 177,  28, 176, 109, 177, 108, 155,
     238, 177, 158,  62, 238, 178, 174, 187, 254, 178, 174, 191, 250, 178, 182, 192,
     249, 178, 190, 192, 250, 179, 182,  95, 249, 181, 174,  64, 253, 182, 149, 223,
     233, 182, 133,  32, 233, 183, 125,  32, 249, 215,  93,  64, 249, 215,  84,  63,
     233, 216,  67, 160, 244, 216,  59,  63, 212, 215,  58, 192, 228, 215,  58,  63,
     228, 216,  66, 160, 233, 183,  75,  32, 229, 183,  99,  32, 246, 183,  99,   5,
     246, 183, 107,   1, 246, 182, 112,  14 };

const byte Sound_C3_VOLUME [124] PROGMEM = {
       0, 124,  47,  47,   5, 179,   0,   0,   1, 180,   3, 151,   1, 145,   4, 193,
      21, 175,   5,  34,  17, 174,   5, 168, 106, 173, 110,  40, 107, 173, 118, 164,
     155, 175, 127,  65, 150, 146, 119,  64,  85, 148, 102, 190,  37, 117,  54,  61,
      36, 117,   6,  61,  36, 150,   6, 187,  20, 150,   6,  92,  37, 183,   7,  64,
      32, 184,   7,  95,  32, 183,   7,  95,  32, 151,   6,  95,  73, 151,  61, 191,
     137, 149,  52, 224, 143, 149,  52, 223, 143, 150,  52, 192,  78, 149,  45,  63,
      78, 180,  61,  64,  78, 180,  52, 161,  25, 178,  92, 161, 105, 178, 164, 192,
     106, 178, 172,  64, 106, 178, 155, 160,  25, 178, 128,  15 };


// My own extra's

const byte Sound_OMELETTE [168] PROGMEM = {
       0,  36,  47,  47,   0, 153, 248,   0,  64, 174, 132,  15, 217, 168, 117,  32,
     169, 167, 109,  32, 153, 198, 109,  96, 237, 166, 100,  59, 217, 165,  99, 159,
     148, 165,  88,  28,  68, 181,  48,   0, 132, 181,  58, 148, 132, 154,  43,  32,
     144, 185,  52, 160, 144, 217,  52, 193,  80, 217,  53,  64,  80, 217,  61, 161,
      84, 183,  78,  32, 100, 183,  86, 224, 144, 184,  86, 224, 149, 183,  86,  64,
     252, 182,  96,   0, 164, 182, 108,  19, 248, 182,  92, 160, 232, 182,  93,  32, 
     248, 182,  93, 193, 248, 214,  94,  33, 245, 214,  86,  65,   0, 153, 248,   0,  
      84, 182, 171, 135, 253, 182, 158,  32, 233, 182, 150, 160, 250, 182, 151,  65, 
     168, 183, 135,  64, 244, 183, 118,  33, 232, 183, 117, 191, 233, 183,  92, 190, 
     161, 215, 100,  63, 192, 215, 104, 112, 128, 153, 112, 112,   1, 185, 251, 176,   
      85, 177, 148,  48,  25, 176,  96,  27 };

// One extra and long one from catalog 1 (in base-16)
//
// In my Arduino code the sound samples have a maximum length of 256 bytes.
// Longer samples are split into sections of maximum 256 byte.
//
// "Ici le synthetiseur de parole MEA8000"
// in three parts (max. 256 bytes) 
const byte Sound_INTRO_MEA8000_P1 [256] PROGMEM = {
                            0x02, 0xB0, 0x1F, 0x31, 0x86, 0xD8, 0x70, 0x01, 0x86, 0xD8, 0x74, 0x88,
    0xB6, 0xD9, 0x57, 0x27, 0xA6, 0xD9, 0x4F, 0x41, 0xA6, 0xD9, 0x47, 0x5F, 0xB7, 0xD9, 0x47, 0x3D,
    0xA0, 0xD8, 0x5E, 0xDF, 0x05, 0xF8, 0x56, 0xF0, 0x05, 0xF8, 0x5D, 0xF0, 0xE6, 0xD8, 0x65, 0xC0,
    0xF1, 0xB8, 0x4E, 0x40, 0xF0, 0xD9, 0x4E, 0xC1, 0xE1, 0xD9, 0x47, 0x41, 0xE4, 0xDA, 0x47, 0x41,
    0xE8, 0xDA, 0x46, 0x40, 0xD8, 0xDA, 0x4C, 0x5F, 0x61, 0xB6, 0x30, 0x5E, 0x74, 0xB5, 0x3A, 0x30,
    0x74, 0xB5, 0x54, 0x20, 0x74, 0xB6, 0x2E, 0x5E, 0x74, 0xB5, 0x26, 0x21, 0x28, 0xB5, 0x56, 0x42,
    0x69, 0xB4, 0x76, 0xA0, 0x6A, 0xB4, 0x76, 0xC0, 0x6B, 0xB4, 0x77, 0x40, 0xAB, 0xB4, 0x6E, 0xDE,
    0xEB, 0xB4, 0x5A, 0xBD, 0x42, 0xD7, 0x55, 0x42, 0x23, 0xF8, 0x55, 0x10, 0x06, 0xF7, 0x56, 0x10,
    0x06, 0xF6, 0x5E, 0x30, 0x02, 0xF6, 0x66, 0xD0, 0x02, 0xD6, 0x6F, 0x50, 0x65, 0xB5, 0x6F, 0x2F,
    0xB9, 0xB4, 0x9F, 0x2F, 0xB8, 0xB3, 0xAF, 0x2A, 0x69, 0xB3, 0xA7, 0x25, 0xA8, 0xD4, 0x9F, 0x3F,
    0xA5, 0xB4, 0x7F, 0x20, 0x40, 0xB4, 0x71, 0x5F, 0x54, 0xD3, 0x78, 0x3F, 0x55, 0xF4, 0x75, 0x10,
    0x16, 0xD7, 0x5E, 0x90, 0xE9, 0xB8, 0x66, 0xDF, 0x85, 0xB8, 0x66, 0xBF, 0xD4, 0xB8, 0x44, 0xDE,
    0x99, 0xB7, 0x3B, 0x3F, 0xC5, 0xB7, 0x4A, 0xBF, 0x81, 0xB7, 0x4A, 0x9E, 0x09, 0xF7, 0x4B, 0x10,
    0x4C, 0xF8, 0x4D, 0x10, 0x08, 0xF8, 0x4D, 0x90, 0x8D, 0xD9, 0x4D, 0x9B, 0x84, 0xDA, 0x45, 0xDF,
    0xD5, 0xD9, 0x4D, 0xC1, 0xD9, 0xB8, 0x5D, 0xBA, 0xE6, 0xB7, 0x45, 0xDB, 0x5A, 0xF6, 0x44, 0xB0,
    0x56, 0xF5, 0x4D, 0x30, 0xAA, 0xF5, 0x5D, 0x9A, 0x99, 0xB5, 0x77, 0x28, 0xEA, 0xB4, 0x8F, 0xC3,
    0x5A, 0xB2, 0x87, 0xBE };

const byte Sound_INTRO_MEA8000_P2 [256] PROGMEM = {
                            0x1A, 0xB0, 0x9F, 0xBF, 0x15, 0xAE, 0x87, 0x57, 0x6B, 0xCE, 0x76, 0x3C,
    0x95, 0xCE, 0x53, 0xBC, 0x99, 0xAD, 0x5A, 0xA9, 0x56, 0xD4, 0x5C, 0xAF, 0x9B, 0xB4, 0x5E, 0xAD,
    0x8A, 0xB4, 0x7E, 0xA4, 0x95, 0xB2, 0x7E, 0xBF, 0x96, 0xB1, 0x53, 0x5F, 0xE6, 0xB1, 0x62, 0x3F,
    0x80, 0xB3, 0x60, 0x5E, 0x80, 0xB3, 0x60, 0x02, 0x15, 0xB5, 0x76, 0x90, 0x15, 0xB5, 0x86, 0x90,
    0x55, 0xB4, 0x8D, 0x9C, 0x6A, 0xB1, 0xAF, 0x3E, 0x26, 0xB1, 0xCF, 0xDF, 0x26, 0xB1, 0xCF, 0x9E,
    0x2B, 0xB0, 0xCF, 0x80, 0x57, 0xB0, 0xBF, 0x36, 0x6A, 0xB0, 0xA6, 0xB8, 0x69, 0xB0, 0x9E, 0x3C,
    0x6A, 0xAF, 0x9E, 0x3D, 0x6A, 0xAF, 0xBF, 0x42, 0x6E, 0xB0, 0xA7, 0x40, 0x69, 0xB1, 0x9F, 0x40,
    0xA8, 0xB2, 0x86, 0x41, 0xFC, 0xB3, 0x5D, 0x62, 0xFC, 0xB3, 0x54, 0xFF, 0xFC, 0xB3, 0x5D, 0x23,
    0xBD, 0xB3, 0x8E, 0xC0, 0xFD, 0xB3, 0x9E, 0xC0, 0xBE, 0xB3, 0x96, 0x5F, 0x7E, 0xB3, 0x95, 0x39,
    0x99, 0xB3, 0x92, 0x5E, 0xD4, 0xB3, 0x91, 0x22, 0xD5, 0xB3, 0x98, 0x7C, 0xD5, 0xB3, 0x98, 0x60,
    0xD5, 0xB3, 0x98, 0x60, 0xD5, 0xB3, 0x98, 0x60, 0xD5, 0xB3, 0x98, 0x60, 0xD5, 0xB3, 0x98, 0x60,
    0xD5, 0xB3, 0x98, 0x60, 0x65, 0xB5, 0xB4, 0xCF, 0xB6, 0xB6, 0xA7, 0x2F, 0xAA, 0xB6, 0x9F, 0xAF,
    0xAA, 0xB6, 0x8F, 0xA0, 0xBA, 0xB6, 0x87, 0xBF, 0xBA, 0xB6, 0x97, 0xBF, 0xAA, 0xB6, 0x97, 0xBF,
    0xAB, 0xB4, 0x7F, 0x3E, 0x9A, 0x94, 0x55, 0xBF, 0x6E, 0xB3, 0x35, 0xBD, 0x6E, 0xB3, 0x4D, 0xBE,
    0x6E, 0xB3, 0x45, 0xBD, 0x6E, 0xB2, 0x45, 0xBE, 0xAE, 0xB2, 0x45, 0xDD, 0xAE, 0xB2, 0x44, 0x5E,
    0xAB, 0xB1, 0x54, 0x3D, 0xFA, 0xB2, 0x6A, 0x5F, 0x65, 0xB2, 0x71, 0x30, 0x65, 0xB2, 0x70, 0x10,
    0x65, 0xB2, 0x70, 0x70 }; 
    
const byte Sound_INTRO_MEA8000_P3 [176] PROGMEM = {
                            0x00, 0xB3, 0x80, 0x30, 0x66, 0xB3, 0xAC, 0x30, 0x6B, 0xB3, 0x9E, 0x3C,
    0xAF, 0xB3, 0x97, 0x5F, 0x6B, 0xB3, 0x87, 0x7E, 0xBB, 0xB3, 0x8E, 0xA2, 0xFB, 0xB3, 0x8B, 0x5E,
    0xD6, 0xB2, 0x81, 0xA0, 0xC6, 0xB1, 0x79, 0x9E, 0x29, 0xB0, 0x90, 0x62, 0x2D, 0xB1, 0xBD, 0xA4,
    0x6F, 0xB1, 0xD6, 0xC1, 0xAE, 0xB1, 0xCE, 0xDF, 0x69, 0xB1, 0xD7, 0x3F, 0x6E, 0xB1, 0xCF, 0x5F,
    0xBF, 0xB1, 0xBE, 0xFF, 0x6A, 0xB1, 0xAC, 0xC0, 0xA5, 0xAF, 0x99, 0xC0, 0xA0, 0xB0, 0x90, 0x27, 
    0xA0, 0xB0, 0x90, 0x60, 0xA0, 0xB0, 0x90, 0x60, 0xA0, 0xB0, 0x90, 0x60, 0x56, 0xB7, 0x59, 0x7D,
    0xD7, 0x96, 0x43, 0xA4, 0xE7, 0x95, 0x44, 0x5F, 0xB6, 0xB5, 0x45, 0xC5, 0xA7, 0x97, 0x46, 0x2B,
    0x57, 0xB9, 0x3E, 0xAE, 0x4A, 0xB8, 0x2F, 0x25, 0x5A, 0xB8, 0x47, 0xAA, 0xA6, 0xB8, 0x36, 0xDE,
    0x90, 0x99, 0x45, 0x3A, 0x8A, 0x95, 0x3C, 0xBA, 0x8A, 0x94, 0x4D, 0x59, 0x51, 0xB8, 0x5F, 0x3B,
    0xEA, 0xB8, 0x66, 0xB9, 0xEC, 0xB8, 0x55, 0xDB, 0xE8, 0xB8, 0x64, 0xDE, 0xBD, 0xB5, 0x5C, 0xFD,
    0xBC, 0xB4, 0x64, 0xFE, 0xFD, 0xB3, 0x5C, 0xFF, 0xBD, 0xB3, 0x5C, 0xA1, 0xBD, 0xB4, 0x94, 0xC0,
    0xAD, 0xB3, 0x98, 0x45 };

// end of data

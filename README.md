
    MEA8000_Sounds.cpp

    This is a data collections of MEA8000 sounds, the ones I know of.
    It's mainly a collection of data from French BASIC programs and French data sets. 
    This data is copied and OCR-ed from 1980's scanned printouts.
    The code in this file is for Arduino projects. Via <avr/pgmspace.h> the data will not
    be copied to the microcontrollers RAM but will 'stay put' in the much bigger Flash memory.
    The first part of the dataset has data in hexadecimal format (base-16).
    Catalog 2 and 3 have data in decimal format (base-10).

    I asume that if you need this data in another programming language (of environment) it will
    be easy to reformat the code.

    Info on the Philips MEA8000 voice synthesizer chip: 
    http://c.papy.free.fr/ZX81/original/mea8000-1.pdf


    version 0.1     (2021-07-07)        First collected set - based on the sets in my current code
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

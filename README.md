
    MEA8000_Sounds.cpp

    This is a dataset of MEA8000 sounds, the ones I know.
    It's mainly a collection of data from French BASIC programs and French datasets. 
    This data was copied and OCR-ed from scanned prints from the 1980s.
    The code in this file is for Arduino projects. Via <avr/pgmspace.h> the data will not
    be copied into the microcontrollers RAM but will 'stay put' in the Flash memory.
    The first part of the dataset has data in hexadecimal format (base-16).
    Catalog 2 and 3 have data in decimal format (base-10).

    (I asume that if you need this data in another programming language (or environment) it will
    be easy to reformat the code.)

    Info on the Philips MEA8000 voice synthesizer chip:\
    http://c.papy.free.fr/ZX81/original/mea8000-1.pdf


    version 0.1     (2021-07-07)        First collected set - based on the sets in my current code\
    version 1.0     (2021-07-16)        All OCR-ed docs - Some of catalog 1 and all of catalog 2 and 3.\
                                        OCR data tested with check sums and manually edited

    (cl) 2014, 2021 by Arno Jacobs
    

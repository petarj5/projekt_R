#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include "io.h"
#include "generator.h"

void generateSignal(int freq) {
    float value;
    const char *filePath = "resources/input.bin";
    int fd = open(filePath, O_WRONLY | O_CREAT, 0777);
    
    printf("%d\n", fd);

    for (int i = 0; i < freq; i++) {
        value = (float) sin(2 * M_PI *50 * i / freq);

        void *a = (void *) &value;
        int value_ieee = *((int *) a);
        int value_int = (int) value_ieee;

        write_word(fd, value_int);
    }
}
#ifndef SLOWPRINT
#define SLOWPRINT

#include <stdio.h>
#include <unistd.h>

void slow_print(char *str) {
    char *temp = str;
    
    while (*temp != '\0') {
        printf("%c", *temp);
        temp++;
        usleep(10000);
    }
}

#endif
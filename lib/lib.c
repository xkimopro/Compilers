#include <stdio.h>
#include <stdbool.h>

void writeInteger(int n) {
    printf("%d", n);
}

void writeBoolean(bool b) {
    if (b) {
        printf("true");
    } else {
        printf("false");
    }
}

void writeChar(char c) {
    printf("%c", c);
}

void writeReal(float f) {
    printf("%f", f);
}

void writeString(char* s) {
    printf("%s", s);
}


#include <stdio.h>

void drawLine(int len) {
    int k;
    for (k = 0; k < len; k++)
        printf("*");
}

void drawRect(int height, int width) {
    int k;
    for (k = 0; k < height; k++) {
        drawLine(width);
        printf("\n");
    }
}

void drawSquare(int len) {
    drawRect(len, len);
}
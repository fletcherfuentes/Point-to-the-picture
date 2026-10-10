
#ifndef CANVAS_MAKE
#define CANVAS_MAKE

char** createCanvas(int width, int height);
void printCanvas(char **canvas, int height, int width);
void freeCanvas(char **canvas, int width);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char genRandomChar(char *charList, int size);
char pickChar(char *charList);
char** createCanvas(int width, int height);
void printCanvas(char **canvas, int height, int width);
void freeCanvas(char **canvas, int height, int width);

char genRandomChar(char *charList, int size){
    int n =rand()%size;
    return charList[n];
}



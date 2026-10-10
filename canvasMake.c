#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static char pickChar(char *charList, int size);
static char genRandomChar(char *charList);
char** createCanvas(int width, int height);
void printCanvas(char **canvas, int height, int width);
void freeCanvas(char **canvas, int height, int width);

static char pickChar(char *charList, int size){
    srand(time(NULL));
    int n =rand()%size;
    return charList[n];
}

static char genRandomChar(char *charList, int size, float chance){
    srand(time(NULL));
    chance = (chance*10)+8;
    char pickedChar = pickChar(*charList, size);
    int n=rand()%chance;
    if(n>=7) return pickedChar;

    return ' ';
}

char
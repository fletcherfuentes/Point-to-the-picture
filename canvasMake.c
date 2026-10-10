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
    char pickedChar = pickChar(charSelection, size);
    int n=rand()%chance;
    if(n>=7) return pickedChar;

    return ' ';
}

char** createCanvas(int width, int height){
    char **canvas = malloc(width * sizeof(char*));
    for(int i =0; i<width; i++){
        canvas[i] = malloc(height * sizeof(char));
    }
    return canvas; 
}

void printCanvas(char **canvas, int height, int width){
    for (int i = 0; i < width; i++ ){
        for(int j = 0; j< height; j++) canvas[i][j] = genRandomChar(charSelection, size, 0.2);
    }
    for (int i = 0; i < width; i++ ){
        for(int j = 0; j< height; j++) printf("%c", canvas[i][j]);
       printf("\n"); 
    }
}

void freeCanvas(char **canvas, int width){
    for(int i =0; i<width; i++){
        free(canvas[i]);
    }
    free(canvas);
}

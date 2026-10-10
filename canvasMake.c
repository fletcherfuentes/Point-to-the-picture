// fletcher file to declare and create the 5 required functions 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// global variables to use for static funtions
char charSelection[] = {'!','#','%','^','*'};
int size = 5;
float chance = 0.2;

static char pickChar(char *charList, int size);
static char genRandomChar(char *charList, int size, float chance);
char** createCanvas(int width, int height);
void printCanvas(char **canvas, int height, int width);
void freeCanvas(char **canvas, int width);

// static function to hide from header file takes the charSelection variable
// and size to get a random variable from the array selection
static char pickChar(char *charList, int size){
    int n =rand()%size;
    return charList[n];
}
// static function to hide from header file takes the charSelection variable
// size and the chance to get a character
static char genRandomChar(char *charList, int size, float chanceConvert){
    int localChance = (chanceConvert*10)+8; // converts the chance decimal so it can be divided by rand
    char pickedChar = pickChar(charSelection, size);
    int n=rand()%localChance;
    if(n>=7) return pickedChar;

    return ' ';
}

// function that takes the users 2 inputs to make the size of the array
char** createCanvas(int width, int height){
    char **canvas = malloc(width * sizeof(char*));
    for(int i =0; i<width; i++){
        canvas[i] = malloc(height * sizeof(char));
    }
    return canvas; 
}

// function that takes the just made canvas and the 2 user inputs for use in the for statements to generate a random character for [i][j]
// and prints [i][j] in the next nested for loop
void printCanvas(char **canvas, int height, int width){
    for (int i = 0; i < width; i++ ){
        for(int j = 0; j< height; j++) canvas[i][j] = genRandomChar(charSelection, size, chance);
    }
    for (int i = 0; i < width; i++ ){
        for(int j = 0; j< height; j++) printf("%c", canvas[i][j]);
       printf("\n"); 
    }
}

// takes the width of the array and the array and frees it
void freeCanvas(char **canvas, int width){
    for(int i =0; i<width; i++){
        free(canvas[i]);
    }
    free(canvas);
}

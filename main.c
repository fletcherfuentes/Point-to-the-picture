#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "canvasMake.h"

int main(int argc, char **argv){
    srand(time(NULL));
    if (argc != 3){
        printf("You need two arguments\n");
        return 1;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    char **canvas = createCanvas(num1, num2);
    printCanvas(canvas, num1, num2);
    freeCanvas(canvas, num1);


    
    
    
    return 0;
}
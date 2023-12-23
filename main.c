#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int boardDim; // defining game variables for more info check comments in gameplay.c
int board1_horiz [3][3];
int board1_vert [3][3];
int board2_horiz [6][6];
int board2_vert [6][6];
int s1[3][3];
int s2[6][6];
int r1,r2,c1,c2;
int Size, input;
char extra;
char name[50];
char ranking[11];
const char *filename = "ranking.csv";
FILE *savedGame;

int main()
{




Game_main_menu ();


    return 0;
}

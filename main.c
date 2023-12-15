#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int boardDim; // defining game variables for more info check comments in gameplay.c
int board1_horiz [3][3];
int board1_vert [3][3];
int board2_horiz [6][6];
int board2_vert [6][6];
int r1,r2,c1,c2;
int Size;


int main()
{

Hello_to_Game ();
Determine_Dim (boardDim);

    return 0;
}

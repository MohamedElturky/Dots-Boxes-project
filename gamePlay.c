#include <stdio.h>
#include<stdlib.h>
void initilaize_Board_2 (){
   int row=0,column=0;
   int board [3][3];

      printf("   ");
   for (column=0 ; column<3 ; column++) printf("%d    ",column+1);
      printf("\n\n");
   for(row=0 ; row<3 ;row++){
       printf("%d  ",row+1);
       for (column=0 ; column<3 ; column++){
        board[row][column]='*';
        printf("%c    ",board[row][column]);
       }
       printf("\n\n\n");

   }

}
void initilaize_Board_5 (){


   int row=0,column=0;
   int board [6][6];

      printf("   ");
   for (column=0 ; column<6 ; column++) printf("%d    ",column+1);
       printf("\n\n");
   for(row=0 ; row<6 ;row++){
       printf("%d  ",row+1);
       for (column=0 ; column<6 ; column++){
        board[row][column]='*';
        printf("%c    ",board[row][column]);
       }
       printf("\n\n\n");

   }

}
void Determine_Dim (int boardDim){
scanf("%d",&boardDim);
 switch(boardDim){
 case 1: initilaize_Board_2();
    break;
 case 2: initilaize_Board_5();
    break;
 default: {printf("Enter 1 or 2\n");
    Determine_Dim(boardDim);}
 }
}
void Hello_to_Game (){

 printf("Dots and Boxes\n\nChoose the game Dimension!\n");
 printf("2*2    [1]\n");
 printf("5*5    [2]\n");
}

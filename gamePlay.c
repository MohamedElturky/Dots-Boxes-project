#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "functions.h"

void initilaize_Board(int board_horiz [Size][Size],int board_vert [Size][Size]){ //initializing the board
      int row=0,column=0;
      printf("   ");
   for (column=0 ; column<Size ; column++) printf("%d   ",column+1);
      printf("\n\n");
    for(row=0 ; row<Size ;row++){
        printf("%d  ",row+1);
    for (column=0 ; column<Size ; column++){
        board_horiz[row][column]=' '; // initializing an array for horizontal dashes -
        printf("*%c%c%c",board_horiz[row][column],board_horiz[row][column],board_horiz[row][column]);
    }
        printf("\n");
    for (column=0 ; column<Size ; column++){
        board_vert[row][column]=' '; // initializing an array for vertical dashes |
        printf("   %c",board_vert[row][column]);
    }
       printf("\n");
   }
}
void Determine_Dim (int boardDim){
scanf("%d",&boardDim);
 switch(boardDim){
 case 1: {
     Size=3; // choosing the size of board if it is 2*2 then the arrays will be [3][3]
     Human_vs_Human(board1_horiz,board1_vert,Size);}
    break;
 case 2: {
     Size=6;  // choosing the size of board if it is 2*2 then the arrays will be [6][6]
     Human_vs_Human(board2_horiz,board2_vert,Size);}
    break;
 default: {printf("Enter 1 or 2\n");
    Determine_Dim(boardDim);}
 }
}
void Hello_to_Game (){ // hello friend :)
 printf("Dots and Boxes\n\nChoose the game Dimension!\n");
 printf("2*2  (beginner)   Enter [1]\n");
 printf("5*5  (expert)     Enter [2]\n");
}
void print_board(int board_horiz[Size][Size],int board_vert[Size][Size],int Size){ //printing the board after each move has the same syntax of initialize Board func without assignment
 int row=0,column=0;


      printf("   ");
   for (column=0 ; column<Size ; column++) printf("%d   ",column+1);
      printf("\n\n");
   for(row=0 ; row<Size ;row++){
       printf("%d  ",row+1);
       for (column=0 ; column<Size ; column++){

        printf("*%c%c%c",board_horiz[row][column],board_horiz[row][column],board_horiz[row][column]);
       }
       printf("\n");


       for (column=0 ; column<Size ; column++){

        printf("   %c",board_vert[row][column]);
       }

       printf("\n");
   }

}
void player1_turn(int board_horiz[Size][Size],int board_vert[Size][Size],int*p1,int*p2){ //player 1 turn func with parameters 1-the horizontal array 2-the vertical array 3-pointer to player 1 score 4-pointer to player 2 score
  End_Game(Size,p1,p2); // check if the game has ended
  printf("Player 1 turn Enter (RRCC) ");
  scanf("%1d%1d%1d%1d",&r1,&r2,&c1,&c2); // scanning the input
  while((r1>Size || r2>Size ||c1>Size || c2>Size ) || (r1<1||r2<1||c1<1||c2<1) ) { // conditions for the input of precise size between 1 and size
    printf("Enter a correct place\n\n");
    scanf("%1d%1d%1d%1d",&r1,&r2,&c1,&c2);
  }
  if (r1==r2 && c1!=c2 && fabs(c1-c2)==1 && board_horiz[r1-1][c1-1]!='-'){ // here are the conditions for input if the input is horizontal  note: here i used the absolute function to neglect the order of input like 2212 and 2221
    board_horiz[r1-1][(c2>c1)?(c1-1):(c2-1)]='-'; // assignment of move  note again: the ternary operator is used as caution of the input order
    print_board(board_horiz,board_vert,Size); // print the board
    Game_score(board_horiz,board_vert,Size,p1,p2,(p1)); // calculating the score
    print_scores(*p1,*p2); // print the scores
   player2_turn(board_horiz,board_vert,p1,p2); // it is time for the another player move
  }
   else if (c1==c2 && r1!=r2 && fabs(r1-r2)== 1 && board_vert[r1-1][c1-1]!='|') { // here are the conditions for input if the input is vertical
    board_vert[(r2>r1)?(r1-1):(r2-1)][c1-1]='|';
    print_board(board_horiz,board_vert,Size);
    Game_score(board_horiz,board_vert,Size,p1,p2,(p1));
    print_scores(*p1,*p2);
   player2_turn(board_horiz,board_vert,p1,p2);
   }
   else{printf("Enter a correct place\n\n"); // another try to enter the input if it was wrong
   player1_turn(board_horiz,board_vert,p1,p2);}
}
void player2_turn(int board_horiz[Size][Size],int board_vert[Size][Size],int*p1,int*p2){ // same as player 1 func
  End_Game(Size,p1,p2);
  printf("Player 2 turn Enter (RRCC) ");
  scanf("%1d%1d%1d%1d",&r1,&r2,&c1,&c2);
  while(( r1>Size|| r2>Size || c1>Size || c2>Size) || (r1<1||r2<1||c1<1||c2<1) ) {
    printf("Enter a correct place\n\n");
    scanf("%1d%1d%1d%1d",&r1,&r2,&c1,&c2);
  }
  if (r1==r2 && c1!=c2 && fabs(c1-c2)==1 && board_horiz[r1-1][c1-1]!='-'){
    board_horiz[r1-1][(c2>c1)?(c1-1):(c2-1)]='-';
    print_board(board_horiz,board_vert,Size);
    Game_score(board_horiz,board_vert,Size,p1,p2,(p2));
    print_scores(*p1,*p2);
   player1_turn(board_horiz,board_vert,p1,p2);
  }
   else if (c1==c2 && r1!=r2 && fabs(r1-r2)== 1 && board_vert[r1-1][c1-1]!='|') {
    board_vert[(r2>r1)?(r1-1):(r2-1)][c1-1]='|';
    print_board(board_horiz,board_vert,Size);
    Game_score(board_horiz,board_vert,Size,p1,p2,(p2));
    print_scores(*p1,*p2);
   player1_turn(board_horiz,board_vert,p1,p2);
   }
   else{printf("Enter a correct place\n\n");
   player2_turn(board_horiz,board_vert,p1,p2);}
}
void Human_vs_Human (int board_horiz [Size][Size],int board_vert [Size][Size],int Size){ //choosing the mode  Note this func id called in Determine Dim func and will be changed later

   int *p1=&player1_score; // referring the pointer to the address of score variable
   int *p2=&player2_score;
   initilaize_Board(board_horiz,board_vert);
   player1_turn(board_horiz,board_vert,p1,p2); // here the first turn will be called
}
void Game_score (int board_horiz[Size][Size],int board_vert[Size][Size],int Size,int* p1,int* p2,int* Current_Player_Score){ /* the most important function that calculates scores VIP ,
                                                            Note:the last parameter is to detect the current player that has made the last turn and it has previous value of either p1 or p2 depem*/

    int count_scores=0; //create var to store the sum scores for both players
    for (int row=0 ; row<Size-1 ;row++){
        for (int column=0 ; column<Size-1 ;column++){
            if (board_horiz[row][column]=='-' && board_vert[row][column]=='|' && board_horiz[row+1][column]=='-' && board_vert[row][column+1]=='|'){
                count_scores++; /*looping inside both horizontal and vertical array and check if the box is filled by using the above conditions
                                  then adding 1 for each score in the variable count_scores */
            }

        }
    }
     if (count_scores> *(p1) + *(p2)){//the next step if the score is updated during the last turn the var count_scores will be greater than sum of both scores recorded
                    *Current_Player_Score += count_scores - (*p1 + *p2);//here the
                    if(*Current_Player_Score == *p1) {
                        print_scores(*p1,*p2);
                        player1_turn(board_horiz,board_vert,p1,p2);
                    }
                    else {
                        print_scores(*p1,*p2);
                        player2_turn(board_horiz,board_vert,p1,p2);
                    }
                }
}
void print_scores (int player1_score, int player2_score){ //just printing the score ..boring..Zzz
   printf("player 1 score : %d\n",player1_score);
   printf("player 2 score : %d\n\n",player2_score);
}
void End_Game (int Size,int* p1,int* p2){ // func to check if the game has ended
        if (*(p1) + *(p2) == (Size-1)*(Size-1)){ // look at this line it will check if the  sum scores = equal the number of boxes and i think this approach is easier than looping

    if (*p1 > *p2) printf("Player 1 is the winner\n"); // no need for explanation
    else printf("Player 2 is the winner\n");
    exit(0); // function to terminate the recursion
    }
}

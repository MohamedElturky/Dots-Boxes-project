#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "functions.h"
clock_t startTime;
int Horiz_or_Vert;


void Human_vs_Comp(int board_horiz [Size][Size],int board_vert [Size][Size],int s[Size][Size],int Size){
   player player1;
   player comp;
   player1.score=0;
   comp.score=0;
   player1.numOfMoves=0;
   comp.numOfMoves=0;
   startTime=clock();
   int *n1=&player1.numOfMoves;
   int *n2=&comp.numOfMoves;
   int *p1=&player1.score; // referring the pointer to the address of score variable
   int *p2=&comp.score;
   clearScreen();
   initilaize_Board(board_horiz,board_vert);

   player_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
}
void player_turn(int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int*p1,int*p2,int*n1,int*n2){ //player 1 turn func with parameters 1-the horizontal array 2-the vertical array 3-pointer to player 1 score 4-pointer to player 2 score
  End_Game(Size,p1,p2); // check if the game has ended
  printf("\x1B[34m""Player 1 turn Enter (RRCC) ""\x1B[0m");
  while(scanf("%1d%1d%1d%1d%c",&r1,&r2,&c1,&c2,&extra) != 5 || extra != '\n'){ // scan and check if the input is not digits
        printf("\x1B[34m""Enter a correct place\n""\x1B[0m");
        printf("\x1B[34m""Player 1 turn Enter (RRCC): ""\x1B[0m");
        while (getchar()!='\n');
}
  if (r1==r2 && c1!=c2 && fabs(c1-c2)==1 && board_horiz[r1-1][(c2>c1)?(c1-1):(c2-1)]==' '&& (r1<=Size && r2<=Size && c1<=Size && c2<=Size ) && (r1>=1 && r2>=1 &&c1>=1 && c2>=1)){ // here are the conditions for input if the input is horizontal  note: here i used the absolute function to neglect the order of input like 2212 and 2221
    board_horiz[r1-1][(c2>c1)?(c1-1):(c2-1)]=1; // assignment of move  note again: the ternary operator is used as caution of the input order
    Game1_score(board_horiz,board_vert,s,Size,p1,p2,1,n1,n2);// calculating the score
    clearScreen();
    print_board(board_horiz,board_vert,s,Size); // print the board
    (*n1)++;
    print_scores(Size,*p1,*p2,*n1,*n2); // print the scores
    Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2); // it is time for the another player move
  }
   else if (c1==c2 && r1!=r2 && fabs(r1-r2)== 1 && board_vert[(r2>r1)?(r1-1):(r2-1)][c1-1]==' '&& (r1<=Size && r2<=Size && c1<=Size && c2<=Size ) && (r1>=1 && r2>=1 &&c1>=1 && c2>=1)) { // here are the conditions for input if the input is vertical
    board_vert[(r2>r1)?(r1-1):(r2-1)][c1-1]=1;
    Game1_score(board_horiz,board_vert,s,Size,p1,p2,1,n1,n2);
    clearScreen();
    print_board(board_horiz,board_vert,s,Size);
    (*n1)++;
    print_scores(Size,*p1,*p2,*n1,*n2);
    Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
   }
   else{printf("\x1B[34m""Enter a correct place\n""\x1B[0m"); // another try to enter the input if it was wrong
   player_turn(board_horiz,board_vert,s,p1,p2,n1,n2);}
}
void Comp_turn(int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int*p1,int*p2,int*n1,int*n2){ // same as player 1 func
     End_Game(Size,p1,p2);

    if (completing_square(board_horiz,board_vert,Size))
        random_move(board_horiz,board_vert,Size);
    Game1_score(board_horiz,board_vert,s,Size,p1,p2,2,n1,n2);
    clearScreen();
    print_board(board_horiz,board_vert,s,Size);
    (*n2)++;
    print_scores(Size,*p1,*p2,*n1,*n2);
    player_turn(board_horiz,board_vert,s,p1,p2,n1,n2);


}
void Game1_score (int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int Size,int* p1,int* p2,int Current_Player,int*n1,int*n2){ /* the most important function that calculates scores VIP ,
                                                            Note:the current_player parameter is to detect the current player that has made the last turn and it has previous value of either p1 or p2 depem*/
    int count_scores=0; //create var to store the sum scores for both players
    for (int row=0 ; row<Size-1 ;row++){
        for (int column=0 ; column<Size-1 ;column++){
            if (board_horiz[row][column]!=' ' && board_vert[row][column]!=' ' && board_horiz[row+1][column]!=' ' && board_vert[row][column+1]!=' '){
                count_scores++; /*looping inside both horizontal and vertical array and check if the box is filled by using the above conditions
                                  then adding 1 for each score in the variable count_scores */

                if(s[row][column]==0)//check if the score box is completed if not marks it with player number and later will change to player color
                s[row][column]=Current_Player;
            }
        }
    }
     if (count_scores> *(p1) + *(p2)){//the next step if the score is updated during the last turn the var count_scores will be greater than sum of both scores recorded
                    if(Current_Player == 1) {
                        *p1 += count_scores-(*p1 + *p2);
                        clearScreen();
                        print_board(board_horiz,board_vert,s,Size);
                        (*n1)++;
                        print_scores(Size,*p1,*p2,*n1,*n2);
                        player_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
                    }
                    else {
                        *p2 += count_scores-(*p1 + *p2);
                        clearScreen();
                        print_board(board_horiz,board_vert,s,Size);
                        (*n2)++;
                        print_scores(Size,*p1,*p2,*n1,*n2);
                        Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
                    }
     }
}
void random_move (int board_horiz [Size][Size],int board_vert [Size][Size],int Size){
   int i=0,j=0;
   int random_H;
   int random_V;
    for (int row=0 ; row<Size ;row++){
        for (int column=0 ; column<Size-1 ;column++){
            if(board_horiz[row][column] == ' ') i++;
        }
    }
        for (int row=0 ; row<Size-1 ;row++){
           for (int column=0 ; column<Size ;column++){
               if(board_vert[row][column] == ' ') j++;
        }
    }
    srand(time(NULL));
    if (i!=0)
     random_H = rand() % i ;
    if (j!=0)
     random_V = rand() % j ;
    int count =0;
    int found =0;
    int H_or_V = rand() % 2;

    if (H_or_V == 0 && i != 0){
    for (int row=0 ; row<Size ;row++){
        for (int column=0 ; column<Size-1 ;column++){
            if(!found) {
                if(board_horiz[row][column] == ' ') {
                    if (random_H == count){
                       board_horiz[row][column] = 2;
                       found = 1;
                    }
                       count++;
                }
            }
        }
    }
    }
    else if (H_or_V == 1 && j != 0){
    for (int row=0 ; row<Size-1 ;row++){
        for (int column=0 ; column<Size ;column++){
            if(!found) {
                if(board_vert[row][column] == ' ') {
                    if (random_V == count){
                       board_vert[row][column] = 2;
                       found = 1;
                    }
                       count++;
                }
            }
        }
    }
    }
    else {
        if (i!=0){
            for (int row=0 ; row<Size ;row++){
               for (int column=0 ; column<Size-1 ;column++){
                  if(!found) {
                    if(board_horiz[row][column] == ' ') {
                      if (random_H == count){
                        board_horiz[row][column] = 2;
                        found = 1;
                      }
                        count++;
                    }
                  }
               }
            }
        }
        else{
             for (int row=0 ; row<Size-1 ;row++){
                for (int column=0 ; column<Size ;column++){
                    if(!found) {
                       if(board_vert[row][column] == ' ') {
                           if (random_V == count){
                             board_vert[row][column] = 2;
                             found = 1;
                           }
                       count++;
                       }
                     }
                }
            }
        }
    }
}
int completing_square (int board_horiz [Size][Size],int board_vert [Size][Size],int Size){

  int found =0;

  for (int row=0 ; row<Size-1 ;row++){
        if(!found){
        for (int column=0 ; column<Size-1 ;column++){
            if (board_horiz[row][column]!=' ' && board_vert[row][column]!=' ' && board_horiz[row+1][column]!=' ' && board_vert[row][column+1]==' '){
            board_vert[row][column+1]=2;
            found=1;
            return 0;
            break;
        }
                    if (board_horiz[row][column]!=' ' && board_vert[row][column]!=' ' && board_horiz[row+1][column]==' ' && board_vert[row][column+1]!=' '){
            board_horiz[row+1][column]=2;
            found=1;
            return 0;
            break;
        }
                    if (board_horiz[row][column]!=' ' && board_vert[row][column]==' ' && board_horiz[row+1][column]!=' ' && board_vert[row][column+1]!=' '){
            board_vert[row][column]=2;
            found=1;
            return 0;
            break;
        }
                    if (board_horiz[row][column]==' ' && board_vert[row][column]!=' ' && board_horiz[row+1][column]!=' ' && board_vert[row][column+1]!=' '){
            board_horiz[row][column]=2;
            found=1;
            return 0;
            break;
        }

        }
   }
  }
  if(found == 0) return 1;
}

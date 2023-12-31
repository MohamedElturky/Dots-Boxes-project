#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "functions.h"

int redo_log1[13][4];
int redo_log2[61][4];
int c=0;
int undoM=0;
int redoM=0;
void undo (int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int Size,int* p1,int* p2,int Current_Player,int*n1,int*n2,int DimRow,int DimCol ,int orient){
      if(*n1+*n2 != 0){
         undoM=1,redoM=0;
         if (Size == 3) {
          while (c>=0){
             (redo_log1[*n1+*n2-1][3] == 'h')? (board_horiz[redo_log1[*n1+*n2-1][0]][redo_log1[*n1+*n2-1][1]] = ' ') : (board_vert[redo_log1[*n1+*n2-1][0]][redo_log1[*n1+*n2-1][1]] = ' ');
             (redo_log1[*n1+*n2-1][2] == 1)?((*n1)--):((*n2)--);
              c--;
          }
           c=0;
             clearScreen();
             Game_score(board_horiz,board_vert,s,Size,p1,p2,Current_Player,n1,n2,DimRow,DimCol,orient);
             print_board(board_horiz,board_vert,s,Size);
             print_scores(Size,*p1,*p2,*n1,*n2);
            (redo_log1[*n1+*n2][2] == 1)? player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);

         }
         else if (Size == 6) {
         while (c>=0){
             (redo_log2[*n1+*n2-1][3] == 'h')? (board_horiz[redo_log2[*n1+*n2-1][0]][redo_log2[*n1+*n2-1][1]] = ' ') : (board_vert[redo_log2[*n1+*n2-1][0]][redo_log2[*n1+*n2-1][1]] = ' ');
             (redo_log2[*n1+*n2-1][2] == 1)?((*n1)--):((*n2)--);
              c--;
          }
              c=0;
             clearScreen();
             Game_score(board_horiz,board_vert,s,Size,p1,p2,Current_Player,n1,n2,DimRow,DimCol,orient);
             print_board(board_horiz,board_vert,s,Size);
             print_scores(Size,*p1,*p2,*n1,*n2);
            (redo_log2[*n1+*n2][2] == 1)? player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2): player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
         }
      }
      else {
        printf("No undo\n");
        (Current_Player == 1) ? player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
      }

}
void redo (int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int Size,int* p1,int* p2,int Current_Player,int*n1,int*n2,int DimRow,int DimCol ,int orient){
undoM=0,redoM = 1;
if (Size == 3) {
         if (redo_log1[*n1+*n2][3] != ' '){

(redo_log1[*n1+*n2][3] == 'h')? (board_horiz[redo_log1[*n1+*n2][0]][redo_log1[*n1+*n2][1]] = redo_log1[*n1+*n2][2]) : (board_vert[redo_log1[*n1+*n2][0]][redo_log1[*n1+*n2][1]] = redo_log1[*n1+*n2][2]);
             (redo_log1[*n1+*n2][2] == 1)?((*n1)++):((*n2)++);
             clearScreen();
             Game_score(board_horiz,board_vert,s,Size,p1,p2,Current_Player,n1,n2,DimRow,DimCol,orient);
             print_board(board_horiz,board_vert,s,Size);
             print_scores(Size,*p1,*p2,*n1,*n2);
            (redo_log1[*n1+*n2][2] == 1)? player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);

         }
         else {
             printf("No redo\n");
            (Current_Player == 1) ? player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
         }
}
         else if (Size == 6) {
           if (redo_log2[*n1+*n2][3] != ' '){

             (redo_log2[*n1+*n2][3] == 'h')? (board_horiz[redo_log2[*n1+*n2][0]][redo_log2[*n1+*n2][1]] = redo_log2[*n1+*n2][2]) : (board_vert[redo_log2[*n1+*n2][0]][redo_log2[*n1+*n2][1]] = redo_log2[*n1+*n2][2]);
             (redo_log2[*n1+*n2+1][2] == 1)?((*n1)++):((*n2)++);
             clearScreen();
             print_board(board_horiz,board_vert,s,Size);
             Game_score(board_horiz,board_vert,s,Size,p1,p2,Current_Player,n1,n2,DimRow,DimCol,orient);
             print_scores(Size,*p1,*p2,*n1,*n2);
            (redo_log2[*n1+*n2][2] == 1)? player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2): player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
           }
          else {
        printf("No redo\n");
        (Current_Player == 1) ? player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
      }
         }
}
void saveRedoLog (int Size,int DimRow,int DimCol ,int orient,int Current_Player,int*n1,int*n2){
     if (Size == 3){
        redo_log1 [*n1+*n2][0] = DimRow;
        redo_log1 [*n1+*n2][1] = DimCol;
        redo_log1 [*n1+*n2][2] = Current_Player;
        redo_log1 [*n1+*n2][3] = orient;
        if(*n1+*n2 != 12)
        (Current_Player == 1)?((*n1)++):((*n2)++);
        redo_log1[12][0]= Current_Player;
        redo_log1[12][1]= *n1;
        redo_log1[12][2]= *n2;
      }

     if (Size == 6){
        redo_log2 [*n1+*n2][0] = DimRow;
        redo_log2 [*n1+*n2][1] = DimCol;
        redo_log2 [*n1+*n2][2] = Current_Player;
        redo_log2 [*n1+*n2][3] = orient;
        if(*n1+*n2 != 60)
        (Current_Player == 1)?((*n1)++):((*n2)++);
        redo_log2[60][0]= Current_Player;
        redo_log2[60][1]= *n1;
        redo_log2[60][2]= *n2;
     }
}
void initialize_Redo_Log (int Size,int*n1,int*n2,int mode){
      if(Size == 3){
       for (int row = 0 ;row < 12 ;row++){
        for (int col =0 ; col < 4 ; col++){
            redo_log1[row][col] = ' ';
        }
       }
       redo_log1[12][0]=0;
       redo_log1[12][1]=0;
       redo_log1[12][2]=0;
       redo_log1[12][3]=(20+mode);
      }
      else if(Size == 6){
       for (int row = 0 ;row < 60 ;row++){
        for (int col =0 ; col < 4 ; col++){
            redo_log2[row][col] = ' ';
        }
       }
       redo_log2[60][0]=0;
       redo_log2[60][1]=0;
       redo_log2[60][2]=0;
       redo_log2[60][3]=(60+mode);
      }
}
void delete_next_redo (int Size,int*n1,int*n2) {
   int i=0;
   if(Size == 3){
   if(*n1+*n2 != 12){
   while (redo_log1[*n1+*n2+i][0] != ' '){
    redo_log1[*n1+*n2+i][0] = ' ';
    redo_log1[*n1+*n2+i][1] = ' ';
    redo_log1[*n1+*n2+i][2] = ' ';
    redo_log1[*n1+*n2+i][3] = ' ';
    i++;
    }}
   }
   else if(Size == 6){
    if(*n1+*n2 != 60){
    while (redo_log2[*n1+*n2+i][0] != ' '){
    redo_log2[*n1+*n2+i][0] = ' ';
    redo_log2[*n1+*n2+i][1] = ' ';
    redo_log2[*n1+*n2+i][2] = ' ';
    redo_log2[*n1+*n2+i][3] = ' ';
    i++;
    }}
   }
}
void undo_comp(int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int Size,int* p1,int* p2,int Current_Player,int*n1,int*n2,int DimRow,int DimCol ,int orient){
      int i =0;
      if(*n1+*n2 != 0){
         undoM=1,redoM=0;
         if (Size == 3) {
         while(redo_log1[*n1+*n2-i-1][2] != 1) i++;
          while (c>=0 || i>=0){
             (redo_log1[*n1+*n2-1][3] == 'h')? (board_horiz[redo_log1[*n1+*n2-1][0]][redo_log1[*n1+*n2-1][1]] = ' ') : (board_vert[redo_log1[*n1+*n2-1][0]][redo_log1[*n1+*n2-1][1]] = ' ');
             (redo_log1[*n1+*n2-1][2] == 1)?((*n1)--):((*n2)--);
              c--;
              i--;
          }
           i=0;
           c=0;
             clearScreen();
             Game1_score(board_horiz,board_vert,s,Size,p1,p2,Current_Player,n1,n2,DimRow,DimCol,orient);
             print_board(board_horiz,board_vert,s,Size);
             print_scores(Size,*p1,*p2,*n1,*n2);
            (redo_log1[*n1+*n2][2] == 1)? player_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2);

         }
         else if (Size == 6) {
         while(redo_log2[*n1+*n2-i-1][2] != 1) i++;
         while (c>=0 || i>=0){
             (redo_log2[*n1+*n2-1][3] == 'h')? (board_horiz[redo_log2[*n1+*n2-1][0]][redo_log2[*n1+*n2-1][1]] = ' ') : (board_vert[redo_log2[*n1+*n2-1][0]][redo_log2[*n1+*n2-1][1]] = ' ');
             (redo_log2[*n1+*n2-1][2] == 1)?((*n1)--):((*n2)--);
              c--;
              i--;
          }
              i=0;
              c=0;
             clearScreen();
             Game1_score(board_horiz,board_vert,s,Size,p1,p2,Current_Player,n1,n2,DimRow,DimCol,orient);
             print_board(board_horiz,board_vert,s,Size);
             print_scores(Size,*p1,*p2,*n1,*n2);
            (redo_log2[*n1+*n2][2] == 1)? player_turn(board_horiz,board_vert,s,p1,p2,n1,n2): Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
         }
      }
      else {
        printf("No undo\n");
        (Current_Player == 1) ? player_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
      }

}
void redo_comp (int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int Size,int* p1,int* p2,int Current_Player,int*n1,int*n2,int DimRow,int DimCol ,int orient){
undoM=0,redoM = 1;
if (Size == 3) {
         if (redo_log1[*n1+*n2][3] != ' '){

(redo_log1[*n1+*n2][3] == 'h')? (board_horiz[redo_log1[*n1+*n2][0]][redo_log1[*n1+*n2][1]] = redo_log1[*n1+*n2][2]) : (board_vert[redo_log1[*n1+*n2][0]][redo_log1[*n1+*n2][1]] = redo_log1[*n1+*n2][2]);
             (redo_log1[*n1+*n2][2] == 1)?((*n1)++):((*n2)++);
             clearScreen();
             Game1_score(board_horiz,board_vert,s,Size,p1,p2,Current_Player,n1,n2,DimRow,DimCol,orient);
             print_board(board_horiz,board_vert,s,Size);
             print_scores(Size,*p1,*p2,*n1,*n2);
            (redo_log1[*n1+*n2][2] == 1)? player_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2);

}
         else {
             printf("No redo\n");
            (Current_Player == 1) ? player_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
         }
}
         else if (Size == 6) {
           if (redo_log2[*n1+*n2][3] != ' '){

             (redo_log2[*n1+*n2][3] == 'h')? (board_horiz[redo_log2[*n1+*n2][0]][redo_log2[*n1+*n2][1]] = redo_log2[*n1+*n2][2]) : (board_vert[redo_log2[*n1+*n2][0]][redo_log2[*n1+*n2][1]] = redo_log2[*n1+*n2][2]);
             (redo_log2[*n1+*n2+1][2] == 1)?((*n1)++):((*n2)++);
             clearScreen();
             print_board(board_horiz,board_vert,s,Size);
             Game1_score(board_horiz,board_vert,s,Size,p1,p2,Current_Player,n1,n2,DimRow,DimCol,orient);
             print_scores(Size,*p1,*p2,*n1,*n2);
            (redo_log2[*n1+*n2][2] == 1)? player_turn(board_horiz,board_vert,s,p1,p2,n1,n2): Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
           }
          else {
        printf("No redo\n");
        (Current_Player == 1) ? player_turn(board_horiz,board_vert,s,p1,p2,n1,n2) : Comp_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
      }
         }
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "functions.h"
int cell_1[2][2];
int cell_2[5][5];
void DFS (int board_horiz[Size][Size],int board_vert[Size][Size],int Size,int Current_Player,int*n1,int*n2,int DimRow, int DimCol,int orient){
   if(Size == 3){
    if (orient == 'h'){
        initialize_cell(cell_1);
        if (search_up(board_horiz,board_vert,cell_1,Size,DimRow,DimCol)&& search_down(board_horiz,board_vert,cell_1,Size,DimRow,DimCol))
            fill_Visited(board_horiz,board_vert,cell_1,Size,Current_Player,n1,n2);
    }
     else if (orient == 'v') {
        initialize_cell(cell_1);
       if(search_right(board_horiz,board_vert,cell_1,Size,DimRow,DimCol) && search_left(board_horiz,board_vert,cell_1,Size,DimRow,DimCol))
        fill_Visited(board_horiz,board_vert,cell_1,Size,Current_Player,n1,n2);
     }
   }
   if(Size == 6){
    if (orient == 'h'){
        initialize_cell(cell_2);
        if (search_up(board_horiz,board_vert,cell_2,Size,DimRow,DimCol)&& search_down(board_horiz,board_vert,cell_2,Size,DimRow,DimCol))
            fill_Visited(board_horiz,board_vert,cell_2,Size,Current_Player,n1,n2);
    }
     else if (orient == 'v') {
        initialize_cell(cell_2);
        if(search_right(board_horiz,board_vert,cell_2,Size,DimRow,DimCol) && search_left(board_horiz,board_vert,cell_2,Size,DimRow,DimCol))
            fill_Visited(board_horiz,board_vert,cell_2,Size,Current_Player,n1,n2);
     }
   }
}
int search_up (int board_horiz[Size][Size],int board_vert[Size][Size],int cell [Size-1][Size-1],int Size,int DimRow, int DimCol){
       if(DimRow == 0) return 0;
       else {
          if (cell [DimRow-1][DimCol] == 0){
              cell [DimRow-1][DimCol] = 1;
              if (board_horiz[DimRow-1][DimCol] != ' ' && board_vert[DimRow-1][DimCol] != ' ' && board_vert[DimRow-1][DimCol+1] != ' '){
                    return 1;
              }
              else {
                    if (board_horiz[DimRow-1][DimCol] == ' ' && board_vert[DimRow-1][DimCol] == ' ' && board_vert[DimRow-1][DimCol+1] == ' ')

                    return (search_up(board_horiz,board_vert,cell,Size,DimRow-1,DimCol) && search_right(board_horiz,board_vert,cell,Size,DimRow-1,DimCol+1) && search_left(board_horiz,board_vert,cell,Size,DimRow-1,DimCol));

               else if (board_horiz[DimRow-1][DimCol] == ' ' && board_vert[DimRow-1][DimCol] == ' ' && board_vert[DimRow-1][DimCol+1] != ' ')

                    return (search_left(board_horiz,board_vert,cell,Size,DimRow-1,DimCol) && search_up(board_horiz,board_vert,cell,Size,DimRow-1,DimCol));

               else if (board_horiz[DimRow-1][DimCol] == ' ' && board_vert[DimRow-1][DimCol] != ' ' && board_vert[DimRow-1][DimCol+1] == ' ')

                return (search_up(board_horiz,board_vert,cell,Size,DimRow-1,DimCol) && search_right(board_horiz,board_vert,cell,Size,DimRow-1,DimCol+1));

               else if (board_horiz[DimRow-1][DimCol] != ' ' && board_vert[DimRow-1][DimCol] == ' ' && board_vert[DimRow-1][DimCol+1] == ' ')

                return (search_left(board_horiz,board_vert,cell,Size,DimRow-1,DimCol) && search_right(board_horiz,board_vert,cell,Size,DimRow-1,DimCol+1));

               else if (board_horiz[DimRow-1][DimCol] == ' ' && board_vert[DimRow-1][DimCol] != ' ' && board_vert[DimRow-1][DimCol+1] != ' ')

                return (search_up(board_horiz,board_vert,cell,Size,DimRow-1,DimCol));

               else if (board_horiz[DimRow-1][DimCol] != ' ' && board_vert[DimRow-1][DimCol] != ' ' && board_vert[DimRow-1][DimCol+1] == ' ')

                return (search_right(board_horiz,board_vert,cell,Size,DimRow-1,DimCol+1));

               else if (board_horiz[DimRow-1][DimCol] != ' ' && board_vert[DimRow-1][DimCol] == ' ' && board_vert[DimRow-1][DimCol+1] != ' ')

                return (search_left(board_horiz,board_vert,cell,Size,DimRow-1,DimCol));
              }
          }
          else return 0;
       }
}
int search_down (int board_horiz[Size][Size],int board_vert[Size][Size],int cell [Size-1][Size-1],int Size,int DimRow, int DimCol){
       if(DimRow == Size-1) return 0;
       else {
          if (cell [DimRow][DimCol] == 0){
              cell [DimRow][DimCol] = 1;
              if (board_horiz[DimRow+1][DimCol] != ' ' && board_vert[DimRow][DimCol] != ' ' && board_vert[DimRow][DimCol+1] != ' '){
                    return 1;
              }
              else {
                    if (board_horiz[DimRow+1][DimCol] == ' ' && board_vert[DimRow][DimCol] == ' ' && board_vert[DimRow][DimCol+1] == ' ')

                        return (search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol) && search_right(board_horiz,board_vert,cell,Size,DimRow,DimCol+1) && search_left(board_horiz,board_vert,cell,Size,DimRow,DimCol));

               else if (board_horiz[DimRow+1][DimCol] == ' ' && board_vert[DimRow][DimCol] == ' ' && board_vert[DimRow][DimCol+1] != ' ')

                    return (search_left(board_horiz,board_vert,cell,Size,DimRow,DimCol) && search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol));

               else if (board_horiz[DimRow+1][DimCol] == ' ' && board_vert[DimRow][DimCol] != ' ' && board_vert[DimRow][DimCol+1] == ' ')

                return (search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol) && search_right(board_horiz,board_vert,cell,Size,DimRow,DimCol+1));

               else if (board_horiz[DimRow+1][DimCol] != ' ' && board_vert[DimRow][DimCol] == ' ' && board_vert[DimRow][DimCol+1] == ' ')


                return (search_left(board_horiz,board_vert,cell,Size,DimRow,DimCol) && search_right(board_horiz,board_vert,cell,Size,DimRow,DimCol+1));

               else if (board_horiz[DimRow+1][DimCol] == ' ' && board_vert[DimRow][DimCol] != ' ' && board_vert[DimRow][DimCol+1] != ' ')

                return (search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol));

               else if (board_horiz[DimRow+1][DimCol] != ' ' && board_vert[DimRow][DimCol] != ' ' && board_vert[DimRow][DimCol+1] == ' ')

                return (search_right(board_horiz,board_vert,cell,Size,DimRow,DimCol+1));

               else if (board_horiz[DimRow+1][DimCol] != ' ' && board_vert[DimRow][DimCol] == ' ' && board_vert[DimRow][DimCol+1] != ' ')

                return (search_left(board_horiz,board_vert,cell,Size,DimRow,DimCol));
              }
          }
          else return 0;
       }
}
int search_right (int board_horiz[Size][Size],int board_vert[Size][Size],int cell [Size-1][Size-1],int Size,int DimRow, int DimCol){
 if(DimCol == Size-1) return 0;
       else {
          if (cell [DimRow][DimCol] == 0){
              cell [DimRow][DimCol] = 1;
              if (board_vert[DimRow][DimCol+1] != ' ' && board_horiz[DimRow][DimCol] != ' ' && board_horiz[DimRow+1][DimCol] != ' '){
                    return 1;
              }
              else {
                    if (board_vert[DimRow][DimCol+1] == ' ' && board_horiz[DimRow][DimCol] == ' ' && board_horiz[DimRow+1][DimCol] == ' ')

                        return (search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol) && search_right(board_horiz,board_vert,cell,Size,DimRow,DimCol+1) && search_up(board_horiz,board_vert,cell,Size,DimRow,DimCol));

               else if (board_vert[DimRow][DimCol+1] == ' ' && board_horiz[DimRow][DimCol] == ' ' && board_horiz[DimRow+1][DimCol] != ' ')

                    return (search_right(board_horiz,board_vert,cell,Size,DimRow,DimCol+1) && search_up(board_horiz,board_vert,cell,Size,DimRow,DimCol));

               else if (board_vert[DimRow][DimCol+1] == ' ' && board_horiz[DimRow][DimCol] != ' ' && board_horiz[DimRow+1][DimCol] == ' ')

                return (search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol) && search_right(board_horiz,board_vert,cell,Size,DimRow,DimCol+1));

               else if (board_vert[DimRow][DimCol+1] != ' ' && board_horiz[DimRow][DimCol] == ' ' && board_horiz[DimRow+1][DimCol] == ' ')

                return (search_up(board_horiz,board_vert,cell,Size,DimRow,DimCol) && search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol));

               else if (board_vert[DimRow][DimCol+1] == ' ' && board_horiz[DimRow][DimCol] != ' ' && board_horiz[DimRow+1][DimCol] != ' ')

                return (search_right(board_horiz,board_vert,cell,Size,DimRow,DimCol+1));

               else if (board_vert[DimRow][DimCol+1] != ' ' && board_horiz[DimRow][DimCol] != ' ' && board_horiz[DimRow+1][DimCol] == ' ')

                return (search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol));

               else if (board_vert[DimRow][DimCol+1] != ' ' && board_horiz[DimRow][DimCol] == ' ' && board_horiz[DimRow+1][DimCol] != ' ')

                return (search_up(board_horiz,board_vert,cell,Size,DimRow,DimCol));
              }
          }
          else return 0;
       }
}
int search_left (int board_horiz[Size][Size],int board_vert[Size][Size],int cell [Size-1][Size-1],int Size,int DimRow, int DimCol){
if(DimCol == 0) return 0;
       else {
          if (cell [DimRow][DimCol-1] == 0){
              cell [DimRow][DimCol-1] =  1;
              if (board_vert[DimRow][DimCol-1] != ' ' && board_horiz[DimRow][DimCol-1] != ' ' && board_horiz[DimRow+1][DimCol-1] != ' '){
                    return 1;
              }
              else {

                if (board_vert[DimRow][DimCol-1] == ' ' && board_horiz[DimRow][DimCol-1] == ' ' && board_horiz[DimRow+1][DimCol-1] == ' ')

                        return (search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol-1) && search_left(board_horiz,board_vert,cell,Size,DimRow,DimCol-1) && search_up(board_horiz,board_vert,cell,Size,DimRow,DimCol-1));

               else if (board_vert[DimRow][DimCol-1] == ' ' && board_horiz[DimRow][DimCol-1] == ' ' && board_horiz[DimRow+1][DimCol-1] != ' ')

                    return (search_left(board_horiz,board_vert,cell,Size,DimRow,DimCol-1) && search_up(board_horiz,board_vert,cell,Size,DimRow,DimCol-1));

               else if (board_vert[DimRow][DimCol-1] == ' ' && board_horiz[DimRow][DimCol-1] != ' ' && board_horiz[DimRow+1][DimCol-1] == ' ')

                return (search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol-1) && search_left(board_horiz,board_vert,cell,Size,DimRow,DimCol-1));

               else if (board_vert[DimRow][DimCol-1] != ' ' && board_horiz[DimRow][DimCol-1] == ' ' && board_horiz[DimRow+1][DimCol-1] == ' ')

                return (search_up(board_horiz,board_vert,cell,Size,DimRow,DimCol-1) && search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol-1));

               else if (board_vert[DimRow][DimCol-1] == ' ' && board_horiz[DimRow][DimCol-1] != ' ' && board_horiz[DimRow+1][DimCol-1] != ' ')

                return (search_left(board_horiz,board_vert,cell,Size,DimRow,DimCol-1));

               else if (board_vert[DimRow][DimCol-1] != ' ' && board_horiz[DimRow][DimCol-1] != ' ' && board_horiz[DimRow+1][DimCol-1] == ' ')

                return (search_down(board_horiz,board_vert,cell,Size,DimRow+1,DimCol-1));

               else if (board_vert[DimRow][DimCol-1] != ' ' && board_horiz[DimRow][DimCol-1] == ' ' && board_horiz[DimRow+1][DimCol-1] != ' ')

                return (search_up(board_horiz,board_vert,cell,Size,DimRow,DimCol-1));
              }
          }
          else return 0;
       }
}
void fill_Visited (int board_horiz[Size][Size],int board_vert[Size][Size],int cell [Size-1][Size-1],int Size,int Current_Player,int* n1,int* n2){
    c=0;
    for (int row = 0 ; row < Size -1 ; row++){
      for(int column = 0 ; column < Size -1 ; column++){
        if (cell[row][column] == 1){

            if (board_horiz[row][column] == ' '){
            board_horiz[row][column]= Current_Player;
            saveRedoLog(Size,row,column,'h',Current_Player,n1,n2);
            c++;
        }
            if (board_vert[row][column] == ' '){
            board_vert[row][column]= Current_Player;
            saveRedoLog(Size,row,column,'v',Current_Player,n1,n2);
            c++;
        }
            if (board_horiz[row+1][column] == ' '){
            board_horiz[row+1][column]= Current_Player;
            saveRedoLog(Size,row+1,column,'h',Current_Player,n1,n2);
            c++;
        }
            if (board_vert[row][column+1] ==  ' '){
            board_vert[row][column+1]= Current_Player;
            saveRedoLog(Size,row,column+1,'v',Current_Player,n1,n2);
            c++;
        }
       }
    }
  }
}
void initialize_cell (int cell [Size-1][Size-1]){
  for (int i = 0 ; i < Size -1 ; i++){
    for(int j = 0 ; j < Size -1 ; j++){
        cell [i][j] = 0;
    }
  }
}


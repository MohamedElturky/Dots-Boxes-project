#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void save_game(int Size,int*p1,int*p2,int*n1,int*n2,int Current_player){
    delete_next_redo(Size,n1,n2);
    savedGame = fopen("saved.bin","wb");
    if (savedGame != NULL) {
        if(Size == 3){
        redo_log1[12][1] = *n1;
        redo_log1[12][2] = *n2;
        redo_log1[12][0] = Current_player;
        fwrite(redo_log1,sizeof(int), sizeof(redo_log1) / sizeof(int), savedGame);
        }
        if(Size == 6){
        redo_log2[60][1] = *n1;
        redo_log2[60][2] = *n2;
        redo_log2[60][0] = Current_player;
        fwrite(redo_log2,sizeof(int), sizeof(redo_log2) / sizeof(int), savedGame);
        }
        fclose(savedGame); // Close the file
        printf("saved to file successfully.\n");
    } else {
        printf("Unable to open the file.\n");
    }
    savedScore = fopen("savedScore.bin","wb");
    if (savedScore != NULL) {
        if(Size == 3){
        fwrite(s1,sizeof(int), sizeof(s1) / sizeof(int), savedScore);
        }
        if(Size == 6){
        fwrite(s2,sizeof(int), sizeof(s2) / sizeof(int), savedScore);
        }
        fclose(savedScore); // Close the file
        printf("saved to file successfully.\n");
    } else {
        printf("Unable to open the file.\n");
    }

    printf("press any key");
    int k;
    scanf("%d",&k);
    clearScreen();
    Game_main_menu();
}
void load_game(){
      int log [70][4];
      int score1 [3][3];
      int score2 [6][6];







    savedGame = fopen("saved.bin", "rb");
    fread(log, sizeof(int), (70*4), savedGame);
        fclose(savedGame);


       if( (log[12][3])/10 == 2){
            Size = 3;

        savedScore = fopen("savedScore.bin", "rb");
    fread(score1, sizeof(int), 3*3 , savedScore);
        fclose(savedScore);

    player player1;
   player player2;
   player1.score=0;
   player2.score=0;
   player1.numOfMoves= log[12][1];
   player2.numOfMoves=log[12][2];

   int *n1=&player1.numOfMoves;
   int *n2=&player2.numOfMoves;
   int *p1=&player1.score; // referring the pointer to the address of score variable
   int *p2=&player2.score;
   clearScreen();
   initilaize_Board(board1_horiz,board1_vert);
         for(int i = 0 ; i < 3 ;i++){
            for(int j =0 ; j < 3 ; j++){
                s1[i][j] = score1[i][j];
                if(s1[i][j] == 1)(*p1)++;
                else if(s1[i][j] == 2)(*p2)++;
            }
         }

         for(int i =0 ; i<13 ; i++){
            for(int j =0 ; j<4 ; j++){
                 redo_log1 [i][j]= log[i][j];
            }
         }
          for(int i =0 ; i<(*n1+*n2) ; i++){
            if(redo_log1[i][3] == 'h')
               board1_horiz[redo_log1[i][0]][redo_log1[i][1]] = redo_log1[i][2];
            else
               board1_vert[redo_log1[i][0]][redo_log1[i][1]] = redo_log1[i][2];

         }
            clearScreen();
            print_board(board1_horiz,board1_vert,s1,Size);

            if(log[12][3]%10 == 1){
            if(log[12][0] == 1)
            player1_turn(board1_horiz,board1_vert,s1,p1,p2,n1,n2) ;
            else
            player2_turn(board1_horiz,board1_vert,s1,p1,p2,n1,n2) ;
            }
            else player_turn(board1_horiz,board1_vert,s1,p1,p2,n1,n2);
       }
       else if(log[60][3]/10 == 6){
    Size = 6;

    savedScore = fopen("savedScore.bin", "rb");
    fread(score2, sizeof(int), 6*6 , savedScore);
        fclose(savedScore);

   player player1;
   player player2;
   player1.score=0;
   player2.score=0;
   player1.numOfMoves= log[60][1];
   player2.numOfMoves=log[60][2];

   int *n1=&player1.numOfMoves;
   int *n2=&player2.numOfMoves;
   int *p1=&player1.score; // referring the pointer to the address of score variable
   int *p2=&player2.score;
   clearScreen();
   initilaize_Board(board2_horiz,board2_vert);
   for(int i = 0 ; i< 6 ;i++){
            for(int j =0 ; j < 6 ; j++){
                s2[i][j] = score2[i][j];
                if(s2[i][j] == 1)(*p1)++;
                else if(s2[i][j] == 2)(*p2)++;
            }
   }
        for(int i =0 ; i<61 ; i++){
            for(int j =0 ; j<4 ; j++){
                 redo_log2 [i][j]= log[i][j];
            }
         }
        for(int i =0 ; i<(*n1+*n2) ; i++){
            if(redo_log2[i][3] == 'h')
               board2_horiz[redo_log2[i][0]][redo_log2[i][1]] = redo_log2[i][2];
            else
               board2_vert[redo_log2[i][0]][redo_log2[i][1]] = redo_log2[i][2];

           }
            clearScreen();
            print_board(board2_horiz,board2_vert,s2,Size);
            if(log[60][3]%10 == 1){
            if(log [60][0] == 1)
            player1_turn(board2_horiz,board2_vert,s2,p1,p2,n1,n2) ;
            else
            player2_turn(board2_horiz,board2_vert,s2,p1,p2,n1,n2) ;
            }
            else player_turn(board2_horiz,board2_vert,s2,p1,p2,n1,n2);
       }
}




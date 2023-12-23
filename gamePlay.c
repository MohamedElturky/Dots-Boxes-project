#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "functions.h"
clock_t startTime; //global var for time
int s1[3][3];// array for score boxes
int s2[6][6];
void initilaize_Board(int board_horiz [Size][Size],int board_vert [Size][Size]){ //initializing the board
      int row=0,column=0;

      printf("\t\t\t\t\t\t   ");
   for (column=0 ; column<Size ; column++) printf("%d   ",column+1);
      printf("\n\n");
    for(row=0 ; row<Size ;row++){
            printf("\t\t\t\t\t\t");
        printf("%d  ",row+1);
    for (column=0 ; column<Size ; column++){
        board_horiz[row][column]=' '; // initializing an array for horizontal dashes -
        printf("*%c%c%c",board_horiz[row][column],board_horiz[row][column],board_horiz[row][column]);
    }
        printf("\n");
    printf("\t\t\t\t\t\t");
    for (column=0 ; column<Size ; column++){
        board_vert[row][column]=' '; // initializing an array for vertical dashes |
        printf("   %c",board_vert[row][column]);
    }
       printf("\n");
   }
   for(int row=0 ; row<Size ;row++){ //initializing score boxes
    for (int column=0 ; column<Size ; column++){
            s1[row][column]=0;
            s2[row][column]=0;
   }
   }
}
void Determine_Dim (int boardDim){
while(scanf("%1d%c",&boardDim,&extra) != 2 || extra != '\n'){ // scan and check if the input is not digits
        printf("Enter 1 or 2\n");
        while (getchar()!='\n');
}
 switch(boardDim){
 case 1:
     clearScreen();
     Size=3; // choosing the size of board if it is 2*2 then the arrays will be [3][3]
     Game_logo ();
     printf("1- Human vs Human\n");
     printf("2- Human vs AI\n");
     printf("Enter 1 or 2: ");
     scanf("%d",&input);
     while(input != 1 && input != 2){
        printf("Enter 1 or 2: ");
        scanf("%d",&input);
     }
     if(input == 1){
        Human_vs_Human(board1_horiz,board1_vert,s1,Size);
     }else if(input == 2){
         Human_vs_Comp(board1_horiz,board1_vert,s1,Size);
     }
    break;
 case 2:
     clearScreen();
     Size=6;  // choosing the size of board if it is 2*2 then the arrays will be [6][6]
     Game_logo ();
     printf("1- Human vs Human\n");
     printf("2- Human vs AI\n");
     printf("Enter 1 or 2: ");
     scanf("%d",&input);
     while(input != 1 && input != 2){
        printf("Enter 1 or 2: ");
        scanf("%d",&input);
     }
     if(input == 1){
        Human_vs_Human(board2_horiz,board2_vert,s2,Size);
     }else if(input == 2){
         Human_vs_Comp(board2_horiz,board2_vert,s2,Size);
     }
    break;
 case 3:
     clearScreen();
     Game_main_menu();
    break;
 default:
     printf("Enter 1 or 2 or 3: ");
     Determine_Dim(boardDim);
 }
}
void Game_main_menu (){ // hello friend :)
    Game_logo ();
    printf("1- New game\n");
    printf("2- Load game\n");
    printf("3- Rank\n");
    printf("choose from 1 to 3: ");
    scanf("%d",&input);
    while (input != 1 && input != 2 && input != 3){
        printf("invalid number\n");
        printf("choose from 1 to 3: ");
        scanf("%d",&input);
    }
    switch (input){
        case(1):
            clearScreen();
            new_game();
            Determine_Dim (boardDim);
            break;
        case(2):
            clearScreen();
            printf("coming soon");
            // load_game;
            printf("\n1- Return to main menu\n");
            printf("2- Exit\n");
            printf("Choose 1 or 2: ");
            scanf("%d",&input);
            while (input != 1 && input != 2){
            printf("invalid number\n");
            printf("choose from 1 or 2: ");
            scanf("%d",&input);
            }
            if(input == 1){
                 clearScreen();
                 Game_main_menu();
            }else{
                 exit(0);
            break;
        case(3):
            clearScreen();
            print_rank(filename);
            printf("\n1- Return to main menu\n");
            printf("2- Exit\n");
            printf("Choose 1 or 2: ");
            scanf("%d",&input);
            while (input != 1 && input != 2){
            printf("invalid number\n");
            printf("choose from 1 or 2: ");
            scanf("%d",&input);
            }
            if(input == 1){
                 clearScreen();
                 Game_main_menu();
            }else{
                 exit(0);
            }
             break;
       }
    }
}
void print_board(int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int Size){ //printing the board after each move
 int row=0,column=0;


      printf("\t\t\t\t\t\t   ");
   for (column=0 ; column<Size ; column++) printf("%d   ",column+1);
      printf("\n\n");
   for(row=0 ; row<Size ;row++){
        printf("\t\t\t\t\t\t");
       printf("%d  ",row+1);
       for (column=0 ; column<Size ; column++){
        if(board_horiz[row][column]==1)
        printf("*\033[0;34m---\033[0m");//printing --- for horizontal dots
        else if (board_horiz[row][column]==2) printf("*\033[0;31m---\033[0m");
        else printf("*   ");
       }
       printf("\n");

         printf("\t\t\t\t\t\t   ");
       for (column=0 ; column<Size ; column++){

       if(board_vert[row][column]==1){//printing | for vertical dots and if a box is completed prints #
            if(s[row][column]==1)
        printf("\033[0;34m|\033[0m \033[0;34m1\033[0m ");
        else if(s[row][column]==2)
        printf("\033[0;34m|\033[0m \033[0;31m2\033[0m ");
         else
        printf("\033[0;34m|\033[0m   ");

       }
        else if(board_vert[row][column]==2) {
           if(s[row][column]==1)
        printf("\033[0;31m|\033[0m \033[0;34m1\033[0m ");
        else if(s[row][column]==2)
        printf("\033[0;31m|\033[0m \033[0;31m2\033[0m ");
         else
        printf("\033[0;31m|\033[0m   ");
        }
        else printf("    ");
       }

       printf("\n");
   }

}
void player1_turn(int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int*p1,int*p2,int*n1,int*n2){ //player 1 turn func with parameters 1-the horizontal array 2-the vertical array 3-pointer to player 1 score 4-pointer to player 2 score
  End_Game(Size,p1,p2); // check if the game has ended
  printf("\x1B[34m""Player 1 turn Enter (RRCC) ""\x1B[0m");
  while(scanf("%1d%1d%1d%1d%c",&r1,&r2,&c1,&c2,&extra) != 5 || extra != '\n'){ // scan and check if the input is not digits
        printf("\x1B[34m""Enter a correct place\n""\x1B[0m");
        printf("\x1B[34m""Player 1 turn Enter (RRCC): ""\x1B[0m");
        while (getchar()!='\n');
}
  if (r1==r2 && c1!=c2 && fabs(c1-c2)==1 && board_horiz[r1-1][(c2>c1)?(c1-1):(c2-1)]==' ' && (r1<=Size && r2<=Size && c1<=Size && c2<=Size ) && (r1>=1 && r2>=1 &&c1>=1 && c2>=1)){ // here are the conditions for input if the input is horizontal  note: here i used the absolute function to neglect the order of input like 2212 and 2221
    board_horiz[r1-1][(c2>c1)?(c1-1):(c2-1)]=1; // assignment of move  note again: the ternary operator is used as caution of the input order
    Game_score(board_horiz,board_vert,s,Size,p1,p2,1,n1,n2);// calculating the score
    clearScreen();
    print_board(board_horiz,board_vert,s,Size); // print the board
    (*n1)++;
    print_scores(Size,*p1,*p2,*n1,*n2); // print the scores
    player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2); // it is time for the another player move
  }
   else if (c1==c2 && r1!=r2 && fabs(r1-r2)== 1 && board_vert[(r2>r1)?(r1-1):(r2-1)][c1-1]==' ' && (r1<=Size && r2<=Size && c1<=Size && c2<=Size ) && (r1>=1 && r2>=1 &&c1>=1 && c2>=1)) { // here are the conditions for input if the input is vertical
    board_vert[(r2>r1)?(r1-1):(r2-1)][c1-1]=1;
    Game_score(board_horiz,board_vert,s,Size,p1,p2,1,n1,n2);
    clearScreen();
    print_board(board_horiz,board_vert,s,Size);
    (*n1)++;
    print_scores(Size,*p1,*p2,*n1,*n2);
    player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
   }
   else{printf("\x1B[34m""Enter a correct place\n""\x1B[0m"); // another try to enter the input if it was wrong
   player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2);}
}
void player2_turn(int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int*p1,int*p2,int*n1,int*n2){ // same as player 1 func
  End_Game(Size,p1,p2);
  printf("\x1B[31m""Player 2 turn Enter (RRCC) ""\x1B[0m");
   while(scanf("%1d%1d%1d%1d%c",&r1,&r2,&c1,&c2,&extra) != 5 || extra != '\n'){ // scan and check if the input is not digits
        printf("\x1B[31m""Enter a correct place\n""\x1B[0m");
        printf("\x1B[31m""Player 2 turn Enter (RRCC): ""\x1B[0m");
        while (getchar()!='\n');
}

  if (r1==r2 && c1!=c2 && fabs(c1-c2)==1 && board_horiz[r1-1][(c2>c1)?(c1-1):(c2-1)]==' '&& (r1<=Size && r2<=Size && c1<=Size && c2<=Size ) && (r1>=1 && r2>=1 &&c1>=1 && c2>=1)){
    board_horiz[r1-1][(c2>c1)?(c1-1):(c2-1)]=2;
    Game_score(board_horiz,board_vert,s,Size,p1,p2,2,n1,n2);
    clearScreen();
    print_board(board_horiz,board_vert,s,Size);
    (*n2)++;
    print_scores(Size,*p1,*p2,*n1,*n2);
    player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
  }
   else if (c1==c2 && r1!=r2 && fabs(r1-r2)== 1 && board_vert[(r2>r1)?(r1-1):(r2-1)][c1-1]==' '&& (r1<=Size && r2<=Size && c1<=Size && c2<=Size ) && (r1>=1 && r2>=1 &&c1>=1 && c2>=1)) {
    board_vert[(r2>r1)?(r1-1):(r2-1)][c1-1]=2;
    Game_score(board_horiz,board_vert,s,Size,p1,p2,2,n1,n2);
    clearScreen();
    print_board(board_horiz,board_vert,s,Size);
    (*n2)++;
    print_scores(Size,*p1,*p2,*n1,*n2);
    player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
   }
   else{printf("\x1B[31m""Enter a correct place\n""\x1B[0m");
   player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);}
}
void Human_vs_Human (int board_horiz [Size][Size],int board_vert [Size][Size],int s[Size][Size],int Size){ //choosing the mode  Note this func id called in Determine Dim func and will be changed later
   player player1;
   player player2;
   player1.score=0;
   player2.score=0;
   player1.numOfMoves=0;
   player2.numOfMoves=0;
   startTime=clock();
   int *n1=&player1.numOfMoves;
   int *n2=&player2.numOfMoves;
   int *p1=&player1.score; // referring the pointer to the address of score variable
   int *p2=&player2.score;
   clearScreen();
   initilaize_Board(board_horiz,board_vert);

   player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2); // here the first turn will be called
}
void Game_score (int board_horiz[Size][Size],int board_vert[Size][Size],int s[Size][Size],int Size,int* p1,int* p2,int Current_Player,int*n1,int*n2){ /* the most important function that calculates scores VIP ,
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
                        player1_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
                    }
                    else {
                        *p2 += count_scores-(*p1 + *p2);
                        clearScreen();
                        print_board(board_horiz,board_vert,s,Size);
                        (*n2)++;
                        print_scores(Size,*p1,*p2,*n1,*n2);
                        player2_turn(board_horiz,board_vert,s,p1,p2,n1,n2);
                    }
     }
}
void print_scores (int Size,int score1, int score2,int move1, int move2){ //just printing the score , the No. of moves and time..boring..Zzz
   clock_t endTime =clock();//end checkpoint for time
   printf("\x1B[34m""\t\t\tplayer 1 score : %d ""\x1B[0m""\x1B[31m""                   player 2 score :%d\n""\x1B[0m",score1,score2);
   printf("\x1B[34m""\t\t\tplayer 1 No. of moves : %d   ""\x1B[0m""\x1B[31m""          player 2 No. of moves :%d\n\n""\x1B[0m",move1,move2);
   double timePassed = (endTime-startTime)/CLOCKS_PER_SEC;
   printf("\t\t\t\t\ttime passed %d min %d sec\n",(int)(timePassed/60),(int)(((int)timePassed%60)));//printing time
   if (Size==3) printf("\t\t\t\t\t %d dots remaining\n",12-(move1+move2));
   if (Size==6) printf("\t\t\t\t\t %d dots remaining\n",60-(move1+move2));
}
void End_Game (int Size,int* p1,int* p2){ // func to check if the game has ended
if (*(p1) + *(p2) == (Size-1)*(Size-1)){ // look at this line, it will check if the  sum of scores = equal the number of boxes and i think this approach is easier than looping
    if (*p1 > *p2){
        printf("\t\t\t\t\t Player 1 is the winner!\n");// no need for explanation
        while(1){
        printf("Enter player 1's name (49 characters MAX): ");
        scanf("%49s", name);
        int containsComma = 0;
        for(int i=0;i<strlen(name);i++){
            if (name[i] == ','){
                containsComma = 1;
                break;
            }
        }
        if (containsComma){
            printf("Name cannot contain ','.\n");
        }else{
            break;
         }
        }
        add_to_rank(filename,name,*p1);
        printf("1-Return to the main menu\n");
        printf("2-Exit\n");
        printf("Choose 1 or 2: ");
        scanf("%d",&input);
        while (input != 1 && input != 2){
        printf("invalid number\n");
        printf("choose from 1 or 2: ");
        scanf("%d",&input);
        }
        if(input == 1){
            clearScreen();
            Game_main_menu();
        }else{
            exit(0);
        }
    }else if(*p2 > *p1){
        printf("\t\t\t\t\t Player 2 is the winner!\n");
        while(1){
        printf("Enter player 2's name (49 characters MAX): ");
        scanf("%49s", name);
        int containsComma = 0;
        for(int i=0;i<strlen(name);i++){
            if (name[i] == ','){
                containsComma = 1;
                break;
            }
        }
        if (containsComma){
            printf("Name cannot contain ','.\n");
        }else{
            break;
         }
        }
        add_to_rank(filename,name,*p2);
        printf("1-Return to the main menu\n");
        printf("2-Exit\n");
        printf("Choose 1 or 2: ");
        scanf("%d",&input);
        while (input != 1 && input != 2){
        printf("invalid number\n");
        printf("choose from 1 or 2: ");
        scanf("%d",&input);
    }
        if(input == 1){
            clearScreen();
            Game_main_menu();
        }else{
            exit(0);
        }
    }else{
        printf("\t\t\t\t\t Tie!\n");
        while(1){
        printf("Enter player 1's name (49 characters MAX): ");
        scanf("%49s", name);
        int containsComma = 0;
        for(int i=0;i<strlen(name);i++){
            if (name[i] == ','){
                containsComma = 1;
                break;
            }
        }
        if (containsComma){
            printf("Name cannot contain ','.\n");
        }else{
            break;
         }
        }
        add_to_rank(filename,name,*p1);
        while(1){
        printf("Enter player 2's name (49 characters MAX): ");
        scanf("%49s", name);
        int containsComma = 0;
        for(int i=0;i<strlen(name);i++){
            if (name[i] == ','){
                containsComma = 1;
                break;
            }
        }
        if (containsComma){
            printf("Name cannot contain ','.\n");
        }else{
            break;
         }
        }
        add_to_rank(filename,name,*p2);
        printf("1-Return to the main menu\n");
        printf("2-Exit\n");
        printf("Choose 1 or 2: ");
        scanf("%[^,]",&input);
        while (input != 1 && input != 2){
        printf("invalid number\n");
        printf("choose from 1 or 2: ");
        scanf("%d",&input);
    }
        if(input == 1){
            clearScreen();
            Game_main_menu();
        }else{
            exit(0);
        }
    }
    exit(0); // function to terminate the recursion
    }
}
void clearScreen() {
    printf("\033[2J\033[1;1H"); // clear screen
}
void new_game(){
    Game_logo ();
    printf("Choose the game Dimensions!\n");
    printf("1- beginner  (2x2)\n");
    printf("2- expert    (5x5)\n");
    printf("3- return to the main menu\n");
    printf("choose from 1 to 3: ");
}



void Game_logo (){
    printf("                         ___           _             _____       ___                             \n");
    printf("                        (  _`\\        ( )_          (  _  )     (  _`\\                           \n");
    printf("                        | | ) |   _   | ,_)  ___    `\\  ,/'     | (_) )   _            __    ___ \n");
    printf("                        | | | ) /'_`\\ | |  /',__)    /'_`\\/\\    |  _ <' /'_`\\ (`\\/') /'__`\\/',__)\n");
    printf("                        | |_) |( (_) )| |_ \\__, \\   | (_> ,<`   | (_) )( (_) ) >  < (  ___/\\__, \\\n");
    printf("                        (____/'`\\___/'`\\__)(____/   `\\___/\\/'   (____/'`\\___/'(_/\\_)`\\____)(____/\n");
    printf("                                                                                    by Mohamed & Ali\n");
}


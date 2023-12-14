#ifndef FUNCTIONS_H_INCLUDED  //this header file to link any variable and function to another file
#define FUNCTIONS_H_INCLUDED
extern int board1_horiz[3][3]; // note the term extern is used to make this variable is seen in all files
extern int board1_vert[3][3];
extern int board2_horiz[6][6];
extern int board2_vert[6][6];
extern int r1,r2,c1,c2;
extern int Size;
extern int player1_score,player2_score;
void initilaize_Board();
void Determine_Dim ();
void Hello_to_Game ();
void print_board();
void player1_turn();
void player2_turn();
void Human_vs_Human();
void Game_score();

#endif // FUNCTIONS_H_INCLUDED

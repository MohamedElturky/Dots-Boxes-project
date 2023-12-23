#ifndef FUNCTIONS_H_INCLUDED  //this header file to link any variable and function to another file
#define FUNCTIONS_H_INCLUDED
extern int boardDim;
extern int board1_horiz[3][3]; // note the term extern is used to make this variable is seen in all files
extern int board1_vert[3][3];
extern int board2_horiz[6][6];
extern int board2_vert[6][6];
extern int s1[3][3];
extern int s2[6][6];
extern int r1,r2,c1,c2;
extern int Size,input;
extern char extra;
extern char name[50];
extern char ranking[11];
extern const char *filename;
extern FILE *savedGame;
typedef struct{
 char name[100];
 int score;
 int numOfMoves;
}player;
void initilaize_Board();
void Determine_Dim ();
void Game_main_menu ();
void print_board();
void player1_turn();
void player2_turn();
void Human_vs_Human();
void Game_score();
void save();
void Game_logo();
void create_rank_file(const char *filename);
void print_rank(const char *filename);
void add_to_rank(const char *filename, char *name,int *p);
#endif // FUNCTIONS_H_INCLUDED

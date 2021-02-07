/* checkers.h: Header file for Project 1 */


/* boolean constants */
#define TRUE 1
#define FALSE 0

/* check functions will return valid/invalid status of moves */
#define VALID_MOVE 1
#define INVALID_MOVE 2

/* each checker board square will encode its contents */
#define EMPTY 0
#define RED 1
#define WHITE 2
#define RED_KING 3
#define WHITE_KING 4

#define BOARD_SIZE 8
extern int the_board[BOARD_SIZE][BOARD_SIZE];


/* Required Functions */
void print_board(); //DONE
int jump_exists(int);
void move_piece(int, int, int, int, int, int);
int check_move(int, int, int, int, int, int);
int check_jump(int, int, int, int, int);
int check_step(int, int, int, int, int);
int is_jumper(int, int);

/* Print Board Helper Functions */
void print_row_border();
void print_row_data(int);

/* Game Progession Functions */
void prompt_move();
void change_player();
int get_and_check_move();
void check_exit();

/* Move Validity Functions */
int is_move_valid(int, int, int, int, int);
int prelim_move_check(int, int, int, int, int);




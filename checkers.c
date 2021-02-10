#include <stdio.h>
#include <stdlib.h>
#include "checkers.h"

int the_board[BOARD_SIZE][BOARD_SIZE];
int color, x_from, y_from, x_to, y_to, move_validity;

void main(){

  /* Starting the Game */
  initialize_board();
  color = RED;
  print_board();

  while (TRUE){

    /* Prompting user for a valid move */
    
    prompt_move();
    move_validity = get_and_check_move();
    while (move_validity == INVALID_MOVE){
      printf("INVALID MOVE.  TRY AGAIN!!\n");
      prompt_move();
      move_validity = get_and_check_move();
    }

    printf("\n %d \n", jump_exists(color)); // DELETE LATER FOR TESTING PURPOSES
    fflush(stdout);
    
    move_piece(color, x_from, y_from, x_to, y_to, FALSE); 
    // TODO: handling multiple jumps for a piece

    /* Change Player after move made */

    color = opposite_player(color);
    
    /* Printing Board */
    printf("\n");
    print_board();

  }
}


/* Game Progression Functions */

void initialize_board(){
  int row, col, piece;
  for (row = 0; row < BOARD_SIZE; row++){
    piece = 0;
    if (row < 3){ piece = 1; }
    if (row > 4){ piece = 2; }
    
    for (col = 0; col < BOARD_SIZE; col++){
      if ((row + col) % 2 == 1){
        the_board[row][col] = piece;
      }
      else{
	the_board[row][col] = 0;
      }
    }
  }
}

void prompt_move(){
  switch(color) {
      case RED:
	printf("RED's move:  ");
	break;
 
      case WHITE:
	printf("WHITE's move:  ");
	break;
  }
}

int get_and_check_move(){
  scanf("%d %d %d %d", &x_from, &y_from, &x_to, &y_to);
  check_exit();
  return(is_move_valid(color, x_from, y_from, x_to, y_to));
}


void check_exit(){
  if (x_from == 0 && y_from == 0 && x_to == 0 && y_to == 0){
    exit(1);
  }
}


/* General Checkers Helper Functions */

int opposite_player(int piece){
  switch(piece) {
    case RED_KING:
    case RED:
      return(WHITE);

    case WHITE_KING:
    case WHITE:
      return(RED);

    case EMPTY:
      return(EMPTY);
  }
}


int get_valid_direction(int piece){
  // for kings check both directions
  switch(piece) {
    case RED_KING:
    case WHITE_KING:
    case RED:
      return(1);

    case WHITE:
      return(-1);
  }
}



int is_king(int piece){
  switch(piece) {
    case RED_KING:
    case WHITE_KING:
      return(TRUE);

    case RED:
    case WHITE:
      return(FALSE);
  }
}

int space_exists(int x, int y){
  if ((x >= BOARD_SIZE) || (x <= -1) || (y >= BOARD_SIZE) || (y <= -1)){
    return(FALSE);
  }

  return(TRUE);
}


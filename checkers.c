#include <stdio.h>
#include <stdlib.h>
#include "checkers.h"

int the_board[BOARD_SIZE][BOARD_SIZE];
int color, x_from, y_from, x_to, y_to, move_validity, jump;
int multijump, prev_x, prev_y;

void main(){

  /* Starting the Game */
  initialize_board();
  color = RED;
  print_board();
  multijump = FALSE;

  while (TRUE){

    jump = FALSE;

    /* Prompting user for a valid move */
    
    prompt_move();
    move_validity = get_and_check_move();
    while (move_validity == INVALID_MOVE){
      printf("INVALID MOVE.  TRY AGAIN!!\n");
      prompt_move();
      move_validity = get_and_check_move();
    }

    jump = is_jumper(x_from, y_from);
    move_piece(color, x_from, y_from, x_to, y_to, jump); 

    /* Check if a multijump move */

    if (jump && is_jumper(x_to, y_to)){
      multijump = TRUE;
      prev_x = x_to;
      prev_y = y_to;
    } else{
      multijump = FALSE;
      color = opposite_player(color);
    }
    
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

// Prompt and checks if move is valid

int get_and_check_move(){
  scanf("%d %d %d %d", &x_from, &y_from, &x_to, &y_to);
  check_exit();
  if (multijump && !check_multijump(x_from, y_from)){
    return(INVALID_MOVE);
  }
  return(is_move_valid(color, x_from, y_from, x_to, y_to));
}

// Checks if a move is a multijump

int check_multijump(int x_from, int y_from){
  if (x_from == prev_x && y_from == prev_y){
    return(TRUE);
  }
  return(FALSE);
}

// Checks if an input is to exit program

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


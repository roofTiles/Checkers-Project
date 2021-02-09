#include <stdio.h>
#include "checkers.h"

/* Determines if a jump exists for a given player */

int jump_exists(int color){
  int x, y;

  for (y = 0; y < BOARD_SIZE; y++){
    for (x = 0; x < BOARD_SIZE; x++){

      if (opposite_player(the_board[y][x]) != color){ // if piece is the current player's

	if (is_jumper(x, y) == TRUE){
	  return(TRUE);
	}
	
      }
    }
  }

  return(FALSE);
}


/* If a given piece can jump */

int is_jumper (int x, int y){
  int piece;
  piece = the_board[y][x];

  dir = get_valid_direction(piece);
}

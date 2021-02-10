#include <stdio.h>
#include "checkers.h"

/* Determines if a jump exists for a given player */

int jump_exists(int color){
  int x, y;
  
  for (y = 0; y < BOARD_SIZE; y++){
    for (x = 0; x < BOARD_SIZE; x++){
      if (opposite_player(the_board[y][x]) != color){ // if piece is the current player's
	if (the_board[y][x] != EMPTY && is_jumper(x, y) == TRUE){
	  return(TRUE);
	}
      }
    }
  }

  return(FALSE);
}


/* If a given piece can jump */

int is_jumper(int x, int y){
  int piece, dir, valid_jumps;
  
  piece = the_board[y][x];
  dir = get_valid_direction(piece);
  valid_jumps = check_diagonals(x, y, dir);

  if (is_king(piece)){ // if a king, check opposite direction
    valid_jumps = valid_jumps || check_diagonals(x, y, -dir);
  }

  return(valid_jumps);
  
}

/* If a given piece has jumping diagonals in a given direction */
  
int check_diagonals(int x, int y, int dir){
  int piece, valid_jumps;
  valid_jumps = FALSE;
  piece = the_board[y][x];
  if (space_exists(x+1, y+dir) && space_exists(x+2, y+(dir*2))){ // checking right diagonal
    valid_jumps = check_space_for_opposite_team(x+1, y+dir, piece) && the_board[y+(dir*2)][x+2] == EMPTY;
  }

  if (space_exists(x-1, y+dir) && space_exists(x-2, y+(dir*2)) && !valid_jumps){ // checking left diagonal only if no jumps for right diagonal
    valid_jumps = check_space_for_opposite_team(x-1, y+dir, piece) && the_board[y+(dir*2)][x-2] == EMPTY;
  }

  return(valid_jumps);
}

/* If a given space occupied by opposite player of a given piece */
  
int check_space_for_opposite_team(int x, int y, int piece){
  int oppositeColor;
  oppositeColor = opposite_player(the_board[y][x]);
  if (oppositeColor != EMPTY && oppositeColor != opposite_player(piece)){ // if given space has piece of opposite player
    return(TRUE);
  }
  return(FALSE);
}

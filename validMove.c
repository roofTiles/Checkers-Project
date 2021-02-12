#include <stdio.h>
#include <stdlib.h>
#include "checkers.h"

int is_move_valid(int color, int x_from, int y_from, int x_to, int y_to){

  /* check if move is within bounds and handles the player pieces */
  
  if (prelim_move_check(color, x_from, y_from, x_to, y_to) == INVALID_MOVE){
    return(INVALID_MOVE);
  }

  int jump;
  jump = jump_exists(color);
  
  /* check move */
  if (check_move(color, x_from, y_from, x_to, y_to, jump) == INVALID_MOVE){
    return(INVALID_MOVE);
  }

  return(VALID_MOVE);
}

int prelim_move_check(int color, int x_from, int y_from, int x_to, int y_to){
  /* is move in bounds? */
  
  // checks starting coordinate and terminating coordinates
  if (!space_exists(x_from, y_from) || !space_exists(x_to, y_to)){
    return(INVALID_MOVE);
  }

  /* does move go from player piece to empty spot? */
  int piece;
  piece = the_board[y_from][x_from];
  
  // checking if player colors correspond with piece being moved
  if (opposite_player(piece) == color || piece == EMPTY){
    return(INVALID_MOVE);
  }

  // checking if terminating spot is empty
  if (the_board[y_to][x_to] != EMPTY){
    return(INVALID_MOVE);
  }

  return(VALID_MOVE);
}

int check_move(int color, int x_from, int y_from, int x_to, int y_to, int jump){
  int piece, dir;
  piece = the_board[y_from][x_from];
  dir = get_valid_direction(piece);
  
  /* Checking if move is a valid jump */
  
  if (jump){
    int is_valid_jump;
    
    is_valid_jump = check_jump(x_from, y_from, x_to, y_to, dir);

    if (is_king(piece) && is_valid_jump == INVALID_MOVE){ // check other direction for king piece if first one not valid
      dir = -dir;
      is_valid_jump = check_jump(x_from, y_from, x_to, y_to, dir);
    }

    if (is_valid_jump == INVALID_MOVE){ return(INVALID_MOVE); }
  }

  /* Checking if move is a valid step */
  
  if (!jump){
    int is_valid_step;
    
    is_valid_step = check_step(x_from, y_from, x_to, y_to, dir);

    if (is_king(piece) && is_valid_step == INVALID_MOVE){ // check other direction for king piece if first one not valid
      dir = -dir;
      is_valid_step = check_step(x_from, y_from, x_to, y_to, dir);
    }

    if (is_valid_step == INVALID_MOVE){ return(INVALID_MOVE); }
  }

  return(VALID_MOVE);
}

/* If a move is a valid step */

int check_step(int x_from, int y_from, int x_to, int y_to, int dir){
  if (abs(x_to - x_from) != 1){
    return(INVALID_MOVE);
  }

  if ((y_to - y_from) != dir){
    return(INVALID_MOVE);
  }

  return(VALID_MOVE);
}

/* If a move is a valid jump */

int check_jump(int x_from, int y_from, int x_to, int y_to, int dir){
  int piece;
  piece = the_board[y_from][x_from];

  if (is_jumper(x_from, y_from) == FALSE){ // if piece selected cannot jump
    return(INVALID_MOVE);
  }

  if (abs(x_to - x_from) != 2 || y_to - y_from != dir*2){ // if jump isn't diagonally two spaces away in correct direction
    return(INVALID_MOVE);
  }

  if (x_from < x_to && check_space_for_opposite_team(x_from+1, y_from+dir, piece) == FALSE){ // if move is to the right
    return(INVALID_MOVE);
  }

  if (x_from > x_to && check_space_for_opposite_team(x_from-1, y_from+dir, piece) == FALSE){ // if move is to the left
    return(INVALID_MOVE);
  }

  return(VALID_MOVE);
}

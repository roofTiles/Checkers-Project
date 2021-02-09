#include <stdio.h>
#include <stdlib.h>
#include "checkers.h"

int is_move_valid(int color, int x_from, int y_from, int x_to, int y_to){

  /* check if move is within bounds and handles the player pieces */
  
  if (prelim_move_check(color, x_from, y_from, x_to, y_to) == INVALID_MOVE){
    return(INVALID_MOVE);
  }


  // have to first determine if jumping move exists for color (jump_exists() uses is_jumper() for each color piece)
  // check_move() which checks if a move is valid step or a valid jump
  // if jump exists check_move must ensure move is a valid jump!
  
  /* check move */
  if (check_move(color, x_from, y_from, x_to, y_to, FALSE) == INVALID_MOVE){ // TODO: need to update jump to check if move is jump
    return(INVALID_MOVE);
  }
  


  return(VALID_MOVE);
}

int prelim_move_check(int color, int x_from, int y_from, int x_to, int y_to){
  /* is move in bounds? */
  
  // checks starting coordinate
  if (!space_exists(x_from, y_from)){
    return(INVALID_MOVE);
  }

  // checks terminating coordinate
  if (!space_exists(x_to, y_to)){
    return(INVALID_MOVE);
  }

  /* does move go from player piece to empty spot */
  int piece;
  piece = the_board[y_from][x_from];
  
  // checking if player colors correspond with piece being moved
  if (opposite_player(piece) == color){
    return(INVALID_MOVE);
  }

  if (piece == EMPTY){
    return(INVALID_MOVE);
  }

  // checking if terminating spot is empty
  if (the_board[y_to][x_to] != EMPTY){
    return(INVALID_MOVE);
  }

  return(VALID_MOVE);
}

int check_move(int color, int x_from, int y_from, int x_to, int y_to, int jump){
  int piece;
  piece = the_board[y_from][x_from];
  
  if (jump){
    // check_jump here
  }

  /* Checking if move is a valid step */
  
  int is_valid_step;
  if (!jump){
    int dir;
    dir = get_valid_direction(piece);
    is_valid_step = check_step(x_from, y_from, x_to, y_to, dir);

    if (is_king(piece) && is_valid_step == FALSE){ // check other direction for king piece if first one not valid
      dir = -dir;
      is_valid_step = check_step(x_from, y_from, x_to, y_to, -1);
    }

    if (is_valid_step == INVALID_MOVE){ return(INVALID_MOVE); }
  }

  return(VALID_MOVE);
}

int check_step(int x_from, int y_from, int x_to, int y_to, int dir){
  if (abs(x_to - x_from) != 1){
    return(INVALID_MOVE);
  }

  if ((y_to - y_from) != dir){
    return(INVALID_MOVE);
  }

  return(VALID_MOVE);
}

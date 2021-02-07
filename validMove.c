#include <stdio.h>
#include "checkers.h"

int is_move_valid(int color, int x_from, int y_from, int x_to, int y_to){

  /* check if move is within bounds and handles the player pieces */
  
  if (prelim_move_check(color, x_from, y_from, x_to, y_to) == INVALID_MOVE){
    return(INVALID_MOVE);
  }


  return(VALID_MOVE);
}

int prelim_move_check(int color, int x_from, int y_from, int x_to, int y_to){
  /* is move in bounds? */
  
  // checks starting coordinate
  if ((x_from >= BOARD_SIZE) || (x_from <= -1) || (y_from >= BOARD_SIZE) || (y_from <= -1)){
    return(INVALID_MOVE);
  }

  // checks terminating coordinate
  if ((x_to >= BOARD_SIZE) || (x_to <= -1) || (y_to >= BOARD_SIZE) || (y_to <= -1)){
    return(INVALID_MOVE);
  }

  /* does move handle player pieces */
  int piece;
  piece = the_board[y_from][x_from];
  
  // checking if player colors correspond with piece being moved
  if (color == RED && piece == WHITE){
    return(INVALID_MOVE);
  }

  if (color == RED && piece == WHITE_KING){
    return(INVALID_MOVE);
  }

  if (color == WHITE && piece == RED){
    return(INVALID_MOVE);
  }

  if (color == WHITE && piece == RED_KING){
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


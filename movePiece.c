#include <stdio.h>
#include "checkers.h"

void move_piece(int color, int x_from, int y_from, int x_to, int y_to, int jump){

  /* Moving steps */
  if (!jump){
    the_board[y_to][x_to] = the_board[y_from][x_from];
    the_board[y_from][x_from] = 0;
  }

  /* Moving Jumps */

  if (jump){
    int piece;
    piece = the_board[y_from][x_from];
    the_board[y_from][x_from] = EMPTY;
    the_board[y_to][x_to] = piece;
    the_board[(y_to + y_from)/2][(x_to + x_from)/2] = EMPTY; // opposite player's piece that is being jumped over
  }
  
  /* Promoting a normal piece to king */
  if (color == RED && y_to == 7){
    the_board[y_to][x_to] = RED_KING;
  }

  if (color == WHITE && y_to == 0){
    the_board[y_to][x_to] = WHITE_KING;
  }
  
}

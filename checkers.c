#include <stdio.h>
#include <stdlib.h>
#include "checkers.h"

int the_board[BOARD_SIZE][BOARD_SIZE];
int color, x_from, y_from, x_to, y_to, move_validity;

void main(){

  /* Starting Orientation of Board */
  
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

  color = RED;
  
  while (TRUE){
    /* Printing Board */
    
    print_board();

    /* Prompting user for a valid move */
    
    prompt_move();
    move_validity = get_and_check_move();

    while (move_validity == INVALID_MOVE){
      printf("INVALID MOVE. TRY AGAIN!!\n");
      prompt_move();
      move_validity = get_and_check_move();
    }

    // TODO: Move validity
    // TODO: Making the Move (updating the board)


    /* Change Player after move made */

    change_player();

  }
}

int get_and_check_move(){
  scanf("%d %d %d %d", &x_from, &y_from, &x_to, &y_to);
  check_exit();
  return(is_move_valid(color, x_from, y_from, x_to, y_to));
}


void prompt_move(){
  switch(color) {
      case RED:
	printf("RED's move: ");
	break;

      case WHITE:
	printf("WHITE's move: ");
	break;
  }
}

void change_player(){
  switch(color) {
      case RED:
	color = WHITE;
	break;

      case WHITE:
	color = RED;
	break;
  }
  
}

void check_exit(){
  if (x_from == 0 && y_from == 0 && x_to == 0 && y_to == 0){
    exit(1);
  }
}


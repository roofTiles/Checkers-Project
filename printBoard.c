#include <stdio.h>
#include "checkers.h"

void print_board(){

  /* Printing column numbers of board */
  
  int col, row;
  printf("  ");
  for (col = 0; col < BOARD_SIZE; col++){
    printf(" %d  ", col); 
  }
  printf("\n");

  /* Printing each row of cells */

  for (row = 0; row < BOARD_SIZE; row++){
    print_row_border();
    print_row_data(row);
  }
  print_row_border();
}

/* Creates border between rows of cells on board */
void print_row_border(){
 int col;
 printf(" ");
 for (col = 0; col < BOARD_SIZE; col++){
    printf("|---");
 }
 printf("|\n");
}

/* Displays what checker piece each row of cells have */
void print_row_data(int row){
  int col;
  char checkerPiece;
  printf("%d", row);
  for (col = 0; col < BOARD_SIZE; col++){
    switch(the_board[row][col]){
      case EMPTY:
	checkerPiece = ' ';
	break;
	
      case RED:
        checkerPiece = 'r';
	break;

      case WHITE:
	checkerPiece = 'w';
	break;

      case RED_KING:
	checkerPiece = 'R';
	break;

      case WHITE_KING:
	checkerPiece = 'W';
	break;
    }
    printf("| %c ", checkerPiece);
  }
  printf("|\n");
}

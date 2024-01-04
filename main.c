#include "plansza.h"
#include <stdio.h>

int main() {
    int width = 5;
    int height = 5;

    Board *board = createBoard(width, height);
    printf("Początkowa pozycja mrówki: (%d, %d)\n", board->antX, board->antY);
    
    printBoard(board);
    freeBoard(board);

    return 0;
}

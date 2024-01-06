#include "plansza.h"
#include "logika.h"
#include <stdio.h>

int main() {
    int width = 20;
    int height = 20;
    int density = 20;

    Board *board = createBoard(width, height, density);
    
    // Początkowy kierunek mrówki
    board->antDirection = 0;
    
    printf("Początkowa pozycja mrówki: (%d, %d)\n", board->antX, board->antY);
    printBoard(board);
    
    for(int i = 0; i < 1000; i++) {
        if(ruch(board) == -1) {
            printf("Mrowka wyszla poza plansze!!!\n");
            return -1;
        };
    }

    // Wygląd planszy po 1000 iteracji:
    
    freeBoard(board);

    return 0;
}

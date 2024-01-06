#include "plansza.h"
#include "logika.h"
#include "argumenty.h"
#include <stdio.h>

int main(int argc, char **argv) {
    
    Arguments args = parseArguments(argc, argv);
    printf("Wymiary planszy: %d x %d\n", args.w, args.h);
    printf("Liczba iteracji: %d\n", args.i);
    printf("Nazwa pliku: %s\n", args.name);
    printf("Kierunek początkowy mrówki: %d\n", args.startDirection);


    Board *board = createBoard(args.w, args.h, args.o);
    
    // Początkowy kierunek mrówki
    board->antDirection = args.startDirection;
    
    printf("Początkowa pozycja mrówki: (%d, %d)\n", board->antX, board->antY);

    // Wygląd planszy przed iteracjami:
    printBoard(board);

    for(int i = 0; i < args.i; i++) {
        if(ruch(board) == -1) {
            printf("Mrowka wyszla poza plansze!!!\n");
            return -1;
        }
    }

    // Wygląd planszy po wykonaniu ostatniej iteracji
    printf("\n");
    printBoard(board);
    freeBoard(board);

    return 0;
}

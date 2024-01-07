#include "plansza.h"
#include "logika.h"
#include "argumenty.h"
#include <stdio.h>

int main(int argc, char **argv) {
    
    Arguments args = parseArguments(argc, argv);
    printf("Wymiary planszy: %d x %d\n", args.w, args.h);
    printf("Liczba iteracji: %d\n", args.i);
    printf("Nazwa pliku: %s\n", args.n);
    printf("Kierunek początkowy mrówki: %d\n", args.startDirection);
    printf("Zagęszczenie przeszkód: %d\n", args.o);
    

    // Tworzenie planszy
    Board *board;  // Deklaracja zmiennej board przed blokiem if-else

    printf("Wczytywanie planszy z pliku %s\n", args.l);

    // sprawdz czy podano plik
    if (args.l == NULL) {
        printf("Tworzenie nowej planszy\n");
        board = createBoard(args.w, args.h, args.o);
    } else {
        printf("Wczytywanie planszy z pliku %s\n", args.l);
        board = loadBoardFromFile(args.l);
    }


    board->antDirection = args.startDirection;
    
    printf("Początkowa pozycja mrówki: (%d, %d)\n", board->antX, board->antY);

    // Wygląd planszy przed iteracjami:
    printBoard(board);
    printf("\n\n\n");

    for(int i = 0; i < args.i; i++) {

        if(ruch(board) == -1) {
            printf("Mrowka wyszla poza plansze!!!\n");
            return -1;
        }
        saveBoardToFile(board, args.n, i);
    }

    // Wygląd planszy po wykonaniu ostatniej iteracji
    printf("\n");
    printBoard(board);
    freeBoard(board);

    return 0;
}



#include "plansza.h"
#include "logika.h"
#include "argumenty.h"
#include <stdio.h>

#define IN "source" // ścieżka do pliku w którym jest przechowywana plansza wejściowa
#define OUT "output" // ścieżka do pliku do którego chcemy zapisać kolejne plansze

void printData(Board *data, int iter, char* nazwa, int direction, int density) {
    printf("Wymiary planszy: %d x %d\n", data->width, data->height);
    printf("Liczba iteracji: %d\n", iter);
    printf("Nazwa pliku: %s\n", nazwa);
    printf("Kierunek początkowy mrówki: %d stopni\n", direction);
    printf("Zagęszczenie przeszkód: %d\n", density);
}

int main(int argc, char **argv) {

    Arguments args = parseArguments(argc, argv, OUT);
    // Tworzenie planszy
    Board *board;  // Deklaracja zmiennej board przed blokiem if-else

    // sprawdz czy podano plik
    if (args.l == NULL) {
        printf("\nTworzenie nowej planszy...\n\n");
        board = createBoard(args.w, args.h, args.o);
        printData(board, args.i, args.n, args.startDirection, args.o);
    } 
    else {
        char input[1024];
        sprintf(input, "%s/%s", IN, args.l);
        printf("\nWczytywanie planszy z pliku %s...\n", input);
        board = loadBoardFromFile(input);
    }

    board->antDirection = args.startDirection; // Ustawienie kierunku początkowego mrówki
    
    printf("Początkowa pozycja mrówki: (%d, %d)\n", board->antX, board->antY);
    printf("Miejsce zapisu: %s/%s\n", OUT, args.n);
    
    char output[1024]; // Zmienna do przechowywania ścieżki do pliku wyjściowego

    // Zapisanie początkowej planszy
    sprintf(output, "%s/%s_%d", OUT, args.n, 0); 
    saveBoardToFile(board, output);

    for(int i = 0; i < args.i; i++) { // Wykonanie iteracji

        if(ruch(board) == -1) {
            printf("Mrowka wyszla poza plansze!!!\n");
            return -1;
        }
        sprintf(output, "%s/%s_%d", OUT, args.n, i+1);
        saveBoardToFile(board, output);
    }

    printf("Plansze zostały pomyślnie zapisane\n");
    freeBoard(board);

    return 0;
}



#include "plansza.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

// Implementacja funkcji createBoard
Board *createBoard(int width, int height, int density) {
    Board *board = (Board *)malloc(sizeof(Board));
    board->width = width;
    board->height = height;
    board->cells = (Cell **)malloc(height * sizeof(Cell *));
    
    // Losowanie koloru komórek zgodnie z zadaną gęstością
    int volume = width * height;
    int *temp = (int*)calloc(volume, sizeof(int));
    int index, size;
    size = (volume*density/100);

    srand(time(NULL));
    for(int k = 0; k < size; k++) {
        index = rand()%volume;
        if(temp[index] == 0) temp[index] = 1;
        else k--;
    }

    // Inicjalizacja komórek
    index = 0;
    for (int i = 0; i < height; i++) {
        board->cells[i] = (Cell *)malloc(width * sizeof(Cell));
        for (int j = 0; j < width; j++) {
            if(temp[index] == 1) board->cells[i][j].symbol = 1;
            else board->cells[i][j].symbol = 0;
            index++;
        }
    }

    free(temp);

    // Początkowa pozycja mrówki
    board->antX = (width - width%2) / 2; 
    board->antY = (height - height%2) / 2;

    return board;
}

void freeBoard(Board *board) {
    for (int i = 0; i < board->height; i++) {
        free(board->cells[i]);
    }
    free(board->cells);
    free(board);
}

void printBoard(Board *board) {
    setlocale(LC_ALL, "C.UTF-8");
    for (int y = 0; y < board->height; y++) {
        // Rysowanie górnych granic komórek
        for (int x = 0; x < board->width; x++) {
            printf("┌─┐ ");
        }
        printf("\n");

        // Rysowanie środków komórek
        for (int x = 0; x < board->width; x++) {
            if (x == board->antX && y == board->antY) {
                // Jeżeli komórka jest biała to mrówka też jest biała
                if(board->cells[y][x].symbol == 0) {
                    switch(board->antDirection) {
                        case 0: printf("│△│ "); break;
                        case 90:  printf("│▷│ "); break;
                        case 180: printf("│▽│ "); break;
                        case 270:  printf("│◁│ "); break;
                    }
                }
                // Jeśli komórka jest czarna to mrówka też jest czarna
                if(board->cells[y][x].symbol == 1) {
                    switch(board->antDirection) {
                        case 0: printf("│▲│ "); break;
                        case 90:  printf("│▶│ "); break;
                        case 180: printf("│▼│ "); break;
                        case 270:  printf("│◀│ "); break;
                    }
                }
            }
            else if (board->cells[y][x].symbol == 0)
                printf("│ │ ");  // Białe pole
            else if (board->cells[y][x].symbol == 1)
                printf("│█│ ");  // Czarne pole
        }
        printf("\n");

        // Rysowanie dolnych granic komórek
        for (int x = 0; x < board->width; x++) {
            printf("└─┘ ");
        }
        printf("\n");
    
    }
}


void saveBoardToFile(Board *board, char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Nie można otworzyć pliku");
        return;
    }

    setlocale(LC_ALL, "C.UTF-8");


    // Zapisywanie wymiarów planszy na początku pliku
    fprintf(file, "%d %d\n", board->width, board->height);


    for (int y = 0; y < board->height; y++) {
        // Rysowanie górnych granic komórek
        for (int x = 0; x < board->width; x++) {
            fprintf(file, "┌─┐ ");
        }
        fprintf(file, "\n");

        // Rysowanie środków komórek
        for (int x = 0; x < board->width; x++) {
            if (x == board->antX && y == board->antY) {
                // Jeżeli komórka jest biała to mrówka też jest biała
                if(board->cells[y][x].symbol == 0) {
                    switch(board->antDirection) {
                        case 0: fprintf(file,"│△│ "); break;
                        case 90:  fprintf(file,"│▷│ "); break;
                        case 180: fprintf(file,"│▽│ "); break;
                        case 270:  fprintf(file,"│◁│ "); break;
                    }
                }
                // Jeśli komórka jest czarna to mrówka też jest czarna
                if(board->cells[y][x].symbol == 1) {
                    switch(board->antDirection) {
                        case 0: fprintf(file,"│▲│ "); break;
                        case 90:  fprintf(file,"│▶│ "); break;
                        case 180: fprintf(file,"│▼│ "); break;
                        case 270:  fprintf(file,"│◀│ "); break;
                    }
                }
            }
            else if (board->cells[y][x].symbol == 0)
                fprintf(file,"│ │ ");  // Białe pole
            else if (board->cells[y][x].symbol == 1)
                fprintf(file,"│█│ ");  // Czarne pole
        }
        fprintf(file,"\n");

        // Rysowanie dolnych granic komórek
        for (int x = 0; x < board->width; x++) {
            fprintf(file, "└─┘ ");
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

Board *loadBoardFromFile(const char *fileName) {

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Nie można otworzyć pliku");
        return NULL;
    }

    int width, height;
    if (fscanf(file, "%d %d", &width, &height) != 2) { // Wczytywanie wymiarów planszy
        fprintf(stderr, "Błąd formatu pliku: oczekiwano wymiarów planszy.\n");
        fclose(file);
        return NULL;
    }
    printf("Wysokosc: %d, szerokosc: %d", height, width);

    Board *board = createBoard(width, height,0);
    int x, p, y;

    char line[1024];
    const char *directions[] = {"△", "▷", "▽", "◁", "▲", "▶", "▼", "◀"};
    y = 0;
    p = 0;
    while (fgets(line, sizeof(line), file) != NULL) { // Wczytywanie kolejnych linii z pliku
        if (y % 3 == 2) { // Linie zawierające stan komórek i pozycję mrówki
            x = 0;        // Indeks kolumny
            char *token = strtok(line, " ");
            while (token != NULL) {
                for (int i = 0; i < 8; i++) { // Sprawdzam czy komórka zawiera mrówkę, a jeśli tak to w jakim kierunku jest zwrócona
                    if (strstr(token, directions[i])) {
                        if(x % 2 == 1) x++;
                        board->antX = x / 2;
                        board->antY = y / 3;
                        if(i > 3) board->cells[y / 3][x / 2].symbol = 1;
                        else board->cells[y / 3][x / 2].symbol = 0;
                        board->antDirection = (i % 4) * 90;
                        p = i;
                        break; // Zakończ pętlę po znalezieniu pasującego kierunku
                    }
                }
            
                if (strstr(token, "█")) {
                    if(x % 2 == 1) x++;
                    board->cells[y / 3][x / 2].symbol = 1;
                }
                
                else if (strstr(token, directions[p]) == NULL) { // Jeśli komórka nie zawiera mrówki, ani czarnego pola to jest to białe pole
                    board->cells[y / 3][x].symbol = 0;
                }
                x++;
                token = strtok(NULL, " ");
            }
        }
        y++;
    }

    printf("\n\nPlansza wczytana z pliku:\n");
    printBoard(board);
    printf("\n\n\n----------------\n\n\n");

    fclose(file);
    return board;
}
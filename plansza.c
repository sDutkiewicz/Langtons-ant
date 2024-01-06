#include "plansza.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Implementacja funkcji createBoard
Board *createBoard(int width, int height) {
    Board *board = (Board *)malloc(sizeof(Board));
    board->width = width;
    board->height = height;
    board->cells = (Cell **)malloc(height * sizeof(Cell *));

    // Inicjalizacja komórek
    for (int i = 0; i < height; i++) {
        board->cells[i] = (Cell *)malloc(width * sizeof(Cell));
        for (int j = 0; j < width; j++) {
            board->cells[i][j].symbol = 0;
        }
    }
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
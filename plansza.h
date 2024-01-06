#ifndef PLANSZA_H
#define PLANSZA_H


typedef struct {
    char symbol; // Przechowuje symbol reprezentujący stan komórki
} Cell;

// Definicja struktury planszy
typedef struct {
    int width;
    int height;
    Cell **cells;
    int antX, antY;
    int antDirection;
} Board;

// Prototypy funkcji
Board *createBoard(int, int, int);
void Colorchange(Board *board, int x, int y);
void freeBoard(Board *board);
void printBoard(Board *board);

#endif 

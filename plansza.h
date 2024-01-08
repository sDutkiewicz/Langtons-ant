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
void Colorchange(Board *, int, int);
void freeBoard(Board *);
void printBoard(Board *);
void saveBoardToFile(Board *, char *);
Board *loadBoardFromFile(const char *);

#endif

#include "plansza.h"
#include <stdio.h>

int ruch(Board *board) {
    int x = board->antX;
    int y = board->antY;

    // Jeżeli biały to 90 stopni w prawo, jeżeli czarny to 90 stopni w lewo
    switch(board->cells[y][x].symbol) {
        case 0: board->antDirection += 90; break;
        case 1: board->antDirection -= 90; break;
    }

    // Kąt nie może być większy od 360, więc jest równy reszcie z dzielenia przez 360, a jeśli jest ujemny to dodaje do niego 360
    if(board->antDirection < 0) board->antDirection = 360 + board->antDirection;
    board->antDirection = board->antDirection%360;

    // Funkcja zmieniająca kolor komórki na przeciwny
    board->cells[y][x].symbol = board->cells[y][x].symbol == 0 ? 1 : 0; // Zmiana koloru komórki na przeciwny (0 -> 1, 1 -> 0)

    // Zgodnie z kierunkiem ruchu zmieniam komórkę w której znajduje się mrówka
    switch(board->antDirection) {
                case 0: board->antY--; break;
                case 90: board->antX++; break;
                case 180: board->antY++; break;
                case 270:  board->antX--; break;
    }

    // Jeżeli któraś ze współrzędnych przekroczy wymiary planszy funkcja zwraca -1;
    if(board->antX >= board->height || board->antY >= board->width || board->antX < 0 || board->antY < 0) return -1;
    return 0;
}
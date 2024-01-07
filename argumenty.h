#ifndef ARGUMENTY_H
#define ARGUMENTY_H
#include <unistd.h>


typedef struct {
    int w; // szerokość
    int h; // wysokość
    int i; // liczba iteracji
    char *n; // nazwa pliku
    int startDirection; // kierunek początkowy mrówki
    int o; // zagęszczenie przeszkód (0 - 100)
    char *l; // nazwa pliku z plansza
} Arguments;

Arguments parseArguments(int argc, char **argv);

#endif //ARGUMENTY_H



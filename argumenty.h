#ifndef ARGUMENTY_H
#define ARGUMENTY_H
#include <unistd.h>


typedef struct {
    int w; // szerokość
    int h; // wysokość
    int i; // liczba iteracji
    char *name; // nazwa pliku
    int startDirection; // kierunek początkowy mrówki
} Arguments;

Arguments parseArguments(int argc, char **argv);

#endif //ARGUMENTY_H



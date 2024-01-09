#include "argumenty.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <getopt.h>

void opcje() {
    printf("\n#POMOC#\n");
    printf("-w <szerokość planszy (większa od 0, domyślnie 10)>\n");
    printf("-h <wysokość planszy (większa od 0, domyślnie 10)>\n");
    printf("-i <liczba iteracji (większa od 0, domyślnie 15)>\n");
    printf("-n <nazwa pliku wynikowego (domyślnie: plansza)>\n");
    printf("-d <początkowy kierunek mrówki (NORTH, WEST, SOUTH, EAST, domyślnie NORTH)>\n");
    printf("-o <zagęszczenie występowania przeszkód na mapie (0-100, domyślnie 0)>\n");
    printf("-l <nazwa pliku zawierającego planszę>\n\n");
}

Arguments parseArguments(int argc, char **argv, char *dir) {
    
    Arguments args = {10, 10, 15, "plansza", 0, 0, NULL}; // Inicjalizacja struktury

    int opt; // Zmienna przechowująca aktualnie przetwarzany argument

    while ((opt = getopt(argc, argv, "w:h:i:n:d:o:l:p")) != -1) {
        switch (opt) {
            case 'w':
                args.w = atoi(optarg);
                if (args.w < 0) {
                    printf("Szerokość planszy nie może być ujemna!\n");
                    printf("\nWpisz -p żeby otrzymać pomoc.\n\n");
                    exit(-1);
                }
                break;
            case 'h':
                args.h = atoi(optarg);
                if (args.h < 0) {
                    printf("Wysokość planszy nie może być ujemna!\n");
                    printf("\nWpisz -p żeby otrzymać pomoc.\n\n");
                    exit(-1);
                }
                break;
            case 'i':
                args.i = atoi(optarg);
                if (args.i < 0) {
                    printf("Liczba iteracji nie może być ujemna!\n");
                    printf("\nWpisz -p żeby otrzymać pomoc.\n\n");
                    exit(-1);
                }
                break;
            case 'n':
                args.n = strdup(optarg);
                break;
            case 'd':
                if (strcmp(optarg, "NORTH") == 0) args.startDirection = 0;
                else if (strcmp(optarg, "EAST") == 0) args.startDirection = 90;
                else if (strcmp(optarg, "SOUTH") == 0) args.startDirection = 180;
                else if (strcmp(optarg, "WEST") == 0) args.startDirection = 270;
                else {
                    printf("Niepoprawny kierunek początkowy mrówki!\n Powinien być NORTH, EAST, SOUTH lub WEST\n");
                    printf("\nWpisz -p żeby otrzymać pomoc.\n\n");
                    exit(-1);
                }
                break;
            case 'o':
                if(atoi(optarg) >= 0 && atoi(optarg) <= 100) args.o = atoi(optarg);
                else {
                    printf("Zagęszczenie przeszkód powinno być zawarte pomiędzy 0 - 100!\n");
                    printf("\nWpisz -p żeby otrzymać pomoc.\n\n");
                    exit(-1);
                }
                break;
            case 'l':
                args.l = strdup(optarg);
                break;
            case 'p':
                opcje();
                exit(-1);
                break;
            default:
                printf("\nWpisz -p żeby otrzymać pomoc.\n\n");
                exit(-1);
                break;
        }
    }
    return args;
}

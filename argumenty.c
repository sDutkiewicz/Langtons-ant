#include "argumenty.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <getopt.h>


Arguments parseArguments(int argc, char **argv) {
    
    Arguments args = {0, 0, 0, NULL,0}; // Inicjalizacja struktury

    int opt; // Zmienna przechowująca aktualnie przetwarzany argument

    while ((opt = getopt(argc, argv, "w:h:i:name:d:")) != -1) {
        switch (opt) {
            case 'w':
                args.w = atoi(optarg);
                break;
            case 'h':
                args.h = atoi(optarg);
                break;
            case 'i':
                args.i = atoi(optarg);
                break;
            case 'name':
                args.name = strdup(optarg);
                break;
            case 'd':
                if (strcmp(optarg, "NORTH") == 0) args.startDirection = 0;
                else if (strcmp(optarg, "EAST") == 0) args.startDirection = 90;
                else if (strcmp(optarg, "SOUTH") == 0) args.startDirection = 180;
                else if (strcmp(optarg, "WEST") == 0) args.startDirection = 270;
                else {
                    printf("Niepoprawny kierunek początkowy mrówki!\n");
                    exit(-1);
                }
            default:
                // Obsługa błędów
                break;
        }
    }
    return args;
}

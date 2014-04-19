#include "../neighborhood.h"
#include "../boardio.h"

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
    FILE *in = argc > 1 ? fopen(argv[1], "r") : NULL;

    if(in == NULL) {
        if(argc > 1)
            fprintf(stderr, "%s: problem z otwarciem pliku %s.\n", argv[0], argv[1]);
        else
            fprintf(stderr, "%s: prosze podac plik z danymi.\n", argv[0]);
        return 1;
    }
    // wczytywanie do board
    board_t *b = read_from_file(in);
    // wypisywanie na ekranie
    write_to_file(b, stdout);

    // sprawdzanie przykladowego sasiedztwa
    int x = 0;
    int y = 1;
    printf("komorka (%d, %d):\n stan: %d\n", x+1, y+1, get_cell(b, x, y));
    nbhood_t* neighbors = get_nbhood(b, x, y);

    for(int i = 0; i < 8; i++) {
        printf("sasiad nr %d: %d\n", i, neighbors->neighbors[i]);
    }

    set_cell(b, 0, 0, DEAD);
    // wypisywanie na ekranie
    write_to_file(b, stdout);

    return 0;
}

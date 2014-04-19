#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *usage =
    "Opcje: %s rn cn stream\n";

int
main(int argc, char **argv)
{
    int i, j;
    int rn = argc > 1 ? atoi(argv[1]) : 9;
    int cn = argc > 2 ? atoi(argv[2]) : 36;
    FILE* stream = argc > 3 ? atof(argv[3]) : "stdout";

    srand(time(NULL));

    fprintf(stream, "%d %d\n", rn, cn);
    for(i = 0; i < rn; i++) {
        for(j = 0; j < cn; j++)
            fprintf(stream, " %d", rand()%2);
        fprintf(stream, "  \n");
    }

    return 0;
}



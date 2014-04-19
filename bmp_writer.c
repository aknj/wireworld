#include "boardio.h"
#include <bmpfile.h>

const char* make_filename(char* basename, int i) {
    filename[0] = '\0';
    strcat(filename, basename);
    strcat(filename, "_");          // dopisanie do filename znaku _
    char buf[20];
    sprintf(buf, "%d", i);          // zamiana i na const char*
    char* c = buf;
    strcat(filename, c);            // dopisanie do filename numeru generacji
    strcat(filename, ".bmp");       // dopisanie do filename .bmp
}

write_to_bmp(b, filename);

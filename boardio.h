#ifndef _BOARDIO_H_
#define _BOARDIO_H_

#include "plansza.h"
#include <bmpfile.h>

board_t*    read_from_file(FILE* stream);

void        write_to_file(board_t* b, FILE* stream);

void        print_cell_to_bmp(bmpfile_t *bmp, int x, int y, int cell_sz, rgb_pixel_t color);

void        write_to_bmp(board_t* b, const char* filename);

#endif

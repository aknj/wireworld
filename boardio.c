#include "boardio.h"
#include "plansza.h"
#include <bmpfile.h>

const rgb_pixel_t dead = {255, 255, 255, 0};
const rgb_pixel_t alive = {0, 0, 0, 0};

board_t* read_from_file(FILE* stream) {
    int rn, cn;
    int i, j;
    int temp;
    board_t *new_board;
    if(fscanf(stream, "%d %d", &rn, &cn) != 2)
        return NULL;
    if((new_board = make_board(rn, cn)) == NULL)
        return NULL;
    for(i = 0; i < rn; i++)
        for(j = 0; j < cn; j++) {
            if(fscanf(stream, "%d", &temp) != 1) {
                free_board(new_board);
                return NULL;
            }
            new_board->state[i * cn + j] = temp;
        }
    return new_board;
}

void write_to_file(board_t* b, FILE* stream) {
    int i, j;
    if(b == NULL) {
        fprintf(stream, "Plansza jest pusta\n");
        return;
    }

    fprintf(stream, "%d %d\n", b->rn, b->cn);
    for(i = 0; i < b->rn; i++) {
        for(j = 0; j < b->cn; j++)
            fprintf(stream, " %d", b->state[i * b->cn + j]);
        fprintf(stream, "  \n");
    }
}

void print_cell_to_bmp(bmpfile_t *bmp, int x, int y, int cell_sz, rgb_pixel_t color) {
    int i, j;
    for(i = 0; i < cell_sz; i++)
        for(j = 0; j < cell_sz; j++)
            bmp_set_pixel(bmp, x+i, y+j, color);
}

void write_to_bmp(board_t* b, const char *filename) {
    bmpfile_t *bmp;
    int i, j;
    int cell_sz = 5;
    int depth = 1;
    int width = cell_sz * b->cn;
    int height = cell_sz * b->rn;

    /* "Usage: %s filename width height depth.\n" */

    bmp = bmp_create(width, height, depth);

    //rgb_pixel_t dead = {255, 255, 255, 0};
    //rgb_pixel_t alive = {0, 0, 0, 0};

    for(i = 0; i < height; i+=5) {
        for(j = 0; j < width; j+=5) {
            if(get_cell(b, i/5, j/5) == ALIVE) {
                print_cell_to_bmp(bmp, j, i, cell_sz, alive);
            }
            //else {
            //    bmp_set_pixel(bmp, j, i, dead);
            //}
        }
    }

    bmp_save(bmp, filename);
    bmp_destroy(bmp);
}

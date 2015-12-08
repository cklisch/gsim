#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define BLACK 0x00000000
#define WHITE 0x00FFFFFF
#define RED   0x00FF0000
#define GREEN 0x0000FF00
#define BLUE  0x000000FF
#define GREY  0xAFAFAFAA


void write_N_byte(FILE * file, uint64_t byte, int N);
void bitmap_file_header(FILE * file, int x, int y);
void bitmap_info_header(FILE * file, int x, int y);

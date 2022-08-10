#ifndef _COMMON_
    #define _COMMON_

#include <stdbool.h>    //bool
typedef unsigned short Board_item_t;
typedef unsigned short Board_t;

#define BOARD_SIZE 9
#define BOARD_SIZE_BYTES (BOARD_SIZE*sizeof(Board_item_t))

#define SEQ_NUMBERS_ASC {1,2,3,4,5,6,7,8,9}
#define SEQ_NUMBERS_DESC {9,8,7,6,5,4,3,2,1}

typedef struct{
    Board_item_t i;
    Board_item_t j;
}Coord_t;

#endif
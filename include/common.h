#ifndef _COMMON_
    #define _COMMON_

#include <stdbool.h>    //bool
typedef unsigned short Board_item_t;
typedef unsigned short Board_t;

#define size 9
#define size_bytes (size*sizeof(Board_item_t))

#define seq_numbers_asc {1,2,3,4,5,6,7,8,9}
#define seq_numbers_desc {9,8,7,6,5,4,3,2,1}

typedef struct{
    Board_item_t i;
    Board_item_t j;
}Coord;

#endif
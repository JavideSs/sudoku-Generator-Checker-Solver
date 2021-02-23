#ifndef _COMMON_
    #define _COMMON_

#define size 9
#define size_bytes (size*sizeof(int_board_t))

#define seq_numbers_asc {1,2,3,4,5,6,7,8,9}
#define seq_numbers_desc {9,8,7,6,5,4,3,2,1}

typedef unsigned short int_board_t;
typedef unsigned short Board_t;

typedef struct{
    int_board_t i;
    int_board_t j;
}Coord;

enum bool{false, true};

#endif
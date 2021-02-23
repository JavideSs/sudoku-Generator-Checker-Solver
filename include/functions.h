#ifndef _FUNCTIONS_
    #define _FUNCTIONS_

#include <stdlib.h> //rand
#include <string.h> //memset, memcpy, memcmp
#include "common.h"

void create_seq_numbers_rand(int_board_t seq_to_test[]);

void create_empty_board(Board_t[][size]);
void copy_board(Board_t board_copy[][size], Board_t board_to_copy[][size]);

enum bool compare_board(Board_t[][size], Board_t[][size]);
enum bool find_empty(Board_t board[][size], Coord* coord_empty);
enum bool valid_number(Board_t board[][size], Coord* coord, int_board_t number);

enum bool solve(Board_t board[][size], int_board_t seq_to_test[]);
void create(Board_t board_solved[][size], Board_t board_for_user[][size]);

#endif
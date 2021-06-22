#ifndef _FUNCTIONS_
    #define _FUNCTIONS_

#include <stdio.h>
#include "common.h"

void create_seq_numbers_rand(Board_item_t seq_to_rand[]);

void create_empty_board(Board_t[][size]);
void copy_board(Board_t board_copy[][size], Board_t board_to_copy[][size]);

bool compare_board(Board_t[][size], Board_t[][size]);
bool find_empty(Board_t board[][size], Coord* coord_empty);
bool valid_number(Board_t board[][size], Coord* coord, Board_item_t number);

bool solve(Board_t board[][size], Board_item_t seq_to_test[]);
void create(Board_t board_solved[][size], Board_item_t board_for_user[][size]);

#endif
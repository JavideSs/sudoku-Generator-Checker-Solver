#ifndef _FUNCTIONS_
    #define _FUNCTIONS_

#include <stdio.h>
#include "common.h"

void create_seq_numbers_rand(Board_item_t seq_to_rand[]);

void create_empty_board(Board_t[][BOARD_SIZE]);
void copy_board(Board_t board_copy[][BOARD_SIZE], Board_t board_to_copy[][BOARD_SIZE]);

bool compare_board(Board_t[][BOARD_SIZE], Board_t[][BOARD_SIZE]);
bool find_empty(Board_t board[][BOARD_SIZE], Coord_t* coord_empty);
bool valid_number(Board_t board[][BOARD_SIZE], Coord_t* coord, Board_item_t number);

bool solve(Board_t board[][BOARD_SIZE], Board_item_t seq_to_test[]);
void create(Board_t board_solved[][BOARD_SIZE], Board_item_t board_for_user[][BOARD_SIZE]);

#endif
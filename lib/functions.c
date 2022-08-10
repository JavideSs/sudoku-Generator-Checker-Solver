#include "functions.h"
#include <stdlib.h>     //rand
#include <string.h>     //memset, memcpy, memcmp

void create_seq_numbers_rand(Board_item_t seq_to_rand[]){
    Board_item_t seq_all[] = SEQ_NUMBERS_ASC;

    for (Board_item_t i=0; i<BOARD_SIZE; i++){
        Board_item_t pos_rand = rand()%(BOARD_SIZE-i);
        seq_to_rand[i] = seq_all[pos_rand];

        //The number used is discarded
        for (Board_item_t j=pos_rand; j<(BOARD_SIZE-i)-1; j++)
            seq_all[j] = seq_all[j+1];
    }
}


void create_empty_board(Board_t board[][BOARD_SIZE]){
    for (Board_item_t i=0; i<BOARD_SIZE; i++)
        memset(board[i], 0, BOARD_SIZE_BYTES);
}


void copy_board(Board_t board_copy[][BOARD_SIZE], Board_t board_to_copy[][BOARD_SIZE]){
    for (Board_item_t i=0; i<BOARD_SIZE; i++)
        memcpy(board_copy[i], board_to_copy[i], BOARD_SIZE_BYTES);
}


bool compare_board(Board_t board1[][BOARD_SIZE], Board_t board2[][BOARD_SIZE]){
    for (Board_item_t i=0; i<BOARD_SIZE; i++){
        if (memcmp(board1[i], board2[i], BOARD_SIZE_BYTES)!=0)
            return false;
    }
    return true;
}


bool find_empty(Board_t board[][BOARD_SIZE], Coord_t* coord_empty){
    for (Board_item_t i=0; i<BOARD_SIZE; i++){
        for (Board_item_t j=0; j<BOARD_SIZE; j++){
            if (board[i][j] == 0){
                coord_empty->i = i;
                coord_empty->j = j;
                return true;
            }
        }
    }
    return false;
}


bool valid_number(Board_t board[][BOARD_SIZE], Coord_t* coord, Board_item_t number){
    //row
    for (Board_item_t j=0; j<BOARD_SIZE; j++){
        if(board[coord->i][j] == number)
            return false;
    }
    //column
    for (Board_item_t i=0; i<BOARD_SIZE; i++){
        if (board[i][coord->j] == number)
            return false;
    }
    //square
    Board_item_t squares = BOARD_SIZE/3;
    Coord_t coord_rel_square = {(coord->i/squares)*squares, (coord->j/squares)*squares};
    for (Board_item_t i=coord_rel_square.i; i<coord_rel_square.i+3; i++){
        for (Board_item_t j=coord_rel_square.j; j<coord_rel_square.j+3; j++){
            if (board[i][j] == number)
                return false;
        }
    }
    return true;
}

//Backtracking Algorithm
bool solve(Board_t board[][BOARD_SIZE], Board_item_t seq_to_test[]){
    Coord_t coord_empty;

    if (!find_empty(board, &coord_empty))
        return true;

    for (Board_item_t i=0; i<BOARD_SIZE; i++){
        if (valid_number(board, &coord_empty, seq_to_test[i])){
            board[coord_empty.i][coord_empty.j] = seq_to_test[i];

            if (solve(board, seq_to_test))
                return true;
            else
                board[coord_empty.i][coord_empty.j] = 0;
        }
    }
    return false;
}


void create(Board_t board_solved[][BOARD_SIZE], Board_t board_for_user[][BOARD_SIZE]){
    Board_item_t seq_to_test_asc[] = SEQ_NUMBERS_ASC;
    Board_item_t seq_to_test_desc[] = SEQ_NUMBERS_DESC;
    Board_item_t seq_to_test_rand[BOARD_SIZE];
    create_seq_numbers_rand(seq_to_test_rand);

    Board_t board_test_asc[BOARD_SIZE][BOARD_SIZE];
    Board_t board_test_desc[BOARD_SIZE][BOARD_SIZE];

    create_empty_board(board_solved);
    solve(board_solved, seq_to_test_rand);
    copy_board(board_for_user, board_solved);

    Board_item_t i, j, number_last = 0;
    do{
        i = rand()%(BOARD_SIZE);
        j = rand()%(BOARD_SIZE);

        if (board_for_user[i][j] != 0){
            number_last =  board_for_user[i][j];
            board_for_user[i][j] = 0;

            //Solve in copy board as asc
            copy_board(board_test_asc, board_for_user);
            solve(board_test_asc, seq_to_test_asc);

            //Solve in copy board as desc
            copy_board(board_test_desc, board_for_user);
            solve(board_test_desc, seq_to_test_desc);
        }
    //If solved board desc != solved board asc -> more than one solution
    }while(compare_board(board_test_asc, board_test_desc));
    board_for_user[i][j] = number_last; //Get last board
}
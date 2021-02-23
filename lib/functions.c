#include "../include/functions.h"

void create_seq_numbers_rand(int_board_t seq_to_test_rand[]){
    int_board_t seq_all[] = seq_numbers_asc;

    for (int_board_t i=0; i<size; i++){
        int_board_t pos_rand = rand()%(size-i);
        seq_to_test_rand[i] = seq_all[pos_rand];

        //The number used is discarded 
        for (int_board_t j=pos_rand; j<(size-i)-1; j++)
            seq_all[j] = seq_all[j+1];
    }
}


void create_empty_board(Board_t board[][size]){
    for (int_board_t i=0; i<size; i++)
        memset(board[i], 0, size_bytes);
}


void copy_board(Board_t board_copy[][size], Board_t board_to_copy[][size]){
    for (int_board_t i=0; i<size; i++)
        memcpy(board_copy[i], board_to_copy[i], size_bytes);
}


enum
bool compare_board(Board_t board1[][size], Board_t board2[][size]){
    for (int_board_t i=0; i<size; i++){
        if (memcmp(board1[i], board2[i], size_bytes)!=0)
            return false;
    }
    return true;
}


enum
bool find_empty(Board_t board[][size], Coord* coord_empty){
    for (int_board_t i=0; i<size; i++){
        for (int_board_t j=0; j<size; j++){
            if (board[i][j] == 0){
                coord_empty->i = i;
                coord_empty->j = j;
                return true;
            }
        }
    }
    return false;
}


enum
bool valid_number(Board_t board[][size], Coord* coord, int_board_t number){
    //row
    for (int_board_t j=0; j<size; j++){
        if(board[coord->i][j] == number)
            return false;
    }
    //column
    for (int_board_t i=0; i<size; i++){
        if (board[i][coord->j] == number)
            return false;
    }
    //square
    int_board_t squares = size/3;
    for (int_board_t i=(coord->i/squares)*squares; i<squares; i++){
        for (unsigned j=(coord->j/squares)*squares; j<squares; j++){
            if (board[i][j] == number)
                return false;
        }
    }
    return true;
}

//Backtracking Algorithm
enum
bool solve(Board_t board[][size], int_board_t seq_to_test[]){
    Coord coord_empty;

    if (!find_empty(board, &coord_empty))
        return true;

    for (unsigned i=0; i<size; i++){
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


void create(Board_t board_solved[][size], Board_t board_for_user[][size]){
    int_board_t seq_to_test_asc[] = seq_numbers_asc;
    int_board_t seq_to_test_desc[] = seq_numbers_desc;
    int_board_t seq_to_test_rand[size];
    create_seq_numbers_rand(seq_to_test_rand);

    Board_t board_test_asc[size][size];
    Board_t board_test_desc[size][size];
    
    create_empty_board(board_solved);
    solve(board_solved, seq_to_test_rand);
    copy_board(board_for_user, board_solved);

    int_board_t i, j, number_last;
    do{
        i = rand()%(size);
        j = rand()%(size);

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
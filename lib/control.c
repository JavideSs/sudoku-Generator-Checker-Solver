#include "control.h"

void option_create(){
    Board_t board_solved[size][size];
    Board_t board_for_user[size][size];

    create(board_solved, board_for_user);
    print_board(board_for_user);

    char option;
    bool loop;
    do{
        show_create_menu();
        scanf("%c", &option); getchar();

        switch (option){
            case '1':
                clearTerminal;

                Board_t board_user[size][size];
                copy_board(board_user, board_for_user);
                input_board_for_user(board_user);

                if (compare_board(board_solved, board_user)){
                    printf("Sudoku correct! :)\nPress any key to continue...");
                    getchar();
                    loop = false;
                }
                else{
                    printf("Sudoku wrong! :(\nPress any key to try again...");
                    getchar();
                    loop = true;
                }
                break;

            case '2':
                printf("\nSOLUTION:\n");
                print_board(board_solved);
                printf("Press return to continue...");
                getchar();
                loop = false;
                break;

            case 'b':
                loop = false;
                break;

            default:
                show_bad_option();
                loop = true;
        }
    }while(loop);
}


void option_check(){
    Board_t board_user[size][size];
    input_board(board_user);
    Board_t board_aux[size][size];

    for (Board_item_t i=0; i<size; i++){
        for (Board_item_t j=0; j<size; j++){
            Coord coord = {i,j};

            //Copy of the board with the cell at 0, so as not to be invalidated by it self
            copy_board(board_aux, board_user);
            board_aux[i][j] = 0;

            if (!valid_number(board_aux, &coord, board_user[i][j])){
                printf("Sudoku wrong! :(\nPress any key to continue...");
                return;
            }
        }
    }
    printf("Sudoku correct! :)\nPress any key to continue...");
}


void option_solve(){
    Board_t board_user[size][size];
    input_board(board_user);

    Board_item_t seq_to_test_asc[] = seq_numbers_asc;
    solve(board_user, seq_to_test_asc);

    printf("\nSOLUTION:\n");
    print_board(board_user);
    printf("Press return to continue...");
    getchar();
}
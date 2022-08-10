#include "interface.h"

/*
2 -> initial margin
2*(i/3) -> extra separation in each block
2*i -> separation between cells
2+2*(i/3)+2*i = (8/3)*i+2
*/
#define column_cells_jump(i) 2+2*(i/3)+2*i

/*
1 -> initial margin
(j/3) -> extra separation in each block
j -> separation between cells
1+(j/3)+j = (4/3)*j+1
*/
#define row_cells_jump(j) 1+(j/3)+j

void ansi_in_windows(){
    #if defined ENABLE_VIRTUAL_TERMINAL_PROCESSING
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD mode; GetConsoleMode(hConsole, &mode);
        SetConsoleMode(hConsole, mode|ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    #endif
}


void show_main_menu(){
    printf("OPTIONS:\n\
1- Create Sudoku\n\
2- Check Sudoku\n\
3- Solve Sudoku\n\
q- Quit\n\
Option: ");
}


void show_create_menu(){
    printf("OPTIONS:\n\
1- Check Sudoku\n\
2- Solve Sudoku\n\
b- Back\n\
Option: ");
}


void show_bad_option(){
    printf("~BAD OPTION :/\n_______________\n");
}


void get_items(Board_t board[][size], bool board_is_empty){
    for (Board_item_t j=0; j<size; j++){
        for (Board_item_t i=0; i<size; i++){
            if (!board_is_empty && board[j][i] != 0)
                continue;

            printf("\033[%d;%df", row_cells_jump(j), column_cells_jump(i));
            if(scanf("%hd", &board[j][i]) > 0) getchar();
        }
    }
}


void input_board(Board_t board[][size]){
    create_empty_board(board);
    print_board(board);
    printf("If there is no number put 0");

    get_items(board, true);

    printf("\n\n\n");
}


void input_board_for_user(Board_t board[][size]){
    print_board(board);

    get_items(board, false);

    printf("\n");
}


void print_board(Board_t board[][size]){
    for (Board_item_t i=0; i<size; i++){
        if (i!=0 && i%3==0)
            printf("- - - - - - - - - - - -\n");

        for (Board_item_t j=0; j<size; j++){
            if (j!=0 && j%3==0)
                printf(" |");

            if (board[i][j] != 0)   printf(" %d", board[i][j]);
            else                    printf(blank_cell);
        }
        printf("\n");
    }
    printf("______________________\n");
}
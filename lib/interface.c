#include "interface.h"

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


void input_board(Board_t board[][size]){
    create_empty_board(board);
    print_board(board);
    printf("If there is no number put 0");

    for (Board_item_t i=0; i<size; i++){
        for (Board_item_t j=0; j<size; j++){
            printf("\033[%d;%df", 2*i-(i-1)+(i/3), 2*j+2+2*(j/3));
            scanf("%hd", &board[i][j]); getchar();
        }
    }
    printf("\n\n\n");
}


void input_board_for_user(Board_t board[][size]){
    print_board(board);

    for (Board_item_t i=0; i<size; i++){
        for (Board_item_t j=0; j<size; j++){
            if (board[i][j] != 0)
                continue;

            printf("\033[%d;%df", 2*i-(i-1)+(i/3), 2*j+2+2*(j/3));
            scanf("%hd", &board[i][j]); getchar();
        }
    }
    printf("\n");
}
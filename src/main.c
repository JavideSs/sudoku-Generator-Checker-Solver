#include <stdio.h>
#include <stdlib.h> //system, srand
#include <time.h>   //time

#include "interface.h"
#include "control.h"

int main(){
    srand(time(NULL));
    ansi_in_windows();

    char option;
    do{
        show_main_menu();
        scanf("%c", &option); getchar();

        switch (option){
            case '1':
                clearTerminal;
                option_create();
                clearTerminal;
                break;

            case '2':
                clearTerminal;
                option_check();
                break;

            case '3':
                clearTerminal;
                option_solve();
                break;

            case 'q':
                break;

            default:
                show_bad_option();
                break;
        }
    }while(option != 'q');

    return 0;
}
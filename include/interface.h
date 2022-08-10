#ifndef _INTERFACE_
    #define _INTERFACE_

#include <stdio.h>
#include "common.h"
#include "functions.h"

#if defined MSDOS || defined _WIN32 || defined _WIN64
    #include <windows.h>
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #define clearTerminal system("cls")
    #define blank_cell " %c", ((char)250)
#else
    #define clearTerminal system("clear")
    #define blank_cell " ·"
#endif

void ansi_in_windows();

void show_main_menu();
void show_create_menu();
void show_bad_option();

void print_board(Board_t[][BOARD_SIZE]);
void input_board(Board_t[][BOARD_SIZE]);
void input_board_for_user(Board_t[][BOARD_SIZE]);

#endif
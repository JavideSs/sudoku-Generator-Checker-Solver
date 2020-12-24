/*Example
6 0 4 0 9 0 0 0 1 0 0 0 4 0 0 6 0 0 0 8 5 6 0 7 0 0 0 0 6 0 1 8 0 5 4 0 5 3 8 0 0 0 1 6 7 0 0 0 7 0 5 0 0 8 8 5 6 0 0 0 0 1 4 7 1 2 0 4 6 0 0 3 4 0 3 0 0 1 0 0 6
6 2 4 3 9 8 7 5 1 1 7 9 4 3 2 6 8 5 3 8 5 6 1 7 4 2 9 9 6 7 1 8 3 5 4 2 5 3 8 9 2 4 1 6 7 2 4 1 7 6 5 9 3 8 8 5 6 2 7 9 3 1 4 7 1 2 5 4 6 8 9 3 4 9 3 8 5 1 2 7 6
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#if defined POSIX
  #define clearTerminal system("clear")
#elif defined MSDOS || defined WIN32
  #define clearTerminal system ("cls")
#endif

const int size = 9;

#define numbers_asc {1,2,3,4,5,6,7,8,9}
#define numbers_desc {9,8,7,6,5,4,3,2,1}

void input_board(int board[][size]);
void print_board(int board[][size]);
void create_empty_board(int board[][size]);
void copy_board(int board[][size], int board_copy[][size]);
bool compare_board(int board1[][size], int board2[][size]);

bool find_empty(int board[][size], int coord_empty[]);
bool valid_number(int board[][size], int coord[], int number);

bool solve(int board[][size], int numbers_order_to_test[]);
void create(int board_created_solved[][size], int board_created_final[][size]);

int main(){
    srand(time(NULL));

    while(true){
        clearTerminal;
        cout<<"OPTIONS:        "<< endl
            <<"1) Create Sudoku"<< endl
            <<"2) Check Sudoku "<< endl
            <<"3) Solve Sudoku "<< endl
            <<"Other number -> Exit"<< endl
            <<"--------------------"<< endl
            <<"                "<< endl
            <<"Option: ";
        int option; cin >> option;
        clearTerminal;

        switch(option){
            case 1:{
                bool loop = true;
                while(loop){
                    int board_created_solved[size][size], board_created_final[size][size];
                    create(board_created_solved, board_created_final);
                    print_board(board_created_final);
                    cout <<endl<<"_______________________"<< endl<<endl;

                    cout<<"OPTIONS:        "<< endl
                        <<"1) Check Sudoku "<< endl
                        <<"2) Solve Sudoku "<< endl
                        <<"Other number -> Main Menu"<< endl
                        <<"-------------------------"<< endl
                        <<"                "<< endl
                        <<"Option: ";
                        int option_create; cin >> option_create;

                    switch(option_create){
                        case 1:{
                            int board_user[size][size];
                            clearTerminal;
                            input_board(board_user);
                            if(compare_board(board_created_solved, board_user)){
                                print_board(board_user);
                                cout <<endl<<"The sudoku is correct"<< endl;
                                cout <<endl<<"Press return to continue..."; char sleep_; cin.ignore(100,'\n'); cin.get(sleep_);
                            }
                            else{
                                print_board(board_user);
                                cout <<endl<<"The sudoku is wrong"<< endl;
                                cout <<endl<<"Press return to try again..."; char sleep_; cin.ignore(100,'\n'); cin.get(sleep_);
                            }
                            clearTerminal;
                            break;
                        }

                        case 2:{
                            cout <<endl<<"SOLUTION:"<< endl;
                            print_board(board_created_solved);
                            cout <<endl<<"Press return to continue..."; char sleep_; cin.ignore(100,'\n'); cin.get(sleep_);
                            loop = false; break;
                        }

                        default:{
                            loop = false; break;
                        }
                    }
                }
                break;
            }

            case 2:{
                int board[size][size];
                input_board(board);
                bool is_correct = true;
                for(unsigned i=0; i<size; i++){
                    for(unsigned j=0; j<size; j++){
                        int coord[2]; coord[0] = i; coord[1] = j;
                        int board_aux[size][size];
                        copy_board(board, board_aux);
                        board_aux[i][j] = 0;
                        if(!valid_number(board_aux, coord, board[i][j])){
                            is_correct = false;
                        }
                    }
                }
                print_board(board);
                if(is_correct){ cout <<endl<<"The sudoku is correct"<< endl;}
                else{           cout <<endl<<"The sudoku is wrong"<< endl;}
                cout <<endl<<"Press return to continue..."; char sleep_; cin.ignore(100,'\n'); cin.get(sleep_);
                break;
            }

            case 3:{
                int board[size][size];
                cout <<"If there is no number put 0"<<endl<< endl;
                input_board(board);
                int numbers_order_to_test[] = numbers_asc;
                print_board(board);
                solve(board, numbers_order_to_test);
                cout <<endl<<"SOLUTION:"<< endl;
                print_board(board);
                cout <<endl<<"Press return to continue..."; char sleep_; cin.ignore(100,'\n'); cin.get(sleep_);
                break;
            }

            default:
                exit(0);
        }
    }
    return 0;
}



//______________________________________________________________________________________

void input_board(int board[][size]){
    create_empty_board(board);
    for(unsigned i=0; i<size; i++){
        for(unsigned j=0; j<size; j++){
            print_board(board);
            cout <<endl<<"Number in F-"<<i+1<<", C-"<<j+1<<" : ";
            cin >> board[i][j];
            clearTerminal;
        }
    }
}


void print_board(int board[][size]){
    for(unsigned i=0; i<size; i++){
        if(i!=0 && i%3==0){ cout <<"- - - - - - - - - - - -"<< endl;}
        for(unsigned j=0; j<size; j++){
            if(j!=0 && j%3==0){ cout <<" |";}

            if(board[i][j] != 0){   cout <<" "<<board[i][j];}
            else{                   cout <<" "<<(char)250;}
        }
        cout<<endl;
    }
}


void create_empty_board(int board[][size]){
    for(unsigned i=0; i<size; i++){
        for(unsigned j=0; j<size; j++){
            board[i][j] = 0;
        }
    }
}


void copy_board(int board[][size], int board_copy[][size]){
    for(unsigned i=0; i<size; i++){
        for(unsigned j=0; j<size; j++){
            board_copy[i][j] = board[i][j];
        }
    }
}

bool compare_board(int board1[][size], int board2[][size]){
    for(unsigned i=0; i<size; i++){
        for(unsigned j=0; j<size; j++){
            if(board1[i][j] != board2[i][j]){
                return false;
            }
        }
    }
    return true;
}

//______________________________________________________________________________________


bool find_empty(int board[][size], int coord_empty[]){
    for(unsigned i=0; i<size; i++){
        for(unsigned j=0; j<size; j++){
            if(board[i][j] == 0){
                coord_empty[0] = i;
                coord_empty[1] = j;
                return true;
            }
        }
    }
    return false;
}


bool valid_number(int board[][size], int coord[], int number){
    //row
    for(unsigned i=0; i<size; i++){
        if(board[coord[0]][i] == number){
            return false;
        }
    }
    //column
    for(unsigned i=0; i<size; i++){
        if(board[i][coord[1]] == number){
            return false;
        }
    }
    //square
    int squares = size/3;
    for(unsigned i=(coord[0]/squares)*squares; i<squares; i++){
        for(unsigned j=(coord[1]/squares)*squares; j<squares; j++){
            if(board[i][j] == number){
                return false;
            }
        }
    }
    return true;
}

//______________________________________________________________________________________

//Backtracking Algorithm
bool solve(int board[][size], int numbers_order_to_test[]){
    int coord_empty[2];
    bool coord_is_empty = find_empty(board, coord_empty);

    //No quedan mas vacias -> el juego se acaba
    if(!coord_is_empty){ return true;}

    for(unsigned i=0; i<size; i++){
        if(valid_number(board, coord_empty, numbers_order_to_test[i])){
            board[coord_empty[0]][coord_empty[1]] = numbers_order_to_test[i];

            bool board_solve = solve(board, numbers_order_to_test);
            if(board_solve){    return true;}
            else{               board[coord_empty[0]][coord_empty[1]] = 0;}
        }
    }
    return false;
}


void create(int board_created_solved[][size], int board_created_final[][size]){
    create_empty_board(board_created_solved);

    //Numbers order rand
    int numbers_all[] = numbers_asc, numbers_rand_order_to_test[size];
    for(unsigned i=0; i<size; i++){
        int pos_rand_number_all = rand()%(size-i);
        numbers_rand_order_to_test[i] = numbers_all[pos_rand_number_all];
        for(unsigned j=pos_rand_number_all; j<(size-i)-1; j++){
            numbers_all[j] = numbers_all[j+1];
        }
    }
    solve(board_created_solved, numbers_rand_order_to_test);

    copy_board(board_created_solved, board_created_final);

    bool one_solution = true;
    int numbers_order_asc[] = numbers_asc;
    int numbers_order_desc[] = numbers_desc;
    int i, j, number_last;
    do{
        i = rand()%(size); j = rand()%(size);

        if(board_created_final[i][j] != 0){
            number_last = board_created_final[i][j];
            board_created_final[i][j] = 0;

            //Solve in copy board as asc
            int board_test_asc[size][size];
            copy_board(board_created_final, board_test_asc);
            solve(board_test_asc, numbers_order_asc);

            //Solve in copy board as desc
            int board_test_desc[size][size];
            copy_board(board_created_final, board_test_desc);
            solve(board_test_desc, numbers_order_desc);

            //If solved board desc != solved board asc -> more than one solution
            one_solution = compare_board(board_test_asc, board_test_desc);
        }
    }while(one_solution);
    board_created_final[i][j] = number_last;  //Get last board
}
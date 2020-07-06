//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Laurent Zheng on 2020-07-05.
//  Copyright © 2020 Laurent Zheng. All rights reserved.
//

#include <iostream>
#include <string>
void display_current_board();
int* position (std::string input);
void change_matrix(std::string new_val, std::string input);
bool check_for_win (std::string player);
bool correct_input (std::string x);
void game_interface(std::string player);
std::string ttt [3][3] = {  "A1", "A2", "A3",
                            "B1", "B2", "B3",
                            "C1", "C2", "C3"}; // this will represent the our tictactoe matrix.

int main() {
    std::cout << "Welcome to TicTacToe created by Laurent Zheng. Player 1 starts with \"X\", followed by Player 2 with \"O\". Please Enter a unfilled grid value to play :) Enter \"STOP\" to stop game at anytime" << std::endl;
    display_current_board();
    std::string current_player;
    for (int i=0; i<9; i++){
        if (i%2 == 0){
            current_player = "X";
        }
        else{
            current_player = "O";
        }
        game_interface(current_player);
    }
    std::cout << "It's a draw..." << std::endl; // It will be a draw if and only if there has been 9 rounds.
    return 0;
}



void display_current_board(){
    std::cout << "Current Board: " << std::endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            std::cout << ttt[i][j] << ' ';
            if (j == 2){
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

int cur_position [2];
//returns the desired position of the matrix as array of size 2(through its pointer) after the user gives us the desired grid value.
int* position (std::string input){
    char input_arr [input.length()];
    strcpy(input_arr, input.c_str());
    cur_position[0] = input_arr[0] - 65;
    cur_position[1] = input_arr[1] - 49;
    int* pointer_to_position = cur_position;
    return pointer_to_position;
    ;
}

//Changing the assigned value in the original matrix.
void change_matrix(std::string new_val, std::string input){
    ttt[*(position(input))][*(position(input)+1)] = new_val;
}

//Used in the interface to see if the "player" input has won the game.
bool check_for_win (std::string player){
    for (int i=0; i<3; i++){
        if (ttt[i][0] == ttt[i][1] && ttt[i][1] == ttt[i][2] && ttt[i][2] == player){
            return 1;
        }
        else if (ttt[0][i] == ttt[1][i] && ttt[1][i] == ttt[2][i] && ttt[2][i] == player){
            return 1;
        }
    }
    if (ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2] && ttt[2][2] == player){
        return 1;
    }
    if (ttt[2][0] == ttt[1][1] && ttt[1][1] == ttt[0][2] && ttt[0][2] == player){
        return 1;
    }
    return 0;
}

//Check if input is a valid grid
bool correct_input (std::string x){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (x == ttt[i][j]){
                return 1;
            }
        }
    }
    return 0;
}

//This is the main interface that checks each scenario of the game
void game_interface(std::string player){
    std::string grid_val;
    if (player == "X"){
            std::cout << "Player 1: " << std::endl;
    }else{
            std::cout << "Player 2: " << std::endl;
    }
    std::cin >> grid_val;
    if (grid_val == "STOP") {
        std::cout << "Game manually terminated." << std::endl;
        exit(0);
    }
    while (!correct_input(grid_val)){
        std::cout << "Unrecognized input, or grid has already been filled."<< std::endl;
        std::cout << "Please enter proper grid location: ";
        std::cin >> grid_val;
        std::cout << std::endl;
    }
    change_matrix(player, grid_val);
    display_current_board();
    if (check_for_win(player)){
        if (player == "X"){
            std::cout<< "Player1 won the game!" << std::endl;;
        }
        else{
            std::cout<< "Player2 won the game!" << std::endl;
        }
        exit(0);
    }
}




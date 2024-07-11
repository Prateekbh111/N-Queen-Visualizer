#include <iostream>
#include <windows.h>
#include <vector>
#include "textUtils.h"
using namespace std;

 //Clear the board from the console (more precisely push it above)
void clearBoard();

//Update the board with "ch" on given row and col. Also change color to red if isBad is true otherwise color is set to yellow
void updateBoard(int row, int col, string ch, bool isBad);

//Draw the give board to the console
void drawBoard(vector<vector<char>>& oard);

//Draw an empty baord to the console
void drawEmptyBoard();
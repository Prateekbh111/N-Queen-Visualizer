#include "board.h"
extern int N;
extern vector<vector<char>>& board;

void clearBoard() {
    cout << "\033[2J\033[1;1H";
}

void updateBoard(int row, int col, string ch, bool isBad = false) {
   COORD coord = { (short)(col * 4 + 1), (short)(row * 2 + 1) };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
   cout << changeColor(ch, isBad ? 'R' : 'Y');
}

void drawEmptyBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << " ---";
        cout << endl;

        for (int j = 0; j < N; j++) {
            if (j == 0) cout << "|";
               cout << "   |";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) cout << " ---";
    cout << endl << endl;
}

void drawBoard(vector<vector<char>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << " ---";
        cout << endl;

        for (int j = 0; j < N; j++) {
            if (j == 0) cout << "|";
               cout << " " << ((board[i][j] == 'Q') ? changeColor("Q", 'Y') : " ") << " |";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) cout << " ---";
    cout << endl << endl;
}

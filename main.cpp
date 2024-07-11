#include "main.h"
using namespace std;

void consoleInit(void){
    SetConsoleOutputCP(CP_UTF8);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // Set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void visualizerInit(void){
   for(int i = 0; i<consoleWidth; i++){
      cout << "=";
   }
   string welcomeText = "WELCOME TO N-queen Visualizer ♛";
   cout << "\n\n";
   cout << changeColor(onCenter(welcomeText, consoleWidth), 'Y') << endl;
   cout << changeColor(onCenter("↓ Enter value of N to get Started ↓", consoleWidth), 'B') << endl;

   cout << onCenter("",consoleWidth);
   cin >> N;
}

bool isSafe(const vector<string>& board, int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void solveNQueensUtil(vector<string>& board, int row) {
    if (row >= N){
        updateBoard(N,0,"",false);
        cout << changeBg(to_string(solNum++) + addSuffix(solNum) +" Solution Found", 'G') << "\n\n";
        Sleep(delay);
        clearBoard();
        drawBoard(board);
        Sleep(delay);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';
            updateBoard(row, col, " Q", false);
            Sleep(delay);

            solveNQueensUtil(board, row + 1);

            board[row][col] = '.';
            updateBoard(row, col, "  ", false);
        } else {
            board[row][col] = 'Q';
            updateBoard(row, col, " Q", true);
            Sleep(delay);

            board[row][col] = '.';
            updateBoard(row, col, "  ", false);
        }
    }
    return;
}

void solveNQueens() {
   if(N<4){
      cout << changeColor(onCenter("Solution Doesn't exist!!!", consoleWidth),'R');
      return;
   }
   string init = "";
   for(int i = 0; i<N; i++) init += ".";
   vector<string> board(N, init);
    clearBoard();
    drawEmptyBoard();
    solveNQueensUtil(board, 0);
    updateBoard(N,0,"",false);
    cout << changeBg("No More Solution Found!!!", 'R') << "\n\n";

}

int main()
{
   consoleInit();
   visualizerInit();
   solveNQueens();

   return 0;
}
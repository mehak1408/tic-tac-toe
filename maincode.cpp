#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char current_player = 'X';

void displayBoard() {
    cout << "\n";
    for(int i=0; i<3; i++) {
        for(int j=0;j<3;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isWinner() {
    for(int i=0;i<3;i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return true;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return true;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return true;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return true;
    return false;
}

bool isDraw() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]!='X' && board[i][j]!='O')
                return false;
    return true;
}

void makeMove() {
    int pos;
    cout << "Player " << current_player << ", enter position (1-9): ";
    cin >> pos;
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_player;
        current_player = (current_player == 'X') ? 'O' : 'X';
    } else {
        cout << "Position already taken. Try again.\n";
        makeMove();
    }
}

int main() {
    while(true) {
        displayBoard();
        makeMove();
        if(isWinner()) {
            displayBoard();
            cout << "Player " << ((current_player=='X') ? 'O' : 'X') << " wins!\n";
            break;
        }
        if(isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
    }
    return 0;
}
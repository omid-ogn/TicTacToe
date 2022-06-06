// creating simple tictactoe game
// using object oriented programming
// omid-ogn -- 2022-06-06 

#include <iostream>  // including headers
using namespace std; 

class TicTacToe {   // defining game class
public:
    void Play_game();     // function can play game

private:
    void Init();    // function for init game board
    void Show_borad();  // function for print game board
    void Get_input();   // function for input
    void Make_change(int input);    // function for change in board
    bool Have_winner();     // function for check game has a winner
    bool Tie();     // function for check game is tie
    string Winner_person();     // if game have winner check who is winner

    int input;
    char board[3][3];
    int turn = 1;
};

void TicTacToe::Play_game() {
    Init();
    while (!Have_winner() && !Tie()) {
        Show_borad();
        Get_input();
        system("clear");
    }
    cout << (Have_winner() ? Winner_person() : "tie") << endl; 
}

void TicTacToe::Init() {
    for (int i = 0;i < 3;++i)
        for (int j = 0;j < 3;++j)
            board[i][j] = '0' + ((i) * 3 + j + 1);
}

void TicTacToe::Show_borad() {
    for (int i = 0;i < 3;++i) {
            for (int j = 0;j < 3;++j)
                cout << board[i][j] << " ";
            cout << endl;
        }
}

void TicTacToe::Get_input() {
    cout << "enter your turn : ";
    cin >> input;   // get input in value input
    Make_change(input);     // call function make change for that input
}

void TicTacToe::Make_change(int input) {
    int x = input % 3 ? input % 3 - 1: 2, y = (input - 1) / 3;
    if (board[y][x] == 'X' || board[y][x] == 'O') {     // input is wrong
        cout << "Your input is wrong" << endl;
        Get_input();    // geting input again
    } 
    else {  // input is corecct
        turn ? board[y][x] = 'X' : board[y][x] = 'O';
        turn ^= 1;  // change turn for next player
    }
}

bool TicTacToe::Have_winner() {
    for (int i = 0;i < 3;++i) { // check horizontal and vertical 
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) 
            return true;
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return true;
    }
        // checking Diameters
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return true;

    return false;
}

bool TicTacToe::Tie() { 
    for (int i = 0;i < 3;++i) // checking board is full or not
            for (int j = 0;j < 3;++j)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;

        return true;
}

string TicTacToe::Winner_person() {
    return (turn ? "winner is O" : "winner is X"); 
}

int main() {
    TicTacToe t;
    t.Play_game();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define INF 1000
#define -INF -1000

int counter, x, y, licznik, next_player, winner, game_board[3][3];
bool finished;
char player1, player2;

int checkScore(){
    // 2 player2 wins
    // 1 player1 wins
    // 0 draw
    // -1 game is still on

    // Vertical
    for(int i=0; i<3; i++){
        if((game_board[i][0] == game_board[i][1]) && (game_board[i][0] == game_board[i][2]) && (game_board[i][0] != 0)){
            return game_board[i][0];
        }
    }

    // Horizontal
    for(int i=0; i<3; i++){
        if((game_board[0][i] == game_board[1][i]) && (game_board[0][i] == game_board[2][i]) && (game_board[0][i] != 0)){
            return game_board[0][i];
        }
    }

    // Diagonal
    if((game_board[0][0] == game_board[1][1]) && (game_board[0][0] == game_board[2][2]) && (game_board[0][0] != 0)){
        return game_board[0][0];
    }
    if((game_board[0][2] == game_board[1][1]) && (game_board[0][2] == game_board[2][0]) && (game_board[0][2] != 0)){
        return game_board[0][2];
    }

    int emptycntr = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(game_board[i][j] == 0) emptycntr++;
        }
    }
    if(emptycntr > 0) return -1;
    return 0;
}

void printBoard(){
    cout << "------------------------\n";
    for(int i=2; i>=0; i--){
        for(int j=0; j<3; j++){
            if(game_board[j][i] == 1){
                cout << "X";
            } else if(game_board[j][i] == 2){
                cout << "O";
            } else{
                cout << "_";
            }
        }
        cout << "\n";
    }
    cout << "------------------------\n";
}

int minimax(int player, bool isMaximizing, int alpha, int beta){
    int result = checkScore();
    if(result != -1) {
        licznik++;
        if(result == 0) return 0;
        if(result == player) return 1;
        return -1;
    }
    if(isMaximizing){
        int bestScore = -INF;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(game_board[j][i] == 0){
                    game_board[j][i] = player;
                    int score = minimax(player,false, alpha, beta);
                    game_board[j][i] = 0;
                    bestScore = max(score, bestScore);
                    alpha = max(alpha, score);
                    if(alpha >= beta) return bestScore;
                }
            }
        }
        return bestScore;
    }
    int bestScore = INF;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(game_board[j][i] == 0){
                game_board[j][i] = (player%2)+1;
                int score = minimax(player, true, alpha, beta);
                game_board[j][i] = 0;
                bestScore = min(score, bestScore);
                beta = min(beta, score);
                if(beta <= alpha) return bestScore;
            }
        }
    }
    return bestScore;
}

void AIMove(int player){
    int bestResult = -1000; // -infinity
    pair<int,int> bestMove;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(game_board[j][i] == 0){
                game_board[j][i] = player;
                int result = minimax(player,false, -INF, INF);
                game_board[j][i] = 0;
                if(result > bestResult){
                    bestResult = result;
                    bestMove = {j, i};
                }
            }
        }
    }
    game_board[bestMove.f][bestMove.s] = player;
    next_player = (player%2)+1;
}

bool makeMove(char playerType, int playernum) {
    if(playerType == 'H') {
        cout << "Enter X, Y coordinates: ";
        cin >> x >> y;
        game_board[x-1][y-1] = playernum;
    } else{
        AIMove(playernum);
    }
    printBoard();
    if(checkScore() != -1) {
        return true;
    }
    return false;
}

int main(){
    cout << "Enter game type: (H - human, B - bot)\n";
    cin >> player1 >> player2;
    while(!finished) {
        finished = makeMove(player1, 1);
        if(finished) break;
        finished = makeMove(player2, 2);
    }
    if (checkScore() == 0) cout << "Draw";
    else cout<< "Winner is Player" << checkScore();
    cout << " " << licznik;
}

#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isWin(vector<string> board, char player)
{
    for (int i = 0; i <3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        else if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1]== player && board[2][0] == player) return true;
    
    return false;
}

int solution(vector<string> board) {
    
    pair<int, int> cnt; //'O', 'X'
    for (auto a : board)
    {
        for (auto b : a)
        {
            if (b == 'O') cnt.first++;
            else if (b == 'X') cnt.second++;
        }
    }
    
    if (cnt.first < cnt.second || cnt.first - cnt.second >= 2) return 0;
    
    bool o_win = isWin(board, 'O');
    bool x_win = isWin(board, 'X');
    
    if (o_win && x_win) return 0;
    if (o_win && cnt.first != cnt.second + 1) return 0;
    if (x_win && cnt.first != cnt.second) return 0;
    
    
    return 1;
}
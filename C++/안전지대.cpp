#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = board.size() * board.size();
    vector<vector<int>> count;
    count.resize(board.size(), vector<int>(board[0].size(), 0));
    

    for (int row = 0; row < board.size(); ++row)
        {
            for (int col = 0; col < board[row].size(); ++col)
                {
                    if (board[row][col] == 1)
                    {
                        count[row][col] = 1;

                        if (row != 0) count[row - 1][col] = 1;
                        if (col != 0) count[row][col - 1] = 1;
                        if (row != 0 && col != 0) count[row - 1][col - 1] = 1;
                        if (row != board.size() - 1) count[row + 1][col] = 1;
                        if (col != board[row].size() - 1) count[row][col + 1] = 1;
                        if (row != board.size() - 1 && col != board[row].size() - 1) count[row + 1][col + 1] = 1;
                        if (row != 0 && col != board[row].size() - 1) count[row - 1][col + 1] = 1;
                        if (row != board.size() - 1 && col != 0) count[row + 1][col - 1] = 1;
                    }
                }
        }

    for (auto row : count)
        {
            for (auto col : row)
                if (col == 1) answer--;
        }
    
    
    return answer;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int memo = 0;
    
    int board_x = board.size();
    int board_y = board[0].size();
    
    vector<vector<int>> attack(board_x + 1, vector<int>(board_y + 1));
    
    for (int i = 0; i < skill.size(); ++i)
    {
        if (skill[i][0] == 1)
        {
            skill[i][5] = skill[i][5] * -1;
        }
        
        attack[skill[i][1]][skill[i][2]] += skill[i][5];
        attack[skill[i][3] + 1][skill[i][2]] -= skill[i][5];
        attack[skill[i][1]][skill[i][4] + 1] -= skill[i][5];
        attack[skill[i][3] + 1][skill[i][4] + 1] += skill[i][5];
    }
    
    //세로
    for (int i = 0; i < board_y; ++i)
    {
        memo = 0;
        for (int j = 0; j < board_x; ++j)
        {
            attack[j][i] += memo;
            memo = attack[j][i];
        }
    }
    
    //가로
    for (int i = 0; i < board_x; ++i)
    {
        memo = 0;
        for (int j =0; j < board_y;++j)
        {
            attack[i][j] += memo;
            memo = attack[i][j];
        }
    }
    
    for (int i = 0; i < board_x; ++i)
    {
        for(int j = 0; j < board_y; ++j)
        {
            if (board[i][j] + attack[i][j] > 0)
                answer++;
        }
    }
    
    return answer;
}
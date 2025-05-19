#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<char>> board;

int remove_1(char target)
{
    vector<vector<bool>> visible(n + 2, vector<bool>(m + 2));
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    int cnt = 0;
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            
            if (x < 0 || x >= n + 2 || y < 0 || y >= m + 2 || visible[x][y]) continue;
            
            visible[x][y] = true;
            
            if (board[x][y] == '0')
            {
                q.push({x,y});
            }
            else if (board[x][y] == target)
            {
                board[x][y] = '0';
                cnt++;
            }
        }
    }
    
    return cnt;
}

int remove_2(char target)
{
    vector<vector<bool>> visible(n + 2, vector<bool>(m + 2));
    queue<pair<int, int>> q;
    q.push({0, 0,});
    
    int cnt = 0;
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            
            if (x < 0 || x >= n + 2 || y < 0 || y >= m + 2 || visible[x][y]) continue;
            
            visible[x][y] = true;
            if (board[x][y] == target)
            {
                board[x][y] = '0';
                cnt++;
            }
            q.push({x, y});
        }
    }
    return cnt;
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].size();
    
    board.resize(n + 2, vector<char>(m + 2, '0'));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            board[i][j] = storage[i-1][j-1];
    }
    
    int answer = n * m;
    for (auto str : requests)
    {
        if (str.size() == 1)
        {
            answer -= remove_1(str[0]);
        }
        else
        {
            answer -= remove_2(str[0]);
        }
    }
    
    return answer;
}
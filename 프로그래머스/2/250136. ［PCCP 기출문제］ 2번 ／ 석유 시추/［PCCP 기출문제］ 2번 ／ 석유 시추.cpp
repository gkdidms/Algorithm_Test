#include <string>
#include <vector>
#include <map>
#include <queue>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt = 2;

using namespace std;

map<int, int> table;
int bfs(vector<vector<int>>& land, vector<bool>& visible, pair<int, int> start)
{
    int idx = land[start.first][start.second];
    if (idx == 0)
        return 0;
    
    if (idx > 1)
    {
        if (!visible[idx])
        {
            visible[idx] = true;
            return table[idx];
        }
       else
          return 0;
    }
    
    priority_queue<pair<int, int>> q;
    q.push(start);
    land[start.first][start.second] += 1;
    
    int count = 1;
    
    while(!q.empty())
    {
        pair<int, int> pos = q.top();
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int x = pos.first + dx[i];
            int y = pos.second + dy[i];
            
            if (x < 0 || x >= land.size() || y < 0 || y >= land[0].size())
                continue;
            
            if (land[x][y] == 1)
            {
                land[x][y] = cnt;
                q.push({x, y});
                ++count;
            }
        }
    }
    
    table.insert({cnt, count});
    visible[cnt] = true;
    cnt++;
    return count;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    //시추관
    for (int i = 0; i < land[0].size(); ++i)
    {
        int count = 0;
        vector<bool> visible(500 * 500);
        //땅의 깊이
        for (int j = 0; j < land.size(); ++j)
        {
            count += bfs(land, visible, make_pair(j, i));
            answer = max(answer, count);
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<int>> graph;

int bfs(int StartX, int StartY)
{
    if (graph[StartX][StartY] == 0)
        return 0;
    
    queue<pair<int, int>> q;
    q.push({StartX, StartY});
    int cnt = graph[StartX][StartY];
    graph[StartX][StartY] = 0;
        
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[nx].size() || graph[nx][ny] == 0)
                continue;
            
            cnt += graph[nx][ny];
            graph[nx][ny] = 0;
            q.push({nx , ny});
        }
    }
    
    return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    graph.resize(maps.size(),vector<int>(maps[0].size()));
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] == 'X')
                graph[i][j] = 0;
            else
                graph[i][j] = maps[i][j] - '0';
        }            
    }
    
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            int anw = bfs(i,j);
            if (anw != 0)
                answer.push_back(anw);
        }
    }
    
    if (answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}
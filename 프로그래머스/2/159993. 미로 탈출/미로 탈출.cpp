#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(pair<int, int> start, pair<int, int> target, vector<vector<string>> graph, vector<vector<bool>>& visible)
{
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, start});
    
    while(!q.empty())
    {
        int count = -q.top().first;
        pair<int, int> pos = q.top().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int x = pos.first + dx[i];
            int y = pos.second + dy[i];
            
            if (x < 0 || x >= graph.size() || y < 0 || y >= graph[0].size())
                continue;
            
            if (target.first == x && target.second == y)
            {
                return count + 1;
            }
            
            if (!(graph[x][y] == "X") && !visible[x][y])
            {
                visible[x][y] = true;
                q.push({ -(count + 1), {x, y}});
            }
        }
    }
    
    return -1;
}


int solution(vector<string> maps) {
    pair<int, int> start;
    pair<int, int> target;
    pair<int, int> exit;
    vector<vector<string>> graph(maps.size());
    vector<vector<bool>> visible(maps.size(), vector<bool>(maps[0].size()));
    
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            string str(1, maps[i][j]);
            if (str == "S")
            {
                start = { i, j};
            }
            if (str == "L")
            {
                target = {i, j};
            }
            if (str == "E")
            {
                exit = {i, j};
            }
            
            graph[i].push_back(str);
        }
    }
    
    int answer = bfs(start, target, graph, visible);
    if (answer == -1)
        return answer;
    
    visible.clear();
    visible.resize(graph.size(), vector<bool>(graph[0].size()));
    
    int answer2 = bfs(target, exit, graph, visible);
    if (answer2 == -1)
        return answer2;
    
    return answer + answer2;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int x, y, count;
};

vector<vector<int>> graph;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int startX, int startY, int itemX, int itemY)
{
    vector<vector<bool>> visible(102, vector<bool>(102));
    queue<node> q;
    q.push({startX, startY, 0});
    visible[startX][startY] = true;
    
    while(!q.empty())
    {
        node n = q.front();
        q.pop();
        
        if (n.x == itemX && n.y == itemY)
        {
            return n.count / 2;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            int x = dx[i] + n.x;
            int y = dy[i] + n.y;
            
            if (x < 0 || x >= 102 || y < 0 || y >= 102 || graph[x][y] != 1 || visible[x][y]) continue;
            
            visible[x][y] = true;
            q.push({x, y, n.count + 1});
        }
    }
    
    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    graph.resize(102, vector<int>(102));

    for (const auto r : rectangle)
    {
        int rx = r[2] * 2;
        int ry = r[3] * 2;
        int lx = r[0] * 2;
        int ly = r[1] * 2;
        
        for (int i = lx + 1; i < rx; ++i)
        {
            for (int j = ly + 1; j < ry; ++j)
            {
                graph[i][j] = 2;
            }
        }
        
        //x
        for(int i = lx; i <= rx; ++i)
        {
            if (graph[i][ly] != 2) graph[i][ly] = 1;
            if (graph[i][ry] != 2) graph[i][ry] = 1;
        }
        
        //y
        for (int i = ly; i <= ry; ++i)
        {
            if (graph[lx][i] != 2) graph[lx][i] = 1;
            if (graph[rx][i] != 2) graph[rx][i] = 1;
        }
    }
    
    answer = bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return answer;
}
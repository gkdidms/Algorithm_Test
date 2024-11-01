#include <string>
#include <vector>
#include <map>

using namespace std;

map<pair<int, pair<int, int>>, int> graph;
void Update(pair<int, pair<int, int>> key)
{
    if (graph.find(key) != graph.end())
        ++graph[key];
    else
        graph.insert({key, 1});
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    for (int i = 0; i < routes.size(); ++i)
    {
        int time = 0;
        for (int j = 0; j < routes[i].size() - 1; ++j)
        {
            //현재 위치
            int curX = points[routes[i][j] - 1][0];
            int curY = points[routes[i][j] - 1][1];
            
            //목적지 위치
            int nextX = points[routes[i][j + 1] - 1][0];
            int nextY = points[routes[i][j + 1] - 1][1];
            
            //목적지까지 가기 위한 이동값
            int distX = nextX - curX > 0 ? 1 : -1;
            int distY = nextY - curY > 0 ? 1 : -1;
            
            if (j == 0)
                Update({time++, {curY, curX}});
            
            //y좌표 먼저 이동
            while(nextX != curX)
            {
                curX += distX;
                Update({time++, {curY, curX}});
            }
            
            while(nextY != curY)
            {
                curY += distY;
                Update({time++, {curY, curX}});
            }
        }
    }
    
    for (auto anw : graph)
    {
        int count = anw.second;
        if (count > 1)
            ++answer;
    }
    
    return answer;
}
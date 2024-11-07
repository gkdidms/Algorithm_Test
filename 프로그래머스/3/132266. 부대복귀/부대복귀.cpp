#include <string>
#include <vector>
#include <queue>

using namespace std;

int dijkstra(int start, int n, int destination, vector<vector<int>>& graph)
{
    vector<bool> visible(n + 1);  
    queue<pair<int, int>> q; //카운트와 노드
    q.push({0, start});
    
    while(!q.empty())
    {
        int count = q.front().first;
        int node = q.front().second;
        q.pop();
        
        if (node == destination)
            return count;
        
        for (auto temp : graph[node])
        {
            if (!visible[temp])
            {
                visible[temp] = true;
                q.push({count + 1, temp});
            }
        }
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> graph(n + 1);
    
    for (auto road : roads)
    {
        graph[road[0]].emplace_back(road[1]);
        graph[road[1]].emplace_back(road[0]); 
    }
    
    for (auto a : sources)
    {
        answer.push_back(dijkstra(a, n, destination, graph));
    }
    
    return answer;
}
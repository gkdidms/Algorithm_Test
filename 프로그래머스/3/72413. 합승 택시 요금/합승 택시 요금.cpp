#include <string>
#include <vector>
#include <queue>
#include <map>

#define INF 20000000

using namespace std;

vector<vector<pair<int, int>>> graph;

int bfs(int s, int anw)
{
    vector<int> dist(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    dist[s] = 0;
    
    while(!q.empty())
    {
        int pay = q.top().first;
        int node = q.top().second;
        q.pop();
        
        if (anw == node) break;
        
        for (auto b : graph[node])
        {
            int next_node = b.first;
            int cost = b.second + pay;
            
            //한번도 들린 적 없다면?
            if (dist[next_node] > cost)
            {
                dist[next_node] = cost;
                q.push({cost, next_node});
            }
        }
    }
    
    return dist[anw];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    graph.resize(n + 1);
    
    for (auto fare : fares)
    {
        graph[fare[0]].push_back({fare[1], fare[2]});
        graph[fare[1]].push_back({fare[0], fare[2]});
    }
    
    int a_dist = bfs(s, a);
    int b_dist = bfs(s, b);
    
    answer = a_dist + b_dist;
    
    for (int i = 1; i <=n; ++i)
    {
        if (s != i)
            answer = min(answer, bfs(s,i) + bfs(i, a) + bfs(i, b));
    }
    
    return answer;
}
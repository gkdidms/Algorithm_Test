#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> visible;
struct node{
    int n = 0, cnt = 0;    
};

void bfs()
{
    queue<node> q;
    q.push({1, 0});
    visible[1] = 1;
    
    while(!q.empty())
    {
        node n = q.front();
        q.pop();
        
        for (auto a : graph[n.n])
        {
            int cost = n.cnt + 1;
            
            if (visible[a] == 0)
            {
                visible[a] = cost;
                q.push({a, cost});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    graph.resize(n + 1);
    visible.resize(n + 1);
    
    for (auto a : edge)
    {
        graph[a[0]].push_back(a[1]);   
        graph[a[1]].push_back(a[0]);    
    }
    
    bfs();
    
    int maxInt = 0;
    for (auto v : visible)
    {
        if (v > maxInt)
        {
            maxInt = v;
            answer = 1;
        }
        else if (v == maxInt)
        {
            answer++;
        }
    }
    
    return answer;
}
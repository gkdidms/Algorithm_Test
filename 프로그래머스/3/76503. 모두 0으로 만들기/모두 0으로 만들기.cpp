#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;

long long answer = 0;

void dfs(vector<long long>& sum, int now, int parent)
{
    for (int i = 0; i < graph[now].size(); ++i)
    {
        if (graph[now][i] != parent)
            dfs(sum, graph[now][i], now);
    }
    
    sum[parent] += sum[now];
    answer += abs(sum[now]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    
    vector<long long> sum(a.size());
    for (int i = 0; i< a.size(); ++i) sum[i] = a[i];
    
    graph.resize(a.size());
    for (auto a : edges)
    {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }
    
     dfs(sum, 0, 0);
    
    if (sum[0] == 0) return answer;
    else return -1;
}
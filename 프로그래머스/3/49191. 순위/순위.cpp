#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> graph;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    graph.resize(n + 1, vector<int>(n + 1));

    for (auto a : results)
    {
        graph[a[0]][a[1]] = 1;
        graph[a[1]][a[0]] = -1;
    }
        
    
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (graph[i][j] != 0) continue;
                else if (graph[i][k] == 1 && graph[k][j] == 1) graph[i][j] = 1;
                else if (graph[i][k] == -1 && graph[k][j] == -1) graph[i][j] = -1;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (graph[i][j] != 0) sum++;
        }
            
        if (sum == n - 1) answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visible;
int count_node(int node)
{
    int cnt = 0;
    for (auto a : graph[node])
    {
        if (visible[a]) cnt++;
    }
    
    return cnt;
}

bool count_tree(int start)
{
    visible[start] = true;
    
    int c = count_node(start);
    if ((start % 2 == 1 && ((graph[start].size() - c) % 2 ) == 0) || (start % 2 == 0 && ((graph[start].size()- c) % 2 ) == 1))
        return false;
    
    int cnt = 0;
    for (auto node : graph[start])
    {
        if (visible[node]) continue;
        
        if (!count_tree(node)) return false;
    }
    
    return true;
}

bool count_reverse_tree(int start)
{
    visible[start] = true;
    
    int c = count_node(start);
    if ((start % 2 == 1 && ((graph[start].size() - c) % 2) == 1) || (start % 2 == 0 && ((graph[start].size()- c) % 2 ) == 0))
        return false;
    
    int cnt = 0;
    for (auto node : graph[start])
    {
        if (visible[node]) continue;
        
        if (!count_reverse_tree(node)) return false;
    }
    
    return true;
}

void clear()
{
    visible.clear();
    visible.resize(1000001);
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2);
    
    graph.resize(1000001);
    for (int i = 0; i < edges.size(); ++i)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    
    for (auto a : nodes)
    {
        clear();
        answer[0] += count_tree(a);
        clear();
        answer[1] += count_reverse_tree(a);
    }
    
    return answer;
}
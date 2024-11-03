#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INF int(1e9)

vector<bool> visible;
int minResult = INF;

void bfs(int x, int y, int n)
{
    priority_queue<pair<int,int>> q;
    q.push({0, x});
    
    while(!q.empty())
    {
        int count = -q.top().first;
        int num = q.top().second;
        q.pop();
        
        if (num == y)
        {
            minResult = min(minResult, count);
        }
        
        for (int i = 0; i < 3; ++i)
        {
            int change = num;
            
            if (i == 0)
                change *= 3;
            else if (i == 1)
                change *= 2;
            else if (i == 2)
                change += n;
            
            if (change > y || change < x || visible[change])
                continue;
            
            visible[change] = true;
            q.push({-(count + 1), change});
        }
    }
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    visible.resize(1000001);
    bfs(x, y, n);
    
    return minResult < INF ? minResult : -1;
}
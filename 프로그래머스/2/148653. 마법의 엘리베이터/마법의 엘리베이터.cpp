#include <string>
#include <vector>
#include <queue>

using namespace std;

int result = int(1e9);

void bfs(int n)
{
    priority_queue<pair<int, int>> q;
    q.push({0, n});
    
    while(!q.empty())
    {
        int count = -q.top().first;
        int storey = q.top().second;
        q.pop();
        
        if (storey == 0)
        {
            result = min(result, count);
            return;
        }
        
        int anw = storey % 10;
        int atr = storey / 10;
        
        if (anw < 5)
        {
            count += anw;
            storey = atr;
        }
        else if (anw > 5)
        {
            count += 10 - anw;
            storey = atr + 1;
        }
        else if (anw == 5)
        {
            if (atr % 10 < 5)
            {
                count += anw;
                storey = atr;
            }
            else
            {
                count += 10 - anw;
                storey = atr + 1;
            }
        }
        
         q.push({-count, storey});
    }
}

int solution(int storey) {
    int answer = 0;
    
    bfs(storey);
    return result;
}
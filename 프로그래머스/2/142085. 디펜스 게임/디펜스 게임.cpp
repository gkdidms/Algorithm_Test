#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> q;
    
    for (int i = 0; i < enemy.size(); ++i)
    {
        q.push(-enemy[i]);
        if (q.size() > k)
        {
            answer += -q.top();
            q.pop();
        }
        
        if (answer > n) return i;
    }
    
    return enemy.size();
}
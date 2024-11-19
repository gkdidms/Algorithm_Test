#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> q;
    for (auto a : works)
        q.push(a);
    
    for (int i = n; i > 0; --i)
    {
        if (q.empty()) break;
        
        int work = q.top();
        q.pop();
        work -= 1;
        
        if (work > 0) q.push(work);
    }
    
    while(!q.empty())
    {
        answer += pow(q.top(), 2);
        q.pop();
    }
    
    return answer;
}
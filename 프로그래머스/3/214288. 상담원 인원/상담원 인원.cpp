#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> orders;

int simul(vector<vector<int>> reqs, vector<int> visible)
{
    priority_queue<int, vector<int>, greater<int>> pq[visible.size()]; // 끝나는 시간
    int result = 0;
    
    for (int i = 1; i < visible.size(); ++i)
        for (int j = 0; j < visible[i]; ++j) pq[i].push(0);
    
    for (auto req : reqs)
    {
        int arrive = req[0]; 
        int time = req[1];
        int idx = req[2];
        
        int picked = pq[idx].top();
        pq[idx].pop();
        
        //멘토의 시간 > 요청 시각
        if (picked > arrive)
        {
            result += picked - arrive;
            pq[idx].push(picked + time);
        }
        else if (picked < arrive) pq[idx].push(arrive + time);
        else pq[idx].push(picked + time);
    }
    
    return result;
}

void combi(int remain, int idx, vector<int> visible)
{
    if (remain <= 0)
    {
        orders.push_back(visible);
        return;
    }
    
    for (int i = idx; i < visible.size(); ++i)
    {
        visible[i]++;
        combi(remain - 1, i, visible);
        visible[i]--;
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 99999999;
    
    vector<int> visible(k + 1, 1);
    
    combi(n - k, 1, visible);
    
    for (auto order : orders)
        answer = min(answer, simul(reqs, order));
    
    return answer;
}
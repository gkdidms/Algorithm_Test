#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//요청부터 종료까지의 시간이 짧은 것을 우선순위로 잡고 진행하자.
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    //소요 시간 오름차순
    sort(jobs.begin(), jobs.end());
    
    int idx = 0;
    int now = jobs[idx][0];
    
    priority_queue<pair<int, int>> q; // 소요시간, 시작 시간
    q.push({-jobs[idx][1], jobs[idx][0]});
        
    idx++;
    while(!q.empty())
    {
        int end_time = -q.top().first;
        int start_time = q.top().second;
        q.pop();
        
        answer += (now + end_time) - start_time;
        now += end_time;
        
        while (idx < jobs.size() && jobs[idx][0] <= now)
        {
            q.push({-jobs[idx][1], jobs[idx][0]});
            ++idx;
        }
        
        if (q.empty() && idx < jobs.size())
        {
            q.push({-jobs[idx][1], jobs[idx][0]});
            now = jobs[idx][0];
            ++idx;
        }
        
    }
    
    return answer / jobs.size();
}
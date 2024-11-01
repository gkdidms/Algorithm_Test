#include <string>
#include <vector>

using namespace std;

//이분탐색 해결..
//제한 시간 내에 퍼질을 모두 해결하기 위한 숙련도의 최솟값을 정수로 return 하도록 solution 함수 완성
long long check(vector<int> diffs, vector<int> times, int level)
{
    long long answer = 0;
    int time_prev = 0;
    for (int i = 0; i < diffs.size(); ++i)
    {
        if (diffs[i] > level)
            answer += (times[i] + time_prev) * (diffs[i] - level) + times[i];
        else 
            answer += times[i];
        
        time_prev = times[i];
    }
    
    return answer;
}
int curr(vector<int> diffs, vector<int> times, long long limit)
{
    int max = 1, min = 100000;
    int level = (max + min) / 2;
    while(max <= min)
    {
        level = (max + min) / 2;
        long long time = check(diffs, times, level);
        if (limit < time) max = level + 1;
        else min = level - 1;
    }
    
    return max;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    return curr(diffs, times, limit);
}
#include <string>
#include <vector>

using namespace std;

bool check(int n, long long mid, vector<int>& times)
{
    long long sum = 0;
    
    for (long long time : times)
        sum += mid / time;
    
    if (sum < n) return false;
    
    return true;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long start = times[0];
    long long end = 1000000000L * 100000L;
    long long mid = 0;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
        
        if (check(n, mid, times))
        {
            answer = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

bool result(vector<int> stones, int k, int mid)
{
    int cnt = 0;
    
    for(int i = 0; i < stones.size(); ++i)
    {
        if (stones[i] - mid <= 0)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        
        if (cnt == k) return false;
    }
    
    return true;
}


int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int end =  200000000;
    
    while(answer < end)
    {
        int mid = (answer + end) / 2;
        bool anw = result(stones, k, mid);
        
        if (anw == true) answer = mid + 1;
        else end = mid;
    }
    
    return answer;
}
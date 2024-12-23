#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    
    vector<int> v(e + 1);
    
    int cnt = 0;
    
    for (int i = 1; i <= e; ++i)
    {
        for (int j = 1; j <= e; ++j)
        {
            if(i * j > e) break;
            v[i * j]++;
        }
    }
    
    vector<pair<int, int>> dp(e + 1);
    dp[e] = dp[e] = {e, v[e]};
    for (int i = e - 1; i >= 1; --i)
    {
        if (dp[i + 1].second > v[i])
            dp[i] = dp[i + 1];
        else
            dp[i] = {i, v[i]};
    }
   
    for (auto s : starts)
        answer.push_back(dp[s].first);
    
    return answer;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 120 + 12;
int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    vector<vector<bool>> dp(MAX, vector<bool>(MAX));
    dp[0][0] = true;
    
    for (int i = 0; i < info.size(); ++i)
    {
        vector<vector<bool>> nextDP(MAX, vector<bool>(MAX));
        int A = info[i][0];
        int B = info[i][1];
        
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                if (!dp[j][k]) continue;
                
                if (j + A < n) nextDP[j + A][k] = true;
                if (k + B < m) nextDP[j][k + B] = true;
            }   
        }
        
        for (int j = 0; j < n; ++j)
        {
            for(int k = 0; k < m; ++k)
            {
                dp[j][k] = nextDP[j][k];
            }
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dp[i][j]) return i;
        }
    }
    
    return -1;
}
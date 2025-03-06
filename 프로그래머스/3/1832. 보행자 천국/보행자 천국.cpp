#include <vector>
#include <queue>

using namespace std;

int MOD = 20170805;

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(n + 1, vector<long long>(2)));
    
    for (int y = 0; y < m; ++y)
    {
        if (city_map[y][0] == 1) break;
        dp[y][0][1] = 1;
    }
    for (int x = 0; x < n; ++x)
    {
        if (city_map[0][x] == 1) break;
        dp[0][x][0] = 1;
    }
    for (int y = 1; y < m; ++y)
    {
        for (int x = 1; x < n; ++x)
        {
            if (city_map[y - 1][x] == 0){
                dp[y][x][1] += (dp[y - 1][x][0] + dp[y - 1][x][1]) % MOD;
            }
            if (city_map[y][x - 1] == 0)
            {
                dp[y][x][0] += (dp[y][x-1][0] + dp[y][x - 1][1]) % MOD;
            }
            if (city_map[y - 1][x] == 2)
            {
                dp[y][x][1] += (dp[y - 1][x][1]) % MOD;
            }
            if (city_map[y][x - 1] == 2)
            {
                dp[y][x][0] += (dp[y][x - 1][0]) % MOD;
            }
            
        }
    }
    
    answer = (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    
    return answer;
}
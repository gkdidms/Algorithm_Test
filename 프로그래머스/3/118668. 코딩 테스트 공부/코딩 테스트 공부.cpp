#include <string>
#include <vector>
#include <algorithm>

#define INF int(1e9)

using namespace std;

int max_alp, max_cop;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = INF;
    
    vector<vector<int>> visible(151, vector<int>(151, INF));
    
    max_alp = alp;
    max_cop = cop;
    
    for (auto a : problems)
    {
        max_alp = max(max_alp, a[0]);
        max_cop = max(max_cop, a[1]);
    }
    
    problems.push_back(vector<int>{0, 0, 0, 1, 1});
    problems.push_back(vector<int>{0, 0, 1, 0, 1});
    
    visible[alp][cop] = 0;
    
    for (int i = alp; i <= max_alp; ++i)
    {
        for (int j = cop; j <= max_cop; ++j)
        {
            if (i == max_alp && j == max_cop)
                return visible[i][j];
            
            int cur_g = visible[i][j];
            for (int k = 0; k < problems.size(); ++k)
            {
                if (problems[k][0] > i || problems[k][1] > j)
                    continue;
                
                int n_al = min(i + problems[k][2], max_alp);
                int n_co = min(j + problems[k][3], max_cop);
                
                if (visible[n_al][n_co] > cur_g + problems[k][4])
                    visible[n_al][n_co] = cur_g + problems[k][4];
            }
        }
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> table(triangle.size(), vector<int>(triangle[triangle.size() - 1].size()));
    
    table[0][0] = triangle[0][0];
    
    for (int i = 1; i < triangle.size(); ++i)
    {
        for (int j = 0; j < triangle[i].size(); ++j)
        {
            if (j > 0)
            {
                if (table[i][j] < table[i - 1][j - 1])
                    table[i][j] = table[i - 1][j - 1] + triangle[i][j];
            }
            
            if (j < triangle[i].size() - 1)
            {   
                if (table[i][j] < table[i - 1][j] + triangle[i][j])
                    table[i][j] = table[i - 1][j] + triangle[i][j];
            }


            
        }
    }
    
    for (int i = 0; i < triangle[triangle.size() - 1].size(); ++i)
    {
        if (answer < table[triangle.size() - 1][i])
            answer = table[triangle.size() - 1][i];
    }
    
    return answer;
}
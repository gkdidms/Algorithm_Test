#include <string>
#include <vector>

using namespace std;

int answer= int(1e9);

void backtracking(vector<int> picks, vector<string>& minerals, int sum, int idx)
{
    if ((picks[0] == 0 && picks[1] == 0 && picks[2] == 0) ||
        idx >= minerals.size())
    {
        answer = min(answer, sum);
        return;
    }
    
    for (int i = 0; i < 3; ++i)
    {
        if (picks[i] == 0) continue;
        
        int cnt = 5;
        int temp = 0;
        int copy_idx = idx;
        while(cnt-- && minerals.size() > copy_idx)
        {
            if (i == 0)
            {
                temp += 1;        
            }
            else if (i == 1)
            {
                if (minerals[copy_idx] == "diamond") temp += 5;
                else temp += 1;
            }
            else if (i == 2)
            {
                if (minerals[copy_idx] == "diamond") temp += 25;
                else if (minerals[copy_idx] == "iron") temp += 5;
                else temp += 1;
            }
            
            copy_idx++;
        }
        
        picks[i]--;
        backtracking(picks, minerals, sum + temp, copy_idx);
        picks[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    
    backtracking(picks, minerals, 0, 0);
    return answer;
}
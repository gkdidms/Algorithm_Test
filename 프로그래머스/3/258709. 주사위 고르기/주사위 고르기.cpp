#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dice_sum(vector<int>& v, vector<int>& temp, int& sum, vector<vector<int>>& dice, int idx)
{
    if (idx >= v.size())
    {
        temp.push_back(sum);
        return;
    }
    
    for (int i = 0; i < dice[v[idx] - 1].size(); ++i)
    {
        sum += dice[v[idx] - 1][i];
        dice_sum(v, temp, sum, dice, idx + 1);
        sum -= dice[v[idx] - 1][i];
    }
    
}

void select(int idx, vector<int>& container, vector<vector<int>>& combination, int dice_size)
{
    if (container.size() >= dice_size / 2)
    {
        combination.push_back(container);
        return;
    }
    
    for (int i = idx; i < dice_size; ++i)
    {
        container.push_back(i + 1);
        select(i + 1, container, combination, dice_size);
        container.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    vector<int> a_list;
    vector<vector<int>> combination;
    select(0, a_list, combination, dice.size());
    int curr_maxRate = 0;
    
    int start = 0, end = combination.size() - 1;
    while(start < end)
    {
        int currentSum1 = 0, currentSum2 = 0;
        vector<int> temp1, temp2;
        
        dice_sum(combination[start], temp1, currentSum1, dice, 0);
        dice_sum(combination[end], temp2, currentSum2, dice, 0);
        
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        
        int winRate1 = 0, winRate2 = 0;
        for (int n : temp1)
        {
            int win = lower_bound(temp2.begin(), temp2.end(), n) - temp2.begin();
            if (win - 1 > 0) winRate1 += win;
        }
        
        for (int n : temp2)
        {
            int win = lower_bound(temp1.begin(), temp1.end(), n) - temp1.begin();
            if (win - 1 > 0) winRate2 += win;
        }
        
        if (winRate1 > winRate2)
        {
            if (winRate1 > curr_maxRate){
                curr_maxRate = winRate1;
                answer = combination[start];
            }
        }
        else if (winRate2 > winRate1)
        {
            if (winRate2 > curr_maxRate)
            {
                curr_maxRate = winRate2;
                answer = combination[end];
            }
        }
        
        temp1.clear();
        temp2.clear();
        start++;
        end--;
    }
    return answer;
}
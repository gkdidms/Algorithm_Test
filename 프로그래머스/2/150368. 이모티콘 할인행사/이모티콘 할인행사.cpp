#include <string>
#include <vector>

using namespace std;

int discount[4] = {10, 20, 30, 40};
vector<int> answer;

bool check(int dcnt, vector<int> user)
{
    if (dcnt < user[0]) return false;
    
    return true;
}

void dfs(int cnt, vector<int> dcnt, vector<vector<int>> users, vector<int> emoticons)
{
    if (cnt == emoticons.size())
    {
        int cnt = 0;
        int all_sum = 0;
        for (int i = 0; i < users.size(); ++i)
        {
            int sum = 0;
            for (int j = 0; j < emoticons.size(); ++j)
            {
                if (!check(dcnt[j], users[i]))  continue;
                
                double d = (100 - dcnt[j]) * 0.01;
                int temp = emoticons[j] * d;
                
                sum += temp;
            }
            
            if (sum >= users[i][1]) cnt++;
            else
            {
                all_sum += sum;
            }
        }
            
        if (answer[0] < cnt)
        {
            answer[0] = cnt;
            answer[1] = all_sum;
        }
        else if (answer[0] == cnt && answer[1] < all_sum)
        {
            answer[1] = all_sum;
        }
        
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        dcnt[cnt] = discount[i];
        dfs(cnt + 1, dcnt, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    answer.resize(2);
    
    vector<int> dcnt(emoticons.size());
    dfs(0, dcnt, users, emoticons);
    
    return answer;
}
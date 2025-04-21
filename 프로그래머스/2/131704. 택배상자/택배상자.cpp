#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    vector<int> assistance;
    
    int idx = 0;
    int num = 1;
    
    while(num <= order.size() + 1&& idx < order.size())
    {
        if (order[idx] == num)
        {
            idx++;
            answer++;
            num++;
        }
        else
        {
            if (assistance.size() > 0)
            {
                bool isSuccess = false;
                while(idx < order.size() && *assistance.rbegin() == order[idx])
                {
                    idx++;
                    answer++;
                    assistance.pop_back();
                    isSuccess = true;
                }
                
                if (isSuccess) continue;
            }
            assistance.push_back(num);
            num++;
        }
    }
    return answer;
}
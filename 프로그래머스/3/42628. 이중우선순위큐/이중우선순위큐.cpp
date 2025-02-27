#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    vector<int> q;
    for (auto operation : operations)
    {
        char str = operation[0];
        int num = stoi(operation.substr(2));
        if (str == 'I')
        {
            q.push_back(num);
        }
        else if (str == 'D')
        {
            if (q.empty()) continue;
            
            sort(q.begin(), q.end());
            if (num == -1)
            {

                //최솟값 삭제
                            q.erase(q.begin());
            }
            else if (num == 1)
            {
                //최대값 삭제
                            q.erase(q.begin() + (q.size() - 1));
            }

        }
    }
    
    if (q.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        sort(q.begin(), q.end());
        answer.push_back(q[q.size() - 1]);
        answer.push_back(q[0]);
    }
    
    
    return answer;
}
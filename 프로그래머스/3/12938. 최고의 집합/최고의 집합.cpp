#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (n > s) answer.push_back(-1);
    else
    {
        int q = s / n;
        for (int i = 0; i < n; ++i)
            answer.push_back(q);
        
        int m = s % n;
        for (int i = 0; i < m; ++i)
            answer[i] += 1;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
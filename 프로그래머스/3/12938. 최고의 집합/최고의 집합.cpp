#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (n > s) answer.push_back(-1);
    else
    {
        int q = s/n;
        int r = s % n;
        
        answer.resize(n, q);
        
        for (int i = 0; i < r; ++i)
            answer[i]++;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
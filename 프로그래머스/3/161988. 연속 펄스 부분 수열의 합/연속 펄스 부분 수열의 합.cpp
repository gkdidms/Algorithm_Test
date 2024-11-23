#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    vector<long long> v1(sequence.size());
    vector<long long> v2(sequence.size());
    
    v1[0] = sequence[0] * -1; // -1,1,-1,1...
    v2[0] = sequence[0]; // 1,-1,1,-1...
    for (int i = 1; i < sequence.size(); ++i)
    {
        v1[i] = sequence[i] * (i % 2 == 0 ? -1 : 1);
        v2[i] = sequence[i] * (i % 2 == 0 ? 1 : -1);
    }
     
    vector<long long> dp1(v1.size());
    vector<long long> dp2(v2.size());
    
    dp1[0] = v1[0];
    dp2[0] = v2[0];
    
    for (int i = 1; i < v1.size(); ++i)
    {
        dp1[i] = max(dp1[i - 1] + v1[i], v1[i]);
        dp2[i] = max(dp2[i - 1] + v2[i], v2[i]);
    }
    
    for (auto a : dp1)
        answer = max(answer, a);
    
    for(auto b : dp2)
        answer = max(answer, b);
    
    return answer;
}
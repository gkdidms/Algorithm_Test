#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    vector<int> table(1001 * 4);
    vector<int> weights_table(1001);
  
    for (int i = 0; i < weights.size(); ++i)
    {
        int anw1 = weights[i] * 2;
        int anw2 = weights[i] * 3;
        int anw3 = weights[i] * 4;
        
        answer += table[anw1];
        answer += table[anw2];
        answer += table[anw3];
        
        if (weights_table[weights[i]] > 0)
            answer -= weights_table[weights[i]] * 2;
        
        weights_table[weights[i]]++;
        table[anw1]++;
        table[anw2]++;
        table[anw3]++;    
    }
    
    return answer;
}
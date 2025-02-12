#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    int start = 0, end = A.size() - 1;
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    
    int idx = A.size() - 1;
    while(start <= end)
    {
        if (idx < 0)
            break;
        
        if (A[idx] < B[end])
        {
            end--;
            answer++;
        }
        else if (A[idx] < B[start])
        {
            start++;
            answer++;
        }
        
        idx--;
    }
    
    return answer;
}
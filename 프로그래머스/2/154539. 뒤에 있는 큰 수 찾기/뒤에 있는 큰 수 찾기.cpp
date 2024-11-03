#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<int> st;
    st.push(numbers[numbers.size() - 1]);
    answer[numbers.size() - 1] = -1;
    
    for (int i = numbers.size() - 2; i >= 0; i--)
    {
        bool isSuccess = false;
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            if (top > numbers[i])
            {
                answer[i] = top;
                isSuccess = true;
                break;
            }
        }
        
        if (isSuccess)
            st.push(answer[i]);
        else
            answer[i] = -1;
        
        st.push(numbers[i]);
    }
    
    return answer;
}
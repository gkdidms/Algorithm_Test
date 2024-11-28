#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int cnt = s.size();
    
    while(cnt--)
    {
        //올바른 괄호 문자열인지 아닌지 확인
        bool isSuccess = false;
        stack<string> stacklist;
        for(auto word : s)
        {
            string str(1, word);
            
            if (str == "{" || str == "(" || str == "[" || stacklist.empty())
                stacklist.push(str);
            else
            {
                if (stacklist.top() == "}" || stacklist.top() == ")" || stacklist.top() == "]")
                    break;
                
                if (str == "}") stacklist.top() == "{" ? stacklist.pop() : stacklist.push(str);
                else if (str == "]") stacklist.top() == "[" ? stacklist.pop() : stacklist.push(str);
                else if (str == ")") stacklist.top() == "(" ? stacklist.pop() : stacklist.push(str);
            }
        }
        
        if (stacklist.empty())
            answer++;
        
        //순서 바꾸기
        char first_word = s[0];
        for (int i = 1; i < s.size(); ++i)
        {
            s[i - 1] = s[i];
            
            if (i == s.size() - 1)
            {
                s[i] = first_word;
            }
        }
    }
    
    return answer;
}
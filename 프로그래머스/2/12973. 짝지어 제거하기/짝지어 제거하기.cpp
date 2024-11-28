#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> q;
    for (auto a: s)
    {
        if (q.size() > 0 && q.top() == a) q.pop();
        else q.push(a);
    }
    
    return q.size() == 0;
}
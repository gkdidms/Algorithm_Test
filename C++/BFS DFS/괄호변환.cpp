#include <string>
#include <iostream>
#include <vector>

using namespace std;

string strnum(int num, string answer)
{
    if (num == answer.size())
        return answer;

    string u = answer.substr(0, num);
    int n = 0;
    int m = 0;

    for (auto a : u)
    {
        if (a == '(') n++;
        else if (a == ')') m++;
    }

    if (n != m)
        u = strnum(num + 2, answer);

    return u;
}

string dfs(string answer)
{
    if (answer.empty()) return "";

    string u,v;

    //u,v는 균형잡힌 문자열 
    //균형잡힌 괄호 문자열은 '(', ')'의 개수가 같으면 됨.
    u = strnum(2, answer);

    if (u.size() == answer.size()) v = "";
    else v = answer.erase(0, u.size());

    //올바른 문자열일경우
    if (*(u.begin()) == '(' && *(u.end() - 1) == ')')
        return u + dfs(v);
    else
    {
        //u가 올바른 괄호 문자열이 아닐 경우
        string n = "(" + dfs(v) + ")";

        u.erase(u.begin());
        u.erase(u.size() - 1);

        string m = "";
        for (auto a : u)
        {
            m += a == '(' ? ")" : "(";
        }

        return n + m;
    }

}

string solution(string p) {
    string answer = "";

    answer = dfs(p);

    return answer;
}
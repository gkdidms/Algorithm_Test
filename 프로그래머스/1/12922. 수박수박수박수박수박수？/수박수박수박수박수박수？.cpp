#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    string str = "수박";
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; ++i)
            answer+=str;
    }
    else
    {
        for (int i = 0; i < n / 2 + 1; ++i)
        {
            if (i == n / 2)
                answer += "수";
            else
                answer += str;
        }
    }
    return answer;
}
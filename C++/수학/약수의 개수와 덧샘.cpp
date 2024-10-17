//https://school.programmers.co.kr/learn/courses/30/lessons/77884

#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; ++i)
    {
        //소인수분해
        vector<int> temp;
        int j = 2;
        int n = i;

        while(n > 1)
        {
            int m = 0;

             while(n % j == 0)
                {
                    m++;
                    n /= j;
                }
            j++;
            temp.push_back(m);
        }
        for (int j = 2; j * j <= i; j++)
        {
            int m = 0;
            int n = i;

            while(n % j == 0)
            {
                m++;
                n /= j;
            }


        }

        //약수 개수 구하기
        int src = 1;
        for (auto j : temp)
        {
            if (j != 0)
                src *= (j + 1);
        }

        if (src % 2 == 0)
            answer += i;
        else if (src % 2 == 1)
            answer -= i;
    }

    return answer;
}
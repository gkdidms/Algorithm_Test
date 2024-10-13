#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> wins;
    //매일 최하위 점수를 기록
    int icnt = 0;
    for (auto iter = score.begin(); iter < score.end(); ++iter)
    {
        //k 번째날 전
        if (answer.size() == 0)
        {
            answer.push_back(*iter);
            wins.push_back(*iter);
        }
        else
        {
            if (icnt < k)
            {
                wins.push_back(*iter);
                sort(wins.begin(), wins.end());
                answer.push_back(wins[0]);
            }
            else
            {
                if (*iter > wins[0])
                {
                    wins[0] = *iter;
                    sort(wins.begin(), wins.end());
                }
                answer.push_back(wins[0]);
            }
        }
        icnt++;
    }

    return answer;
}
*/
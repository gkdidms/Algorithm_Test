//https://www.acmicpc.net/problem/1431

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void swap(int a, int b, vector<string>& table)
{
    string temp = table[a];
    table[a] = table[b];
    table[b] = temp;
}

int main() {
    int iCnt = 0;
    cin >> iCnt;

    vector<string> table(iCnt);
    for (int i = 0; i < iCnt; ++i)
    {
        cin >> table[i];
    }

    //1. A,B의 길이가 다르면 짧은 것이 먼저온다
    //2. 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는것이 먼저 온다(숫자만)
    //3. 만약 1,2둘 조건으로 비교할 수 없으면 사전순으로 비교한다.
    //숫자가 알파벳보다 사전순으로 작다.

   for (int i = 0; i < iCnt; ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if (table[j].size() < table[j - 1].size())
            {
                swap(j, j - 1, table);
            }
            else if (table[j].size() == table[j - 1].size())
            {
                int a = 0;
                int b = 0;

                for (int k = 0; k < table[j].size(); ++k)
                {
                    if (isdigit(table[j][k]))
                        a += table[j][k] - '0';
                    if (isdigit(table[j - 1][k]))
                        b += table[j - 1][k] - '0';
                }

                if (a < b)
                {
                    swap(j, j - 1, table);
                }
                else if (a == b)
                {
                    for (int k = 0; k < table[j].size(); ++k)
                    {
                        if (table[j][k] == table[j - 1][k])
                            continue;

                        if (table[j][k] > table[j - 1][k])
                        {
                            break;
                        }
                        else if (table[j][k] < table[j - 1][k])
                        {
                            swap(j, j - 1, table);
                            break;
                        }
                    }
                }
            }
        }
    }

    for (auto answer : table)
        cout << answer << endl;
}
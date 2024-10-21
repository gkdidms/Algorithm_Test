//https://school.programmers.co.kr/learn/courses/30/lessons/42898
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> table(m + 1, vector<int>(n + 1));

    for (auto pos : puddles)
        table[pos[0]][pos[1]] = -1;

    table[1][1] = 1;
    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if ((i == 1 && j == 1) || table[i][j] == -1)
                continue;

            int sum = 0;
            sum += table[i - 1][j] != -1 ? table[i - 1][j] : 0;
            sum += table[i][j - 1] != -1 ? table[i][j - 1] : 0;

            table[i][j] = sum % 1000000007;
        }
    }
    answer = table[m][n] % 1000000007;
    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> computers, vector<bool>& visited, int n)
{
    if (visited[n] == true)
        return 0;

    visited[n] = true;

    int result = 0;
    for(int i = 0; i < computers[n].size(); ++i)
    {
        if (computers[n][i] == 1 && n != i)
            result += dfs(computers, visited, i);
    }

    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<bool> visited(n);

    for (int i = 0; i < n; ++i)
        answer += dfs(computers, visited, i);

    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/43163
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(string begin, string target, vector<string> words)
{
    queue<pair<string, int>> q;
    q.push({begin, 0});

    vector<bool> visited(words.size());

    while(!q.empty())
    {
        string word = q.front().first;
        int count = q.front().second;
        q.pop();

        if (word == target)
        {
            return count;
        }

        for (int i = 0; i < words.size(); ++i)
        {
            if (visited[i] == true)
                continue;

            int cnt = 0;
            for (int j = 0; j < words[i].size(); ++j)
            {
                if (words[i][j] != word[j])
                    cnt++;
            }

            if (cnt == 1)
            {
                q.push({words[i], ++count});
                visited[i] = true;
            }
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    auto find_word = find(words.begin(), words.end(), target);
    if (find_word == words.end())
        return answer;

    answer = bfs(begin, target, words);

    return answer;
}
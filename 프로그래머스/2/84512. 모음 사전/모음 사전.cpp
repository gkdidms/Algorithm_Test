#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> str_word = {'A', 'E', 'I', 'O', 'U'};

int answer = 0;
bool dfs(string target, string word, int count)
{
    if (count == 5)
    {
        return false;
    }
    
    
    for (auto a : str_word)
    {
        ++answer;
        if (target + a == word)
            return true;
        
        if (dfs(target + a, word, count + 1))
            return true;
    }
    
    return false;
}

int solution(string word) {
    dfs("", word, 0);
    
    return answer;
}
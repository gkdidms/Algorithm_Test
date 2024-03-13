#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
vector<int> solution(string s);

int main() {
  vector<int> answer = solution("banana");

  for (int i : answer)
    cout << i << endl;
}

vector<int> solution(string s) {
    vector<int> answer;

    answer.reserve(s.size());

    for (int i = 0; i < s.size(); i++)
      {
        bool isAdd = false;
        for (int j = i-1; j > -1; j--)
          {
            if (s[i] == s[j])
            {
              answer.push_back(i - j);
              isAdd = true;
              break;
            }
          }
        if (!isAdd)
          answer.push_back(-1);
      }
    return answer;
}*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic);

/*int main() {
  int answer = solution(vector<string>{"p", "o", "s"}, vector<string>{"sod", "eocd", "qixm", "adio", "soo"});

  cout << answer << endl;
}*/


int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;

    for (string a : dic)
      {
        for (string b : spell)
          {
            if (a.find(b) != string::npos)
              answer += 1;

            if (answer == spell.size())
              return 1;
          }
        answer = 0;
      }
    return 2;
}
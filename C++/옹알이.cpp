#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열이 전부 옹알이로 되어있는가를 체크해야한다
// 문자를 그냥 삭제할 경우 삭제된 문자의 앞, 뒤 단어가 합성되어 새로운 단어를 생성할 수 있기 때문에 삭제하는것이 아니라 '@'라는 중간 문자를 넣어준다.
/*int solution1(vector<string> babbling);

int main() {
  int answer = solution1(vector<string>{"ayaye", "uuuma", "ye", "yemawoo", "ayaa", "wyeoo"});

  cout << answer << endl;
}


int solution1(vector<string> babbling) {
    int answer = 0;

  vector<string> strBaby = {"aya", "ye", "woo", "ma"};

  for (string str : babbling)
    {
      int sum = 0;
      for (string strAnswer : strBaby)
        {
          int iIndex = str.find(strAnswer);
          if (iIndex != string::npos)
          {
            str.replace(iIndex, strAnswer.size(), "@");
              ++sum;
          }
        }

      if (str.length() == sum)
        ++answer;
    }

    return answer;
}*/
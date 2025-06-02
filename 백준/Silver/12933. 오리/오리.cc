#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;
vector<string> ducks;

bool solution(char word, char key, int num)
{
  if (word == key)
  {
    for (int i = 0; i < (int)ducks.size(); ++i)
      {
        if ((int)ducks[i].length() % 5 == num)
        {
          ducks[i].push_back(word);
          return false;
        }
      }
  }

  if (word == 'q' && key == 'q')
  {
    ducks.push_back("q");
    return false;
  }

  return true;
}

int main() {
  format;
  
  string str;
  cin >> str;

  bool isPass = false;
  for (int i = 0; i < (int)str.length(); ++i)
    {
      isPass = true;
      char word = str[i];

      if(ducks.empty())
      {
        if (word == 'q')
        {
          ducks.push_back("q");
          isPass = false;
        }
      }
      else
      {
        isPass &= solution(word,'q', 0);
        isPass &= solution(word,'u', 1);
        isPass &= solution(word,'a', 2);
        isPass &= solution(word,'c', 3);
        isPass &= solution(word,'k', 4);
      }

      if (isPass) break;
    }

  for (int i = 0; i < (int)ducks.size(); ++i)
    {
      if((int)ducks[i].length() % 5 != 0)
      {
        cout << -1;
        return 0;
      }
    }

  if (isPass) cout << -1;
  else cout << (int)ducks.size();

}

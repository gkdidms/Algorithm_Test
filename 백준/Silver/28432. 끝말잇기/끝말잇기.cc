#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

  int n, m;
vector<string> word;
bool isCheck(string str){
  for (int i = 0; i < n; ++i){
    if (str == word[i])
      return false;
  }
  return true;
}

int main() {
  format;

  cin >> n;

  int idx = 0;
  word.resize(n);
  for(int i = 0; i <n; ++i){
    cin >> word[i];
    if(word[i] == "?")
      idx = i;
  }

  cin >> m;
  for (int i = 0; i < m; ++i){
    string str;
    cin >> str;

    if (!isCheck(str)) continue;

    if( n == 1)
    {
      cout << str;
      break;
    }

    
    if (idx == word.size() - 1){
      string start = word[idx - 1];
      if (start[start.size() - 1] == str[0]){
      cout << str;
      break;
       }
    }
      else if (idx == 0){
        string end = word[idx + 1];
        if (end[0] == str[str.size() - 1]){
          cout << str;
          break;
         }
      }
    else{
        string start = word[idx - 1];
        string end = word[idx + 1];
        if (start[start.size() - 1] == str[0] &&
            end[0] == str[str.size() - 1]){
                cout << str;
              break;
         }
      }
  }

  return 0;
}


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  string str;
  cin >> str;

  int cnt = 0, num = 1;
  while(cnt != (int)str.size()){
    string s = to_string(num);

    for (int i = 0; i < (int)s.size(); ++i){
      if (str[cnt] == s[i]){
        cnt++;
        if (cnt >= (int)str.size()){
          cout << num;
          break;
        }
      }
    }
    num++;
  }

}

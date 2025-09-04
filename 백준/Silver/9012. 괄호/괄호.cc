#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int t;
  cin >> t;

  while(t--){
    stack<char> sk;
    
    string str;
    cin >> str;

    for (int i = 0; i < (int)str.size(); ++i){
      char cur = str[i];

      if (sk.size() == 0) sk.push(cur);
      else{
        if (sk.top() == '('){
          if (cur == '(') sk.push(cur);
          else sk.pop();
        }
        else {
          //)
          sk.push(cur);
        }
      }
    }
    if (!sk.empty()) cout << "NO" << '\n';
    else cout << "YES" << '\n';
  }
}

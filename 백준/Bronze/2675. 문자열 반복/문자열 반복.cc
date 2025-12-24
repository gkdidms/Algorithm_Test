#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int t;
  cin >> t;

  while(t--){
    int n;
    string str;

    cin >> n >> str;

    string answer = "";
    for(int i = 0; i < (int)str.size(); ++i){
      for(int j = 0; j < n; ++j){
        answer += str[i];
      }
    }

    cout << answer << '\n';
  }

}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  cin >> n;

  int answer = 0;
  for (int i = 1; i <= n; ++i){
    string temp = to_string(i);

    int def = 0;
    for (int j = 0; j < (int)temp.size() - 1; ++j){
      if (j == 0) def = temp[j] - temp[j + 1];
      else{
        int num = temp[j] - temp[j + 1];
        if (num != def){
          def = int(1e9);
          break;
        }
      }
    }
    if (def != int(1e9)) answer++;
  }
  cout << answer;

  return 0;
}


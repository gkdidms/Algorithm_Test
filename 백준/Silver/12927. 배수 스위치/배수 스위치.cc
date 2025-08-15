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

  int size = str.size();
  string answer = "";
  int cnt = 0;
  for (int i = 0; i < size; ++i)
    answer += 'N';

  for(int i = 1; i <= size; ++i){
    if (str[i - 1] == 'Y'){
      cnt += 1;
      for (int k = i; k <= size; k+=i){
        if(str[k - 1] == 'Y') str[k - 1] = 'N';
        else str[k - 1] = 'Y';
      }
    }
    if (str == answer){
      cout << cnt;
      return 0;
    }
  }

  cout << -1;
}

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
  int cnt = 1;
  while(n >= cnt){
    answer++;
    if (to_string(answer).find("666") != string::npos){
      cnt++;
    }
  }

  cout << answer;

  return 0;
}


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
  while(n > 1){
    answer += n / 5;
    n /= 5;
  }
  
  cout << answer;
}


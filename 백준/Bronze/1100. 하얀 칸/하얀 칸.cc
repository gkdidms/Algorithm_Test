#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int answer = 0;
  for(int i = 1; i <= 8; ++i){
    for(int j = 1; j <= 8; ++j){
      char temp;
      cin >> temp;
      
      if (i % 2 == 0 && j % 2 == 0){
        //짝, 짝
        if (temp == 'F') answer++;
      }
      else if (i % 2 == 1 && j % 2 == 1) {
        if (temp == 'F') answer++;
      }
    }
  }

  cout << answer;

}

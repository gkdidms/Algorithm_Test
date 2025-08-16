#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m, j;
  cin >> n >> m >> j;

  vector<int> table(j);
  for(int i = 0; i < j; ++i){
    cin >> table[i];
  }

  int start = 1;
  int answer = 0;

  for (int i = 0; i < j; ++i){
    int end = start + m - 1;

    if (table[i] >= start && table[i] <= end) continue;

    if (table[i] < start){
      answer += start - table[i];
      start = table[i];
    }
    else {
      start += table[i] - end;
      answer += table[i] - end;
    }
  }

  cout << answer;
  
  
}

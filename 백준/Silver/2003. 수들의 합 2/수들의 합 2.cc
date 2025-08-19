#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m;
  cin >> n >> m;

  vector<int> table(n + 1);

  for (int i = 1; i <= n; ++i)
    {
      int temp;
      cin >> temp;

      table[i] = table[i - 1]+ temp;
    }

  int start = 0, end = 1; 
  int answer = 0;
  while(start <= end){
    if (start > n || end > n) break;
    int cur = table[end] - table[start];
    if (cur == m) answer++;
    
    if (cur <= m)
      end++;
    else start++;
  }

  cout << answer;
}

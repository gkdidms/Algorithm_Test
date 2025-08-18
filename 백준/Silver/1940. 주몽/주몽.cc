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

  vector<int> table(n);
  for (int i = 0; i < n; ++i)
    cin >> table[i];

  sort(table.begin(), table.end());

  int answer = 0;

  int start = 0, end = n - 1;

  while(start < end){
    int sum = table[start] + table[end];

    if (sum > m)
      end--;
    else if (sum < m)
      start++;
    else if (sum == m){
      answer++;
      start++;
      end--;
    }
      
  }
  cout << answer;
}

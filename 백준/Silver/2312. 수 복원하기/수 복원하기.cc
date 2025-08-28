#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

void answer(int n){
  int cnt = 0;

  map<int, int> table;


  for (int i = 2; i * i <= n; ++i){
    while(n % i == 0){
      table[i]++;
      n /= i;
    }
  }

  if (n > 1)
    table[n]++;
  
  for (auto iter = table.begin(); iter != table.end(); ++iter){
    cout << iter->first << " " << iter->second << '\n';
  }
}

int main() {
  format;

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    answer(n);
    
  }

  

  return 0;
}


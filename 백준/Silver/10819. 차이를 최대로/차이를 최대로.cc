#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int n;
int answer = 0;
vector<int> table;

int main() {
  format;


  cin >> n;

  table.resize(n);

  for(int i = 0; i < n; ++i){
    cin >> table[i];
  }

  sort(table.begin(), table.end());

  while(next_permutation(table.begin(), table.end())){
    int sum = 0;
      for (int i = 0; i < n - 1; i++){
    sum += abs(table[i] - table[i + 1]);
  }
    answer = max(answer, sum);
  }


  cout << answer;

}

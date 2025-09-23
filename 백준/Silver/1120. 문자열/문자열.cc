#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;


int main() {
  format;

  string a,b;
  cin >> a>> b;

  int answer = int(1e9);

  int aa = a.size();
  int bb = b.size();
  int def = bb - aa;

  for (int i = 0; i <= def; ++i){
    int cnt = 0;
    for (int j = 0; j < aa; ++j){
      if (a[j] != b[j + i]) cnt++;
    }
    answer = min(answer, cnt);
  }
  

  cout << answer;

  return 0;
}


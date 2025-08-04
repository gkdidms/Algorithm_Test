#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  char str;
  cin >> n >> str;

  set<string> names;
  int cnt = 0;
  int answer = 0;
  for(int i = 0; i < n; ++i){
    string name;
    cin >> name;
    
    if (names.find(name) != names.end()) continue;
      
    names.insert(name);
    cnt++;
  }

  if (str == 'Y') answer = cnt;
  else if (str == 'F') answer = cnt / 2;
  else if (str == 'O') answer = cnt/ 3;

  cout << answer << '\n';
}

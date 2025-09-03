#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int t;
  cin >> t;

  while(t--){
    string s, q;
    cin >> s>> q;

    int cnt = 0;
    size_t pos = 0;
    while((pos = s.find(q, pos)) != string::npos){
      cnt++;
      pos += q.size();
    }
    int answer = s.size() - (q.size() * cnt) + (1 * cnt);
    cout << answer << '\n';
  }

}

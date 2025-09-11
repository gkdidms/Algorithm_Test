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
  cin >> n;

  set<string> check;
  for (int i = 0; i < n; ++i){
    string str;
    cin >> str;
    if (str.size() < 6) continue;

    string cut = str.substr(str.size() - 6, 6);
    if (cut == "Cheese"){
      if (check.find(str) == check.end()){
        check.insert(str);
      }
    }
  }

  if (check.size() >= 4) cout << "yummy";
  else cout << "sad";
  

  return 0;
}


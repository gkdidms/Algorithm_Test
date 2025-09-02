#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  cin >> n;

  map<string, int> table;
  for (int i = 0; i < n; ++i){
    string str;
    cin >> str;

    int idx = str.find('.');
    string extension = str.substr(idx + 1);

    table[extension]++;
  }

  for (auto a : table){
    cout << a.first << " " << a.second << '\n';
  }

}

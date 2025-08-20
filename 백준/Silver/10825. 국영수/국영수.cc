#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

struct node{
  string name;
  int a, b, c;
};

int main() {
  format;

  int n;
  cin >> n;

  vector<node> table(n);
  for (int i = 0; i < n; ++i){
    string a;
    int b, c, d;

    cin >> a >> b>> c>> d;

    table[i] = {a, b, c, d};
  }

  sort(table.begin(), table.end(), [](const node& a, const node& b){
    if (a.a == b.a){
      if (a.b == b.b){
        if (a.c == b.c){
          return a.name < b.name;
        }
        return a.c > b.c;
      }
      return a.b < b.b;
    }
    return a.a > b.a;
  });

  for (auto a : table){
    cout << a.name << '\n';
  }
}

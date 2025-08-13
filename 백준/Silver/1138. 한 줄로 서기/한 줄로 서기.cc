#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;


int main() {
  format;

  int n;
  cin >> n;

  vector<int> p(n);
  for (int i = 1; i <=n; ++i){
    int temp = 0;
    cin >> temp;

    for (int j = 0; j < n; ++j){
      if (temp == 0 && p[j] == 0){
        p[j] = i;
        break;
      }
      if (p[j] ==0) temp--;
    }
  }
  
  for (int i = 0; i < n; ++i)
    cout << p[i] << " ";
  
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int arr[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main() {
  format;

  string a, b;
  cin >> a >> b;

  vector<int> check1;
  vector<int> check2;
  for (int i = 0; i < int(a.size()); ++i){
    check1.push_back(arr[a[i] - 65]);
    check1.push_back(arr[b[i] - 65]);
  }

  while(check1.size() > 2){
    for (int i = 0; i < int(check1.size()) - 1; ++i){
      int temp = check1[i] + check1[i+1];
      check2.push_back(temp % 10);
    }

    check1.clear();
    check1 = check2;
    check2.clear();
  }

  cout << check1[0] << check1[1];
  
  return 0;
}


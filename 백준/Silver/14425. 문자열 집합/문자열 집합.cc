#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, m;

  cin >> n >> m;

  set<string> arr;
  for (int i = 0; i < n; ++i){
    string str;
    cin >> str;

    arr.insert(str);
  }

  int answer = 0;
  for (int i = 0; i < m; ++i){
    string temp;
    cin >> temp;

    if (arr.find(temp) != arr.end()){
      answer++;
    }
  }
    
cout << answer;
  

  return 0;
}


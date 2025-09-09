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

  map<string, int> arr;
  for(int i = 0; i  < n; ++i)
    {
      string str;
      cin >> str;
      arr[str]++;
    }

  for (int i = 0; i < n -1; ++i)
    {
      string str;
      cin >>str;
      arr[str]++;
    }

  for (auto m = arr.begin(); m != arr.end(); ++m){
    if (m->second % 2 == 1){
      cout << m->first;
      break;
    }
  }
  
  

  return 0;
}


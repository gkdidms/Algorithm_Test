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

  vector<int> arr;
  arr.push_back(-1);
  for (int i = 0; i < n; ++i)
    {
      int x;
      cin >> x;

      if (arr.back() <x)
        arr.push_back(x);
      else
      {
        int start = 0, end = arr.size();

        while(start < end)
          {
            int mid = (start + end ) / 2;

            if (arr[mid] < x)
              start = mid + 1;
            else end = mid;
          }

        arr[end] = x;
      }
    }

  cout << n - arr.size() + 1;

  

  return 0;
}


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n, k;
  cin >> n >> k;

  vector<int> lv(n);
  for (int i = 0; i < n; ++i)
    cin >> lv[i];

  sort(lv.begin(), lv.end());

  int left = 1, right = 1'000'000'001;
  int answer = 0;
  while(left <= right)
    {
      int mid = (left + right) / 2;

      long long sum = 0;
       for (int i = 0; i < n; ++i)
         {
           if (lv[i] < mid)
             sum += mid - lv[i];
         }

      if (k < sum)
        right = mid - 1;
      else
      {
        answer = mid;
        left = mid + 1;
      }
    }

  cout << answer;
}


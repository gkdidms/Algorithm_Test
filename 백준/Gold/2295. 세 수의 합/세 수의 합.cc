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

  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >>  v[i];

  vector<int> sum;
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j)
      sum.push_back(v[i] + v[j]);
  
  sort(v.begin(), v.end());
  sort(sum.begin(), sum.end());

  int answer = 0;
  for (int i = n-1; i >= 0; --i)
    {
      for (int j = i; j >=0; --j)
        {
          int temp = v[i] - v[j];
          int left = 0, right = sum.size() - 1;
          
          if(binary_search(sum.begin(), sum.end(), temp))
          {
            cout << v[i];
            return 0;
          }
          
        }
    }

}


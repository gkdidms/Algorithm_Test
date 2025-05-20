#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

//1. 연결선이 서로 꼬이지 않게 연결해야 한다. (겹치지 않게, 교차하지 않게)
//2. 연결선이 짧은 애들이 좋음.

int n;
vector<int> answer;

int get_idx(int k)
{
  int left = 0, right = answer.size() -1;

  while(left < right)
    {
      int mid = (left + right) / 2;

      if (answer[mid] >= k)
        right = mid;
      else left = mid + 1;
    }

  return right;
}

int main() {
  format;

  cin >> n;

  vector<int> v(n );
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  
  answer.push_back(v[0]);

  for (int i = 1; i < n; ++i)
    {
      if (v[i] > answer.back())
        answer.push_back(v[i]);
      else
      {
        int idx = get_idx(v[i]);
        answer[idx] = v[i];
      }
    }

  int size = answer.size();
  cout << size;
}


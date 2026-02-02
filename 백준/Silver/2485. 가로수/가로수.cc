#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int euclidean(int a, int b) {
    int temp = a % b;
  if(temp == 0) return b;
  else return euclidean(b, temp);
}

int main() {
  format;

  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < n; ++i)
    cin >> arr[i];

  vector<int> dist;
  for(int i = 0; i < n-1; ++i){
    dist.push_back(arr[i+1] - arr[i]);
  }

  int gcd = dist[0];
  for(int i = 1; i < n-1; ++i){
    gcd = euclidean(gcd, dist[i]);
  }

  int answer=0;
  for(int i =0;i <n-1; ++i){
    //양끝에 이미 하나씩 심어져 있음으로 -1
    answer += (dist[i] / gcd) - 1;
  }
  

  cout << answer;
}

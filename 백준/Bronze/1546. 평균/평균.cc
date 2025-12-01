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

  vector<double> arr(n);
  double maxNum = 0;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
    maxNum = max(maxNum, arr[i]);
  }

  double answer = 0;
  for (int i = 0; i < n; ++i){
    answer += arr[i]/maxNum*100;
  }

  
  cout << (double)(answer / n);

  
  

  return 0;
}


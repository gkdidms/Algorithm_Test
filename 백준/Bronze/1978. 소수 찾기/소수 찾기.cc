#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

bool check(int num){
  if (num <= 1) return false;

  for (int i = 2; i <= sqrt(num); ++i){
    if (num % i == 0) return false;
  }

  return true;
}

int main() {
  format;

  int n;
  cin >> n;

  int answer = 0;
  for (int i = 0; i < n; ++i){
    int temp;
    cin >> temp;

    if (check(temp) == true)
      answer++;
  }

  cout << answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

bool isPrime(int n){
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); ++i){
    if (n % i == 0) return false; 
  }

  return true;
}

bool isPalindrome(string str){
  int size = str.size();
  for (int i = 0; i <= size / 2; ++i){
    if (str[i] != str[size - i - 1]) return false;
  }

  return true;
}

int main() {
  format;

  int n;
  cin >> n;

  int num = n;
  while(true){
    if (isPrime(num) && isPalindrome(to_string(num))){
      break;
    }

    num++;
  }

  cout << num;
}

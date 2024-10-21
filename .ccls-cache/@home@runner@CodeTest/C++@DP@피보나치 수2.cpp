//https://www.acmicpc.net/problem/2748
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int n = 0;
  cin >> n;

  vector<long long> table(n);
  table[0] = 1;
  table[1] = 1;

  for (int i = 2; i < n; ++i)
  {
    table[i] = table[i - 1] + table[i - 2];
  }


  cout << table[n - 1] << endl;
}
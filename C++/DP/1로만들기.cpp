//https://www.acmicpc.net/problem/1463
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int n = 0;
  cin >> n;

  if (n == 1)
  {
    cout << 0 << endl;
    return 0;
  }

  if (n == 2 || n == 3)
  {
    cout << 1 << endl;
    return 0;
  }

  vector<int> table(n + 1);
  table[1] = 1;
  table[2] = 1;
  table[3] = 1;

  for (int i = 4; i < n + 1; ++i)
  {
    table[i] = 1 + table[i - 1];
    if (i % 3 == 0) table[i] = min(table[i], 1 + table[i / 3]);
    if (i % 2 == 0) table[i] = min(table[i], 1 + table[i / 2]);
  }

  cout << table[n] << endl;
}
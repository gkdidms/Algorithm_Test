//https://www.acmicpc.net/problem/11726
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int n = 0;
  cin >> n;

  vector<int> table(n);

  if (n == 1)
  {
    cout << 1 << endl;
  }
  else if (n == 2)
  {
    cout << 2 << endl;
  }
  else
  {
    table[0] = 1;
    table[1] = 2;
    for (int i = 2; i < n; ++i)
    {
      table[i] = (table[i - 2] + table[i - 1]) % 10007;
    }

    cout << table[n - 1]<< endl;
  }
}
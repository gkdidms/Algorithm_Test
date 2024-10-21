//https://www.acmicpc.net/problem/9095
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int n = 0;
  cin >> n;

  for (int _ = 0; _ < n; ++_)
  {
    int m = 0;

    cin >> m;

    if (m == 1)
      cout << 1 << endl;
    else if (m == 2)
      cout << 2 << endl;
    else if (m == 3)
      cout << 4 << endl;
    else
    {
      vector<int> table(m + 1);
      table[1] = 1;
      table[2] = 2;
      table[3] = 4;
      for (int j = 4; j < m + 1; ++j)
      {
        table[j] = table[j - 3] + table[j - 2] + table[j - 1];
      }

      cout << table[m] << endl;
    }

  }
}
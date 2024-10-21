//https://www.acmicpc.net/problem/15486
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int n = 0;
  cin >> n;

  vector<pair<int, int>> tp;
  vector<int> table;
  for (int i = 0; i < n; ++i)
  {
    int t = 0, p = 0;
    cin >> t >> p;

    tp.push_back({ t, p });
    table.push_back(p);
  }

  table.push_back(0);
  for (int i = n - 1; i > -1; --i)
  {
    if (tp[i].first + i > n)
      table[i] = table[i + 1];
    else
    {
      //넘지 않는다면
      table[i] = max(table[i + 1], table[i + tp[i].first] + tp[i].second);
    }
  }

  cout << table[0] << endl;
}
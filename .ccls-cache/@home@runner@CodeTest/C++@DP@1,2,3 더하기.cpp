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

  vector<int> score(n + 1);
  vector<int> table(n + 1);

  for (int _ = 0; _ < n; ++_)
  {
    cin >> score[_ + 1];
  }

  // 한 번에 한계단, 두계단 씩 오를 수 있다.
  // 연속된 세 개의 계단을 모두 밟아선 안된다.
  // 마지막 도착 계단은 반드시 밟아야 한다.
  table[1] = score[1];
  table[2] = score[1] + score[2];
  table[3] = max(score[1] + score[3], score[2] + score[3]);
  for (int i = 4; i < n + 1; ++i)
  {
    table[i] = max(table[i - 3] + score[i - 1] + score[i], table[i - 2] + score[i]);
  }

  cout << table[n] << endl;
}
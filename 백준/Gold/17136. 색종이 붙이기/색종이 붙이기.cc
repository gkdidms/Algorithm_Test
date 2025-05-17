#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int answer = 100;

bool check(int x, int y, int size, vector<vector<int>>& paper)
{
  if (x + size > 10 || y + size > 10) return false;
  for (int i = x; i < x + size; ++i)
    {
      for (int j = y; j < y + size; ++j)
        if (paper[i][j] == 0) return false;
    }

  return true;
}

void fill(int x, int y, int size, vector<vector<int>>& paper)
{
    for (int i = x; i < x + size && i < 10; ++i)
    {
      for (int j = y; j < y + size && j < 10; ++j)
        {
          paper[i][j] = 0;
        }
    }
}

bool fill_check(vector<vector<int>>& paper)
{
  for (int i = 0; i < 10; ++i)
    {
      for (int j = 0; j < 10; ++j)
        if (paper[i][j] == 1) return false;
    }

  return true;
}

void backtracking(int cnt, vector<int>& visible, vector<vector<int>> paper)
{
  if (answer < cnt) return;
  if (fill_check(paper))
  {
    answer = min(answer, cnt);
    return;
  }

  int c = 0;
  for (int i = 0; i < 10; ++i)
    {
      for (int j = 0; j < 10; ++j)
        {
          if (paper[i][j] == 0) continue;
          for (int k = 5; k >= 1; --k)
            {
              vector<vector<int>> copy(paper);
              if (visible[k] > 0 && check(i, j, k, copy))
              {
                visible[k]--;
                fill(i, j, k, copy);

                backtracking(cnt + 1, visible, copy);
                visible[k]++;
              }
            }

          return;
        }
    }
}

int main() {
  format;

  vector<vector<int>> paper(10, vector<int>(10));
  vector<int> visible(6, 5);
  
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      cin >> paper[i][j];

  backtracking(0, visible, paper);

  cout << (answer == 100 ? -1 : answer);

  return 0;
}


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, vector<int> Input);
int fibonacci(int* i, int* j, int n);

int main() {
  int iCnt = 0;
  cin >> iCnt;

  vector<int> Input;
  for (int i = 0; i < iCnt; ++i)
    {
      int iInput = 0;
      cin >> iInput;
      Input.push_back(iInput);
    }
  
  solution(iCnt, Input);
}

void solution(int n, vector<int> Input) {
  int i = 0; // 0
  int j = 0; // 1

  for (int cnt = 0; cnt < n; ++cnt)
    {
      fibonacci(&i, &j, Input[cnt]);

      printf("%d %d", i, j);
    }
}

int fibonacci(int* i, int* j, int n) {
  int iResult = 0;
    if (n == 0) {
        printf("0");
      iResult= 0;
    } else if (n == 1) {
        printf("1");
      iResult = 1;
    } else {
      iResult = fibonacci(i, j, n - 1) + fibonacci(i, j, n - 2);
    }

  if (iResult == 0) (*i)++;
  else if (iResult == 1) (*j)++;

  return iResult;
}
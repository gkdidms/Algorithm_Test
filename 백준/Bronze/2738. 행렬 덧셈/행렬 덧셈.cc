#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;
  int n, m;
void setArr(vector<vector<int>>& oOutArr){
    for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> oOutArr[i][j];
    }
  }
}

int main() {
  format;


  cin >> n >> m;

  vector<vector<int>> arr_a(n, vector<int>(m));
  vector<vector<int>> arr_b(n, vector<int>(m));

  setArr(arr_a);
  setArr(arr_b);

  vector<vector<int>> sum(n, vector<int>(m));
  for(int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cout << arr_a[i][j] + arr_b[i][j] << " ";
    }
    cout << '\n';
  }


  return 0;
}


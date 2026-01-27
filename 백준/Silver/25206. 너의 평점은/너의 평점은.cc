#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

map<string, double> grade;
int main() {
  format;
  //grade.emplace({"A+", 4.5});
  grade["A+"] = 4.5;
  grade["A0"] = 4.0;
  grade["B+"] = 3.5;
  grade["B0"] = 3.0;
  grade["C+"] = 2.5;
  grade["C0"] = 2.0;
  grade["D+"] = 1.5;
  grade["D0"] = 1.0;
  grade["F"] = 0.0;

  int t = 20;
  double all = 0;
  double sum = 0;
  while(t--){
    string str;
    double n;
    string m;
    cin >> str >> n >> m;

    if (m == "P") continue;

    all += n;
    sum += n * grade[m];
  }

  cout << sum / all;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)
#define ll long long
using namespace std;

int n;
string answer = ""; 
bool isFinished = false;
void backtracking(string sWord){
  int size = sWord.size();
  if(isFinished == true)
    return;
  
  for (int i = 1; i <= size / 2; i++) {
		if (sWord.substr(size - i, i) == sWord.substr(size - 2 * i, i)) return;
	}
  
  if(size >= n){
    if(answer == "")
      answer = sWord;
    isFinished = true;
    return;
  }

  backtracking(sWord + "1");
  backtracking(sWord + "2");
  backtracking(sWord + "3");
}

int main() {
  format;

  cin >> n;

  string str = "";
  backtracking(str);

  cout << answer;
}

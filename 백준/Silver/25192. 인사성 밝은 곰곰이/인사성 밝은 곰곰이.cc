#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int n;
  cin >> n;

  set<string> chat;
  int answer = 0;
  while(n--){
    string str;
    cin >> str;

    if(str == "ENTER"){
      chat.clear();
    }
    else{
      if(chat.find(str) == chat.end()){
        answer++;
        chat.emplace(str);
      }
    }
  }
  cout << answer;
}

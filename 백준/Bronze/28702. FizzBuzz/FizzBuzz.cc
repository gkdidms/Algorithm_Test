#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cctype>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

bool isNextNumber(int iPrevNum, int iCurNum){
  return iPrevNum + 1 == iCurNum;
}

int main() {
  format;

  vector<string> arr(3);
  for (int i = 0; i < 3; ++i){
    cin >> arr[i];
  }

  int iIndex = 0;
  int answer = 1;
  int iPrevAnswer = 0;
  while(true){
    if(iIndex == 3) break;

    bool isDigit = true;
    for (int i = 0; i < (int)arr[iIndex].size(); ++i){
      if (std::isdigit(arr[iIndex][i]) == false){
        isDigit = false;
        break;
      }
    }
    
    if (isDigit == true){
      answer = std::stoi(arr[iIndex]);
      iPrevAnswer = answer - 1;
    }
    
    if (arr[iIndex] == "FizzBuzz"){
      if (answer % 3 == 0 && answer % 5 == 0){
        if(isNextNumber(iPrevAnswer, answer)){
          iIndex++;
        }
        else{
          answer--;
          iIndex--;
          break;
        }
      }
    }
    else if (arr[iIndex] == "Fizz"){
      if (answer % 3 == 0 && answer % 5 != 0){
        if(isNextNumber(iPrevAnswer, answer)){
          iIndex++;
        }
        else{
          answer--;
          iIndex--;
          break;
        }
      }
    }
    else if (arr[iIndex] == "Buzz"){
      if (answer % 3 != 0 && answer % 5 == 0){
        if(isNextNumber(iPrevAnswer, answer)){
          iIndex++;
        }
        else{
          answer--;
          iIndex--;
          break;
        }
      }
    }
    else{
      iIndex++;
    }

    iPrevAnswer = answer;
    answer++;
  }

  if (answer % 3 == 0 && answer % 5 == 0)
    cout << "FizzBuzz";
  else if (answer % 3 == 0 && answer % 5 != 0)
    cout << "Fizz";
  else if (answer % 3 != 0 && answer % 5 == 0)
    cout << "Buzz";
  else 
    cout << answer;
}

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget);

/*int main() {

  int iAnswer = solution(vector<int>{1,3,2,5,4}, 9);

  std::cout << iAnswer << std::endl;
}*/



int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(), d.end());

    for (int i : d)
      {
        if (sum + i > budget)
          break;

        sum += i;
        answer += 1; 
      }

    return answer;
}
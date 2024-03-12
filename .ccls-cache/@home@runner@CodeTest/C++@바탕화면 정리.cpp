#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper);

/*int main() {
  vector<int> answer = solution(vector<string>{".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...."});

  for (int i : answer)
    cout << i ;
}*/

vector<int> solution(vector<string> wallpaper) {

  // 시작 좌표
    int iux=wallpaper.size();
    int iuy=wallpaper[0].size();
  // 끝 좌표
    int rdx=0;
    int rdy=0; 

    for (int i =0; i < wallpaper.size(); i++)
      {
        for (int j = 0; j < wallpaper[i].size(); j++)
          {
            if (wallpaper[i][j] == '#')
            {
              //if (iux > i) iux = i;
              //if (iuy > j) iuy = j;
              //if (rdx < i+1) rdx = i+1;
              //if (rdy < j+1) rdy = j+1;
              iux = min(iux, i);
              iuy = min(iuy, j);
              rdx = max(rdx, i+1);
              rdy = max(rdy, j+1);
            }
          }
      }

    vector<int> answer = {iux, iuy, rdx, rdy};

    return answer;
}
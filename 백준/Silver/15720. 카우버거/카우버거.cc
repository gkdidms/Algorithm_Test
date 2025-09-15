#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  int b, c, d;
  cin >> b>> c>> d;

  vector<int> bb(b);
  vector<int> cc(c);
  vector<int> dd(d);

  int all = 0;
  int max_idx = max(b, max(c, d));
  for (int i = 0; i < b; ++i)
    {
    cin >> bb[i];
      all += bb[i];
    }

  for (int i = 0; i < c; ++i){
    cin >> cc[i];
    all += cc[i];
  }
    
  for (int i = 0; i < d; ++i){
    cin >> dd[i];
    all += dd[i];
  }

  
  sort(bb.begin(), bb.end(), greater<>());
  sort(cc.begin(), cc.end(), greater<>());
  sort(dd.begin(), dd.end(), greater<>());


  int answer = 0;
  for (int i = 0; i < max_idx; ++i){
    int place = 0;
    int cnt = 0;
    if (i < b){
      place += bb[i];
      cnt++;
    }
    if (i < c){
      place += cc[i];
      cnt++;
    }
    if (i < d){
      place += dd[i];
      cnt++;
    }

    if (cnt == 3)
      answer += place * 0.9;
    else answer += place;
  }

  cout << all << '\n' << answer;

  return 0;
}


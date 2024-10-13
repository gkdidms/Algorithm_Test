#include <iostream>
#include <cstring>

using namespace std;

/*
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int iCnt = 0;
  cin >> iCnt;

  int Bit = 0;

  for (int i = 0; i < iCnt; ++i)
    {
      string strCul = "";
      int iInput = 0;
      
      cin >> strCul;

      if (strCul == "add")
      {
        cin >> iInput;
        Bit |= (1 << iInput);
      }
      else if (strCul == "remove") 
      {
        cin >> iInput;
        Bit &= ~(1 << iInput);
      }
      else if (strCul == "check")
      {
        cin >> iInput;
        if (Bit & (1 << iInput))
          cout << 1 << '\n';
        else cout << 0 << '\n';
      }
      else if (strCul == "toggle")
      {
        cin >> iInput;
        Bit ^= (1 << iInput);
      }
      else if (strCul == "all") Bit = (1 << 21) - 1;
      else if (strCul == "empty") Bit = 0;
      
    }

}
*/
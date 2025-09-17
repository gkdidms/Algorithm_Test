#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}


int main() {
  format;

  string s, t;
  string a, b;

  cin >> s >> t;

  int min_int = s.length() * t.length() / gcd(s.length(),t.length());

  for (int i = 0; i < min_int / s.length(); ++i){
    a += s;
  }
  for (int i = 0; i < min_int/ t.length(); ++i){
    b += t;
  }
  if (a == b) cout << "1";
  else cout << "0";
}


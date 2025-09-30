#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define format std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr)

using namespace std;

int main() {
  format;

  unsigned long long n;
  cin >> n;

    unsigned long long start = 0, end = (1ULL << 32); // sqrt(2^63) < 2^32
    unsigned long long answer = 0;

    while (start <= end) {
        unsigned long long mid = start + (end - start) / 2;
        __int128 sq = (__int128)mid * mid;

        if (sq >= n) {
            answer = mid;
            if (mid == 0) break;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

  cout << answer;

  return 0;
}


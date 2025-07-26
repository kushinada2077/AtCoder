#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, Y;
  std::cin >> N >> Y;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N - i; ++j) {
      int k = N - i - j;
      if (k < 0) continue;
      if (10000 * i + 5000 * j + 1000 * k == Y) {
        std::cout << i << " " << j << " " << k << "\n";
        return 0;
      }
    }
  }

  std::cout << "-1 -1 -1\n";
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  std::cin >> h >> w;
  std::vector d(10, std::vector<int>(10));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cin >> d[i][j];
    }
  }

  for (int k = 0; k < 10; ++k) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int x;
      std::cin >> x;
      if (abs(x) != 1) {
        ans += d[x][1];
      }
    }
  }

  std::cout << ans << "\n";
}
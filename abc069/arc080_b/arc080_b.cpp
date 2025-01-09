#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w, n;
  std::cin >> h >> w >> n;
  std::vector<int> a(n);
  std::vector b(h, std::vector<int>(w, 0));
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int c = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      b[i][j] = c + 1;
      a[c]--;
      if (a[c] == 0) c++;
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int k = j;
      if (i % 2) k = w - j - 1;
      std::cout << b[i][k] << " ";
    }
    std::cout << "\n";
  }
}
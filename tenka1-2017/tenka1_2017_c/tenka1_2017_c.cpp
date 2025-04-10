#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N;
  std::cin >> N;
  auto ok = [&](i64 N, i64 n, i64 h) {
    if (4 * h * n - N * h - N * n == 0) {
      return false;
    }
    auto res = (N * h * n) % (4 * h * n - N * h - N * n) == 0;
    return (N * h * n) / (4 * h * n - N * h - N * n) > 0 && res;
  };
  for (i64 i = 1; i <= 3500; ++i) {
    for (i64 j = 1; j <= 3500; ++j) {
      if (ok(N, i, j)) {
        std::cout << i << " " << j << " " << (N * i * j) / (4 * i * j - N * i - N * j) << "\n";
        return 0;
      }
    }
  }
}
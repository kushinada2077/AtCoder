#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> ans(n);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int d = abs(j - i);
      d = std::min(d, std::min(abs(x - i) + abs(y - j) + 1, abs(y - i) + abs(x - j) + 1));
      ans[d]++;
    }
  }

  for (int i = 1; i < n; ++i) {
    std::cout << ans[i] << "\n";
  }
}
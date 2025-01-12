#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  int g = 0, max = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    max = std::max(max, x);
    g = std::gcd(g, x);
  }

  bool ans = k % g;
  if (max < k) ans = true;
  std::cout << (ans ? "IMPOSSIBLE" : "POSSIBLE") << "\n";
}
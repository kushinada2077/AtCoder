#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1e18;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<i64> x(n), c(n + 1), dp(n + 1);
  for (int i = 0; i < n; ++i) std::cin >> x[i];
  for (int i = 0; i < m; ++i) {
    int a;
    std::cin >> a >> c[a];
  }

  for (int i = 0; i < n; ++i) {
    std::vector<i64> g(n + 1);
    for (int j = 0; j <= i; ++j) {
      g[j + 1] = std::max(g[j + 1], dp[j] + x[i] + c[j + 1]);
      g[0] = std::max(g[0], dp[j]);
    }
    dp = g;
  }

  std::cout << *max_element(dp.begin(), dp.end()) << "\n";
}
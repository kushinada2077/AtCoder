#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<i64> x(n), c(n + 1);
  std::vector<std::vector<i64>> dp(n, std::vector<i64>(n + 1, 0));
  for (int i = 0; i < n; ++i) std::cin >> x[i];
  for (int i = 0; i < m; ++i) {
    int a;
    i64 b;
    std::cin >> a >> b;
    c[a] = b;
  }

  dp[0][1] = x[0] + c[1];

  for (int i = 1; i < n; ++i) {
    dp[i][0] = *max_element(dp[i - 1].begin(), dp[i - 1].end());
    for (int j = 1; j <= i + 1; ++j) {
      dp[i][j] = dp[i - 1][j - 1] + x[i] + c[j];
    }
  }

  std::cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";
}
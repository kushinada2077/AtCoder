#include <bits/stdc++.h>
using i64 = long long;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<i64> a(n);
  // dp[i][j] = i번째까지일 때 최대 합 i번째는 누름(j == 1), 안 누름(j == 0)
  std::vector dp(n + 1, std::vector<i64>(2, 0));
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  dp[0][0] = a[0];
  dp[0][1] = -a[0];

  for (int i = 0; i < n - 1; ++i) {
    dp[i + 1][0] = std::max(dp[i][0] + a[i + 1], dp[i][1] - a[i + 1]);
    dp[i + 1][1] = std::max(dp[i][0] - a[i + 1], dp[i][1] + a[i + 1]);
  }

  std::cout << dp[n - 1][0] << "\n";
}
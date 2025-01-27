#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, n;
  std::cin >> h >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i];
  }
  int ans = 0x3f3f3f3f;
  std::vector dp(n + 1, std::vector<int>(20001, 0x3f3f3f3f));
  for (int i = n - 1; i >= 0; --i) {
    dp[i][0] = 0;
    for (int j = 1; j <= 20000; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (j - a[i] <= 20000 && j - a[i] >= 0) {
        dp[i][j] = std::min(dp[i][j], dp[i][j - a[i]] + b[i]);
      }
      if (j >= h) {
        ans = std::min(ans, dp[i][j]);
      }
    }
  }

  std::cout << ans << "\n";
}
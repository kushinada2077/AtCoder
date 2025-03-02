#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n;
  std::cin >> n;
  std::vector dp(10, std::vector<i64>(10));
  for (int i = 1; i <= n; ++i) {
    int f = i, b = i % 10;
    while (f > 9) {
      f /= 10;
    }
    dp[f][b]++;
  }

  i64 ans = 0;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      ans += dp[i][j] * dp[j][i];
    }
  }

  std::cout << ans << "\n";
}
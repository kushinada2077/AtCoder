#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  i64 x;
  std::cin >> n >> x;
  std::vector<i64> dp(n + 1), pat(n + 1);
  dp[0] = pat[0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = 2 * dp[i - 1] + 3;
    pat[i] = 2 * pat[i - 1] + 1;
  }

  i64 ans = 0;
  for (int i = n; i >= 0 && x > 0;) {
    if (x >= dp[i]) {
      ans += pat[i];
      x -= dp[i];
      if (x > 0) {
        x--;
        ans++;
      }
    } else {
      i--;
      x--;
    }
  }

  std::cout << ans << "\n";
}
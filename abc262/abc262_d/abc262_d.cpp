#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  mint ans = 0;
  for (int i = 1; i <= n; ++i) {
    std::vector dp(n + 1, std::vector(i + 1, std::vector<mint>(i, 0)));
    dp[0][0][0] = 1;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k <= i; ++k) {
        for (int l = 0; l < i; ++l) {
          dp[j + 1][k][l] += dp[j][k][l];
          if (i != k) dp[j + 1][k + 1][(l + a[j]) % i] += dp[j][k][l];
        }
      }
    }
    ans += dp[n][i][0];
  }

  std::cout << ans.val() << "\n";
}
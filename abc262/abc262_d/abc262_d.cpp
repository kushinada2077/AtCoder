#include <bits/stdc++.h>
using i64 = long long;

constexpr int M = 998244353;

i64 my_pow(i64 a, i64 b) {
  if (b == 0) return 1;
  if (b % 2) return a * my_pow(a, b - 1) % M;
  i64 half = my_pow(a, b / 2) % M;
  return half * half % M;
}
i64 nCr(i64 n, i64 r) {
  if (n == r || r == 0) return 1;
  return nCr(n - 1, r - 1) % M + nCr(n, r - 1) % M;
}

// dp[i][j][k] 앞의 i개에서 j개를 골랐을 때 고른 합을 a로 나눈 나머지가 k인 개수를 M으로 나눈 값

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    std::vector dp(n + 1, std::vector(i + 1, std::vector<i64>(i, 0)));
    dp[0][0][0] = 1;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k <= i; ++k) {
        for (int l = 0; l < i; ++l) {
          dp[j + 1][k][l] = (dp[j][k][l] + dp[j + 1][k][l]) % M;
          i64& d = dp[j + 1][k + 1][(l + a[j]) % i];
          if (i != k) d = (d + dp[j][k][l]) % M;
        }
      }
    }

    ans = (ans + dp[n][i][0]) % M;
  }

  std::cout << ans << "\n";
}
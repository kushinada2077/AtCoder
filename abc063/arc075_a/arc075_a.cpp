#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, sum = 0;
  std::cin >> N;
  std::vector<int> s(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> s[i];
    sum += s[i];
  }

  std::vector dp(N + 1, std::vector<int>(sum + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= sum; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - s[i - 1] >= 0) {
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - s[i - 1]]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= sum; ++i) {
    if (dp[N][i] == 1 && i % 10 != 0) {
      ans = std::max(ans, i);
    }
  }

  std::cout << ans << "\n";
}
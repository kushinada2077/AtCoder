#include <bits/stdc++.h>
using i64 = long long;

constexpr int INF = 100000;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> c;
  c.push_back(1);
  int nine = 9, six = 6;
  while (nine <= N) {
    c.push_back(nine);
    nine *= 9;
  }
  while (six <= N) {
    c.push_back(six);
    six *= 6;
  }
  int n = c.size();
  std::vector dp(n + 1, std::vector<int>(N + 1, INF));
  for (int i = 0; i < n; ++i) {
    dp[i + 1][0] = 0;
    for (int j = 1; j <= N; ++j) {
      dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
      if (j - c[i] >= 0) {
        dp[i + 1][j] = std::min(dp[i + 1][j], dp[i + 1][j - c[i]] + 1);
      }
    }
  }
  std::cout << dp[n][N] << "\n";
}
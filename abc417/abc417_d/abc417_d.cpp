#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 30000;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> P(N), A(N), B(N), sum(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> P[i] >> A[i] >> B[i];
    if (i > 0) sum[i] += sum[i - 1];
    sum[i] += B[i];
  }

  std::vector dp(N + 1, std::vector<int>(1001, 0));
  for (int i = 0; i < 1001; ++i) {
    if (i > P[N - 1]) {
      dp[N - 1][i] = std::max(0, i - B[N - 1]);
    } else {
      dp[N - 1][i] = i + A[N - 1];
    }
  }

  for (int i = N - 2; i >= 0; --i) {
    for (int j = 0; j < 1001; ++j) {
      if (j > P[i]) {
        dp[i][j] = dp[i + 1][std::max(0, j - B[i])];
      } else {
        dp[i][j] = dp[i + 1][j + A[i]];
      }
    }
  }

  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int X;
    std::cin >> X;
    if (X > 1000) {
      auto j = std::lower_bound(sum.begin(), sum.end(), X - 1000) - sum.begin();
      if (j + 1 < N) {
        std::cout << dp[j + 1][std::max(0, X - sum[j])] << "\n";
      } else {
        std::cout << std::max(0, X - sum[N - 1]) << "\n";
      }
    } else {
      std::cout << dp[0][X] << "\n";
    }
  }
}
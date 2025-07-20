#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int H, W;
  std::cin >> H >> W;
  int K = H + W - 1;
  std::vector A(H, std::vector<i64>(W, 0));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      std::cin >> A[i][j];
    }
  }
  std::vector<i64> P(K);
  for (int i = 0; i < K; ++i) {
    std::cin >> P[i];
  }

  std::vector B(H, std::vector<i64>(W, 0));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      B[i][j] = A[i][j] - P[i + j];
    }
  }

  std::vector dp(H, std::vector<i64>(W, LLONG_MAX));
  dp[H - 1][W - 1] = std::max(0LL, -B[H - 1][W - 1]);
  for (int i = H - 1; i >= 0; --i) {
    for (int j = W - 1; j >= 0; --j) {
      if (i < H - 1) {
        dp[i][j] = std::min(dp[i][j], std::max(0LL, dp[i + 1][j] - B[i][j]));
      }
      if (j < W - 1) {
        dp[i][j] = std::min(dp[i][j], std::max(0LL, dp[i][j + 1] - B[i][j]));
      }
    }
  }

  std::cout << std::max(0LL, dp[0][0]) << "\n";
}
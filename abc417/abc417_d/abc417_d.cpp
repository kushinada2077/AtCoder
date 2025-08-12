#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1001;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> P(N), A(N), B(N), pref(N + 1);
  for (int i = 0; i < N; ++i) {
    std::cin >> P[i] >> A[i] >> B[i];
    pref[i + 1] = pref[i] + B[i];
  }

  std::vector dp(N, std::vector<int>(MAX, 0));
  for (int i = 0; i < MAX; ++i) {
    dp[N - 1][i] = P[N - 1] >= i ? i + A[N - 1] : std::max(0, i - B[N - 1]);
  }

  for (int i = N - 2; i >= 0; --i) {
    for (int j = 0; j < MAX; ++j) {
      if (P[i] >= j) dp[i][j] = dp[i + 1][j + A[i]];
      else dp[i][j] = dp[i + 1][std::max(0, j - B[i])];
    }
  }

  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int x;
    std::cin >> x;
    auto p = std::lower_bound(pref.begin(), pref.end(), std::max(0, x - MAX + 1)) - pref.begin();
    if (p >= N) {
      std::cout << std::max(0, x - pref[N]) << "\n";
      continue;
    }
    x -= pref[p];
    std::cout << dp[p][x] << "\n";
  }
}
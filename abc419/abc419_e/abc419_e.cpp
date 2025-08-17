#include <bits/stdc++.h>
using i64 = long long;
template <class T, class U>
inline bool chmin(T& a, const U& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
constexpr int INF = 0x3f3f3f3f;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M, L;
  std::cin >> N >> M >> L;
  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  std::vector<int> dp(M, INF);
  dp[0] = 0;
  for (int i = 0; i < L; ++i) {
    std::vector<int> ep(M, INF);
    for (int j = 0; j < M; ++j) {
      int cost = 0;
      for (int k = i; k < N; k += L) {
        if (j >= A[k]) cost += j - A[k];
        else cost += j - A[k] + M;
      }
      for (int k = 0; k < M; ++k) {
        chmin(ep[(k + j) % M], dp[k] + cost);
      }
    }
    dp = std::move(ep);
  }

  std::cout << dp[0] << "\n";
}
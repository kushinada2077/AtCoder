#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N, M;
  std::cin >> N >> M;
  std::vector<std::pair<i64, i64>> A(M);
  for (int i = 0; i < M; ++i) {
    i64 a, b;
    std::cin >> a >> b;
    A[i] = {a, b};
  }
  std::sort(A.begin(), A.end(), [&](std::pair<i64, i64> a, std::pair<i64, i64> b) {
    if (a.first - a.second == b.first - b.second) return a < b;
    return a.first - a.second < b.first - b.second;
  });

  i64 ans = 0;

  for (int i = 0; i < M; ++i) {
    auto [a, b] = A[i];
    if (a > N) {
      continue;
    }
    i64 d = a - b;
    i64 cnt = (N - a + d) / d;
    ans += cnt;
    N -= cnt * d;
  }

  std::cout << ans << "\n";
}
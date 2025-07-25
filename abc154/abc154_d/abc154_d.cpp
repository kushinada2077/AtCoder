#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, K;
  std::cin >> N >> K;
  std::vector<int> p(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> p[i];
  }
  double ans = 0, cur = 0;
  for (int i = 0; i < K - 1; ++i) {
    cur += (p[i] + (double)1) / 2;
  }

  for (int i = K - 1; i < N; ++i) {
    cur += (p[i] + (double)1) / 2;
    ans = std::max(ans, cur);
    cur -= (p[i - K + 1] + (double)1) / 2;
  }

  std::cout << std::fixed << std::setprecision(10) << ans << "\n";
}
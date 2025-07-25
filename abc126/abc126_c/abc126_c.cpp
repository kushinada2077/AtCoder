#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, K;
  std::cin >> N >> K;
  std::cout << std::fixed << std::setprecision(20);
  double ans = 0;
  auto cal = [&](int x) {
    int ret = 0;
    while (K > x) {
      ret++;
      x *= 2;
    }
    return ret;
  };
  for (int i = 1; i <= N; ++i) {
    int times = cal(i);
    ans += (double)1 / (1 << times);
  }
  ans /= N;
  std::cout << ans << "\n";
}
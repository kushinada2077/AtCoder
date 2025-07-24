#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, T;
  std::cin >> N >> T;
  int ans = 0, l = 0, r = T;
  for (int i = 0; i < N; ++i) {
    int t;
    std::cin >> t;
    if (t > r) {
      ans += r - l;
      l = t;
      r = t + T;
    } else {
      r = t + T;
    }
  }
  ans += r - l;
  std::cout << ans << "\n";
}
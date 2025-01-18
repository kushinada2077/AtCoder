#include <bits/stdc++.h>
using i64 = long long;

__int128 a;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  i64 m;
  std::cin >> n >> m;
  std::vector<i64> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }

  i64 lo = 1, hi = m + 1;
  auto ok = [&](i64 mid) {
    __int128 s = 0;
    for (int i = 0; i < n; ++i) {
      __int128 t = (mid / p[i] + 1) / 2;
      s += t * t * p[i];
      if (s > m) break;
    }
    return s <= m;
  };

  while (lo + 1 < hi) {
    i64 mid = (lo + hi) / 2;
    if (ok(mid)) lo = mid;
    else hi = mid;
  }

  i64 ans = 0, t = 0;
  for (int i = 0; i < n; ++i) {
    i64 g = (lo / p[i] + 1) / 2;
    ans += g;
    t += g * g * p[i];
  }

  ans += (m - t) / hi;
  std::cout << ans << "\n";
}
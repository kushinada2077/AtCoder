#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::map<int, int> a;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    a[x]++;
  }

  for (int i = 0; i < m; ++i) {
    int b, c;
    std::cin >> b >> c;

    while (b) {
      auto [v, cnt] = *a.begin();
      if (v > c) break;
      a[v] = std::max(0, cnt - b);
      a[c] += cnt - a[v];
      b = std::max(0, b - cnt);
      if (cnt == 0) a.erase(v);
    }
  }

  i64 ans = 0;
  for (auto [v, cnt] : a) {
    ans += 1LL * v * cnt;
  }

  std::cout << ans << "\n";
}
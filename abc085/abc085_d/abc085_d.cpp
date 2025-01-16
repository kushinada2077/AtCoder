#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, h;
  std::cin >> n >> h;
  std::vector<std::tuple<int, int, int>> p;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    p.push_back({a, 0, i});
    p.push_back({b, 1, i});
  }

  sort(p.begin(), p.end());
  int ans = 0;
  for (int i = 2 * n - 1; i >= 0 && h > 0; --i) {
    auto [d, t, idx] = p[i];
    if (t == 1) {
      h -= d;
      ans++;
    } else {
      ans += (h + d - 1) / d;
      h = 0;
      break;
    }
  }

  std::cout << ans << "\n";
}
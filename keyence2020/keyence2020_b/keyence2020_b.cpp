#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> x(n), l(n);
  std::vector<std::pair<int, int>> ts;
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i] >> l[i];
    ts.push_back({x[i] + l[i], x[i] - l[i]});
  }

  sort(ts.begin(), ts.end());

  int ans = 0, c = -INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (c <= ts[i].second) {
      ans++;
      c = ts[i].first;
    }
  }

  std::cout << ans << "\n";
}
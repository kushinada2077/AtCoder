#include <bits/stdc++.h>
using i64 = long long;

std::string conv(int n) {
  std::string sn = std::to_string(n);
  return std::string(std::max(0, 6 - (int)sn.size()), '0') + sn;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> p(m), y(m);
  std::vector c(n, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    std::cin >> p[i] >> y[i];
    c[p[i] - 1].push_back(y[i]);
  }

  for (int i = 0; i < n; ++i) {
    sort(c[i].begin(), c[i].end());
  }

  for (int i = 0; i < m; ++i) {
    auto& b = c[p[i] - 1];
    int x = lower_bound(b.begin(), b.end(), y[i]) - b.begin() + 1;
    std::cout << conv(p[i]) + conv(x) << "\n";
  }
}
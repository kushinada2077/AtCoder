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
  std::vector b(n + 1, std::vector<std::pair<int, int>>());
  std::vector<std::string> ans(m);
  for (int i = 0; i < m; ++i) {
    int p, y;
    std::cin >> p >> y;
    b[p].push_back({y, i});
  }

  for (int i = 1; i <= n; ++i) {
    if (b[i].size()) {
      sort(b[i].begin(), b[i].end());
      int k = b[i].size();
      for (int j = 0; j < k; ++j) {
        auto [p, idx] = b[i][j];
        ans[idx] = conv(i) + conv(j + 1);
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    std::cout << ans[i] << "\n";
  }
}
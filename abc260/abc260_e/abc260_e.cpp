#include <bits/stdc++.h>
using i64 = long long;

int n, m;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n >> m;
  std::vector<int> f(m);
  int maxl = m - 1, minr = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    maxl = std::min(maxl, b);
    minr = std::max(minr, a);
    f[a] = std::max(f[a], b);
  }

  std::vector<int> ans(m);
  for (int i = 0; i <= maxl; ++i) {
    ans[minr - i + 1]++;
    ans[m - i + 1]--;
    minr = std::max(minr, f[i]);
  }

  for (int i = 2; i <= m; ++i) {
    ans[i] += ans[i - 1];
  }

  for (int i = 1; i <= m; ++i) {
    std::cout << ans[i] << " \n"[i == m];
  }
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, allcnt = 0;
  std::cin >> n >> m;
  std::vector<int> a(n), b(n), cnt(n), ans(m + 3);
  std::vector<std::vector<int>> inv(m + 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i];
    inv[a[i]].push_back(i);
    inv[b[i]].push_back(i);
  }
  for (int i = 1, j = 1; i <= m;) {
    while (j <= m && allcnt < n) {
      for (auto v : inv[j]) {
        if (cnt[v] == 0) allcnt++;
        cnt[v]++;
      }
      j++;
    }

    if (allcnt < n) break;
    ans[j - i]++;
    ans[m - i + 2]--;

    for (auto v : inv[i]) {
      cnt[v]--;
      if (cnt[v] == 0) allcnt--;
    }
    i++;
  }

  for (int i = 1; i <= m; ++i) {
    ans[i] += ans[i - 1];
    std::cout << ans[i] << " \n"[i == m];
  }
}
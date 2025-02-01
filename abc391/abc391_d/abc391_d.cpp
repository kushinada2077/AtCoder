#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, w;
  std::cin >> n >> w;
  std::vector b(w + 1, std::vector<std::pair<int, int>>());
  std::map<int, int> e;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    b[x].push_back({y, i + 1});
  }
  for (int i = 1; i <= w; ++i) {
    sort(b[i].begin(), b[i].end());
  }
  int l = 0;
  while (true) {
    bool ok = true;
    int maxy = 0;
    for (int i = 1; i <= w; ++i) {
      if (l >= b[i].size()) {
        ok = false;
        break;
      }
      maxy = std::max(maxy, b[i][l].first);
    }

    if (ok == true) {
      for (int i = 1; i <= w; ++i) {
        auto [_, v] = b[i][l];
        e[v] = maxy;
      }
      l++;
    } else {
      break;
    }
  }

  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int t, a;
    std::cin >> t >> a;

    if (!e.contains(a) || t < e[a]) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
}
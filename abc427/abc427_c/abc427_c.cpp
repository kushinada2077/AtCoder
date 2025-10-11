#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<P> edge;
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    edge.push_back({u, v});
  }

  int ans = 0x3f3f3f3f;

  for (int bit = 0; bit < (1 << n); ++bit) {
    int cnt = 0;

    for (int i = 0; i < m; ++i) {
      auto [u, v] = edge[i];
      if (((bit >> u) & 1) == ((bit >> v) & 1)) cnt++;
    }

    ans = std::min(ans, cnt);
  }

  std::cout << ans << "\n";
}
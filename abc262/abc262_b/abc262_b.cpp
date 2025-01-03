#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<bool>> c(n + 1, std::vector<bool>(n + 1, false));
  for (int u, v, i = 0; i < m; ++i) {
    std::cin >> u >> v;
    c[u][v] = c[v][u] = true;
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      for (int k = j + 1; k <= n; ++k) {
        if (c[i][j] && c[j][k] && c[k][i]) ans++;
      }
    }
  }

  std::cout << ans << "\n";
}
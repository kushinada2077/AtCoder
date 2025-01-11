#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<int> adj[n + 1], c(n + 1), ans(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < q; ++i) {
    int p, x;
    std::cin >> p >> x;
    c[p] += x;
  }

  std::vector<bool> vis(n + 1);
  std::function<void(int, int)> dfs = [&](int u, int cnt) {
    vis[u] = true;
    ans[u] = cnt + c[u];
    for (auto v : adj[u]) {
      if (!vis[v]) {
        dfs(v, ans[u]);
      }
    }
  };

  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    std::cout << ans[i] << " \n"[i == n];
  }
}
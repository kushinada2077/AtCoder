#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<int> adj[n + 1], c(n + 1), s(n + 1), e(n + 1), inv(n + 1);
  std::vector<bool> vis(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int sn = 1;
  std::function<void(int)> dfs = [&](int u) {
    vis[u] = true;
    inv[sn] = u;
    s[u] = sn++;
    for (auto v : adj[u]) {
      if (!vis[v]) {
        dfs(v);
      }
    }
    e[u] = sn;
  };

  dfs(1);

  for (int i = 0; i < q; ++i) {
    int p, x;
    std::cin >> p >> x;
    c[s[p]] += x;
    if (e[p] <= n) c[e[p]] -= x;
  }

  for (int i = 1; i < n; ++i) {
    c[i + 1] += c[i];
  }

  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    ans[inv[i]] = c[i];
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << ans[i] << " \n"[i == n];
  }
}
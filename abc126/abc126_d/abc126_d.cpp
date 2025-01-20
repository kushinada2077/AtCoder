#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector adj(n + 1, std::vector<std::pair<int, int>>());
  std::vector<int> p(n + 1);
  std::vector<bool> ans(n + 1);
  for (int i = 0; i < n; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back({w % 2, v});
    adj[v].push_back({w % 2, u});
  }

  std::queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [w, v] : adj[u]) {
      if (p[u] == v) continue;
      q.push(v);
      p[v] = u;
      ans[v] = w == 0 ? ans[u] : !ans[u];
    }
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << ans[i] << "\n";
  }
}
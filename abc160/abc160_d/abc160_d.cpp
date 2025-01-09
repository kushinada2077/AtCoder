#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector adj(n + 1, std::vector<int>());
  for (int i = 1; i < n; ++i) {
    adj[i].push_back(i + 1);
    adj[i + 1].push_back(i);
  }
  adj[x].push_back(y);
  adj[y].push_back(x);
  std::vector<int> ans(n + 1);

  for (int st = 1; st <= n; ++st) {
    std::queue<int> q;
    std::vector<int> dist(n + 1, -1);
    q.push(st);
    dist[st] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : adj[u]) {
        if (dist[v] != -1) continue;
        q.push(v);
        dist[v] = dist[u] + 1;
        if (st < v) ans[dist[v]]++;
      }
    }
  }

  for (int i = 1; i < n; ++i) std::cout << ans[i] << "\n";
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> vis(n + 1);
  std::queue<int> q;
  std::vector adj(n + 1, std::vector<int>());

  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    if (a == 0 && b == 0) {
      q.push(i + 1);
      vis[i + 1] = true;
    }
    adj[a].push_back(i + 1);
    adj[b].push_back(i + 1);
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (vis[v] == 0) {
        q.push(v);
        vis[v] = 1;
      }
    }
  }

  std::cout << std::count(vis.begin() + 1, vis.end(), 1) << "\n";
}
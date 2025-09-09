#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, X, Y;
  std::cin >> N >> X >> Y;
  std::vector adj(N + 1, std::vector<int>());
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<bool> vis(N + 1, false);
  std::vector<int> ans;
  vis[X] = true;

  auto dfs = [&](auto&& dfs, int u) {
    int result = 0;
    for (auto v : adj[u]) {
      if (vis[v] == true) continue;
      if (v == Y) {
        ans.push_back(Y);
        ans.push_back(u);
        vis[Y] = true;
        return result = 1;
      }
      vis[v] = true;
      result = std::max(result, dfs(dfs, v));
    }

    if (result == 1) {
      ans.push_back(u);
    }

    return result;
  };

  dfs(dfs, X);

  for (int i = (int)ans.size() - 1; i >= 0; --i) {
    std::cout << ans[i] << " \n"[i == 0];
  }
}
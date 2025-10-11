#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using P = std::pair<int, int>;

void solve() {
  int n, m, k;
  std::string s;
  std::cin >> n >> m >> k >> s;
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
  }

  std::vector dp(n, std::vector<int>(2 * k, -1));
  auto dfs = [&](auto&& dfs, int u, int cnt) {
    if (cnt == 2 * k) {
      if (s[u] == 'A') return 1;
      else return 2;
    }
    int& ret = dp[u][cnt];

    if (ret != -1) return ret;

    if (cnt % 2 == 0) {
      ret = 2;
      for (auto& v : adj[u]) {
        if (dfs(dfs, v, cnt + 1) == 1) ret = 1;
      }
    } else {
      ret = 1;
      for (auto& v : adj[u]) {
        if (dfs(dfs, v, cnt + 1) == 2) ret = 2;
      }
    }

    return ret;
  };

  dfs(dfs, 0, 0);
  if (dp[0][0] == 1) std::cout << "Alice\n";
  else std::cout << "Bob\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}
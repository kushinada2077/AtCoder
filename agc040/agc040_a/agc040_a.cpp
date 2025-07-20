#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string S;
  std::cin >> S;
  int N = S.size() + 1;
  std::vector adj(N, std::vector<int>());
  std::vector<int> indg(N, 0);
  for (int i = 0; i < N - 1; ++i) {
    if (S[i] == '<') {
      adj[i].push_back(i + 1);
      indg[i + 1]++;
    } else {
      adj[i + 1].push_back(i);
      indg[i]++;
    }
  }

  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < N; ++i) {
    if (indg[i] == 0) {
      q.push({i, 0});
    }
  }

  i64 ans = 0;
  while (!q.empty()) {
    auto [u, val] = q.front();
    q.pop();
    ans += val;
    for (auto v : adj[u]) {
      if (--indg[v] == 0) {
        q.push({v, val + 1});
      }
    }
  }

  std::cout << ans << "\n";
}
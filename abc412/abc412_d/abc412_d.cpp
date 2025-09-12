#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  std::vector adj(N, std::vector<int>(N, 0));
  for (int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    adj[u][v] = adj[v][u] = 1;
  }

  int K = N * (N - 1) / 2;
  std::vector<int> b(K, 1);
  std::fill(b.begin(), b.begin() + N, 0);
  int ans = 0x3f3f3f3f;

  do {
    int cnt = 0, tot = 0;
    std::vector<int> deg(N, 0);
    for (int i = 0; i < N - 1; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (b[cnt] == 0) {
          tot += adj[i][j] != 1;
          deg[i]++;
          deg[j]++;
        } else {
          tot += adj[i][j] != 0;
        }
        cnt++;
      }
    }

    if (std::ranges::all_of(deg, [&](int x) { return x == 2; })) ans = std::min(ans, tot);
  } while (std::next_permutation(b.begin(), b.end()));

  std::cout << ans << "\n";
}
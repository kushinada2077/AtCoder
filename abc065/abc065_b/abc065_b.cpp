#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> next(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> next[i];
    next[i]--;
  }
  std::queue<int> q;
  std::vector<int> dist(N, -1);
  q.push(0);
  dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v = next[u];
    if (dist[v] != -1) {
      continue;
    }
    q.push(v);
    dist[v] = dist[u] + 1;
  }

  std::cout << dist[1] << "\n";
}
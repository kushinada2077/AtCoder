#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 INF = 1e18;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  std::vector dist(N + 1, std::vector<i64>(N + 1, INF));
  for (int i = 0; i <= N; ++i) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    dist[a][b] = std::min(dist[a][b], (i64)c);
    dist[b][a] = std::min(dist[b][a], (i64)c);
  }
  int K, T;
  std::cin >> K >> T;
  for (int i = 0; i < K; ++i) {
    int D;
    std::cin >> D;
    dist[D][0] = T;
    dist[0][D] = 0;
  }

  for (int k = 0; k <= N; ++k) {
    for (int i = 0; i <= N; ++i) {
      for (int j = 0; j <= N; ++j) {
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int type;
    std::cin >> type;
    if (type == 1) {
      int x, y, t;
      std::cin >> x >> y >> t;
      dist[x][y] = std::min(dist[x][y], (i64)t);
      dist[y][x] = std::min(dist[y][x], (i64)t);
      for (auto k : {x, y}) {
        for (int i = 0; i <= N; ++i) {
          for (int j = 0; j <= N; ++j) {
            dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    } else if (type == 2) {
      int x;
      std::cin >> x;
      dist[x][0] = T;
      dist[0][x] = 0;
      for (auto k : {0, x}) {
        for (int i = 0; i <= N; ++i) {
          for (int j = 0; j <= N; ++j) {
            dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    } else if (type == 3) {
      i64 tot = 0;
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          tot += dist[i][j] % INF;
        }
      }
      std::cout << tot << "\n";
    }
  }
}
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
    int a, b;
    i64 c;
    std::cin >> a >> b >> c;
    dist[a][b] = std::min(dist[a][b], c);
    dist[b][a] = std::min(dist[b][a], c);
  }
  int K, T;
  std::cin >> K >> T;
  for (int i = 0; i < K; ++i) {
    int D;
    std::cin >> D;
    dist[0][D] = 0;
    dist[D][0] = T;
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
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, y, t;
      std::cin >> x >> y >> t;

      for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
          dist[i][j] = std::min(dist[i][j], dist[i][y] + t + dist[x][j]);
          dist[i][j] = std::min(dist[i][j], dist[i][x] + t + dist[y][j]);
        }
      }
    } else if (op == 2) {
      int x;
      std::cin >> x;
      for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
          dist[i][j] = std::min(dist[i][j], dist[i][x] + T + dist[0][j]);
          dist[i][j] = std::min(dist[i][j], dist[i][0] + dist[x][j]);
        }
      }

    } else if (op == 3) {
      i64 tot = 0;
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          if (dist[i][j] != INF) {
            tot += dist[i][j];
          }
        }
      }
      std::cout << tot << "\n";
    }
  }
}
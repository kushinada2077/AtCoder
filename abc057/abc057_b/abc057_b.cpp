#include <bits/stdc++.h>
using i64 = long long;

int m_distance(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  std::vector<std ::pair<int, int>> A(N), B(M);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i].first >> A[i].second;
  }
  for (int i = 0; i < M; ++i) {
    std::cin >> B[i].first >> B[i].second;
  }

  for (int i = 0; i < N; ++i) {
    auto [x, y] = A[i];
    int t = 0;
    for (int j = 1; j < M; ++j) {
      auto [px, py] = B[t];
      auto [nx, ny] = B[j];
      if (m_distance(x, y, px, py) > m_distance(x, y, nx, ny)) {
        t = j;
      }
    }

    std::cout << t + 1 << "\n";
  }
}
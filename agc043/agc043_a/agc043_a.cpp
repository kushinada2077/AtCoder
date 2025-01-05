#include <bits/stdc++.h>
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> a(h);
  std::vector dist(h, std::vector<int>(w, 0x3f3f3f3f));
  for (int i = 0; i < h; ++i) std::cin >> a[i];

  std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
  pq.push({a[0][0] == '#', 0, 0});
  dist[0][0] = a[0][0] == '#';

  while (!pq.empty()) {
    auto [d, y, x] = pq.top();
    pq.pop();
    if (d != dist[y][x]) continue;

    for (int dir = 0; dir < 2; ++dir) {
      int ny = y + "21"[dir] - '1', nx = x + "12"[dir] - '1';
      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      int c = a[y][x] == '.' && a[ny][nx] == '#';
      if (c + d >= dist[ny][nx]) continue;
      pq.push({c + d, ny, nx});
      dist[ny][nx] = c + d;
    }
  }

  std::cout << dist[h - 1][w - 1] << "\n";
}
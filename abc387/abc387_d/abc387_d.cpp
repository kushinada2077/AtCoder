#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> b(h);
  int si, sj, ei, ej;
  for (int i = 0; i < h; ++i) {
    std::cin >> b[i];
    for (int j = 0; j < w; ++j) {
      if (b[i][j] == 'S') {
        si = i;
        sj = j;
      }
      if (b[i][j] == 'G') {
        ei = i;
        ej = j;
      }
    }
  }

  int ans = 0x3f3f3f3f;
  for (int fd = 0; fd < 4; ++fd) {
    std::queue<std::tuple<int, int, bool>> q;
    std::vector dist(h, std::vector<int>(w, -1));
    int nx = sj + "2101"[fd] - '1', ny = si + "1210"[fd] - '1';
    if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
    if (b[ny][nx] == '#') continue;
    q.push({ny, nx, fd % 2});
    dist[si][sj] = 0;
    dist[ny][nx] = 1;

    while (!q.empty()) {
      auto [y, x, s] = q.front();
      q.pop();

      if (ei == y && ej == x) {
        ans = std::min(ans, dist[y][x]);
        break;
      }

      for (int dir = 0; dir < 4; ++dir) {
        if (dir % 2 == s) continue;
        int ny = y + "1210"[dir] - '1', nx = x + "2101"[dir] - '1';
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if (dist[ny][nx] != -1 || b[ny][nx] == '#') continue;
        q.push({ny, nx, dir % 2});
        dist[ny][nx] = dist[y][x] + 1;
      }
    }
  }

  if (ans == 0x3f3f3f3f) ans = -1;
  std::cout << ans << "\n";
}
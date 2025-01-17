#include <bits/stdc++.h>
using i64 = long long;

int bfs(int sy, int sx, std::vector<std::vector<char>>& b) {
  int h = b.size(), w = b[0].size();
  int ret = 0;
  std::queue<std::pair<int, int>> q;
  std::vector d(h, std::vector<int>(w, -1));
  q.push({sy, sx});
  d[sy][sx] = 0;

  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + "2101"[dir] - '1', nx = x + "1210"[dir] - '1';
      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if (b[ny][nx] == '#' || d[ny][nx] != -1) continue;
      q.push({ny, nx});
      d[ny][nx] = d[y][x] + 1;
      ret = std::max(ret, d[ny][nx]);
    }
  }

  return ret;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  std::cin >> h >> w;
  std::vector b(h, std::vector<char>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cin >> b[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (b[i][j] == '.') {
        ans = std::max(ans, bfs(i, j, b));
      }
    }
  }

  std::cout << ans << "\n";
}
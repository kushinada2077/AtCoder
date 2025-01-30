#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w, ans = 0;
  std::cin >> h >> w;
  std::vector<std::string> m(h);
  for (int i = 0; i < h; ++i) {
    std::cin >> m[i];
    for (int j = 0; j < w; ++j) {
      ans += m[i][j] == '.';
    }
  }

  std::queue<std::pair<int, int>> q;
  std::vector d(h, std::vector<int>(w));
  q.push({0, 0});
  d[0][0] = 1;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + "2101"[dir] - '1';
      int nx = x + "1210"[dir] - '1';
      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if (m[ny][nx] == '#' || d[ny][nx] != 0) continue;
      q.push({ny, nx});
      d[ny][nx] = d[y][x] + 1;
    }
  }

  if (d[h - 1][w - 1] == 0) {
    ans = -1;
  } else {
    ans -= d[h - 1][w - 1];
  }
  std::cout << ans << "\n";
}
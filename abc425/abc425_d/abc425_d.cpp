#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> board(h);
  for (int i = 0; i < h; ++i) {
    std::cin >> board[i];
  }

  auto OOB = [&](int y, int x) { return y < 0 || y >= h || x < 0 || x >= w; };
  auto cnt = [&](int y, int x) {
    int ret = 0;
    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + "2101"[dir] - '1';
      int nx = x + "1210"[dir] - '1';
      if (!OOB(ny, nx) && board[ny][nx] == '#') ret++;
    }

    return ret;
  };

  std::vector<P> T;
  for (int c = 0; c < h * w; ++c) {
    if (c == 0) {
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (board[i][j] == '.' && cnt(i, j) == 1) T.push_back({i, j});
        }
      }
    }

    else {
      std::vector<P> NT;
      for (auto [y, x] : T) {
        for (int dir = 0; dir < 4; ++dir) {
          int ny = y + "2101"[dir] - '1', nx = x + "1210"[dir] - '1';
          if (!OOB(ny, nx) && board[ny][nx] == '.' && cnt(ny, nx) == 1) {
            NT.push_back({ny, nx});
          }
        }
      }

      T = NT;
    }

    if (T.empty()) break;
    for (auto [y, x] : T) board[y][x] = '#';
  }

  int ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      ans += board[i][j] == '#';
    }
  }

  std::cout << ans << "\n";
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w, k;
  std::cin >> h >> w >> k;
  std::vector b(h, std::vector<char>(w));
  std::vector ans(h, std::vector<int>(w, 0));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cin >> b[i][j];
    }
  }

  int n = 1;
  std::function<void(int, int, int, int)> solve = [&](int sy, int sx, int ey, int ex) {
    int c = 0;
    for (int y = sy; y < ey; ++y) {
      for (int x = sx; x < ex; ++x) {
        c += b[y][x] == '#';
      }
    }

    if (c == 1) {
      for (int y = sy; y < ey; ++y) {
        for (int x = sx; x < ex; ++x) {
          ans[y][x] = n;
        }
      }
      n++;
    }

    else {
      bool r = false;
      int ny = -1, nx = -1;
      for (int y = sy; y < ey; ++y) {
        int c = 0;
        for (int x = sx; x < ex; ++x) {
          if (b[y][x] == '#') {
            c++;
            if (ny == -1) {
              ny = y;
            }
          }
        }
        if (c > 1) {
          r = true;
        }
      }

      for (int x = sx; x < ex; ++x) {
        for (int y = sy; y < ey; ++y) {
          if (b[y][x] == '#' && nx == -1) {
            nx = x;
            break;
          }
        }
      }

      int mid;
      if (r == true) {
        solve(sy, sx, ey, nx + 1);
        solve(sy, nx + 1, ey, ex);
      } else {
        solve(sy, sx, ny + 1, ex);
        solve(ny + 1, sx, ey, ex);
      }
      return;
    }
  };

  solve(0, 0, h, w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cout << ans[i][j] << " \n"[j == w - 1];
    }
  }
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w, k;
  std::cin >> h >> w >> k;
  std::vector b(h, std::vector<char>(w));
  std::vector ans(h, std::vector<int>(w, 0));
  std::vector<int> p;
  p.push_back(0);
  bool m = false;
  for (int i = 0; i < h; ++i) {
    bool s = false;
    for (int j = 0; j < w; ++j) {
      std::cin >> b[i][j];
      if (b[i][j] == '#') {
        s = true;
      }
    }
    if (s == true && m == false) {
      m = true;
    } else if (s == true && m == true) {
      p.push_back(i);
    }
  }

  p.push_back(h);

  int n = p.size(), c = 1;
  for (int i = 0; i < n - 1; ++i) {
    bool m = false;
    int ni = p[i + 1];
    for (int x = 0; x < w; ++x) {
      bool s = false;
      for (int y = p[i]; y < ni; ++y) {
        if (b[y][x] == '#') {
          s = true;
        }
      }
      if (m == false && s == true) {
        m = true;
      } else if (m == true && s == true) {
        c++;
      }

      for (int y = p[i]; y < ni; ++y) {
        ans[y][x] = c;
      }
    }
    c++;
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cout << ans[i][j] << " \n"[j == w - 1];
    }
  }
}
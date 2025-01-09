#include <bits/stdc++.h>
using i64 = long long;

std::tuple<int, int, int> fill(int y, int x, int c, int cnt, bool dir, std::vector<std::vector<int>>& b) {
  if (cnt == 0) return {y, x, dir};
  if (y == b.size()) return {y, x, dir};
  int h = b.size(), w = b[0].size();
  b[y][x] = c;

  if (dir == false) {
    if (x == w - 1) return fill(y + 1, x, c, cnt - 1, !dir, b);
    else return fill(y, x + 1, c, cnt - 1, dir, b);
  } else {
    if (x == 0) return fill(y + 1, x, c, cnt - 1, !dir, b);
    else return fill(y, x - 1, c, cnt - 1, dir, b);
  }
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w, n;
  std::cin >> h >> w >> n;
  std::vector<int> a(n);
  std::vector b(h, std::vector<int>(w, 0));
  int y = 0, x = 0;
  bool dir = false;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    auto c = fill(y, x, i + 1, a[i], dir, b);
    std::tie(y, x, dir) = c;
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cout << b[i][j] << " \n"[j == w - 1];
    }
  }
}
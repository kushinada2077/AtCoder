#include <bits/stdc++.h>
using i64 = long long;

void solve(int sx, int sy, int tx, int ty) {
  while (sx != tx) {
    if (sx < tx) {
      sx++;
      std::cout << "R";
    } else {
      sx--;
      std::cout << "L";
    }
  }
  while (sy != ty) {
    if (sy < ty) {
      sy++;
      std::cout << "U";
    } else {
      sy--;
      std::cout << "D";
    }
  }
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int sx, sy, tx, ty;
  std::cin >> sx >> sy >> tx >> ty;
  int dy = ty - sy, dx = tx - sx;
  std::cout << std::string(dy, 'U') << std::string(dx, 'R');
  std::cout << std::string(dy, 'D') << std::string(dx, 'L');
  std::cout << 'D' << std::string(dx + 1, 'R') << std::string(dy + 1, 'U') << 'L';
  std::cout << 'U' << std::string(dx + 1, 'L') << std::string(dy + 1, 'D') << 'R';
}
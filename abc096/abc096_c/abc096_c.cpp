#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int H, W;
  std::cin >> H >> W;
  std::vector<std::string> s(H);
  for (int i = 0; i < H; ++i) {
    std::cin >> s[i];
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (s[i][j] == '.') continue;
      bool ok = false;
      for (int dir = 0; dir < 4; ++dir) {
        int ni = i + "2101"[dir] - '1';
        int nj = j + "1210"[dir] - '1';
        if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
        if (s[ni][nj] == '#') {
          ok = true;
          break;
        }
      }

      if (!ok) {
        std::cout << "No\n";
        return 0;
      }
    }
  }

  std::cout << "Yes\n";
}
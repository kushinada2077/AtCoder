#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int H, W;
  std::cin >> H >> W;
  std::vector<std::string> S(H);
  for (int i = 0; i < H; ++i) {
    std::cin >> S[i];
  }

  auto cnt = [&](int i, int j) {
    int ret = 0;
    for (int dir = 0; dir < 4; ++dir) {
      int ny = i + "2101"[dir] - '1';
      int nx = j + "1210"[dir] - '1';
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
      ret += S[ny][nx] == '#';
    }
    return ret;
  };

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') {
        int c = cnt(i, j);
        if (c != 2 && c != 4) {
          std::cout << "No\n";
          return 0;
        }
      }
    }
  }

  std::cout << "Yes\n";
}
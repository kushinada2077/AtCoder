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
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') {
        std::cout << "#";
      } else {
        int c = 0;
        for (int dir = 0; dir < 8; ++dir) {
          int ny = i + "22210001"[dir] - '1';
          int nx = j + "01222100"[dir] - '1';
          if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
            continue;
          }
          c += S[ny][nx] == '#';
        }
        std::cout << c;
      }
      if (j == W - 1) {
        std::cout << "\n";
      }
    }
  }
}
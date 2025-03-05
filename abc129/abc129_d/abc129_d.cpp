#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> board(h);
  for (int i = 0; i < h; ++i) {
    std::cin >> board[i];
  }

  std::vector ans(h, std::vector<int>(w));
  for (int i = 0; i < h; ++i) {
    int cnt = 0;
    for (int j = 0; j < w; ++j) {
      if (board[i][j] == '#') {
        cnt = 0;
      } else {
        ans[i][j] += ++cnt;
      }
    }

    cnt = 0;
    for (int j = w - 1; j >= 0; --j) {
      if (board[i][j] == '#') {
        cnt = 0;
      } else {
        ans[i][j] += ++cnt;
      }
    }
  }

  for (int j = 0; j < w; ++j) {
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
      if (board[i][j] == '#') {
        cnt = 0;
      } else {
        ans[i][j] += ++cnt;
      }
    }

    cnt = 0;
    for (int i = h - 1; i >= 0; --i) {
      if (board[i][j] == '#') {
        cnt = 0;
      } else {
        ans[i][j] += ++cnt;
      }
    }
  }

  int max = 0;
  for (int i = 0; i < h; ++i) {
    max = std::max(max, *std::max_element(ans[i].begin(), ans[i].end()));
  }
  std::cout << max - 3 << "\n";
}
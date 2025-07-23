#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int H, W;
  std::cin >> H >> W;
  std::vector<std::string> a(H);
  for (int i = 0; i < H; ++i) {
    std::cin >> a[i];
  }
  std::vector<bool> disabled_col(H), disabled_row(W);

  auto check_row = [&](int y) {
    bool ret = true;
    if (!disabled_row[y]) {
      for (int x = 0; x < W; ++x) {
        if (disabled_col[x]) {
          continue;
        }
        ret &= a[y][x] == '.';
      }
    } else {
      ret = false;
    }
    return ret;
  };

  auto check_col = [&](int x) {
    bool ret = true;
    if (!disabled_col[x]) {
      for (int y = 0; y < H; ++y) {
        if (disabled_row[y]) {
          continue;
        }
        ret &= a[y][x] == '.';
      }
    } else {
      ret = false;
    }
    return ret;
  };

  while (true) {
    int tx = -1, ty = -1;
    for (int i = 0; i < H; ++i) {
      if (check_row(i)) {
        disabled_row[i] = true;
        ty = i;
      }
    }

    for (int i = 0; i < W; ++i) {
      if (check_col(i)) {
        disabled_col[i] = true;
        tx = i;
      }
    }

    if (ty == -1 && tx == -1) {
      break;
    }
  }

  for (int i = 0; i < H; ++i) {
    if (disabled_row[i]) {
      continue;
    }
    for (int j = 0; j < W; ++j) {
      if (disabled_col[j]) {
        continue;
      }
      std::cout << a[i][j];
    }
    std::cout << "\n";
  }
}
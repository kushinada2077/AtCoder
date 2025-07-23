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
  std::vector<bool> row(H), col(W);
  for (int i = 0; i < H; ++i) {
    bool ok = true;
    for (int j = 0; j < W; ++j) {
      ok &= a[i][j] == '.';
    }
    if (ok) {
      row[i] = true;
    }
  }

  for (int j = 0; j < W; ++j) {
    bool ok = true;
    for (int i = 0; i < H; ++i) {
      ok &= a[i][j] == '.';
    }
    if (ok) {
      col[j] = true;
    }
  }

  for (int i = 0; i < H; ++i) {
    if (row[i]) continue;
    for (int j = 0; j < W; ++j) {
      if (col[j]) continue;
      std::cout << a[i][j];
    }
    std::cout << "\n";
  }
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector c(3, std::vector<int>(3, 0));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cin >> c[i][j];
    }
  }

  for (int i = 0; i < 3; ++i) {
    int a = c[(i + 1) % 3][0] - c[i][0];
    for (int j = 1; j < 3; ++j) {
      if (a != c[(i + 1) % 3][j] - c[i][j]) {
        std::cout << "No\n";
        return 0;
      }
    }
  }

  for (int j = 0; j < 3; ++j) {
    int a = c[0][(j + 1) % 3] - c[0][j];
    for (int i = 1; i < 3; ++i) {
      if (a != c[i][(j + 1) % 3] - c[i][j]) {
        std::cout << "No\n";
        return 0;
      }
    }
  }
  std::cout << "Yes\n";
}
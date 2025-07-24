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

  std::vector<int> a(3), b(3);
  a[1] = c[1][0] - c[0][0] + a[0];
  a[2] = c[2][0] - c[1][0] + a[1];
  b[0] = c[0][0] - a[0];
  b[1] = c[0][1] - c[0][0] + b[0];
  b[2] = c[0][2] - c[0][1] + b[1];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (a[i] + b[j] != c[i][j]) {
        std::cout << "No\n";
        return 0;
      }
    }
  }
  std::cout << "Yes\n";
}
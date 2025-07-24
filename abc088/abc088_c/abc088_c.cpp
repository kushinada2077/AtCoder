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
  b[0] = c[0][0] - a[0];
  for (int i = 1; i < 3; ++i) {
    a[i] = c[i][0] - c[i - 1][0] + a[i - 1];
    b[i] = c[0][i] - c[0][i - 1] + b[i - 1];
  }
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
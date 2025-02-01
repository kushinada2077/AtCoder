#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector a(n, std::vector<char>(n)), b(m, std::vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> b[i][j];
    }
  }

  for (int i = 0; i < n - m + 1; ++i) {
    for (int j = 0; j < n - m + 1; ++j) {
      bool ok = true;
      for (int p = i; p < i + m; ++p) {
        for (int q = j; q < j + m; ++q) {
          if (a[p][q] != b[p - i][q - j]) {
            ok = false;
            break;
          }
        }
      }

      if (ok == true) {
        std::cout << i + 1 << " " << j + 1 << "\n";
        return 0;
      }
    }
  }
}
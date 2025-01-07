#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n), b(m);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < m; ++i) std::cin >> b[i];

  for (int i = 0; i < n - m + 1; ++i) {
    for (int j = 0; j < n - m + 1; ++j) {
      if (a[i][j] != b[0][0]) continue;
      auto f = [&]() -> bool {
        for (int k = i; k < i + m; ++k) {
          for (int l = j; l < j + m; ++l) {
            if (a[k][l] != b[k - i][l - j]) return false;
          }
        }
        return true;
      };

      bool ok = f();
      if (ok) {
        std::cout << "Yes\n";
        return 0;
      }
    }
  }

  std::cout << "No\n";
}
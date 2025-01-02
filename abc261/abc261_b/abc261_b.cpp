#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      bool ok = true;
      if (a[i][j] == 'D' && a[i][j] != a[j][i]) ok = false;
      if (a[i][j] != 'D' && a[i][j] == a[j][i]) ok = false;
      if (!ok) {
        std::cout << "incorrect\n";
        return 0;
      }
    }
  }

  std::cout << "correct\n";
}
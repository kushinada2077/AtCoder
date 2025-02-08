#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, x;
  std::cin >> n >> m;
  std::vector<bool> c(n + 1);
  for (int i = 0; i < m; ++i) {
    std::cin >> x;
    c[x] = true;
  }

  if (n == m) {
    std::cout << "0\n";
  } else {
    std::cout << n - m << "\n";
    for (int i = 1; i <= n; ++i) {
      if (c[i] == false) {
        std::cout << i << " \n"[i == n];
      }
    }
  }
}
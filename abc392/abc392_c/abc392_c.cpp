#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1), q(n + 1), rev(n + 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i + 1];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> q[i + 1];
    rev[q[i + 1]] = i + 1;
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << q[p[rev[i]]] << " \n"[i == n];
  }
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> c(n - 1), s(n - 1), f(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> c[i] >> s[i] >> f[i];
  }

  for (int st = 0; st < n - 1; ++st) {
    int u = st, time = 0;
    while (u != n - 1) {
      if (time <= s[u]) {
        time += s[u] - time + c[u];
      } else {
        if (time % f[u]) time += f[u] - (time % f[u]);
        time += c[u];
      }
      u++;
    }

    std::cout << time << "\n";
  }

  std::cout << 0 << "\n";
}
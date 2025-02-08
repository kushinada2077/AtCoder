#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> k(n + 1);
  std::vector c(n + 1, std::map<int, int>());
  for (int i = 0; i < n; ++i) {
    std::cin >> k[i + 1];
    for (int j = 0; j < k[i + 1]; ++j) {
      int x;
      std::cin >> x;
      c[i + 1][x]++;
    }
  }

  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      double t = 0;
      for (auto [kk, v] : c[i]) {
        if (!c[j].contains(kk)) continue;
        double p = (double)v / (double)(k[i]);
        double q = (double)c[j][kk] / (double)(k[j]);
        t += p * q;
      }

      ans = std::max(ans, t);
    }
  }

  std::cout.precision(10);
  std::cout << ans << "\n";
}
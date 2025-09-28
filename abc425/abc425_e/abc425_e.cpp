#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  const int MAX = 5001;
  int t, m;
  std::cin >> t >> m;

  std::vector binom(MAX, std::vector<int>(MAX, 0));
  binom[0][0] = 1;
  for (int i = 1; i < MAX; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j < MAX; ++j) {
      binom[i][j] = (1LL * binom[i - 1][j - 1] + binom[i - 1][j]) % m;
    }
  }

  auto solve = [&]() {
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> c[i];
    }

    int sum = 0, ans = 1;
    for (int i = 0; i < n; ++i) {
      sum += c[i];
      ans = (1LL * ans * binom[sum][c[i]]) % m;
    }

    std::cout << ans << "\n";
  };

  while (t--) {
    solve();
  }
}
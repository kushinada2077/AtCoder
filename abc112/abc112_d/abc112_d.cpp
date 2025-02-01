#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, m;
  std::cin >> n >> m;
  std::vector<int> d;
  for (int i = 1; i * i <= m; ++i) {
    if (m % i == 0) {
      d.push_back(i);
      if (i * i != m) {
        d.push_back(m / i);
      }
    }
  }

  sort(d.begin(), d.end(), std::greater<int>());
  for (auto i : d) {
    if (n * i <= m) {
      std::cout << i << "\n";
      return 0;
    }
  }
}
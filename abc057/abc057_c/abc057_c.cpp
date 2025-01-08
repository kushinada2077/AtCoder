#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n;
  std::cin >> n;
  std::vector<i64> d;
  for (i64 i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      d.push_back(i);
    }
  }

  int ans = 0;
  i64 b = std::max(d.back(), n / d.back());
  while (b) {
    b /= 10;
    ans++;
  }

  std::cout << ans << "\n";
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 a, b;
  std::cin >> a >> b;
  i64 g = std::gcd(a, b);

  i64 ans = 1;
  for (i64 i = 2; i * i <= g; ++i) {
    ans += g % i == 0;
    while (g % i == 0) {
      g /= i;
    }
  }

  ans += g != 1;
  std::cout << ans << "\n";
}
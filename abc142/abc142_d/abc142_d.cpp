#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 a, b;
  std::cin >> a >> b;
  i64 g = std::gcd(a, b);
  std::vector<bool> p(1000001, true);
  for (int i = 2; i * i <= 1000001; ++i) {
    if (!p[i]) continue;
    for (int j = i * i; j <= 1000001; j += i) {
      p[j] = false;
    }
  }

  i64 ans = 1;
  for (i64 i = 2; i * i <= g; ++i) {
    ans += g % i == 0 && p[i];
    while (g % i == 0) {
      g /= i;
    }
  }

  ans += g != 1;
  std::cout << ans << "\n";
}
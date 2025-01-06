#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 a, b, x, ans = 0;
  std::cin >> a >> b >> x;
  i64 st = a + (a % x ? (x - a % x) : 0);
  if (st <= b) {
    ans += 1 + (b - st) / x;
  }

  std::cout << ans << "\n";
}
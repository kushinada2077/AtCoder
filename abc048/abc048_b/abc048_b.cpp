#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 a, b, x, ans = 0;
  std::cin >> a >> b >> x;
  if (a % x == 0) ans++;
  a -= (a % x);
  ans += (b - a) / x;
  std::cout << ans << "\n";
}
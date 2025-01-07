#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 a, b, x;
  std::cin >> a >> b >> x;
  i64 ans = (b / x) - (std::max(0LL, a - 1) / x);
  if (a == 0) ans++;
  std::cout << ans << "\n";
}
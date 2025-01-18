#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 r;
  std::cin >> r;
  i64 ans = 4 * (r - 1) + 1;
  auto in = [&](i64 a, i64 b) { return (2 * a + 1) * (2 * a + 1) + (2 * b + 1) * (2 * b + 1) <= 4 * r * r; };
  i64 c = 0, y = r - 1;
  for (int x = 1; in(x, 1); ++x) {
    while (!in(x, y)) --y;
    c += y;
  }
  ans += 4 * c;
  std::cout << ans << "\n";
}
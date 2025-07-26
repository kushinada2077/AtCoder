#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 A, B, C, D;
  std::cin >> A >> B >> C >> D;
  i64 ans = B - A + 1, E = std::lcm(C, D);

  ans -= B / C;
  ans += (A - 1) / C;
  ans -= B / D;
  ans += (A - 1) / D;
  ans += B / E;
  ans -= (A - 1) / E;
  std::cout << ans << "\n";
}
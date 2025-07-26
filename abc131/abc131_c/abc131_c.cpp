#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 A, B, C, D;
  std::cin >> A >> B >> C >> D;
  i64 E = std::lcm(C, D);
  i64 restB = B / C + B / D - B / E, restA = (A - 1) / C + (A - 1) / D - (A - 1) / E;
  i64 ans = B - A + 1 - (restB - restA);
  std::cout << ans << "\n";
}
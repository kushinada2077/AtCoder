#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int l1, r1, l2, r2;
  std::cin >> l1 >> r1 >> l2 >> r2;
  l1 = std::max(l1, l2);
  r1 = std::min(r1, r2);
  std::cout << std::max(0, r1 - l1) << "\n";
}
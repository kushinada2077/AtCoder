#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int X, C;
  std::cin >> X >> C;

  int ans = X / (C + 1000);
  std::cout << ans * 1000 << "\n";
}
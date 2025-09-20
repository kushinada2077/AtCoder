#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  i64 a, b, c;
  std::cin >> a >> b >> c;
  std::cout << std::min({a, c, (a + b + c) / 3}) << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
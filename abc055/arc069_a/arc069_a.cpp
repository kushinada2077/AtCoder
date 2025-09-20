#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N, M;
  std::cin >> N >> M;
  i64 ans = std::min(M / 2, N);
  M -= 2 * ans;
  ans += M / 4;
  std::cout << ans << "\n";
}
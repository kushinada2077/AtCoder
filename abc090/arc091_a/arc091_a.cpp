#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N, M;
  std::cin >> N >> M;
  i64 ans = N * M;
  if (N == 1 && M == 1) {
    ans = 1;
  } else if (N == 1 || M == 1) {
    ans -= 2;
  } else {
    ans -= 2 * (N + M) - 4;
  }
  std::cout << ans << "\n";
}
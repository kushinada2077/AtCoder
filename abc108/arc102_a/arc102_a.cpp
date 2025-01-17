#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  i64 c = n / k;
  i64 ans = c * c * c;
  if (k % 2 == 0) {
    i64 d = 0;
    for (int i = 1; i <= n; ++i) {
      d += (i % k) == (k / 2);
    }
    ans += d * d * d;
  }

  std::cout << ans << "\n";
}
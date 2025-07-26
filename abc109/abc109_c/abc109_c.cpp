#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, X, ans = 0;
  std::cin >> N >> X;
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    ans = std::gcd(ans, std::abs(x - X));
  }

  std::cout << ans << "\n";
}
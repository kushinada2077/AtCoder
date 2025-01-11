#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i];
  }
  int ans = INT_MAX;
  for (int i = 0; i < n - k + 1; ++i) {
    int la = x[i], ra = x[i + k - 1];
    if (la < 0 && ra < 0) {
      ans = std::min(ans, -la);
    } else if (la > 0 && ra > 0) {
      ans = std::min(ans, ra);
    } else {
      ans = std::min(ans, 2 * std::min(-la, ra) + std::max(-la, ra));
    }
  }

  std::cout << ans << "\n";
}
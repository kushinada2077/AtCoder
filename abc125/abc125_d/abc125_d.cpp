#include <bits/stdc++.h>
using i64 = long long;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, s = 0, z = 0;
  i64 ans = 0;
  std::cin >> n;
  std::vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ans += std::abs(a[i]);
    z += a[i] == 0;
    s += a[i] < 0;
    if (a[i] < 0) a[i] *= -1;
  }

  if (!z && s % 2) {
    ans -= 2 * *min_element(a.begin(), a.end());
  }

  std::cout << ans << "\n";
}
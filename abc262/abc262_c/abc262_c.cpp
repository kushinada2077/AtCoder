#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, p = 0;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (i + 1 == a[i]) p++;
  }

  p = std::max(p - 1, 0);
  i64 ans = 1LL * (1 + p) * p / 2;

  for (int i = 0; i < n; ++i) {
    if (i + 1 < a[i] && a[a[i] - 1] == i + 1) ans++;
  }

  std::cout << ans << "\n";
}
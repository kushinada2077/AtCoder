#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  i64 k;
  std::cin >> n >> k;
  std::vector<i64> a(n), pref(n + 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    pref[i + 1] = pref[i] + a[i];
  }

  i64 ans = 0;
  for (int i = 0, j = 0; i <= n;) {
    for (; j <= n && pref[j] - pref[i] < k; ++j);
    if (pref[j] - pref[i] < k) break;
    ans += n - j + 1;
    i++;
  }

  std::cout << ans << "\n";
}
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
  for (int i = 1; i <= n; ++i) {
    if (pref[i] < k) continue;
    int j = std::upper_bound(pref.begin(), pref.end(), pref[i] - k) - pref.begin();
    if (j == n + 1) continue;
    ans += j;
  }

  std::cout << ans << "\n";
}
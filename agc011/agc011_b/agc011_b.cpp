#include <bits/stdc++.h>
using i64 = long long;

bool ok(int idx, std::vector<i64>& a) {
  int n = a.size();
  i64 siz = a[idx];
  for (int i = 0; i < n; ++i) {
    if (i == idx) continue;
    if (2 * siz < a[i]) return false;
    siz += a[i];
  }

  return true;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  sort(a.begin(), a.end());
  int lo = 0, hi = a.back();
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    int idx = lower_bound(a.begin(), a.end(), mid) - a.begin();
    if (ok(idx, a)) hi = mid;
    else lo = mid;
  }

  int ans = a.end() - lower_bound(a.begin(), a.end(), hi);
  std::cout << ans << "\n";
}
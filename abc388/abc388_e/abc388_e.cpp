#include <bits/stdc++.h>
using i64 = long long;

bool ok(int k, std::vector<int>& a) {
  int n = a.size();
  for (int i = 0; i < k; ++i) {
    if (2 * a[i] > a[n - k + i]) {
      return false;
    }
  }
  return true;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int lo = 0, hi = n / 2 + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (ok(mid, a)) lo = mid;
    else hi = mid;
  }

  std::cout << lo << "\n";
}
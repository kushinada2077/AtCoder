#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<i64> a(n), dt(n + 2), ans(n + 2);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  i64 d = 0;
  for (int i = 0; i < n; ++i) {
    d += dt[i];
    i64 cur = a[i] + d;
    ans[i] = cur;
    if (cur > 0) {
      d++;
      if (i + cur + 1 < n + 2) dt[i + cur + 1]--;
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << std::max(0LL, ans[i] - (n - i - 1)) << " \n"[i == n - 1];
  }
}
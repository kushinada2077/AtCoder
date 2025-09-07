#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      ans[i / 2] = a[n - 1 - i];
    } else {
      ans[n - 1 - i / 2] = a[n - 1 - i];
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << " \n"[i == n - 1];
  }
}
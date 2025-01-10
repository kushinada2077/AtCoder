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
  std::sort(a.begin(), a.end());
  int i = std::lower_bound(a.begin(), a.end(), a.back() / 2) - a.begin();
  if (i == n - 1 || i - 1 >= 0 && std::abs(a[i - 1] - a.back() / 2) < std::abs(a[i] - a.back() / 2)) {
    i = i - 1;
  }

  std::cout << a.back() << " " << a[i] << "\n";
}
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
  int x = a.back(), j = -1;
  for (int i = 0; i < n - 1; ++i) {
    if (j == -1 || std::abs(x - 2 * a[i]) < std::abs(x - 2 * a[j])) {
      j = i;
    }
  }

  std::cout << x << " " << a[j] << "\n";
}
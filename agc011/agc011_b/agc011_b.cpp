#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  sort(a.begin(), a.end());
  i64 sum = 0;
  int k = 0;
  for (int i = 0; i < n - 1; ++i) {
    sum += a[i];
    if (2 * sum < a[i + 1]) {
      k = i + 1;
    }
  }

  std::cout << n - k << "\n";
}
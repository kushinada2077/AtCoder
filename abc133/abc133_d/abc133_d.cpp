#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<i64> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  i64 res = 0;
  for (int i = 0; i < n; ++i) {
    int d = i % 2 ? -1 : 1;
    res += d * a[i];
  }

  b[0] = res;
  for (int i = 1; i < n; ++i) {
    b[i] = 2 * a[i - 1] - b[(i + n - 1) % n];
  }

  for (int i = 0; i < n; ++i) {
    std::cout << b[i] << " ";
  }
}
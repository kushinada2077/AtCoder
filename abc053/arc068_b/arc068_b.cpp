#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::map<int, int> c;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    c[a[i]]++;
  }

  for (auto [k, v] : c) {
    if (v > 2) {
      c[k] = 1 + !(c[k] % 2);
    }
  }
  int one = 0, two = 0;
  for (auto [k, v] : c) {
    if (v == 1) {
      one++;
    } else {
      two++;
    }
  }

  if (two % 2 == 1) {
    two--;
  }

  int ans = two + one;
  std::cout << ans << "\n";
}
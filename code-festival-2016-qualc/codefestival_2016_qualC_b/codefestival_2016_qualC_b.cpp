#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int k, t, ans = 0;
  std::cin >> k >> t;
  std::vector<int> a(t);
  for (int i = 0; i < t; ++i) {
    std::cin >> a[i];
  }

  int max = *max_element(a.begin(), a.end());
  std::cout << std::max(max - 1 - (k - max), 0);
}
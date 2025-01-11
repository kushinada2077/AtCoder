#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, d;
  std::cin >> n >> d;
  std::vector<int> t(n), l(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> t[i] >> l[i];
  }

  for (int i = 1; i <= d; ++i) {
    int max = 0;
    for (int j = 0; j < n; ++j) {
      max = std::max(max, (i + l[j]) * t[j]);
    }

    std::cout << max << "\n";
  }
}
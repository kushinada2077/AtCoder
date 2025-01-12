#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n), d(n + 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += d[i];
    a[i] += cnt;
    cnt++;
    d[std::min(n, i + a[i] + 1)]--;
  }

  for (int i = 0; i < n; ++i) {
    std::cout << std::max(0, a[i] - n + i + 1) << " ";
  }
}
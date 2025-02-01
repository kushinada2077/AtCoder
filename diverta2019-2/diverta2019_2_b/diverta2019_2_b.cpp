#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::map<int, std::map<int, int>> c;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first >> a[i].second;
  }

  int max = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int dx = a[j].first - a[i].first;
      int dy = a[j].second - a[i].second;
      c[dx][dy]++;
      max = std::max(max, c[dx][dy]);
    }
  }

  std::cout << n - max << "\n";
}
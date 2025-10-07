#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> cnt(N + 1, 1);
  cnt[0] = 0;
  int cur = 0;
  for (int i = 0; i < Q; ++i) {
    int x, y;
    std::cin >> x >> y;
    if (cur > x) {
      std::cout << "0\n";
      continue;
    }
    int o = 0;
    for (int j = cur; j <= x; ++j) {
      o += cnt[j];
    }

    cur = x + 1;
    cnt[y] += o;

    std::cout << o << "\n";
  }
}
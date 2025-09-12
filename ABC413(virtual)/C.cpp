#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int Q;
  std::cin >> Q;
  std::deque<std::pair<int, int>> dq;
  for (int i = 0; i < Q; ++i) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int c, x;
      std::cin >> c >> x;
      dq.push_back({x, c});
    } else if (op == 2) {
      int k;
      std::cin >> k;
      i64 sum = 0;
      while (k > 0) {
        auto [x, c] = dq.front();
        dq.pop_front();
        if (k >= c) {
          sum += 1LL * x * c;
          k -= c;
        } else {
          sum += 1LL * k * x;
          dq.push_front({x, c - k});
          k = 0;
        }
      }
      std::cout << sum << "\n";
    }
  }
}
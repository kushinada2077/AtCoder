#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  std::cin >> q;
  std::deque<std::pair<i64, i64>> dq;
  i64 d = 0;
  for (int i = 0; i < q; ++i) {
    int t;
    std::cin >> t;
    if (t == 1) {
      i64 l;
      std::cin >> l;
      if (dq.empty()) {
        dq.push_back({0, l});
      } else {
        dq.push_back({dq.back().first + dq.back().second, l});
      }
    } else if (t == 2) {
      d += dq.front().second;
      dq.pop_front();
    } else if (t == 3) {
      int k;
      std::cin >> k;
      std::cout << dq[k - 1].first - d << "\n";
    }
  }
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int Q;
  std::cin >> Q;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i = 0; i < Q; ++i) {
    int q;
    std::cin >> q;
    if (q == 1) {
      int x;
      std::cin >> x;
      pq.push(x);
    } else {
      std::cout << pq.top() << "\n";
      pq.pop();
    }
  }
}
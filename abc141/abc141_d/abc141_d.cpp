#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    pq.push(x);
  }

  for (int i = 0; i < m; ++i) {
    int x = pq.top();
    pq.pop();
    pq.push(x / 2);
  }

  i64 ans = 0;
  while (!pq.empty()) {
    ans += 1LL * pq.top();
    pq.pop();
  }

  std::cout << ans << "\n";
}
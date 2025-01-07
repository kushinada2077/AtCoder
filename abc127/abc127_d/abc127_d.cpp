#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  i64 ans = 0;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    pq.push(x);
    ans += 1LL * x;
  }

  std::vector<std::pair<int, int>> query(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> query[i].second >> query[i].first;
  }

  sort(query.begin(), query.end(), std::greater<std::pair<int, int>>());
  for (int i = 0; i < m; ++i) {
    auto [c, b] = query[i];
    while (!pq.empty() && b-- && pq.top() < c) {
      ans += c - pq.top();
      pq.pop();
    }
  }

  std::cout << ans << "\n";
}
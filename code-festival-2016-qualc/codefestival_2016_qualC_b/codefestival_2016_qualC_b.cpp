#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, t, ans = 0;
  std::cin >> n >> t;
  std::vector<int> a(t);
  std::priority_queue<std::pair<int, int>> pq;
  for (int i = 0; i < t; ++i) {
    std::cin >> a[i];
    pq.push({a[i], i});
  }
  int pre = -1;

  while (!pq.empty()) {
    auto [num, v] = pq.top();
    pq.pop();

    if (pre == v) {
      if (!pq.empty()) {
        auto [nnum, nv] = pq.top();
        pq.pop();
        pq.push({num, v});
        if (nnum > 1) pq.push({nnum - 1, nv});
        pre = nv;
      } else {
        ans++;
        if (num > 1) pq.push({num - 1, v});
      }
    } else {
      if (num > 1) pq.push({num - 1, v});
      pre = v;
    }
  }

  std::cout << ans << "\n";
}
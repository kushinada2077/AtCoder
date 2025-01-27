#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, h;
  std::cin >> n >> h;
  std::priority_queue<std::pair<int, bool>> pq;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    pq.push({a, 0});
    pq.push({b, 1});
  }

  int ans = 0;
  while (!pq.empty() && h > 0) {
    auto [d, t] = pq.top();
    pq.pop();
    if (t == 0) {
      ans += (h + d - 1) / d;
      h = 0;
    } else {
      ans++;
      h -= d;
    }
  }

  std::cout << ans << "\n";
}
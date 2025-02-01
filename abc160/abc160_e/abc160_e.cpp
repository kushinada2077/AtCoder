#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int x, y;
  i64 a, b, c;
  std::cin >> x >> y >> a >> b >> c;
  std::vector<i64> t = {a, b, c};
  std::priority_queue<std::pair<int, int>> pq;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < t[i]; ++j) {
      int x;
      std::cin >> x;
      pq.push({x, i});
    }
  }

  i64 ans = 0;
  int cnt = 0;
  while (!pq.empty() && (x != 0 || y != 0) && cnt < x + y) {
    auto [w, tt] = pq.top();
    pq.pop();
    if (tt == 0 && x > 0) {
      x--;
      ans += w;
    } else if (tt == 1 && y > 0) {
      y--;
      ans += w;
    } else if (tt == 2) {
      cnt++;
      ans += w;
    }
  }

  std::cout << ans << "\n";
}
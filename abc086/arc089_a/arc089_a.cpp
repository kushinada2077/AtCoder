#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  int cur_x = 0, cur_y = 0, cur_t = 0;
  for (int i = 0; i < N; ++i) {
    int t, x, y;
    std::cin >> t >> x >> y;
    int d = (t - cur_t) - (abs(x - cur_x) + abs(y - cur_y));
    if (d < 0 || (d % 2 == 1)) {
      std::cout << "No\n";
      return 0;
    }
    cur_x = x;
    cur_y = y;
    cur_t = t;
  }

  std::cout << "Yes\n";
}
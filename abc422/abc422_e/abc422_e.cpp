#include <bits/stdc++.h>
using i64 = long long;

std::mt19937_64 rng(58);
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<i64> x(N), y(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> x[i] >> y[i];
  }

  int T = 100;
  while (T--) {
    int c1, c2;
    do {
      c1 = rng() % N, c2 = rng() % N;
    } while (c1 == c2);

    i64 x1 = x[c1], y1 = y[c1];
    i64 x2 = x[c2], y2 = y[c2];
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      cnt += (x1 - x2) * y[i] + (y2 - y1) * x[i] + x2 * y1 - x1 * y2 == 0LL;
    }
    if (2 * cnt > N) {
      std::cout << "Yes\n";
      std::cout << y2 - y1 << " " << x1 - x2 << " " << x2 * y1 - x1 * y2 << "\n";
      return 0;
    }
  }

  std::cout << "No\n";
}
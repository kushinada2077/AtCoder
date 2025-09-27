#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  int ans = 0;
  std::cin >> N;
  for (int i = 1; i <= N; ++i) {
    ans += i * i * i * (i % 2 == 1 ? -1 : 1);
  }

  std::cout << ans << "\n";
}
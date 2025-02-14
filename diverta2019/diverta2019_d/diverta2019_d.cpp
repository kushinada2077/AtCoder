#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N, ans = 0;
  std::cin >> N;
  for (i64 p = 1; p * p < N; ++p) {
    if (N % p == 0) {
      i64 m = N / p - 1;
      if (m > 0 && N / m == N % m) {
        ans += m;
      }
    }
  }

  std::cout << ans << "\n";
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int R, G, B, N, ans = 0;
  std::cin >> R >> G >> B >> N;

  for (int i = 0; i <= 3000; ++i) {
    for (int j = 0; j <= 3000; ++j) {
      int rest = N - (R * i + G * j);
      if (rest >= 0 && rest % B == 0) {
        ans++;
      }
    }
  }
  std::cout << ans << "\n";
}
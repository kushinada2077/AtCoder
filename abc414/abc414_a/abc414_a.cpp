#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, L, R;
  std::cin >> N >> L >> R;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int x, y;
    std::cin >> x >> y;
    ans += (x <= L) && (R <= y);
  }

  std::cout << ans << "\n";
}
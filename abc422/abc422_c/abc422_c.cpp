#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  int A, B, C;
  std::cin >> A >> B >> C;
  int min = std::min(A, C);
  int ans = B;
  if (min > B) {
    A -= B;
    C -= B;
    if (A > C) std::swap(A, C);
    if (2 * A <= C) {
      ans += A;
    } else {
      ans += C / 2;
      A -= C / 2;
      C %= 2;
      if (C == 1 && A > 1) {
        A -= 2;
        ans++;
      }
      if (A > 0) {
        ans += A / 3;
      }
    }
  } else {
    ans = min;
  }
  std::cout << ans << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    solve();
  }
}
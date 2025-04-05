#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int A, B;
  std::cin >> A >> B;
  if (B == 1) {
    std::cout << "0\n";
    return 0;
  }
  B -= A;
  int ans = 1;
  A--;

  if (B > 0) {
    ans += (B + A - 1) / A;
  }
  std::cout << ans << "\n";
}
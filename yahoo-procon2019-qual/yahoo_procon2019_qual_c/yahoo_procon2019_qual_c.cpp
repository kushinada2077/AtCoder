#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 K, A, B, ans = 1;
  std::cin >> K >> A >> B;
  if (A + 1 < B) {
    int d = std::min(A - 1, K);
    ans += d;
    K -= d;
    d = K / 2;
    ans += (B - A) * d;
    if (K % 2) ans++;
  } else {
    ans += K;
  }
  std::cout << ans << "\n";
}
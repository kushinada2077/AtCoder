#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using mint = atcoder::modint1000000007;

mint my_pow(mint n, i64 r) {
  if (r == 0) return mint(1);
  if (r % 2 == 1) return n * my_pow(n, r - 1);
  mint half = my_pow(n, r / 2);
  return (half * half);
}
mint inv(int n) { return my_pow(n, 1e9 + 5); }
mint com(i64 n, i64 r) {
  mint ret = 1;
  if (n - r > r) {
    for (int i = n - r + 1; i <= n; ++i) {
      ret *= i;
    }
    for (int i = 2; i <= r; ++i) {
      ret *= inv(i);
    }
  } else {
    for (i64 i = r + 1; i <= n; ++i) {
      ret *= i;
    }
    for (int i = 2; i <= n - r; ++i) {
      ret *= inv(i);
    }
  }

  return ret;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, a, b;
  std::cin >> n >> a >> b;
  mint ans = my_pow(2, n) - 1;
  ans -= com(n, a);
  ans -= com(n, b);
  std::cout << ans.val() << "\n";
}
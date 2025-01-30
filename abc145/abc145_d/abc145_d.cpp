#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using mint = atcoder::modint1000000007;

mint comb(i64 n, i64 r, std::vector<int>& f) {
  mint ret = f[n];
  return ret * mint(f[r]).inv() * mint(f[n - r]).inv();
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int x, y;
  std::cin >> x >> y;
  if ((x + y) % 3 != 0) {
    std::cout << "0\n";
    return 0;
  }
  std::vector<int> f(x + y + 1);
  f[0] = f[1] = 1;
  for (int i = 2; i <= x + y + 1; ++i) {
    f[i] = (1LL * i * f[i - 1]) % 1000000007;
  }
  int n = (2 * y - x) / 3;
  int m = (x - n) / 2;
  if (n < 0 || m < 0) {
    std::cout << "0\n";
    return 0;
  }

  mint ans = comb(n + m, n, f);
  std::cout << ans.val() << "\n";
}
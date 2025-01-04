#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using mint = atcoder::modint998244353;

constexpr int M = 998244353;
mint my_pow(int n, int r) {
  if (n == 0) return mint(0);
  if (r == 0) return mint(1);
  if (r % 2) return n * my_pow(n, r - 1);
  mint half = my_pow(n, r / 2);
  return half * half;
}
mint nCr(int n, int r, std::vector<mint>& f) {
  if (n < r) return 0;
  mint np = f[n], rp = f[r], nrp = f[n - r];
  return np * my_pow(rp.val(), M - 2) * my_pow(nrp.val(), M - 2);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> deg(n + 1, 0);
  std::vector<mint> f(n + 1);
  f[0] = 1;
  mint t = 1;
  for (int i = 1; i <= n; ++i) {
    t *= i;
    f[i] = t;
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    deg[u]++;
    deg[v]++;
  }

  int odd = 0;
  for (int i = 1; i <= n; ++i) odd += deg[i] % 2;
  int even = n - odd;
  mint ans = 0;
  for (int i = 0; i <= k; i += 2) {
    if (odd < i) break;
    ans += nCr(odd, i, f) * nCr(even, k - i, f);
  }

  std::cout << ans.val() << "\n";
}
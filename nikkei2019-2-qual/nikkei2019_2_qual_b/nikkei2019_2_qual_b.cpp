#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<mint> c(n);
  for (int i = 0; i < n; ++i) {
    int d;
    std::cin >> d;
    if (i == 0 && d != 0) {
      std::cout << "0\n";
      return 0;
    }
    c[d]++;
  }

  if (c[0] != 1) {
    std::cout << "0\n";
    return 0;
  }
  mint ans = 1;
  for (int i = 1; i < n; ++i) {
    ans *= c[i - 1].pow(c[i].val());
  }

  std::cout << ans.val() << "\n";
}
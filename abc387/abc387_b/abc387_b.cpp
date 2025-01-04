#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using mint = atcoder::modint998244353;

int a[10][10];
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int x, ans = 0;
  std::cin >> x;
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (i * j != x) ans += i * j;
    }
  }

  std::cout << ans << "\n";
}
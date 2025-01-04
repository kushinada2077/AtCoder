#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int a, b;
  std::cin >> a >> b;
  std::cout << ((a + b) * (a + b)) << "\n";
}
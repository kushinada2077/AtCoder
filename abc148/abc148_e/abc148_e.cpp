#include <bits/stdc++.h>
using i64 = long long;

i64 f(i64 n) {
  if (n % 2) return 0;
  i64 d = 10, ret = 0;
  while (d <= n) {
    ret += n / d;
    d *= 5;
  }

  return ret;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n;
  std::cin >> n;
  std::cout << f(n) << "\n";
}
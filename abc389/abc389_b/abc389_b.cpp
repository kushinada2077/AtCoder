#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 x;
  std::cin >> x;
  i64 n = 1, d = 1;

  while (n != x) {
    d++;
    n *= d;
  }

  std::cout << d << "\n";
}
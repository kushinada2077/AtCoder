#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a == b || a == c || b == c) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
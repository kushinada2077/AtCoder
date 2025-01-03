#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int x;
  std::cin >> x;
  while (x % 4 != 2) x++;
  std::cout << x << "\n";
}
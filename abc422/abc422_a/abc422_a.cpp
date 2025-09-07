#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  int a, b;
  std::cin >> s;
  a = s[0] - '0';
  b = s[2] - '0';
  a += b == 8;
  b += 1;
  if (b == 9) b = 1;
  std::cout << a << "-" << b << "\n";
}
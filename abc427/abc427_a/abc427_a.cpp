#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int n = (int)s.size();
  for (int i = 0; i < n; ++i) {
    if (i == n / 2) continue;
    std::cout << s[i];
  }
}
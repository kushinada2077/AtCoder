#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::map<std::string, int> f;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    int x = f[s]++;
    std::cout << s;
    if (x) std::cout << "(" << x << ")";
    std::cout << "\n";
  }
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s, t;
  std::cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), std::greater<char>());
  if (s < t) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
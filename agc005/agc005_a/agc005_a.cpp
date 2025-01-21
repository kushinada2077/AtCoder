#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string x;
  std::cin >> x;
  int n = x.size();
  std::list<char> l(x.begin(), x.end());
  auto it = l.begin();
  while (next(it) != l.end()) {
    std::string s(1, *it);
    s += *next(it);
    if (s == "ST") {
      it = l.erase(it);
      it = l.erase(it);
      if (it != l.begin()) {
        it = prev(it);
      }
    } else {
      it = next(it);
    }
  }
  std::cout << l.size() << "\n";
}
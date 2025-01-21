#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string x;
  std::cin >> x;
  int n = x.size(), ans = n;
  std::stack<char> s;
  for (int i = 0; i < n; ++i) {
    if (!s.empty() && s.top() == 'S' && x[i] == 'T') {
      ans -= 2;
      s.pop();
    } else {
      s.push(x[i]);
    }
  }
  std::cout << ans << "\n";
}
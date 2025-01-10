#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s, t;
  std::cin >> s >> t;
  int n = s.size();
  std::vector<std::set<char>> c(26), d(26);
  for (int i = 0; i < n; ++i) {
    c[s[i] - 'a'].insert(t[i]);
    d[t[i] - 'a'].insert(s[i]);
  }

  for (int i = 0; i < 26; ++i) {
    if (c[i].size() > 1 || d[i].size() > 1) {
      std::cout << "No\n";
      return 0;
    }
  }

  std::cout << "Yes\n";
}
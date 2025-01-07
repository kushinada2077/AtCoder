#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s, t;
  std::cin >> s >> t;
  int n = s.size(), m = t.size();

  for (int i = n - 1; i >= 0; --i) {
    bool ok = true;
    int j;
    for (j = i; j < i + m; ++j) {
      if (j >= n || (s[j] != '?' && s[j] != t[j - i])) {
        ok = false;
        break;
      }
    }

    if (ok) {
      for (j = i; j < i + m; ++j) {
        s[j] = t[j - i];
      }
      for (int k = 0; k < n; ++k) {
        if (s[k] == '?') s[k] = 'a';
      }

      std::cout << s << "\n";
      return 0;
    }
  }

  std::cout << "UNRESTORABLE\n";
}
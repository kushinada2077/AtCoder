#include <bits/stdc++.h>
using i64 = long long;

bool pal(int s, int e, const std::string& t) {
  if (e <= s) return true;
  if (t[s] != t[e]) return false;
  return pal(s + 1, e - 1, t);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s, nox = "";
  std::cin >> s;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'x') {
      nox += s[i];
    }
  }

  if (!pal(0, (int)nox.size() - 1, nox)) {
    std::cout << "-1\n";
    return 0;
  }

  int ans = 0;
  for (int h = 0, e = n - 1; h < e;) {
    if (s[h] == s[e]) {
      h++;
      e--;
    } else if (s[h] == 'x') {
      h++;
      ans++;
    } else if (s[e] == 'x') {
      e--;
      ans++;
    }
  }

  std::cout << ans << "\n";
}
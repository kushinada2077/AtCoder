#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, ans = 0, pre = 0, suf = 0, both = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    int m = s.size();
    for (int j = 0; j < m - 1; ++j) {
      ans += s[j] == 'A' && s[j + 1] == 'B';
    }
    if (s.front() == 'B' && s.back() == 'A') both++;
    else if (s.front() == 'B') pre++;
    else if (s.back() == 'A') suf++;
  }

  if (both) {
    if (pre || suf) ans += both + std::min(pre, suf);
    else ans += both - 1;
  } else {
    ans += std::min(pre, suf);
  }

  std::cout << ans << "\n";
}
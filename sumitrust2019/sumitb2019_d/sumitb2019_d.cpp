#include <bits/stdc++.h>
using i64 = long long;

bool ok(const std::string& s, const std::string& t) {
  int n = s.size(), m = t.size();
  for (int i = 0, j = 0; i < n; ++i) {
    for (; j < m && s[i] != t[j]; ++j);
    if (j == m) return false;
    ++j;
  }

  return true;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  i64 ans = 0;
  std::string s;
  std::cin >> n >> s;
  for (int i = 0; i < 1000; ++i) {
    std::string a(3, ' ');
    a[0] = i / 100 + '0';
    a[1] = i / 10 % 10 + '0';
    a[2] = i % 10 + '0';
    ans += ok(a, s);
  }

  std::cout << ans << "\n";
}
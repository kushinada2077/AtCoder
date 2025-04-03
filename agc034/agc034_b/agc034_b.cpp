#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s, ns = "";
  std::cin >> s;
  int n = s.size();
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == 'B' && s[i + 1] == 'C') {
      ns += 'D';
      i++;
    } else {
      ns += s[i];
    }
  }

  i64 ans = 0;
  n = ns.size();
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (ns[i] == 'A') {
      cnt++;
    } else if (ns[i] == 'D') {
      ans += cnt;
    } else {
      cnt = 0;
    }
  }

  std::cout << ans << "\n";
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int n = s.size();
  i64 cnt = 0, ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == 'A') {
      cnt++;
    } else if (s[i] == 'B' && s[i + 1] == 'C') {
      ans += cnt;
      i++;
    } else {
      cnt = 0;
    }
  }

  std::cout << ans << "\n";
}
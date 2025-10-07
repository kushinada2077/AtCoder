#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int cnt(int n, std::string& s, char target) {
  int len = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == target) cnt++;
    else cnt = 0;
    len = std::max(len, cnt);
  }

  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret++;
    if (target == s[i]) ret++;
  }

  return ret - 2 * len;
}
void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int zero = cnt(n, s, '0');
  int one = cnt(n, s, '1');

  std::cout << std::min(zero, one) << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}
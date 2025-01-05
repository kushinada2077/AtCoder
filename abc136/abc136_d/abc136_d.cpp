#include <bits/stdc++.h>
using i64 = long long;

std::vector<int> split(std::string& s) {
  int n = s.size(), j = 0;
  std::vector<int> ret(n);
  for (int i = 1; i < n; ++i) {
    if (s[i] == 'L' && s[i - 1] == 'R') {
      int l = i, r = i - 1;
      while (i < n && s[i] == 'L') i++;
      for (int k = j; k < i; ++k) {
        ret[std::array{l, r}[abs(l - k) % 2]]++;
      }
      j = i;
    }
  }

  return ret;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  std::vector<int> ans = split(s);
  for (auto i : ans) std::cout << i << " ";
}
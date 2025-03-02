#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int k, len = s.size();
  std::cin >> k;
  for (int i = 0; i < len; ++i) {
    if (s[i] != 'a' && 26 - (s[i] - 'a') <= k) {
      k -= 26 - (s[i] - 'a');
      s[i] = 'a';
    }
  }

  k %= 26;
  s[len - 1] = (s[len - 1] - 'a' + k) % 26 + 'a';
  std::cout << s << "\n";
}
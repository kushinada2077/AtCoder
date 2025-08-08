#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;

  int ans = 0x3f3f3f3f;
  for (int i = 0; i < 26; ++i) {
    char t = 'a' + i;
    std::string p(s);

    while (true) {
      int sz = (int)p.size() - 1;
      std::vector<bool> chk(26);
      for (auto c : p) {
        chk[c - 'a'] = true;
      }
      if (std::accumulate(chk.begin(), chk.end(), 0) == 1) {
        ans = std::min(ans, (int)s.size() - (int)p.size());
        break;
      }

      for (int j = 0; j < sz; ++j) {
        if (p[j] == t || p[j + 1] == t) {
          p[j] = t;
        }
      }
      p.pop_back();
    }
  }

  std::cout << ans << "\n";
}
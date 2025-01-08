#include <bits/stdc++.h>
using i64 = long long;

std::vector<std::string> split(const std::string& s) {
  int n = s.size();
  std::vector<std::string> ret;
  for (int i = 0, j = 0; i < n; i = j) {
    std::string t = "";
    for (; j < n && s[i] == s[j]; ++j) {
      t += s[j];
    }
    ret.push_back(t);
  }

  return ret;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s, t;
  std::cin >> s >> t;
  std::vector<std::string> sb = split(s), tb = split(t);

  if (sb.size() != tb.size()) {
    std::cout << "No\n";
    return 0;
  }

  int n = sb.size();

  for (int i = 0; i < n; ++i) {
    bool ok = true;
    if (sb[i][0] != tb[i][0]) {
      ok = false;
    } else if (sb[i].size() == 1 && tb[i].size() > 1 || sb[i].size() > 1 && tb[i].size() < sb[i].size()) {
      ok = false;
    }

    if (!ok) {
      std::cout << "No\n";
      return 0;
    }
  }

  std::cout << "Yes\n";
}
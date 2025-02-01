#include <bits/stdc++.h>
using i64 = long long;

std::string solve(const std::string& s) {
  if (s == "N") return "S";
  if (s == "S") return "N";
  if (s == "E") return "W";
  if (s == "W") return "E";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;

  std::string ans = "";
  for (int i = 0; i < s.size(); ++i) {
    ans += solve(std::string(1, s[i]));
  }

  std::cout << ans << "\n";
}
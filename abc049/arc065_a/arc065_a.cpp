#include <bits/stdc++.h>
using i64 = long long;

bool ok(const std::string& s, int i, int l) {
  if (i == -1) return l == 1;
  if (l > 7) return false;
  if (l == 5 && (s.substr(i, l) == "dream" || s.substr(i, l) == "erase")) return ok(s, i, 0);
  if (l == 6 && s.substr(i, l) == "eraser") return ok(s, i, 0);
  if (l == 7 && s.substr(i, l) == "dreamer") return ok(s, i, 0);
  return ok(s, i - 1, l + 1);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int n = s.size();
  std::cout << (ok(s, n, 0) ? "YES" : "NO") << "\n";
}
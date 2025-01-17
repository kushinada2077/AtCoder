#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector<int> b(n + 1);
  for (int i = 0; i < n; ++i) {
    b[i + 1] = b[i] + (s[i] == '#');
  }

  int ans = std::min(b[n], n - b[n]);
  for (int i = 0; i < n; ++i) {
    ans = std::min(ans, b[i + 1] + n - i - 1 - (b[n] - b[i + 1]));
  }

  std::cout << ans << "\n";
}
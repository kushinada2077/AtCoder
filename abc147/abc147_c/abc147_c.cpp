#include <bits/stdc++.h>
using i64 = long long;

void solve(int n, int k, int& ans, std::vector<std::vector<std::pair<int, int>>>& t, std::vector<bool>& s) {
  if (n == k) {
    for (int i = 0; i < n; ++i) {
      for (auto [x, y] : t[i]) {
        if (s[i] == true && y != s[x]) return;
      }
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
      c += s[i] == true;
    }
    ans = std::max(ans, c);
    return;
  }

  s[k] = false;
  solve(n, k + 1, ans, t, s);
  s[k] = true;
  solve(n, k + 1, ans, t, s);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, ans = 0;
  std::cin >> n;
  std::vector t(n, std::vector<std::pair<int, int>>());
  std::vector<bool> s(n);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    for (int j = 0; j < a; ++j) {
      int x, y;
      std::cin >> x >> y;
      t[i].push_back({x - 1, y});
    }
  }

  solve(n, 0, ans, t, s);
  std::cout << ans << "\n";
}
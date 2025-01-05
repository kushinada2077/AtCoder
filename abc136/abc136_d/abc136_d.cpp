#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int n = s.size();
  std::vector f(333, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') f[0][i] = i + 1;
    else f[0][i] = i - 1;
  }

  for (int k = 1; k < 333; ++k) {
    for (int i = 0; i < n; ++i) {
      f[k][i] = f[k - 1][f[k - 1][i]];
    }
  }

  std::vector<int> ans(n, 0);
  for (int i = 0; i < n; ++i) {
    int c = i;
    for (int k = 100; k < 333; ++k) {
      c = f[k][c];
    }

    ans[c]++;
  }

  for (auto i : ans) std::cout << i << " ";
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> c(n - 1), s(n - 1), f(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> c[i] >> s[i] >> f[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int t = s[i] + c[i];
    for (int j = i + 1; j < n - 1; ++j) {
      if (t < s[j]) t = s[j];
      else if (t % f[j]) t += f[j] - t % f[j];
      t += c[j];
    }
    std::cout << t << "\n";
  }

  std::cout << 0 << "\n";
}
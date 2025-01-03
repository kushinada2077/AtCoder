#include <bits/stdc++.h>
using i64 = long long;

int operate(int a, int b, int t) {
  if (t == 1) return a & b;
  if (t == 2) return a | b;
  return a ^ b;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, c;
  std::cin >> n >> c;
  std::vector<int> t(n), a(n), ans(n);
  std::vector<std::vector<std::array<int, 2>>> f(30, std::vector<std::array<int, 2>>(n));
  for (int i = 0; i < n; ++i) std::cin >> t[i] >> a[i];
  for (int k = 0; k < 30; ++k) {
    int b[2] = {0, 1};
    for (int i = 0; i < n; ++i) {
      b[0] = f[k][i][0] = operate(b[0], (a[i] >> k) & 1, t[i]);
      b[1] = f[k][i][1] = operate(b[1], (a[i] >> k) & 1, t[i]);
    }
  }

  for (int k = 0; k < 30; ++k) {
    int bit = (c >> k) & 1;
    for (int i = 0; i < n; ++i) {
      bit = f[k][i][bit];
      ans[i] |= (bit << k);
    }
  }

  for (int i = 0; i < n; ++i) std::cout << ans[i] << "\n";
}
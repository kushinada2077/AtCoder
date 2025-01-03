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
    int bit = (c >> k) & 1;
    int arr[2] = {0, 1};
    for (int i = 0; i < n; ++i) {
      arr[0] = operate(arr[0], (a[i] >> k) & 1, t[i]);
      arr[1] = operate(arr[1], (a[i] >> k) & 1, t[i]);
      bit = arr[bit];
      ans[i] |= (bit << k);
    }
  }

  for (int i = 0; i < n; ++i) std::cout << ans[i] << "\n";
}
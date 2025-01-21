#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAX = 1e5;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<bool> p(MAX + 1, true);
  p[1] = false;
  for (int i = 2; i * i <= MAX; ++i) {
    if (p[i] == true) {
      for (int j = i * i; j <= MAX; j += i) {
        p[j] = false;
      }
    }
  }
  auto isn = [&](int n) { return p[n] && p[(n + 1) / 2]; };
  std::vector<int> a(MAX + 1), pref(MAX + 2);
  for (int i = 1; i <= MAX; i += 2) {
    a[i] = isn(i);
  }
  for (int i = 1; i <= MAX; ++i) {
    pref[i + 1] = pref[i] + a[i];
  }

  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << pref[r + 1] - pref[l] << "\n";
  }
}
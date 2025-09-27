#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<i64> a(n), pref(n + 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    pref[i + 1] = pref[i] + a[i];
  }

  int offset = 0;
  for (int i = 0; i < q; ++i) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int c;
      std::cin >> c;
      offset = (offset + c) % n;
    } else if (op == 2) {
      int l, r;
      std::cin >> l >> r;
      l--;
      r--;
      l = (l + offset) % n;
      r = (r + offset) % n;
      i64 sum;
      if (l <= r) sum = pref[r + 1] - pref[l];
      else sum = (pref[n] - pref[l]) + pref[r + 1];
      std::cout << sum << "\n";
    }
  }
}
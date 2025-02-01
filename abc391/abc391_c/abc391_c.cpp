#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q, c = 0;
  std::cin >> n >> q;
  std::vector<int> a(n, 1), hash(n);
  std::iota(hash.begin(), hash.end(), 0);
  for (int i = 0; i < q; ++i) {
    int t;
    std::cin >> t;
    if (t == 1) {
      int p, h;
      std::cin >> p >> h;
      p--;
      h--;
      int m = hash[p];
      hash[p] = h;
      if (--a[m] == 1) {
        c--;
      }
      if (a[h]++ == 1) {
        c++;
      }
    } else if (t == 2) {
      std::cout << c << "\n";
    }
  }
}
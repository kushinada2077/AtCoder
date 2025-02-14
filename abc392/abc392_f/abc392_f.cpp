#include <bits/stdc++.h>
using i64 = long long;

template <typename T>
struct Fenwick {
  int n;
  std::vector<T> a;

  Fenwick(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    a.assign(n, T{});
  }

  void add(int x, const T& v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] = a[i - 1] + v;
    }
  }

  T sum(int x) {
    T ans{};
    for (int i = x; i > 0; i -= i & -i) {
      ans = ans + a[i - 1];
    }
    return ans;
  }

  T rangeSum(int l, int r) {
    return sum(r) - sum(l);
  }

  int select(const T& k) {
    int x = 0;
    T cur{};
    for (int i = 1 << (std::bit_width((unsigned)n) - 1); i; i /= 2) {
      if (x + i <= n && cur + a[x + i - 1] <= k) {
        x += i;
        cur = cur + a[x - 1];
      }
    }
    return x;
  }
};
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> P(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> P[i];
    P[i]--;
  }

  std::vector<int> ans(n);
  Fenwick<int> fw(n);
  for (int i = 0; i < n; ++i) {
    fw.add(i, 1);
  }

  for (int i = n - 1; i >= 0; --i) {
    int x = fw.select(P[i]);
    ans[x] = i;
    fw.add(x, -1);
  }

  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] + 1 << " \n"[i == n - 1];
  }
}
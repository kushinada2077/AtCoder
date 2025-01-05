#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using mint = atcoder::modint1000000007;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  std::vector<std::pair<int, int>> cnt(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      cnt[i].first += a[j] < a[i];
    }
    for (int j = i + 1; j < n; ++j) {
      cnt[i].second += a[j] < a[i];
    }
  }

  mint ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [l, r] = cnt[i];
    ans += mint(k) * (k - 1) / 2 * (l + r);
    ans += mint(k) * r;
  }

  std::cout << ans.val() << "\n";
}
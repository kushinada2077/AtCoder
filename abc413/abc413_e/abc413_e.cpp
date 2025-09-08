#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  int N;
  std::cin >> N;
  int L = (1 << N);
  std::vector<int> P(L);
  for (int i = 0; i < L; ++i) {
    std::cin >> P[i];
  }

  auto solve = [&](auto&& solve, int l, int r) -> std::vector<int> {
    if (r - l == 1) return {P[l]};
    int mid = (l + r) / 2;
    auto a = solve(solve, l, mid);
    auto b = solve(solve, mid, r);
    if (a[0] > b[0]) swap(a, b);
    a.insert(a.end(), b.begin(), b.end());
    return a;
  };

  P = solve(solve, 0, L);

  for (int i = 0; i < L; ++i) {
    std::cout << P[i] << " \n"[i == L - 1];
  }
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
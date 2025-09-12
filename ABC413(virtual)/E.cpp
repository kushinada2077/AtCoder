#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  int N;
  std::cin >> N;
  int M = (1 << N);
  std::vector<int> P(M);
  for (int i = 0; i < M; ++i) {
    std::cin >> P[i];
  }

  auto f = [&](auto &&f, int l, int r) -> std::vector<int> {
    if (l + 1 == r) {
      return {P[l]};
    }

    int mid = (l + r) / 2;
    auto A = f(f, l, mid);
    auto B = f(f, mid, r);
    if (A[0] > B[0])
      std::swap(A, B);
    A.insert(A.end(), B.begin(), B.end());
    return A;
  };

  auto ans = f(f, 0, M);
  for (int i = 0; i < M; ++i) {
    std::cout << ans[i] << " \n"[i == M - 1];
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
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> B[i];
  }

  sort(A.begin(), A.end(), std::greater<int>());
  sort(B.begin(), B.end());
  std::vector<bool> chk(N);
  i64 ans = 0;
  int offset = 0;
  for (int i = 0; i < N; ++i) {
    int a = A[i];
    auto b_ptr = std::lower_bound(B.begin() + offset, B.end(), M - a) - B.begin();
    if (b_ptr != N) {
      int d = (a + B[b_ptr]) % M;
      ans += d;
      chk[b_ptr] = true;
      offset = b_ptr + 1;
    } else {
      ans += a;
    }
  }
  for (int i = 0; i < N; ++i) {
    if (chk[i] == false) {
      ans += B[i];
    }
  }
  std::cout << ans << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
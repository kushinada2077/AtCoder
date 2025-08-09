#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> A(N);
  std::vector<i64> pref(N + 1);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  std::sort(A.begin(), A.end());
  for (int i = 0; i < N; ++i) {
    pref[i + 1] = pref[i] + A[i];
  }
  for (int i = 0; i < Q; ++i) {
    int B;
    std::cin >> B;
    auto p = std::lower_bound(A.begin(), A.end(), B) - A.begin();
    i64 rest = N - p;
    if (p == N) {
      std::cout << "-1\n";
    } else {
      i64 ans = pref[p] + rest * (B - 1) + 1;
      std::cout << ans << "\n";
    }
  }
}
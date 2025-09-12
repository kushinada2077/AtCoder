#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  int N;
  std::cin >> N;
  std::vector<int> S(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> S[i];
  }
  if (N == 2) {
    if (2 * S[0] < S[1]) std::cout << "-1\n";
    else std::cout << "2\n";
    return;
  }

  std::vector<int> A(S.begin() + 1, S.end() - 1);
  std::sort(A.begin(), A.end());

  int ans = [&]() -> int {
    int val = S.front(), ret = 2;
    while (true) {
      auto it = std::upper_bound(A.begin(), A.end(), 2 * val);
      if (2 * val >= S.back()) return ret;
      if (it == A.begin()) return ret = -1;
      it = std::prev(it);
      if (val == (*it)) return ret = -1;
      val = *it;
      ret++;
    }

    return ret;
  }();

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
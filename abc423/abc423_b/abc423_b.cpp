#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> L(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> L[i];
  }

  std::vector<int> ans(N + 1, 0);
  ans[0] = ans[N] = 1;
  for (int i = 0; i < N - 1; ++i) {
    if (L[i] == 0) ans[i + 1] = 1;
    else break;
  }

  for (int i = N - 1; i > 0; --i) {
    if (L[i] == 0) ans[i] = 1;
    else break;
  }

  std::cout << std::ranges::count(ans, 0) << "\n";
}
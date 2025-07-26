#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  std::vector<int> X(M);
  for (int i = 0; i < M; ++i) {
    std::cin >> X[i];
  }
  sort(X.begin(), X.end());
  std::vector<int> D(M - 1);
  i64 ans = 0;
  for (int i = 0; i < M - 1; ++i) {
    D[i] = std::abs(X[i + 1] - X[i]);
    ans += D[i];
  }

  sort(D.begin(), D.end(), std::greater<int>());
  for (int i = 0; i < N - 1; ++i) {
    if (i < D.size()) ans -= D[i];
  }
  std::cout << ans << "\n";
}
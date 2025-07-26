#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, K;
  std::cin >> N >> K;
  int M = K - 1;
  std::vector<int> A(N);
  int ptr = 0;
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    if (A[i] == 1) {
      ptr = i;
    }
  }

  int ans = (N - 2 + M) / M;
  std::cout << ans << "\n";
}
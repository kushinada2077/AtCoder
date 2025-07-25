#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  std::vector<int> S(M), C(M), ans(N + 1, -1);
  for (int i = 0; i < M; ++i) {
    std::cin >> S[i] >> C[i];
  }

  for (int i = 0; i < M; ++i) {
    int s = S[i], c = C[i];
    if (ans[s] != -1 && c != ans[s]) {
      std::cout << "-1\n";
      return 0;
    }
    ans[s] = c;
  }

  if (N > 1 && ans[1] == 0) {
    std::cout << "-1\n";
    return 0;
  }

  for (int i = 1; i <= N; ++i) {
    if (ans[i] == -1) {
      if (N > 1 && i == 1) ans[i] = 1;
      else ans[i] = 0;
    }
  }

  for (int i = 1; i <= N; ++i) {
    std::cout << ans[i];
  }
}
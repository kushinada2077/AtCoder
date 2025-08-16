#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::string S, T;
  std::cin >> N >> M >> S >> T;
  std::vector<int> cnt(N, 0);
  for (int i = 0; i < M; ++i) {
    int L, R;
    std::cin >> L >> R;
    L--;
    cnt[L]++;
    cnt[R]--;
  }

  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      cnt[i] += cnt[i - 1];
    }
  }

  for (int i = 0; i < N; ++i) {
    if (cnt[i] % 2 == 0) {
      std::cout << S[i];
    } else {
      std::cout << T[i];
    }
  }
}
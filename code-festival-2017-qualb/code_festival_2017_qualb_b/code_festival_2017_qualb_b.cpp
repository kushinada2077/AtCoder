#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::map<int, int> cnt;
  for (int i = 0; i < N; ++i) {
    int D;
    std::cin >> D;
    cnt[D]++;
  }
  int M;
  std::cin >> M;
  for (int i = 0; i < M; ++i) {
    int T;
    std::cin >> T;
    if (cnt[T] == 0) {
      std::cout << "NO\n";
      return 0;
    }
    cnt[T]--;
  }

  std::cout << "YES\n";
}
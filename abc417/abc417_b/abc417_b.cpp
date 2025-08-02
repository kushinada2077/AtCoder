#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  std::map<int, int> A;
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    A[x]++;
  }
  for (int i = 0; i < M; ++i) {
    int x;
    std::cin >> x;
    A[x]--;
  }

  for (auto [k, v] : A) {
    if (v > 0) {
      for (int i = 0; i < v; ++i) {
        std::cout << k << " ";
      }
    }
  }
}
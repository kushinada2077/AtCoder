#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> next(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> next[i];
    next[i]--;
  }
  int c = 0, u = 0;
  while (true) {
    if (c >= N) {
      c = -1;
      break;
    }
    if (u == 1) {
      break;
    }
    c++;
    u = next[u];
  }
  std::cout << c << "\n";
}
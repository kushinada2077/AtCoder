#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int A, B;
    std::cin >> A >> B;
    ans += A < B;
  }
  std::cout << ans << "\n";
}
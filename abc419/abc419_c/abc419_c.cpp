#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N;
  std::cin >> N;
  std::vector<i64> R(N), C(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> R[i] >> C[i];
  }

  i64 midR = (*std::max_element(R.begin(), R.end()) + *std::min_element(R.begin(), R.end())) / 2;
  i64 midC = (*std::max_element(C.begin(), C.end()) + *std::min_element(C.begin(), C.end())) / 2;

  i64 ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = std::max(ans, std::max(std::abs(midR - R[i]), std::abs(midC - C[i])));
  }
  std::cout << ans << "\n";
}
#include <bits/stdc++.h>
using i64 = long long;

bool solve() {
  int N;
  std::cin >> N;
  std::vector<i64> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  if (std::ranges::count(A, A[0]) == N)
    return true;

  if (const auto p_cnt{std::ranges::count(A, A[0])},
      m_cnt{std::ranges::count(A, -A[0])};
      p_cnt + m_cnt == N && std::min(p_cnt, m_cnt) == N / 2)
    return true;

  std::sort(A.begin(), A.end(),
            [&](i64 a, i64 b) { return std::abs(a) < std::abs(b); });
  for (int i = 1; i < N; i++) {
    if (i + 1 < N && A[i - 1] * A[i + 1] != A[i] * A[i])
      return false;
  }

  return true;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    if (solve() == true) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
}
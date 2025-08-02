#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 5 * 10e5;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  std::vector<int> cnt(MAX, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    if (i - A[i] > 0) cnt[i - A[i]]++;
  }

  i64 ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += cnt[A[i] + i];
  }

  std::cout << ans << "\n";
}
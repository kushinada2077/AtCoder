#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> A(N), cnt(N + 1);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    cnt[A[i]]++;
  }
  i64 tot = 0;
  auto cal = [&](i64 x) { return x * (x - 1) / 2; };
  for (int i = 1; i <= N; ++i) {
    if (cnt[i] > 0) {
      tot += cal(cnt[i]);
    }
  }

  for (int i = 0; i < N; ++i) {
    i64 res = tot - cal(cnt[A[i]]) + cal(cnt[A[i]] - 1);
    std::cout << res << "\n";
  }
}
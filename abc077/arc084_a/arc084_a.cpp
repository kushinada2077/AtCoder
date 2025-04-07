#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> B[i];
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> C[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  std::vector<i64> cnt(N + 1);
  for (int i = 0; i < N; ++i) {
    cnt[i] = C.end() - std::upper_bound(C.begin(), C.end(), B[i]);
  }
  for (int i = N - 1; i >= 0; --i) {
    cnt[i] += cnt[i + 1];
  }
  i64 ans = 0;
  for (int i = 0; i < N; ++i) {
    int st = std::upper_bound(B.begin(), B.end(), A[i]) - B.begin();
    ans += cnt[st];
  }
  std::cout << ans << "\n";
}
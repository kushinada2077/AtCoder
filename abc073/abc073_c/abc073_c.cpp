#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    B[i] = A[i];
  }
  sort(B.begin(), B.end());
  B.erase(std::unique(B.begin(), B.end()), B.end());
  for (int i = 0; i < N; ++i) {
    A[i] = std::lower_bound(B.begin(), B.end(), A[i]) - B.begin();
  }

  std::vector<int> c(N);
  for (int i = 0; i < N; ++i) {
    c[A[i]] ^= 1;
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += c[i] == 1;
  }
  std::cout << ans << "\n";
}
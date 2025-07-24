#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  sort(A.begin(), A.end());
  int ans = 0;
  for (int i = 0; i < N;) {
    int cc = A[i], f = 0;
    while (cc == A[i]) {
      i++;
      f++;
    }
    ans += f % 2;
  }
  std::cout << ans << "\n";
}
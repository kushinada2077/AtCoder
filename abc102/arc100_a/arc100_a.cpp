#include <bits/stdc++.h>
using i64 = long long;

i64 sumD(std::vector<int>& A, int b) {
  i64 ret = 0;
  for (int i = 0; i < A.size(); ++i) {
    ret += std::abs(A[i] - b);
  }
  return ret;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> B[i];
    B[i] = B[i] - i - 1;
  }
  sort(B.begin(), B.end());
  int m = B.size() / 2;
  i64 ans = sumD(B, B[m]);
  if (B.size() % 2 == 0) {
    ans = std::min(ans, sumD(B, B[m - 1]));
  }
  std::cout << ans << "\n";
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  sort(A.begin(), A.end());
  std::deque<int> B, C;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      B.push_back(A[i / 2]);
      C.push_back(A[(n - 1) - i / 2]);
    } else {
      B.push_back(A[(n - 1) - i / 2]);
      C.push_back(A[i / 2]);
    }
  }
  B.push_front(B.back());
  B.pop_back();
  C.push_front(C.back());
  C.pop_back();

  i64 tot = 0, ans = -1;
  for (int i = 0; i < n - 1; ++i) {
    tot += std::abs(B[i] - B[i + 1]);
  }

  ans = tot;
  tot = 0;

  for (int i = 0; i < n - 1; ++i) {
    tot += std::abs(C[i] - C[i + 1]);
  }
  ans = std::max(ans, tot);

  std::cout << ans << "\n";
}
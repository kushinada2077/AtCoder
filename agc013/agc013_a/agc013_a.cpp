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

  int ptr = 0, ans = 0;
  while (ptr < N) {
    int iptr = ptr, dptr = ptr;
    while (iptr + 1 < N && A[iptr] <= A[iptr + 1]) {
      iptr++;
    }
    while (dptr + 1 < N && A[dptr] >= A[dptr + 1]) {
      dptr++;
    }
    ptr = std::max(iptr, dptr) + 1;
    ans++;
  }
  std::cout << ans << "\n";
}
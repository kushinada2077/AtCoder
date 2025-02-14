#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<i64> A(N), B(N);
  i64 sumA = 0, sumB = 0;
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    sumA += A[i];
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> B[i];
    sumB += B[i];
  }

  if (sumA > sumB) {
    std::cout << "No\n";
    return 0;
  }

  i64 cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] == B[i]) continue;
    if (A[i] < B[i]) {
      cnt += (B[i] - A[i]) / 2;
    } else {
      cnt -= A[i] - B[i];
    }
  }

  if (cnt >= 0) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
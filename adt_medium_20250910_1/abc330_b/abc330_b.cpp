#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, L, R;
  std::cin >> N >> L >> R;
  std::vector<int> A(N), X(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  for (int i = 0; i < N; ++i) {
    if (L <= A[i] && A[i] <= R) {
      X[i] = A[i];
    } else if (A[i] < L) {
      X[i] = L;
    } else if (A[i] > R) {
      X[i] = R;
    }
  }

  for (int i = 0; i < N; ++i) {
    std::cout << X[i] << " \n"[i == N - 1];
  }
}
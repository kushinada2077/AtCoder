#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  if (std::all_of(A.begin(), A.end(), [&](int x) { return std::abs(x) == std::abs(A[0]); })) {
    int p = 0;
    for (int i = 0; i < N; ++i) {
      p += A[i] > 0;
    }
    int m = N - p;
    if (p == 0 || p == N || std::abs(p - m) <= 1) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
    return;
  }

  std::sort(A.begin(), A.end(), [&](int a, int b) { return std::abs(a) < std::abs(b); });
  int lo = A[0], hi = A[1], gcd = std::gcd(lo, hi);
  lo = lo / gcd, hi = hi / gcd;
  for (int i = 1; i < N - 1; ++i) {
    gcd = std::gcd(A[i], A[i + 1]);
    if ((lo != A[i] / gcd || hi != A[i + 1] / gcd) && (lo != -A[i] / gcd || hi != -A[i + 1] / gcd)) {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
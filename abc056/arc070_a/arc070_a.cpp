#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int X;
  std::cin >> X;
  int N = 1;
  while ((1 + N) * N / 2 < X) {
    N++;
  }
  std::cout << N << "\n";
}
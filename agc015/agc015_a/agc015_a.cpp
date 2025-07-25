#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 N, A, B;
  std::cin >> N >> A >> B;
  std::cout << std::max(0LL, (N - 2) * B + (2 - N) * A + 1) << "\n";
}
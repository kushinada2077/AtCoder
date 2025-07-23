#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int A, B, C;
  std::cin >> A >> B >> C;
  for (int i = 1; i <= B; ++i) {
    int D = A * i - C;
    if (D < 0) {
      continue;
    }
    if (D % B == 0) {
      std::cout << "YES\n";
      return 0;
    }
  }
  std::cout << "NO\n";
}
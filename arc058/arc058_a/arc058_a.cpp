#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<bool> d(10);
  for (int i = 0; i < k; ++i) {
    int x;
    std::cin >> x;
    d[x] = true;
  }

  auto ok = [&](int n) {
    while (n > 0) {
      if (d[n % 10] == true) {
        return false;
      }
      n /= 10;
    }
    return true;
  };
  while (!ok(n)) {
    n++;
  }

  std::cout << n << "\n";
}
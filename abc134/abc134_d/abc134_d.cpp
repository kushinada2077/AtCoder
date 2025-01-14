#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1), ans;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  for (int i = n; 2 * i > n; --i) {
    b[i] = a[i];
  }

  for (int i = n / 2; i != 0; --i) {
    bool res = false;
    for (int j = 2 * i; j <= n; j += i) {
      res ^= b[j];
    }
    b[i] = a[i] ^ res;
  }

  for (int i = 1; i <= n; ++i) {
    if (b[i] == 1) {
      ans.push_back(i);
    }
  }

  std::cout << ans.size() << "\n";
  for (auto i : ans) {
    std::cout << i << " ";
  }
}
#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<int> a(3);
  std::cin >> a[0] >> a[1] >> a[2];
  bool ans = false;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (i == j || j == k || i == k) continue;
        ans |= a[i] * a[j] == a[k];
      }
    }
  }

  if (ans) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
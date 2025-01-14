#include <bits/stdc++.h>
#include <atcoder/modint>
using i64 = long long;
using mint = atcoder::modint1000000007;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  mint ans = 1;
  std::vector<int> c(n + 1, 0);
  std::vector<bool> isp(n + 1, true);

  for (int i = 2; i * i < n + 1; ++i) {
    if (isp[i]) {
      for (int j = i * i; j < n + 1; j += i) {
        isp[j] = false;
      }
    }
  }

  for (int i = 2; i < n + 1; ++i) {
    if (isp[i]) {
      int cp = i;
      while (cp < n + 1) {
        c[i] += n / cp;
        cp *= i;
      }
    }
  }

  for (auto i : c) {
    if (i != 0) {
      ans *= i + 1;
    }
  }

  std::cout << ans.val() << "\n";
}
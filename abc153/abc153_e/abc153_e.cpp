#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, n;
  std::cin >> h >> n;
  std::vector<int> dp(20001, 0x3f3f3f3f);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    for (int j = 1; j <= 20001; ++j) {
      if (j - a >= 0) dp[j] = std::min(dp[j], dp[j - a] + b);
    }
  }

  std::cout << *min_element(dp.begin() + h, dp.end()) << "\n";
}
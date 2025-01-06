#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> a(h);
  std::vector dp(h, std::vector<int>(w, 0x3f3f3f3f));
  for (int i = 0; i < h; ++i) {
    std::cin >> a[i];
  }

  dp[0][0] = a[0][0] == '#';

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i > 0) {
        if (a[i - 1][j] == '.' && a[i][j] == '#') dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
        else dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
      }
      if (j > 0) {
        if (a[i][j - 1] == '.' && a[i][j] == '#') dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
        else dp[i][j] = std::min(dp[i][j], dp[i][j - 1]);
      }
    }
  }

  std::cout << dp[h - 1][w - 1] << "\n";
}
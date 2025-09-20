#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

constexpr int INF = 0x3f3f3f3f;

void solve() {
  int h, w, ans = INF;
  std::cin >> h >> w;
  int s = 1 << w;
  std::vector<std::string> m(h);
  for (int i = 0; i < h; ++i) {
    std::cin >> m[i];
  }
  std::vector dp(h, std::vector<int>(s, INF));
  for (int i = 0; i < s; ++i) {
    int cnt = 0;
    for (int j = 0; j < w; ++j) {
      if ((i >> j) % 2 == 1 && m[0][j] == '.') {
        cnt = INF;
        break;
      } else if ((i >> j) % 2 == 0 && m[0][j] == '#') {
        cnt++;
      }
    }

    dp[0][i] = cnt;
  }

  for (int i = 1; i < h; ++i) {
    for (int j = 0; j < s; ++j) {
      int cnt = 0;
      bool poss = true;
      for (int k = 0; k < w; ++k) {
        if ((j >> k) % 2 == 1 && m[i][k] == '.') {
          poss = false;
          break;
        } else if ((j >> k) % 2 == 0 && m[i][k] == '#') {
          cnt++;
        }
      }

      if (poss == false) continue;

      for (int jj = 0; jj < s; ++jj) {
        bool chk = true;
        for (int l = 0; l < w - 1; ++l) {
          if ((jj >> l) % 2 == 1 && (jj >> l + 1) % 2 == 1 && (j >> l) % 2 == 1 && (j >> l + 1) % 2 == 1) {
            chk = false;
            break;
          }
        }

        if (chk == false) continue;
        dp[i][j] = std::min(dp[i][j], dp[i - 1][jj] + cnt);
      }
    }
  }

  for (int i = 0; i < s; ++i) {
    ans = std::min(ans, dp[h - 1][i]);
  }

  std::cout << ans << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
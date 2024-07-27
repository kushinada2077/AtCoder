#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

// dp[i][j][k] => i번째 접시까지 sweetness가 k이고 j개를 골랐을 때 최소 saltiness
vector<vector<vector<int>>> dp(85, vector<vector<int>>(85, vector<int>(10005, 1e9)));
int n, x, y;
int main() {
  fastio;
    cin >> n >> x >> y;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= x; ++k) {
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        if (k + a[i] <= x) dp[i + 1][j + 1][k + a[i]] = min(dp[i + 1][j + 1][k + a[i]], dp[i][j][k] + b[i]);
      }
    }
  }

  for (int i = n; i >= 0; --i) {
    for (int j = 0; j <= x; ++j) {
      if (dp[n][i][j] <= y) {
        cout << min(i + 1, n) << "\n";
        return 0;
      }
    }
  }
}
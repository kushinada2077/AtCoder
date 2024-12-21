#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

vector<int> indices[3001];
int dp[3001];
int n, ans = 1;
int main() {
  fastio;
  cin >> n;
  for (int h, i = 0; i < n; ++i) {
    cin >> h;
    indices[h].pb(i);
  }

  for (int i = 1; i <= 3000; ++i) {
    vector<int> &curArr = indices[i];
    if (si(curArr) < 2)
      continue;
    int maxDiff = curArr.back() - curArr.front(), mx = -1;
    for (int d = 1; d <= maxDiff; ++d) {
      fill(dp, dp + curArr.back() + 1, 0);
      for (int j = 0; j < si(curArr); ++j) {
        dp[curArr[j]] = 1;
        if (curArr[j] - d >= 0)
          dp[curArr[j]] = max(dp[curArr[j]], dp[curArr[j] - d] + 1);
        mx = max(mx, dp[curArr[j]]);
      }
    }

    ans = max(ans, mx);
  }

  cout << ans << "\n";
}
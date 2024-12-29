#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n;
i64 cost[205][205], dist[205][205];
vector<tuple<i64, i64, i64>> coor;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int x, y, c, i = 0; i < n; ++i) {
    cin >> x >> y >> c;
    coor.push_back({x, y, c});
  }

  for (int i = 1; i <= n; ++i) {
    auto [x, y, c] = coor[i - 1];
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      auto [nx, ny, _] = coor[j - 1];
      i64 cc = (abs(x - nx) + abs(y - ny) + c - 1) / c;
      cost[i][j] = dist[i][j] = cc;
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
      }
    }
  }

  i64 ans = LLONG_MAX;

  for (int u = 1; u <= n; ++u) {
    i64 mx = 0;
    for (int v = 1; v <= n; ++v) {
      if (u == v) continue;
      mx = max(mx, dist[u][v]);
    }

    ans = min(ans, mx);
  }

  cout << ans << "\n";
}
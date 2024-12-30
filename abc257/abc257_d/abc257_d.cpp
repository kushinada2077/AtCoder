#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n;
vector<tuple<i64, i64, i64>> coor;
i64 cost[205][205], minPower[205][205];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int x, y, p, i = 0; i < n; ++i) {
    cin >> x >> y >> p;
    coor.push_back({x, y, p});
  }

  for (int u = 0; u < n; ++u) {
    auto [x, y, p] = coor[u];
    for (int v = 0; v < n; ++v) {
      if (u == v) continue;
      auto [nx, ny, _] = coor[v];
      cost[u + 1][v + 1] = minPower[u + 1][v + 1] = (abs(nx - x) + abs(ny - y) + p - 1) / p;
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int u = 1; u <= n; ++u) {
      for (int v = 1; v <= n; ++v) {
        minPower[u][v] = min(minPower[u][v], max(minPower[u][k], minPower[k][v]));
      }
    }
  }

  i64 ans = LLONG_MAX;
  for (int u = 1; u <= n; ++u) {
    i64 mx = 0;
    for (int v = 1; v <= n; ++v) {
      if (u == v) continue;
      mx = max(mx, minPower[u][v]);
    }

    ans = min(ans, mx);
  }

  cout << ans << "\n";
}
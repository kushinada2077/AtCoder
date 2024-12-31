#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;
int n, p[205];
vector<tuple<i64, i64, i64>> coor;
vector<pair<i64, i64>> adj[205];

bool f(i64 s) {
  for (int st = 1; st <= n; ++st) {
    queue<int> q;
    vector<bool> vis(n + 1, 0);
    q.push(st);
    vis[st] = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto [cost, v] : adj[u]) {
        if (cost > s || vis[v]) continue;
        q.push(v);
        vis[v] = true;
      }
    }

    bool f = true;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        f = false;
        break;
      }
    }

    if (f) return true;
  }

  return false;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  fill(p, p + n + 1, -1);
  for (int x, y, p, i = 0; i < n; ++i) {
    cin >> x >> y >> p;
    coor.push_back({x, y, p});
  }

  for (int u = 0; u < n; ++u) {
    auto [x, y, p] = coor[u];
    for (int v = 0; v < n; ++v) {
      if (u == v) continue;
      auto [nx, ny, _] = coor[v];
      adj[u + 1].push_back({(abs(x - nx) + abs(y - ny) + p - 1) / p, v + 1});
    }
  }

  i64 lo = -1, hi = 4 * 10e9 + 5;
  while (lo + 1 < hi) {
    i64 mid = (lo + hi) / 2;
    if (f(mid)) hi = mid;
    else lo = mid;
  }

  cout << hi << "\n";
}
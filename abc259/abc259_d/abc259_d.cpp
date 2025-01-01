#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, st, en;
i64 sx, sy, tx, ty, x, y, r;
vector<tuple<i64, i64, i64>> circle;
vector<int> adj[3005];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> sx >> sy >> tx >> ty;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> r;
    circle.push_back({x, y, r});
    if (abs(x - sx) * abs(x - sx) + abs(y - sy) * abs(y - sy) == r * r) st = i + 1;
    if (abs(x - tx) * abs(x - tx) + abs(y - ty) * abs(y - ty) == r * r) en = i + 1;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      auto [x, y, r] = circle[i];
      auto [nx, ny, nr] = circle[j];
      i64 cDistP = abs(x - nx) * abs(x - nx) + abs(y - ny) * abs(y - ny);
      i64 rSum = r + nr, rDiff = abs(r - nr);
      if (rSum * rSum < cDistP) continue;
      if (rDiff * rDiff > cDistP) continue;
      adj[i + 1].push_back(j + 1);
      adj[j + 1].push_back(i + 1);
    }
  }

  queue<int> q;
  q.push(st);
  vector<bool> vis(3005);
  vis[st] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == en) {
      cout << "Yes\n";
      return 0;
    }
    for (auto nxt : adj[cur]) {
      if (vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
    }
  }

  cout << "No\n";
}
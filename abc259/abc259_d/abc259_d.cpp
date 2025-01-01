#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, sx, sy, tx, ty, x[3005], y[3005], r[3005];

struct DSU {
  vector<int> f, siz;
  DSU(int n) : f(n), siz(n, 1) { iota(f.begin(), f.end(), 0); };
  int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return leader(x) == leader(y); }
  bool merge(int x, int y) {
    x = leader(x), y = leader(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }
  int size(int x) { return siz[leader(x)]; }
};
i64 dist(int x1, int y1, int x2, int y2) { return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2); }
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> sx >> sy >> tx >> ty;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
  }

  DSU dsu(n + 2);
  for (int i = 0; i < n; ++i) {
    if (dist(sx, sy, x[i], y[i]) == 1LL * r[i] * r[i]) dsu.merge(i, n);
    if (dist(tx, ty, x[i], y[i]) == 1LL * r[i] * r[i]) dsu.merge(i, n + 1);
    for (int j = i + 1; j < n; ++j) {
      i64 d = dist(x[i], y[i], x[j], y[j]);
      int sum = r[i] + r[j];
      int diff = abs(r[i] - r[j]);
      if (1LL * diff * diff <= d && d <= 1LL * sum * sum) dsu.merge(i, j);
    }
  }

  if (dsu.same(n, n + 1)) cout << "Yes\n";
  else cout << "No\n";
}
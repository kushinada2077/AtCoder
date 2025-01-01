#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n;
map<int, array<int, 2>> maxe;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  vector<vector<array<int, 2>>> a(n);
  for (int m, i = 0; i < n; ++i) {
    cin >> m;
    a[i].resize(m);
    for (int p, e, j = 0; j < m; ++j) {
      cin >> p >> e;
      auto& [v, c] = maxe[p];
      if (v < e) {
        v = e;
        c = 1;
      } else if (v == e) c++;
      a[i][j] = {p, e};
    }
  }

  int ans = 0;
  bool no = false;
  for (int i = 0; i < n; ++i) {
    bool ok = false;
    for (auto [p, e] : a[i]) {
      if (maxe[p] == array{e, 1}) ok = true;
      if (ok) break;
    }

    ans += ok;
    no |= !ok;
  }

  ans += no;
  cout << ans << "\n";
}
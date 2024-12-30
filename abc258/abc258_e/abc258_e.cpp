#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int q, nxt[50][200005];
i64 n, X, k, W[200005], pref[200005], cost[200005];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q >> X;
  for (int i = 0; i < n; ++i) {
    cin >> W[i];
    pref[i + 1] = pref[i] + W[i];
  }

  i64 xm = X % pref[n];

  for (int i = 0, j = 0; i < n; ++i) {
    while (pref[n] * (j / n) + pref[j % n] - pref[i] < xm) j++;
    nxt[0][i] = j % n;
    cost[i] = j - i + X / pref[n] * n;
  }

  for (int k = 1; k < 50; ++k) {
    for (int i = 0; i < n; ++i) {
      nxt[k][i] = nxt[k - 1][nxt[k - 1][i]];
    }
  }

  for (int i = 0; i < q; ++i) {
    cin >> k;
    k--;
    int u = 0;
    for (int i = 0; i < 50; ++i)
      if (k & (1ll << i)) u = nxt[i][u];

    cout << cost[u] << "\n";
  }
}
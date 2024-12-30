#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int q, nxt[200005][50];
i64 n, X, offset, k, W[200005], pref[200005], cost[200005];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q >> X;
  for (int i = 0; i < n; ++i) {
    cin >> W[i];
    pref[i + 1] = pref[i] + W[i];
  }

  if (X >= pref[n]) {
    offset = X / pref[n];
    X %= pref[n];
  }

  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(pref + i + 1, pref + n + 1, X + pref[i]) - pref - 1;
    if (idx == n) idx = lower_bound(pref, pref + i + 1, X - (pref[n] - pref[i])) - pref - 1;
    int next_i = (idx + 1) % n;
    nxt[i][0] = next_i;
    if (X != 0) cost[i] = i < next_i ? next_i - i : n - (i - next_i);
  }

  for (int k = 1; k < 50; ++k) {
    for (int i = 0; i < n; ++i) {
      nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
    }
  }

  for (int i = 0; i < q; ++i) {
    cin >> k;
    k--;
    int u = 0;
    for (int i = 0; i < 50; ++i)
      if (k & (1ll << i)) u = nxt[u][i];

    cout << cost[u] + offset * n << "\n";
  }
}
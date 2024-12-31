#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, q, nxt[50][200005], num[200005];
i64 x, k, W[200005], pref[200005];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q >> x;
  for (int i = 0; i < n; ++i) {
    cin >> W[i];
    pref[i + 1] = pref[i] + W[i];
  }

  i64 xm = x % pref[n];
  for (int i = 0, j = 0; i < n; ++i) {
    while (pref[j % n] + j / n * pref[n] - pref[i] < xm) j++;
    nxt[0][i] = j % n;
    num[i] = x / pref[n] * n + j - i;
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
    for (int j = 0; j < 50; ++j) {
      if (k & ((i64)1 << j)) u = nxt[j][u];
    }

    cout << num[u] << "\n";
  }
}
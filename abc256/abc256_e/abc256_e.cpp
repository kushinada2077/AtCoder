#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

const int MX = 2e5 + 5;
int n, X[MX], C[MX], p[MX];

int find(int v) {
  if (p[v] < 0) return v;
  return p[v] = find(p[v]);
}

bool isTheSame(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return true;
  if (p[a] > p[b]) swap(a, b);
  p[a] += p[b];
  p[b] = a;
  return false;
}

int main() {
  fastio;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> X[i];
    p[i] = -1;
  }
  for (int i = 1; i <= n; ++i) cin >> C[i];
  ll ans = 0;

  for (int i = 1; i <= n; ++i) {
    if (!isTheSame(i, X[i])) continue;
    int v = i, mn = INF;
    do {
      mn = min(mn, C[v]);
      v = X[v];
    } while (v != i);
    ans += mn;
  }

  cout << ans << "\n";
}
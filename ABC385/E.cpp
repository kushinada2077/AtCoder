#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

const int MX = 300005;
int n, indg[MX];
vector<int> adj[MX];
int main() {
  fastio;
  freopen(PATH, "r", stdin);
  cin >> n;
  for (int u, v, i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    adj[v].pb(u);
    adj[u].pb(v);
    indg[u]++;
    indg[v]++;
  }

  int ans = INF;
  for (int x, y, u = 1; u <= n; ++u) {
    x = y = 0;
    sort(all(adj[u]), [&](int a, int b) { return indg[a] > indg[b]; });
    for (auto v : adj[u]) {
      x++;
      y = indg[v] - 1;
      ans = min(ans, n - (1 + x + x * y));
    }
  }

  cout << ans << "\n";
}
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

const int MXN = 200'010;
vector<pair<int, int>> adj[MXN];
bool vis[MXN];
ll mxD = 0;
int mxV;
void dfs(int v, ll dis) {
  if (vis[v]) return;
  if (dis > mxD) {
    mxD = dis;
    mxV = v;
  }
  vis[v] = true;
  for (auto [nxt, c] : adj[v]) dfs(nxt, dis + c);
}
int main() {
  fastio;
    int n, v, u, c;
  ll sc = 0;
  cin >> n;
  for_in(n - 1) {
    cin >> v >> u >> c;
    adj[v].pb({u, c});
    adj[u].pb({v, c});
    sc += 2 * c;
  }
  dfs(1, 0);
  fill(vis, vis + n + 1, 0);
  mxD = 0;
  dfs(mxV, 0);
  cout << sc - mxD << "\n";
}
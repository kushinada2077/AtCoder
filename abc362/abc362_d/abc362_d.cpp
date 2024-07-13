#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

const ll INF = 9223372036554775807;
vector<pair<ll, int>> adj[200005];
ll d[200005];
int main() {
  fastio;
    int n, m, u, v;
  ll c;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  cin >> n >> m;
  fill(d, d + n + 1, INF);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    adj[u].pb({c + a[v], v});
    adj[v].pb({c + a[u], u});
  }
  d[1] = a[1];
  pq.push({d[1], 1});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (d[cur.Y] != cur.X) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
    }
  }
  for (int i = 2; i <= n; ++i) cout << d[i] << " ";
}
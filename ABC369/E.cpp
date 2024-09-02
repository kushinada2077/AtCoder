#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int n, m, u, v, q, b, k, c;
vector<vector<ll>> dist(405, vector<ll>(405, LLONG_MAX / 3));
vector<tuple<int, int, int>> br(200005);
void floyd() {
  for (int i = 1; i <= n; ++i)
    dist[i][i] = 0;
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}
int main() {
  fastio;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> c;
    dist[u][v] = min(dist[u][v], 1ll * c);
    dist[v][u] = min(dist[v][u], 1ll * c);
    br[i] = tuple<int, int, int>{c, u, v};
  }
  floyd();
  cin >> q;
  while (q--) {
    cin >> k;
    ll ans = LLONG_MAX;
    vector<int> a(k);
    for (auto &i : a)
      cin >> i;
    sort(all(a));
    do {
      for (int i = 0; i < (1 << k); ++i) {
        int cur = 1;
        ll cnt = 0;
        for (int j = 0; j < k; ++j) {
          auto [c, u, v] = br[a[j]];
          if (i & (1 << j))
            swap(u, v);
          cnt += 1ll * dist[cur][u] + c;
          cur = v;
        }
        cnt += dist[cur][n];
        ans = min(ans, cnt);
      }
    } while (next_permutation(all(a)));
    cout << ans << "\n";
  }
}
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

const int MX = 2e5 + 5;
int n, X[MX], indg[MX], vis[MX];
ll ans, cSum[MX], C[MX];
//  (들어오는 가중치 합, 정점번호)
set<pair<ll, int>> vertices;
int main() {
  fastio;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> X[i];
    indg[X[i]]++;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> C[i];
    cSum[X[i]] += C[i];
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (indg[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    vis[cur] = 1;
    cSum[X[cur]] -= C[cur];
    if (--indg[X[cur]] == 0) {
      q.push(X[cur]);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (vis[i])
      continue;
    vertices.insert(pair<ll, int>(cSum[i], i));
  }

  while (!vertices.empty()) {
    auto [totCost, u] = *vertices.begin();
    vertices.erase(vertices.begin());
    int v = X[u];
    ans += cSum[u];
    vis[u] = 1;

    if (vis[v])
      continue;
    vertices.erase(P(cSum[v], v));
    cSum[v] -= C[u];
    vertices.insert(P(cSum[v], v));
  }

  cout << ans << "\n";
}
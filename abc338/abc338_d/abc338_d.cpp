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

int main() {
  fastio;
    int n, m;
  cin >> n >> m;
  vector<int> x(m);
  vector<ll> d(n + 5);
  for (auto& i : x) cin >> i;

  for (int i = 0; i < m - 1; ++i) {
    ll from = min(x[i], x[i + 1]), to = max(x[i], x[i + 1]);
    ll d1 = to - from, d2 = from + n - to;
    d[from] += d2;
    d[to] -= d2;
    d[0] += d1;
    d[from] -= d1;
    d[to] += d1;
    d[n] -= d1;
  }

  ll ans = LLONG_MAX, tot = 0;
  for (int i = 0; i < n; ++i) {
    tot += 1ll * d[i];
    ans = min(ans, tot);
  }
  cout << ans << "\n";
}
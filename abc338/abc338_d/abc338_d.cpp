#include <algorithm>
#include <climits>
#include <iostream>
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
    int n, m, pre, cur;
  cin >> n >> m >> pre;
  vector<ll> a(n + 1);
  for (int i = 0; i < m - 1; ++i) {
    cin >> cur;
    int l = min(pre, cur), r = max(pre, cur);
    ll dis1 = r - l, dis2 = n - r + l;
    a[l] += dis2;
    a[r] -= dis2;
    a[0] += dis1;
    a[l] -= dis1;
    a[r] += dis1;
    a[n] -= dis1;
    pre = cur;
  }
  ll ans = LLONG_MAX, tot = 0;
  for (int i = 0; i < si(a) - 1; ++i) {
    tot += 1ll * a[i];
    if (ans > tot) ans = tot;
  }
  cout << ans << "\n";
}
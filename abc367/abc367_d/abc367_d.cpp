#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int n, m;
int main() {
  fastio;
    cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a.pb(a[i]);
  }

  vector<int> r = {0};
  for (int i = 0; i < 2 * n; ++i) r.pb(((si(r) ? r.back() : 0) + a[i]) % m);

  vector<int> b(m, 0);
  ll ans = 0;
  for (int i = 0; i < n; ++i) b[r[i]]++;
  for (int i = n; i < 2 * n; ++i) {
    b[r[i - n]]--;
    ans += b[r[i]];
    b[r[i]]++;
  }
  cout << ans << "\n";
}
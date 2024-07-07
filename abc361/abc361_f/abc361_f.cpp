#include <algorithm>
#include <cmath>
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

ll ans, n;
void pfact(vector<int>& pfb, int b) {
  for (int i = 2; i * i <= b; ++i) {
    while (b % i == 0) {
      pfb.pb(i);
      b /= i;
    }
  }
}
ll safe_pow(ll a, ll b) {
  ll ret = 1;
  for (ll i = 0; i < b; ++i) {
    double pret = ret;
    pret *= a;
    if (pret > 2e18) return 2e18;
    ret *= a;
  }
  return ret;
}

int main() {
  fastio;
    cin >> n;
  for_in(b, 2, 60) {
    ll lo = 1, hi = 1e9 + 1;
    while (lo + 1 < hi) {
      ll mid = (lo + hi) / 2;
      if (safe_pow(mid, b) <= n) lo = mid;
      else hi = mid;
    }
    vector<int> pfb;
    pfact(pfb, b);
    bool dup = false;
    for_in(i, 1, si(pfb)) {
      if (pfb[i - 1] == pfb[i]) {
        dup = true;
        break;
      }
    }
    if (dup) continue;
    int mark = si(pfb) & 1 ? -1 : 1;
    ans += mark * (lo - 1);
  }
  ans++;
  cout << ans;
}
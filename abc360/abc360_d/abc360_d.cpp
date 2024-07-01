#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(i, x) for (int i = 0; i < x; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
  fastio;
    int n, t, x;
  ll ans = 0;
  string s;
  cin >> n >> t >> s;
  vector<int> a, b;
  for_in(i, n) {
    cin >> x;
    if (s[i] == '0') b.push_back(x);
    else a.push_back(x);
  }
  sort(all(b));
  for (auto v : a) ans += upper_bound(all(b), (ll)v + 2 * t) - lower_bound(all(b), v);
  cout << ans;
}
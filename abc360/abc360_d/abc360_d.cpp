#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
  fastio;
  ll n, t, ans = 0;
  string s;
  cin >> n >> t >> s;
  vector<ll> coor(n), pos, neg;
  for (int i = 0; i < n; ++i) {
    cin >> coor[i];
    if (s[i] == '0') neg.push_back(coor[i]);
    else pos.push_back(coor[i]);
  }
  sort(neg.begin(), neg.end());
  for (auto v : pos) {
    ll x = v + 2 * t;
    ans += upper_bound(neg.begin(), neg.end(), x) - lower_bound(neg.begin(), neg.end(), v);
  }
  cout << ans;
}
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

int main() {
  fastio;
    int n;
  ll s_l, s_r;
  s_l = s_r = 0;
  cin >> n;
  vector<ll> l(n), r(n);
  for_in(n) {
    cin >> l[i] >> r[i];
    s_l += l[i];
    s_r += r[i];
  }
  if (0 < s_l || s_r < 0) {
    cout << "No\n";
    return 0;
  }
  vector<ll> x = l;
  ll sum_x = s_l;
  for (int i = 0; i < n; ++i) {
    ll d = min(-sum_x, r[i] - l[i]);
    sum_x += d;
    x[i] += d;
  }
  cout << "Yes\n";
  for (auto& i : x) cout << i << " ";
}
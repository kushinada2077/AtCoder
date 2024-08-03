#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

ll n, m, sum;
bool f(vector<ll>& a, ll x) {
  ll tot = 0;
  for (auto& i : a) tot += min(i, x);
  return tot <= m;
}
int main() {
  fastio;
    cin >> n >> m;
  vector<ll> a(n);
  for (auto& i : a) {
    cin >> i;
    sum += i;
  }
  sort(all(a));
  if (sum <= m) {
    cout << "infinite\n";
    return 0;
  }
  ll lo = 1, hi = 1e9 + 1;
  while (lo + 1 < hi) {
    ll mid = (lo + hi) / 2;
    if (f(a, mid)) lo = mid;
    else hi = mid;
  }
  cout << lo << "\n";
}
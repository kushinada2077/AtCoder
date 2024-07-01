#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for(i, x) for (int i = 0; i < x; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
  fastio;
    int n, a[100005], w[100005];
  ll ans = 0;
  vector<int> x[100005];
  cin >> n;
  for (i, n) cin >> a[i];
  for (i, n) cin >> w[i];
  for (i, n) x[a[i] - 1].push_back(w[i]);
  for (i, n) {
    sort(all(x[i]));
    for (j, si(x[i]) - 1) ans += x[i][j];
  }
  cout << ans;
}
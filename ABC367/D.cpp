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
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<int> r = {0};
  for (int i = 0; i < 2 * n; ++i)
    r.pb((1ll * r.back() + a[i % n]) % m);
  vector<int> b(m, 0);
  for (int i = 0; i < n; ++i)
    b[r[i]]++;
  ll ans = 0;
  for (int i = n; i < 2 * n; ++i) {
    b[r[i - n]]--;
    ans += b[r[i]]++;
  }
  cout << ans << "\n";
}
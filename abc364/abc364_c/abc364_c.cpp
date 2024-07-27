#include <algorithm>
#include <deque>
#include <iostream>
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

ll n, x, y;
int main() {
  fastio;
    cin >> n >> x >> y;
  vector<ll> da(n), db(n);
  for (auto& i : da) cin >> i;
  for (auto& i : db) cin >> i;
  sort(all(da), greater<>());
  sort(all(db), greater<>());
  int ans = n;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += da[i];
    if (sum > x) {
      ans = i + 1;
      break;
    }
  }
  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += db[i];
    if (sum > y) {
      ans = min(ans, i + 1);
      break;
    }
  }
  cout << ans << "\n";
}
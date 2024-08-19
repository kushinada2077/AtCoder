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

int main() {
  fastio;
    int n, x, cur = 0;
  cin >> n;
  ll ans = 0, tot = 0;
  vector<int> cnt(30, 0);
  for (int i = 0; i < n; ++i) {
    cin >> x;
    cur ^= x;
    tot += 1ll * x;
    for (int j = 0; j < 30; ++j) {
      if (cur & (1ll << j)) {
        ans += (1ll << j) * (i - cnt[j] + 1);
        cnt[j]++;
      } else {
        ans += (1ll << j) * cnt[j];
      }
    }
  }
  cout << ans - tot << "\n";
}
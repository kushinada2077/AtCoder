#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
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
  int n;
  cin >> n;
  ll ans = 2 * n - 1;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<int> diff;
  for (int i = 1; i < n; ++i)
    diff.pb(a[i] - a[i - 1]);
  int cnt = 1, cur = diff[0];
  for (int i = 1; i < si(diff); ++i) {
    if (diff[i] == cur)
      ans += cnt++;
    else {
      cnt = 1;
      cur = diff[i];
    }
  }
  cout << ans << "\n";
}
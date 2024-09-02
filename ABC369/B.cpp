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
  int n, k;
  cin >> n;
  char c;
  vector<int> a[2];

  for (int i = 0; i < n; ++i) {
    cin >> k >> c;
    if (c == 'L')
      a[0].pb(k);
    else
      a[1].pb(k);
  }

  int ans = 0;
  for (int i = 1; i < si(a[0]); ++i) {
    ans += abs(a[0][i] - a[0][i - 1]);
  }
  for (int i = 1; i < si(a[1]); ++i) {
    ans += abs(a[1][i] - a[1][i - 1]);
  }
  cout << ans << "\n";
}
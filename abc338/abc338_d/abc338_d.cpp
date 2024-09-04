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
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int main() {
  fastio;
    int n, m;
  cin >> n >> m;
  vector<int> x(m);
  for (int &i : x) {
    cin >> i;
    --i;
  }
  vector<ll> v(n + 1);
  auto dist = [&](int from, int to) {
    if (from <= to) return to - from;
    else return to + n - from;
  };
  auto add = [&](int from, int to, int num) {
    if (from <= to) {
      v[from] += num;
      v[to] -= num;
    } else {
      v[from] += num;
      v[n] -= num;
      v[0] += num;
      v[to] -= num;
    }
  };
  for (int i = 0; i < m - 1; i++) {
    add(x[i], x[i + 1], dist(x[i + 1], x[i]));
    add(x[i + 1], x[i], dist(x[i], x[i + 1]));
  }
  ll ans = 1LL << 60;
  for (int i = 0; i < n; i++) {
    v[i + 1] += v[i];
    ans = min(ans, v[i]);
  }
  cout << ans << "\n";
}
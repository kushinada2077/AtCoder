#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n, x, y;
vector<P> coor, ans;
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    coor.pb(P(x, -y));
  }

  sort(all(coor));

  int curL = -1, curR = -1;

  for (auto [l, r] : coor) {
    r = -r;
    if (curR < l) {
      ans.pb(P(curL, curR));
      curL = l;
      curR = r;
    } else if (r > curR)
      curR = r;
  }

  ans.pb(P(curL, curR));

  for (int i = 1; i < si(ans); ++i) {
    cout << ans[i].X << " " << ans[i].Y << "\n";
  }
}
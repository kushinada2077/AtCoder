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

int n, m, ans;
ll sx, sy, c;
char op;
map<ll, set<ll>> xCoor, yCoor;
int main() {
  fastio;
  freopen(PATH, "r", stdin);
  cin >> n >> m >> sx >> sy;
  for (int x, y, i = 0; i < n; ++i) {
    cin >> x >> y;
    xCoor[y].insert(x);
    yCoor[x].insert(y);
  }

  for (int i = 0; i < m; ++i) {
    cin >> op >> c;
    if (op == 'U') {
      auto it = yCoor[sx].lower_bound(sy);
      while (it != yCoor[sx].end() && *it <= sy + c) {
        ans++;
        xCoor[*it].erase(sx);
        yCoor[sx].erase(it);
        it = yCoor[sx].lower_bound(sy);
      }
      sy += c;
    } else if (op == 'D') {
      auto it = yCoor[sx].lower_bound(sy - c);
      while (it != yCoor[sx].end() && *it <= sy) {
        ans++;
        xCoor[*it].erase(sx);
        yCoor[sx].erase(it);
        it = yCoor[sx].lower_bound(sy - c);
      }
      sy -= c;
    } else if (op == 'L') {
      auto it = xCoor[sy].lower_bound(sx - c);
      while (it != xCoor[sy].end() && *it <= sx) {
        ans++;
        yCoor[*it].erase(sy);
        xCoor[sy].erase(it);
        it = xCoor[sy].lower_bound(sx - c);
      }
      sx -= c;
    } else {
      auto it = xCoor[sy].lower_bound(sx);
      while (it != xCoor[sy].end() && *it <= sx + c) {
        ans++;
        yCoor[*it].erase(sy);
        xCoor[sy].erase(it);
        it = xCoor[sy].lower_bound(sx);
      }
      sx += c;
    }
  }

  cout << sx << " " << sy << " " << ans << "\n";
}
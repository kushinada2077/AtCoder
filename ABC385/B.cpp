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

int h, w, x, y, ans, vis[101][101];
string board[101], t;
bool canGo(int x, int y) {
  return 0 <= x && x < h && 0 <= y && y < w && board[x][y] != '#';
}
int main() {
  fastio;
  cin >> h >> w >> x >> y;
  for (int i = 0; i < h; ++i)
    cin >> board[i];
  cin >> t;

  x--;
  y--;
  vis[x][y] = 1;
  if (board[x][y] == '@')
    ans++;
  for (auto c : t) {
    if (c == 'U' && canGo(x - 1, y))
      x = x - 1;
    else if (c == 'D' && canGo(x + 1, y))
      x = x + 1;
    else if (c == 'L' && canGo(x, y - 1))
      y = y - 1;
    else if (c == 'R' && canGo(x, y + 1))
      y = y + 1;
    if (vis[x][y] == 0 && board[x][y] == '@')
      ans++;
    vis[x][y] = 1;
  }

  cout << x + 1 << " " << y + 1 << " " << ans << "\n";
}
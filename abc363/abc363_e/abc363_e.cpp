#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define TUPLE tuple<int, int, int>
using namespace std;

int h, w, y, cnt;
vector<vector<int>> board(1005, vector<int>(1005));
vector<vector<bool>> vis(1005, vector<bool>(1005, 0)), chk(1005, vector<bool>(1005, 0));
priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE>> pq;
bool OOB(int x, int y) { return x < 0 || x >= h || y < 0 || y >= w; }
void bfs(int sx, int sy, int sv) {
  if (board[sx][sy] == -1) return;
  queue<pair<int, int>> q;
  q.push({sx, sy});
  vis[sx][sy] = 1;
  board[sx][sy] = -1;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    cnt++;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == -1) continue;
      if (board[nx][ny] > sv) {
        pq.push({board[nx][ny], nx, ny});
        chk[nx][ny] = true;
        continue;
      }
      q.push({nx, ny});
      vis[nx][ny] = 1;
      board[nx][ny] = -1;
    }
  }
}
int main() {
  fastio;
    cin >> h >> w >> y;
  int tot = h * w;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> board[i][j];
      if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
        if (chk[i][j]) continue;
        pq.push({board[i][j], i, j});
        chk[i][j] = true;
      }
    }
  }
  for (int sv = 1; sv <= y; ++sv) {
    vector<pair<int, int>> coor;
    while (!pq.empty()) {
      auto [he, x, y] = pq.top();
      if (he > sv) break;
      coor.pb({x, y});
      pq.pop();
    }
    for (auto [x, y] : coor) bfs(x, y, sv);
    cout << tot - cnt << "\n";
  }
}
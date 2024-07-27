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

int h, w, si, sj;
string board[100];
string op;
void f(char dir) {
  if (dir == 'U') dir = 0;
  else if (dir == 'L') dir = 1;
  else if (dir == 'D') dir = 2;
  else if (dir == 'R') dir = 3;
  int nx = si + "0121"[dir] - '1';
  int ny = sj + "1012"[dir] - '1';
  if (nx < 0 || nx >= h || ny < 0 || ny >= w) return;
  if (board[nx][ny] == '#') return;
  si = nx;
  sj = ny;
}
int main() {
  fastio;
    cin >> h >> w >> si >> sj;
  si--;
  sj--;
  for (int i = 0; i < h; ++i) cin >> board[i];
  cin >> op;
  for (auto& opc : op) f(opc);
  cout << si + 1 << " " << sj + 1 << "\n";
}
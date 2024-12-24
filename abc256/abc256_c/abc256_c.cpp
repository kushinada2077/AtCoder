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

int h[3], w[3], board[3][3], ans;
int main() {
  fastio;
    for (int i = 0; i < 3; ++i) cin >> h[i];
  for (int i = 0; i < 3; ++i) cin >> w[i];

  for (int ul = 1; ul < h[0] - 1; ++ul) {
    for (int ur = 1; ul + ur < h[0]; ++ur) {
      for (int dl = 1; dl < h[1] - 1; ++dl) {
        for (int dr = 1; dl + dr < h[1]; ++dr) {
          bool fail = false;
          board[0][0] = ul;
          board[0][1] = ur;
          board[1][0] = dl;
          board[1][1] = dr;
          board[0][2] = h[0] - ul - ur;
          board[1][2] = h[1] - dl - dr;
          for (int i = 0; i < 3; ++i) {
            if ((board[2][i] = w[i] - board[1][i] - board[0][i]) < 1) {
              fail = true;
              break;
            }
          }

          if (board[2][0] + board[2][1] + board[2][2] != h[2]) fail = true;
          if (!fail) ans++;
        }
      }
    }
  }

  cout << ans << "\n";
}
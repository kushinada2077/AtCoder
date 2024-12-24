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

int h[3], w[3], a[3][3], ans;
void solve(int ij) {
  int i = ij / 3, j = ij % 3;
  if (i == 3) {
    ans++;
    return;
  }

  if (i == 2) {
    int x = w[j] - a[1][j] - a[0][j];
    if (x < 1) return;
    a[i][j] = x;
    solve(ij + 1);
  } else if (j == 2) {
    int x = h[i] - a[i][1] - a[i][0];
    if (x < 1) return;
    a[i][j] = x;
    solve(ij + 1);
  } else {
    for (int x = 1; x < min(h[i], w[j]); ++x) {
      a[i][j] = x;
      solve(ij + 1);
    }
  }
}
int main() {
  fastio;
    for (int i = 0; i < 3; ++i) cin >> h[i];
  for (int i = 0; i < 3; ++i) cin >> w[i];
  if (h[0] + h[1] + h[2] != w[0] + w[1] + w[2]) {
    cout << "0\n";
    return 0;
  }
  solve(0);

  cout << ans << "\n";
}
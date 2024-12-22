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
// using P = pair<int, int>;

int h[3], w[3], tmp[3][3], ans;

void solve(int k) {
  if (k == 3) {
    bool f = 1;
    for (int j = 0; j < 3; ++j) {
      int sum = 0;
      for (int i = 0; i < 3; ++i)
        sum += tmp[i][j];
      if (sum != w[j])
        f = 0;
    }

    if (f)
      ans++;
    return;
  }

  for (int a1 = 1; a1 < h[k] - 1; a1++) {
    for (int a2 = 1; a1 + a2 < h[k]; ++a2) {
      tmp[k][0] = a1;
      tmp[k][1] = a2;
      tmp[k][2] = h[k] - a1 - a2;
      solve(k + 1);
    }
  }
}
int main() {
  fastio;
  for (int i = 0; i < 3; ++i)
    cin >> h[i];
  for (int i = 0; i < 3; ++i)
    cin >> w[i];
  solve(0);
  cout << ans << "\n";
}
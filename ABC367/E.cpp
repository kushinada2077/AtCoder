#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

const int MX_D = 60;
int nxt[200005][MX_D];
int main() {
  fastio;
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n + 1), q(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> nxt[i][0];
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int j = 1; j < MX_D; ++j) {
    for (int i = 1; i <= n; ++i)
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
  }
  for (int i = 1; i <= n; ++i) {
    q[i] = i;
    for (int j = 0; j < MX_D; ++j) {
      if (k & (1ll << j))
        q[i] = nxt[q[i]][j];
    }
    cout << a[q[i]] << " ";
  }
}
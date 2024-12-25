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

int n;
vector<P> query;
int main() {
  fastio;
    cin >> n;
  for (int l, r, i = 0; i < n; ++i) {
    cin >> l >> r;
    query.pb(P(l, 0));
    query.pb(P(r, 1));
  }

  sort(all(query));
  int cnt = 0;
  for (auto [x, f] : query) {
    if (f == 0) {
      if (cnt == 0) cout << x << " ";
      cnt++;
    } else {
      cnt--;
      if (cnt == 0) cout << x << "\n";
    }
  }
}
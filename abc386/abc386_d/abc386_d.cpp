#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n, m, mny = INF;
char c;
vector<tuple<int, int, int>> query;
int main() {
  fastio;
  cin >> n >> m;
  for (int y, x, i = 0; i < m; ++i) {
    cin >> y >> x >> c;
    query.push_back(tuple<int, int, int>(x, y, c));
  }

  sort(all(query));
  for (auto [x, y, c] : query) {
    if (c == 'W') {
      mny = min(mny, y);
    } else {
      if (mny <= y) {
        cout << "No\n";
        return 0;
      }
    }
  }

  cout << "Yes\n";
}
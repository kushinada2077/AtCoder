#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n, m;
char c;
set<int> bx;
vector<tuple<int, int, int>> query;
int main() {
  fastio;
  cin >> n >> m;
  for (int y, x, i = 0; i < m; ++i) {
    cin >> y >> x >> c;
    query.push_back(tuple<int, int, int>(-y, -x, c));
  }

  sort(all(query));
  for (auto [y, x, c] : query) {
    y = -y, x = -x;
    if (c == 'B') {
      bx.insert(x);
    } else {
      if (bx.lower_bound(x) != bx.end()) {
        cout << "No\n";
        return 0;
      }
    }
  }

  cout << "Yes\n";
}
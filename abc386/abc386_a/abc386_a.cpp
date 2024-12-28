#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int a, b, c, d;
set<int> s;
int main() {
  fastio;
  cin >> a >> b >> c >> d;
  s.insert(a);
  s.insert(b);
  s.insert(c);
  s.insert(d);

  if (si(s) == 2) cout << "Yes\n";
  else cout << "No\n";
}
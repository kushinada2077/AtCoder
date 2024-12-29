#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

bool check(const string& s, const string& t) {
  int j = 0;
  for (int i = 0; i < si(s); ++i) {
    if (j < si(t) && s[i] == t[j]) j++;
  }

  return j == si(t);
}
int main() {
  fastio;
  int k;
  string s, t;
  cin >> k >> s >> t;

  bool ok = false;
  if (si(s) == si(t)) {
    int cnt = 0;
    for (int i = 0; i < si(s); ++i) cnt += s[i] != t[i];
    ok = cnt < 2;
  } else if (si(s) + 1 == si(t)) {
    ok = check(t, s);
  } else if (si(s) == si(t) + 1) {
    ok = check(s, t);
  }

  if (ok) cout << "Yes\n";
  else cout << "No\n";
}
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int k;
string s, t;
int main() {
  fastio;
  cin >> k >> s >> t;
  if (abs(si(s) - si(t)) > 1) {
    cout << "No\n";
    return 0;
  }

  if (s == t) {
    cout << "Yes\n";
    return 0;
  }

  if (si(s) == si(t)) {
    int cnt = 0;
    for (int i = 0; i < si(s); ++i) cnt += s[i] != t[i];
    if (cnt == 1) {
      cout << "Yes\n";
      return 0;
    }
  }

  if (si(s) == si(t) + 1) {
    int cnt = 0, sp = 0, tp = 0;
    while (sp < si(s) && tp < si(t) && cnt <= 1) {
      if (s[sp] != t[tp]) {
        cnt++;
        sp++;
        continue;
      }
      sp++;
      tp++;
    }
    if (cnt <= 1) {
      cout << "Yes\n";
      return 0;
    }
  }

  if (si(s) + 1 == si(t)) {
    int cnt = 0, sp = 0, tp = 0;
    while (sp < si(s) && tp < si(t) && cnt <= 1) {
      if (s[sp] != t[tp]) {
        cnt++;
        tp++;
        continue;
      }
      sp++;
      tp++;
    }

    if (cnt <= 1) {
      cout << "Yes\n";
      return 0;
    }
  }

  cout << "No\n";
}
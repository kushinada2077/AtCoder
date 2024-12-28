#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

string s;
int ans, idx, n;
int main() {
  fastio;
  cin >> s;
  n = si(s);
  while (idx < n) {
    if (s[idx] == '0' && idx + 1 < n && s[idx + 1] == '0') idx += 2;
    else idx++;
    ans++;
  }

  cout << ans << "\n";
}
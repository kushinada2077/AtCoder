#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;

int n;
string s, t;
map<string, int> d;
bool sol() {
  queue<tuple<string, int, int>> q;
  q.push({s, n, n + 1});
  d[s] = 0;
  while (!q.empty()) {
    auto [cur, a, b] = q.front();
    if (cur == t) {
      cout << d[cur];
      return true;
    }
    q.pop();
    for_in(n + 1) {
      if (cur[i] == ' ' || cur[i + 1] == ' ') continue;
      string nxt = cur;
      swap(nxt[i], nxt[a]);
      swap(nxt[i + 1], nxt[b]);
      if (d.find(nxt) != d.end()) continue;
      q.push({nxt, i, i + 1});
      d[nxt] = d[cur] + 1;
    }
  }
  return false;
}
int main() {
  fastio;
    cin >> n >> s >> t;
  s += "  ";
  t += "  ";
  if (!sol()) cout << "-1\n";
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n, res, ans;
string s;
map<int, int> f;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> s;
  for (int w, i = 0; i < n; ++i) {
    cin >> w;
    res += s[i] == '1';
    f[w] += s[i] == '0' ? 1 : -1;
  }

  ans = res;
  for (auto [_, x] : f) {
    res += x;
    ans = max(ans, res);
  }

  cout << ans << "\n";
}
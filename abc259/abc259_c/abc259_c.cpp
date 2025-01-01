#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

string s, t;
vector<pair<char, int>> divide(const string& s) {
  vector<pair<char, int>> ret;
  int l = s.size(), i = 0;
  while (i < l) {
    int cnt = 1;
    while (i < l - 1 && s[i] == s[i + 1]) {
      i++;
      cnt++;
    }
    ret.push_back({s[i], cnt});
    i++;
  }

  return ret;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s >> t;
  auto sseg = divide(s), tseg = divide(t);
  bool ok = true;
  if (sseg.size() != tseg.size()) ok = false;
  for (int i = 0; i < sseg.size(); ++i) {
    auto [sc, sn] = sseg[i];
    auto [tc, tn] = tseg[i];
    if (sc != tc) ok = false;
    else if (sn == 1 && tn > 1 || sn > tn) ok = false;
    if (!ok) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
}
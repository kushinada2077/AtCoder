#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

string s, t;
vector<pair<char, int>> split(const string& s) {
  int n = s.size();
  vector<pair<char, int>> ret;
  for (int i = 0, j; i < n; i = j) {
    for (j = i; j < n && s[i] == s[j]; ++j);
    ret.emplace_back(s[i], j - i);
  }
  return ret;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s >> t;
  auto a = split(s);
  auto b = split(t);
  if (a.size() != b.size()) {
    cout << "No\n";
    return 0;
  }

  int n = a.size();
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (a[i].first != b[i].first) ok = false;
    else if (a[i].second == 1 && a[i].second < b[i].second || a[i].second > 1 && a[i].second > b[i].second) ok = false;
    if (!ok) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
}
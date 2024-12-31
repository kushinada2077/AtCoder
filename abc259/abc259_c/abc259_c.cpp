#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool compare(const string& s, const string& t) {
  int si = 0, ti = 0, slen = s.size(), tlen = t.size();
  if (slen > tlen) return false;
  while (si < slen && ti < tlen) {
    if (s[si] != t[ti]) return false;
    if (0 < si && s[si - 1] == s[si]) {
      while (si < slen && s[si] == s[si - 1] && s[si] == t[ti]) {
        si++;
        ti++;
      }
      while (ti < tlen && t[ti] == t[ti - 1]) ti++;
    } else {
      si++;
      ti++;
    }
  }

  return (si == slen && ti == tlen);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, t;
  cin >> s >> t;

  bool ans = compare(s, t);
  if (ans) cout << "Yes\n";
  else cout << "No\n";
}
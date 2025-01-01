#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

string s, t;
bool compare(const string& s, const string& t) {
  int sl = s.size(), tl = t.size(), a, b;
  a = b = 0;

  while (a < sl && b < tl) {
    if (s[a] != t[b]) return false;
    if (0 < a && 0 < b && s[a - 1] == s[a]) {
      while (a < sl && s[a - 1] == s[a] && s[a] == t[b]) {
        a++;
        b++;
      }
      while (b < tl && s[a - 1] == t[b]) b++;
    } else {
      a++;
      b++;
    }
  }

  return a == sl && b == tl;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s >> t;
  bool ans = compare(s, t);
  cout << (ans ? "Yes" : "No") << "\n";
}
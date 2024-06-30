#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

vector<string> get_sub(string& s, int w) {
  vector<string> sub;
  string tmp = "";
  int cnt = 0;
  for (auto c : s) {
    tmp += c;
    if (++cnt == w) {
      sub.push_back(tmp);
      tmp = "";
      cnt = 0;
    }
  }
  sub.push_back(tmp);
  return sub;
}
int main() {
  fastio;
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int k = t.size();
  for (int w = 1; w < n; ++w) {
    vector<string> sub = get_sub(s, w);
    if ((int)sub.size() < k) break;
    for (int c = 0; c < w; ++c) {
      string s1 = "";
      for (auto su : sub) {
        if (su.size() <= c) break;
        s1 += su[c];
      }
      if (!t.compare(s1)) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
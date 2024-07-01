#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
using namespace std;

int main() {
  fastio;
    string s, t, tmp;
  cin >> s >> t;
  for (int c = 1; c < si(s); ++c) {
    for (int w = c; w < si(s); ++w) {
      tmp = "";
      for (int i = 0; i < si(s); i += w) {
        if (i + c - 1 < si(s)) tmp += s[i + c - 1];
      }
      if (tmp == t) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
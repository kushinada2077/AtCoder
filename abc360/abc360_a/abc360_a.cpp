#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
  fastio;
  int r = 0, m = 0;
  string s;
  cin >> s;
  for (int i = 0; i < 3; ++i) {
    char c = s[i];
    if (c == 'R') r = i;
    else if (c == 'M') m = i;
  }
  if (r < m) cout << "Yes";
  else cout << "No";
}
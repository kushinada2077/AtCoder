#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  for (auto c : s) {
    if (count(s.begin(), s.end(), c) == 1) {
      cout << c << "\n";
      return 0;
    }
  }

  cout << "-1\n";

  return 0;
}
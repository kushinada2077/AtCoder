#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

string s;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s;
  vector<int> cnt(26, 0);
  for (auto c : s) cnt[c - 'a']++;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] == 1) {
      cout << char('a' + i) << "\n";
      return 0;
    }
  }

  cout << "-1\n";
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, q, f;
string s;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q >> s;
  for (int t, x, i = 0; i < q; ++i) {
    cin >> t >> x;
    if (t == 1) f = (f + x) % n;
    if (t == 2) {
      cout << s[(x - 1 - f + n) % n] << "\n";
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, q;
string s;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q >> s;
  int prefix = 0;
  for (int a, x, i = 0; i < q; ++i) {
    cin >> a >> x;
    if (a == 1) prefix = (prefix + n - x) % n;
    if (a == 2) cout << s[(prefix + x - 1) % n] << "\n";
  }
}
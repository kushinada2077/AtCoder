#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n, q;
string s;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q >> s;
  int idx = 0;
  for (int a, x, i = 0; i < q; ++i) {
    cin >> a >> x;
    if (a == 1) idx = (idx + (n - x)) % n;
    else cout << s[(idx + x - 1) % n] << "\n";
  }
}
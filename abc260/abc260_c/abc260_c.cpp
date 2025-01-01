#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, x, y, a = 1, b = 0;
  cin >> n >> x >> y;

  for (int i = n; i > 1; --i) {
    i64 na = a;
    b += x * a;
    na += b;
    b = y * b;
    a = na;
  }

  cout << b << "\n";
}
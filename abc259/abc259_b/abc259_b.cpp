#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  double a, b, d;
  cin >> a >> b >> d;
  double theta = atan2(b, a);
  double r = hypot(a, b);
  theta += d * M_PI / 180;
  double x = cos(theta) * r, y = sin(theta) * r;
  cout << fixed << setprecision(10) << x << " " << y << "\n";
}
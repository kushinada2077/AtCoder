#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  double x, y, d;
  cin >> x >> y >> d;
  double radian = d * M_PI / 180.0;
  double xp = x * cos(radian) - y * sin(radian);
  double yp = x * sin(radian) + y * cos(radian);
  cout << fixed;
  cout.precision(10);
  cout << xp << " " << yp << "\n";
}
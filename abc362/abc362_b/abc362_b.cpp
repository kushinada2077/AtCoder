#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

bool f(vector<int>& b) {
  for (int i = 0; i < 3; ++i)
    if (b[i] == b[(i + 1) % 3] + b[(i + 2) % 3]) return true;
  return false;
}
int main() {
  fastio;
    pair<int, int> a[3];
  for (int i = 0; i < 3; ++i) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y};
  }
  vector<int> b;
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      int p = abs(a[i].X - a[j].X);
      int q = abs(a[i].Y - a[j].Y);
      b.pb(p * p + q * q);
    }
  }
  if (f(b)) cout << "Yes\n";
  else cout << "No\n";
}
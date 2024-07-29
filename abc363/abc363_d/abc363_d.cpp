#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

ll TEN(int x) {
  if (x == 0) return 1;
  return TEN(x - 1) * 10;
}
int main() {
  fastio;
    ll n;
  cin >> n;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  n--;
  for (int d = 1;; ++d) {
    int x = (d + 1) / 2;
    if (n > TEN(x - 1) * 9) {
      n -= TEN(x - 1) * 9;
      continue;
    }
    string s = to_string(TEN(x - 1) + n - 1);
    for (int i = x; i < d; ++i) s += s[d - i - 1];
    cout << s << "\n";
    break;
  }
}
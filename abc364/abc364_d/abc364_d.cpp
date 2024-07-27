#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
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

int n, q, b, k;
int main() {
  fastio;
    cin >> n >> q;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  sort(all(a));
  while (q--) {
    cin >> b >> k;
    auto f = [&](int x) -> bool {
      auto lb = lower_bound(all(a), b - x);
      auto ub = upper_bound(all(a), b + x);
      return ub - lb >= k;
    };
    int l = -1, r = 2e8 + 2;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (f(mid)) r = mid;
      else l = mid;
    }
    cout << r << "\n";
  }
}
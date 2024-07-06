#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;

int main() {
  fastio;
    int n, k, ans = 0x3f3f3f3f;
  cin >> n >> k;
  vector<int> a(n);
  for_in(n) cin >> a[i];
  sort(all(a));
  int st = 0, en = n - 1 - k;
  while (en < n) ans = min(ans, a[en++] - a[st++]);
  cout << ans;
}
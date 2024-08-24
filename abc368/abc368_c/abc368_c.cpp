#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int main() {
  fastio;
    int n, cur = 0, dx[3] = {1, 1, 3};
  ll ans = 0;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  for (int i = 0; i < n; ++i) {
    int h = a[i];
    if (h == 1) {
      cur = (cur + 1) % 3;
      ans++;
    } else if (h == 2) {
      if (cur == 2) {
        ans++;
        cur = 0;
      } else {
        ans += 2ll;
        cur = (cur + 2) % 3;
      }
    } else {
      ans += 3ll * (h / 5);
      h %= 5;
      while (h > 0) {
        h -= dx[cur];
        ans++;
        cur = (cur + 1) % 3;
      }
    }
  }
  cout << ans << "\n";
}
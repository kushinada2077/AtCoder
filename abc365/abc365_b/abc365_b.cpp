#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_set>
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

int main() {
  fastio;
    int n;
  cin >> n;
  vector<int> a(n), b;
  for (auto& i : a) cin >> i;
  b = a;
  sort(all(a));
  for (int i = 0; i < n; ++i) {
    if (a[n - 2] == b[i]) {
      cout << i + 1 << "\n";
      break;
    }
  }
}
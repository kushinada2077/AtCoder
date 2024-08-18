#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int n, k;
vector<int> a(8), seq;
void f(int p) {
  if (p == n) {
    int tot = 0;
    for (auto &i : seq)
      tot += i;
    if (tot % k == 0) {
      for (auto &i : seq)
        cout << i << " ";
      cout << "\n";
    }
    return;
  }

  for (int i = 1; i <= a[p]; ++i) {
    seq.pb(i);
    f(p + 1);
    seq.pop_back();
  }
}
int main() {
  fastio;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  f(0);
}
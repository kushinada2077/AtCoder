#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
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
#define ROOT 1
using ll = long long;
using namespace std;

int n, k, x;
vector<int> r, seq;
void f(int p) {
  if (p == n) {
    int sum = 0;
    for (auto& i : seq) sum += i;
    if (sum % k) return;
    for (auto& i : seq) cout << i << " ";
    cout << "\n";
    return;
  }

  for (int i = 1; i <= r[p]; ++i) {
    seq.pb(i);
    f(p + 1);
    seq.pop_back();
  }
}
int main() {
  fastio;
    cin >> n >> k;
  r = vector<int>(n);
  for (auto& i : r) cin >> i;
  f(0);
}
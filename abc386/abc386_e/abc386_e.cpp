#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n, k;
ll A[200005];
ll solve(int idx, int cnt, ll sum) {
  if (cnt == k) return sum;
  if (idx == n) return 0;

  return max(solve(idx + 1, cnt + 1, sum ^ A[idx]), solve(idx + 1, cnt, sum));
}
int main() {
  fastio;
  cin >> n >> k;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    sum ^= A[i];
  }

  if (n - k < k) {
    k = n - k;
    cout << solve(0, 0, sum) << "\n";
  } else {
    cout << solve(0, 0, 0) << "\n";
  }
}
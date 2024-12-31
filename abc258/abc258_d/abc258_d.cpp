#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n;
i64 x, A[200005], B[200005];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> x;
  for (int i = 0; i < n; ++i) cin >> A[i] >> B[i];
  i64 ans = A[0] + B[0] + (x - 1) * B[0], sum = A[0] + B[0], min_cost = B[0];

  for (int i = 1; i < n; ++i) {
    min_cost = min(min_cost, B[i]);
    sum += A[i] + B[i];
    ans = min(ans, sum + (x - i - 1) * min_cost);
  }

  cout << ans << "\n";
}
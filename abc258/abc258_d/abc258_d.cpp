#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

const int MX = 2e5 + 5;
int n;
i64 x, A[MX], B[MX];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> x;
  for (int i = 0; i < n; ++i) cin >> A[i] >> B[i];
  i64 minGameT = B[0], baseT = A[0] + B[0], ans = A[0] + B[0] + (x - 1) * B[0];
  int clearNum = 2;
  for (int i = 1; i < n; ++i, clearNum++) {
    minGameT = min(minGameT, B[i]);
    baseT += A[i] + B[i];
    if (x > clearNum) ans = min(ans, baseT + (x - clearNum) * minGameT);
  }

  cout << ans << "\n";
}
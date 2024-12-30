#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TPi = tuple<int, int, int>;
using Pi = pair<int, int>;

int n, k, q, A[201];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k >> q;
  for (int i = 0; i < k; ++i) cin >> A[i];
  for (int l, i = 0; i < q; ++i) {
    cin >> l;
    l--;
    if (A[l] == n || A[l + 1] == A[l] + 1) continue;
    A[l]++;
  }

  for (int i = 0; i < k; ++i) cout << A[i] << " ";
}
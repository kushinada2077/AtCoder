#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, xyz[3];
  cin >> n >> xyz[0] >> xyz[1] >> xyz[2];
  vector<vector<pair<int, int>>> A(3, vector<pair<int, int>>(n));
  vector<bool> ok(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[0][i].first;
    A[0][i].first *= -1;
    A[0][i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> A[1][i].first;
    A[1][i].first *= -1;
    A[1][i].second = i;
    A[2][i].first = A[0][i].first + A[1][i].first;
    A[2][i].second = i;
  }

  for (int i = 0; i < 3; ++i) sort(A[i].begin(), A[i].end());

  for (int k = 0; k < 3; ++k) {
    for (auto [_, i] : A[k]) {
      if (xyz[k] == 0) break;
      if (!ok[i]) {
        ok[i] = true;
        xyz[k]--;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (ok[i]) cout << i + 1 << "\n";
  }
}